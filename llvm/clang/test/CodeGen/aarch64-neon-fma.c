// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --function-signature
// RUN: %clang_cc1 -triple arm64-none-linux-gnu -target-feature +neon -disable-O0-optnone -emit-llvm -o - %s | opt -S -passes=mem2reg | FileCheck %s

// REQUIRES: aarch64-registered-target || arm-registered-target

#include <arm_neon.h>

// CHECK-LABEL: define {{[^@]+}}@test_vmla_n_f32
// CHECK-SAME: (<2 x float> noundef [[A:%.*]], <2 x float> noundef [[B:%.*]], float noundef [[C:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[VECINIT_I:%.*]] = insertelement <2 x float> poison, float [[C]], i32 0
// CHECK-NEXT:    [[VECINIT1_I:%.*]] = insertelement <2 x float> [[VECINIT_I]], float [[C]], i32 1
// CHECK-NEXT:    [[MUL_I:%.*]] = fmul <2 x float> [[B]], [[VECINIT1_I]]
// CHECK-NEXT:    [[ADD_I:%.*]] = fadd <2 x float> [[A]], [[MUL_I]]
// CHECK-NEXT:    ret <2 x float> [[ADD_I]]
//
float32x2_t test_vmla_n_f32(float32x2_t a, float32x2_t b, float32_t c) {
  return vmla_n_f32(a, b, c);
}

// CHECK-LABEL: define {{[^@]+}}@test_vmlaq_n_f32
// CHECK-SAME: (<4 x float> noundef [[A:%.*]], <4 x float> noundef [[B:%.*]], float noundef [[C:%.*]]) #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[VECINIT_I:%.*]] = insertelement <4 x float> poison, float [[C]], i32 0
// CHECK-NEXT:    [[VECINIT1_I:%.*]] = insertelement <4 x float> [[VECINIT_I]], float [[C]], i32 1
// CHECK-NEXT:    [[VECINIT2_I:%.*]] = insertelement <4 x float> [[VECINIT1_I]], float [[C]], i32 2
// CHECK-NEXT:    [[VECINIT3_I:%.*]] = insertelement <4 x float> [[VECINIT2_I]], float [[C]], i32 3
// CHECK-NEXT:    [[MUL_I:%.*]] = fmul <4 x float> [[B]], [[VECINIT3_I]]
// CHECK-NEXT:    [[ADD_I:%.*]] = fadd <4 x float> [[A]], [[MUL_I]]
// CHECK-NEXT:    ret <4 x float> [[ADD_I]]
//
float32x4_t test_vmlaq_n_f32(float32x4_t a, float32x4_t b, float32_t c) {
  return vmlaq_n_f32(a, b, c);
}

// CHECK-LABEL: define {{[^@]+}}@test_vmlsq_n_f32
// CHECK-SAME: (<4 x float> noundef [[A:%.*]], <4 x float> noundef [[B:%.*]], float noundef [[C:%.*]]) #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[VECINIT_I:%.*]] = insertelement <4 x float> poison, float [[C]], i32 0
// CHECK-NEXT:    [[VECINIT1_I:%.*]] = insertelement <4 x float> [[VECINIT_I]], float [[C]], i32 1
// CHECK-NEXT:    [[VECINIT2_I:%.*]] = insertelement <4 x float> [[VECINIT1_I]], float [[C]], i32 2
// CHECK-NEXT:    [[VECINIT3_I:%.*]] = insertelement <4 x float> [[VECINIT2_I]], float [[C]], i32 3
// CHECK-NEXT:    [[MUL_I:%.*]] = fmul <4 x float> [[B]], [[VECINIT3_I]]
// CHECK-NEXT:    [[SUB_I:%.*]] = fsub <4 x float> [[A]], [[MUL_I]]
// CHECK-NEXT:    ret <4 x float> [[SUB_I]]
//
float32x4_t test_vmlsq_n_f32(float32x4_t a, float32x4_t b, float32_t c) {
  return vmlsq_n_f32(a, b, c);
}

