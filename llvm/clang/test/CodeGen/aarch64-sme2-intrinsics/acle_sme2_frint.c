// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py

// REQUIRES: aarch64-registered-target

// RUN: %clang_cc1 -triple aarch64 -target-feature +bf16 -target-feature +sme -target-feature +sme2 -disable-O0-optnone -Werror -Wall -emit-llvm -o - %s | opt -S -p mem2reg,instcombine,tailcallelim | FileCheck %s
// RUN: %clang_cc1 -triple aarch64 -target-feature +bf16 -target-feature +sme -target-feature +sme2 -disable-O0-optnone -Werror -Wall -emit-llvm -o - -x c++ %s | opt -S -p mem2reg,instcombine,tailcallelim | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64 -target-feature +bf16 -target-feature +sme -target-feature +sme2 -disable-O0-optnone -Werror -Wall -emit-llvm -o - %s | opt -S -p mem2reg,instcombine,tailcallelim | FileCheck %s
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64 -target-feature +bf16 -target-feature +sme -target-feature +sme2 -disable-O0-optnone -Werror -Wall -emit-llvm -o - -x c++ %s | opt -S -p mem2reg,instcombine,tailcallelim | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -triple aarch64 -target-feature +bf16 -target-feature +sme -target-feature +sme2 -S -disable-O0-optnone -Werror -Wall -o /dev/null %s

#include <arm_sme.h>

#ifdef SVE_OVERLOADED_FORMS
// A simple used,unused... macro, long enough to represent any SVE builtin.
#define SVE_ACLE_FUNC(A1,A2_UNUSED) A1
#else
#define SVE_ACLE_FUNC(A1,A2) A1##A2
#endif

// FRINTA

// CHECK-LABEL: @test_svfrinta_f32_x2(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[ZN:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[ZN]], i64 4)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call { <vscale x 4 x float>, <vscale x 4 x float> } @llvm.aarch64.sve.frinta.x2.nxv4f32(<vscale x 4 x float> [[TMP0]], <vscale x 4 x float> [[TMP1]])
// CHECK-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float> } [[TMP2]], 0
// CHECK-NEXT:    [[TMP4:%.*]] = tail call <vscale x 8 x float> @llvm.vector.insert.nxv8f32.nxv4f32(<vscale x 8 x float> poison, <vscale x 4 x float> [[TMP3]], i64 0)
// CHECK-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float> } [[TMP2]], 1
// CHECK-NEXT:    [[TMP6:%.*]] = tail call <vscale x 8 x float> @llvm.vector.insert.nxv8f32.nxv4f32(<vscale x 8 x float> [[TMP4]], <vscale x 4 x float> [[TMP5]], i64 4)
// CHECK-NEXT:    ret <vscale x 8 x float> [[TMP6]]
//
// CPP-CHECK-LABEL: @_Z20test_svfrinta_f32_x213svfloat32x2_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[ZN:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[ZN]], i64 4)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call { <vscale x 4 x float>, <vscale x 4 x float> } @llvm.aarch64.sve.frinta.x2.nxv4f32(<vscale x 4 x float> [[TMP0]], <vscale x 4 x float> [[TMP1]])
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float> } [[TMP2]], 0
// CPP-CHECK-NEXT:    [[TMP4:%.*]] = tail call <vscale x 8 x float> @llvm.vector.insert.nxv8f32.nxv4f32(<vscale x 8 x float> poison, <vscale x 4 x float> [[TMP3]], i64 0)
// CPP-CHECK-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float> } [[TMP2]], 1
// CPP-CHECK-NEXT:    [[TMP6:%.*]] = tail call <vscale x 8 x float> @llvm.vector.insert.nxv8f32.nxv4f32(<vscale x 8 x float> [[TMP4]], <vscale x 4 x float> [[TMP5]], i64 4)
// CPP-CHECK-NEXT:    ret <vscale x 8 x float> [[TMP6]]
//
svfloat32x2_t test_svfrinta_f32_x2(svfloat32x2_t zn) __arm_streaming {
  return SVE_ACLE_FUNC(svrinta,_f32_x2)(zn);
}

