//===-- Unittests for expf16 ----------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "hdr/errno_macros.h"
#include "hdr/fenv_macros.h"
#include "src/errno/libc_errno.h"
#include "src/math/expf16.h"
#include "test/UnitTest/FPMatcher.h"
#include "test/UnitTest/Test.h"

using LlvmLibcExpf16Test = LIBC_NAMESPACE::testing::FPTest<float16>;

TEST_F(LlvmLibcExpf16Test, SpecialNumbers) {
  LIBC_NAMESPACE::libc_errno = 0;

  EXPECT_FP_EQ_ALL_ROUNDING(aNaN, LIBC_NAMESPACE::expf16(aNaN));
  EXPECT_MATH_ERRNO(0);

  EXPECT_FP_EQ_WITH_EXCEPTION(aNaN, LIBC_NAMESPACE::expf16(sNaN), FE_INVALID);
  EXPECT_MATH_ERRNO(0);

  EXPECT_FP_EQ_ALL_ROUNDING(inf, LIBC_NAMESPACE::expf16(inf));
  EXPECT_MATH_ERRNO(0);

  EXPECT_FP_EQ_ALL_ROUNDING(static_cast<float16>(zero),
                            LIBC_NAMESPACE::expf16(neg_inf));
  EXPECT_MATH_ERRNO(0);

  EXPECT_FP_EQ_ALL_ROUNDING(static_cast<float16>(1.0f),
                            LIBC_NAMESPACE::expf16(zero));
  EXPECT_MATH_ERRNO(0);

  EXPECT_FP_EQ_ALL_ROUNDING(static_cast<float16>(1.0f),
                            LIBC_NAMESPACE::expf16(neg_zero));
  EXPECT_MATH_ERRNO(0);
}

TEST_F(LlvmLibcExpf16Test, Overflow) {
  LIBC_NAMESPACE::libc_errno = 0;

  EXPECT_FP_EQ_WITH_EXCEPTION(inf, LIBC_NAMESPACE::expf16(max_normal),
                              FE_OVERFLOW);
  EXPECT_MATH_ERRNO(ERANGE);

  EXPECT_FP_EQ_WITH_EXCEPTION(
      inf, LIBC_NAMESPACE::expf16(static_cast<float16>(12.0)), FE_OVERFLOW);
  EXPECT_MATH_ERRNO(ERANGE);
}

TEST_F(LlvmLibcExpf16Test, Underflow) {
  LIBC_NAMESPACE::libc_errno = 0;

  EXPECT_FP_EQ_WITH_EXCEPTION(zero, LIBC_NAMESPACE::expf16(neg_max_normal),
                              FE_UNDERFLOW | FE_INEXACT);
  EXPECT_MATH_ERRNO(ERANGE);

  EXPECT_FP_EQ_WITH_EXCEPTION(
      zero, LIBC_NAMESPACE::expf16(static_cast<float16>(-18.0)),
      FE_UNDERFLOW | FE_INEXACT);
  EXPECT_MATH_ERRNO(ERANGE);
}
