// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: aarch64-registered-target
// RUN: %clang_cc1 -triple aarch64 -target-feature +sve -disable-O0-optnone -Werror -emit-llvm -o - %s | opt -S -passes=mem2reg,instcombine,tailcallelim | FileCheck %s
// RUN: %clang_cc1 -triple aarch64 -target-feature +sve -disable-O0-optnone -Werror -emit-llvm -o - -x c++ %s | opt -S -passes=mem2reg,instcombine,tailcallelim | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64 -target-feature +sve -disable-O0-optnone -Werror -emit-llvm -o - %s | opt -S -passes=mem2reg,instcombine,tailcallelim | FileCheck %s
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64 -target-feature +sve -disable-O0-optnone -Werror -emit-llvm -o - -x c++ %s | opt -S -passes=mem2reg,instcombine,tailcallelim | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -triple aarch64 -target-feature +sve -S -disable-O0-optnone -Werror -o /dev/null %s
// RUN: %clang_cc1 -triple aarch64 -target-feature +sme -S -disable-O0-optnone -Werror -o /dev/null %s

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

// CHECK-LABEL: @test_svld1sw_s64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i32> @llvm.masked.load.nxv2i32.p0(ptr [[BASE:%.*]], i32 1, <vscale x 2 x i1> [[TMP0]], <vscale x 2 x i32> zeroinitializer)
// CHECK-NEXT:    [[TMP2:%.*]] = sext <vscale x 2 x i32> [[TMP1]] to <vscale x 2 x i64>
// CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP2]]
//
// CPP-CHECK-LABEL: @_Z16test_svld1sw_s64u10__SVBool_tPKi(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i32> @llvm.masked.load.nxv2i32.p0(ptr [[BASE:%.*]], i32 1, <vscale x 2 x i1> [[TMP0]], <vscale x 2 x i32> zeroinitializer)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = sext <vscale x 2 x i32> [[TMP1]] to <vscale x 2 x i64>
// CPP-CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP2]]
//
svint64_t test_svld1sw_s64(svbool_t pg, const int32_t *base) MODE_ATTR
{
  return svld1sw_s64(pg, base);
}

// CHECK-LABEL: @test_svld1sw_u64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i32> @llvm.masked.load.nxv2i32.p0(ptr [[BASE:%.*]], i32 1, <vscale x 2 x i1> [[TMP0]], <vscale x 2 x i32> zeroinitializer)
// CHECK-NEXT:    [[TMP2:%.*]] = sext <vscale x 2 x i32> [[TMP1]] to <vscale x 2 x i64>
// CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP2]]
//
// CPP-CHECK-LABEL: @_Z16test_svld1sw_u64u10__SVBool_tPKi(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i32> @llvm.masked.load.nxv2i32.p0(ptr [[BASE:%.*]], i32 1, <vscale x 2 x i1> [[TMP0]], <vscale x 2 x i32> zeroinitializer)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = sext <vscale x 2 x i32> [[TMP1]] to <vscale x 2 x i64>
// CPP-CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP2]]
//
svuint64_t test_svld1sw_u64(svbool_t pg, const int32_t *base) MODE_ATTR
{
  return svld1sw_u64(pg, base);
}

