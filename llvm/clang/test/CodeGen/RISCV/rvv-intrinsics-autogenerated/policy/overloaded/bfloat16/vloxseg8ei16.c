// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 4
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v \
// RUN:   -target-feature +zvfbfmin \
// RUN:   -target-feature +zvfbfwma -disable-O0-optnone \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 8) @test_vloxseg8ei16_v_bf16mf4x8_tu(
// CHECK-RV64-SAME: target("riscv.vector.tuple", <vscale x 2 x i8>, 8) [[VD:%.*]], ptr noundef [[RS1:%.*]], <vscale x 1 x i16> [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 2 x i8>, 8) @llvm.riscv.vloxseg8.triscv.vector.tuple_nxv2i8_8t.nxv1i16.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 8) [[VD]], ptr [[RS1]], <vscale x 1 x i16> [[RS2]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 8) [[TMP0]]
//
vbfloat16mf4x8_t test_vloxseg8ei16_v_bf16mf4x8_tu(vbfloat16mf4x8_t vd,
                                                  const __bf16 *rs1,
                                                  vuint16mf4_t rs2, size_t vl) {
  return __riscv_vloxseg8ei16_tu(vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 8) @test_vloxseg8ei16_v_bf16mf2x8_tu(
// CHECK-RV64-SAME: target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[VD:%.*]], ptr noundef [[RS1:%.*]], <vscale x 2 x i16> [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 8) @llvm.riscv.vloxseg8.triscv.vector.tuple_nxv4i8_8t.nxv2i16.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[VD]], ptr [[RS1]], <vscale x 2 x i16> [[RS2]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[TMP0]]
//
vbfloat16mf2x8_t test_vloxseg8ei16_v_bf16mf2x8_tu(vbfloat16mf2x8_t vd,
                                                  const __bf16 *rs1,
                                                  vuint16mf2_t rs2, size_t vl) {
  return __riscv_vloxseg8ei16_tu(vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 8) @test_vloxseg8ei16_v_bf16m1x8_tu(
// CHECK-RV64-SAME: target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[VD:%.*]], ptr noundef [[RS1:%.*]], <vscale x 4 x i16> [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 8) @llvm.riscv.vloxseg8.triscv.vector.tuple_nxv8i8_8t.nxv4i16.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[VD]], ptr [[RS1]], <vscale x 4 x i16> [[RS2]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[TMP0]]
//
vbfloat16m1x8_t test_vloxseg8ei16_v_bf16m1x8_tu(vbfloat16m1x8_t vd,
                                                const __bf16 *rs1,
                                                vuint16m1_t rs2, size_t vl) {
  return __riscv_vloxseg8ei16_tu(vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 8) @test_vloxseg8ei16_v_bf16mf4x8_tum(
// CHECK-RV64-SAME: <vscale x 1 x i1> [[VM:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 8) [[VD:%.*]], ptr noundef [[RS1:%.*]], <vscale x 1 x i16> [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 2 x i8>, 8) @llvm.riscv.vloxseg8.mask.triscv.vector.tuple_nxv2i8_8t.nxv1i16.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 8) [[VD]], ptr [[RS1]], <vscale x 1 x i16> [[RS2]], <vscale x 1 x i1> [[VM]], i64 [[VL]], i64 2, i64 0)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 8) [[TMP0]]
//
vbfloat16mf4x8_t test_vloxseg8ei16_v_bf16mf4x8_tum(vbool64_t vm,
                                                   vbfloat16mf4x8_t vd,
                                                   const __bf16 *rs1,
                                                   vuint16mf4_t rs2,
                                                   size_t vl) {
  return __riscv_vloxseg8ei16_tum(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 8) @test_vloxseg8ei16_v_bf16mf2x8_tum(
// CHECK-RV64-SAME: <vscale x 2 x i1> [[VM:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[VD:%.*]], ptr noundef [[RS1:%.*]], <vscale x 2 x i16> [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 8) @llvm.riscv.vloxseg8.mask.triscv.vector.tuple_nxv4i8_8t.nxv2i16.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[VD]], ptr [[RS1]], <vscale x 2 x i16> [[RS2]], <vscale x 2 x i1> [[VM]], i64 [[VL]], i64 2, i64 0)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[TMP0]]
//
vbfloat16mf2x8_t test_vloxseg8ei16_v_bf16mf2x8_tum(vbool32_t vm,
                                                   vbfloat16mf2x8_t vd,
                                                   const __bf16 *rs1,
                                                   vuint16mf2_t rs2,
                                                   size_t vl) {
  return __riscv_vloxseg8ei16_tum(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 8) @test_vloxseg8ei16_v_bf16m1x8_tum(
// CHECK-RV64-SAME: <vscale x 4 x i1> [[VM:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[VD:%.*]], ptr noundef [[RS1:%.*]], <vscale x 4 x i16> [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 8) @llvm.riscv.vloxseg8.mask.triscv.vector.tuple_nxv8i8_8t.nxv4i16.nxv4i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[VD]], ptr [[RS1]], <vscale x 4 x i16> [[RS2]], <vscale x 4 x i1> [[VM]], i64 [[VL]], i64 2, i64 0)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[TMP0]]
//
vbfloat16m1x8_t test_vloxseg8ei16_v_bf16m1x8_tum(vbool16_t vm,
                                                 vbfloat16m1x8_t vd,
                                                 const __bf16 *rs1,
                                                 vuint16m1_t rs2, size_t vl) {
  return __riscv_vloxseg8ei16_tum(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 8) @test_vloxseg8ei16_v_bf16mf4x8_tumu(
// CHECK-RV64-SAME: <vscale x 1 x i1> [[VM:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 8) [[VD:%.*]], ptr noundef [[RS1:%.*]], <vscale x 1 x i16> [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 2 x i8>, 8) @llvm.riscv.vloxseg8.mask.triscv.vector.tuple_nxv2i8_8t.nxv1i16.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 8) [[VD]], ptr [[RS1]], <vscale x 1 x i16> [[RS2]], <vscale x 1 x i1> [[VM]], i64 [[VL]], i64 0, i64 0)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 8) [[TMP0]]
//
vbfloat16mf4x8_t test_vloxseg8ei16_v_bf16mf4x8_tumu(vbool64_t vm,
                                                    vbfloat16mf4x8_t vd,
                                                    const __bf16 *rs1,
                                                    vuint16mf4_t rs2,
                                                    size_t vl) {
  return __riscv_vloxseg8ei16_tumu(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 8) @test_vloxseg8ei16_v_bf16mf2x8_tumu(
// CHECK-RV64-SAME: <vscale x 2 x i1> [[VM:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[VD:%.*]], ptr noundef [[RS1:%.*]], <vscale x 2 x i16> [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 8) @llvm.riscv.vloxseg8.mask.triscv.vector.tuple_nxv4i8_8t.nxv2i16.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[VD]], ptr [[RS1]], <vscale x 2 x i16> [[RS2]], <vscale x 2 x i1> [[VM]], i64 [[VL]], i64 0, i64 0)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[TMP0]]
//
vbfloat16mf2x8_t test_vloxseg8ei16_v_bf16mf2x8_tumu(vbool32_t vm,
                                                    vbfloat16mf2x8_t vd,
                                                    const __bf16 *rs1,
                                                    vuint16mf2_t rs2,
                                                    size_t vl) {
  return __riscv_vloxseg8ei16_tumu(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 8) @test_vloxseg8ei16_v_bf16m1x8_tumu(
// CHECK-RV64-SAME: <vscale x 4 x i1> [[VM:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[VD:%.*]], ptr noundef [[RS1:%.*]], <vscale x 4 x i16> [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 8) @llvm.riscv.vloxseg8.mask.triscv.vector.tuple_nxv8i8_8t.nxv4i16.nxv4i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[VD]], ptr [[RS1]], <vscale x 4 x i16> [[RS2]], <vscale x 4 x i1> [[VM]], i64 [[VL]], i64 0, i64 0)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[TMP0]]
//
vbfloat16m1x8_t test_vloxseg8ei16_v_bf16m1x8_tumu(vbool16_t vm,
                                                  vbfloat16m1x8_t vd,
                                                  const __bf16 *rs1,
                                                  vuint16m1_t rs2, size_t vl) {
  return __riscv_vloxseg8ei16_tumu(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 8) @test_vloxseg8ei16_v_bf16mf4x8_mu(
// CHECK-RV64-SAME: <vscale x 1 x i1> [[VM:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 8) [[VD:%.*]], ptr noundef [[RS1:%.*]], <vscale x 1 x i16> [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 2 x i8>, 8) @llvm.riscv.vloxseg8.mask.triscv.vector.tuple_nxv2i8_8t.nxv1i16.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 8) [[VD]], ptr [[RS1]], <vscale x 1 x i16> [[RS2]], <vscale x 1 x i1> [[VM]], i64 [[VL]], i64 1, i64 0)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 8) [[TMP0]]
//
vbfloat16mf4x8_t test_vloxseg8ei16_v_bf16mf4x8_mu(vbool64_t vm,
                                                  vbfloat16mf4x8_t vd,
                                                  const __bf16 *rs1,
                                                  vuint16mf4_t rs2, size_t vl) {
  return __riscv_vloxseg8ei16_mu(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 8) @test_vloxseg8ei16_v_bf16mf2x8_mu(
// CHECK-RV64-SAME: <vscale x 2 x i1> [[VM:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[VD:%.*]], ptr noundef [[RS1:%.*]], <vscale x 2 x i16> [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 8) @llvm.riscv.vloxseg8.mask.triscv.vector.tuple_nxv4i8_8t.nxv2i16.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[VD]], ptr [[RS1]], <vscale x 2 x i16> [[RS2]], <vscale x 2 x i1> [[VM]], i64 [[VL]], i64 1, i64 0)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[TMP0]]
//
vbfloat16mf2x8_t test_vloxseg8ei16_v_bf16mf2x8_mu(vbool32_t vm,
                                                  vbfloat16mf2x8_t vd,
                                                  const __bf16 *rs1,
                                                  vuint16mf2_t rs2, size_t vl) {
  return __riscv_vloxseg8ei16_mu(vm, vd, rs1, rs2, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 8) @test_vloxseg8ei16_v_bf16m1x8_mu(
// CHECK-RV64-SAME: <vscale x 4 x i1> [[VM:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[VD:%.*]], ptr noundef [[RS1:%.*]], <vscale x 4 x i16> [[RS2:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 8) @llvm.riscv.vloxseg8.mask.triscv.vector.tuple_nxv8i8_8t.nxv4i16.nxv4i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[VD]], ptr [[RS1]], <vscale x 4 x i16> [[RS2]], <vscale x 4 x i1> [[VM]], i64 [[VL]], i64 1, i64 0)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[TMP0]]
//
vbfloat16m1x8_t test_vloxseg8ei16_v_bf16m1x8_mu(vbool16_t vm,
                                                vbfloat16m1x8_t vd,
                                                const __bf16 *rs1,
                                                vuint16m1_t rs2, size_t vl) {
  return __riscv_vloxseg8ei16_mu(vm, vd, rs1, rs2, vl);
}
