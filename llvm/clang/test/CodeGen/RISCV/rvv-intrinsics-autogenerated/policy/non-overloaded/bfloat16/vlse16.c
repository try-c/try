// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 4
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v \
// RUN:   -target-feature +zvfbfmin \
// RUN:   -target-feature +zvfbfwma -disable-O0-optnone \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x bfloat> @test_vlse16_v_bf16mf4_tu(
// CHECK-RV64-SAME: <vscale x 1 x bfloat> [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x bfloat> @llvm.riscv.vlse.nxv1bf16.i64(<vscale x 1 x bfloat> [[VD]], ptr [[RS1]], i64 [[RS2]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x bfloat> [[TMP0]]
//
vbfloat16mf4_t test_vlse16_v_bf16mf4_tu(vbfloat16mf4_t vd, const __bf16 *rs1, ptrdiff_t rs2, size_t vl) {
  return __riscv_vlse16_v_bf16mf4_tu(vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x bfloat> @test_vlse16_v_bf16mf2_tu(
// CHECK-RV64-SAME: <vscale x 2 x bfloat> [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x bfloat> @llvm.riscv.vlse.nxv2bf16.i64(<vscale x 2 x bfloat> [[VD]], ptr [[RS1]], i64 [[RS2]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x bfloat> [[TMP0]]
//
vbfloat16mf2_t test_vlse16_v_bf16mf2_tu(vbfloat16mf2_t vd, const __bf16 *rs1, ptrdiff_t rs2, size_t vl) {
  return __riscv_vlse16_v_bf16mf2_tu(vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x bfloat> @test_vlse16_v_bf16m1_tu(
// CHECK-RV64-SAME: <vscale x 4 x bfloat> [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x bfloat> @llvm.riscv.vlse.nxv4bf16.i64(<vscale x 4 x bfloat> [[VD]], ptr [[RS1]], i64 [[RS2]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x bfloat> [[TMP0]]
//
vbfloat16m1_t test_vlse16_v_bf16m1_tu(vbfloat16m1_t vd, const __bf16 *rs1, ptrdiff_t rs2, size_t vl) {
  return __riscv_vlse16_v_bf16m1_tu(vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x bfloat> @test_vlse16_v_bf16m2_tu(
// CHECK-RV64-SAME: <vscale x 8 x bfloat> [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x bfloat> @llvm.riscv.vlse.nxv8bf16.i64(<vscale x 8 x bfloat> [[VD]], ptr [[RS1]], i64 [[RS2]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x bfloat> [[TMP0]]
//
vbfloat16m2_t test_vlse16_v_bf16m2_tu(vbfloat16m2_t vd, const __bf16 *rs1, ptrdiff_t rs2, size_t vl) {
  return __riscv_vlse16_v_bf16m2_tu(vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x bfloat> @test_vlse16_v_bf16m4_tu(
// CHECK-RV64-SAME: <vscale x 16 x bfloat> [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x bfloat> @llvm.riscv.vlse.nxv16bf16.i64(<vscale x 16 x bfloat> [[VD]], ptr [[RS1]], i64 [[RS2]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 16 x bfloat> [[TMP0]]
//
vbfloat16m4_t test_vlse16_v_bf16m4_tu(vbfloat16m4_t vd, const __bf16 *rs1, ptrdiff_t rs2, size_t vl) {
  return __riscv_vlse16_v_bf16m4_tu(vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 32 x bfloat> @test_vlse16_v_bf16m8_tu(
// CHECK-RV64-SAME: <vscale x 32 x bfloat> [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x bfloat> @llvm.riscv.vlse.nxv32bf16.i64(<vscale x 32 x bfloat> [[VD]], ptr [[RS1]], i64 [[RS2]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 32 x bfloat> [[TMP0]]
//
vbfloat16m8_t test_vlse16_v_bf16m8_tu(vbfloat16m8_t vd, const __bf16 *rs1, ptrdiff_t rs2, size_t vl) {
  return __riscv_vlse16_v_bf16m8_tu(vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x bfloat> @test_vlse16_v_bf16mf4_tum(
// CHECK-RV64-SAME: <vscale x 1 x i1> [[VM:%.*]], <vscale x 1 x bfloat> [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x bfloat> @llvm.riscv.vlse.mask.nxv1bf16.i64(<vscale x 1 x bfloat> [[VD]], ptr [[RS1]], i64 [[RS2]], <vscale x 1 x i1> [[VM]], i64 [[VL]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 1 x bfloat> [[TMP0]]
//
vbfloat16mf4_t test_vlse16_v_bf16mf4_tum(vbool64_t vm, vbfloat16mf4_t vd, const __bf16 *rs1, ptrdiff_t rs2, size_t vl) {
  return __riscv_vlse16_v_bf16mf4_tum(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x bfloat> @test_vlse16_v_bf16mf2_tum(
// CHECK-RV64-SAME: <vscale x 2 x i1> [[VM:%.*]], <vscale x 2 x bfloat> [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x bfloat> @llvm.riscv.vlse.mask.nxv2bf16.i64(<vscale x 2 x bfloat> [[VD]], ptr [[RS1]], i64 [[RS2]], <vscale x 2 x i1> [[VM]], i64 [[VL]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 2 x bfloat> [[TMP0]]
//
vbfloat16mf2_t test_vlse16_v_bf16mf2_tum(vbool32_t vm, vbfloat16mf2_t vd, const __bf16 *rs1, ptrdiff_t rs2, size_t vl) {
  return __riscv_vlse16_v_bf16mf2_tum(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x bfloat> @test_vlse16_v_bf16m1_tum(
// CHECK-RV64-SAME: <vscale x 4 x i1> [[VM:%.*]], <vscale x 4 x bfloat> [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x bfloat> @llvm.riscv.vlse.mask.nxv4bf16.i64(<vscale x 4 x bfloat> [[VD]], ptr [[RS1]], i64 [[RS2]], <vscale x 4 x i1> [[VM]], i64 [[VL]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 4 x bfloat> [[TMP0]]
//
vbfloat16m1_t test_vlse16_v_bf16m1_tum(vbool16_t vm, vbfloat16m1_t vd, const __bf16 *rs1, ptrdiff_t rs2, size_t vl) {
  return __riscv_vlse16_v_bf16m1_tum(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x bfloat> @test_vlse16_v_bf16m2_tum(
// CHECK-RV64-SAME: <vscale x 8 x i1> [[VM:%.*]], <vscale x 8 x bfloat> [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x bfloat> @llvm.riscv.vlse.mask.nxv8bf16.i64(<vscale x 8 x bfloat> [[VD]], ptr [[RS1]], i64 [[RS2]], <vscale x 8 x i1> [[VM]], i64 [[VL]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 8 x bfloat> [[TMP0]]
//
vbfloat16m2_t test_vlse16_v_bf16m2_tum(vbool8_t vm, vbfloat16m2_t vd, const __bf16 *rs1, ptrdiff_t rs2, size_t vl) {
  return __riscv_vlse16_v_bf16m2_tum(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x bfloat> @test_vlse16_v_bf16m4_tum(
// CHECK-RV64-SAME: <vscale x 16 x i1> [[VM:%.*]], <vscale x 16 x bfloat> [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x bfloat> @llvm.riscv.vlse.mask.nxv16bf16.i64(<vscale x 16 x bfloat> [[VD]], ptr [[RS1]], i64 [[RS2]], <vscale x 16 x i1> [[VM]], i64 [[VL]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 16 x bfloat> [[TMP0]]
//
vbfloat16m4_t test_vlse16_v_bf16m4_tum(vbool4_t vm, vbfloat16m4_t vd, const __bf16 *rs1, ptrdiff_t rs2, size_t vl) {
  return __riscv_vlse16_v_bf16m4_tum(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 32 x bfloat> @test_vlse16_v_bf16m8_tum(
// CHECK-RV64-SAME: <vscale x 32 x i1> [[VM:%.*]], <vscale x 32 x bfloat> [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x bfloat> @llvm.riscv.vlse.mask.nxv32bf16.i64(<vscale x 32 x bfloat> [[VD]], ptr [[RS1]], i64 [[RS2]], <vscale x 32 x i1> [[VM]], i64 [[VL]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 32 x bfloat> [[TMP0]]
//
vbfloat16m8_t test_vlse16_v_bf16m8_tum(vbool2_t vm, vbfloat16m8_t vd, const __bf16 *rs1, ptrdiff_t rs2, size_t vl) {
  return __riscv_vlse16_v_bf16m8_tum(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x bfloat> @test_vlse16_v_bf16mf4_tumu(
// CHECK-RV64-SAME: <vscale x 1 x i1> [[VM:%.*]], <vscale x 1 x bfloat> [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x bfloat> @llvm.riscv.vlse.mask.nxv1bf16.i64(<vscale x 1 x bfloat> [[VD]], ptr [[RS1]], i64 [[RS2]], <vscale x 1 x i1> [[VM]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 1 x bfloat> [[TMP0]]
//
vbfloat16mf4_t test_vlse16_v_bf16mf4_tumu(vbool64_t vm, vbfloat16mf4_t vd, const __bf16 *rs1, ptrdiff_t rs2, size_t vl) {
  return __riscv_vlse16_v_bf16mf4_tumu(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x bfloat> @test_vlse16_v_bf16mf2_tumu(
// CHECK-RV64-SAME: <vscale x 2 x i1> [[VM:%.*]], <vscale x 2 x bfloat> [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x bfloat> @llvm.riscv.vlse.mask.nxv2bf16.i64(<vscale x 2 x bfloat> [[VD]], ptr [[RS1]], i64 [[RS2]], <vscale x 2 x i1> [[VM]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 2 x bfloat> [[TMP0]]
//
vbfloat16mf2_t test_vlse16_v_bf16mf2_tumu(vbool32_t vm, vbfloat16mf2_t vd, const __bf16 *rs1, ptrdiff_t rs2, size_t vl) {
  return __riscv_vlse16_v_bf16mf2_tumu(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x bfloat> @test_vlse16_v_bf16m1_tumu(
// CHECK-RV64-SAME: <vscale x 4 x i1> [[VM:%.*]], <vscale x 4 x bfloat> [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x bfloat> @llvm.riscv.vlse.mask.nxv4bf16.i64(<vscale x 4 x bfloat> [[VD]], ptr [[RS1]], i64 [[RS2]], <vscale x 4 x i1> [[VM]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 4 x bfloat> [[TMP0]]
//
vbfloat16m1_t test_vlse16_v_bf16m1_tumu(vbool16_t vm, vbfloat16m1_t vd, const __bf16 *rs1, ptrdiff_t rs2, size_t vl) {
  return __riscv_vlse16_v_bf16m1_tumu(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x bfloat> @test_vlse16_v_bf16m2_tumu(
// CHECK-RV64-SAME: <vscale x 8 x i1> [[VM:%.*]], <vscale x 8 x bfloat> [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x bfloat> @llvm.riscv.vlse.mask.nxv8bf16.i64(<vscale x 8 x bfloat> [[VD]], ptr [[RS1]], i64 [[RS2]], <vscale x 8 x i1> [[VM]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 8 x bfloat> [[TMP0]]
//
vbfloat16m2_t test_vlse16_v_bf16m2_tumu(vbool8_t vm, vbfloat16m2_t vd, const __bf16 *rs1, ptrdiff_t rs2, size_t vl) {
  return __riscv_vlse16_v_bf16m2_tumu(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x bfloat> @test_vlse16_v_bf16m4_tumu(
// CHECK-RV64-SAME: <vscale x 16 x i1> [[VM:%.*]], <vscale x 16 x bfloat> [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x bfloat> @llvm.riscv.vlse.mask.nxv16bf16.i64(<vscale x 16 x bfloat> [[VD]], ptr [[RS1]], i64 [[RS2]], <vscale x 16 x i1> [[VM]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 16 x bfloat> [[TMP0]]
//
vbfloat16m4_t test_vlse16_v_bf16m4_tumu(vbool4_t vm, vbfloat16m4_t vd, const __bf16 *rs1, ptrdiff_t rs2, size_t vl) {
  return __riscv_vlse16_v_bf16m4_tumu(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 32 x bfloat> @test_vlse16_v_bf16m8_tumu(
// CHECK-RV64-SAME: <vscale x 32 x i1> [[VM:%.*]], <vscale x 32 x bfloat> [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x bfloat> @llvm.riscv.vlse.mask.nxv32bf16.i64(<vscale x 32 x bfloat> [[VD]], ptr [[RS1]], i64 [[RS2]], <vscale x 32 x i1> [[VM]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 32 x bfloat> [[TMP0]]
//
vbfloat16m8_t test_vlse16_v_bf16m8_tumu(vbool2_t vm, vbfloat16m8_t vd, const __bf16 *rs1, ptrdiff_t rs2, size_t vl) {
  return __riscv_vlse16_v_bf16m8_tumu(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x bfloat> @test_vlse16_v_bf16mf4_mu(
// CHECK-RV64-SAME: <vscale x 1 x i1> [[VM:%.*]], <vscale x 1 x bfloat> [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x bfloat> @llvm.riscv.vlse.mask.nxv1bf16.i64(<vscale x 1 x bfloat> [[VD]], ptr [[RS1]], i64 [[RS2]], <vscale x 1 x i1> [[VM]], i64 [[VL]], i64 1)
// CHECK-RV64-NEXT:    ret <vscale x 1 x bfloat> [[TMP0]]
//
vbfloat16mf4_t test_vlse16_v_bf16mf4_mu(vbool64_t vm, vbfloat16mf4_t vd, const __bf16 *rs1, ptrdiff_t rs2, size_t vl) {
  return __riscv_vlse16_v_bf16mf4_mu(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x bfloat> @test_vlse16_v_bf16mf2_mu(
// CHECK-RV64-SAME: <vscale x 2 x i1> [[VM:%.*]], <vscale x 2 x bfloat> [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x bfloat> @llvm.riscv.vlse.mask.nxv2bf16.i64(<vscale x 2 x bfloat> [[VD]], ptr [[RS1]], i64 [[RS2]], <vscale x 2 x i1> [[VM]], i64 [[VL]], i64 1)
// CHECK-RV64-NEXT:    ret <vscale x 2 x bfloat> [[TMP0]]
//
vbfloat16mf2_t test_vlse16_v_bf16mf2_mu(vbool32_t vm, vbfloat16mf2_t vd, const __bf16 *rs1, ptrdiff_t rs2, size_t vl) {
  return __riscv_vlse16_v_bf16mf2_mu(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x bfloat> @test_vlse16_v_bf16m1_mu(
// CHECK-RV64-SAME: <vscale x 4 x i1> [[VM:%.*]], <vscale x 4 x bfloat> [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x bfloat> @llvm.riscv.vlse.mask.nxv4bf16.i64(<vscale x 4 x bfloat> [[VD]], ptr [[RS1]], i64 [[RS2]], <vscale x 4 x i1> [[VM]], i64 [[VL]], i64 1)
// CHECK-RV64-NEXT:    ret <vscale x 4 x bfloat> [[TMP0]]
//
vbfloat16m1_t test_vlse16_v_bf16m1_mu(vbool16_t vm, vbfloat16m1_t vd, const __bf16 *rs1, ptrdiff_t rs2, size_t vl) {
  return __riscv_vlse16_v_bf16m1_mu(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x bfloat> @test_vlse16_v_bf16m2_mu(
// CHECK-RV64-SAME: <vscale x 8 x i1> [[VM:%.*]], <vscale x 8 x bfloat> [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x bfloat> @llvm.riscv.vlse.mask.nxv8bf16.i64(<vscale x 8 x bfloat> [[VD]], ptr [[RS1]], i64 [[RS2]], <vscale x 8 x i1> [[VM]], i64 [[VL]], i64 1)
// CHECK-RV64-NEXT:    ret <vscale x 8 x bfloat> [[TMP0]]
//
vbfloat16m2_t test_vlse16_v_bf16m2_mu(vbool8_t vm, vbfloat16m2_t vd, const __bf16 *rs1, ptrdiff_t rs2, size_t vl) {
  return __riscv_vlse16_v_bf16m2_mu(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x bfloat> @test_vlse16_v_bf16m4_mu(
// CHECK-RV64-SAME: <vscale x 16 x i1> [[VM:%.*]], <vscale x 16 x bfloat> [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x bfloat> @llvm.riscv.vlse.mask.nxv16bf16.i64(<vscale x 16 x bfloat> [[VD]], ptr [[RS1]], i64 [[RS2]], <vscale x 16 x i1> [[VM]], i64 [[VL]], i64 1)
// CHECK-RV64-NEXT:    ret <vscale x 16 x bfloat> [[TMP0]]
//
vbfloat16m4_t test_vlse16_v_bf16m4_mu(vbool4_t vm, vbfloat16m4_t vd, const __bf16 *rs1, ptrdiff_t rs2, size_t vl) {
  return __riscv_vlse16_v_bf16m4_mu(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 32 x bfloat> @test_vlse16_v_bf16m8_mu(
// CHECK-RV64-SAME: <vscale x 32 x i1> [[VM:%.*]], <vscale x 32 x bfloat> [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x bfloat> @llvm.riscv.vlse.mask.nxv32bf16.i64(<vscale x 32 x bfloat> [[VD]], ptr [[RS1]], i64 [[RS2]], <vscale x 32 x i1> [[VM]], i64 [[VL]], i64 1)
// CHECK-RV64-NEXT:    ret <vscale x 32 x bfloat> [[TMP0]]
//
vbfloat16m8_t test_vlse16_v_bf16m8_mu(vbool2_t vm, vbfloat16m8_t vd, const __bf16 *rs1, ptrdiff_t rs2, size_t vl) {
  return __riscv_vlse16_v_bf16m8_mu(vm, vd, rs1, rs2, vl);
}
