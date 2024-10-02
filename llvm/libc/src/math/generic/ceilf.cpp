//===-- Implementation of ceilf function ----------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/math/ceilf.h"
#include "src/__support/FPUtil/NearestIntegerOperations.h"
#include "src/__support/common.h"
#include "src/__support/macros/config.h"

namespace LIBC_NAMESPACE_DECL {

LLVM_LIBC_FUNCTION(float, ceilf, (float x)) {
#ifdef __LIBC_USE_BUILTIN_CEIL_FLOOR_RINT_TRUNC
  return __builtin_ceilf(x);
#else
  return fputil::ceil(x);
#endif
}

} // namespace LIBC_NAMESPACE_DECL
