//===-- Unittests for llrint ----------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "RoundToIntegerTest.h"

#include "src/math/llrint.h"

LIST_ROUND_TO_INTEGER_TESTS_WITH_MODES(double, long long,
                                       LIBC_NAMESPACE::llrint)