// CHECK-LABEL: @test_svfrinta_f32_x4(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 4)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 8)
// CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 12)
// CHECK-NEXT:    [[TMP4:%.*]] = tail call { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float> } @llvm.aarch64.sve.frinta.x4.nxv4f32(<vscale x 4 x float> [[TMP0]], <vscale x 4 x float> [[TMP1]], <vscale x 4 x float> [[TMP2]], <vscale x 4 x float> [[TMP3]])
// CHECK-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float> } [[TMP4]], 0
// CHECK-NEXT:    [[TMP6:%.*]] = tail call <vscale x 16 x float> @llvm.vector.insert.nxv16f32.nxv4f32(<vscale x 16 x float> poison, <vscale x 4 x float> [[TMP5]], i64 0)
// CHECK-NEXT:    [[TMP7:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float> } [[TMP4]], 1
// CHECK-NEXT:    [[TMP8:%.*]] = tail call <vscale x 16 x float> @llvm.vector.insert.nxv16f32.nxv4f32(<vscale x 16 x float> [[TMP6]], <vscale x 4 x float> [[TMP7]], i64 4)
// CHECK-NEXT:    [[TMP9:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float> } [[TMP4]], 2
// CHECK-NEXT:    [[TMP10:%.*]] = tail call <vscale x 16 x float> @llvm.vector.insert.nxv16f32.nxv4f32(<vscale x 16 x float> [[TMP8]], <vscale x 4 x float> [[TMP9]], i64 8)
// CHECK-NEXT:    [[TMP11:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float> } [[TMP4]], 3
// CHECK-NEXT:    [[TMP12:%.*]] = tail call <vscale x 16 x float> @llvm.vector.insert.nxv16f32.nxv4f32(<vscale x 16 x float> [[TMP10]], <vscale x 4 x float> [[TMP11]], i64 12)
// CHECK-NEXT:    ret <vscale x 16 x float> [[TMP12]]
//
// CPP-CHECK-LABEL: @_Z20test_svfrinta_f32_x413svfloat32x4_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 4)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 8)
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 12)
// CPP-CHECK-NEXT:    [[TMP4:%.*]] = tail call { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float> } @llvm.aarch64.sve.frinta.x4.nxv4f32(<vscale x 4 x float> [[TMP0]], <vscale x 4 x float> [[TMP1]], <vscale x 4 x float> [[TMP2]], <vscale x 4 x float> [[TMP3]])
// CPP-CHECK-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float> } [[TMP4]], 0
// CPP-CHECK-NEXT:    [[TMP6:%.*]] = tail call <vscale x 16 x float> @llvm.vector.insert.nxv16f32.nxv4f32(<vscale x 16 x float> poison, <vscale x 4 x float> [[TMP5]], i64 0)
// CPP-CHECK-NEXT:    [[TMP7:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float> } [[TMP4]], 1
// CPP-CHECK-NEXT:    [[TMP8:%.*]] = tail call <vscale x 16 x float> @llvm.vector.insert.nxv16f32.nxv4f32(<vscale x 16 x float> [[TMP6]], <vscale x 4 x float> [[TMP7]], i64 4)
// CPP-CHECK-NEXT:    [[TMP9:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float> } [[TMP4]], 2
// CPP-CHECK-NEXT:    [[TMP10:%.*]] = tail call <vscale x 16 x float> @llvm.vector.insert.nxv16f32.nxv4f32(<vscale x 16 x float> [[TMP8]], <vscale x 4 x float> [[TMP9]], i64 8)
// CPP-CHECK-NEXT:    [[TMP11:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float> } [[TMP4]], 3
// CPP-CHECK-NEXT:    [[TMP12:%.*]] = tail call <vscale x 16 x float> @llvm.vector.insert.nxv16f32.nxv4f32(<vscale x 16 x float> [[TMP10]], <vscale x 4 x float> [[TMP11]], i64 12)
// CPP-CHECK-NEXT:    ret <vscale x 16 x float> [[TMP12]]
//
svfloat32x4_t test_svfrinta_f32_x4(svfloat32x4_t zn) __arm_streaming {
  return SVE_ACLE_FUNC(svrinta,_f32_x4)(zn);
}

