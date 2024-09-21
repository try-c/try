// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 2
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +zvfhmin -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x half> @test_vle16_v_f16mf4_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x half> @llvm.riscv.vle.mask.nxv1f16.i64(<vscale x 1 x half> poison, ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x half> [[TMP0]]
//
vfloat16mf4_t test_vle16_v_f16mf4_m(vbool64_t mask, const _Float16 *base, size_t vl) {
  return __riscv_vle16(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x half> @test_vle16_v_f16mf2_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x half> @llvm.riscv.vle.mask.nxv2f16.i64(<vscale x 2 x half> poison, ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x half> [[TMP0]]
//
vfloat16mf2_t test_vle16_v_f16mf2_m(vbool32_t mask, const _Float16 *base, size_t vl) {
  return __riscv_vle16(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x half> @test_vle16_v_f16m1_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x half> @llvm.riscv.vle.mask.nxv4f16.i64(<vscale x 4 x half> poison, ptr [[BASE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x half> [[TMP0]]
//
vfloat16m1_t test_vle16_v_f16m1_m(vbool16_t mask, const _Float16 *base, size_t vl) {
  return __riscv_vle16(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x half> @test_vle16_v_f16m2_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x half> @llvm.riscv.vle.mask.nxv8f16.i64(<vscale x 8 x half> poison, ptr [[BASE]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x half> [[TMP0]]
//
vfloat16m2_t test_vle16_v_f16m2_m(vbool8_t mask, const _Float16 *base, size_t vl) {
  return __riscv_vle16(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x half> @test_vle16_v_f16m4_m
// CHECK-RV64-SAME: (<vscale x 16 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x half> @llvm.riscv.vle.mask.nxv16f16.i64(<vscale x 16 x half> poison, ptr [[BASE]], <vscale x 16 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 16 x half> [[TMP0]]
//
vfloat16m4_t test_vle16_v_f16m4_m(vbool4_t mask, const _Float16 *base, size_t vl) {
  return __riscv_vle16(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 32 x half> @test_vle16_v_f16m8_m
// CHECK-RV64-SAME: (<vscale x 32 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x half> @llvm.riscv.vle.mask.nxv32f16.i64(<vscale x 32 x half> poison, ptr [[BASE]], <vscale x 32 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 32 x half> [[TMP0]]
//
vfloat16m8_t test_vle16_v_f16m8_m(vbool2_t mask, const _Float16 *base, size_t vl) {
  return __riscv_vle16(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x i16> @test_vle16_v_i16mf4_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i16> @llvm.riscv.vle.mask.nxv1i16.i64(<vscale x 1 x i16> poison, ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i16> [[TMP0]]
//
vint16mf4_t test_vle16_v_i16mf4_m(vbool64_t mask, const int16_t *base, size_t vl) {
  return __riscv_vle16(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i16> @test_vle16_v_i16mf2_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i16> @llvm.riscv.vle.mask.nxv2i16.i64(<vscale x 2 x i16> poison, ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i16> [[TMP0]]
//
vint16mf2_t test_vle16_v_i16mf2_m(vbool32_t mask, const int16_t *base, size_t vl) {
  return __riscv_vle16(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i16> @test_vle16_v_i16m1_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i16> @llvm.riscv.vle.mask.nxv4i16.i64(<vscale x 4 x i16> poison, ptr [[BASE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i16> [[TMP0]]
//
vint16m1_t test_vle16_v_i16m1_m(vbool16_t mask, const int16_t *base, size_t vl) {
  return __riscv_vle16(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x i16> @test_vle16_v_i16m2_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i16> @llvm.riscv.vle.mask.nxv8i16.i64(<vscale x 8 x i16> poison, ptr [[BASE]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i16> [[TMP0]]
//
vint16m2_t test_vle16_v_i16m2_m(vbool8_t mask, const int16_t *base, size_t vl) {
  return __riscv_vle16(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x i16> @test_vle16_v_i16m4_m
// CHECK-RV64-SAME: (<vscale x 16 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i16> @llvm.riscv.vle.mask.nxv16i16.i64(<vscale x 16 x i16> poison, ptr [[BASE]], <vscale x 16 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 16 x i16> [[TMP0]]
//
vint16m4_t test_vle16_v_i16m4_m(vbool4_t mask, const int16_t *base, size_t vl) {
  return __riscv_vle16(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 32 x i16> @test_vle16_v_i16m8_m
// CHECK-RV64-SAME: (<vscale x 32 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x i16> @llvm.riscv.vle.mask.nxv32i16.i64(<vscale x 32 x i16> poison, ptr [[BASE]], <vscale x 32 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 32 x i16> [[TMP0]]
//
vint16m8_t test_vle16_v_i16m8_m(vbool2_t mask, const int16_t *base, size_t vl) {
  return __riscv_vle16(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x i16> @test_vle16_v_u16mf4_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i16> @llvm.riscv.vle.mask.nxv1i16.i64(<vscale x 1 x i16> poison, ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i16> [[TMP0]]
//
vuint16mf4_t test_vle16_v_u16mf4_m(vbool64_t mask, const uint16_t *base, size_t vl) {
  return __riscv_vle16(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i16> @test_vle16_v_u16mf2_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i16> @llvm.riscv.vle.mask.nxv2i16.i64(<vscale x 2 x i16> poison, ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i16> [[TMP0]]
//
vuint16mf2_t test_vle16_v_u16mf2_m(vbool32_t mask, const uint16_t *base, size_t vl) {
  return __riscv_vle16(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i16> @test_vle16_v_u16m1_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i16> @llvm.riscv.vle.mask.nxv4i16.i64(<vscale x 4 x i16> poison, ptr [[BASE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i16> [[TMP0]]
//
vuint16m1_t test_vle16_v_u16m1_m(vbool16_t mask, const uint16_t *base, size_t vl) {
  return __riscv_vle16(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x i16> @test_vle16_v_u16m2_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i16> @llvm.riscv.vle.mask.nxv8i16.i64(<vscale x 8 x i16> poison, ptr [[BASE]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i16> [[TMP0]]
//
vuint16m2_t test_vle16_v_u16m2_m(vbool8_t mask, const uint16_t *base, size_t vl) {
  return __riscv_vle16(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x i16> @test_vle16_v_u16m4_m
// CHECK-RV64-SAME: (<vscale x 16 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i16> @llvm.riscv.vle.mask.nxv16i16.i64(<vscale x 16 x i16> poison, ptr [[BASE]], <vscale x 16 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 16 x i16> [[TMP0]]
//
vuint16m4_t test_vle16_v_u16m4_m(vbool4_t mask, const uint16_t *base, size_t vl) {
  return __riscv_vle16(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 32 x i16> @test_vle16_v_u16m8_m
// CHECK-RV64-SAME: (<vscale x 32 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x i16> @llvm.riscv.vle.mask.nxv32i16.i64(<vscale x 32 x i16> poison, ptr [[BASE]], <vscale x 32 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 32 x i16> [[TMP0]]
//
vuint16m8_t test_vle16_v_u16m8_m(vbool2_t mask, const uint16_t *base, size_t vl) {
  return __riscv_vle16(mask, base, vl);
}