// CHECK-LABEL: define {{[^@]+}}@test_vmls_n_f32
// CHECK-SAME: (<2 x float> noundef [[A:%.*]], <2 x float> noundef [[B:%.*]], float noundef [[C:%.*]]) #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[VECINIT_I:%.*]] = insertelement <2 x float> poison, float [[C]], i32 0
// CHECK-NEXT:    [[VECINIT1_I:%.*]] = insertelement <2 x float> [[VECINIT_I]], float [[C]], i32 1
// CHECK-NEXT:    [[MUL_I:%.*]] = fmul <2 x float> [[B]], [[VECINIT1_I]]
// CHECK-NEXT:    [[SUB_I:%.*]] = fsub <2 x float> [[A]], [[MUL_I]]
// CHECK-NEXT:    ret <2 x float> [[SUB_I]]
//
float32x2_t test_vmls_n_f32(float32x2_t a, float32x2_t b, float32_t c) {
  return vmls_n_f32(a, b, c);
}

// CHECK-LABEL: define {{[^@]+}}@test_vmla_lane_f32_0
// CHECK-SAME: (<2 x float> noundef [[A:%.*]], <2 x float> noundef [[B:%.*]], <2 x float> noundef [[V:%.*]]) #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <2 x float> [[V]] to <8 x i8>
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x float>
// CHECK-NEXT:    [[LANE:%.*]] = shufflevector <2 x float> [[TMP1]], <2 x float> [[TMP1]], <2 x i32> zeroinitializer
// CHECK-NEXT:    [[MUL:%.*]] = fmul <2 x float> [[B]], [[LANE]]
// CHECK-NEXT:    [[ADD:%.*]] = fadd <2 x float> [[A]], [[MUL]]
// CHECK-NEXT:    ret <2 x float> [[ADD]]
//
float32x2_t test_vmla_lane_f32_0(float32x2_t a, float32x2_t b, float32x2_t v) {
  return vmla_lane_f32(a, b, v, 0);
}

// CHECK-LABEL: define {{[^@]+}}@test_vmlaq_lane_f32_0
// CHECK-SAME: (<4 x float> noundef [[A:%.*]], <4 x float> noundef [[B:%.*]], <2 x float> noundef [[V:%.*]]) #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <2 x float> [[V]] to <8 x i8>
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x float>
// CHECK-NEXT:    [[LANE:%.*]] = shufflevector <2 x float> [[TMP1]], <2 x float> [[TMP1]], <4 x i32> zeroinitializer
// CHECK-NEXT:    [[MUL:%.*]] = fmul <4 x float> [[B]], [[LANE]]
// CHECK-NEXT:    [[ADD:%.*]] = fadd <4 x float> [[A]], [[MUL]]
// CHECK-NEXT:    ret <4 x float> [[ADD]]
//
float32x4_t test_vmlaq_lane_f32_0(float32x4_t a, float32x4_t b, float32x2_t v) {
  return vmlaq_lane_f32(a, b, v, 0);
}

// CHECK-LABEL: define {{[^@]+}}@test_vmla_laneq_f32_0
// CHECK-SAME: (<2 x float> noundef [[A:%.*]], <2 x float> noundef [[B:%.*]], <4 x float> noundef [[V:%.*]]) #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <4 x float> [[V]] to <16 x i8>
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x float>
// CHECK-NEXT:    [[LANE:%.*]] = shufflevector <4 x float> [[TMP1]], <4 x float> [[TMP1]], <2 x i32> zeroinitializer
// CHECK-NEXT:    [[MUL:%.*]] = fmul <2 x float> [[B]], [[LANE]]
// CHECK-NEXT:    [[ADD:%.*]] = fadd <2 x float> [[A]], [[MUL]]
// CHECK-NEXT:    ret <2 x float> [[ADD]]
//
float32x2_t test_vmla_laneq_f32_0(float32x2_t a, float32x2_t b, float32x4_t v) {
  return vmla_laneq_f32(a, b, v, 0);
}