// FRINTM

// CHECK-LABEL: @test_svfrintam_f32_x2(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[ZN:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[ZN]], i64 4)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call { <vscale x 4 x float>, <vscale x 4 x float> } @llvm.aarch64.sve.frintm.x2.nxv4f32(<vscale x 4 x float> [[TMP0]], <vscale x 4 x float> [[TMP1]])
// CHECK-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float> } [[TMP2]], 0
// CHECK-NEXT:    [[TMP4:%.*]] = tail call <vscale x 8 x float> @llvm.vector.insert.nxv8f32.nxv4f32(<vscale x 8 x float> poison, <vscale x 4 x float> [[TMP3]], i64 0)
// CHECK-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float> } [[TMP2]], 1
// CHECK-NEXT:    [[TMP6:%.*]] = tail call <vscale x 8 x float> @llvm.vector.insert.nxv8f32.nxv4f32(<vscale x 8 x float> [[TMP4]], <vscale x 4 x float> [[TMP5]], i64 4)
// CHECK-NEXT:    ret <vscale x 8 x float> [[TMP6]]
//
// CPP-CHECK-LABEL: @_Z21test_svfrintam_f32_x213svfloat32x2_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[ZN:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[ZN]], i64 4)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call { <vscale x 4 x float>, <vscale x 4 x float> } @llvm.aarch64.sve.frintm.x2.nxv4f32(<vscale x 4 x float> [[TMP0]], <vscale x 4 x float> [[TMP1]])
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float> } [[TMP2]], 0
// CPP-CHECK-NEXT:    [[TMP4:%.*]] = tail call <vscale x 8 x float> @llvm.vector.insert.nxv8f32.nxv4f32(<vscale x 8 x float> poison, <vscale x 4 x float> [[TMP3]], i64 0)
// CPP-CHECK-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float> } [[TMP2]], 1
// CPP-CHECK-NEXT:    [[TMP6:%.*]] = tail call <vscale x 8 x float> @llvm.vector.insert.nxv8f32.nxv4f32(<vscale x 8 x float> [[TMP4]], <vscale x 4 x float> [[TMP5]], i64 4)
// CPP-CHECK-NEXT:    ret <vscale x 8 x float> [[TMP6]]
//
svfloat32x2_t test_svfrintam_f32_x2(svfloat32x2_t zn) __arm_streaming {
  return SVE_ACLE_FUNC(svrintm,_f32_x2)(zn);
}

