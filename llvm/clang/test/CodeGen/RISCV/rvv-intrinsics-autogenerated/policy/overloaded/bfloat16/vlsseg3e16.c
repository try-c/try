// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 4
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v \
// RUN:   -target-feature +zvfbfmin \
// RUN:   -target-feature +zvfbfwma -disable-O0-optnone \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 3) @test_vlsseg3e16_v_bf16mf4x3_tu(
// CHECK-RV64-SAME: target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 2 x i8>, 3) @llvm.riscv.vlsseg3.triscv.vector.tuple_nxv2i8_3t.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[VD]], ptr [[RS1]], i64 [[RS2]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[TMP0]]
//
vbfloat16mf4x3_t test_vlsseg3e16_v_bf16mf4x3_tu(vbfloat16mf4x3_t vd,
                                                const __bf16 *rs1,
                                                ptrdiff_t rs2, size_t vl) {
  return __riscv_vlsseg3e16_tu(vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @test_vlsseg3e16_v_bf16mf2x3_tu(
// CHECK-RV64-SAME: target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @llvm.riscv.vlsseg3.triscv.vector.tuple_nxv4i8_3t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[VD]], ptr [[RS1]], i64 [[RS2]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[TMP0]]
//
vbfloat16mf2x3_t test_vlsseg3e16_v_bf16mf2x3_tu(vbfloat16mf2x3_t vd,
                                                const __bf16 *rs1,
                                                ptrdiff_t rs2, size_t vl) {
  return __riscv_vlsseg3e16_tu(vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @test_vlsseg3e16_v_bf16m1x3_tu(
// CHECK-RV64-SAME: target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @llvm.riscv.vlsseg3.triscv.vector.tuple_nxv8i8_3t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[VD]], ptr [[RS1]], i64 [[RS2]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[TMP0]]
//
vbfloat16m1x3_t test_vlsseg3e16_v_bf16m1x3_tu(vbfloat16m1x3_t vd,
                                              const __bf16 *rs1, ptrdiff_t rs2,
                                              size_t vl) {
  return __riscv_vlsseg3e16_tu(vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @test_vlsseg3e16_v_bf16m2x3_tu(
// CHECK-RV64-SAME: target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @llvm.riscv.vlsseg3.triscv.vector.tuple_nxv16i8_3t.i64(target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[VD]], ptr [[RS1]], i64 [[RS2]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[TMP0]]
//
vbfloat16m2x3_t test_vlsseg3e16_v_bf16m2x3_tu(vbfloat16m2x3_t vd,
                                              const __bf16 *rs1, ptrdiff_t rs2,
                                              size_t vl) {
  return __riscv_vlsseg3e16_tu(vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 3) @test_vlsseg3e16_v_bf16mf4x3_tum(
// CHECK-RV64-SAME: <vscale x 1 x i1> [[VM:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 2 x i8>, 3) @llvm.riscv.vlsseg3.mask.triscv.vector.tuple_nxv2i8_3t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[VD]], ptr [[RS1]], i64 [[RS2]], <vscale x 1 x i1> [[VM]], i64 [[VL]], i64 2, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[TMP0]]
//
vbfloat16mf4x3_t test_vlsseg3e16_v_bf16mf4x3_tum(vbool64_t vm,
                                                 vbfloat16mf4x3_t vd,
                                                 const __bf16 *rs1,
                                                 ptrdiff_t rs2, size_t vl) {
  return __riscv_vlsseg3e16_tum(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @test_vlsseg3e16_v_bf16mf2x3_tum(
// CHECK-RV64-SAME: <vscale x 2 x i1> [[VM:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @llvm.riscv.vlsseg3.mask.triscv.vector.tuple_nxv4i8_3t.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[VD]], ptr [[RS1]], i64 [[RS2]], <vscale x 2 x i1> [[VM]], i64 [[VL]], i64 2, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[TMP0]]
//
vbfloat16mf2x3_t test_vlsseg3e16_v_bf16mf2x3_tum(vbool32_t vm,
                                                 vbfloat16mf2x3_t vd,
                                                 const __bf16 *rs1,
                                                 ptrdiff_t rs2, size_t vl) {
  return __riscv_vlsseg3e16_tum(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @test_vlsseg3e16_v_bf16m1x3_tum(
// CHECK-RV64-SAME: <vscale x 4 x i1> [[VM:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @llvm.riscv.vlsseg3.mask.triscv.vector.tuple_nxv8i8_3t.i64.nxv4i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[VD]], ptr [[RS1]], i64 [[RS2]], <vscale x 4 x i1> [[VM]], i64 [[VL]], i64 2, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[TMP0]]
//
vbfloat16m1x3_t test_vlsseg3e16_v_bf16m1x3_tum(vbool16_t vm, vbfloat16m1x3_t vd,
                                               const __bf16 *rs1, ptrdiff_t rs2,
                                               size_t vl) {
  return __riscv_vlsseg3e16_tum(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @test_vlsseg3e16_v_bf16m2x3_tum(
// CHECK-RV64-SAME: <vscale x 8 x i1> [[VM:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @llvm.riscv.vlsseg3.mask.triscv.vector.tuple_nxv16i8_3t.i64.nxv8i1(target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[VD]], ptr [[RS1]], i64 [[RS2]], <vscale x 8 x i1> [[VM]], i64 [[VL]], i64 2, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[TMP0]]
//
vbfloat16m2x3_t test_vlsseg3e16_v_bf16m2x3_tum(vbool8_t vm, vbfloat16m2x3_t vd,
                                               const __bf16 *rs1, ptrdiff_t rs2,
                                               size_t vl) {
  return __riscv_vlsseg3e16_tum(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 3) @test_vlsseg3e16_v_bf16mf4x3_tumu(
// CHECK-RV64-SAME: <vscale x 1 x i1> [[VM:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 2 x i8>, 3) @llvm.riscv.vlsseg3.mask.triscv.vector.tuple_nxv2i8_3t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[VD]], ptr [[RS1]], i64 [[RS2]], <vscale x 1 x i1> [[VM]], i64 [[VL]], i64 0, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[TMP0]]
//
vbfloat16mf4x3_t test_vlsseg3e16_v_bf16mf4x3_tumu(vbool64_t vm,
                                                  vbfloat16mf4x3_t vd,
                                                  const __bf16 *rs1,
                                                  ptrdiff_t rs2, size_t vl) {
  return __riscv_vlsseg3e16_tumu(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @test_vlsseg3e16_v_bf16mf2x3_tumu(
// CHECK-RV64-SAME: <vscale x 2 x i1> [[VM:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @llvm.riscv.vlsseg3.mask.triscv.vector.tuple_nxv4i8_3t.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[VD]], ptr [[RS1]], i64 [[RS2]], <vscale x 2 x i1> [[VM]], i64 [[VL]], i64 0, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[TMP0]]
//
vbfloat16mf2x3_t test_vlsseg3e16_v_bf16mf2x3_tumu(vbool32_t vm,
                                                  vbfloat16mf2x3_t vd,
                                                  const __bf16 *rs1,
                                                  ptrdiff_t rs2, size_t vl) {
  return __riscv_vlsseg3e16_tumu(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @test_vlsseg3e16_v_bf16m1x3_tumu(
// CHECK-RV64-SAME: <vscale x 4 x i1> [[VM:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @llvm.riscv.vlsseg3.mask.triscv.vector.tuple_nxv8i8_3t.i64.nxv4i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[VD]], ptr [[RS1]], i64 [[RS2]], <vscale x 4 x i1> [[VM]], i64 [[VL]], i64 0, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[TMP0]]
//
vbfloat16m1x3_t test_vlsseg3e16_v_bf16m1x3_tumu(vbool16_t vm,
                                                vbfloat16m1x3_t vd,
                                                const __bf16 *rs1,
                                                ptrdiff_t rs2, size_t vl) {
  return __riscv_vlsseg3e16_tumu(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @test_vlsseg3e16_v_bf16m2x3_tumu(
// CHECK-RV64-SAME: <vscale x 8 x i1> [[VM:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @llvm.riscv.vlsseg3.mask.triscv.vector.tuple_nxv16i8_3t.i64.nxv8i1(target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[VD]], ptr [[RS1]], i64 [[RS2]], <vscale x 8 x i1> [[VM]], i64 [[VL]], i64 0, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[TMP0]]
//
vbfloat16m2x3_t test_vlsseg3e16_v_bf16m2x3_tumu(vbool8_t vm, vbfloat16m2x3_t vd,
                                                const __bf16 *rs1,
                                                ptrdiff_t rs2, size_t vl) {
  return __riscv_vlsseg3e16_tumu(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 3) @test_vlsseg3e16_v_bf16mf4x3_mu(
// CHECK-RV64-SAME: <vscale x 1 x i1> [[VM:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 2 x i8>, 3) @llvm.riscv.vlsseg3.mask.triscv.vector.tuple_nxv2i8_3t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[VD]], ptr [[RS1]], i64 [[RS2]], <vscale x 1 x i1> [[VM]], i64 [[VL]], i64 1, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[TMP0]]
//
vbfloat16mf4x3_t test_vlsseg3e16_v_bf16mf4x3_mu(vbool64_t vm,
                                                vbfloat16mf4x3_t vd,
                                                const __bf16 *rs1,
                                                ptrdiff_t rs2, size_t vl) {
  return __riscv_vlsseg3e16_mu(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @test_vlsseg3e16_v_bf16mf2x3_mu(
// CHECK-RV64-SAME: <vscale x 2 x i1> [[VM:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @llvm.riscv.vlsseg3.mask.triscv.vector.tuple_nxv4i8_3t.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[VD]], ptr [[RS1]], i64 [[RS2]], <vscale x 2 x i1> [[VM]], i64 [[VL]], i64 1, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[TMP0]]
//
vbfloat16mf2x3_t test_vlsseg3e16_v_bf16mf2x3_mu(vbool32_t vm,
                                                vbfloat16mf2x3_t vd,
                                                const __bf16 *rs1,
                                                ptrdiff_t rs2, size_t vl) {
  return __riscv_vlsseg3e16_mu(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @test_vlsseg3e16_v_bf16m1x3_mu(
// CHECK-RV64-SAME: <vscale x 4 x i1> [[VM:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @llvm.riscv.vlsseg3.mask.triscv.vector.tuple_nxv8i8_3t.i64.nxv4i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[VD]], ptr [[RS1]], i64 [[RS2]], <vscale x 4 x i1> [[VM]], i64 [[VL]], i64 1, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[TMP0]]
//
vbfloat16m1x3_t test_vlsseg3e16_v_bf16m1x3_mu(vbool16_t vm, vbfloat16m1x3_t vd,
                                              const __bf16 *rs1, ptrdiff_t rs2,
                                              size_t vl) {
  return __riscv_vlsseg3e16_mu(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @test_vlsseg3e16_v_bf16m2x3_mu(
// CHECK-RV64-SAME: <vscale x 8 x i1> [[VM:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[VD:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @llvm.riscv.vlsseg3.mask.triscv.vector.tuple_nxv16i8_3t.i64.nxv8i1(target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[VD]], ptr [[RS1]], i64 [[RS2]], <vscale x 8 x i1> [[VM]], i64 [[VL]], i64 1, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[TMP0]]
//
vbfloat16m2x3_t test_vlsseg3e16_v_bf16m2x3_mu(vbool8_t vm, vbfloat16m2x3_t vd,
                                              const __bf16 *rs1, ptrdiff_t rs2,
                                              size_t vl) {
  return __riscv_vlsseg3e16_mu(vm, vd, rs1, rs2, vl);
}
