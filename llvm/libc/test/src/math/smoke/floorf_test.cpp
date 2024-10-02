//===-- Unittests for floorf ----------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "FloorTest.h"

#include "src/math/floorf.h"

LIST_FLOOR_TESTS(float, LIBC_NAMESPACE::floorf)