// CHECK-LABEL: @test_svld1sw_vnum_s64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call i64 @llvm.vscale.i64()
// CHECK-NEXT:    [[TMP2:%.*]] = shl nuw nsw i64 [[TMP1]], 3
// CHECK-NEXT:    [[DOTIDX:%.*]] = mul i64 [[VNUM:%.*]], [[TMP2]]
// CHECK-NEXT:    [[TMP3:%.*]] = getelementptr i8, ptr [[BASE:%.*]], i64 [[DOTIDX]]
// CHECK-NEXT:    [[TMP4:%.*]] = tail call <vscale x 2 x i32> @llvm.masked.load.nxv2i32.p0(ptr [[TMP3]], i32 1, <vscale x 2 x i1> [[TMP0]], <vscale x 2 x i32> zeroinitializer)
// CHECK-NEXT:    [[TMP5:%.*]] = sext <vscale x 2 x i32> [[TMP4]] to <vscale x 2 x i64>
// CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP5]]
//
// CPP-CHECK-LABEL: @_Z21test_svld1sw_vnum_s64u10__SVBool_tPKil(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call i64 @llvm.vscale.i64()
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = shl nuw nsw i64 [[TMP1]], 3
// CPP-CHECK-NEXT:    [[DOTIDX:%.*]] = mul i64 [[VNUM:%.*]], [[TMP2]]
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = getelementptr i8, ptr [[BASE:%.*]], i64 [[DOTIDX]]
// CPP-CHECK-NEXT:    [[TMP4:%.*]] = tail call <vscale x 2 x i32> @llvm.masked.load.nxv2i32.p0(ptr [[TMP3]], i32 1, <vscale x 2 x i1> [[TMP0]], <vscale x 2 x i32> zeroinitializer)
// CPP-CHECK-NEXT:    [[TMP5:%.*]] = sext <vscale x 2 x i32> [[TMP4]] to <vscale x 2 x i64>
// CPP-CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP5]]
//
svint64_t test_svld1sw_vnum_s64(svbool_t pg, const int32_t *base, int64_t vnum) MODE_ATTR
{
  return svld1sw_vnum_s64(pg, base, vnum);
}

// CHECK-LABEL: @test_svld1sw_vnum_u64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call i64 @llvm.vscale.i64()
// CHECK-NEXT:    [[TMP2:%.*]] = shl nuw nsw i64 [[TMP1]], 3
// CHECK-NEXT:    [[DOTIDX:%.*]] = mul i64 [[VNUM:%.*]], [[TMP2]]
// CHECK-NEXT:    [[TMP3:%.*]] = getelementptr i8, ptr [[BASE:%.*]], i64 [[DOTIDX]]
// CHECK-NEXT:    [[TMP4:%.*]] = tail call <vscale x 2 x i32> @llvm.masked.load.nxv2i32.p0(ptr [[TMP3]], i32 1, <vscale x 2 x i1> [[TMP0]], <vscale x 2 x i32> zeroinitializer)
// CHECK-NEXT:    [[TMP5:%.*]] = sext <vscale x 2 x i32> [[TMP4]] to <vscale x 2 x i64>
// CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP5]]
//
// CPP-CHECK-LABEL: @_Z21test_svld1sw_vnum_u64u10__SVBool_tPKil(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call i64 @llvm.vscale.i64()
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = shl nuw nsw i64 [[TMP1]], 3
// CPP-CHECK-NEXT:    [[DOTIDX:%.*]] = mul i64 [[VNUM:%.*]], [[TMP2]]
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = getelementptr i8, ptr [[BASE:%.*]], i64 [[DOTIDX]]
// CPP-CHECK-NEXT:    [[TMP4:%.*]] = tail call <vscale x 2 x i32> @llvm.masked.load.nxv2i32.p0(ptr [[TMP3]], i32 1, <vscale x 2 x i1> [[TMP0]], <vscale x 2 x i32> zeroinitializer)
// CPP-CHECK-NEXT:    [[TMP5:%.*]] = sext <vscale x 2 x i32> [[TMP4]] to <vscale x 2 x i64>
// CPP-CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP5]]
//
svuint64_t test_svld1sw_vnum_u64(svbool_t pg, const int32_t *base, int64_t vnum) MODE_ATTR
{
  return svld1sw_vnum_u64(pg, base, vnum);
}

#ifndef __ARM_FEATURE_SME

// CHECK-LABEL: @test_svld1sw_gather_u64base_s64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i32> @llvm.aarch64.sve.ld1.gather.scalar.offset.nxv2i32.nxv2i64(<vscale x 2 x i1> [[TMP0]], <vscale x 2 x i64> [[BASES:%.*]], i64 0)
// CHECK-NEXT:    [[TMP2:%.*]] = sext <vscale x 2 x i32> [[TMP1]] to <vscale x 2 x i64>
// CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP2]]
//
// CPP-CHECK-LABEL: @_Z31test_svld1sw_gather_u64base_s64u10__SVBool_tu12__SVUint64_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i32> @llvm.aarch64.sve.ld1.gather.scalar.offset.nxv2i32.nxv2i64(<vscale x 2 x i1> [[TMP0]], <vscale x 2 x i64> [[BASES:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = sext <vscale x 2 x i32> [[TMP1]] to <vscale x 2 x i64>
// CPP-CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP2]]
//
svint64_t test_svld1sw_gather_u64base_s64(svbool_t pg, svuint64_t bases) {
  return SVE_ACLE_FUNC(svld1sw_gather, _u64base, _s64, )(pg, bases);
}

