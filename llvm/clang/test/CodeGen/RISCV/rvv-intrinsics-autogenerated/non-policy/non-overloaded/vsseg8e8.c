// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 2
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +zvfh -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local void @test_vsseg8e8_v_i8mf8x8
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 1 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg8.triscv.vector.tuple_nxv1i8_8t.i64(target("riscv.vector.tuple", <vscale x 1 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg8e8_v_i8mf8x8(int8_t *base, vint8mf8x8_t v_tuple, size_t vl) {
  return __riscv_vsseg8e8_v_i8mf8x8(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg8e8_v_i8mf4x8
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg8.triscv.vector.tuple_nxv2i8_8t.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg8e8_v_i8mf4x8(int8_t *base, vint8mf4x8_t v_tuple, size_t vl) {
  return __riscv_vsseg8e8_v_i8mf4x8(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg8e8_v_i8mf2x8
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg8.triscv.vector.tuple_nxv4i8_8t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg8e8_v_i8mf2x8(int8_t *base, vint8mf2x8_t v_tuple, size_t vl) {
  return __riscv_vsseg8e8_v_i8mf2x8(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg8e8_v_i8m1x8
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg8.triscv.vector.tuple_nxv8i8_8t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg8e8_v_i8m1x8(int8_t *base, vint8m1x8_t v_tuple, size_t vl) {
  return __riscv_vsseg8e8_v_i8m1x8(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg8e8_v_u8mf8x8
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 1 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg8.triscv.vector.tuple_nxv1i8_8t.i64(target("riscv.vector.tuple", <vscale x 1 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg8e8_v_u8mf8x8(uint8_t *base, vuint8mf8x8_t v_tuple, size_t vl) {
  return __riscv_vsseg8e8_v_u8mf8x8(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg8e8_v_u8mf4x8
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg8.triscv.vector.tuple_nxv2i8_8t.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg8e8_v_u8mf4x8(uint8_t *base, vuint8mf4x8_t v_tuple, size_t vl) {
  return __riscv_vsseg8e8_v_u8mf4x8(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg8e8_v_u8mf2x8
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg8.triscv.vector.tuple_nxv4i8_8t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg8e8_v_u8mf2x8(uint8_t *base, vuint8mf2x8_t v_tuple, size_t vl) {
  return __riscv_vsseg8e8_v_u8mf2x8(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg8e8_v_u8m1x8
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg8.triscv.vector.tuple_nxv8i8_8t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg8e8_v_u8m1x8(uint8_t *base, vuint8m1x8_t v_tuple, size_t vl) {
  return __riscv_vsseg8e8_v_u8m1x8(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg8e8_v_i8mf8x8_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 1 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg8.mask.triscv.vector.tuple_nxv1i8_8t.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 1 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg8e8_v_i8mf8x8_m(vbool64_t mask, int8_t *base, vint8mf8x8_t v_tuple, size_t vl) {
  return __riscv_vsseg8e8_v_i8mf8x8_m(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg8e8_v_i8mf4x8_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg8.mask.triscv.vector.tuple_nxv2i8_8t.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg8e8_v_i8mf4x8_m(vbool32_t mask, int8_t *base, vint8mf4x8_t v_tuple, size_t vl) {
  return __riscv_vsseg8e8_v_i8mf4x8_m(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg8e8_v_i8mf2x8_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg8.mask.triscv.vector.tuple_nxv4i8_8t.nxv4i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg8e8_v_i8mf2x8_m(vbool16_t mask, int8_t *base, vint8mf2x8_t v_tuple, size_t vl) {
  return __riscv_vsseg8e8_v_i8mf2x8_m(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg8e8_v_i8m1x8_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg8.mask.triscv.vector.tuple_nxv8i8_8t.nxv8i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg8e8_v_i8m1x8_m(vbool8_t mask, int8_t *base, vint8m1x8_t v_tuple, size_t vl) {
  return __riscv_vsseg8e8_v_i8m1x8_m(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg8e8_v_u8mf8x8_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 1 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg8.mask.triscv.vector.tuple_nxv1i8_8t.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 1 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg8e8_v_u8mf8x8_m(vbool64_t mask, uint8_t *base, vuint8mf8x8_t v_tuple, size_t vl) {
  return __riscv_vsseg8e8_v_u8mf8x8_m(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg8e8_v_u8mf4x8_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg8.mask.triscv.vector.tuple_nxv2i8_8t.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg8e8_v_u8mf4x8_m(vbool32_t mask, uint8_t *base, vuint8mf4x8_t v_tuple, size_t vl) {
  return __riscv_vsseg8e8_v_u8mf4x8_m(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg8e8_v_u8mf2x8_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg8.mask.triscv.vector.tuple_nxv4i8_8t.nxv4i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg8e8_v_u8mf2x8_m(vbool16_t mask, uint8_t *base, vuint8mf2x8_t v_tuple, size_t vl) {
  return __riscv_vsseg8e8_v_u8mf2x8_m(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg8e8_v_u8m1x8_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg8.mask.triscv.vector.tuple_nxv8i8_8t.nxv8i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg8e8_v_u8m1x8_m(vbool8_t mask, uint8_t *base, vuint8m1x8_t v_tuple, size_t vl) {
  return __riscv_vsseg8e8_v_u8m1x8_m(mask, base, v_tuple, vl);
}

