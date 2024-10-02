//===-- Unittests for stdc_bit_floor_us -----------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/__support/CPP/limits.h"
#include "src/stdbit/stdc_bit_floor_us.h"
#include "test/UnitTest/Test.h"

TEST(LlvmLibcStdcBitfloorUsTest, Zero) {
  EXPECT_EQ(LIBC_NAMESPACE::stdc_bit_floor_us(0U),
            static_cast<unsigned short>(0));
}

TEST(LlvmLibcStdcBitfloorUsTest, Ones) {
  for (unsigned i = 0U; i != USHRT_WIDTH; ++i)
    EXPECT_EQ(LIBC_NAMESPACE::stdc_bit_floor_us(USHRT_MAX >> i),
              static_cast<unsigned short>(1 << (USHRT_WIDTH - i - 1)));
}
