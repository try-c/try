//===-- Utility class to test fmax[f|l] -------------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIBC_TEST_SRC_MATH_SMOKE_FMAXTEST_H
#define LLVM_LIBC_TEST_SRC_MATH_SMOKE_FMAXTEST_H

#include "src/__support/CPP/algorithm.h"
#include "test/UnitTest/FEnvSafeTest.h"
#include "test/UnitTest/FPMatcher.h"
#include "test/UnitTest/Test.h"

template <typename T>
class FMaxTest : public LIBC_NAMESPACE::testing::FEnvSafeTest {

  DECLARE_SPECIAL_CONSTANTS(T)

public:
  typedef T (*FMaxFunc)(T, T);

  void testNaN(FMaxFunc func) {
    EXPECT_FP_EQ(inf, func(aNaN, inf));
    EXPECT_FP_EQ(neg_inf, func(neg_inf, aNaN));
    EXPECT_FP_EQ(zero, func(aNaN, zero));
    EXPECT_FP_EQ(neg_zero, func(neg_zero, aNaN));
    EXPECT_FP_EQ(T(-1.2345), func(aNaN, T(-1.2345)));
    EXPECT_FP_EQ(T(1.2345), func(T(1.2345), aNaN));
    EXPECT_FP_EQ(aNaN, func(aNaN, aNaN));
  }

  void testInfArg(FMaxFunc func) {
    EXPECT_FP_EQ(inf, func(neg_inf, inf));
    EXPECT_FP_EQ(inf, func(inf, zero));
    EXPECT_FP_EQ(inf, func(neg_zero, inf));
    EXPECT_FP_EQ(inf, func(inf, T(1.2345)));
    EXPECT_FP_EQ(inf, func(T(-1.2345), inf));
  }

  void testNegInfArg(FMaxFunc func) {
    EXPECT_FP_EQ(inf, func(inf, neg_inf));
    EXPECT_FP_EQ(zero, func(neg_inf, zero));
    EXPECT_FP_EQ(neg_zero, func(neg_zero, neg_inf));
    EXPECT_FP_EQ(T(-1.2345), func(neg_inf, T(-1.2345)));
    EXPECT_FP_EQ(T(1.2345), func(T(1.2345), neg_inf));
  }

  void testBothZero(FMaxFunc func) {
    EXPECT_FP_EQ(zero, func(zero, zero));
    EXPECT_FP_EQ(zero, func(neg_zero, zero));
    EXPECT_FP_EQ(zero, func(zero, neg_zero));
    EXPECT_FP_EQ(neg_zero, func(neg_zero, neg_zero));
  }

  void testRange(FMaxFunc func) {
    constexpr int COUNT = 100'001;
    constexpr StorageType STEP = LIBC_NAMESPACE::cpp::max(
        static_cast<StorageType>(STORAGE_MAX / COUNT), StorageType(1));
    StorageType v = 0, w = STORAGE_MAX;
    for (int i = 0; i <= COUNT; ++i, v += STEP, w -= STEP) {
      FPBits xbits(v), ybits(w);
      if (xbits.is_inf_or_nan())
        continue;
      if (ybits.is_inf_or_nan())
        continue;
      T x = xbits.get_val();
      T y = ybits.get_val();
      if ((x == 0) && (y == 0))
        continue;

      if (x > y) {
        EXPECT_FP_EQ(x, func(x, y));
      } else {
        EXPECT_FP_EQ(y, func(x, y));
      }
    }
  }
};

#define LIST_FMAX_TESTS(T, func)                                               \
  using LlvmLibcFMaxTest = FMaxTest<T>;                                        \
  TEST_F(LlvmLibcFMaxTest, NaN) { testNaN(&func); }                            \
  TEST_F(LlvmLibcFMaxTest, InfArg) { testInfArg(&func); }                      \
  TEST_F(LlvmLibcFMaxTest, NegInfArg) { testNegInfArg(&func); }                \
  TEST_F(LlvmLibcFMaxTest, BothZero) { testBothZero(&func); }                  \
  TEST_F(LlvmLibcFMaxTest, Range) { testRange(&func); }

#endif // LLVM_LIBC_TEST_SRC_MATH_SMOKE_FMAXTEST_H