// CHECK-LABEL: @test_svfrintm_f32_x4(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 4)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 8)
// CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 12)
// CHECK-NEXT:    [[TMP4:%.*]] = tail call { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float> } @llvm.aarch64.sve.frintm.x4.nxv4f32(<vscale x 4 x float> [[TMP0]], <vscale x 4 x float> [[TMP1]], <vscale x 4 x float> [[TMP2]], <vscale x 4 x float> [[TMP3]])
// CHECK-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float> } [[TMP4]], 0
// CHECK-NEXT:    [[TMP6:%.*]] = tail call <vscale x 16 x float> @llvm.vector.insert.nxv16f32.nxv4f32(<vscale x 16 x float> poison, <vscale x 4 x float> [[TMP5]], i64 0)
// CHECK-NEXT:    [[TMP7:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float> } [[TMP4]], 1
// CHECK-NEXT:    [[TMP8:%.*]] = tail call <vscale x 16 x float> @llvm.vector.insert.nxv16f32.nxv4f32(<vscale x 16 x float> [[TMP6]], <vscale x 4 x float> [[TMP7]], i64 4)
// CHECK-NEXT:    [[TMP9:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float> } [[TMP4]], 2
// CHECK-NEXT:    [[TMP10:%.*]] = tail call <vscale x 16 x float> @llvm.vector.insert.nxv16f32.nxv4f32(<vscale x 16 x float> [[TMP8]], <vscale x 4 x float> [[TMP9]], i64 8)
// CHECK-NEXT:    [[TMP11:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float> } [[TMP4]], 3
// CHECK-NEXT:    [[TMP12:%.*]] = tail call <vscale x 16 x float> @llvm.vector.insert.nxv16f32.nxv4f32(<vscale x 16 x float> [[TMP10]], <vscale x 4 x float> [[TMP11]], i64 12)
// CHECK-NEXT:    ret <vscale x 16 x float> [[TMP12]]
//
// CPP-CHECK-LABEL: @_Z20test_svfrintm_f32_x413svfloat32x4_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 4)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 8)
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 12)
// CPP-CHECK-NEXT:    [[TMP4:%.*]] = tail call { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float> } @llvm.aarch64.sve.frintm.x4.nxv4f32(<vscale x 4 x float> [[TMP0]], <vscale x 4 x float> [[TMP1]], <vscale x 4 x float> [[TMP2]], <vscale x 4 x float> [[TMP3]])
// CPP-CHECK-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float> } [[TMP4]], 0
// CPP-CHECK-NEXT:    [[TMP6:%.*]] = tail call <vscale x 16 x float> @llvm.vector.insert.nxv16f32.nxv4f32(<vscale x 16 x float> poison, <vscale x 4 x float> [[TMP5]], i64 0)
// CPP-CHECK-NEXT:    [[TMP7:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float> } [[TMP4]], 1
// CPP-CHECK-NEXT:    [[TMP8:%.*]] = tail call <vscale x 16 x float> @llvm.vector.insert.nxv16f32.nxv4f32(<vscale x 16 x float> [[TMP6]], <vscale x 4 x float> [[TMP7]], i64 4)
// CPP-CHECK-NEXT:    [[TMP9:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float> } [[TMP4]], 2
// CPP-CHECK-NEXT:    [[TMP10:%.*]] = tail call <vscale x 16 x float> @llvm.vector.insert.nxv16f32.nxv4f32(<vscale x 16 x float> [[TMP8]], <vscale x 4 x float> [[TMP9]], i64 8)
// CPP-CHECK-NEXT:    [[TMP11:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float> } [[TMP4]], 3
// CPP-CHECK-NEXT:    [[TMP12:%.*]] = tail call <vscale x 16 x float> @llvm.vector.insert.nxv16f32.nxv4f32(<vscale x 16 x float> [[TMP10]], <vscale x 4 x float> [[TMP11]], i64 12)
// CPP-CHECK-NEXT:    ret <vscale x 16 x float> [[TMP12]]
//
svfloat32x4_t test_svfrintm_f32_x4(svfloat32x4_t zn) __arm_streaming {
  return SVE_ACLE_FUNC(svrintm,_f32_x4)(zn);
}

// FRINTN

// CHECK-LABEL: @test_svfrintn_f32_x2(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[ZN:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[ZN]], i64 4)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call { <vscale x 4 x float>, <vscale x 4 x float> } @llvm.aarch64.sve.frintn.x2.nxv4f32(<vscale x 4 x float> [[TMP0]], <vscale x 4 x float> [[TMP1]])
// CHECK-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float> } [[TMP2]], 0
// CHECK-NEXT:    [[TMP4:%.*]] = tail call <vscale x 8 x float> @llvm.vector.insert.nxv8f32.nxv4f32(<vscale x 8 x float> poison, <vscale x 4 x float> [[TMP3]], i64 0)
// CHECK-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float> } [[TMP2]], 1
// CHECK-NEXT:    [[TMP6:%.*]] = tail call <vscale x 8 x float> @llvm.vector.insert.nxv8f32.nxv4f32(<vscale x 8 x float> [[TMP4]], <vscale x 4 x float> [[TMP5]], i64 4)
// CHECK-NEXT:    ret <vscale x 8 x float> [[TMP6]]
//
// CPP-CHECK-LABEL: @_Z20test_svfrintn_f32_x213svfloat32x2_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[ZN:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[ZN]], i64 4)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call { <vscale x 4 x float>, <vscale x 4 x float> } @llvm.aarch64.sve.frintn.x2.nxv4f32(<vscale x 4 x float> [[TMP0]], <vscale x 4 x float> [[TMP1]])
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float> } [[TMP2]], 0
// CPP-CHECK-NEXT:    [[TMP4:%.*]] = tail call <vscale x 8 x float> @llvm.vector.insert.nxv8f32.nxv4f32(<vscale x 8 x float> poison, <vscale x 4 x float> [[TMP3]], i64 0)
// CPP-CHECK-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float> } [[TMP2]], 1
// CPP-CHECK-NEXT:    [[TMP6:%.*]] = tail call <vscale x 8 x float> @llvm.vector.insert.nxv8f32.nxv4f32(<vscale x 8 x float> [[TMP4]], <vscale x 4 x float> [[TMP5]], i64 4)
// CPP-CHECK-NEXT:    ret <vscale x 8 x float> [[TMP6]]
//
svfloat32x2_t test_svfrintn_f32_x2(svfloat32x2_t zn) __arm_streaming {
  return SVE_ACLE_FUNC(svrintn,_f32_x2)(zn);
}