// CHECK-LABEL: define {{[^@]+}}@test_vmlaq_laneq_f32_0
// CHECK-SAME: (<4 x float> noundef [[A:%.*]], <4 x float> noundef [[B:%.*]], <4 x float> noundef [[V:%.*]]) #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <4 x float> [[V]] to <16 x i8>
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x float>
// CHECK-NEXT:    [[LANE:%.*]] = shufflevector <4 x float> [[TMP1]], <4 x float> [[TMP1]], <4 x i32> zeroinitializer
// CHECK-NEXT:    [[MUL:%.*]] = fmul <4 x float> [[B]], [[LANE]]
// CHECK-NEXT:    [[ADD:%.*]] = fadd <4 x float> [[A]], [[MUL]]
// CHECK-NEXT:    ret <4 x float> [[ADD]]
//
float32x4_t test_vmlaq_laneq_f32_0(float32x4_t a, float32x4_t b, float32x4_t v) {
  return vmlaq_laneq_f32(a, b, v, 0);
}

// CHECK-LABEL: define {{[^@]+}}@test_vmls_lane_f32_0
// CHECK-SAME: (<2 x float> noundef [[A:%.*]], <2 x float> noundef [[B:%.*]], <2 x float> noundef [[V:%.*]]) #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <2 x float> [[V]] to <8 x i8>
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x float>
// CHECK-NEXT:    [[LANE:%.*]] = shufflevector <2 x float> [[TMP1]], <2 x float> [[TMP1]], <2 x i32> zeroinitializer
// CHECK-NEXT:    [[MUL:%.*]] = fmul <2 x float> [[B]], [[LANE]]
// CHECK-NEXT:    [[SUB:%.*]] = fsub <2 x float> [[A]], [[MUL]]
// CHECK-NEXT:    ret <2 x float> [[SUB]]
//
float32x2_t test_vmls_lane_f32_0(float32x2_t a, float32x2_t b, float32x2_t v) {
  return vmls_lane_f32(a, b, v, 0);
}

// CHECK-LABEL: define {{[^@]+}}@test_vmlsq_lane_f32_0
// CHECK-SAME: (<4 x float> noundef [[A:%.*]], <4 x float> noundef [[B:%.*]], <2 x float> noundef [[V:%.*]]) #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <2 x float> [[V]] to <8 x i8>
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x float>
// CHECK-NEXT:    [[LANE:%.*]] = shufflevector <2 x float> [[TMP1]], <2 x float> [[TMP1]], <4 x i32> zeroinitializer
// CHECK-NEXT:    [[MUL:%.*]] = fmul <4 x float> [[B]], [[LANE]]
// CHECK-NEXT:    [[SUB:%.*]] = fsub <4 x float> [[A]], [[MUL]]
// CHECK-NEXT:    ret <4 x float> [[SUB]]
//
float32x4_t test_vmlsq_lane_f32_0(float32x4_t a, float32x4_t b, float32x2_t v) {
  return vmlsq_lane_f32(a, b, v, 0);
}

// CHECK-LABEL: define {{[^@]+}}@test_vmls_laneq_f32_0
// CHECK-SAME: (<2 x float> noundef [[A:%.*]], <2 x float> noundef [[B:%.*]], <4 x float> noundef [[V:%.*]]) #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <4 x float> [[V]] to <16 x i8>
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x float>
// CHECK-NEXT:    [[LANE:%.*]] = shufflevector <4 x float> [[TMP1]], <4 x float> [[TMP1]], <2 x i32> zeroinitializer
// CHECK-NEXT:    [[MUL:%.*]] = fmul <2 x float> [[B]], [[LANE]]
// CHECK-NEXT:    [[SUB:%.*]] = fsub <2 x float> [[A]], [[MUL]]
// CHECK-NEXT:    ret <2 x float> [[SUB]]
//
float32x2_t test_vmls_laneq_f32_0(float32x2_t a, float32x2_t b, float32x4_t v) {
  return vmls_laneq_f32(a, b, v, 0);
}

