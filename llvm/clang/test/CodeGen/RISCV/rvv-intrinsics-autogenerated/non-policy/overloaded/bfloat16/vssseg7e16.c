// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 4
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v \
// RUN:   -target-feature +zvfbfmin \
// RUN:   -target-feature +zvfbfwma -disable-O0-optnone \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local void @test_vssseg7e16_v_bf16mf4x7(
// CHECK-RV64-SAME: ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 7) [[VS3:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg7.triscv.vector.tuple_nxv2i8_7t.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 7) [[VS3]], ptr [[RS1]], i64 [[RS2]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg7e16_v_bf16mf4x7(__bf16 *rs1, ptrdiff_t rs2,
                                 vbfloat16mf4x7_t vs3, size_t vl) {
  return __riscv_vssseg7e16(rs1, rs2, vs3, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg7e16_v_bf16mf2x7(
// CHECK-RV64-SAME: ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 7) [[VS3:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg7.triscv.vector.tuple_nxv4i8_7t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 7) [[VS3]], ptr [[RS1]], i64 [[RS2]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg7e16_v_bf16mf2x7(__bf16 *rs1, ptrdiff_t rs2,
                                 vbfloat16mf2x7_t vs3, size_t vl) {
  return __riscv_vssseg7e16(rs1, rs2, vs3, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg7e16_v_bf16m1x7(
// CHECK-RV64-SAME: ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 7) [[VS3:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg7.triscv.vector.tuple_nxv8i8_7t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 7) [[VS3]], ptr [[RS1]], i64 [[RS2]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg7e16_v_bf16m1x7(__bf16 *rs1, ptrdiff_t rs2, vbfloat16m1x7_t vs3,
                                size_t vl) {
  return __riscv_vssseg7e16(rs1, rs2, vs3, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg7e16_v_bf16mf4x7_m(
// CHECK-RV64-SAME: <vscale x 1 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 7) [[VS3:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg7.mask.triscv.vector.tuple_nxv2i8_7t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 2 x i8>, 7) [[VS3]], ptr [[RS1]], i64 [[RS2]], <vscale x 1 x i1> [[VM]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg7e16_v_bf16mf4x7_m(vbool64_t vm, __bf16 *rs1, ptrdiff_t rs2,
                                   vbfloat16mf4x7_t vs3, size_t vl) {
  return __riscv_vssseg7e16(vm, rs1, rs2, vs3, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg7e16_v_bf16mf2x7_m(
// CHECK-RV64-SAME: <vscale x 2 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 7) [[VS3:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg7.mask.triscv.vector.tuple_nxv4i8_7t.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 4 x i8>, 7) [[VS3]], ptr [[RS1]], i64 [[RS2]], <vscale x 2 x i1> [[VM]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg7e16_v_bf16mf2x7_m(vbool32_t vm, __bf16 *rs1, ptrdiff_t rs2,
                                   vbfloat16mf2x7_t vs3, size_t vl) {
  return __riscv_vssseg7e16(vm, rs1, rs2, vs3, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg7e16_v_bf16m1x7_m(
// CHECK-RV64-SAME: <vscale x 4 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], i64 noundef [[RS2:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 7) [[VS3:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg7.mask.triscv.vector.tuple_nxv8i8_7t.i64.nxv4i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 7) [[VS3]], ptr [[RS1]], i64 [[RS2]], <vscale x 4 x i1> [[VM]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg7e16_v_bf16m1x7_m(vbool16_t vm, __bf16 *rs1, ptrdiff_t rs2,
                                  vbfloat16m1x7_t vs3, size_t vl) {
  return __riscv_vssseg7e16(vm, rs1, rs2, vs3, vl);
}
