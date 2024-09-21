// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 4
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v \
// RUN:   -target-feature +zvfbfmin \
// RUN:   -target-feature +zvfbfwma -disable-O0-optnone \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 7) @test_vlsseg7e16_v_bf16mf4x7_tu(
// CHECK-RV64-SAME: target("riscv.vector.tuple", <vscale x 2 x i8>, 7) [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 2 x i8>, 7) @llvm.riscv.vlsseg7.triscv.vector.tuple_nxv2i8_7t.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 7) [[VD]], ptr [[RS1]], i64 [[RS2]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 7) [[TMP0]]
//
vbfloat16mf4x7_t test_vlsseg7e16_v_bf16mf4x7_tu(vbfloat16mf4x7_t vd, const __bf16 *rs1, ptrdiff_t rs2, size_t vl) {
  return __riscv_vlsseg7e16_v_bf16mf4x7_tu(vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 7) @test_vlsseg7e16_v_bf16mf2x7_tu(
// CHECK-RV64-SAME: target("riscv.vector.tuple", <vscale x 4 x i8>, 7) [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 7) @llvm.riscv.vlsseg7.triscv.vector.tuple_nxv4i8_7t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 7) [[VD]], ptr [[RS1]], i64 [[RS2]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 7) [[TMP0]]
//
vbfloat16mf2x7_t test_vlsseg7e16_v_bf16mf2x7_tu(vbfloat16mf2x7_t vd, const __bf16 *rs1, ptrdiff_t rs2, size_t vl) {
  return __riscv_vlsseg7e16_v_bf16mf2x7_tu(vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 7) @test_vlsseg7e16_v_bf16m1x7_tu(
// CHECK-RV64-SAME: target("riscv.vector.tuple", <vscale x 8 x i8>, 7) [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 7) @llvm.riscv.vlsseg7.triscv.vector.tuple_nxv8i8_7t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 7) [[VD]], ptr [[RS1]], i64 [[RS2]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 7) [[TMP0]]
//
vbfloat16m1x7_t test_vlsseg7e16_v_bf16m1x7_tu(vbfloat16m1x7_t vd, const __bf16 *rs1, ptrdiff_t rs2, size_t vl) {
  return __riscv_vlsseg7e16_v_bf16m1x7_tu(vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 7) @test_vlsseg7e16_v_bf16mf4x7_tum(
// CHECK-RV64-SAME: <vscale x 1 x i1> [[VM:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 7) [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 2 x i8>, 7) @llvm.riscv.vlsseg7.mask.triscv.vector.tuple_nxv2i8_7t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 2 x i8>, 7) [[VD]], ptr [[RS1]], i64 [[RS2]], <vscale x 1 x i1> [[VM]], i64 [[VL]], i64 2, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 7) [[TMP0]]
//
vbfloat16mf4x7_t test_vlsseg7e16_v_bf16mf4x7_tum(vbool64_t vm, vbfloat16mf4x7_t vd, const __bf16 *rs1, ptrdiff_t rs2, size_t vl) {
  return __riscv_vlsseg7e16_v_bf16mf4x7_tum(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 7) @test_vlsseg7e16_v_bf16mf2x7_tum(
// CHECK-RV64-SAME: <vscale x 2 x i1> [[VM:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 7) [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 7) @llvm.riscv.vlsseg7.mask.triscv.vector.tuple_nxv4i8_7t.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 4 x i8>, 7) [[VD]], ptr [[RS1]], i64 [[RS2]], <vscale x 2 x i1> [[VM]], i64 [[VL]], i64 2, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 7) [[TMP0]]
//
vbfloat16mf2x7_t test_vlsseg7e16_v_bf16mf2x7_tum(vbool32_t vm, vbfloat16mf2x7_t vd, const __bf16 *rs1, ptrdiff_t rs2, size_t vl) {
  return __riscv_vlsseg7e16_v_bf16mf2x7_tum(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 7) @test_vlsseg7e16_v_bf16m1x7_tum(
// CHECK-RV64-SAME: <vscale x 4 x i1> [[VM:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 7) [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 7) @llvm.riscv.vlsseg7.mask.triscv.vector.tuple_nxv8i8_7t.i64.nxv4i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 7) [[VD]], ptr [[RS1]], i64 [[RS2]], <vscale x 4 x i1> [[VM]], i64 [[VL]], i64 2, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 7) [[TMP0]]
//
vbfloat16m1x7_t test_vlsseg7e16_v_bf16m1x7_tum(vbool16_t vm, vbfloat16m1x7_t vd, const __bf16 *rs1, ptrdiff_t rs2, size_t vl) {
  return __riscv_vlsseg7e16_v_bf16m1x7_tum(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 7) @test_vlsseg7e16_v_bf16mf4x7_tumu(
// CHECK-RV64-SAME: <vscale x 1 x i1> [[VM:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 7) [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 2 x i8>, 7) @llvm.riscv.vlsseg7.mask.triscv.vector.tuple_nxv2i8_7t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 2 x i8>, 7) [[VD]], ptr [[RS1]], i64 [[RS2]], <vscale x 1 x i1> [[VM]], i64 [[VL]], i64 0, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 7) [[TMP0]]
//
vbfloat16mf4x7_t test_vlsseg7e16_v_bf16mf4x7_tumu(vbool64_t vm, vbfloat16mf4x7_t vd, const __bf16 *rs1, ptrdiff_t rs2, size_t vl) {
  return __riscv_vlsseg7e16_v_bf16mf4x7_tumu(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 7) @test_vlsseg7e16_v_bf16mf2x7_tumu(
// CHECK-RV64-SAME: <vscale x 2 x i1> [[VM:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 7) [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 7) @llvm.riscv.vlsseg7.mask.triscv.vector.tuple_nxv4i8_7t.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 4 x i8>, 7) [[VD]], ptr [[RS1]], i64 [[RS2]], <vscale x 2 x i1> [[VM]], i64 [[VL]], i64 0, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 7) [[TMP0]]
//
vbfloat16mf2x7_t test_vlsseg7e16_v_bf16mf2x7_tumu(vbool32_t vm, vbfloat16mf2x7_t vd, const __bf16 *rs1, ptrdiff_t rs2, size_t vl) {
  return __riscv_vlsseg7e16_v_bf16mf2x7_tumu(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 7) @test_vlsseg7e16_v_bf16m1x7_tumu(
// CHECK-RV64-SAME: <vscale x 4 x i1> [[VM:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 7) [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 7) @llvm.riscv.vlsseg7.mask.triscv.vector.tuple_nxv8i8_7t.i64.nxv4i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 7) [[VD]], ptr [[RS1]], i64 [[RS2]], <vscale x 4 x i1> [[VM]], i64 [[VL]], i64 0, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 7) [[TMP0]]
//
vbfloat16m1x7_t test_vlsseg7e16_v_bf16m1x7_tumu(vbool16_t vm, vbfloat16m1x7_t vd, const __bf16 *rs1, ptrdiff_t rs2, size_t vl) {
  return __riscv_vlsseg7e16_v_bf16m1x7_tumu(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 7) @test_vlsseg7e16_v_bf16mf4x7_mu(
// CHECK-RV64-SAME: <vscale x 1 x i1> [[VM:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 7) [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 2 x i8>, 7) @llvm.riscv.vlsseg7.mask.triscv.vector.tuple_nxv2i8_7t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 2 x i8>, 7) [[VD]], ptr [[RS1]], i64 [[RS2]], <vscale x 1 x i1> [[VM]], i64 [[VL]], i64 1, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 7) [[TMP0]]
//
vbfloat16mf4x7_t test_vlsseg7e16_v_bf16mf4x7_mu(vbool64_t vm, vbfloat16mf4x7_t vd, const __bf16 *rs1, ptrdiff_t rs2, size_t vl) {
  return __riscv_vlsseg7e16_v_bf16mf4x7_mu(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 7) @test_vlsseg7e16_v_bf16mf2x7_mu(
// CHECK-RV64-SAME: <vscale x 2 x i1> [[VM:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 7) [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 7) @llvm.riscv.vlsseg7.mask.triscv.vector.tuple_nxv4i8_7t.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 4 x i8>, 7) [[VD]], ptr [[RS1]], i64 [[RS2]], <vscale x 2 x i1> [[VM]], i64 [[VL]], i64 1, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 7) [[TMP0]]
//
vbfloat16mf2x7_t test_vlsseg7e16_v_bf16mf2x7_mu(vbool32_t vm, vbfloat16mf2x7_t vd, const __bf16 *rs1, ptrdiff_t rs2, size_t vl) {
  return __riscv_vlsseg7e16_v_bf16mf2x7_mu(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 7) @test_vlsseg7e16_v_bf16m1x7_mu(
// CHECK-RV64-SAME: <vscale x 4 x i1> [[VM:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 7) [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 7) @llvm.riscv.vlsseg7.mask.triscv.vector.tuple_nxv8i8_7t.i64.nxv4i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 7) [[VD]], ptr [[RS1]], i64 [[RS2]], <vscale x 4 x i1> [[VM]], i64 [[VL]], i64 1, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 7) [[TMP0]]
//
vbfloat16m1x7_t test_vlsseg7e16_v_bf16m1x7_mu(vbool16_t vm, vbfloat16m1x7_t vd, const __bf16 *rs1, ptrdiff_t rs2, size_t vl) {
  return __riscv_vlsseg7e16_v_bf16m1x7_mu(vm, vd, rs1, rs2, vl);
}