// CHECK-LABEL: @test_svld1sw_gather_u64base_u64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i32> @llvm.aarch64.sve.ld1.gather.scalar.offset.nxv2i32.nxv2i64(<vscale x 2 x i1> [[TMP0]], <vscale x 2 x i64> [[BASES:%.*]], i64 0)
// CHECK-NEXT:    [[TMP2:%.*]] = sext <vscale x 2 x i32> [[TMP1]] to <vscale x 2 x i64>
// CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP2]]
//
// CPP-CHECK-LABEL: @_Z31test_svld1sw_gather_u64base_u64u10__SVBool_tu12__SVUint64_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i32> @llvm.aarch64.sve.ld1.gather.scalar.offset.nxv2i32.nxv2i64(<vscale x 2 x i1> [[TMP0]], <vscale x 2 x i64> [[BASES:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = sext <vscale x 2 x i32> [[TMP1]] to <vscale x 2 x i64>
// CPP-CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP2]]
//
svuint64_t test_svld1sw_gather_u64base_u64(svbool_t pg, svuint64_t bases) {
  return SVE_ACLE_FUNC(svld1sw_gather, _u64base, _u64, )(pg, bases);
}

// CHECK-LABEL: @test_svld1sw_gather_s64offset_s64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i32> @llvm.aarch64.sve.ld1.gather.nxv2i32(<vscale x 2 x i1> [[TMP0]], ptr [[BASE:%.*]], <vscale x 2 x i64> [[OFFSETS:%.*]])
// CHECK-NEXT:    [[TMP2:%.*]] = sext <vscale x 2 x i32> [[TMP1]] to <vscale x 2 x i64>
// CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP2]]
//
// CPP-CHECK-LABEL: @_Z33test_svld1sw_gather_s64offset_s64u10__SVBool_tPKiu11__SVInt64_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i32> @llvm.aarch64.sve.ld1.gather.nxv2i32(<vscale x 2 x i1> [[TMP0]], ptr [[BASE:%.*]], <vscale x 2 x i64> [[OFFSETS:%.*]])
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = sext <vscale x 2 x i32> [[TMP1]] to <vscale x 2 x i64>
// CPP-CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP2]]
//
svint64_t test_svld1sw_gather_s64offset_s64(svbool_t pg, const int32_t *base, svint64_t offsets) {
  return SVE_ACLE_FUNC(svld1sw_gather_, s64, offset_s64, )(pg, base, offsets);
}

// CHECK-LABEL: @test_svld1sw_gather_s64offset_u64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i32> @llvm.aarch64.sve.ld1.gather.nxv2i32(<vscale x 2 x i1> [[TMP0]], ptr [[BASE:%.*]], <vscale x 2 x i64> [[OFFSETS:%.*]])
// CHECK-NEXT:    [[TMP2:%.*]] = sext <vscale x 2 x i32> [[TMP1]] to <vscale x 2 x i64>
// CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP2]]
//
// CPP-CHECK-LABEL: @_Z33test_svld1sw_gather_s64offset_u64u10__SVBool_tPKiu11__SVInt64_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i32> @llvm.aarch64.sve.ld1.gather.nxv2i32(<vscale x 2 x i1> [[TMP0]], ptr [[BASE:%.*]], <vscale x 2 x i64> [[OFFSETS:%.*]])
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = sext <vscale x 2 x i32> [[TMP1]] to <vscale x 2 x i64>
// CPP-CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP2]]
//
svuint64_t test_svld1sw_gather_s64offset_u64(svbool_t pg, const int32_t *base, svint64_t offsets) {
  return SVE_ACLE_FUNC(svld1sw_gather_, s64, offset_u64, )(pg, base, offsets);
}

