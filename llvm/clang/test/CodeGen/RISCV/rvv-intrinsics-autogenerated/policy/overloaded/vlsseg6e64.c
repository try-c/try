// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 2
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +zvfh -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @test_vlsseg6e64_v_f64m1x6_tu
// CHECK-RV64-SAME: (target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @llvm.riscv.vlsseg6.triscv.vector.tuple_nxv8i8_6t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 6)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[TMP0]]
//
vfloat64m1x6_t test_vlsseg6e64_v_f64m1x6_tu(vfloat64m1x6_t maskedoff_tuple, const double *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e64_tu(maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @test_vlsseg6e64_v_i64m1x6_tu
// CHECK-RV64-SAME: (target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @llvm.riscv.vlsseg6.triscv.vector.tuple_nxv8i8_6t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 6)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[TMP0]]
//
vint64m1x6_t test_vlsseg6e64_v_i64m1x6_tu(vint64m1x6_t maskedoff_tuple, const int64_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e64_tu(maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @test_vlsseg6e64_v_u64m1x6_tu
// CHECK-RV64-SAME: (target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @llvm.riscv.vlsseg6.triscv.vector.tuple_nxv8i8_6t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 6)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[TMP0]]
//
vuint64m1x6_t test_vlsseg6e64_v_u64m1x6_tu(vuint64m1x6_t maskedoff_tuple, const uint64_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e64_tu(maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @test_vlsseg6e64_v_f64m1x6_tum
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @llvm.riscv.vlsseg6.mask.triscv.vector.tuple_nxv8i8_6t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 2, i64 6)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[TMP0]]
//
vfloat64m1x6_t test_vlsseg6e64_v_f64m1x6_tum(vbool64_t mask, vfloat64m1x6_t maskedoff_tuple, const double *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e64_tum(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @test_vlsseg6e64_v_i64m1x6_tum
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @llvm.riscv.vlsseg6.mask.triscv.vector.tuple_nxv8i8_6t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 2, i64 6)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[TMP0]]
//
vint64m1x6_t test_vlsseg6e64_v_i64m1x6_tum(vbool64_t mask, vint64m1x6_t maskedoff_tuple, const int64_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e64_tum(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @test_vlsseg6e64_v_u64m1x6_tum
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @llvm.riscv.vlsseg6.mask.triscv.vector.tuple_nxv8i8_6t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 2, i64 6)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[TMP0]]
//
vuint64m1x6_t test_vlsseg6e64_v_u64m1x6_tum(vbool64_t mask, vuint64m1x6_t maskedoff_tuple, const uint64_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e64_tum(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @test_vlsseg6e64_v_f64m1x6_tumu
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @llvm.riscv.vlsseg6.mask.triscv.vector.tuple_nxv8i8_6t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 0, i64 6)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[TMP0]]
//
vfloat64m1x6_t test_vlsseg6e64_v_f64m1x6_tumu(vbool64_t mask, vfloat64m1x6_t maskedoff_tuple, const double *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e64_tumu(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @test_vlsseg6e64_v_i64m1x6_tumu
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @llvm.riscv.vlsseg6.mask.triscv.vector.tuple_nxv8i8_6t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 0, i64 6)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[TMP0]]
//
vint64m1x6_t test_vlsseg6e64_v_i64m1x6_tumu(vbool64_t mask, vint64m1x6_t maskedoff_tuple, const int64_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e64_tumu(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @test_vlsseg6e64_v_u64m1x6_tumu
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @llvm.riscv.vlsseg6.mask.triscv.vector.tuple_nxv8i8_6t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 0, i64 6)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[TMP0]]
//
vuint64m1x6_t test_vlsseg6e64_v_u64m1x6_tumu(vbool64_t mask, vuint64m1x6_t maskedoff_tuple, const uint64_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e64_tumu(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @test_vlsseg6e64_v_f64m1x6_mu
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @llvm.riscv.vlsseg6.mask.triscv.vector.tuple_nxv8i8_6t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 1, i64 6)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[TMP0]]
//
vfloat64m1x6_t test_vlsseg6e64_v_f64m1x6_mu(vbool64_t mask, vfloat64m1x6_t maskedoff_tuple, const double *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e64_mu(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @test_vlsseg6e64_v_i64m1x6_mu
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @llvm.riscv.vlsseg6.mask.triscv.vector.tuple_nxv8i8_6t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 1, i64 6)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[TMP0]]
//
vint64m1x6_t test_vlsseg6e64_v_i64m1x6_mu(vbool64_t mask, vint64m1x6_t maskedoff_tuple, const int64_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e64_mu(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @test_vlsseg6e64_v_u64m1x6_mu
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @llvm.riscv.vlsseg6.mask.triscv.vector.tuple_nxv8i8_6t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 1, i64 6)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[TMP0]]
//
vuint64m1x6_t test_vlsseg6e64_v_u64m1x6_mu(vbool64_t mask, vuint64m1x6_t maskedoff_tuple, const uint64_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e64_mu(mask, maskedoff_tuple, base, bstride, vl);
}

