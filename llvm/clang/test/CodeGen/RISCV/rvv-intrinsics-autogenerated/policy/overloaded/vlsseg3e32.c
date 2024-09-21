// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 2
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +zvfh -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @test_vlsseg3e32_v_f32mf2x3_tu
// CHECK-RV64-SAME: (target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @llvm.riscv.vlsseg3.triscv.vector.tuple_nxv4i8_3t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[TMP0]]
//
vfloat32mf2x3_t test_vlsseg3e32_v_f32mf2x3_tu(vfloat32mf2x3_t maskedoff_tuple, const float *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg3e32_tu(maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @test_vlsseg3e32_v_f32m1x3_tu
// CHECK-RV64-SAME: (target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @llvm.riscv.vlsseg3.triscv.vector.tuple_nxv8i8_3t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[TMP0]]
//
vfloat32m1x3_t test_vlsseg3e32_v_f32m1x3_tu(vfloat32m1x3_t maskedoff_tuple, const float *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg3e32_tu(maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @test_vlsseg3e32_v_f32m2x3_tu
// CHECK-RV64-SAME: (target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @llvm.riscv.vlsseg3.triscv.vector.tuple_nxv16i8_3t.i64(target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[TMP0]]
//
vfloat32m2x3_t test_vlsseg3e32_v_f32m2x3_tu(vfloat32m2x3_t maskedoff_tuple, const float *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg3e32_tu(maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @test_vlsseg3e32_v_i32mf2x3_tu
// CHECK-RV64-SAME: (target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @llvm.riscv.vlsseg3.triscv.vector.tuple_nxv4i8_3t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[TMP0]]
//
vint32mf2x3_t test_vlsseg3e32_v_i32mf2x3_tu(vint32mf2x3_t maskedoff_tuple, const int32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg3e32_tu(maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @test_vlsseg3e32_v_i32m1x3_tu
// CHECK-RV64-SAME: (target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @llvm.riscv.vlsseg3.triscv.vector.tuple_nxv8i8_3t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[TMP0]]
//
vint32m1x3_t test_vlsseg3e32_v_i32m1x3_tu(vint32m1x3_t maskedoff_tuple, const int32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg3e32_tu(maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @test_vlsseg3e32_v_i32m2x3_tu
// CHECK-RV64-SAME: (target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @llvm.riscv.vlsseg3.triscv.vector.tuple_nxv16i8_3t.i64(target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[TMP0]]
//
vint32m2x3_t test_vlsseg3e32_v_i32m2x3_tu(vint32m2x3_t maskedoff_tuple, const int32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg3e32_tu(maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @test_vlsseg3e32_v_u32mf2x3_tu
// CHECK-RV64-SAME: (target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @llvm.riscv.vlsseg3.triscv.vector.tuple_nxv4i8_3t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[TMP0]]
//
vuint32mf2x3_t test_vlsseg3e32_v_u32mf2x3_tu(vuint32mf2x3_t maskedoff_tuple, const uint32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg3e32_tu(maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @test_vlsseg3e32_v_u32m1x3_tu
// CHECK-RV64-SAME: (target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @llvm.riscv.vlsseg3.triscv.vector.tuple_nxv8i8_3t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[TMP0]]
//
vuint32m1x3_t test_vlsseg3e32_v_u32m1x3_tu(vuint32m1x3_t maskedoff_tuple, const uint32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg3e32_tu(maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @test_vlsseg3e32_v_u32m2x3_tu
// CHECK-RV64-SAME: (target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @llvm.riscv.vlsseg3.triscv.vector.tuple_nxv16i8_3t.i64(target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[TMP0]]
//
vuint32m2x3_t test_vlsseg3e32_v_u32m2x3_tu(vuint32m2x3_t maskedoff_tuple, const uint32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg3e32_tu(maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @test_vlsseg3e32_v_f32mf2x3_tum
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @llvm.riscv.vlsseg3.mask.triscv.vector.tuple_nxv4i8_3t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 2, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[TMP0]]
//
vfloat32mf2x3_t test_vlsseg3e32_v_f32mf2x3_tum(vbool64_t mask, vfloat32mf2x3_t maskedoff_tuple, const float *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg3e32_tum(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @test_vlsseg3e32_v_f32m1x3_tum
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @llvm.riscv.vlsseg3.mask.triscv.vector.tuple_nxv8i8_3t.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 2, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[TMP0]]
//
vfloat32m1x3_t test_vlsseg3e32_v_f32m1x3_tum(vbool32_t mask, vfloat32m1x3_t maskedoff_tuple, const float *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg3e32_tum(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @test_vlsseg3e32_v_f32m2x3_tum
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @llvm.riscv.vlsseg3.mask.triscv.vector.tuple_nxv16i8_3t.i64.nxv4i1(target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 2, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[TMP0]]
//
vfloat32m2x3_t test_vlsseg3e32_v_f32m2x3_tum(vbool16_t mask, vfloat32m2x3_t maskedoff_tuple, const float *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg3e32_tum(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @test_vlsseg3e32_v_i32mf2x3_tum
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @llvm.riscv.vlsseg3.mask.triscv.vector.tuple_nxv4i8_3t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 2, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[TMP0]]
//
vint32mf2x3_t test_vlsseg3e32_v_i32mf2x3_tum(vbool64_t mask, vint32mf2x3_t maskedoff_tuple, const int32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg3e32_tum(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @test_vlsseg3e32_v_i32m1x3_tum
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @llvm.riscv.vlsseg3.mask.triscv.vector.tuple_nxv8i8_3t.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 2, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[TMP0]]
//
vint32m1x3_t test_vlsseg3e32_v_i32m1x3_tum(vbool32_t mask, vint32m1x3_t maskedoff_tuple, const int32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg3e32_tum(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @test_vlsseg3e32_v_i32m2x3_tum
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @llvm.riscv.vlsseg3.mask.triscv.vector.tuple_nxv16i8_3t.i64.nxv4i1(target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 2, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[TMP0]]
//
vint32m2x3_t test_vlsseg3e32_v_i32m2x3_tum(vbool16_t mask, vint32m2x3_t maskedoff_tuple, const int32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg3e32_tum(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @test_vlsseg3e32_v_u32mf2x3_tum
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @llvm.riscv.vlsseg3.mask.triscv.vector.tuple_nxv4i8_3t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 2, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[TMP0]]
//
vuint32mf2x3_t test_vlsseg3e32_v_u32mf2x3_tum(vbool64_t mask, vuint32mf2x3_t maskedoff_tuple, const uint32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg3e32_tum(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @test_vlsseg3e32_v_u32m1x3_tum
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @llvm.riscv.vlsseg3.mask.triscv.vector.tuple_nxv8i8_3t.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 2, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[TMP0]]
//
vuint32m1x3_t test_vlsseg3e32_v_u32m1x3_tum(vbool32_t mask, vuint32m1x3_t maskedoff_tuple, const uint32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg3e32_tum(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @test_vlsseg3e32_v_u32m2x3_tum
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @llvm.riscv.vlsseg3.mask.triscv.vector.tuple_nxv16i8_3t.i64.nxv4i1(target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 2, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[TMP0]]
//
vuint32m2x3_t test_vlsseg3e32_v_u32m2x3_tum(vbool16_t mask, vuint32m2x3_t maskedoff_tuple, const uint32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg3e32_tum(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @test_vlsseg3e32_v_f32mf2x3_tumu
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @llvm.riscv.vlsseg3.mask.triscv.vector.tuple_nxv4i8_3t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 0, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[TMP0]]
//
vfloat32mf2x3_t test_vlsseg3e32_v_f32mf2x3_tumu(vbool64_t mask, vfloat32mf2x3_t maskedoff_tuple, const float *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg3e32_tumu(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @test_vlsseg3e32_v_f32m1x3_tumu
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @llvm.riscv.vlsseg3.mask.triscv.vector.tuple_nxv8i8_3t.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 0, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[TMP0]]
//
vfloat32m1x3_t test_vlsseg3e32_v_f32m1x3_tumu(vbool32_t mask, vfloat32m1x3_t maskedoff_tuple, const float *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg3e32_tumu(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @test_vlsseg3e32_v_f32m2x3_tumu
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @llvm.riscv.vlsseg3.mask.triscv.vector.tuple_nxv16i8_3t.i64.nxv4i1(target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 0, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[TMP0]]
//
vfloat32m2x3_t test_vlsseg3e32_v_f32m2x3_tumu(vbool16_t mask, vfloat32m2x3_t maskedoff_tuple, const float *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg3e32_tumu(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @test_vlsseg3e32_v_i32mf2x3_tumu
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @llvm.riscv.vlsseg3.mask.triscv.vector.tuple_nxv4i8_3t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 0, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[TMP0]]
//
vint32mf2x3_t test_vlsseg3e32_v_i32mf2x3_tumu(vbool64_t mask, vint32mf2x3_t maskedoff_tuple, const int32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg3e32_tumu(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @test_vlsseg3e32_v_i32m1x3_tumu
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @llvm.riscv.vlsseg3.mask.triscv.vector.tuple_nxv8i8_3t.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 0, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[TMP0]]
//
vint32m1x3_t test_vlsseg3e32_v_i32m1x3_tumu(vbool32_t mask, vint32m1x3_t maskedoff_tuple, const int32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg3e32_tumu(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @test_vlsseg3e32_v_i32m2x3_tumu
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @llvm.riscv.vlsseg3.mask.triscv.vector.tuple_nxv16i8_3t.i64.nxv4i1(target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 0, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[TMP0]]
//
vint32m2x3_t test_vlsseg3e32_v_i32m2x3_tumu(vbool16_t mask, vint32m2x3_t maskedoff_tuple, const int32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg3e32_tumu(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @test_vlsseg3e32_v_u32mf2x3_tumu
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @llvm.riscv.vlsseg3.mask.triscv.vector.tuple_nxv4i8_3t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 0, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[TMP0]]
//
vuint32mf2x3_t test_vlsseg3e32_v_u32mf2x3_tumu(vbool64_t mask, vuint32mf2x3_t maskedoff_tuple, const uint32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg3e32_tumu(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @test_vlsseg3e32_v_u32m1x3_tumu
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @llvm.riscv.vlsseg3.mask.triscv.vector.tuple_nxv8i8_3t.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 0, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[TMP0]]
//
vuint32m1x3_t test_vlsseg3e32_v_u32m1x3_tumu(vbool32_t mask, vuint32m1x3_t maskedoff_tuple, const uint32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg3e32_tumu(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @test_vlsseg3e32_v_u32m2x3_tumu
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @llvm.riscv.vlsseg3.mask.triscv.vector.tuple_nxv16i8_3t.i64.nxv4i1(target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 0, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[TMP0]]
//
vuint32m2x3_t test_vlsseg3e32_v_u32m2x3_tumu(vbool16_t mask, vuint32m2x3_t maskedoff_tuple, const uint32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg3e32_tumu(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @test_vlsseg3e32_v_f32mf2x3_mu
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @llvm.riscv.vlsseg3.mask.triscv.vector.tuple_nxv4i8_3t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 1, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[TMP0]]
//
vfloat32mf2x3_t test_vlsseg3e32_v_f32mf2x3_mu(vbool64_t mask, vfloat32mf2x3_t maskedoff_tuple, const float *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg3e32_mu(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @test_vlsseg3e32_v_f32m1x3_mu
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @llvm.riscv.vlsseg3.mask.triscv.vector.tuple_nxv8i8_3t.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 1, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[TMP0]]
//
vfloat32m1x3_t test_vlsseg3e32_v_f32m1x3_mu(vbool32_t mask, vfloat32m1x3_t maskedoff_tuple, const float *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg3e32_mu(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @test_vlsseg3e32_v_f32m2x3_mu
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @llvm.riscv.vlsseg3.mask.triscv.vector.tuple_nxv16i8_3t.i64.nxv4i1(target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 1, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[TMP0]]
//
vfloat32m2x3_t test_vlsseg3e32_v_f32m2x3_mu(vbool16_t mask, vfloat32m2x3_t maskedoff_tuple, const float *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg3e32_mu(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @test_vlsseg3e32_v_i32mf2x3_mu
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @llvm.riscv.vlsseg3.mask.triscv.vector.tuple_nxv4i8_3t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 1, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[TMP0]]
//
vint32mf2x3_t test_vlsseg3e32_v_i32mf2x3_mu(vbool64_t mask, vint32mf2x3_t maskedoff_tuple, const int32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg3e32_mu(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @test_vlsseg3e32_v_i32m1x3_mu
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @llvm.riscv.vlsseg3.mask.triscv.vector.tuple_nxv8i8_3t.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 1, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[TMP0]]
//
vint32m1x3_t test_vlsseg3e32_v_i32m1x3_mu(vbool32_t mask, vint32m1x3_t maskedoff_tuple, const int32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg3e32_mu(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @test_vlsseg3e32_v_i32m2x3_mu
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @llvm.riscv.vlsseg3.mask.triscv.vector.tuple_nxv16i8_3t.i64.nxv4i1(target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 1, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[TMP0]]
//
vint32m2x3_t test_vlsseg3e32_v_i32m2x3_mu(vbool16_t mask, vint32m2x3_t maskedoff_tuple, const int32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg3e32_mu(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @test_vlsseg3e32_v_u32mf2x3_mu
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 3) @llvm.riscv.vlsseg3.mask.triscv.vector.tuple_nxv4i8_3t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 1, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[TMP0]]
//
vuint32mf2x3_t test_vlsseg3e32_v_u32mf2x3_mu(vbool64_t mask, vuint32mf2x3_t maskedoff_tuple, const uint32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg3e32_mu(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @test_vlsseg3e32_v_u32m1x3_mu
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 3) @llvm.riscv.vlsseg3.mask.triscv.vector.tuple_nxv8i8_3t.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 1, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[TMP0]]
//
vuint32m1x3_t test_vlsseg3e32_v_u32m1x3_mu(vbool32_t mask, vuint32m1x3_t maskedoff_tuple, const uint32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg3e32_mu(mask, maskedoff_tuple, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @test_vlsseg3e32_v_u32m2x3_mu
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 16 x i8>, 3) @llvm.riscv.vlsseg3.mask.triscv.vector.tuple_nxv16i8_3t.i64.nxv4i1(target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 1, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[TMP0]]
//
vuint32m2x3_t test_vlsseg3e32_v_u32m2x3_mu(vbool16_t mask, vuint32m2x3_t maskedoff_tuple, const uint32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg3e32_mu(mask, maskedoff_tuple, base, bstride, vl);
}

