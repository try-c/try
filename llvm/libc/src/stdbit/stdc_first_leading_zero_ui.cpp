//===-- Implementation of stdc_first_leading_zero_ui ----------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/stdbit/stdc_first_leading_zero_ui.h"

#include "src/__support/common.h"
#include "src/__support/macros/config.h"
#include "src/__support/math_extras.h"

namespace LIBC_NAMESPACE_DECL {

LLVM_LIBC_FUNCTION(unsigned, stdc_first_leading_zero_ui, (unsigned value)) {
  return static_cast<unsigned>(first_leading_zero(value));
}

} // namespace LIBC_NAMESPACE_DECL