// CHECK-LABEL: @test_svfrintn_f32_x4(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 4)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 8)
// CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 12)
// CHECK-NEXT:    [[TMP4:%.*]] = tail call { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float> } @llvm.aarch64.sve.frintn.x4.nxv4f32(<vscale x 4 x float> [[TMP0]], <vscale x 4 x float> [[TMP1]], <vscale x 4 x float> [[TMP2]], <vscale x 4 x float> [[TMP3]])
// CHECK-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float> } [[TMP4]], 0
// CHECK-NEXT:    [[TMP6:%.*]] = tail call <vscale x 16 x float> @llvm.vector.insert.nxv16f32.nxv4f32(<vscale x 16 x float> poison, <vscale x 4 x float> [[TMP5]], i64 0)
// CHECK-NEXT:    [[TMP7:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float> } [[TMP4]], 1
// CHECK-NEXT:    [[TMP8:%.*]] = tail call <vscale x 16 x float> @llvm.vector.insert.nxv16f32.nxv4f32(<vscale x 16 x float> [[TMP6]], <vscale x 4 x float> [[TMP7]], i64 4)
// CHECK-NEXT:    [[TMP9:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float> } [[TMP4]], 2
// CHECK-NEXT:    [[TMP10:%.*]] = tail call <vscale x 16 x float> @llvm.vector.insert.nxv16f32.nxv4f32(<vscale x 16 x float> [[TMP8]], <vscale x 4 x float> [[TMP9]], i64 8)
// CHECK-NEXT:    [[TMP11:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float> } [[TMP4]], 3
// CHECK-NEXT:    [[TMP12:%.*]] = tail call <vscale x 16 x float> @llvm.vector.insert.nxv16f32.nxv4f32(<vscale x 16 x float> [[TMP10]], <vscale x 4 x float> [[TMP11]], i64 12)
// CHECK-NEXT:    ret <vscale x 16 x float> [[TMP12]]
//
// CPP-CHECK-LABEL: @_Z20test_svfrintn_f32_x413svfloat32x4_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 4)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 8)
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 12)
// CPP-CHECK-NEXT:    [[TMP4:%.*]] = tail call { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float> } @llvm.aarch64.sve.frintn.x4.nxv4f32(<vscale x 4 x float> [[TMP0]], <vscale x 4 x float> [[TMP1]], <vscale x 4 x float> [[TMP2]], <vscale x 4 x float> [[TMP3]])
// CPP-CHECK-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float> } [[TMP4]], 0
// CPP-CHECK-NEXT:    [[TMP6:%.*]] = tail call <vscale x 16 x float> @llvm.vector.insert.nxv16f32.nxv4f32(<vscale x 16 x float> poison, <vscale x 4 x float> [[TMP5]], i64 0)
// CPP-CHECK-NEXT:    [[TMP7:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float> } [[TMP4]], 1
// CPP-CHECK-NEXT:    [[TMP8:%.*]] = tail call <vscale x 16 x float> @llvm.vector.insert.nxv16f32.nxv4f32(<vscale x 16 x float> [[TMP6]], <vscale x 4 x float> [[TMP7]], i64 4)
// CPP-CHECK-NEXT:    [[TMP9:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float> } [[TMP4]], 2
// CPP-CHECK-NEXT:    [[TMP10:%.*]] = tail call <vscale x 16 x float> @llvm.vector.insert.nxv16f32.nxv4f32(<vscale x 16 x float> [[TMP8]], <vscale x 4 x float> [[TMP9]], i64 8)
// CPP-CHECK-NEXT:    [[TMP11:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float> } [[TMP4]], 3
// CPP-CHECK-NEXT:    [[TMP12:%.*]] = tail call <vscale x 16 x float> @llvm.vector.insert.nxv16f32.nxv4f32(<vscale x 16 x float> [[TMP10]], <vscale x 4 x float> [[TMP11]], i64 12)
// CPP-CHECK-NEXT:    ret <vscale x 16 x float> [[TMP12]]
//
svfloat32x4_t test_svfrintn_f32_x4(svfloat32x4_t zn) __arm_streaming {
  return SVE_ACLE_FUNC(svrintn,_f32_x4)(zn);
}