// CHECK-LABEL: define {{[^@]+}}@test_vmlsq_laneq_f32_0
// CHECK-SAME: (<4 x float> noundef [[A:%.*]], <4 x float> noundef [[B:%.*]], <4 x float> noundef [[V:%.*]]) #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <4 x float> [[V]] to <16 x i8>
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x float>
// CHECK-NEXT:    [[LANE:%.*]] = shufflevector <4 x float> [[TMP1]], <4 x float> [[TMP1]], <4 x i32> zeroinitializer
// CHECK-NEXT:    [[MUL:%.*]] = fmul <4 x float> [[B]], [[LANE]]
// CHECK-NEXT:    [[SUB:%.*]] = fsub <4 x float> [[A]], [[MUL]]
// CHECK-NEXT:    ret <4 x float> [[SUB]]
//
float32x4_t test_vmlsq_laneq_f32_0(float32x4_t a, float32x4_t b, float32x4_t v) {
  return vmlsq_laneq_f32(a, b, v, 0);
}

// CHECK-LABEL: define {{[^@]+}}@test_vmla_lane_f32
// CHECK-SAME: (<2 x float> noundef [[A:%.*]], <2 x float> noundef [[B:%.*]], <2 x float> noundef [[V:%.*]]) #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <2 x float> [[V]] to <8 x i8>
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x float>
// CHECK-NEXT:    [[LANE:%.*]] = shufflevector <2 x float> [[TMP1]], <2 x float> [[TMP1]], <2 x i32> <i32 1, i32 1>
// CHECK-NEXT:    [[MUL:%.*]] = fmul <2 x float> [[B]], [[LANE]]
// CHECK-NEXT:    [[ADD:%.*]] = fadd <2 x float> [[A]], [[MUL]]
// CHECK-NEXT:    ret <2 x float> [[ADD]]
//
float32x2_t test_vmla_lane_f32(float32x2_t a, float32x2_t b, float32x2_t v) {
  return vmla_lane_f32(a, b, v, 1);
}

// CHECK-LABEL: define {{[^@]+}}@test_vmlaq_lane_f32
// CHECK-SAME: (<4 x float> noundef [[A:%.*]], <4 x float> noundef [[B:%.*]], <2 x float> noundef [[V:%.*]]) #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <2 x float> [[V]] to <8 x i8>
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x float>
// CHECK-NEXT:    [[LANE:%.*]] = shufflevector <2 x float> [[TMP1]], <2 x float> [[TMP1]], <4 x i32> <i32 1, i32 1, i32 1, i32 1>
// CHECK-NEXT:    [[MUL:%.*]] = fmul <4 x float> [[B]], [[LANE]]
// CHECK-NEXT:    [[ADD:%.*]] = fadd <4 x float> [[A]], [[MUL]]
// CHECK-NEXT:    ret <4 x float> [[ADD]]
//
float32x4_t test_vmlaq_lane_f32(float32x4_t a, float32x4_t b, float32x2_t v) {
  return vmlaq_lane_f32(a, b, v, 1);
}

// CHECK-LABEL: define {{[^@]+}}@test_vmla_laneq_f32
// CHECK-SAME: (<2 x float> noundef [[A:%.*]], <2 x float> noundef [[B:%.*]], <4 x float> noundef [[V:%.*]]) #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <4 x float> [[V]] to <16 x i8>
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x float>
// CHECK-NEXT:    [[LANE:%.*]] = shufflevector <4 x float> [[TMP1]], <4 x float> [[TMP1]], <2 x i32> <i32 3, i32 3>
// CHECK-NEXT:    [[MUL:%.*]] = fmul <2 x float> [[B]], [[LANE]]
// CHECK-NEXT:    [[ADD:%.*]] = fadd <2 x float> [[A]], [[MUL]]
// CHECK-NEXT:    ret <2 x float> [[ADD]]
//
float32x2_t test_vmla_laneq_f32(float32x2_t a, float32x2_t b, float32x4_t v) {
  return vmla_laneq_f32(a, b, v, 3);
}

