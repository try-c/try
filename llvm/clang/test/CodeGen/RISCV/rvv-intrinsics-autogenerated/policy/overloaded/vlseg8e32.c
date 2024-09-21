// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 2
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +zvfh -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 8) @test_vlseg8e32_v_f32mf2x8_tu
// CHECK-RV64-SAME: (target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 8) @llvm.riscv.vlseg8.triscv.vector.tuple_nxv4i8_8t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[TMP0]]
//
vfloat32mf2x8_t test_vlseg8e32_v_f32mf2x8_tu(vfloat32mf2x8_t maskedoff_tuple, const float *base, size_t vl) {
  return __riscv_vlseg8e32_tu(maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 8) @test_vlseg8e32_v_f32m1x8_tu
// CHECK-RV64-SAME: (target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 8) @llvm.riscv.vlseg8.triscv.vector.tuple_nxv8i8_8t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[TMP0]]
//
vfloat32m1x8_t test_vlseg8e32_v_f32m1x8_tu(vfloat32m1x8_t maskedoff_tuple, const float *base, size_t vl) {
  return __riscv_vlseg8e32_tu(maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 8) @test_vlseg8e32_v_i32mf2x8_tu
// CHECK-RV64-SAME: (target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 8) @llvm.riscv.vlseg8.triscv.vector.tuple_nxv4i8_8t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[TMP0]]
//
vint32mf2x8_t test_vlseg8e32_v_i32mf2x8_tu(vint32mf2x8_t maskedoff_tuple, const int32_t *base, size_t vl) {
  return __riscv_vlseg8e32_tu(maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 8) @test_vlseg8e32_v_i32m1x8_tu
// CHECK-RV64-SAME: (target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 8) @llvm.riscv.vlseg8.triscv.vector.tuple_nxv8i8_8t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[TMP0]]
//
vint32m1x8_t test_vlseg8e32_v_i32m1x8_tu(vint32m1x8_t maskedoff_tuple, const int32_t *base, size_t vl) {
  return __riscv_vlseg8e32_tu(maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 8) @test_vlseg8e32_v_u32mf2x8_tu
// CHECK-RV64-SAME: (target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 8) @llvm.riscv.vlseg8.triscv.vector.tuple_nxv4i8_8t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[TMP0]]
//
vuint32mf2x8_t test_vlseg8e32_v_u32mf2x8_tu(vuint32mf2x8_t maskedoff_tuple, const uint32_t *base, size_t vl) {
  return __riscv_vlseg8e32_tu(maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 8) @test_vlseg8e32_v_u32m1x8_tu
// CHECK-RV64-SAME: (target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 8) @llvm.riscv.vlseg8.triscv.vector.tuple_nxv8i8_8t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[MASKEDOFF_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[TMP0]]
//
vuint32m1x8_t test_vlseg8e32_v_u32m1x8_tu(vuint32m1x8_t maskedoff_tuple, const uint32_t *base, size_t vl) {
  return __riscv_vlseg8e32_tu(maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 8) @test_vlseg8e32_v_f32mf2x8_tum
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 8) @llvm.riscv.vlseg8.mask.triscv.vector.tuple_nxv4i8_8t.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 2, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[TMP0]]
//
vfloat32mf2x8_t test_vlseg8e32_v_f32mf2x8_tum(vbool64_t mask, vfloat32mf2x8_t maskedoff_tuple, const float *base, size_t vl) {
  return __riscv_vlseg8e32_tum(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 8) @test_vlseg8e32_v_f32m1x8_tum
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 8) @llvm.riscv.vlseg8.mask.triscv.vector.tuple_nxv8i8_8t.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 2, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[TMP0]]
//
vfloat32m1x8_t test_vlseg8e32_v_f32m1x8_tum(vbool32_t mask, vfloat32m1x8_t maskedoff_tuple, const float *base, size_t vl) {
  return __riscv_vlseg8e32_tum(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 8) @test_vlseg8e32_v_i32mf2x8_tum
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 8) @llvm.riscv.vlseg8.mask.triscv.vector.tuple_nxv4i8_8t.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 2, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[TMP0]]
//
vint32mf2x8_t test_vlseg8e32_v_i32mf2x8_tum(vbool64_t mask, vint32mf2x8_t maskedoff_tuple, const int32_t *base, size_t vl) {
  return __riscv_vlseg8e32_tum(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 8) @test_vlseg8e32_v_i32m1x8_tum
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 8) @llvm.riscv.vlseg8.mask.triscv.vector.tuple_nxv8i8_8t.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 2, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[TMP0]]
//
vint32m1x8_t test_vlseg8e32_v_i32m1x8_tum(vbool32_t mask, vint32m1x8_t maskedoff_tuple, const int32_t *base, size_t vl) {
  return __riscv_vlseg8e32_tum(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 8) @test_vlseg8e32_v_u32mf2x8_tum
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 8) @llvm.riscv.vlseg8.mask.triscv.vector.tuple_nxv4i8_8t.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 2, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[TMP0]]
//
vuint32mf2x8_t test_vlseg8e32_v_u32mf2x8_tum(vbool64_t mask, vuint32mf2x8_t maskedoff_tuple, const uint32_t *base, size_t vl) {
  return __riscv_vlseg8e32_tum(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 8) @test_vlseg8e32_v_u32m1x8_tum
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 8) @llvm.riscv.vlseg8.mask.triscv.vector.tuple_nxv8i8_8t.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 2, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[TMP0]]
//
vuint32m1x8_t test_vlseg8e32_v_u32m1x8_tum(vbool32_t mask, vuint32m1x8_t maskedoff_tuple, const uint32_t *base, size_t vl) {
  return __riscv_vlseg8e32_tum(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 8) @test_vlseg8e32_v_f32mf2x8_tumu
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 8) @llvm.riscv.vlseg8.mask.triscv.vector.tuple_nxv4i8_8t.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 0, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[TMP0]]
//
vfloat32mf2x8_t test_vlseg8e32_v_f32mf2x8_tumu(vbool64_t mask, vfloat32mf2x8_t maskedoff_tuple, const float *base, size_t vl) {
  return __riscv_vlseg8e32_tumu(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 8) @test_vlseg8e32_v_f32m1x8_tumu
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 8) @llvm.riscv.vlseg8.mask.triscv.vector.tuple_nxv8i8_8t.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 0, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[TMP0]]
//
vfloat32m1x8_t test_vlseg8e32_v_f32m1x8_tumu(vbool32_t mask, vfloat32m1x8_t maskedoff_tuple, const float *base, size_t vl) {
  return __riscv_vlseg8e32_tumu(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 8) @test_vlseg8e32_v_i32mf2x8_tumu
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 8) @llvm.riscv.vlseg8.mask.triscv.vector.tuple_nxv4i8_8t.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 0, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[TMP0]]
//
vint32mf2x8_t test_vlseg8e32_v_i32mf2x8_tumu(vbool64_t mask, vint32mf2x8_t maskedoff_tuple, const int32_t *base, size_t vl) {
  return __riscv_vlseg8e32_tumu(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 8) @test_vlseg8e32_v_i32m1x8_tumu
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 8) @llvm.riscv.vlseg8.mask.triscv.vector.tuple_nxv8i8_8t.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 0, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[TMP0]]
//
vint32m1x8_t test_vlseg8e32_v_i32m1x8_tumu(vbool32_t mask, vint32m1x8_t maskedoff_tuple, const int32_t *base, size_t vl) {
  return __riscv_vlseg8e32_tumu(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 8) @test_vlseg8e32_v_u32mf2x8_tumu
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 8) @llvm.riscv.vlseg8.mask.triscv.vector.tuple_nxv4i8_8t.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 0, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[TMP0]]
//
vuint32mf2x8_t test_vlseg8e32_v_u32mf2x8_tumu(vbool64_t mask, vuint32mf2x8_t maskedoff_tuple, const uint32_t *base, size_t vl) {
  return __riscv_vlseg8e32_tumu(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 8) @test_vlseg8e32_v_u32m1x8_tumu
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 8) @llvm.riscv.vlseg8.mask.triscv.vector.tuple_nxv8i8_8t.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 0, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[TMP0]]
//
vuint32m1x8_t test_vlseg8e32_v_u32m1x8_tumu(vbool32_t mask, vuint32m1x8_t maskedoff_tuple, const uint32_t *base, size_t vl) {
  return __riscv_vlseg8e32_tumu(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 8) @test_vlseg8e32_v_f32mf2x8_mu
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 8) @llvm.riscv.vlseg8.mask.triscv.vector.tuple_nxv4i8_8t.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 1, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[TMP0]]
//
vfloat32mf2x8_t test_vlseg8e32_v_f32mf2x8_mu(vbool64_t mask, vfloat32mf2x8_t maskedoff_tuple, const float *base, size_t vl) {
  return __riscv_vlseg8e32_mu(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 8) @test_vlseg8e32_v_f32m1x8_mu
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 8) @llvm.riscv.vlseg8.mask.triscv.vector.tuple_nxv8i8_8t.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 1, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[TMP0]]
//
vfloat32m1x8_t test_vlseg8e32_v_f32m1x8_mu(vbool32_t mask, vfloat32m1x8_t maskedoff_tuple, const float *base, size_t vl) {
  return __riscv_vlseg8e32_mu(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 8) @test_vlseg8e32_v_i32mf2x8_mu
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 8) @llvm.riscv.vlseg8.mask.triscv.vector.tuple_nxv4i8_8t.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 1, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[TMP0]]
//
vint32mf2x8_t test_vlseg8e32_v_i32mf2x8_mu(vbool64_t mask, vint32mf2x8_t maskedoff_tuple, const int32_t *base, size_t vl) {
  return __riscv_vlseg8e32_mu(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 8) @test_vlseg8e32_v_i32m1x8_mu
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 8) @llvm.riscv.vlseg8.mask.triscv.vector.tuple_nxv8i8_8t.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 1, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[TMP0]]
//
vint32m1x8_t test_vlseg8e32_v_i32m1x8_mu(vbool32_t mask, vint32m1x8_t maskedoff_tuple, const int32_t *base, size_t vl) {
  return __riscv_vlseg8e32_mu(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 8) @test_vlseg8e32_v_u32mf2x8_mu
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 8) @llvm.riscv.vlseg8.mask.triscv.vector.tuple_nxv4i8_8t.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 1, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[TMP0]]
//
vuint32mf2x8_t test_vlseg8e32_v_u32mf2x8_mu(vbool64_t mask, vuint32mf2x8_t maskedoff_tuple, const uint32_t *base, size_t vl) {
  return __riscv_vlseg8e32_mu(mask, maskedoff_tuple, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 8) @test_vlseg8e32_v_u32m1x8_mu
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[MASKEDOFF_TUPLE:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 8) @llvm.riscv.vlseg8.mask.triscv.vector.tuple_nxv8i8_8t.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[MASKEDOFF_TUPLE]], ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 1, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[TMP0]]
//
vuint32m1x8_t test_vlseg8e32_v_u32m1x8_mu(vbool32_t mask, vuint32m1x8_t maskedoff_tuple, const uint32_t *base, size_t vl) {
  return __riscv_vlseg8e32_mu(mask, maskedoff_tuple, base, vl);
}

