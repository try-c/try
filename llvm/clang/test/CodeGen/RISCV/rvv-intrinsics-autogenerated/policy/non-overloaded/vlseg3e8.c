// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 2
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +zvfh -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 1 x i8>, 3) @test_vlseg3e8_v_i8mf8x3_tu
// CHECK-RV64-SAME: (target("riscv.vector.tuple", <vscale x 1 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 1 x i8>, 3) @llvm.riscv.vlseg3.triscv.vector.tuple_nxv1i8_3t.i64(target("riscv.vector.tuple", <vscale x 1 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 1 x i8>, 3) [[TMP0]]
//
vint8mf8x3_t test_vlseg3e8_v_i8mf8x3_tu(vint8mf8x3_t maskedoff_tuple, const int8_t *base, size_t vl) {
  return __riscv_vlseg3e8_v_i8mf8x3_tu(maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 3) @test_vlseg3e8_v_i8mf4x3_tu
// CHECK-RV64-SAME: (target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 2 x i8>, 3) @llvm.riscv.vlseg3.triscv.vector.tuple_nxv2i8_3t.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[TMP0]]
//
vint8mf4x3_t test_vlseg3e8_v_i8mf4x3_tu(vint8mf4x3_t maskedoff_tuple, const int8_t *base, size_t vl) {
  return __riscv_vlseg3e8_v_i8mf4x3_tu(maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @test_vlseg3e8_v_i8mf2x3_tu
// CHECK-RV64-SAME: (target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @llvm.riscv.vlseg3.triscv.vector.tuple_nxv4i8_3t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[TMP0]]
//
vint8mf2x3_t test_vlseg3e8_v_i8mf2x3_tu(vint8mf2x3_t maskedoff_tuple, const int8_t *base, size_t vl) {
  return __riscv_vlseg3e8_v_i8mf2x3_tu(maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @test_vlseg3e8_v_i8m1x3_tu
// CHECK-RV64-SAME: (target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @llvm.riscv.vlseg3.triscv.vector.tuple_nxv8i8_3t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[TMP0]]
//
vint8m1x3_t test_vlseg3e8_v_i8m1x3_tu(vint8m1x3_t maskedoff_tuple, const int8_t *base, size_t vl) {
  return __riscv_vlseg3e8_v_i8m1x3_tu(maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @test_vlseg3e8_v_i8m2x3_tu
// CHECK-RV64-SAME: (target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @llvm.riscv.vlseg3.triscv.vector.tuple_nxv16i8_3t.i64(target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[TMP0]]
//
vint8m2x3_t test_vlseg3e8_v_i8m2x3_tu(vint8m2x3_t maskedoff_tuple, const int8_t *base, size_t vl) {
  return __riscv_vlseg3e8_v_i8m2x3_tu(maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 1 x i8>, 3) @test_vlseg3e8_v_u8mf8x3_tu
// CHECK-RV64-SAME: (target("riscv.vector.tuple", <vscale x 1 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 1 x i8>, 3) @llvm.riscv.vlseg3.triscv.vector.tuple_nxv1i8_3t.i64(target("riscv.vector.tuple", <vscale x 1 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 1 x i8>, 3) [[TMP0]]
//
vuint8mf8x3_t test_vlseg3e8_v_u8mf8x3_tu(vuint8mf8x3_t maskedoff_tuple, const uint8_t *base, size_t vl) {
  return __riscv_vlseg3e8_v_u8mf8x3_tu(maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 3) @test_vlseg3e8_v_u8mf4x3_tu
// CHECK-RV64-SAME: (target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 2 x i8>, 3) @llvm.riscv.vlseg3.triscv.vector.tuple_nxv2i8_3t.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[TMP0]]
//
vuint8mf4x3_t test_vlseg3e8_v_u8mf4x3_tu(vuint8mf4x3_t maskedoff_tuple, const uint8_t *base, size_t vl) {
  return __riscv_vlseg3e8_v_u8mf4x3_tu(maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @test_vlseg3e8_v_u8mf2x3_tu
// CHECK-RV64-SAME: (target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @llvm.riscv.vlseg3.triscv.vector.tuple_nxv4i8_3t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[TMP0]]
//
vuint8mf2x3_t test_vlseg3e8_v_u8mf2x3_tu(vuint8mf2x3_t maskedoff_tuple, const uint8_t *base, size_t vl) {
  return __riscv_vlseg3e8_v_u8mf2x3_tu(maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @test_vlseg3e8_v_u8m1x3_tu
// CHECK-RV64-SAME: (target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @llvm.riscv.vlseg3.triscv.vector.tuple_nxv8i8_3t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[TMP0]]
//
vuint8m1x3_t test_vlseg3e8_v_u8m1x3_tu(vuint8m1x3_t maskedoff_tuple, const uint8_t *base, size_t vl) {
  return __riscv_vlseg3e8_v_u8m1x3_tu(maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @test_vlseg3e8_v_u8m2x3_tu
// CHECK-RV64-SAME: (target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @llvm.riscv.vlseg3.triscv.vector.tuple_nxv16i8_3t.i64(target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[TMP0]]
//
vuint8m2x3_t test_vlseg3e8_v_u8m2x3_tu(vuint8m2x3_t maskedoff_tuple, const uint8_t *base, size_t vl) {
  return __riscv_vlseg3e8_v_u8m2x3_tu(maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 1 x i8>, 3) @test_vlseg3e8_v_i8mf8x3_tum
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 1 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 1 x i8>, 3) @llvm.riscv.vlseg3.mask.triscv.vector.tuple_nxv1i8_3t.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 1 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 2, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 1 x i8>, 3) [[TMP0]]
//
vint8mf8x3_t test_vlseg3e8_v_i8mf8x3_tum(vbool64_t mask, vint8mf8x3_t maskedoff_tuple, const int8_t *base, size_t vl) {
  return __riscv_vlseg3e8_v_i8mf8x3_tum(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 3) @test_vlseg3e8_v_i8mf4x3_tum
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 2 x i8>, 3) @llvm.riscv.vlseg3.mask.triscv.vector.tuple_nxv2i8_3t.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 2, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[TMP0]]
//
vint8mf4x3_t test_vlseg3e8_v_i8mf4x3_tum(vbool32_t mask, vint8mf4x3_t maskedoff_tuple, const int8_t *base, size_t vl) {
  return __riscv_vlseg3e8_v_i8mf4x3_tum(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @test_vlseg3e8_v_i8mf2x3_tum
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @llvm.riscv.vlseg3.mask.triscv.vector.tuple_nxv4i8_3t.nxv4i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 2, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[TMP0]]
//
vint8mf2x3_t test_vlseg3e8_v_i8mf2x3_tum(vbool16_t mask, vint8mf2x3_t maskedoff_tuple, const int8_t *base, size_t vl) {
  return __riscv_vlseg3e8_v_i8mf2x3_tum(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @test_vlseg3e8_v_i8m1x3_tum
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @llvm.riscv.vlseg3.mask.triscv.vector.tuple_nxv8i8_3t.nxv8i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 2, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[TMP0]]
//
vint8m1x3_t test_vlseg3e8_v_i8m1x3_tum(vbool8_t mask, vint8m1x3_t maskedoff_tuple, const int8_t *base, size_t vl) {
  return __riscv_vlseg3e8_v_i8m1x3_tum(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @test_vlseg3e8_v_i8m2x3_tum
// CHECK-RV64-SAME: (<vscale x 16 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @llvm.riscv.vlseg3.mask.triscv.vector.tuple_nxv16i8_3t.nxv16i1.i64(target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 16 x i1> [[MASK]], i64 [[VL]], i64 2, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[TMP0]]
//
vint8m2x3_t test_vlseg3e8_v_i8m2x3_tum(vbool4_t mask, vint8m2x3_t maskedoff_tuple, const int8_t *base, size_t vl) {
  return __riscv_vlseg3e8_v_i8m2x3_tum(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 1 x i8>, 3) @test_vlseg3e8_v_u8mf8x3_tum
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 1 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 1 x i8>, 3) @llvm.riscv.vlseg3.mask.triscv.vector.tuple_nxv1i8_3t.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 1 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 2, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 1 x i8>, 3) [[TMP0]]
//
vuint8mf8x3_t test_vlseg3e8_v_u8mf8x3_tum(vbool64_t mask, vuint8mf8x3_t maskedoff_tuple, const uint8_t *base, size_t vl) {
  return __riscv_vlseg3e8_v_u8mf8x3_tum(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 3) @test_vlseg3e8_v_u8mf4x3_tum
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 2 x i8>, 3) @llvm.riscv.vlseg3.mask.triscv.vector.tuple_nxv2i8_3t.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 2, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[TMP0]]
//
vuint8mf4x3_t test_vlseg3e8_v_u8mf4x3_tum(vbool32_t mask, vuint8mf4x3_t maskedoff_tuple, const uint8_t *base, size_t vl) {
  return __riscv_vlseg3e8_v_u8mf4x3_tum(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @test_vlseg3e8_v_u8mf2x3_tum
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @llvm.riscv.vlseg3.mask.triscv.vector.tuple_nxv4i8_3t.nxv4i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 2, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[TMP0]]
//
vuint8mf2x3_t test_vlseg3e8_v_u8mf2x3_tum(vbool16_t mask, vuint8mf2x3_t maskedoff_tuple, const uint8_t *base, size_t vl) {
  return __riscv_vlseg3e8_v_u8mf2x3_tum(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @test_vlseg3e8_v_u8m1x3_tum
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @llvm.riscv.vlseg3.mask.triscv.vector.tuple_nxv8i8_3t.nxv8i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 2, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[TMP0]]
//
vuint8m1x3_t test_vlseg3e8_v_u8m1x3_tum(vbool8_t mask, vuint8m1x3_t maskedoff_tuple, const uint8_t *base, size_t vl) {
  return __riscv_vlseg3e8_v_u8m1x3_tum(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @test_vlseg3e8_v_u8m2x3_tum
// CHECK-RV64-SAME: (<vscale x 16 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @llvm.riscv.vlseg3.mask.triscv.vector.tuple_nxv16i8_3t.nxv16i1.i64(target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 16 x i1> [[MASK]], i64 [[VL]], i64 2, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[TMP0]]
//
vuint8m2x3_t test_vlseg3e8_v_u8m2x3_tum(vbool4_t mask, vuint8m2x3_t maskedoff_tuple, const uint8_t *base, size_t vl) {
  return __riscv_vlseg3e8_v_u8m2x3_tum(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 1 x i8>, 3) @test_vlseg3e8_v_i8mf8x3_tumu
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 1 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 1 x i8>, 3) @llvm.riscv.vlseg3.mask.triscv.vector.tuple_nxv1i8_3t.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 1 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 0, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 1 x i8>, 3) [[TMP0]]
//
vint8mf8x3_t test_vlseg3e8_v_i8mf8x3_tumu(vbool64_t mask, vint8mf8x3_t maskedoff_tuple, const int8_t *base, size_t vl) {
  return __riscv_vlseg3e8_v_i8mf8x3_tumu(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 3) @test_vlseg3e8_v_i8mf4x3_tumu
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 2 x i8>, 3) @llvm.riscv.vlseg3.mask.triscv.vector.tuple_nxv2i8_3t.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 0, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[TMP0]]
//
vint8mf4x3_t test_vlseg3e8_v_i8mf4x3_tumu(vbool32_t mask, vint8mf4x3_t maskedoff_tuple, const int8_t *base, size_t vl) {
  return __riscv_vlseg3e8_v_i8mf4x3_tumu(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @test_vlseg3e8_v_i8mf2x3_tumu
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @llvm.riscv.vlseg3.mask.triscv.vector.tuple_nxv4i8_3t.nxv4i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 0, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[TMP0]]
//
vint8mf2x3_t test_vlseg3e8_v_i8mf2x3_tumu(vbool16_t mask, vint8mf2x3_t maskedoff_tuple, const int8_t *base, size_t vl) {
  return __riscv_vlseg3e8_v_i8mf2x3_tumu(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @test_vlseg3e8_v_i8m1x3_tumu
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @llvm.riscv.vlseg3.mask.triscv.vector.tuple_nxv8i8_3t.nxv8i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 0, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[TMP0]]
//
vint8m1x3_t test_vlseg3e8_v_i8m1x3_tumu(vbool8_t mask, vint8m1x3_t maskedoff_tuple, const int8_t *base, size_t vl) {
  return __riscv_vlseg3e8_v_i8m1x3_tumu(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @test_vlseg3e8_v_i8m2x3_tumu
// CHECK-RV64-SAME: (<vscale x 16 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @llvm.riscv.vlseg3.mask.triscv.vector.tuple_nxv16i8_3t.nxv16i1.i64(target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 16 x i1> [[MASK]], i64 [[VL]], i64 0, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[TMP0]]
//
vint8m2x3_t test_vlseg3e8_v_i8m2x3_tumu(vbool4_t mask, vint8m2x3_t maskedoff_tuple, const int8_t *base, size_t vl) {
  return __riscv_vlseg3e8_v_i8m2x3_tumu(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 1 x i8>, 3) @test_vlseg3e8_v_u8mf8x3_tumu
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 1 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 1 x i8>, 3) @llvm.riscv.vlseg3.mask.triscv.vector.tuple_nxv1i8_3t.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 1 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 0, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 1 x i8>, 3) [[TMP0]]
//
vuint8mf8x3_t test_vlseg3e8_v_u8mf8x3_tumu(vbool64_t mask, vuint8mf8x3_t maskedoff_tuple, const uint8_t *base, size_t vl) {
  return __riscv_vlseg3e8_v_u8mf8x3_tumu(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 3) @test_vlseg3e8_v_u8mf4x3_tumu
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 2 x i8>, 3) @llvm.riscv.vlseg3.mask.triscv.vector.tuple_nxv2i8_3t.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 0, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[TMP0]]
//
vuint8mf4x3_t test_vlseg3e8_v_u8mf4x3_tumu(vbool32_t mask, vuint8mf4x3_t maskedoff_tuple, const uint8_t *base, size_t vl) {
  return __riscv_vlseg3e8_v_u8mf4x3_tumu(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @test_vlseg3e8_v_u8mf2x3_tumu
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @llvm.riscv.vlseg3.mask.triscv.vector.tuple_nxv4i8_3t.nxv4i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 0, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[TMP0]]
//
vuint8mf2x3_t test_vlseg3e8_v_u8mf2x3_tumu(vbool16_t mask, vuint8mf2x3_t maskedoff_tuple, const uint8_t *base, size_t vl) {
  return __riscv_vlseg3e8_v_u8mf2x3_tumu(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @test_vlseg3e8_v_u8m1x3_tumu
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @llvm.riscv.vlseg3.mask.triscv.vector.tuple_nxv8i8_3t.nxv8i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 0, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[TMP0]]
//
vuint8m1x3_t test_vlseg3e8_v_u8m1x3_tumu(vbool8_t mask, vuint8m1x3_t maskedoff_tuple, const uint8_t *base, size_t vl) {
  return __riscv_vlseg3e8_v_u8m1x3_tumu(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @test_vlseg3e8_v_u8m2x3_tumu
// CHECK-RV64-SAME: (<vscale x 16 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @llvm.riscv.vlseg3.mask.triscv.vector.tuple_nxv16i8_3t.nxv16i1.i64(target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 16 x i1> [[MASK]], i64 [[VL]], i64 0, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[TMP0]]
//
vuint8m2x3_t test_vlseg3e8_v_u8m2x3_tumu(vbool4_t mask, vuint8m2x3_t maskedoff_tuple, const uint8_t *base, size_t vl) {
  return __riscv_vlseg3e8_v_u8m2x3_tumu(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 1 x i8>, 3) @test_vlseg3e8_v_i8mf8x3_mu
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 1 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 1 x i8>, 3) @llvm.riscv.vlseg3.mask.triscv.vector.tuple_nxv1i8_3t.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 1 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 1, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 1 x i8>, 3) [[TMP0]]
//
vint8mf8x3_t test_vlseg3e8_v_i8mf8x3_mu(vbool64_t mask, vint8mf8x3_t maskedoff_tuple, const int8_t *base, size_t vl) {
  return __riscv_vlseg3e8_v_i8mf8x3_mu(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 3) @test_vlseg3e8_v_i8mf4x3_mu
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 2 x i8>, 3) @llvm.riscv.vlseg3.mask.triscv.vector.tuple_nxv2i8_3t.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 1, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[TMP0]]
//
vint8mf4x3_t test_vlseg3e8_v_i8mf4x3_mu(vbool32_t mask, vint8mf4x3_t maskedoff_tuple, const int8_t *base, size_t vl) {
  return __riscv_vlseg3e8_v_i8mf4x3_mu(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @test_vlseg3e8_v_i8mf2x3_mu
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @llvm.riscv.vlseg3.mask.triscv.vector.tuple_nxv4i8_3t.nxv4i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 1, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[TMP0]]
//
vint8mf2x3_t test_vlseg3e8_v_i8mf2x3_mu(vbool16_t mask, vint8mf2x3_t maskedoff_tuple, const int8_t *base, size_t vl) {
  return __riscv_vlseg3e8_v_i8mf2x3_mu(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @test_vlseg3e8_v_i8m1x3_mu
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @llvm.riscv.vlseg3.mask.triscv.vector.tuple_nxv8i8_3t.nxv8i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 1, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[TMP0]]
//
vint8m1x3_t test_vlseg3e8_v_i8m1x3_mu(vbool8_t mask, vint8m1x3_t maskedoff_tuple, const int8_t *base, size_t vl) {
  return __riscv_vlseg3e8_v_i8m1x3_mu(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @test_vlseg3e8_v_i8m2x3_mu
// CHECK-RV64-SAME: (<vscale x 16 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @llvm.riscv.vlseg3.mask.triscv.vector.tuple_nxv16i8_3t.nxv16i1.i64(target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 16 x i1> [[MASK]], i64 [[VL]], i64 1, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[TMP0]]
//
vint8m2x3_t test_vlseg3e8_v_i8m2x3_mu(vbool4_t mask, vint8m2x3_t maskedoff_tuple, const int8_t *base, size_t vl) {
  return __riscv_vlseg3e8_v_i8m2x3_mu(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 1 x i8>, 3) @test_vlseg3e8_v_u8mf8x3_mu
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 1 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 1 x i8>, 3) @llvm.riscv.vlseg3.mask.triscv.vector.tuple_nxv1i8_3t.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 1 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 1, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 1 x i8>, 3) [[TMP0]]
//
vuint8mf8x3_t test_vlseg3e8_v_u8mf8x3_mu(vbool64_t mask, vuint8mf8x3_t maskedoff_tuple, const uint8_t *base, size_t vl) {
  return __riscv_vlseg3e8_v_u8mf8x3_mu(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 3) @test_vlseg3e8_v_u8mf4x3_mu
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 2 x i8>, 3) @llvm.riscv.vlseg3.mask.triscv.vector.tuple_nxv2i8_3t.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 1, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[TMP0]]
//
vuint8mf4x3_t test_vlseg3e8_v_u8mf4x3_mu(vbool32_t mask, vuint8mf4x3_t maskedoff_tuple, const uint8_t *base, size_t vl) {
  return __riscv_vlseg3e8_v_u8mf4x3_mu(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @test_vlseg3e8_v_u8mf2x3_mu
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @llvm.riscv.vlseg3.mask.triscv.vector.tuple_nxv4i8_3t.nxv4i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 1, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[TMP0]]
//
vuint8mf2x3_t test_vlseg3e8_v_u8mf2x3_mu(vbool16_t mask, vuint8mf2x3_t maskedoff_tuple, const uint8_t *base, size_t vl) {
  return __riscv_vlseg3e8_v_u8mf2x3_mu(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @test_vlseg3e8_v_u8m1x3_mu
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @llvm.riscv.vlseg3.mask.triscv.vector.tuple_nxv8i8_3t.nxv8i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 1, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[TMP0]]
//
vuint8m1x3_t test_vlseg3e8_v_u8m1x3_mu(vbool8_t mask, vuint8m1x3_t maskedoff_tuple, const uint8_t *base, size_t vl) {
  return __riscv_vlseg3e8_v_u8m1x3_mu(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @test_vlseg3e8_v_u8m2x3_mu
// CHECK-RV64-SAME: (<vscale x 16 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @llvm.riscv.vlseg3.mask.triscv.vector.tuple_nxv16i8_3t.nxv16i1.i64(target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 16 x i1> [[MASK]], i64 [[VL]], i64 1, i64 3)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[TMP0]]
//
vuint8m2x3_t test_vlseg3e8_v_u8m2x3_mu(vbool4_t mask, vuint8m2x3_t maskedoff_tuple, const uint8_t *base, size_t vl) {
  return __riscv_vlseg3e8_v_u8m2x3_mu(mask, maskedoff_tuple, base, vl);
}

