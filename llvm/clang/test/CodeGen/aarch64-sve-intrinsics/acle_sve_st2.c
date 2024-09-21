// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: aarch64-registered-target
// RUN: %clang_cc1 -triple aarch64 -target-feature +sve -disable-O0-optnone -Werror -Wall -emit-llvm -o - %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s
// RUN: %clang_cc1 -triple aarch64 -target-feature +sve -disable-O0-optnone -Werror -Wall -emit-llvm -o - -x c++ %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64 -target-feature +sve -disable-O0-optnone -Werror -Wall -emit-llvm -o - %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64 -target-feature +sve -disable-O0-optnone -Werror -Wall -emit-llvm -o - -x c++ %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -triple aarch64 -target-feature +sve -S -disable-O0-optnone -Werror -Wall -o /dev/null %s
// RUN: %clang_cc1 -triple aarch64 -target-feature +sme -S -disable-O0-optnone -Werror -Wall -o /dev/null %s

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

// CHECK-LABEL: @test_svst2_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 16 x i8> @llvm.vector.extract.nxv16i8.nxv32i8(<vscale x 32 x i8> [[DATA:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 16 x i8> @llvm.vector.extract.nxv16i8.nxv32i8(<vscale x 32 x i8> [[DATA]], i64 16)
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv16i8(<vscale x 16 x i8> [[TMP0]], <vscale x 16 x i8> [[TMP1]], <vscale x 16 x i1> [[PG:%.*]], ptr [[BASE:%.*]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z13test_svst2_s8u10__SVBool_tPa10svint8x2_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 16 x i8> @llvm.vector.extract.nxv16i8.nxv32i8(<vscale x 32 x i8> [[DATA:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 16 x i8> @llvm.vector.extract.nxv16i8.nxv32i8(<vscale x 32 x i8> [[DATA]], i64 16)
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv16i8(<vscale x 16 x i8> [[TMP0]], <vscale x 16 x i8> [[TMP1]], <vscale x 16 x i1> [[PG:%.*]], ptr [[BASE:%.*]])
// CPP-CHECK-NEXT:    ret void
//
void test_svst2_s8(svbool_t pg, int8_t *base, svint8x2_t data) MODE_ATTR
{
  return SVE_ACLE_FUNC(svst2,_s8,,)(pg, base, data);
}

// CHECK-LABEL: @test_svst2_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i16> @llvm.vector.extract.nxv8i16.nxv16i16(<vscale x 16 x i16> [[DATA:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 8 x i16> @llvm.vector.extract.nxv8i16.nxv16i16(<vscale x 16 x i16> [[DATA]], i64 8)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv8i16(<vscale x 8 x i16> [[TMP0]], <vscale x 8 x i16> [[TMP1]], <vscale x 8 x i1> [[TMP2]], ptr [[BASE:%.*]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z14test_svst2_s16u10__SVBool_tPs11svint16x2_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i16> @llvm.vector.extract.nxv8i16.nxv16i16(<vscale x 16 x i16> [[DATA:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 8 x i16> @llvm.vector.extract.nxv8i16.nxv16i16(<vscale x 16 x i16> [[DATA]], i64 8)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv8i16(<vscale x 8 x i16> [[TMP0]], <vscale x 8 x i16> [[TMP1]], <vscale x 8 x i1> [[TMP2]], ptr [[BASE:%.*]])
// CPP-CHECK-NEXT:    ret void
//
void test_svst2_s16(svbool_t pg, int16_t *base, svint16x2_t data) MODE_ATTR
{
  return SVE_ACLE_FUNC(svst2,_s16,,)(pg, base, data);
}

// CHECK-LABEL: @test_svst2_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i32> @llvm.vector.extract.nxv4i32.nxv8i32(<vscale x 8 x i32> [[DATA:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x i32> @llvm.vector.extract.nxv4i32.nxv8i32(<vscale x 8 x i32> [[DATA]], i64 4)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv4i32(<vscale x 4 x i32> [[TMP0]], <vscale x 4 x i32> [[TMP1]], <vscale x 4 x i1> [[TMP2]], ptr [[BASE:%.*]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z14test_svst2_s32u10__SVBool_tPi11svint32x2_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i32> @llvm.vector.extract.nxv4i32.nxv8i32(<vscale x 8 x i32> [[DATA:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x i32> @llvm.vector.extract.nxv4i32.nxv8i32(<vscale x 8 x i32> [[DATA]], i64 4)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv4i32(<vscale x 4 x i32> [[TMP0]], <vscale x 4 x i32> [[TMP1]], <vscale x 4 x i1> [[TMP2]], ptr [[BASE:%.*]])
// CPP-CHECK-NEXT:    ret void
//
void test_svst2_s32(svbool_t pg, int32_t *base, svint32x2_t data) MODE_ATTR
{
  return SVE_ACLE_FUNC(svst2,_s32,,)(pg, base, data);
}

// CHECK-LABEL: @test_svst2_s64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i64> @llvm.vector.extract.nxv2i64.nxv4i64(<vscale x 4 x i64> [[DATA:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i64> @llvm.vector.extract.nxv2i64.nxv4i64(<vscale x 4 x i64> [[DATA]], i64 2)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv2i64(<vscale x 2 x i64> [[TMP0]], <vscale x 2 x i64> [[TMP1]], <vscale x 2 x i1> [[TMP2]], ptr [[BASE:%.*]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z14test_svst2_s64u10__SVBool_tPl11svint64x2_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i64> @llvm.vector.extract.nxv2i64.nxv4i64(<vscale x 4 x i64> [[DATA:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i64> @llvm.vector.extract.nxv2i64.nxv4i64(<vscale x 4 x i64> [[DATA]], i64 2)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv2i64(<vscale x 2 x i64> [[TMP0]], <vscale x 2 x i64> [[TMP1]], <vscale x 2 x i1> [[TMP2]], ptr [[BASE:%.*]])
// CPP-CHECK-NEXT:    ret void
//
void test_svst2_s64(svbool_t pg, int64_t *base, svint64x2_t data) MODE_ATTR
{
  return SVE_ACLE_FUNC(svst2,_s64,,)(pg, base, data);
}

// CHECK-LABEL: @test_svst2_u8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 16 x i8> @llvm.vector.extract.nxv16i8.nxv32i8(<vscale x 32 x i8> [[DATA:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 16 x i8> @llvm.vector.extract.nxv16i8.nxv32i8(<vscale x 32 x i8> [[DATA]], i64 16)
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv16i8(<vscale x 16 x i8> [[TMP0]], <vscale x 16 x i8> [[TMP1]], <vscale x 16 x i1> [[PG:%.*]], ptr [[BASE:%.*]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z13test_svst2_u8u10__SVBool_tPh11svuint8x2_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 16 x i8> @llvm.vector.extract.nxv16i8.nxv32i8(<vscale x 32 x i8> [[DATA:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 16 x i8> @llvm.vector.extract.nxv16i8.nxv32i8(<vscale x 32 x i8> [[DATA]], i64 16)
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv16i8(<vscale x 16 x i8> [[TMP0]], <vscale x 16 x i8> [[TMP1]], <vscale x 16 x i1> [[PG:%.*]], ptr [[BASE:%.*]])
// CPP-CHECK-NEXT:    ret void
//
void test_svst2_u8(svbool_t pg, uint8_t *base, svuint8x2_t data) MODE_ATTR
{
  return SVE_ACLE_FUNC(svst2,_u8,,)(pg, base, data);
}

// CHECK-LABEL: @test_svst2_u16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i16> @llvm.vector.extract.nxv8i16.nxv16i16(<vscale x 16 x i16> [[DATA:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 8 x i16> @llvm.vector.extract.nxv8i16.nxv16i16(<vscale x 16 x i16> [[DATA]], i64 8)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv8i16(<vscale x 8 x i16> [[TMP0]], <vscale x 8 x i16> [[TMP1]], <vscale x 8 x i1> [[TMP2]], ptr [[BASE:%.*]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z14test_svst2_u16u10__SVBool_tPt12svuint16x2_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i16> @llvm.vector.extract.nxv8i16.nxv16i16(<vscale x 16 x i16> [[DATA:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 8 x i16> @llvm.vector.extract.nxv8i16.nxv16i16(<vscale x 16 x i16> [[DATA]], i64 8)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv8i16(<vscale x 8 x i16> [[TMP0]], <vscale x 8 x i16> [[TMP1]], <vscale x 8 x i1> [[TMP2]], ptr [[BASE:%.*]])
// CPP-CHECK-NEXT:    ret void
//
void test_svst2_u16(svbool_t pg, uint16_t *base, svuint16x2_t data) MODE_ATTR
{
  return SVE_ACLE_FUNC(svst2,_u16,,)(pg, base, data);
}

// CHECK-LABEL: @test_svst2_u32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i32> @llvm.vector.extract.nxv4i32.nxv8i32(<vscale x 8 x i32> [[DATA:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x i32> @llvm.vector.extract.nxv4i32.nxv8i32(<vscale x 8 x i32> [[DATA]], i64 4)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv4i32(<vscale x 4 x i32> [[TMP0]], <vscale x 4 x i32> [[TMP1]], <vscale x 4 x i1> [[TMP2]], ptr [[BASE:%.*]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z14test_svst2_u32u10__SVBool_tPj12svuint32x2_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i32> @llvm.vector.extract.nxv4i32.nxv8i32(<vscale x 8 x i32> [[DATA:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x i32> @llvm.vector.extract.nxv4i32.nxv8i32(<vscale x 8 x i32> [[DATA]], i64 4)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv4i32(<vscale x 4 x i32> [[TMP0]], <vscale x 4 x i32> [[TMP1]], <vscale x 4 x i1> [[TMP2]], ptr [[BASE:%.*]])
// CPP-CHECK-NEXT:    ret void
//
void test_svst2_u32(svbool_t pg, uint32_t *base, svuint32x2_t data) MODE_ATTR
{
  return SVE_ACLE_FUNC(svst2,_u32,,)(pg, base, data);
}

// CHECK-LABEL: @test_svst2_u64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i64> @llvm.vector.extract.nxv2i64.nxv4i64(<vscale x 4 x i64> [[DATA:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i64> @llvm.vector.extract.nxv2i64.nxv4i64(<vscale x 4 x i64> [[DATA]], i64 2)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv2i64(<vscale x 2 x i64> [[TMP0]], <vscale x 2 x i64> [[TMP1]], <vscale x 2 x i1> [[TMP2]], ptr [[BASE:%.*]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z14test_svst2_u64u10__SVBool_tPm12svuint64x2_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i64> @llvm.vector.extract.nxv2i64.nxv4i64(<vscale x 4 x i64> [[DATA:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i64> @llvm.vector.extract.nxv2i64.nxv4i64(<vscale x 4 x i64> [[DATA]], i64 2)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv2i64(<vscale x 2 x i64> [[TMP0]], <vscale x 2 x i64> [[TMP1]], <vscale x 2 x i1> [[TMP2]], ptr [[BASE:%.*]])
// CPP-CHECK-NEXT:    ret void
//
void test_svst2_u64(svbool_t pg, uint64_t *base, svuint64x2_t data) MODE_ATTR
{
  return SVE_ACLE_FUNC(svst2,_u64,,)(pg, base, data);
}

// CHECK-LABEL: @test_svst2_f16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x half> @llvm.vector.extract.nxv8f16.nxv16f16(<vscale x 16 x half> [[DATA:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 8 x half> @llvm.vector.extract.nxv8f16.nxv16f16(<vscale x 16 x half> [[DATA]], i64 8)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv8f16(<vscale x 8 x half> [[TMP0]], <vscale x 8 x half> [[TMP1]], <vscale x 8 x i1> [[TMP2]], ptr [[BASE:%.*]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z14test_svst2_f16u10__SVBool_tPDh13svfloat16x2_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x half> @llvm.vector.extract.nxv8f16.nxv16f16(<vscale x 16 x half> [[DATA:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 8 x half> @llvm.vector.extract.nxv8f16.nxv16f16(<vscale x 16 x half> [[DATA]], i64 8)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv8f16(<vscale x 8 x half> [[TMP0]], <vscale x 8 x half> [[TMP1]], <vscale x 8 x i1> [[TMP2]], ptr [[BASE:%.*]])
// CPP-CHECK-NEXT:    ret void
//
void test_svst2_f16(svbool_t pg, float16_t *base, svfloat16x2_t data) MODE_ATTR
{
  return SVE_ACLE_FUNC(svst2,_f16,,)(pg, base, data);
}

// CHECK-LABEL: @test_svst2_f32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[DATA:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[DATA]], i64 4)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv4f32(<vscale x 4 x float> [[TMP0]], <vscale x 4 x float> [[TMP1]], <vscale x 4 x i1> [[TMP2]], ptr [[BASE:%.*]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z14test_svst2_f32u10__SVBool_tPf13svfloat32x2_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[DATA:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[DATA]], i64 4)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv4f32(<vscale x 4 x float> [[TMP0]], <vscale x 4 x float> [[TMP1]], <vscale x 4 x i1> [[TMP2]], ptr [[BASE:%.*]])
// CPP-CHECK-NEXT:    ret void
//
void test_svst2_f32(svbool_t pg, float32_t *base, svfloat32x2_t data) MODE_ATTR
{
  return SVE_ACLE_FUNC(svst2,_f32,,)(pg, base, data);
}

// CHECK-LABEL: @test_svst2_f64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv4f64(<vscale x 4 x double> [[DATA:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv4f64(<vscale x 4 x double> [[DATA]], i64 2)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv2f64(<vscale x 2 x double> [[TMP0]], <vscale x 2 x double> [[TMP1]], <vscale x 2 x i1> [[TMP2]], ptr [[BASE:%.*]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z14test_svst2_f64u10__SVBool_tPd13svfloat64x2_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv4f64(<vscale x 4 x double> [[DATA:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv4f64(<vscale x 4 x double> [[DATA]], i64 2)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv2f64(<vscale x 2 x double> [[TMP0]], <vscale x 2 x double> [[TMP1]], <vscale x 2 x i1> [[TMP2]], ptr [[BASE:%.*]])
// CPP-CHECK-NEXT:    ret void
//
void test_svst2_f64(svbool_t pg, float64_t *base, svfloat64x2_t data) MODE_ATTR
{
  return SVE_ACLE_FUNC(svst2,_f64,,)(pg, base, data);
}

// CHECK-LABEL: @test_svst2_vnum_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 16 x i8> @llvm.vector.extract.nxv16i8.nxv32i8(<vscale x 32 x i8> [[DATA:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 16 x i8> @llvm.vector.extract.nxv16i8.nxv32i8(<vscale x 32 x i8> [[DATA]], i64 16)
// CHECK-NEXT:    [[TMP2:%.*]] = getelementptr <vscale x 16 x i8>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv16i8(<vscale x 16 x i8> [[TMP0]], <vscale x 16 x i8> [[TMP1]], <vscale x 16 x i1> [[PG:%.*]], ptr [[TMP2]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z18test_svst2_vnum_s8u10__SVBool_tPal10svint8x2_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 16 x i8> @llvm.vector.extract.nxv16i8.nxv32i8(<vscale x 32 x i8> [[DATA:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 16 x i8> @llvm.vector.extract.nxv16i8.nxv32i8(<vscale x 32 x i8> [[DATA]], i64 16)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = getelementptr <vscale x 16 x i8>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv16i8(<vscale x 16 x i8> [[TMP0]], <vscale x 16 x i8> [[TMP1]], <vscale x 16 x i1> [[PG:%.*]], ptr [[TMP2]])
// CPP-CHECK-NEXT:    ret void
//
void test_svst2_vnum_s8(svbool_t pg, int8_t *base, int64_t vnum, svint8x2_t data) MODE_ATTR
{
  return SVE_ACLE_FUNC(svst2_vnum,_s8,,)(pg, base, vnum, data);
}

// CHECK-LABEL: @test_svst2_vnum_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i16> @llvm.vector.extract.nxv8i16.nxv16i16(<vscale x 16 x i16> [[DATA:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 8 x i16> @llvm.vector.extract.nxv8i16.nxv16i16(<vscale x 16 x i16> [[DATA]], i64 8)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP3:%.*]] = getelementptr <vscale x 8 x i16>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv8i16(<vscale x 8 x i16> [[TMP0]], <vscale x 8 x i16> [[TMP1]], <vscale x 8 x i1> [[TMP2]], ptr [[TMP3]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z19test_svst2_vnum_s16u10__SVBool_tPsl11svint16x2_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i16> @llvm.vector.extract.nxv8i16.nxv16i16(<vscale x 16 x i16> [[DATA:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 8 x i16> @llvm.vector.extract.nxv8i16.nxv16i16(<vscale x 16 x i16> [[DATA]], i64 8)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = getelementptr <vscale x 8 x i16>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv8i16(<vscale x 8 x i16> [[TMP0]], <vscale x 8 x i16> [[TMP1]], <vscale x 8 x i1> [[TMP2]], ptr [[TMP3]])
// CPP-CHECK-NEXT:    ret void
//
void test_svst2_vnum_s16(svbool_t pg, int16_t *base, int64_t vnum, svint16x2_t data) MODE_ATTR
{
  return SVE_ACLE_FUNC(svst2_vnum,_s16,,)(pg, base, vnum, data);
}

// CHECK-LABEL: @test_svst2_vnum_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i32> @llvm.vector.extract.nxv4i32.nxv8i32(<vscale x 8 x i32> [[DATA:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x i32> @llvm.vector.extract.nxv4i32.nxv8i32(<vscale x 8 x i32> [[DATA]], i64 4)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP3:%.*]] = getelementptr <vscale x 4 x i32>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv4i32(<vscale x 4 x i32> [[TMP0]], <vscale x 4 x i32> [[TMP1]], <vscale x 4 x i1> [[TMP2]], ptr [[TMP3]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z19test_svst2_vnum_s32u10__SVBool_tPil11svint32x2_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i32> @llvm.vector.extract.nxv4i32.nxv8i32(<vscale x 8 x i32> [[DATA:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x i32> @llvm.vector.extract.nxv4i32.nxv8i32(<vscale x 8 x i32> [[DATA]], i64 4)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = getelementptr <vscale x 4 x i32>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv4i32(<vscale x 4 x i32> [[TMP0]], <vscale x 4 x i32> [[TMP1]], <vscale x 4 x i1> [[TMP2]], ptr [[TMP3]])
// CPP-CHECK-NEXT:    ret void
//
void test_svst2_vnum_s32(svbool_t pg, int32_t *base, int64_t vnum, svint32x2_t data) MODE_ATTR
{
  return SVE_ACLE_FUNC(svst2_vnum,_s32,,)(pg, base, vnum, data);
}

// CHECK-LABEL: @test_svst2_vnum_s64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i64> @llvm.vector.extract.nxv2i64.nxv4i64(<vscale x 4 x i64> [[DATA:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i64> @llvm.vector.extract.nxv2i64.nxv4i64(<vscale x 4 x i64> [[DATA]], i64 2)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP3:%.*]] = getelementptr <vscale x 2 x i64>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv2i64(<vscale x 2 x i64> [[TMP0]], <vscale x 2 x i64> [[TMP1]], <vscale x 2 x i1> [[TMP2]], ptr [[TMP3]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z19test_svst2_vnum_s64u10__SVBool_tPll11svint64x2_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i64> @llvm.vector.extract.nxv2i64.nxv4i64(<vscale x 4 x i64> [[DATA:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i64> @llvm.vector.extract.nxv2i64.nxv4i64(<vscale x 4 x i64> [[DATA]], i64 2)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = getelementptr <vscale x 2 x i64>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv2i64(<vscale x 2 x i64> [[TMP0]], <vscale x 2 x i64> [[TMP1]], <vscale x 2 x i1> [[TMP2]], ptr [[TMP3]])
// CPP-CHECK-NEXT:    ret void
//
void test_svst2_vnum_s64(svbool_t pg, int64_t *base, int64_t vnum, svint64x2_t data) MODE_ATTR
{
  return SVE_ACLE_FUNC(svst2_vnum,_s64,,)(pg, base, vnum, data);
}

// CHECK-LABEL: @test_svst2_vnum_u8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 16 x i8> @llvm.vector.extract.nxv16i8.nxv32i8(<vscale x 32 x i8> [[DATA:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 16 x i8> @llvm.vector.extract.nxv16i8.nxv32i8(<vscale x 32 x i8> [[DATA]], i64 16)
// CHECK-NEXT:    [[TMP2:%.*]] = getelementptr <vscale x 16 x i8>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv16i8(<vscale x 16 x i8> [[TMP0]], <vscale x 16 x i8> [[TMP1]], <vscale x 16 x i1> [[PG:%.*]], ptr [[TMP2]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z18test_svst2_vnum_u8u10__SVBool_tPhl11svuint8x2_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 16 x i8> @llvm.vector.extract.nxv16i8.nxv32i8(<vscale x 32 x i8> [[DATA:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 16 x i8> @llvm.vector.extract.nxv16i8.nxv32i8(<vscale x 32 x i8> [[DATA]], i64 16)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = getelementptr <vscale x 16 x i8>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv16i8(<vscale x 16 x i8> [[TMP0]], <vscale x 16 x i8> [[TMP1]], <vscale x 16 x i1> [[PG:%.*]], ptr [[TMP2]])
// CPP-CHECK-NEXT:    ret void
//
void test_svst2_vnum_u8(svbool_t pg, uint8_t *base, int64_t vnum, svuint8x2_t data) MODE_ATTR
{
  return SVE_ACLE_FUNC(svst2_vnum,_u8,,)(pg, base, vnum, data);
}

// CHECK-LABEL: @test_svst2_vnum_u16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i16> @llvm.vector.extract.nxv8i16.nxv16i16(<vscale x 16 x i16> [[DATA:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 8 x i16> @llvm.vector.extract.nxv8i16.nxv16i16(<vscale x 16 x i16> [[DATA]], i64 8)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP3:%.*]] = getelementptr <vscale x 8 x i16>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv8i16(<vscale x 8 x i16> [[TMP0]], <vscale x 8 x i16> [[TMP1]], <vscale x 8 x i1> [[TMP2]], ptr [[TMP3]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z19test_svst2_vnum_u16u10__SVBool_tPtl12svuint16x2_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i16> @llvm.vector.extract.nxv8i16.nxv16i16(<vscale x 16 x i16> [[DATA:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 8 x i16> @llvm.vector.extract.nxv8i16.nxv16i16(<vscale x 16 x i16> [[DATA]], i64 8)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = getelementptr <vscale x 8 x i16>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv8i16(<vscale x 8 x i16> [[TMP0]], <vscale x 8 x i16> [[TMP1]], <vscale x 8 x i1> [[TMP2]], ptr [[TMP3]])
// CPP-CHECK-NEXT:    ret void
//
void test_svst2_vnum_u16(svbool_t pg, uint16_t *base, int64_t vnum, svuint16x2_t data) MODE_ATTR
{
  return SVE_ACLE_FUNC(svst2_vnum,_u16,,)(pg, base, vnum, data);
}

// CHECK-LABEL: @test_svst2_vnum_u32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i32> @llvm.vector.extract.nxv4i32.nxv8i32(<vscale x 8 x i32> [[DATA:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x i32> @llvm.vector.extract.nxv4i32.nxv8i32(<vscale x 8 x i32> [[DATA]], i64 4)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP3:%.*]] = getelementptr <vscale x 4 x i32>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv4i32(<vscale x 4 x i32> [[TMP0]], <vscale x 4 x i32> [[TMP1]], <vscale x 4 x i1> [[TMP2]], ptr [[TMP3]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z19test_svst2_vnum_u32u10__SVBool_tPjl12svuint32x2_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i32> @llvm.vector.extract.nxv4i32.nxv8i32(<vscale x 8 x i32> [[DATA:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x i32> @llvm.vector.extract.nxv4i32.nxv8i32(<vscale x 8 x i32> [[DATA]], i64 4)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = getelementptr <vscale x 4 x i32>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv4i32(<vscale x 4 x i32> [[TMP0]], <vscale x 4 x i32> [[TMP1]], <vscale x 4 x i1> [[TMP2]], ptr [[TMP3]])
// CPP-CHECK-NEXT:    ret void
//
void test_svst2_vnum_u32(svbool_t pg, uint32_t *base, int64_t vnum, svuint32x2_t data) MODE_ATTR
{
  return SVE_ACLE_FUNC(svst2_vnum,_u32,,)(pg, base, vnum, data);
}

// CHECK-LABEL: @test_svst2_vnum_u64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i64> @llvm.vector.extract.nxv2i64.nxv4i64(<vscale x 4 x i64> [[DATA:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i64> @llvm.vector.extract.nxv2i64.nxv4i64(<vscale x 4 x i64> [[DATA]], i64 2)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP3:%.*]] = getelementptr <vscale x 2 x i64>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv2i64(<vscale x 2 x i64> [[TMP0]], <vscale x 2 x i64> [[TMP1]], <vscale x 2 x i1> [[TMP2]], ptr [[TMP3]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z19test_svst2_vnum_u64u10__SVBool_tPml12svuint64x2_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i64> @llvm.vector.extract.nxv2i64.nxv4i64(<vscale x 4 x i64> [[DATA:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i64> @llvm.vector.extract.nxv2i64.nxv4i64(<vscale x 4 x i64> [[DATA]], i64 2)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = getelementptr <vscale x 2 x i64>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv2i64(<vscale x 2 x i64> [[TMP0]], <vscale x 2 x i64> [[TMP1]], <vscale x 2 x i1> [[TMP2]], ptr [[TMP3]])
// CPP-CHECK-NEXT:    ret void
//
void test_svst2_vnum_u64(svbool_t pg, uint64_t *base, int64_t vnum, svuint64x2_t data) MODE_ATTR
{
  return SVE_ACLE_FUNC(svst2_vnum,_u64,,)(pg, base, vnum, data);
}

// CHECK-LABEL: @test_svst2_vnum_f16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x half> @llvm.vector.extract.nxv8f16.nxv16f16(<vscale x 16 x half> [[DATA:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 8 x half> @llvm.vector.extract.nxv8f16.nxv16f16(<vscale x 16 x half> [[DATA]], i64 8)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP3:%.*]] = getelementptr <vscale x 8 x half>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv8f16(<vscale x 8 x half> [[TMP0]], <vscale x 8 x half> [[TMP1]], <vscale x 8 x i1> [[TMP2]], ptr [[TMP3]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z19test_svst2_vnum_f16u10__SVBool_tPDhl13svfloat16x2_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x half> @llvm.vector.extract.nxv8f16.nxv16f16(<vscale x 16 x half> [[DATA:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 8 x half> @llvm.vector.extract.nxv8f16.nxv16f16(<vscale x 16 x half> [[DATA]], i64 8)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = getelementptr <vscale x 8 x half>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv8f16(<vscale x 8 x half> [[TMP0]], <vscale x 8 x half> [[TMP1]], <vscale x 8 x i1> [[TMP2]], ptr [[TMP3]])
// CPP-CHECK-NEXT:    ret void
//
void test_svst2_vnum_f16(svbool_t pg, float16_t *base, int64_t vnum, svfloat16x2_t data) MODE_ATTR
{
  return SVE_ACLE_FUNC(svst2_vnum,_f16,,)(pg, base, vnum, data);
}

// CHECK-LABEL: @test_svst2_vnum_f32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[DATA:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[DATA]], i64 4)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP3:%.*]] = getelementptr <vscale x 4 x float>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv4f32(<vscale x 4 x float> [[TMP0]], <vscale x 4 x float> [[TMP1]], <vscale x 4 x i1> [[TMP2]], ptr [[TMP3]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z19test_svst2_vnum_f32u10__SVBool_tPfl13svfloat32x2_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[DATA:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[DATA]], i64 4)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = getelementptr <vscale x 4 x float>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv4f32(<vscale x 4 x float> [[TMP0]], <vscale x 4 x float> [[TMP1]], <vscale x 4 x i1> [[TMP2]], ptr [[TMP3]])
// CPP-CHECK-NEXT:    ret void
//
void test_svst2_vnum_f32(svbool_t pg, float32_t *base, int64_t vnum, svfloat32x2_t data) MODE_ATTR
{
  return SVE_ACLE_FUNC(svst2_vnum,_f32,,)(pg, base, vnum, data);
}

// CHECK-LABEL: @test_svst2_vnum_f64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv4f64(<vscale x 4 x double> [[DATA:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv4f64(<vscale x 4 x double> [[DATA]], i64 2)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP3:%.*]] = getelementptr <vscale x 2 x double>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv2f64(<vscale x 2 x double> [[TMP0]], <vscale x 2 x double> [[TMP1]], <vscale x 2 x i1> [[TMP2]], ptr [[TMP3]])
// CHECK-NEXT:    ret void
//
// CPP-CHECK-LABEL: @_Z19test_svst2_vnum_f64u10__SVBool_tPdl13svfloat64x2_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv4f64(<vscale x 4 x double> [[DATA:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x double> @llvm.vector.extract.nxv2f64.nxv4f64(<vscale x 4 x double> [[DATA]], i64 2)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = getelementptr <vscale x 2 x double>, ptr [[BASE:%.*]], i64 [[VNUM:%.*]]
// CPP-CHECK-NEXT:    tail call void @llvm.aarch64.sve.st2.nxv2f64(<vscale x 2 x double> [[TMP0]], <vscale x 2 x double> [[TMP1]], <vscale x 2 x i1> [[TMP2]], ptr [[TMP3]])
// CPP-CHECK-NEXT:    ret void
//
void test_svst2_vnum_f64(svbool_t pg, float64_t *base, int64_t vnum, svfloat64x2_t data) MODE_ATTR
{
  return SVE_ACLE_FUNC(svst2_vnum,_f64,,)(pg, base, vnum, data);
}
