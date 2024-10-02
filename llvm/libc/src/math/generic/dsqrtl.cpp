//===-- Implementation of dsqrtl function ---------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/math/dsqrtl.h"
#include "src/__support/FPUtil/generic/sqrt.h"
#include "src/__support/common.h"
#include "src/__support/macros/config.h"

namespace LIBC_NAMESPACE_DECL {

LLVM_LIBC_FUNCTION(double, dsqrtl, (long double x)) {
  return fputil::sqrt<double>(x);
}

} // namespace LIBC_NAMESPACE_DECL
