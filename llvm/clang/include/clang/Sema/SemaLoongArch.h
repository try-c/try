//===-- SemaLoongArch.h -- LoongArch target-specific routines --*- C++ -*--===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
/// \file
/// This file declares semantic analysis functions specific to LoongArch.
///
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_SEMA_SEMALOONGARCH_H
#define LLVM_CLANG_SEMA_SEMALOONGARCH_H

#include "clang/AST/ASTFwd.h"
#include "clang/Sema/SemaBase.h"

namespace clang {
class TargetInfo;

class SemaLoongArch : public SemaBase {
public:
  SemaLoongArch(Sema &S);

  bool CheckLoongArchBuiltinFunctionCall(const TargetInfo &TI,
                                         unsigned BuiltinID, CallExpr *TheCall);
};
} // namespace clang

#endif // LLVM_CLANG_SEMA_SEMALOONGARCH_H