// CHECK-LABEL: @test_svld1sw_gather_u64offset_s64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i32> @llvm.aarch64.sve.ld1.gather.nxv2i32(<vscale x 2 x i1> [[TMP0]], ptr [[BASE:%.*]], <vscale x 2 x i64> [[OFFSETS:%.*]])
// CHECK-NEXT:    [[TMP2:%.*]] = sext <vscale x 2 x i32> [[TMP1]] to <vscale x 2 x i64>
// CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP2]]
//
// CPP-CHECK-LABEL: @_Z33test_svld1sw_gather_u64offset_s64u10__SVBool_tPKiu12__SVUint64_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i32> @llvm.aarch64.sve.ld1.gather.nxv2i32(<vscale x 2 x i1> [[TMP0]], ptr [[BASE:%.*]], <vscale x 2 x i64> [[OFFSETS:%.*]])
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = sext <vscale x 2 x i32> [[TMP1]] to <vscale x 2 x i64>
// CPP-CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP2]]
//
svint64_t test_svld1sw_gather_u64offset_s64(svbool_t pg, const int32_t *base, svuint64_t offsets) {
  return SVE_ACLE_FUNC(svld1sw_gather_, u64, offset_s64, )(pg, base, offsets);
}

// CHECK-LABEL: @test_svld1sw_gather_u64offset_u64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i32> @llvm.aarch64.sve.ld1.gather.nxv2i32(<vscale x 2 x i1> [[TMP0]], ptr [[BASE:%.*]], <vscale x 2 x i64> [[OFFSETS:%.*]])
// CHECK-NEXT:    [[TMP2:%.*]] = sext <vscale x 2 x i32> [[TMP1]] to <vscale x 2 x i64>
// CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP2]]
//
// CPP-CHECK-LABEL: @_Z33test_svld1sw_gather_u64offset_u64u10__SVBool_tPKiu12__SVUint64_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i32> @llvm.aarch64.sve.ld1.gather.nxv2i32(<vscale x 2 x i1> [[TMP0]], ptr [[BASE:%.*]], <vscale x 2 x i64> [[OFFSETS:%.*]])
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = sext <vscale x 2 x i32> [[TMP1]] to <vscale x 2 x i64>
// CPP-CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP2]]
//
svuint64_t test_svld1sw_gather_u64offset_u64(svbool_t pg, const int32_t *base, svuint64_t offsets) {
  return SVE_ACLE_FUNC(svld1sw_gather_, u64, offset_u64, )(pg, base, offsets);
}

// CHECK-LABEL: @test_svld1sw_gather_u64base_offset_s64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i32> @llvm.aarch64.sve.ld1.gather.scalar.offset.nxv2i32.nxv2i64(<vscale x 2 x i1> [[TMP0]], <vscale x 2 x i64> [[BASES:%.*]], i64 [[OFFSET:%.*]])
// CHECK-NEXT:    [[TMP2:%.*]] = sext <vscale x 2 x i32> [[TMP1]] to <vscale x 2 x i64>
// CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP2]]
//
// CPP-CHECK-LABEL: @_Z38test_svld1sw_gather_u64base_offset_s64u10__SVBool_tu12__SVUint64_tl(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i32> @llvm.aarch64.sve.ld1.gather.scalar.offset.nxv2i32.nxv2i64(<vscale x 2 x i1> [[TMP0]], <vscale x 2 x i64> [[BASES:%.*]], i64 [[OFFSET:%.*]])
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = sext <vscale x 2 x i32> [[TMP1]] to <vscale x 2 x i64>
// CPP-CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP2]]
//
svint64_t test_svld1sw_gather_u64base_offset_s64(svbool_t pg, svuint64_t bases, int64_t offset) {
  return SVE_ACLE_FUNC(svld1sw_gather, _u64base, _offset_s64, )(pg, bases, offset);
}

// CHECK-LABEL: @test_svld1sw_gather_u64base_offset_u64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i32> @llvm.aarch64.sve.ld1.gather.scalar.offset.nxv2i32.nxv2i64(<vscale x 2 x i1> [[TMP0]], <vscale x 2 x i64> [[BASES:%.*]], i64 [[OFFSET:%.*]])
// CHECK-NEXT:    [[TMP2:%.*]] = sext <vscale x 2 x i32> [[TMP1]] to <vscale x 2 x i64>
// CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP2]]
//
// CPP-CHECK-LABEL: @_Z38test_svld1sw_gather_u64base_offset_u64u10__SVBool_tu12__SVUint64_tl(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i32> @llvm.aarch64.sve.ld1.gather.scalar.offset.nxv2i32.nxv2i64(<vscale x 2 x i1> [[TMP0]], <vscale x 2 x i64> [[BASES:%.*]], i64 [[OFFSET:%.*]])
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = sext <vscale x 2 x i32> [[TMP1]] to <vscale x 2 x i64>
// CPP-CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP2]]
//
svuint64_t test_svld1sw_gather_u64base_offset_u64(svbool_t pg, svuint64_t bases, int64_t offset) {
  return SVE_ACLE_FUNC(svld1sw_gather, _u64base, _offset_u64, )(pg, bases, offset);
}

