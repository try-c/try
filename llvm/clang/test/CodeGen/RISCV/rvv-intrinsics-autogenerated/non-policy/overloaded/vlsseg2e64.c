// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 2
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +zvfh -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 2) @test_vlsseg2e64_v_f64m1x2_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 2) @llvm.riscv.vlsseg2.mask.triscv.vector.tuple_nxv8i8_2t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 2) poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3, i64 6)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 2) [[TMP0]]
//
vfloat64m1x2_t test_vlsseg2e64_v_f64m1x2_m(vbool64_t mask, const double *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg2e64(mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 16 x i8>, 2) @test_vlsseg2e64_v_f64m2x2_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 16 x i8>, 2) @llvm.riscv.vlsseg2.mask.triscv.vector.tuple_nxv16i8_2t.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 16 x i8>, 2) poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3, i64 6)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 16 x i8>, 2) [[TMP0]]
//
vfloat64m2x2_t test_vlsseg2e64_v_f64m2x2_m(vbool32_t mask, const double *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg2e64(mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 32 x i8>, 2) @test_vlsseg2e64_v_f64m4x2_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 32 x i8>, 2) @llvm.riscv.vlsseg2.mask.triscv.vector.tuple_nxv32i8_2t.i64.nxv4i1(target("riscv.vector.tuple", <vscale x 32 x i8>, 2) poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 3, i64 6)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 32 x i8>, 2) [[TMP0]]
//
vfloat64m4x2_t test_vlsseg2e64_v_f64m4x2_m(vbool16_t mask, const double *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg2e64(mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 2) @test_vlsseg2e64_v_i64m1x2_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 2) @llvm.riscv.vlsseg2.mask.triscv.vector.tuple_nxv8i8_2t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 2) poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3, i64 6)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 2) [[TMP0]]
//
vint64m1x2_t test_vlsseg2e64_v_i64m1x2_m(vbool64_t mask, const int64_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg2e64(mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 16 x i8>, 2) @test_vlsseg2e64_v_i64m2x2_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 16 x i8>, 2) @llvm.riscv.vlsseg2.mask.triscv.vector.tuple_nxv16i8_2t.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 16 x i8>, 2) poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3, i64 6)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 16 x i8>, 2) [[TMP0]]
//
vint64m2x2_t test_vlsseg2e64_v_i64m2x2_m(vbool32_t mask, const int64_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg2e64(mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 32 x i8>, 2) @test_vlsseg2e64_v_i64m4x2_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 32 x i8>, 2) @llvm.riscv.vlsseg2.mask.triscv.vector.tuple_nxv32i8_2t.i64.nxv4i1(target("riscv.vector.tuple", <vscale x 32 x i8>, 2) poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 3, i64 6)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 32 x i8>, 2) [[TMP0]]
//
vint64m4x2_t test_vlsseg2e64_v_i64m4x2_m(vbool16_t mask, const int64_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg2e64(mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 2) @test_vlsseg2e64_v_u64m1x2_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 2) @llvm.riscv.vlsseg2.mask.triscv.vector.tuple_nxv8i8_2t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 2) poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3, i64 6)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 2) [[TMP0]]
//
vuint64m1x2_t test_vlsseg2e64_v_u64m1x2_m(vbool64_t mask, const uint64_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg2e64(mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 16 x i8>, 2) @test_vlsseg2e64_v_u64m2x2_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 16 x i8>, 2) @llvm.riscv.vlsseg2.mask.triscv.vector.tuple_nxv16i8_2t.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 16 x i8>, 2) poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3, i64 6)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 16 x i8>, 2) [[TMP0]]
//
vuint64m2x2_t test_vlsseg2e64_v_u64m2x2_m(vbool32_t mask, const uint64_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg2e64(mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 32 x i8>, 2) @test_vlsseg2e64_v_u64m4x2_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 32 x i8>, 2) @llvm.riscv.vlsseg2.mask.triscv.vector.tuple_nxv32i8_2t.i64.nxv4i1(target("riscv.vector.tuple", <vscale x 32 x i8>, 2) poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 3, i64 6)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 32 x i8>, 2) [[TMP0]]
//
vuint64m4x2_t test_vlsseg2e64_v_u64m4x2_m(vbool16_t mask, const uint64_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg2e64(mask, base, bstride, vl);
}

