// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 4
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v \
// RUN:   -target-feature +zvfbfmin \
// RUN:   -target-feature +zvfbfwma -disable-O0-optnone \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local void @test_vsseg2e16_v_bf16mf4x2(
// CHECK-RV64-SAME: ptr noundef [[RS1:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 2) [[VS3:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg2.triscv.vector.tuple_nxv2i8_2t.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 2) [[VS3]], ptr [[RS1]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg2e16_v_bf16mf4x2(__bf16 *rs1, vbfloat16mf4x2_t vs3, size_t vl) {
  return __riscv_vsseg2e16_v_bf16mf4x2(rs1, vs3, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg2e16_v_bf16mf2x2(
// CHECK-RV64-SAME: ptr noundef [[RS1:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 2) [[VS3:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg2.triscv.vector.tuple_nxv4i8_2t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 2) [[VS3]], ptr [[RS1]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg2e16_v_bf16mf2x2(__bf16 *rs1, vbfloat16mf2x2_t vs3, size_t vl) {
  return __riscv_vsseg2e16_v_bf16mf2x2(rs1, vs3, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg2e16_v_bf16m1x2(
// CHECK-RV64-SAME: ptr noundef [[RS1:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 2) [[VS3:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg2.triscv.vector.tuple_nxv8i8_2t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 2) [[VS3]], ptr [[RS1]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg2e16_v_bf16m1x2(__bf16 *rs1, vbfloat16m1x2_t vs3, size_t vl) {
  return __riscv_vsseg2e16_v_bf16m1x2(rs1, vs3, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg2e16_v_bf16m2x2(
// CHECK-RV64-SAME: ptr noundef [[RS1:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 2) [[VS3:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg2.triscv.vector.tuple_nxv16i8_2t.i64(target("riscv.vector.tuple", <vscale x 16 x i8>, 2) [[VS3]], ptr [[RS1]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg2e16_v_bf16m2x2(__bf16 *rs1, vbfloat16m2x2_t vs3, size_t vl) {
  return __riscv_vsseg2e16_v_bf16m2x2(rs1, vs3, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg2e16_v_bf16m4x2(
// CHECK-RV64-SAME: ptr noundef [[RS1:%.*]], target("riscv.vector.tuple", <vscale x 32 x i8>, 2) [[VS3:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg2.triscv.vector.tuple_nxv32i8_2t.i64(target("riscv.vector.tuple", <vscale x 32 x i8>, 2) [[VS3]], ptr [[RS1]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg2e16_v_bf16m4x2(__bf16 *rs1, vbfloat16m4x2_t vs3, size_t vl) {
  return __riscv_vsseg2e16_v_bf16m4x2(rs1, vs3, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg2e16_v_bf16mf4x2_m(
// CHECK-RV64-SAME: <vscale x 1 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 2) [[VS3:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg2.mask.triscv.vector.tuple_nxv2i8_2t.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 2) [[VS3]], ptr [[RS1]], <vscale x 1 x i1> [[VM]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg2e16_v_bf16mf4x2_m(vbool64_t vm, __bf16 *rs1,
                                  vbfloat16mf4x2_t vs3, size_t vl) {
  return __riscv_vsseg2e16_v_bf16mf4x2_m(vm, rs1, vs3, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg2e16_v_bf16mf2x2_m(
// CHECK-RV64-SAME: <vscale x 2 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 2) [[VS3:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg2.mask.triscv.vector.tuple_nxv4i8_2t.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 2) [[VS3]], ptr [[RS1]], <vscale x 2 x i1> [[VM]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg2e16_v_bf16mf2x2_m(vbool32_t vm, __bf16 *rs1,
                                  vbfloat16mf2x2_t vs3, size_t vl) {
  return __riscv_vsseg2e16_v_bf16mf2x2_m(vm, rs1, vs3, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg2e16_v_bf16m1x2_m(
// CHECK-RV64-SAME: <vscale x 4 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 2) [[VS3:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg2.mask.triscv.vector.tuple_nxv8i8_2t.nxv4i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 2) [[VS3]], ptr [[RS1]], <vscale x 4 x i1> [[VM]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg2e16_v_bf16m1x2_m(vbool16_t vm, __bf16 *rs1, vbfloat16m1x2_t vs3,
                                 size_t vl) {
  return __riscv_vsseg2e16_v_bf16m1x2_m(vm, rs1, vs3, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg2e16_v_bf16m2x2_m(
// CHECK-RV64-SAME: <vscale x 8 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 2) [[VS3:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg2.mask.triscv.vector.tuple_nxv16i8_2t.nxv8i1.i64(target("riscv.vector.tuple", <vscale x 16 x i8>, 2) [[VS3]], ptr [[RS1]], <vscale x 8 x i1> [[VM]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg2e16_v_bf16m2x2_m(vbool8_t vm, __bf16 *rs1, vbfloat16m2x2_t vs3,
                                 size_t vl) {
  return __riscv_vsseg2e16_v_bf16m2x2_m(vm, rs1, vs3, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg2e16_v_bf16m4x2_m(
// CHECK-RV64-SAME: <vscale x 16 x i1> [[VM:%.*]], ptr noundef [[RS1:%.*]], target("riscv.vector.tuple", <vscale x 32 x i8>, 2) [[VS3:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg2.mask.triscv.vector.tuple_nxv32i8_2t.nxv16i1.i64(target("riscv.vector.tuple", <vscale x 32 x i8>, 2) [[VS3]], ptr [[RS1]], <vscale x 16 x i1> [[VM]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg2e16_v_bf16m4x2_m(vbool4_t vm, __bf16 *rs1, vbfloat16m4x2_t vs3,
                                 size_t vl) {
  return __riscv_vsseg2e16_v_bf16m4x2_m(vm, rs1, vs3, vl);
}
