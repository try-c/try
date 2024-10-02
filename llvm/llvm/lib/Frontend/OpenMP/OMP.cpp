//===- OMP.cpp ------ Collection of helpers for OpenMP --------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "llvm/Frontend/OpenMP/OMP.h"

#include "llvm/ADT/ArrayRef.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/ADT/SmallString.h"
#include "llvm/ADT/SmallVector.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/ADT/StringSwitch.h"
#include "llvm/Demangle/Demangle.h"
#include "llvm/Frontend/OpenMP/OMPIRBuilder.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/StringSaver.h"

#include <algorithm>
#include <cstdio>
#include <iterator>
#include <string>
#include <type_traits>

using namespace llvm;
using namespace llvm::omp;

#define GEN_DIRECTIVES_IMPL
#include "llvm/Frontend/OpenMP/OMP.inc"

static iterator_range<ArrayRef<Directive>::iterator>
getFirstCompositeRange(iterator_range<ArrayRef<Directive>::iterator> Leafs) {
  // OpenMP Spec 5.2: [17.3, 8-9]
  // If directive-name-A and directive-name-B both correspond to loop-
  // associated constructs then directive-name is a composite construct
  // otherwise directive-name is a combined construct.
  //
  // In the list of leaf constructs, find the first loop-associated construct,
  // this is the beginning of the returned range. Then, starting from the
  // immediately following leaf construct, find the first sequence of adjacent
  // loop-associated constructs. The last of those is the last one of the
  // range, that is, the end of the range is one past that element.
  // If such a sequence of adjacent loop-associated directives does not exist,
  // return an empty range.
  //
  // The end of the returned range (including empty range) is intended to be
  // a point from which the search for the next range could resume.
  //
  // Consequently, this function can't return a range with a single leaf
  // construct in it.

  auto firstLoopAssociated =
      [](iterator_range<ArrayRef<Directive>::iterator> List) {
        for (auto It = List.begin(), End = List.end(); It != End; ++It) {
          if (getDirectiveAssociation(*It) == Association::Loop)
            return It;
        }
        return List.end();
      };

  auto Empty = llvm::make_range(Leafs.end(), Leafs.end());

  auto Begin = firstLoopAssociated(Leafs);
  if (Begin == Leafs.end())
    return Empty;

  auto End =
      firstLoopAssociated(llvm::make_range(std::next(Begin), Leafs.end()));
  if (End == Leafs.end())
    return Empty;

  for (; End != Leafs.end(); ++End) {
    if (getDirectiveAssociation(*End) != Association::Loop)
      break;
  }
  return llvm::make_range(Begin, End);
}

