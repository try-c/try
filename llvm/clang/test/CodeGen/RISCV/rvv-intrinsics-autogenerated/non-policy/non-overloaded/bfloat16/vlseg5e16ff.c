// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 4
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v \
// RUN:   -target-feature +zvfbfmin \
// RUN:   -target-feature +zvfbfwma -disable-O0-optnone \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 5) @test_vlseg5e16ff_v_bf16mf4x5(
// CHECK-RV64-SAME: ptr noundef [[RS1:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { target("riscv.vector.tuple", <vscale x 2 x i8>, 5), i64 } @llvm.riscv.vlseg5ff.triscv.vector.tuple_nxv2i8_5t.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 5) poison, ptr [[RS1]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 2 x i8>, 5), i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 2 x i8>, 5), i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 5) [[TMP1]]
//
vbfloat16mf4x5_t test_vlseg5e16ff_v_bf16mf4x5(const __bf16 *rs1, size_t *new_vl,
                                              size_t vl) {
  return __riscv_vlseg5e16ff_v_bf16mf4x5(rs1, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 5) @test_vlseg5e16ff_v_bf16mf2x5(
// CHECK-RV64-SAME: ptr noundef [[RS1:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { target("riscv.vector.tuple", <vscale x 4 x i8>, 5), i64 } @llvm.riscv.vlseg5ff.triscv.vector.tuple_nxv4i8_5t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 5) poison, ptr [[RS1]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 4 x i8>, 5), i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 4 x i8>, 5), i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 5) [[TMP1]]
//
vbfloat16mf2x5_t test_vlseg5e16ff_v_bf16mf2x5(const __bf16 *rs1, size_t *new_vl,
                                              size_t vl) {
  return __riscv_vlseg5e16ff_v_bf16mf2x5(rs1, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 5) @test_vlseg5e16ff_v_bf16m1x5(
// CHECK-RV64-SAME: ptr noundef [[RS1:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { target("riscv.vector.tuple", <vscale x 8 x i8>, 5), i64 } @llvm.riscv.vlseg5ff.triscv.vector.tuple_nxv8i8_5t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 5) poison, ptr [[RS1]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 8 x i8>, 5), i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 8 x i8>, 5), i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 5) [[TMP1]]
//
vbfloat16m1x5_t test_vlseg5e16ff_v_bf16m1x5(const __bf16 *rs1, size_t *new_vl,
                                            size_t vl) {
  return __riscv_vlseg5e16ff_v_bf16m1x5(rs1, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 5) @test_vlseg5e16ff_v_bf16mf4x5_m(
// CHECK-RV64-SAME: <vscale x 1 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { target("riscv.vector.tuple", <vscale x 2 x i8>, 5), i64 } @llvm.riscv.vlseg5ff.mask.triscv.vector.tuple_nxv2i8_5t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 2 x i8>, 5) poison, ptr [[RS1]], <vscale x 1 x i1> [[VM]], i64 [[VL]], i64 3, i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 2 x i8>, 5), i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 2 x i8>, 5), i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 5) [[TMP1]]
//
vbfloat16mf4x5_t test_vlseg5e16ff_v_bf16mf4x5_m(vbool64_t vm, const __bf16 *rs1,
                                                size_t *new_vl, size_t vl) {
  return __riscv_vlseg5e16ff_v_bf16mf4x5_m(vm, rs1, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 5) @test_vlseg5e16ff_v_bf16mf2x5_m(
// CHECK-RV64-SAME: <vscale x 2 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { target("riscv.vector.tuple", <vscale x 4 x i8>, 5), i64 } @llvm.riscv.vlseg5ff.mask.triscv.vector.tuple_nxv4i8_5t.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 4 x i8>, 5) poison, ptr [[RS1]], <vscale x 2 x i1> [[VM]], i64 [[VL]], i64 3, i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 4 x i8>, 5), i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 4 x i8>, 5), i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 5) [[TMP1]]
//
vbfloat16mf2x5_t test_vlseg5e16ff_v_bf16mf2x5_m(vbool32_t vm, const __bf16 *rs1,
                                                size_t *new_vl, size_t vl) {
  return __riscv_vlseg5e16ff_v_bf16mf2x5_m(vm, rs1, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 5) @test_vlseg5e16ff_v_bf16m1x5_m(
// CHECK-RV64-SAME: <vscale x 4 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { target("riscv.vector.tuple", <vscale x 8 x i8>, 5), i64 } @llvm.riscv.vlseg5ff.mask.triscv.vector.tuple_nxv8i8_5t.i64.nxv4i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 5) poison, ptr [[RS1]], <vscale x 4 x i1> [[VM]], i64 [[VL]], i64 3, i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 8 x i8>, 5), i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 8 x i8>, 5), i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 5) [[TMP1]]
//
vbfloat16m1x5_t test_vlseg5e16ff_v_bf16m1x5_m(vbool16_t vm, const __bf16 *rs1,
                                              size_t *new_vl, size_t vl) {
  return __riscv_vlseg5e16ff_v_bf16m1x5_m(vm, rs1, new_vl, vl);
}
