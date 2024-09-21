// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: aarch64-registered-target
// RUN: %clang_cc1 -triple aarch64 -target-feature +sve -target-feature +bf16 -disable-O0-optnone -Werror -Wall -emit-llvm -o - %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s
// RUN: %clang_cc1 -triple aarch64 -target-feature +sve -target-feature +bf16 -disable-O0-optnone -Werror -Wall -emit-llvm -o - -x c++ %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64 -target-feature +sve -target-feature +bf16 -disable-O0-optnone -Werror -Wall -emit-llvm -o - %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64 -target-feature +sve -target-feature +bf16 -disable-O0-optnone -Werror -Wall -emit-llvm -o - -x c++ %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -fclang-abi-compat=latest -triple aarch64 -target-feature +sve -target-feature +bf16 -S -disable-O0-optnone -Werror -Wall -o /dev/null %s
// RUN: %clang_cc1 -fclang-abi-compat=latest -triple aarch64 -target-feature +sme -target-feature +bf16 -S -disable-O0-optnone -Werror -Wall -o /dev/null %s

#include <arm_sve.h>

#if defined __ARM_FEATURE_SME
#define MODE_ATTR __arm_streaming
#else
#define MODE_ATTR
#endif


#ifdef SVE_OVERLOADED_FORMS
// A simple used,unused... macro, long enough to represent any SVE builtin.
#define SVE_ACLE_FUNC(A1,A2_UNUSED,A3,A4_UNUSED) A1##A3
#else
#define SVE_ACLE_FUNC(A1,A2,A3,A4) A1##A2##A3##A4
#endif

// CHECK-LABEL: @test_svst3_bf16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x bfloat> @llvm.vector.extract.nxv8bf16.nxv24bf16(<vscale x 24 x bfloat> [[DATA:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 8 x bfloat> @llvm.vector.extract.nxv8bf16.nxv24bf16(<vscale x 24 x bfloat> [[DATA]], i64 8)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 8 x bfloat> @llvm.vector.extract.nxv8bf16.nxv24bf16(<vscale x 24 x bfloat> [[DATA]], i64 16)
// CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.st3.nxv8bf16(<vscale x 8 x bfloat> [[TMP0]], <vscale x 8 x bfloat> [[TMP1]], <vscale x 8 x bfloat> [[TMP2]], <vscale x 8 x i1> [[TMP3]], ptr [[BASE:%.*]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z15test_svst3_bf16u10__SVBool_tPu6__bf1614svbfloat16x3_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x bfloat> @llvm.vector.extract.nxv8bf16.nxv24bf16(<vscale x 24 x bfloat> [[DATA:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 8 x bfloat> @llvm.vector.extract.nxv8bf16.nxv24bf16(<vscale x 24 x bfloat> [[DATA]], i64 8)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 8 x bfloat> @llvm.vector.extract.nxv8bf16.nxv24bf16(<vscale x 24 x bfloat> [[DATA]], i64 16)
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.st3.nxv8bf16(<vscale x 8 x bfloat> [[TMP0]], <vscale x 8 x bfloat> [[TMP1]], <vscale x 8 x bfloat> [[TMP2]], <vscale x 8 x i1> [[TMP3]], ptr [[BASE:%.*]])
// CPP-CHECK-NEXT:    ret void
//
void test_svst3_bf16(svbool_t pg, bfloat16_t *base, svbfloat16x3_t data) MODE_ATTR
{
  return SVE_ACLE_FUNC(svst3,_bf16,,)(pg, base, data);
}

// CHECK-LABEL: @test_svst3_vnum_bf16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x bfloat> @llvm.vector.extract.nxv8bf16.nxv24bf16(<vscale x 24 x bfloat> [[DATA:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 8 x bfloat> @llvm.vector.extract.nxv8bf16.nxv24bf16(<vscale x 24 x bfloat> [[DATA]], i64 8)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 8 x bfloat> @llvm.vector.extract.nxv8bf16.nxv24bf16(<vscale x 24 x bfloat> [[DATA]], i64 16)
// CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP4:%.*]] = getelementptr <vscale x 8 x bfloat>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.st3.nxv8bf16(<vscale x 8 x bfloat> [[TMP0]], <vscale x 8 x bfloat> [[TMP1]], <vscale x 8 x bfloat> [[TMP2]], <vscale x 8 x i1> [[TMP3]], ptr [[TMP4]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z20test_svst3_vnum_bf16u10__SVBool_tPu6__bf16l14svbfloat16x3_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x bfloat> @llvm.vector.extract.nxv8bf16.nxv24bf16(<vscale x 24 x bfloat> [[DATA:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 8 x bfloat> @llvm.vector.extract.nxv8bf16.nxv24bf16(<vscale x 24 x bfloat> [[DATA]], i64 8)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 8 x bfloat> @llvm.vector.extract.nxv8bf16.nxv24bf16(<vscale x 24 x bfloat> [[DATA]], i64 16)
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP4:%.*]] = getelementptr <vscale x 8 x bfloat>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.st3.nxv8bf16(<vscale x 8 x bfloat> [[TMP0]], <vscale x 8 x bfloat> [[TMP1]], <vscale x 8 x bfloat> [[TMP2]], <vscale x 8 x i1> [[TMP3]], ptr [[TMP4]])
// CPP-CHECK-NEXT:    ret void
//
void test_svst3_vnum_bf16(svbool_t pg, bfloat16_t *base, int64_t vnum, svbfloat16x3_t data) MODE_ATTR
{
  return SVE_ACLE_FUNC(svst3_vnum,_bf16,,)(pg, base, vnum, data);
}