// CHECK-LABEL: define {{[^@]+}}@test_vmlaq_laneq_f32
// CHECK-SAME: (<4 x float> noundef [[A:%.*]], <4 x float> noundef [[B:%.*]], <4 x float> noundef [[V:%.*]]) #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <4 x float> [[V]] to <16 x i8>
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x float>
// CHECK-NEXT:    [[LANE:%.*]] = shufflevector <4 x float> [[TMP1]], <4 x float> [[TMP1]], <4 x i32> <i32 3, i32 3, i32 3, i32 3>
// CHECK-NEXT:    [[MUL:%.*]] = fmul <4 x float> [[B]], [[LANE]]
// CHECK-NEXT:    [[ADD:%.*]] = fadd <4 x float> [[A]], [[MUL]]
// CHECK-NEXT:    ret <4 x float> [[ADD]]
//
float32x4_t test_vmlaq_laneq_f32(float32x4_t a, float32x4_t b, float32x4_t v) {
  return vmlaq_laneq_f32(a, b, v, 3);
}

// CHECK-LABEL: define {{[^@]+}}@test_vmls_lane_f32
// CHECK-SAME: (<2 x float> noundef [[A:%.*]], <2 x float> noundef [[B:%.*]], <2 x float> noundef [[V:%.*]]) #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <2 x float> [[V]] to <8 x i8>
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x float>
// CHECK-NEXT:    [[LANE:%.*]] = shufflevector <2 x float> [[TMP1]], <2 x float> [[TMP1]], <2 x i32> <i32 1, i32 1>
// CHECK-NEXT:    [[MUL:%.*]] = fmul <2 x float> [[B]], [[LANE]]
// CHECK-NEXT:    [[SUB:%.*]] = fsub <2 x float> [[A]], [[MUL]]
// CHECK-NEXT:    ret <2 x float> [[SUB]]
//
float32x2_t test_vmls_lane_f32(float32x2_t a, float32x2_t b, float32x2_t v) {
  return vmls_lane_f32(a, b, v, 1);
}

// CHECK-LABEL: define {{[^@]+}}@test_vmlsq_lane_f32
// CHECK-SAME: (<4 x float> noundef [[A:%.*]], <4 x float> noundef [[B:%.*]], <2 x float> noundef [[V:%.*]]) #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <2 x float> [[V]] to <8 x i8>
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x float>
// CHECK-NEXT:    [[LANE:%.*]] = shufflevector <2 x float> [[TMP1]], <2 x float> [[TMP1]], <4 x i32> <i32 1, i32 1, i32 1, i32 1>
// CHECK-NEXT:    [[MUL:%.*]] = fmul <4 x float> [[B]], [[LANE]]
// CHECK-NEXT:    [[SUB:%.*]] = fsub <4 x float> [[A]], [[MUL]]
// CHECK-NEXT:    ret <4 x float> [[SUB]]
//
float32x4_t test_vmlsq_lane_f32(float32x4_t a, float32x4_t b, float32x2_t v) {
  return vmlsq_lane_f32(a, b, v, 1);
}
// CHECK-LABEL: define {{[^@]+}}@test_vmls_laneq_f32
// CHECK-SAME: (<2 x float> noundef [[A:%.*]], <2 x float> noundef [[B:%.*]], <4 x float> noundef [[V:%.*]]) #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <4 x float> [[V]] to <16 x i8>
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x float>
// CHECK-NEXT:    [[LANE:%.*]] = shufflevector <4 x float> [[TMP1]], <4 x float> [[TMP1]], <2 x i32> <i32 3, i32 3>
// CHECK-NEXT:    [[MUL:%.*]] = fmul <2 x float> [[B]], [[LANE]]
// CHECK-NEXT:    [[SUB:%.*]] = fsub <2 x float> [[A]], [[MUL]]
// CHECK-NEXT:    ret <2 x float> [[SUB]]
//
float32x2_t test_vmls_laneq_f32(float32x2_t a, float32x2_t b, float32x4_t v) {
  return vmls_laneq_f32(a, b, v, 3);
}