// FRINTP

// CHECK-LABEL: @test_svfrintp_f32_x2(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[ZN:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[ZN]], i64 4)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call { <vscale x 4 x float>, <vscale x 4 x float> } @llvm.aarch64.sve.frintp.x2.nxv4f32(<vscale x 4 x float> [[TMP0]], <vscale x 4 x float> [[TMP1]])
// CHECK-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float> } [[TMP2]], 0
// CHECK-NEXT:    [[TMP4:%.*]] = tail call <vscale x 8 x float> @llvm.vector.insert.nxv8f32.nxv4f32(<vscale x 8 x float> poison, <vscale x 4 x float> [[TMP3]], i64 0)
// CHECK-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float> } [[TMP2]], 1
// CHECK-NEXT:    [[TMP6:%.*]] = tail call <vscale x 8 x float> @llvm.vector.insert.nxv8f32.nxv4f32(<vscale x 8 x float> [[TMP4]], <vscale x 4 x float> [[TMP5]], i64 4)
// CHECK-NEXT:    ret <vscale x 8 x float> [[TMP6]]
//
// CPP-CHECK-LABEL: @_Z20test_svfrintp_f32_x213svfloat32x2_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[ZN:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv8f32(<vscale x 8 x float> [[ZN]], i64 4)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call { <vscale x 4 x float>, <vscale x 4 x float> } @llvm.aarch64.sve.frintp.x2.nxv4f32(<vscale x 4 x float> [[TMP0]], <vscale x 4 x float> [[TMP1]])
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float> } [[TMP2]], 0
// CPP-CHECK-NEXT:    [[TMP4:%.*]] = tail call <vscale x 8 x float> @llvm.vector.insert.nxv8f32.nxv4f32(<vscale x 8 x float> poison, <vscale x 4 x float> [[TMP3]], i64 0)
// CPP-CHECK-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float> } [[TMP2]], 1
// CPP-CHECK-NEXT:    [[TMP6:%.*]] = tail call <vscale x 8 x float> @llvm.vector.insert.nxv8f32.nxv4f32(<vscale x 8 x float> [[TMP4]], <vscale x 4 x float> [[TMP5]], i64 4)
// CPP-CHECK-NEXT:    ret <vscale x 8 x float> [[TMP6]]
//
svfloat32x2_t test_svfrintp_f32_x2(svfloat32x2_t zn) __arm_streaming {
  return SVE_ACLE_FUNC(svrintp,_f32_x2)(zn);
}

