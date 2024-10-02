//===-- Implementation of truncf16 function -------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/math/truncf16.h"
#include "src/__support/FPUtil/NearestIntegerOperations.h"
#include "src/__support/common.h"
#include "src/__support/macros/config.h"
#include "src/__support/macros/properties/cpu_features.h"

namespace LIBC_NAMESPACE_DECL {

LLVM_LIBC_FUNCTION(float16, truncf16, (float16 x)) {
#if defined(__LIBC_USE_BUILTIN_CEIL_FLOOR_RINT_TRUNC) &&                       \
    defined(LIBC_TARGET_CPU_HAS_FAST_FLOAT16_OPS)
  return static_cast<float16>(__builtin_truncf(x));
#else
  return fputil::trunc(x);
#endif
}

} // namespace LIBC_NAMESPACE_DECL
