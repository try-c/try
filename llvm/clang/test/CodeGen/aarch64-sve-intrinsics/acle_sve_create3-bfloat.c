// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: aarch64-registered-target
// RUN: %clang_cc1 -fclang-abi-compat=latest -triple aarch64 -target-feature +sve -target-feature +bf16 -disable-O0-optnone -Werror -Wall -emit-llvm -o - %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s
// RUN: %clang_cc1 -fclang-abi-compat=latest -triple aarch64 -target-feature +sve -target-feature +bf16 -disable-O0-optnone -Werror -Wall -emit-llvm -o - -x c++ %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -fclang-abi-compat=latest -DSVE_OVERLOADED_FORMS -triple aarch64 -target-feature +sve -target-feature +bf16 -disable-O0-optnone -Werror -Wall -emit-llvm -o - %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s
// RUN: %clang_cc1 -fclang-abi-compat=latest -DSVE_OVERLOADED_FORMS -triple aarch64 -target-feature +sve -target-feature +bf16 -disable-O0-optnone -Werror -Wall -emit-llvm -o - -x c++ %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -fclang-abi-compat=latest -triple aarch64 -target-feature +bf16 -target-feature +sve -target-feature +sme -S -disable-O0-optnone -Werror -Wall -o /dev/null %s
// RUN: %clang_cc1 -fclang-abi-compat=latest -triple aarch64 -target-feature +bf16 -target-feature +sme -S -disable-O0-optnone -Werror -Wall -o /dev/null %s

#include <arm_sve.h>

#ifdef SVE_OVERLOADED_FORMS
// A simple used,unused... macro, long enough to represent any SVE builtin.
#define SVE_ACLE_FUNC(A1,A2_UNUSED,A3,A4_UNUSED) A1##A3
#else
#define SVE_ACLE_FUNC(A1,A2,A3,A4) A1##A2##A3##A4
#endif

#ifdef __ARM_FEATURE_SME
#define ATTR __arm_streaming
#else
#define ATTR
#endif

// CHECK-LABEL: @test_svcreate3_bf16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 24 x bfloat> @llvm.vector.insert.nxv24bf16.nxv8bf16(<vscale x 24 x bfloat> poison, <vscale x 8 x bfloat> [[X0:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 24 x bfloat> @llvm.vector.insert.nxv24bf16.nxv8bf16(<vscale x 24 x bfloat> [[TMP0]], <vscale x 8 x bfloat> [[X1:%.*]], i64 8)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 24 x bfloat> @llvm.vector.insert.nxv24bf16.nxv8bf16(<vscale x 24 x bfloat> [[TMP1]], <vscale x 8 x bfloat> [[X2:%.*]], i64 16)
// CHECK-NEXT:    ret <vscale x 24 x bfloat> [[TMP2]]
//
// CPP-CHECK-LABEL: @_Z19test_svcreate3_bf16u14__SVBfloat16_tS_S_(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 24 x bfloat> @llvm.vector.insert.nxv24bf16.nxv8bf16(<vscale x 24 x bfloat> poison, <vscale x 8 x bfloat> [[X0:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 24 x bfloat> @llvm.vector.insert.nxv24bf16.nxv8bf16(<vscale x 24 x bfloat> [[TMP0]], <vscale x 8 x bfloat> [[X1:%.*]], i64 8)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 24 x bfloat> @llvm.vector.insert.nxv24bf16.nxv8bf16(<vscale x 24 x bfloat> [[TMP1]], <vscale x 8 x bfloat> [[X2:%.*]], i64 16)
// CPP-CHECK-NEXT:    ret <vscale x 24 x bfloat> [[TMP2]]
//
svbfloat16x3_t test_svcreate3_bf16(svbfloat16_t x0, svbfloat16_t x1, svbfloat16_t x2) ATTR
{
  return SVE_ACLE_FUNC(svcreate3,_bf16,,)(x0, x1, x2);
}