// CHECK-LABEL: @test_svld1sw_gather_s64index_s64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i32> @llvm.aarch64.sve.ld1.gather.index.nxv2i32(<vscale x 2 x i1> [[TMP0]], ptr [[BASE:%.*]], <vscale x 2 x i64> [[INDICES:%.*]])
// CHECK-NEXT:    [[TMP2:%.*]] = sext <vscale x 2 x i32> [[TMP1]] to <vscale x 2 x i64>
// CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP2]]
//
// CPP-CHECK-LABEL: @_Z32test_svld1sw_gather_s64index_s64u10__SVBool_tPKiu11__SVInt64_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i32> @llvm.aarch64.sve.ld1.gather.index.nxv2i32(<vscale x 2 x i1> [[TMP0]], ptr [[BASE:%.*]], <vscale x 2 x i64> [[INDICES:%.*]])
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = sext <vscale x 2 x i32> [[TMP1]] to <vscale x 2 x i64>
// CPP-CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP2]]
//
svint64_t test_svld1sw_gather_s64index_s64(svbool_t pg, const int32_t *base, svint64_t indices) {
  return SVE_ACLE_FUNC(svld1sw_gather_, s64, index_s64, )(pg, base, indices);
}

// CHECK-LABEL: @test_svld1sw_gather_s64index_u64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i32> @llvm.aarch64.sve.ld1.gather.index.nxv2i32(<vscale x 2 x i1> [[TMP0]], ptr [[BASE:%.*]], <vscale x 2 x i64> [[INDICES:%.*]])
// CHECK-NEXT:    [[TMP2:%.*]] = sext <vscale x 2 x i32> [[TMP1]] to <vscale x 2 x i64>
// CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP2]]
//
// CPP-CHECK-LABEL: @_Z32test_svld1sw_gather_s64index_u64u10__SVBool_tPKiu11__SVInt64_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i32> @llvm.aarch64.sve.ld1.gather.index.nxv2i32(<vscale x 2 x i1> [[TMP0]], ptr [[BASE:%.*]], <vscale x 2 x i64> [[INDICES:%.*]])
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = sext <vscale x 2 x i32> [[TMP1]] to <vscale x 2 x i64>
// CPP-CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP2]]
//
svuint64_t test_svld1sw_gather_s64index_u64(svbool_t pg, const int32_t *base, svint64_t indices) {
  return SVE_ACLE_FUNC(svld1sw_gather_, s64, index_u64, )(pg, base, indices);
}

// CHECK-LABEL: @test_svld1sw_gather_u64index_s64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i32> @llvm.aarch64.sve.ld1.gather.index.nxv2i32(<vscale x 2 x i1> [[TMP0]], ptr [[BASE:%.*]], <vscale x 2 x i64> [[INDICES:%.*]])
// CHECK-NEXT:    [[TMP2:%.*]] = sext <vscale x 2 x i32> [[TMP1]] to <vscale x 2 x i64>
// CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP2]]
//
// CPP-CHECK-LABEL: @_Z32test_svld1sw_gather_u64index_s64u10__SVBool_tPKiu12__SVUint64_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i32> @llvm.aarch64.sve.ld1.gather.index.nxv2i32(<vscale x 2 x i1> [[TMP0]], ptr [[BASE:%.*]], <vscale x 2 x i64> [[INDICES:%.*]])
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = sext <vscale x 2 x i32> [[TMP1]] to <vscale x 2 x i64>
// CPP-CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP2]]
//
svint64_t test_svld1sw_gather_u64index_s64(svbool_t pg, const int32_t *base, svuint64_t indices) {
  return SVE_ACLE_FUNC(svld1sw_gather_, u64, index_s64, )(pg, base, indices);
}

