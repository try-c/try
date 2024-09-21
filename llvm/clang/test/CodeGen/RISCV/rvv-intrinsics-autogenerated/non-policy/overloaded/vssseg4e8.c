// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 2
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +zvfh -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local void @test_vssseg4e8_v_i8mf8x4
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], target("riscv.vector.tuple", <vscale x 1 x i8>, 4) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg4.triscv.vector.tuple_nxv1i8_4t.i64(target("riscv.vector.tuple", <vscale x 1 x i8>, 4) [[V_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg4e8_v_i8mf8x4(int8_t *base, ptrdiff_t bstride, vint8mf8x4_t v_tuple, size_t vl) {
  return __riscv_vssseg4e8(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg4e8_v_i8mf4x4
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 4) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg4.triscv.vector.tuple_nxv2i8_4t.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 4) [[V_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg4e8_v_i8mf4x4(int8_t *base, ptrdiff_t bstride, vint8mf4x4_t v_tuple, size_t vl) {
  return __riscv_vssseg4e8(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg4e8_v_i8mf2x4
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 4) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg4.triscv.vector.tuple_nxv4i8_4t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 4) [[V_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg4e8_v_i8mf2x4(int8_t *base, ptrdiff_t bstride, vint8mf2x4_t v_tuple, size_t vl) {
  return __riscv_vssseg4e8(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg4e8_v_i8m1x4
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 4) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg4.triscv.vector.tuple_nxv8i8_4t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 4) [[V_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg4e8_v_i8m1x4(int8_t *base, ptrdiff_t bstride, vint8m1x4_t v_tuple, size_t vl) {
  return __riscv_vssseg4e8(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg4e8_v_i8m2x4
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 4) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg4.triscv.vector.tuple_nxv16i8_4t.i64(target("riscv.vector.tuple", <vscale x 16 x i8>, 4) [[V_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg4e8_v_i8m2x4(int8_t *base, ptrdiff_t bstride, vint8m2x4_t v_tuple, size_t vl) {
  return __riscv_vssseg4e8(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg4e8_v_u8mf8x4
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], target("riscv.vector.tuple", <vscale x 1 x i8>, 4) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg4.triscv.vector.tuple_nxv1i8_4t.i64(target("riscv.vector.tuple", <vscale x 1 x i8>, 4) [[V_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg4e8_v_u8mf8x4(uint8_t *base, ptrdiff_t bstride, vuint8mf8x4_t v_tuple, size_t vl) {
  return __riscv_vssseg4e8(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg4e8_v_u8mf4x4
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 4) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg4.triscv.vector.tuple_nxv2i8_4t.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 4) [[V_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg4e8_v_u8mf4x4(uint8_t *base, ptrdiff_t bstride, vuint8mf4x4_t v_tuple, size_t vl) {
  return __riscv_vssseg4e8(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg4e8_v_u8mf2x4
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 4) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg4.triscv.vector.tuple_nxv4i8_4t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 4) [[V_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg4e8_v_u8mf2x4(uint8_t *base, ptrdiff_t bstride, vuint8mf2x4_t v_tuple, size_t vl) {
  return __riscv_vssseg4e8(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg4e8_v_u8m1x4
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 4) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg4.triscv.vector.tuple_nxv8i8_4t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 4) [[V_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg4e8_v_u8m1x4(uint8_t *base, ptrdiff_t bstride, vuint8m1x4_t v_tuple, size_t vl) {
  return __riscv_vssseg4e8(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg4e8_v_u8m2x4
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 4) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg4.triscv.vector.tuple_nxv16i8_4t.i64(target("riscv.vector.tuple", <vscale x 16 x i8>, 4) [[V_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg4e8_v_u8m2x4(uint8_t *base, ptrdiff_t bstride, vuint8m2x4_t v_tuple, size_t vl) {
  return __riscv_vssseg4e8(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg4e8_v_i8mf8x4_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], target("riscv.vector.tuple", <vscale x 1 x i8>, 4) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg4.mask.triscv.vector.tuple_nxv1i8_4t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 1 x i8>, 4) [[V_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg4e8_v_i8mf8x4_m(vbool64_t mask, int8_t *base, ptrdiff_t bstride, vint8mf8x4_t v_tuple, size_t vl) {
  return __riscv_vssseg4e8(mask, base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg4e8_v_i8mf4x4_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 4) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg4.mask.triscv.vector.tuple_nxv2i8_4t.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 2 x i8>, 4) [[V_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg4e8_v_i8mf4x4_m(vbool32_t mask, int8_t *base, ptrdiff_t bstride, vint8mf4x4_t v_tuple, size_t vl) {
  return __riscv_vssseg4e8(mask, base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg4e8_v_i8mf2x4_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 4) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg4.mask.triscv.vector.tuple_nxv4i8_4t.i64.nxv4i1(target("riscv.vector.tuple", <vscale x 4 x i8>, 4) [[V_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg4e8_v_i8mf2x4_m(vbool16_t mask, int8_t *base, ptrdiff_t bstride, vint8mf2x4_t v_tuple, size_t vl) {
  return __riscv_vssseg4e8(mask, base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg4e8_v_i8m1x4_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 4) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg4.mask.triscv.vector.tuple_nxv8i8_4t.i64.nxv8i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 4) [[V_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg4e8_v_i8m1x4_m(vbool8_t mask, int8_t *base, ptrdiff_t bstride, vint8m1x4_t v_tuple, size_t vl) {
  return __riscv_vssseg4e8(mask, base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg4e8_v_i8m2x4_m
// CHECK-RV64-SAME: (<vscale x 16 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 4) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg4.mask.triscv.vector.tuple_nxv16i8_4t.i64.nxv16i1(target("riscv.vector.tuple", <vscale x 16 x i8>, 4) [[V_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 16 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg4e8_v_i8m2x4_m(vbool4_t mask, int8_t *base, ptrdiff_t bstride, vint8m2x4_t v_tuple, size_t vl) {
  return __riscv_vssseg4e8(mask, base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg4e8_v_u8mf8x4_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], target("riscv.vector.tuple", <vscale x 1 x i8>, 4) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg4.mask.triscv.vector.tuple_nxv1i8_4t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 1 x i8>, 4) [[V_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg4e8_v_u8mf8x4_m(vbool64_t mask, uint8_t *base, ptrdiff_t bstride, vuint8mf8x4_t v_tuple, size_t vl) {
  return __riscv_vssseg4e8(mask, base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg4e8_v_u8mf4x4_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 4) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg4.mask.triscv.vector.tuple_nxv2i8_4t.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 2 x i8>, 4) [[V_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg4e8_v_u8mf4x4_m(vbool32_t mask, uint8_t *base, ptrdiff_t bstride, vuint8mf4x4_t v_tuple, size_t vl) {
  return __riscv_vssseg4e8(mask, base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg4e8_v_u8mf2x4_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 4) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg4.mask.triscv.vector.tuple_nxv4i8_4t.i64.nxv4i1(target("riscv.vector.tuple", <vscale x 4 x i8>, 4) [[V_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg4e8_v_u8mf2x4_m(vbool16_t mask, uint8_t *base, ptrdiff_t bstride, vuint8mf2x4_t v_tuple, size_t vl) {
  return __riscv_vssseg4e8(mask, base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg4e8_v_u8m1x4_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 4) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg4.mask.triscv.vector.tuple_nxv8i8_4t.i64.nxv8i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 4) [[V_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg4e8_v_u8m1x4_m(vbool8_t mask, uint8_t *base, ptrdiff_t bstride, vuint8m1x4_t v_tuple, size_t vl) {
  return __riscv_vssseg4e8(mask, base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg4e8_v_u8m2x4_m
// CHECK-RV64-SAME: (<vscale x 16 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 4) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg4.mask.triscv.vector.tuple_nxv16i8_4t.i64.nxv16i1(target("riscv.vector.tuple", <vscale x 16 x i8>, 4) [[V_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 16 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg4e8_v_u8m2x4_m(vbool4_t mask, uint8_t *base, ptrdiff_t bstride, vuint8m2x4_t v_tuple, size_t vl) {
  return __riscv_vssseg4e8(mask, base, bstride, v_tuple, vl);
}

