// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 2
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +zvfh -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 1 x i8>, 6) @test_vlsseg6e8_v_i8mf8x6_tu
// CHECK-RV64-SAME: (target("riscv.vector.tuple", <vscale x 1 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 1 x i8>, 6) @llvm.riscv.vlsseg6.triscv.vector.tuple_nxv1i8_6t.i64(target("riscv.vector.tuple", <vscale x 1 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 1 x i8>, 6) [[TMP0]]
//
vint8mf8x6_t test_vlsseg6e8_v_i8mf8x6_tu(vint8mf8x6_t maskedoff_tuple, const int8_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e8_v_i8mf8x6_tu(maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 6) @test_vlsseg6e8_v_i8mf4x6_tu
// CHECK-RV64-SAME: (target("riscv.vector.tuple", <vscale x 2 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 2 x i8>, 6) @llvm.riscv.vlsseg6.triscv.vector.tuple_nxv2i8_6t.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 6) [[TMP0]]
//
vint8mf4x6_t test_vlsseg6e8_v_i8mf4x6_tu(vint8mf4x6_t maskedoff_tuple, const int8_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e8_v_i8mf4x6_tu(maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 6) @test_vlsseg6e8_v_i8mf2x6_tu
// CHECK-RV64-SAME: (target("riscv.vector.tuple", <vscale x 4 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 6) @llvm.riscv.vlsseg6.triscv.vector.tuple_nxv4i8_6t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 6) [[TMP0]]
//
vint8mf2x6_t test_vlsseg6e8_v_i8mf2x6_tu(vint8mf2x6_t maskedoff_tuple, const int8_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e8_v_i8mf2x6_tu(maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @test_vlsseg6e8_v_i8m1x6_tu
// CHECK-RV64-SAME: (target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @llvm.riscv.vlsseg6.triscv.vector.tuple_nxv8i8_6t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[TMP0]]
//
vint8m1x6_t test_vlsseg6e8_v_i8m1x6_tu(vint8m1x6_t maskedoff_tuple, const int8_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e8_v_i8m1x6_tu(maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 1 x i8>, 6) @test_vlsseg6e8_v_u8mf8x6_tu
// CHECK-RV64-SAME: (target("riscv.vector.tuple", <vscale x 1 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 1 x i8>, 6) @llvm.riscv.vlsseg6.triscv.vector.tuple_nxv1i8_6t.i64(target("riscv.vector.tuple", <vscale x 1 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 1 x i8>, 6) [[TMP0]]
//
vuint8mf8x6_t test_vlsseg6e8_v_u8mf8x6_tu(vuint8mf8x6_t maskedoff_tuple, const uint8_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e8_v_u8mf8x6_tu(maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 6) @test_vlsseg6e8_v_u8mf4x6_tu
// CHECK-RV64-SAME: (target("riscv.vector.tuple", <vscale x 2 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 2 x i8>, 6) @llvm.riscv.vlsseg6.triscv.vector.tuple_nxv2i8_6t.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 6) [[TMP0]]
//
vuint8mf4x6_t test_vlsseg6e8_v_u8mf4x6_tu(vuint8mf4x6_t maskedoff_tuple, const uint8_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e8_v_u8mf4x6_tu(maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 6) @test_vlsseg6e8_v_u8mf2x6_tu
// CHECK-RV64-SAME: (target("riscv.vector.tuple", <vscale x 4 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 6) @llvm.riscv.vlsseg6.triscv.vector.tuple_nxv4i8_6t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 6) [[TMP0]]
//
vuint8mf2x6_t test_vlsseg6e8_v_u8mf2x6_tu(vuint8mf2x6_t maskedoff_tuple, const uint8_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e8_v_u8mf2x6_tu(maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @test_vlsseg6e8_v_u8m1x6_tu
// CHECK-RV64-SAME: (target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @llvm.riscv.vlsseg6.triscv.vector.tuple_nxv8i8_6t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[TMP0]]
//
vuint8m1x6_t test_vlsseg6e8_v_u8m1x6_tu(vuint8m1x6_t maskedoff_tuple, const uint8_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e8_v_u8m1x6_tu(maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 1 x i8>, 6) @test_vlsseg6e8_v_i8mf8x6_tum
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 1 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 1 x i8>, 6) @llvm.riscv.vlsseg6.mask.triscv.vector.tuple_nxv1i8_6t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 1 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 2, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 1 x i8>, 6) [[TMP0]]
//
vint8mf8x6_t test_vlsseg6e8_v_i8mf8x6_tum(vbool64_t mask, vint8mf8x6_t maskedoff_tuple, const int8_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e8_v_i8mf8x6_tum(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 6) @test_vlsseg6e8_v_i8mf4x6_tum
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 2 x i8>, 6) @llvm.riscv.vlsseg6.mask.triscv.vector.tuple_nxv2i8_6t.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 2 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 2, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 6) [[TMP0]]
//
vint8mf4x6_t test_vlsseg6e8_v_i8mf4x6_tum(vbool32_t mask, vint8mf4x6_t maskedoff_tuple, const int8_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e8_v_i8mf4x6_tum(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 6) @test_vlsseg6e8_v_i8mf2x6_tum
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 6) @llvm.riscv.vlsseg6.mask.triscv.vector.tuple_nxv4i8_6t.i64.nxv4i1(target("riscv.vector.tuple", <vscale x 4 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 2, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 6) [[TMP0]]
//
vint8mf2x6_t test_vlsseg6e8_v_i8mf2x6_tum(vbool16_t mask, vint8mf2x6_t maskedoff_tuple, const int8_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e8_v_i8mf2x6_tum(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @test_vlsseg6e8_v_i8m1x6_tum
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @llvm.riscv.vlsseg6.mask.triscv.vector.tuple_nxv8i8_6t.i64.nxv8i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 2, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[TMP0]]
//
vint8m1x6_t test_vlsseg6e8_v_i8m1x6_tum(vbool8_t mask, vint8m1x6_t maskedoff_tuple, const int8_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e8_v_i8m1x6_tum(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 1 x i8>, 6) @test_vlsseg6e8_v_u8mf8x6_tum
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 1 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 1 x i8>, 6) @llvm.riscv.vlsseg6.mask.triscv.vector.tuple_nxv1i8_6t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 1 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 2, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 1 x i8>, 6) [[TMP0]]
//
vuint8mf8x6_t test_vlsseg6e8_v_u8mf8x6_tum(vbool64_t mask, vuint8mf8x6_t maskedoff_tuple, const uint8_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e8_v_u8mf8x6_tum(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 6) @test_vlsseg6e8_v_u8mf4x6_tum
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 2 x i8>, 6) @llvm.riscv.vlsseg6.mask.triscv.vector.tuple_nxv2i8_6t.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 2 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 2, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 6) [[TMP0]]
//
vuint8mf4x6_t test_vlsseg6e8_v_u8mf4x6_tum(vbool32_t mask, vuint8mf4x6_t maskedoff_tuple, const uint8_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e8_v_u8mf4x6_tum(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 6) @test_vlsseg6e8_v_u8mf2x6_tum
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 6) @llvm.riscv.vlsseg6.mask.triscv.vector.tuple_nxv4i8_6t.i64.nxv4i1(target("riscv.vector.tuple", <vscale x 4 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 2, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 6) [[TMP0]]
//
vuint8mf2x6_t test_vlsseg6e8_v_u8mf2x6_tum(vbool16_t mask, vuint8mf2x6_t maskedoff_tuple, const uint8_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e8_v_u8mf2x6_tum(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @test_vlsseg6e8_v_u8m1x6_tum
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @llvm.riscv.vlsseg6.mask.triscv.vector.tuple_nxv8i8_6t.i64.nxv8i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 2, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[TMP0]]
//
vuint8m1x6_t test_vlsseg6e8_v_u8m1x6_tum(vbool8_t mask, vuint8m1x6_t maskedoff_tuple, const uint8_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e8_v_u8m1x6_tum(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 1 x i8>, 6) @test_vlsseg6e8_v_i8mf8x6_tumu
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 1 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 1 x i8>, 6) @llvm.riscv.vlsseg6.mask.triscv.vector.tuple_nxv1i8_6t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 1 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 0, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 1 x i8>, 6) [[TMP0]]
//
vint8mf8x6_t test_vlsseg6e8_v_i8mf8x6_tumu(vbool64_t mask, vint8mf8x6_t maskedoff_tuple, const int8_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e8_v_i8mf8x6_tumu(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 6) @test_vlsseg6e8_v_i8mf4x6_tumu
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 2 x i8>, 6) @llvm.riscv.vlsseg6.mask.triscv.vector.tuple_nxv2i8_6t.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 2 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 0, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 6) [[TMP0]]
//
vint8mf4x6_t test_vlsseg6e8_v_i8mf4x6_tumu(vbool32_t mask, vint8mf4x6_t maskedoff_tuple, const int8_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e8_v_i8mf4x6_tumu(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 6) @test_vlsseg6e8_v_i8mf2x6_tumu
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 6) @llvm.riscv.vlsseg6.mask.triscv.vector.tuple_nxv4i8_6t.i64.nxv4i1(target("riscv.vector.tuple", <vscale x 4 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 0, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 6) [[TMP0]]
//
vint8mf2x6_t test_vlsseg6e8_v_i8mf2x6_tumu(vbool16_t mask, vint8mf2x6_t maskedoff_tuple, const int8_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e8_v_i8mf2x6_tumu(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @test_vlsseg6e8_v_i8m1x6_tumu
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @llvm.riscv.vlsseg6.mask.triscv.vector.tuple_nxv8i8_6t.i64.nxv8i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 0, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[TMP0]]
//
vint8m1x6_t test_vlsseg6e8_v_i8m1x6_tumu(vbool8_t mask, vint8m1x6_t maskedoff_tuple, const int8_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e8_v_i8m1x6_tumu(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 1 x i8>, 6) @test_vlsseg6e8_v_u8mf8x6_tumu
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 1 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 1 x i8>, 6) @llvm.riscv.vlsseg6.mask.triscv.vector.tuple_nxv1i8_6t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 1 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 0, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 1 x i8>, 6) [[TMP0]]
//
vuint8mf8x6_t test_vlsseg6e8_v_u8mf8x6_tumu(vbool64_t mask, vuint8mf8x6_t maskedoff_tuple, const uint8_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e8_v_u8mf8x6_tumu(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 6) @test_vlsseg6e8_v_u8mf4x6_tumu
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 2 x i8>, 6) @llvm.riscv.vlsseg6.mask.triscv.vector.tuple_nxv2i8_6t.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 2 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 0, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 6) [[TMP0]]
//
vuint8mf4x6_t test_vlsseg6e8_v_u8mf4x6_tumu(vbool32_t mask, vuint8mf4x6_t maskedoff_tuple, const uint8_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e8_v_u8mf4x6_tumu(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 6) @test_vlsseg6e8_v_u8mf2x6_tumu
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 6) @llvm.riscv.vlsseg6.mask.triscv.vector.tuple_nxv4i8_6t.i64.nxv4i1(target("riscv.vector.tuple", <vscale x 4 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 0, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 6) [[TMP0]]
//
vuint8mf2x6_t test_vlsseg6e8_v_u8mf2x6_tumu(vbool16_t mask, vuint8mf2x6_t maskedoff_tuple, const uint8_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e8_v_u8mf2x6_tumu(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @test_vlsseg6e8_v_u8m1x6_tumu
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @llvm.riscv.vlsseg6.mask.triscv.vector.tuple_nxv8i8_6t.i64.nxv8i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 0, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[TMP0]]
//
vuint8m1x6_t test_vlsseg6e8_v_u8m1x6_tumu(vbool8_t mask, vuint8m1x6_t maskedoff_tuple, const uint8_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e8_v_u8m1x6_tumu(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 1 x i8>, 6) @test_vlsseg6e8_v_i8mf8x6_mu
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 1 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 1 x i8>, 6) @llvm.riscv.vlsseg6.mask.triscv.vector.tuple_nxv1i8_6t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 1 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 1, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 1 x i8>, 6) [[TMP0]]
//
vint8mf8x6_t test_vlsseg6e8_v_i8mf8x6_mu(vbool64_t mask, vint8mf8x6_t maskedoff_tuple, const int8_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e8_v_i8mf8x6_mu(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 6) @test_vlsseg6e8_v_i8mf4x6_mu
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 2 x i8>, 6) @llvm.riscv.vlsseg6.mask.triscv.vector.tuple_nxv2i8_6t.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 2 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 1, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 6) [[TMP0]]
//
vint8mf4x6_t test_vlsseg6e8_v_i8mf4x6_mu(vbool32_t mask, vint8mf4x6_t maskedoff_tuple, const int8_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e8_v_i8mf4x6_mu(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 6) @test_vlsseg6e8_v_i8mf2x6_mu
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 6) @llvm.riscv.vlsseg6.mask.triscv.vector.tuple_nxv4i8_6t.i64.nxv4i1(target("riscv.vector.tuple", <vscale x 4 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 1, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 6) [[TMP0]]
//
vint8mf2x6_t test_vlsseg6e8_v_i8mf2x6_mu(vbool16_t mask, vint8mf2x6_t maskedoff_tuple, const int8_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e8_v_i8mf2x6_mu(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @test_vlsseg6e8_v_i8m1x6_mu
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @llvm.riscv.vlsseg6.mask.triscv.vector.tuple_nxv8i8_6t.i64.nxv8i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 1, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[TMP0]]
//
vint8m1x6_t test_vlsseg6e8_v_i8m1x6_mu(vbool8_t mask, vint8m1x6_t maskedoff_tuple, const int8_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e8_v_i8m1x6_mu(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 1 x i8>, 6) @test_vlsseg6e8_v_u8mf8x6_mu
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 1 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 1 x i8>, 6) @llvm.riscv.vlsseg6.mask.triscv.vector.tuple_nxv1i8_6t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 1 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 1, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 1 x i8>, 6) [[TMP0]]
//
vuint8mf8x6_t test_vlsseg6e8_v_u8mf8x6_mu(vbool64_t mask, vuint8mf8x6_t maskedoff_tuple, const uint8_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e8_v_u8mf8x6_mu(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 6) @test_vlsseg6e8_v_u8mf4x6_mu
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 2 x i8>, 6) @llvm.riscv.vlsseg6.mask.triscv.vector.tuple_nxv2i8_6t.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 2 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 1, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 6) [[TMP0]]
//
vuint8mf4x6_t test_vlsseg6e8_v_u8mf4x6_mu(vbool32_t mask, vuint8mf4x6_t maskedoff_tuple, const uint8_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e8_v_u8mf4x6_mu(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 6) @test_vlsseg6e8_v_u8mf2x6_mu
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 6) @llvm.riscv.vlsseg6.mask.triscv.vector.tuple_nxv4i8_6t.i64.nxv4i1(target("riscv.vector.tuple", <vscale x 4 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 1, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 6) [[TMP0]]
//
vuint8mf2x6_t test_vlsseg6e8_v_u8mf2x6_mu(vbool16_t mask, vuint8mf2x6_t maskedoff_tuple, const uint8_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e8_v_u8mf2x6_mu(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @test_vlsseg6e8_v_u8m1x6_mu
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @llvm.riscv.vlsseg6.mask.triscv.vector.tuple_nxv8i8_6t.i64.nxv8i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 1, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[TMP0]]
//
vuint8m1x6_t test_vlsseg6e8_v_u8m1x6_mu(vbool8_t mask, vuint8m1x6_t maskedoff_tuple, const uint8_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg6e8_v_u8m1x6_mu(mask, maskedoff_tuple, base, bstride, vl);
}

