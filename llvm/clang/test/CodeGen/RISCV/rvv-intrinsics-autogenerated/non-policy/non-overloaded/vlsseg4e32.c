// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 2
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +zvfh -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 4) @test_vlsseg4e32_v_f32mf2x4
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 4) @llvm.riscv.vlsseg4.triscv.vector.tuple_nxv4i8_4t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 4) poison, ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 4) [[TMP0]]
//
vfloat32mf2x4_t test_vlsseg4e32_v_f32mf2x4(const float *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg4e32_v_f32mf2x4(base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 4) @test_vlsseg4e32_v_f32m1x4
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 4) @llvm.riscv.vlsseg4.triscv.vector.tuple_nxv8i8_4t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 4) poison, ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 4) [[TMP0]]
//
vfloat32m1x4_t test_vlsseg4e32_v_f32m1x4(const float *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg4e32_v_f32m1x4(base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 16 x i8>, 4) @test_vlsseg4e32_v_f32m2x4
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 16 x i8>, 4) @llvm.riscv.vlsseg4.triscv.vector.tuple_nxv16i8_4t.i64(target("riscv.vector.tuple", <vscale x 16 x i8>, 4) poison, ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 16 x i8>, 4) [[TMP0]]
//
vfloat32m2x4_t test_vlsseg4e32_v_f32m2x4(const float *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg4e32_v_f32m2x4(base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 4) @test_vlsseg4e32_v_i32mf2x4
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 4) @llvm.riscv.vlsseg4.triscv.vector.tuple_nxv4i8_4t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 4) poison, ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 4) [[TMP0]]
//
vint32mf2x4_t test_vlsseg4e32_v_i32mf2x4(const int32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg4e32_v_i32mf2x4(base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 4) @test_vlsseg4e32_v_i32m1x4
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 4) @llvm.riscv.vlsseg4.triscv.vector.tuple_nxv8i8_4t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 4) poison, ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 4) [[TMP0]]
//
vint32m1x4_t test_vlsseg4e32_v_i32m1x4(const int32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg4e32_v_i32m1x4(base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 16 x i8>, 4) @test_vlsseg4e32_v_i32m2x4
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 16 x i8>, 4) @llvm.riscv.vlsseg4.triscv.vector.tuple_nxv16i8_4t.i64(target("riscv.vector.tuple", <vscale x 16 x i8>, 4) poison, ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 16 x i8>, 4) [[TMP0]]
//
vint32m2x4_t test_vlsseg4e32_v_i32m2x4(const int32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg4e32_v_i32m2x4(base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 4) @test_vlsseg4e32_v_u32mf2x4
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 4) @llvm.riscv.vlsseg4.triscv.vector.tuple_nxv4i8_4t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 4) poison, ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 4) [[TMP0]]
//
vuint32mf2x4_t test_vlsseg4e32_v_u32mf2x4(const uint32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg4e32_v_u32mf2x4(base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 4) @test_vlsseg4e32_v_u32m1x4
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 4) @llvm.riscv.vlsseg4.triscv.vector.tuple_nxv8i8_4t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 4) poison, ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 4) [[TMP0]]
//
vuint32m1x4_t test_vlsseg4e32_v_u32m1x4(const uint32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg4e32_v_u32m1x4(base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 16 x i8>, 4) @test_vlsseg4e32_v_u32m2x4
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 16 x i8>, 4) @llvm.riscv.vlsseg4.triscv.vector.tuple_nxv16i8_4t.i64(target("riscv.vector.tuple", <vscale x 16 x i8>, 4) poison, ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 16 x i8>, 4) [[TMP0]]
//
vuint32m2x4_t test_vlsseg4e32_v_u32m2x4(const uint32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg4e32_v_u32m2x4(base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 4) @test_vlsseg4e32_v_f32mf2x4_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 4) @llvm.riscv.vlsseg4.mask.triscv.vector.tuple_nxv4i8_4t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 4 x i8>, 4) poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 4) [[TMP0]]
//
vfloat32mf2x4_t test_vlsseg4e32_v_f32mf2x4_m(vbool64_t mask, const float *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg4e32_v_f32mf2x4_m(mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 4) @test_vlsseg4e32_v_f32m1x4_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 4) @llvm.riscv.vlsseg4.mask.triscv.vector.tuple_nxv8i8_4t.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 4) poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 4) [[TMP0]]
//
vfloat32m1x4_t test_vlsseg4e32_v_f32m1x4_m(vbool32_t mask, const float *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg4e32_v_f32m1x4_m(mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 16 x i8>, 4) @test_vlsseg4e32_v_f32m2x4_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 16 x i8>, 4) @llvm.riscv.vlsseg4.mask.triscv.vector.tuple_nxv16i8_4t.i64.nxv4i1(target("riscv.vector.tuple", <vscale x 16 x i8>, 4) poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 3, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 16 x i8>, 4) [[TMP0]]
//
vfloat32m2x4_t test_vlsseg4e32_v_f32m2x4_m(vbool16_t mask, const float *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg4e32_v_f32m2x4_m(mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 4) @test_vlsseg4e32_v_i32mf2x4_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 4) @llvm.riscv.vlsseg4.mask.triscv.vector.tuple_nxv4i8_4t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 4 x i8>, 4) poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 4) [[TMP0]]
//
vint32mf2x4_t test_vlsseg4e32_v_i32mf2x4_m(vbool64_t mask, const int32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg4e32_v_i32mf2x4_m(mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 4) @test_vlsseg4e32_v_i32m1x4_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 4) @llvm.riscv.vlsseg4.mask.triscv.vector.tuple_nxv8i8_4t.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 4) poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 4) [[TMP0]]
//
vint32m1x4_t test_vlsseg4e32_v_i32m1x4_m(vbool32_t mask, const int32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg4e32_v_i32m1x4_m(mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 16 x i8>, 4) @test_vlsseg4e32_v_i32m2x4_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 16 x i8>, 4) @llvm.riscv.vlsseg4.mask.triscv.vector.tuple_nxv16i8_4t.i64.nxv4i1(target("riscv.vector.tuple", <vscale x 16 x i8>, 4) poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 3, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 16 x i8>, 4) [[TMP0]]
//
vint32m2x4_t test_vlsseg4e32_v_i32m2x4_m(vbool16_t mask, const int32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg4e32_v_i32m2x4_m(mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 4) @test_vlsseg4e32_v_u32mf2x4_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 4) @llvm.riscv.vlsseg4.mask.triscv.vector.tuple_nxv4i8_4t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 4 x i8>, 4) poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 4) [[TMP0]]
//
vuint32mf2x4_t test_vlsseg4e32_v_u32mf2x4_m(vbool64_t mask, const uint32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg4e32_v_u32mf2x4_m(mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 4) @test_vlsseg4e32_v_u32m1x4_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 4) @llvm.riscv.vlsseg4.mask.triscv.vector.tuple_nxv8i8_4t.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 4) poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 4) [[TMP0]]
//
vuint32m1x4_t test_vlsseg4e32_v_u32m1x4_m(vbool32_t mask, const uint32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg4e32_v_u32m1x4_m(mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 16 x i8>, 4) @test_vlsseg4e32_v_u32m2x4_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 16 x i8>, 4) @llvm.riscv.vlsseg4.mask.triscv.vector.tuple_nxv16i8_4t.i64.nxv4i1(target("riscv.vector.tuple", <vscale x 16 x i8>, 4) poison, ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 3, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 16 x i8>, 4) [[TMP0]]
//
vuint32m2x4_t test_vlsseg4e32_v_u32m2x4_m(vbool16_t mask, const uint32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg4e32_v_u32m2x4_m(mask, base, bstride, vl);
}