// CHECK-LABEL: @test_svld1sw_gather_u64index_u64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i32> @llvm.aarch64.sve.ld1.gather.index.nxv2i32(<vscale x 2 x i1> [[TMP0]], ptr [[BASE:%.*]], <vscale x 2 x i64> [[INDICES:%.*]])
// CHECK-NEXT:    [[TMP2:%.*]] = sext <vscale x 2 x i32> [[TMP1]] to <vscale x 2 x i64>
// CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP2]]
//
// CPP-CHECK-LABEL: @_Z32test_svld1sw_gather_u64index_u64u10__SVBool_tPKiu12__SVUint64_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i32> @llvm.aarch64.sve.ld1.gather.index.nxv2i32(<vscale x 2 x i1> [[TMP0]], ptr [[BASE:%.*]], <vscale x 2 x i64> [[INDICES:%.*]])
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = sext <vscale x 2 x i32> [[TMP1]] to <vscale x 2 x i64>
// CPP-CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP2]]
//
svuint64_t test_svld1sw_gather_u64index_u64(svbool_t pg, const int32_t *base, svuint64_t indices) {
  return SVE_ACLE_FUNC(svld1sw_gather_, u64, index_u64, )(pg, base, indices);
}

// CHECK-LABEL: @test_svld1sw_gather_u64base_index_s64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = shl i64 [[INDEX:%.*]], 2
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 2 x i32> @llvm.aarch64.sve.ld1.gather.scalar.offset.nxv2i32.nxv2i64(<vscale x 2 x i1> [[TMP0]], <vscale x 2 x i64> [[BASES:%.*]], i64 [[TMP1]])
// CHECK-NEXT:    [[TMP3:%.*]] = sext <vscale x 2 x i32> [[TMP2]] to <vscale x 2 x i64>
// CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP3]]
//
// CPP-CHECK-LABEL: @_Z37test_svld1sw_gather_u64base_index_s64u10__SVBool_tu12__SVUint64_tl(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = shl i64 [[INDEX:%.*]], 2
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 2 x i32> @llvm.aarch64.sve.ld1.gather.scalar.offset.nxv2i32.nxv2i64(<vscale x 2 x i1> [[TMP0]], <vscale x 2 x i64> [[BASES:%.*]], i64 [[TMP1]])
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = sext <vscale x 2 x i32> [[TMP2]] to <vscale x 2 x i64>
// CPP-CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP3]]
//
svint64_t test_svld1sw_gather_u64base_index_s64(svbool_t pg, svuint64_t bases, int64_t index) {
  return SVE_ACLE_FUNC(svld1sw_gather, _u64base, _index_s64, )(pg, bases, index);
}

// CHECK-LABEL: @test_svld1sw_gather_u64base_index_u64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = shl i64 [[INDEX:%.*]], 2
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 2 x i32> @llvm.aarch64.sve.ld1.gather.scalar.offset.nxv2i32.nxv2i64(<vscale x 2 x i1> [[TMP0]], <vscale x 2 x i64> [[BASES:%.*]], i64 [[TMP1]])
// CHECK-NEXT:    [[TMP3:%.*]] = sext <vscale x 2 x i32> [[TMP2]] to <vscale x 2 x i64>
// CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP3]]
//
// CPP-CHECK-LABEL: @_Z37test_svld1sw_gather_u64base_index_u64u10__SVBool_tu12__SVUint64_tl(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = shl i64 [[INDEX:%.*]], 2
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 2 x i32> @llvm.aarch64.sve.ld1.gather.scalar.offset.nxv2i32.nxv2i64(<vscale x 2 x i1> [[TMP0]], <vscale x 2 x i64> [[BASES:%.*]], i64 [[TMP1]])
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = sext <vscale x 2 x i32> [[TMP2]] to <vscale x 2 x i64>
// CPP-CHECK-NEXT:    ret <vscale x 2 x i64> [[TMP3]]
//
svuint64_t test_svld1sw_gather_u64base_index_u64(svbool_t pg, svuint64_t bases, int64_t index) {
  return SVE_ACLE_FUNC(svld1sw_gather, _u64base, _index_u64, )(pg, bases, index);
}

#endif
