//===-- Unittests for fmaximum_mag_num-------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===---------------------------------------------------------------------===//

#include "FMaximumMagNumTest.h"

#include "src/math/fmaximum_mag_num.h"

LIST_FMAXIMUM_MAG_NUM_TESTS(double, LIBC_NAMESPACE::fmaximum_mag_num)