namespace llvm::omp {
ArrayRef<Directive> getLeafConstructs(Directive D) {
  auto Idx = static_cast<std::size_t>(D);
  if (Idx >= Directive_enumSize)
    return std::nullopt;
  const auto *Row = LeafConstructTable[LeafConstructTableOrdering[Idx]];
  return ArrayRef(&Row[2], static_cast<int>(Row[1]));
}

ArrayRef<Directive> getLeafConstructsOrSelf(Directive D) {
  if (auto Leafs = getLeafConstructs(D); !Leafs.empty())
    return Leafs;
  auto Idx = static_cast<size_t>(D);
  assert(Idx < Directive_enumSize && "Invalid directive");
  const auto *Row = LeafConstructTable[LeafConstructTableOrdering[Idx]];
  // The first entry in the row is the directive itself.
  return ArrayRef(&Row[0], &Row[0] + 1);
}

ArrayRef<Directive>
getLeafOrCompositeConstructs(Directive D, SmallVectorImpl<Directive> &Output) {
  using ArrayTy = ArrayRef<Directive>;
  using IteratorTy = ArrayTy::iterator;
  ArrayRef<Directive> Leafs = getLeafConstructsOrSelf(D);

  IteratorTy Iter = Leafs.begin();
  do {
    auto Range = getFirstCompositeRange(llvm::make_range(Iter, Leafs.end()));
    // All directives before the range are leaf constructs.
    for (; Iter != Range.begin(); ++Iter)
      Output.push_back(*Iter);
    if (!Range.empty()) {
      Directive Comp =
          getCompoundConstruct(ArrayTy(Range.begin(), Range.end()));
      assert(Comp != OMPD_unknown);
      Output.push_back(Comp);
      Iter = Range.end();
      // As of now, a composite construct must contain all constituent leaf
      // constructs from some point until the end of all constituent leaf
      // constructs.
      assert(Iter == Leafs.end() && "Malformed directive");
    }
  } while (Iter != Leafs.end());

  return Output;
}

Directive getCompoundConstruct(ArrayRef<Directive> Parts) {
  if (Parts.empty())
    return OMPD_unknown;

  // Parts don't have to be leafs, so expand them into leafs first.
  // Store the expanded leafs in the same format as rows in the leaf
  // table (generated by tablegen).
  SmallVector<Directive> RawLeafs(2);
  for (Directive P : Parts) {
    ArrayRef<Directive> Ls = getLeafConstructs(P);
    if (!Ls.empty())
      RawLeafs.append(Ls.begin(), Ls.end());
    else
      RawLeafs.push_back(P);
  }

  // RawLeafs will be used as key in the binary search. The search doesn't
  // guarantee that the exact same entry will be found (since RawLeafs may
  // not correspond to any compound directive). Because of that, we will
  // need to compare the search result with the given set of leafs.
  // Also, if there is only one leaf in the list, it corresponds to itself,
  // no search is necessary.
  auto GivenLeafs{ArrayRef<Directive>(RawLeafs).drop_front(2)};
  if (GivenLeafs.size() == 1)
    return GivenLeafs.front();
  RawLeafs[1] = static_cast<Directive>(GivenLeafs.size());

  auto Iter = std::lower_bound(
      LeafConstructTable, LeafConstructTableEndDirective,
      static_cast<std::decay_t<decltype(*LeafConstructTable)>>(RawLeafs.data()),
      [](const llvm::omp::Directive *RowA, const llvm::omp::Directive *RowB) {
        const auto *BeginA = &RowA[2];
        const auto *EndA = BeginA + static_cast<int>(RowA[1]);
        const auto *BeginB = &RowB[2];
        const auto *EndB = BeginB + static_cast<int>(RowB[1]);
        if (BeginA == EndA && BeginB == EndB)
          return static_cast<int>(RowA[0]) < static_cast<int>(RowB[0]);
        return std::lexicographical_compare(BeginA, EndA, BeginB, EndB);
      });

  if (Iter == std::end(LeafConstructTable))
    return OMPD_unknown;

  // Verify that we got a match.
  Directive Found = (*Iter)[0];
  ArrayRef<Directive> FoundLeafs = getLeafConstructs(Found);
  if (FoundLeafs == GivenLeafs)
    return Found;
  return OMPD_unknown;
}

bool isLeafConstruct(Directive D) { return getLeafConstructs(D).empty(); }

bool isCompositeConstruct(Directive D) {
  ArrayRef<Directive> Leafs = getLeafConstructsOrSelf(D);
  if (Leafs.size() <= 1)
    return false;
  auto Range = getFirstCompositeRange(Leafs);
  return Range.begin() == Leafs.begin() && Range.end() == Leafs.end();
}

bool isCombinedConstruct(Directive D) {
  // OpenMP Spec 5.2: [17.3, 9-10]
  // Otherwise directive-name is a combined construct.
  return !getLeafConstructs(D).empty() && !isCompositeConstruct(D);
}

std::string prettifyFunctionName(StringRef FunctionName) {
  // Internalized functions have the right name, but simply a suffix.
  if (FunctionName.ends_with(".internalized"))
    return FunctionName.drop_back(sizeof("internalized")).str() +
           " (internalized)";
  unsigned LineNo = 0;
  auto ParentName = deconstructOpenMPKernelName(FunctionName, LineNo);
  if (LineNo == 0)
    return FunctionName.str();
  return ("omp target in " + ParentName + " @ " + std::to_string(LineNo) +
          " (" + FunctionName + ")")
      .str();
}

std::string deconstructOpenMPKernelName(StringRef KernelName,
                                        unsigned &LineNo) {

  // Only handle functions with an OpenMP kernel prefix for now. Naming scheme:
  // __omp_offloading_<hex_hash1>_<hex_hash2>_<name>_l<line>_[<count>_]<suffix>
  if (!KernelName.starts_with(TargetRegionEntryInfo::KernelNamePrefix))
    return "";

  auto PrettyName = KernelName.drop_front(
      sizeof(TargetRegionEntryInfo::KernelNamePrefix) - /*'\0'*/ 1);
  for (int I = 0; I < 3; ++I) {
    PrettyName = PrettyName.drop_while([](char c) { return c != '_'; });
    PrettyName = PrettyName.drop_front();
  }

  // Look for the last '_l<line>'.
  size_t LineIdx = PrettyName.rfind("_l");
  if (LineIdx == StringRef::npos)
    return "";
  if (PrettyName.drop_front(LineIdx + 2).consumeInteger(10, LineNo))
    return "";
  return demangle(PrettyName.take_front(LineIdx));
}
} // namespace llvm::omp
