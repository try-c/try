// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 2
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +zvfhmin -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x float> @test_vfwcvt_f_f_v_f32mf2_tu
// CHECK-RV64-SAME: (<vscale x 1 x float> [[MASKEDOFF:%.*]], <vscale x 1 x half> [[SRC:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x float> @llvm.riscv.vfwcvt.f.f.v.nxv1f32.nxv1f16.i64(<vscale x 1 x float> [[MASKEDOFF]], <vscale x 1 x half> [[SRC]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x float> [[TMP0]]
//
vfloat32mf2_t test_vfwcvt_f_f_v_f32mf2_tu(vfloat32mf2_t maskedoff, vfloat16mf4_t src, size_t vl) {
  return __riscv_vfwcvt_f_tu(maskedoff, src, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x float> @test_vfwcvt_f_f_v_f32m1_tu
// CHECK-RV64-SAME: (<vscale x 2 x float> [[MASKEDOFF:%.*]], <vscale x 2 x half> [[SRC:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x float> @llvm.riscv.vfwcvt.f.f.v.nxv2f32.nxv2f16.i64(<vscale x 2 x float> [[MASKEDOFF]], <vscale x 2 x half> [[SRC]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x float> [[TMP0]]
//
vfloat32m1_t test_vfwcvt_f_f_v_f32m1_tu(vfloat32m1_t maskedoff, vfloat16mf2_t src, size_t vl) {
  return __riscv_vfwcvt_f_tu(maskedoff, src, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x float> @test_vfwcvt_f_f_v_f32m2_tu
// CHECK-RV64-SAME: (<vscale x 4 x float> [[MASKEDOFF:%.*]], <vscale x 4 x half> [[SRC:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x float> @llvm.riscv.vfwcvt.f.f.v.nxv4f32.nxv4f16.i64(<vscale x 4 x float> [[MASKEDOFF]], <vscale x 4 x half> [[SRC]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x float> [[TMP0]]
//
vfloat32m2_t test_vfwcvt_f_f_v_f32m2_tu(vfloat32m2_t maskedoff, vfloat16m1_t src, size_t vl) {
  return __riscv_vfwcvt_f_tu(maskedoff, src, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x float> @test_vfwcvt_f_f_v_f32m4_tu
// CHECK-RV64-SAME: (<vscale x 8 x float> [[MASKEDOFF:%.*]], <vscale x 8 x half> [[SRC:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x float> @llvm.riscv.vfwcvt.f.f.v.nxv8f32.nxv8f16.i64(<vscale x 8 x float> [[MASKEDOFF]], <vscale x 8 x half> [[SRC]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x float> [[TMP0]]
//
vfloat32m4_t test_vfwcvt_f_f_v_f32m4_tu(vfloat32m4_t maskedoff, vfloat16m2_t src, size_t vl) {
  return __riscv_vfwcvt_f_tu(maskedoff, src, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x float> @test_vfwcvt_f_f_v_f32m8_tu
// CHECK-RV64-SAME: (<vscale x 16 x float> [[MASKEDOFF:%.*]], <vscale x 16 x half> [[SRC:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x float> @llvm.riscv.vfwcvt.f.f.v.nxv16f32.nxv16f16.i64(<vscale x 16 x float> [[MASKEDOFF]], <vscale x 16 x half> [[SRC]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 16 x float> [[TMP0]]
//
vfloat32m8_t test_vfwcvt_f_f_v_f32m8_tu(vfloat32m8_t maskedoff, vfloat16m4_t src, size_t vl) {
  return __riscv_vfwcvt_f_tu(maskedoff, src, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x double> @test_vfwcvt_f_f_v_f64m1_tu
// CHECK-RV64-SAME: (<vscale x 1 x double> [[MASKEDOFF:%.*]], <vscale x 1 x float> [[SRC:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vfwcvt.f.f.v.nxv1f64.nxv1f32.i64(<vscale x 1 x double> [[MASKEDOFF]], <vscale x 1 x float> [[SRC]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
vfloat64m1_t test_vfwcvt_f_f_v_f64m1_tu(vfloat64m1_t maskedoff, vfloat32mf2_t src, size_t vl) {
  return __riscv_vfwcvt_f_tu(maskedoff, src, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x double> @test_vfwcvt_f_f_v_f64m2_tu
// CHECK-RV64-SAME: (<vscale x 2 x double> [[MASKEDOFF:%.*]], <vscale x 2 x float> [[SRC:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x double> @llvm.riscv.vfwcvt.f.f.v.nxv2f64.nxv2f32.i64(<vscale x 2 x double> [[MASKEDOFF]], <vscale x 2 x float> [[SRC]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x double> [[TMP0]]
//
vfloat64m2_t test_vfwcvt_f_f_v_f64m2_tu(vfloat64m2_t maskedoff, vfloat32m1_t src, size_t vl) {
  return __riscv_vfwcvt_f_tu(maskedoff, src, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x double> @test_vfwcvt_f_f_v_f64m4_tu
// CHECK-RV64-SAME: (<vscale x 4 x double> [[MASKEDOFF:%.*]], <vscale x 4 x float> [[SRC:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x double> @llvm.riscv.vfwcvt.f.f.v.nxv4f64.nxv4f32.i64(<vscale x 4 x double> [[MASKEDOFF]], <vscale x 4 x float> [[SRC]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x double> [[TMP0]]
//
vfloat64m4_t test_vfwcvt_f_f_v_f64m4_tu(vfloat64m4_t maskedoff, vfloat32m2_t src, size_t vl) {
  return __riscv_vfwcvt_f_tu(maskedoff, src, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x double> @test_vfwcvt_f_f_v_f64m8_tu
// CHECK-RV64-SAME: (<vscale x 8 x double> [[MASKEDOFF:%.*]], <vscale x 8 x float> [[SRC:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x double> @llvm.riscv.vfwcvt.f.f.v.nxv8f64.nxv8f32.i64(<vscale x 8 x double> [[MASKEDOFF]], <vscale x 8 x float> [[SRC]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x double> [[TMP0]]
//
vfloat64m8_t test_vfwcvt_f_f_v_f64m8_tu(vfloat64m8_t maskedoff, vfloat32m4_t src, size_t vl) {
  return __riscv_vfwcvt_f_tu(maskedoff, src, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x float> @test_vfwcvt_f_f_v_f32mf2_tum
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], <vscale x 1 x float> [[MASKEDOFF:%.*]], <vscale x 1 x half> [[SRC:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x float> @llvm.riscv.vfwcvt.f.f.v.mask.nxv1f32.nxv1f16.i64(<vscale x 1 x float> [[MASKEDOFF]], <vscale x 1 x half> [[SRC]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 1 x float> [[TMP0]]
//
vfloat32mf2_t test_vfwcvt_f_f_v_f32mf2_tum(vbool64_t mask, vfloat32mf2_t maskedoff, vfloat16mf4_t src, size_t vl) {
  return __riscv_vfwcvt_f_tum(mask, maskedoff, src, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x float> @test_vfwcvt_f_f_v_f32m1_tum
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], <vscale x 2 x float> [[MASKEDOFF:%.*]], <vscale x 2 x half> [[SRC:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x float> @llvm.riscv.vfwcvt.f.f.v.mask.nxv2f32.nxv2f16.i64(<vscale x 2 x float> [[MASKEDOFF]], <vscale x 2 x half> [[SRC]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 2 x float> [[TMP0]]
//
vfloat32m1_t test_vfwcvt_f_f_v_f32m1_tum(vbool32_t mask, vfloat32m1_t maskedoff, vfloat16mf2_t src, size_t vl) {
  return __riscv_vfwcvt_f_tum(mask, maskedoff, src, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x float> @test_vfwcvt_f_f_v_f32m2_tum
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], <vscale x 4 x float> [[MASKEDOFF:%.*]], <vscale x 4 x half> [[SRC:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x float> @llvm.riscv.vfwcvt.f.f.v.mask.nxv4f32.nxv4f16.i64(<vscale x 4 x float> [[MASKEDOFF]], <vscale x 4 x half> [[SRC]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 4 x float> [[TMP0]]
//
vfloat32m2_t test_vfwcvt_f_f_v_f32m2_tum(vbool16_t mask, vfloat32m2_t maskedoff, vfloat16m1_t src, size_t vl) {
  return __riscv_vfwcvt_f_tum(mask, maskedoff, src, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x float> @test_vfwcvt_f_f_v_f32m4_tum
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], <vscale x 8 x float> [[MASKEDOFF:%.*]], <vscale x 8 x half> [[SRC:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x float> @llvm.riscv.vfwcvt.f.f.v.mask.nxv8f32.nxv8f16.i64(<vscale x 8 x float> [[MASKEDOFF]], <vscale x 8 x half> [[SRC]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 8 x float> [[TMP0]]
//
vfloat32m4_t test_vfwcvt_f_f_v_f32m4_tum(vbool8_t mask, vfloat32m4_t maskedoff, vfloat16m2_t src, size_t vl) {
  return __riscv_vfwcvt_f_tum(mask, maskedoff, src, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x float> @test_vfwcvt_f_f_v_f32m8_tum
// CHECK-RV64-SAME: (<vscale x 16 x i1> [[MASK:%.*]], <vscale x 16 x float> [[MASKEDOFF:%.*]], <vscale x 16 x half> [[SRC:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x float> @llvm.riscv.vfwcvt.f.f.v.mask.nxv16f32.nxv16f16.i64(<vscale x 16 x float> [[MASKEDOFF]], <vscale x 16 x half> [[SRC]], <vscale x 16 x i1> [[MASK]], i64 [[VL]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 16 x float> [[TMP0]]
//
vfloat32m8_t test_vfwcvt_f_f_v_f32m8_tum(vbool4_t mask, vfloat32m8_t maskedoff, vfloat16m4_t src, size_t vl) {
  return __riscv_vfwcvt_f_tum(mask, maskedoff, src, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x double> @test_vfwcvt_f_f_v_f64m1_tum
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], <vscale x 1 x double> [[MASKEDOFF:%.*]], <vscale x 1 x float> [[SRC:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vfwcvt.f.f.v.mask.nxv1f64.nxv1f32.i64(<vscale x 1 x double> [[MASKEDOFF]], <vscale x 1 x float> [[SRC]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
vfloat64m1_t test_vfwcvt_f_f_v_f64m1_tum(vbool64_t mask, vfloat64m1_t maskedoff, vfloat32mf2_t src, size_t vl) {
  return __riscv_vfwcvt_f_tum(mask, maskedoff, src, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x double> @test_vfwcvt_f_f_v_f64m2_tum
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], <vscale x 2 x double> [[MASKEDOFF:%.*]], <vscale x 2 x float> [[SRC:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x double> @llvm.riscv.vfwcvt.f.f.v.mask.nxv2f64.nxv2f32.i64(<vscale x 2 x double> [[MASKEDOFF]], <vscale x 2 x float> [[SRC]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 2 x double> [[TMP0]]
//
vfloat64m2_t test_vfwcvt_f_f_v_f64m2_tum(vbool32_t mask, vfloat64m2_t maskedoff, vfloat32m1_t src, size_t vl) {
  return __riscv_vfwcvt_f_tum(mask, maskedoff, src, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x double> @test_vfwcvt_f_f_v_f64m4_tum
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], <vscale x 4 x double> [[MASKEDOFF:%.*]], <vscale x 4 x float> [[SRC:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x double> @llvm.riscv.vfwcvt.f.f.v.mask.nxv4f64.nxv4f32.i64(<vscale x 4 x double> [[MASKEDOFF]], <vscale x 4 x float> [[SRC]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 4 x double> [[TMP0]]
//
vfloat64m4_t test_vfwcvt_f_f_v_f64m4_tum(vbool16_t mask, vfloat64m4_t maskedoff, vfloat32m2_t src, size_t vl) {
  return __riscv_vfwcvt_f_tum(mask, maskedoff, src, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x double> @test_vfwcvt_f_f_v_f64m8_tum
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], <vscale x 8 x double> [[MASKEDOFF:%.*]], <vscale x 8 x float> [[SRC:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x double> @llvm.riscv.vfwcvt.f.f.v.mask.nxv8f64.nxv8f32.i64(<vscale x 8 x double> [[MASKEDOFF]], <vscale x 8 x float> [[SRC]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 8 x double> [[TMP0]]
//
vfloat64m8_t test_vfwcvt_f_f_v_f64m8_tum(vbool8_t mask, vfloat64m8_t maskedoff, vfloat32m4_t src, size_t vl) {
  return __riscv_vfwcvt_f_tum(mask, maskedoff, src, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x float> @test_vfwcvt_f_f_v_f32mf2_tumu
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], <vscale x 1 x float> [[MASKEDOFF:%.*]], <vscale x 1 x half> [[SRC:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x float> @llvm.riscv.vfwcvt.f.f.v.mask.nxv1f32.nxv1f16.i64(<vscale x 1 x float> [[MASKEDOFF]], <vscale x 1 x half> [[SRC]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 1 x float> [[TMP0]]
//
vfloat32mf2_t test_vfwcvt_f_f_v_f32mf2_tumu(vbool64_t mask, vfloat32mf2_t maskedoff, vfloat16mf4_t src, size_t vl) {
  return __riscv_vfwcvt_f_tumu(mask, maskedoff, src, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x float> @test_vfwcvt_f_f_v_f32m1_tumu
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], <vscale x 2 x float> [[MASKEDOFF:%.*]], <vscale x 2 x half> [[SRC:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x float> @llvm.riscv.vfwcvt.f.f.v.mask.nxv2f32.nxv2f16.i64(<vscale x 2 x float> [[MASKEDOFF]], <vscale x 2 x half> [[SRC]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 2 x float> [[TMP0]]
//
vfloat32m1_t test_vfwcvt_f_f_v_f32m1_tumu(vbool32_t mask, vfloat32m1_t maskedoff, vfloat16mf2_t src, size_t vl) {
  return __riscv_vfwcvt_f_tumu(mask, maskedoff, src, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x float> @test_vfwcvt_f_f_v_f32m2_tumu
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], <vscale x 4 x float> [[MASKEDOFF:%.*]], <vscale x 4 x half> [[SRC:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x float> @llvm.riscv.vfwcvt.f.f.v.mask.nxv4f32.nxv4f16.i64(<vscale x 4 x float> [[MASKEDOFF]], <vscale x 4 x half> [[SRC]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 4 x float> [[TMP0]]
//
vfloat32m2_t test_vfwcvt_f_f_v_f32m2_tumu(vbool16_t mask, vfloat32m2_t maskedoff, vfloat16m1_t src, size_t vl) {
  return __riscv_vfwcvt_f_tumu(mask, maskedoff, src, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x float> @test_vfwcvt_f_f_v_f32m4_tumu
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], <vscale x 8 x float> [[MASKEDOFF:%.*]], <vscale x 8 x half> [[SRC:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x float> @llvm.riscv.vfwcvt.f.f.v.mask.nxv8f32.nxv8f16.i64(<vscale x 8 x float> [[MASKEDOFF]], <vscale x 8 x half> [[SRC]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 8 x float> [[TMP0]]
//
vfloat32m4_t test_vfwcvt_f_f_v_f32m4_tumu(vbool8_t mask, vfloat32m4_t maskedoff, vfloat16m2_t src, size_t vl) {
  return __riscv_vfwcvt_f_tumu(mask, maskedoff, src, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x float> @test_vfwcvt_f_f_v_f32m8_tumu
// CHECK-RV64-SAME: (<vscale x 16 x i1> [[MASK:%.*]], <vscale x 16 x float> [[MASKEDOFF:%.*]], <vscale x 16 x half> [[SRC:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x float> @llvm.riscv.vfwcvt.f.f.v.mask.nxv16f32.nxv16f16.i64(<vscale x 16 x float> [[MASKEDOFF]], <vscale x 16 x half> [[SRC]], <vscale x 16 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 16 x float> [[TMP0]]
//
vfloat32m8_t test_vfwcvt_f_f_v_f32m8_tumu(vbool4_t mask, vfloat32m8_t maskedoff, vfloat16m4_t src, size_t vl) {
  return __riscv_vfwcvt_f_tumu(mask, maskedoff, src, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x double> @test_vfwcvt_f_f_v_f64m1_tumu
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], <vscale x 1 x double> [[MASKEDOFF:%.*]], <vscale x 1 x float> [[SRC:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vfwcvt.f.f.v.mask.nxv1f64.nxv1f32.i64(<vscale x 1 x double> [[MASKEDOFF]], <vscale x 1 x float> [[SRC]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
vfloat64m1_t test_vfwcvt_f_f_v_f64m1_tumu(vbool64_t mask, vfloat64m1_t maskedoff, vfloat32mf2_t src, size_t vl) {
  return __riscv_vfwcvt_f_tumu(mask, maskedoff, src, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x double> @test_vfwcvt_f_f_v_f64m2_tumu
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], <vscale x 2 x double> [[MASKEDOFF:%.*]], <vscale x 2 x float> [[SRC:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x double> @llvm.riscv.vfwcvt.f.f.v.mask.nxv2f64.nxv2f32.i64(<vscale x 2 x double> [[MASKEDOFF]], <vscale x 2 x float> [[SRC]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 2 x double> [[TMP0]]
//
vfloat64m2_t test_vfwcvt_f_f_v_f64m2_tumu(vbool32_t mask, vfloat64m2_t maskedoff, vfloat32m1_t src, size_t vl) {
  return __riscv_vfwcvt_f_tumu(mask, maskedoff, src, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x double> @test_vfwcvt_f_f_v_f64m4_tumu
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], <vscale x 4 x double> [[MASKEDOFF:%.*]], <vscale x 4 x float> [[SRC:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x double> @llvm.riscv.vfwcvt.f.f.v.mask.nxv4f64.nxv4f32.i64(<vscale x 4 x double> [[MASKEDOFF]], <vscale x 4 x float> [[SRC]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 4 x double> [[TMP0]]
//
vfloat64m4_t test_vfwcvt_f_f_v_f64m4_tumu(vbool16_t mask, vfloat64m4_t maskedoff, vfloat32m2_t src, size_t vl) {
  return __riscv_vfwcvt_f_tumu(mask, maskedoff, src, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x double> @test_vfwcvt_f_f_v_f64m8_tumu
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], <vscale x 8 x double> [[MASKEDOFF:%.*]], <vscale x 8 x float> [[SRC:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x double> @llvm.riscv.vfwcvt.f.f.v.mask.nxv8f64.nxv8f32.i64(<vscale x 8 x double> [[MASKEDOFF]], <vscale x 8 x float> [[SRC]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 8 x double> [[TMP0]]
//
vfloat64m8_t test_vfwcvt_f_f_v_f64m8_tumu(vbool8_t mask, vfloat64m8_t maskedoff, vfloat32m4_t src, size_t vl) {
  return __riscv_vfwcvt_f_tumu(mask, maskedoff, src, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x float> @test_vfwcvt_f_f_v_f32mf2_mu
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], <vscale x 1 x float> [[MASKEDOFF:%.*]], <vscale x 1 x half> [[SRC:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x float> @llvm.riscv.vfwcvt.f.f.v.mask.nxv1f32.nxv1f16.i64(<vscale x 1 x float> [[MASKEDOFF]], <vscale x 1 x half> [[SRC]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 1)
// CHECK-RV64-NEXT:    ret <vscale x 1 x float> [[TMP0]]
//
vfloat32mf2_t test_vfwcvt_f_f_v_f32mf2_mu(vbool64_t mask, vfloat32mf2_t maskedoff, vfloat16mf4_t src, size_t vl) {
  return __riscv_vfwcvt_f_mu(mask, maskedoff, src, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x float> @test_vfwcvt_f_f_v_f32m1_mu
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], <vscale x 2 x float> [[MASKEDOFF:%.*]], <vscale x 2 x half> [[SRC:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x float> @llvm.riscv.vfwcvt.f.f.v.mask.nxv2f32.nxv2f16.i64(<vscale x 2 x float> [[MASKEDOFF]], <vscale x 2 x half> [[SRC]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 1)
// CHECK-RV64-NEXT:    ret <vscale x 2 x float> [[TMP0]]
//
vfloat32m1_t test_vfwcvt_f_f_v_f32m1_mu(vbool32_t mask, vfloat32m1_t maskedoff, vfloat16mf2_t src, size_t vl) {
  return __riscv_vfwcvt_f_mu(mask, maskedoff, src, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x float> @test_vfwcvt_f_f_v_f32m2_mu
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], <vscale x 4 x float> [[MASKEDOFF:%.*]], <vscale x 4 x half> [[SRC:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x float> @llvm.riscv.vfwcvt.f.f.v.mask.nxv4f32.nxv4f16.i64(<vscale x 4 x float> [[MASKEDOFF]], <vscale x 4 x half> [[SRC]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 1)
// CHECK-RV64-NEXT:    ret <vscale x 4 x float> [[TMP0]]
//
vfloat32m2_t test_vfwcvt_f_f_v_f32m2_mu(vbool16_t mask, vfloat32m2_t maskedoff, vfloat16m1_t src, size_t vl) {
  return __riscv_vfwcvt_f_mu(mask, maskedoff, src, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x float> @test_vfwcvt_f_f_v_f32m4_mu
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], <vscale x 8 x float> [[MASKEDOFF:%.*]], <vscale x 8 x half> [[SRC:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x float> @llvm.riscv.vfwcvt.f.f.v.mask.nxv8f32.nxv8f16.i64(<vscale x 8 x float> [[MASKEDOFF]], <vscale x 8 x half> [[SRC]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 1)
// CHECK-RV64-NEXT:    ret <vscale x 8 x float> [[TMP0]]
//
vfloat32m4_t test_vfwcvt_f_f_v_f32m4_mu(vbool8_t mask, vfloat32m4_t maskedoff, vfloat16m2_t src, size_t vl) {
  return __riscv_vfwcvt_f_mu(mask, maskedoff, src, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x float> @test_vfwcvt_f_f_v_f32m8_mu
// CHECK-RV64-SAME: (<vscale x 16 x i1> [[MASK:%.*]], <vscale x 16 x float> [[MASKEDOFF:%.*]], <vscale x 16 x half> [[SRC:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x float> @llvm.riscv.vfwcvt.f.f.v.mask.nxv16f32.nxv16f16.i64(<vscale x 16 x float> [[MASKEDOFF]], <vscale x 16 x half> [[SRC]], <vscale x 16 x i1> [[MASK]], i64 [[VL]], i64 1)
// CHECK-RV64-NEXT:    ret <vscale x 16 x float> [[TMP0]]
//
vfloat32m8_t test_vfwcvt_f_f_v_f32m8_mu(vbool4_t mask, vfloat32m8_t maskedoff, vfloat16m4_t src, size_t vl) {
  return __riscv_vfwcvt_f_mu(mask, maskedoff, src, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x double> @test_vfwcvt_f_f_v_f64m1_mu
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], <vscale x 1 x double> [[MASKEDOFF:%.*]], <vscale x 1 x float> [[SRC:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vfwcvt.f.f.v.mask.nxv1f64.nxv1f32.i64(<vscale x 1 x double> [[MASKEDOFF]], <vscale x 1 x float> [[SRC]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 1)
// CHECK-RV64-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
vfloat64m1_t test_vfwcvt_f_f_v_f64m1_mu(vbool64_t mask, vfloat64m1_t maskedoff, vfloat32mf2_t src, size_t vl) {
  return __riscv_vfwcvt_f_mu(mask, maskedoff, src, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x double> @test_vfwcvt_f_f_v_f64m2_mu
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], <vscale x 2 x double> [[MASKEDOFF:%.*]], <vscale x 2 x float> [[SRC:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x double> @llvm.riscv.vfwcvt.f.f.v.mask.nxv2f64.nxv2f32.i64(<vscale x 2 x double> [[MASKEDOFF]], <vscale x 2 x float> [[SRC]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 1)
// CHECK-RV64-NEXT:    ret <vscale x 2 x double> [[TMP0]]
//
vfloat64m2_t test_vfwcvt_f_f_v_f64m2_mu(vbool32_t mask, vfloat64m2_t maskedoff, vfloat32m1_t src, size_t vl) {
  return __riscv_vfwcvt_f_mu(mask, maskedoff, src, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x double> @test_vfwcvt_f_f_v_f64m4_mu
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], <vscale x 4 x double> [[MASKEDOFF:%.*]], <vscale x 4 x float> [[SRC:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x double> @llvm.riscv.vfwcvt.f.f.v.mask.nxv4f64.nxv4f32.i64(<vscale x 4 x double> [[MASKEDOFF]], <vscale x 4 x float> [[SRC]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 1)
// CHECK-RV64-NEXT:    ret <vscale x 4 x double> [[TMP0]]
//
vfloat64m4_t test_vfwcvt_f_f_v_f64m4_mu(vbool16_t mask, vfloat64m4_t maskedoff, vfloat32m2_t src, size_t vl) {
  return __riscv_vfwcvt_f_mu(mask, maskedoff, src, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x double> @test_vfwcvt_f_f_v_f64m8_mu
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], <vscale x 8 x double> [[MASKEDOFF:%.*]], <vscale x 8 x float> [[SRC:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x double> @llvm.riscv.vfwcvt.f.f.v.mask.nxv8f64.nxv8f32.i64(<vscale x 8 x double> [[MASKEDOFF]], <vscale x 8 x float> [[SRC]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 1)
// CHECK-RV64-NEXT:    ret <vscale x 8 x double> [[TMP0]]
//
vfloat64m8_t test_vfwcvt_f_f_v_f64m8_mu(vbool8_t mask, vfloat64m8_t maskedoff, vfloat32m4_t src, size_t vl) {
  return __riscv_vfwcvt_f_mu(mask, maskedoff, src, vl);
}