// CHECK-LABEL: @test_svfrintp_f32_x4(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN:%.*]], i64 0)
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 4)
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 8)
// CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 12)
// CHECK-NEXT:    [[TMP4:%.*]] = tail call { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float> } @llvm.aarch64.sve.frintp.x4.nxv4f32(<vscale x 4 x float> [[TMP0]], <vscale x 4 x float> [[TMP1]], <vscale x 4 x float> [[TMP2]], <vscale x 4 x float> [[TMP3]])
// CHECK-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float> } [[TMP4]], 0
// CHECK-NEXT:    [[TMP6:%.*]] = tail call <vscale x 16 x float> @llvm.vector.insert.nxv16f32.nxv4f32(<vscale x 16 x float> poison, <vscale x 4 x float> [[TMP5]], i64 0)
// CHECK-NEXT:    [[TMP7:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float> } [[TMP4]], 1
// CHECK-NEXT:    [[TMP8:%.*]] = tail call <vscale x 16 x float> @llvm.vector.insert.nxv16f32.nxv4f32(<vscale x 16 x float> [[TMP6]], <vscale x 4 x float> [[TMP7]], i64 4)
// CHECK-NEXT:    [[TMP9:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float> } [[TMP4]], 2
// CHECK-NEXT:    [[TMP10:%.*]] = tail call <vscale x 16 x float> @llvm.vector.insert.nxv16f32.nxv4f32(<vscale x 16 x float> [[TMP8]], <vscale x 4 x float> [[TMP9]], i64 8)
// CHECK-NEXT:    [[TMP11:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float> } [[TMP4]], 3
// CHECK-NEXT:    [[TMP12:%.*]] = tail call <vscale x 16 x float> @llvm.vector.insert.nxv16f32.nxv4f32(<vscale x 16 x float> [[TMP10]], <vscale x 4 x float> [[TMP11]], i64 12)
// CHECK-NEXT:    ret <vscale x 16 x float> [[TMP12]]
//
// CPP-CHECK-LABEL: @_Z20test_svfrintp_f32_x413svfloat32x4_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN:%.*]], i64 0)
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 4)
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 8)
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 4 x float> @llvm.vector.extract.nxv4f32.nxv16f32(<vscale x 16 x float> [[ZN]], i64 12)
// CPP-CHECK-NEXT:    [[TMP4:%.*]] = tail call { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float> } @llvm.aarch64.sve.frintp.x4.nxv4f32(<vscale x 4 x float> [[TMP0]], <vscale x 4 x float> [[TMP1]], <vscale x 4 x float> [[TMP2]], <vscale x 4 x float> [[TMP3]])
// CPP-CHECK-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float> } [[TMP4]], 0
// CPP-CHECK-NEXT:    [[TMP6:%.*]] = tail call <vscale x 16 x float> @llvm.vector.insert.nxv16f32.nxv4f32(<vscale x 16 x float> poison, <vscale x 4 x float> [[TMP5]], i64 0)
// CPP-CHECK-NEXT:    [[TMP7:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float> } [[TMP4]], 1
// CPP-CHECK-NEXT:    [[TMP8:%.*]] = tail call <vscale x 16 x float> @llvm.vector.insert.nxv16f32.nxv4f32(<vscale x 16 x float> [[TMP6]], <vscale x 4 x float> [[TMP7]], i64 4)
// CPP-CHECK-NEXT:    [[TMP9:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float> } [[TMP4]], 2
// CPP-CHECK-NEXT:    [[TMP10:%.*]] = tail call <vscale x 16 x float> @llvm.vector.insert.nxv16f32.nxv4f32(<vscale x 16 x float> [[TMP8]], <vscale x 4 x float> [[TMP9]], i64 8)
// CPP-CHECK-NEXT:    [[TMP11:%.*]] = extractvalue { <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float>, <vscale x 4 x float> } [[TMP4]], 3
// CPP-CHECK-NEXT:    [[TMP12:%.*]] = tail call <vscale x 16 x float> @llvm.vector.insert.nxv16f32.nxv4f32(<vscale x 16 x float> [[TMP10]], <vscale x 4 x float> [[TMP11]], i64 12)
// CPP-CHECK-NEXT:    ret <vscale x 16 x float> [[TMP12]]
//
svfloat32x4_t test_svfrintp_f32_x4(svfloat32x4_t zn) __arm_streaming {
  return SVE_ACLE_FUNC(svrintp,_f32_x4)(zn);
}
