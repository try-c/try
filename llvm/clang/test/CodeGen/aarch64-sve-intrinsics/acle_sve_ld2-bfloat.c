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

// CHECK-LABEL: @test_svld2_bf16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call { <vscale x 8 x bfloat>, <vscale x 8 x bfloat> } @llvm.aarch64.sve.ld2.sret.nxv8bf16(<vscale x 8 x i1> [[TMP0]], ptr [[BASE:%.*]])
// CHECK-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 8 x bfloat>, <vscale x 8 x bfloat> } [[TMP1]], 0
// CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 16 x bfloat> @llvm.vector.insert.nxv16bf16.nxv8bf16(<vscale x 16 x bfloat> poison, <vscale x 8 x bfloat> [[TMP2]], i64 0)
// CHECK-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 8 x bfloat>, <vscale x 8 x bfloat> } [[TMP1]], 1
// CHECK-NEXT:    [[TMP5:%.*]] = tail call <vscale x 16 x bfloat> @llvm.vector.insert.nxv16bf16.nxv8bf16(<vscale x 16 x bfloat> [[TMP3]], <vscale x 8 x bfloat> [[TMP4]], i64 8)
// CHECK-NEXT:    ret <vscale x 16 x bfloat> [[TMP5]]
//
// CPP-CHECK-LABEL: @_Z15test_svld2_bf16u10__SVBool_tPKu6__bf16(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call { <vscale x 8 x bfloat>, <vscale x 8 x bfloat> } @llvm.aarch64.sve.ld2.sret.nxv8bf16(<vscale x 8 x i1> [[TMP0]], ptr [[BASE:%.*]])
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 8 x bfloat>, <vscale x 8 x bfloat> } [[TMP1]], 0
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 16 x bfloat> @llvm.vector.insert.nxv16bf16.nxv8bf16(<vscale x 16 x bfloat> poison, <vscale x 8 x bfloat> [[TMP2]], i64 0)
// CPP-CHECK-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 8 x bfloat>, <vscale x 8 x bfloat> } [[TMP1]], 1
// CPP-CHECK-NEXT:    [[TMP5:%.*]] = tail call <vscale x 16 x bfloat> @llvm.vector.insert.nxv16bf16.nxv8bf16(<vscale x 16 x bfloat> [[TMP3]], <vscale x 8 x bfloat> [[TMP4]], i64 8)
// CPP-CHECK-NEXT:    ret <vscale x 16 x bfloat> [[TMP5]]
//
svbfloat16x2_t test_svld2_bf16(svbool_t pg, const bfloat16_t *base) MODE_ATTR
{
  return SVE_ACLE_FUNC(svld2,_bf16,,)(pg, base);
}


// CHECK-LABEL: @test_svld2_vnum_bf16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = getelementptr <vscale x 8 x bfloat>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CHECK-NEXT:    [[TMP2:%.*]] = tail call { <vscale x 8 x bfloat>, <vscale x 8 x bfloat> } @llvm.aarch64.sve.ld2.sret.nxv8bf16(<vscale x 8 x i1> [[TMP0]], ptr [[TMP1]])
// CHECK-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 8 x bfloat>, <vscale x 8 x bfloat> } [[TMP2]], 0
// CHECK-NEXT:    [[TMP4:%.*]] = tail call <vscale x 16 x bfloat> @llvm.vector.insert.nxv16bf16.nxv8bf16(<vscale x 16 x bfloat> poison, <vscale x 8 x bfloat> [[TMP3]], i64 0)
// CHECK-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 8 x bfloat>, <vscale x 8 x bfloat> } [[TMP2]], 1
// CHECK-NEXT:    [[TMP6:%.*]] = tail call <vscale x 16 x bfloat> @llvm.vector.insert.nxv16bf16.nxv8bf16(<vscale x 16 x bfloat> [[TMP4]], <vscale x 8 x bfloat> [[TMP5]], i64 8)
// CHECK-NEXT:    ret <vscale x 16 x bfloat> [[TMP6]]
//
// CPP-CHECK-LABEL: @_Z20test_svld2_vnum_bf16u10__SVBool_tPKu6__bf16l(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = getelementptr <vscale x 8 x bfloat>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call { <vscale x 8 x bfloat>, <vscale x 8 x bfloat> } @llvm.aarch64.sve.ld2.sret.nxv8bf16(<vscale x 8 x i1> [[TMP0]], ptr [[TMP1]])
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 8 x bfloat>, <vscale x 8 x bfloat> } [[TMP2]], 0
// CPP-CHECK-NEXT:    [[TMP4:%.*]] = tail call <vscale x 16 x bfloat> @llvm.vector.insert.nxv16bf16.nxv8bf16(<vscale x 16 x bfloat> poison, <vscale x 8 x bfloat> [[TMP3]], i64 0)
// CPP-CHECK-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 8 x bfloat>, <vscale x 8 x bfloat> } [[TMP2]], 1
// CPP-CHECK-NEXT:    [[TMP6:%.*]] = tail call <vscale x 16 x bfloat> @llvm.vector.insert.nxv16bf16.nxv8bf16(<vscale x 16 x bfloat> [[TMP4]], <vscale x 8 x bfloat> [[TMP5]], i64 8)
// CPP-CHECK-NEXT:    ret <vscale x 16 x bfloat> [[TMP6]]
//
svbfloat16x2_t test_svld2_vnum_bf16(svbool_t pg, const bfloat16_t *base, int64_t vnum) MODE_ATTR
{
  return SVE_ACLE_FUNC(svld2_vnum,_bf16,,)(pg, base, vnum);
}