// CHECK-LABEL: define {{[^@]+}}@test_vmlsq_laneq_f32
// CHECK-SAME: (<4 x float> noundef [[A:%.*]], <4 x float> noundef [[B:%.*]], <4 x float> noundef [[V:%.*]]) #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <4 x float> [[V]] to <16 x i8>
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x float>
// CHECK-NEXT:    [[LANE:%.*]] = shufflevector <4 x float> [[TMP1]], <4 x float> [[TMP1]], <4 x i32> <i32 3, i32 3, i32 3, i32 3>
// CHECK-NEXT:    [[MUL:%.*]] = fmul <4 x float> [[B]], [[LANE]]
// CHECK-NEXT:    [[SUB:%.*]] = fsub <4 x float> [[A]], [[MUL]]
// CHECK-NEXT:    ret <4 x float> [[SUB]]
//
float32x4_t test_vmlsq_laneq_f32(float32x4_t a, float32x4_t b, float32x4_t v) {
  return vmlsq_laneq_f32(a, b, v, 3);
}

// CHECK-LABEL: define {{[^@]+}}@test_vfmaq_n_f64
// CHECK-SAME: (<2 x double> noundef [[A:%.*]], <2 x double> noundef [[B:%.*]], double noundef [[C:%.*]]) #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[VECINIT_I:%.*]] = insertelement <2 x double> poison, double [[C]], i32 0
// CHECK-NEXT:    [[VECINIT1_I:%.*]] = insertelement <2 x double> [[VECINIT_I]], double [[C]], i32 1
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <2 x double> [[A]] to <16 x i8>
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast <2 x double> [[B]] to <16 x i8>
// CHECK-NEXT:    [[TMP2:%.*]] = bitcast <2 x double> [[VECINIT1_I]] to <16 x i8>
// CHECK-NEXT:    [[TMP3:%.*]] = call <2 x double> @llvm.fma.v2f64(<2 x double> [[B]], <2 x double> [[VECINIT1_I]], <2 x double> [[A]])
// CHECK-NEXT:    ret <2 x double> [[TMP3]]
//
float64x2_t test_vfmaq_n_f64(float64x2_t a, float64x2_t b, float64_t c) {
  return vfmaq_n_f64(a, b, c);
}

// CHECK-LABEL: define {{[^@]+}}@test_vfmsq_n_f64
// CHECK-SAME: (<2 x double> noundef [[A:%.*]], <2 x double> noundef [[B:%.*]], double noundef [[C:%.*]]) #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[FNEG_I:%.*]] = fneg <2 x double> [[B]]
// CHECK-NEXT:    [[VECINIT_I:%.*]] = insertelement <2 x double> poison, double [[C]], i32 0
// CHECK-NEXT:    [[VECINIT1_I:%.*]] = insertelement <2 x double> [[VECINIT_I]], double [[C]], i32 1
// CHECK-NEXT:    [[TMP0:%.*]] = bitcast <2 x double> [[A]] to <16 x i8>
// CHECK-NEXT:    [[TMP1:%.*]] = bitcast <2 x double> [[FNEG_I]] to <16 x i8>
// CHECK-NEXT:    [[TMP2:%.*]] = bitcast <2 x double> [[VECINIT1_I]] to <16 x i8>
// CHECK-NEXT:    [[TMP3:%.*]] = call <2 x double> @llvm.fma.v2f64(<2 x double> [[FNEG_I]], <2 x double> [[VECINIT1_I]], <2 x double> [[A]])
// CHECK-NEXT:    ret <2 x double> [[TMP3]]
//
float64x2_t test_vfmsq_n_f64(float64x2_t a, float64x2_t b, float64_t c) {
  return vfmsq_n_f64(a, b, c);
}

