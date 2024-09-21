// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 2
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +zvfh -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 7) @test_vlseg7e64_v_f64m1x7_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 7) @llvm.riscv.vlseg7.mask.triscv.vector.tuple_nxv8i8_7t.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 7) poison, ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3, i64 6)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 7) [[TMP0]]
//
vfloat64m1x7_t test_vlseg7e64_v_f64m1x7_m(vbool64_t mask, const double *base, size_t vl) {
  return __riscv_vlseg7e64(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 7) @test_vlseg7e64_v_i64m1x7_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 7) @llvm.riscv.vlseg7.mask.triscv.vector.tuple_nxv8i8_7t.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 7) poison, ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3, i64 6)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 7) [[TMP0]]
//
vint64m1x7_t test_vlseg7e64_v_i64m1x7_m(vbool64_t mask, const int64_t *base, size_t vl) {
  return __riscv_vlseg7e64(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 7) @test_vlseg7e64_v_u64m1x7_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 7) @llvm.riscv.vlseg7.mask.triscv.vector.tuple_nxv8i8_7t.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 7) poison, ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3, i64 6)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 7) [[TMP0]]
//
vuint64m1x7_t test_vlseg7e64_v_u64m1x7_m(vbool64_t mask, const uint64_t *base, size_t vl) {
  return __riscv_vlseg7e64(mask, base, vl);
}

