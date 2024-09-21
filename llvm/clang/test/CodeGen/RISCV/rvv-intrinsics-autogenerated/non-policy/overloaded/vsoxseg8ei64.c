// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 2
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +zvfhmin -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_f16mf4x8
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], <vscale x 1 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.triscv.vector.tuple_nxv2i8_8t.nxv1i64.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 1 x i64> [[BINDEX]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_f16mf4x8(_Float16 *base, vuint64m1_t bindex, vfloat16mf4x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_f16mf2x8
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], <vscale x 2 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.triscv.vector.tuple_nxv4i8_8t.nxv2i64.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 2 x i64> [[BINDEX]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_f16mf2x8(_Float16 *base, vuint64m2_t bindex, vfloat16mf2x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_f16m1x8
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], <vscale x 4 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.triscv.vector.tuple_nxv8i8_8t.nxv4i64.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 4 x i64> [[BINDEX]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_f16m1x8(_Float16 *base, vuint64m4_t bindex, vfloat16m1x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_f32mf2x8
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], <vscale x 1 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.triscv.vector.tuple_nxv4i8_8t.nxv1i64.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 1 x i64> [[BINDEX]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_f32mf2x8(float *base, vuint64m1_t bindex, vfloat32mf2x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_f32m1x8
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], <vscale x 2 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.triscv.vector.tuple_nxv8i8_8t.nxv2i64.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 2 x i64> [[BINDEX]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_f32m1x8(float *base, vuint64m2_t bindex, vfloat32m1x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_f64m1x8
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], <vscale x 1 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.triscv.vector.tuple_nxv8i8_8t.nxv1i64.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 1 x i64> [[BINDEX]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_f64m1x8(double *base, vuint64m1_t bindex, vfloat64m1x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_i8mf8x8
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], <vscale x 1 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 1 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.triscv.vector.tuple_nxv1i8_8t.nxv1i64.i64(target("riscv.vector.tuple", <vscale x 1 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 1 x i64> [[BINDEX]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_i8mf8x8(int8_t *base, vuint64m1_t bindex, vint8mf8x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_i8mf4x8
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], <vscale x 2 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.triscv.vector.tuple_nxv2i8_8t.nxv2i64.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 2 x i64> [[BINDEX]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_i8mf4x8(int8_t *base, vuint64m2_t bindex, vint8mf4x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_i8mf2x8
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], <vscale x 4 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.triscv.vector.tuple_nxv4i8_8t.nxv4i64.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 4 x i64> [[BINDEX]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_i8mf2x8(int8_t *base, vuint64m4_t bindex, vint8mf2x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_i8m1x8
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], <vscale x 8 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.triscv.vector.tuple_nxv8i8_8t.nxv8i64.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 8 x i64> [[BINDEX]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_i8m1x8(int8_t *base, vuint64m8_t bindex, vint8m1x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_i16mf4x8
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], <vscale x 1 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.triscv.vector.tuple_nxv2i8_8t.nxv1i64.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 1 x i64> [[BINDEX]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_i16mf4x8(int16_t *base, vuint64m1_t bindex, vint16mf4x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_i16mf2x8
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], <vscale x 2 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.triscv.vector.tuple_nxv4i8_8t.nxv2i64.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 2 x i64> [[BINDEX]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_i16mf2x8(int16_t *base, vuint64m2_t bindex, vint16mf2x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_i16m1x8
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], <vscale x 4 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.triscv.vector.tuple_nxv8i8_8t.nxv4i64.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 4 x i64> [[BINDEX]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_i16m1x8(int16_t *base, vuint64m4_t bindex, vint16m1x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_i32mf2x8
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], <vscale x 1 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.triscv.vector.tuple_nxv4i8_8t.nxv1i64.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 1 x i64> [[BINDEX]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_i32mf2x8(int32_t *base, vuint64m1_t bindex, vint32mf2x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_i32m1x8
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], <vscale x 2 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.triscv.vector.tuple_nxv8i8_8t.nxv2i64.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 2 x i64> [[BINDEX]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_i32m1x8(int32_t *base, vuint64m2_t bindex, vint32m1x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_i64m1x8
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], <vscale x 1 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.triscv.vector.tuple_nxv8i8_8t.nxv1i64.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 1 x i64> [[BINDEX]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_i64m1x8(int64_t *base, vuint64m1_t bindex, vint64m1x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_u8mf8x8
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], <vscale x 1 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 1 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.triscv.vector.tuple_nxv1i8_8t.nxv1i64.i64(target("riscv.vector.tuple", <vscale x 1 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 1 x i64> [[BINDEX]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_u8mf8x8(uint8_t *base, vuint64m1_t bindex, vuint8mf8x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_u8mf4x8
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], <vscale x 2 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.triscv.vector.tuple_nxv2i8_8t.nxv2i64.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 2 x i64> [[BINDEX]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_u8mf4x8(uint8_t *base, vuint64m2_t bindex, vuint8mf4x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_u8mf2x8
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], <vscale x 4 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.triscv.vector.tuple_nxv4i8_8t.nxv4i64.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 4 x i64> [[BINDEX]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_u8mf2x8(uint8_t *base, vuint64m4_t bindex, vuint8mf2x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_u8m1x8
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], <vscale x 8 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.triscv.vector.tuple_nxv8i8_8t.nxv8i64.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 8 x i64> [[BINDEX]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_u8m1x8(uint8_t *base, vuint64m8_t bindex, vuint8m1x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_u16mf4x8
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], <vscale x 1 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.triscv.vector.tuple_nxv2i8_8t.nxv1i64.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 1 x i64> [[BINDEX]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_u16mf4x8(uint16_t *base, vuint64m1_t bindex, vuint16mf4x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_u16mf2x8
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], <vscale x 2 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.triscv.vector.tuple_nxv4i8_8t.nxv2i64.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 2 x i64> [[BINDEX]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_u16mf2x8(uint16_t *base, vuint64m2_t bindex, vuint16mf2x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_u16m1x8
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], <vscale x 4 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.triscv.vector.tuple_nxv8i8_8t.nxv4i64.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 4 x i64> [[BINDEX]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_u16m1x8(uint16_t *base, vuint64m4_t bindex, vuint16m1x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_u32mf2x8
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], <vscale x 1 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.triscv.vector.tuple_nxv4i8_8t.nxv1i64.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 1 x i64> [[BINDEX]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_u32mf2x8(uint32_t *base, vuint64m1_t bindex, vuint32mf2x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_u32m1x8
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], <vscale x 2 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.triscv.vector.tuple_nxv8i8_8t.nxv2i64.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 2 x i64> [[BINDEX]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_u32m1x8(uint32_t *base, vuint64m2_t bindex, vuint32m1x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_u64m1x8
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], <vscale x 1 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.triscv.vector.tuple_nxv8i8_8t.nxv1i64.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 1 x i64> [[BINDEX]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_u64m1x8(uint64_t *base, vuint64m1_t bindex, vuint64m1x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_f16mf4x8_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], <vscale x 1 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.mask.triscv.vector.tuple_nxv2i8_8t.nxv1i64.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 1 x i64> [[BINDEX]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_f16mf4x8_m(vbool64_t mask, _Float16 *base, vuint64m1_t bindex, vfloat16mf4x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(mask, base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_f16mf2x8_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], <vscale x 2 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.mask.triscv.vector.tuple_nxv4i8_8t.nxv2i64.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 2 x i64> [[BINDEX]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_f16mf2x8_m(vbool32_t mask, _Float16 *base, vuint64m2_t bindex, vfloat16mf2x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(mask, base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_f16m1x8_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], <vscale x 4 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.mask.triscv.vector.tuple_nxv8i8_8t.nxv4i64.nxv4i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 4 x i64> [[BINDEX]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_f16m1x8_m(vbool16_t mask, _Float16 *base, vuint64m4_t bindex, vfloat16m1x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(mask, base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_f32mf2x8_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], <vscale x 1 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.mask.triscv.vector.tuple_nxv4i8_8t.nxv1i64.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 1 x i64> [[BINDEX]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_f32mf2x8_m(vbool64_t mask, float *base, vuint64m1_t bindex, vfloat32mf2x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(mask, base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_f32m1x8_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], <vscale x 2 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.mask.triscv.vector.tuple_nxv8i8_8t.nxv2i64.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 2 x i64> [[BINDEX]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_f32m1x8_m(vbool32_t mask, float *base, vuint64m2_t bindex, vfloat32m1x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(mask, base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_f64m1x8_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], <vscale x 1 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.mask.triscv.vector.tuple_nxv8i8_8t.nxv1i64.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 1 x i64> [[BINDEX]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_f64m1x8_m(vbool64_t mask, double *base, vuint64m1_t bindex, vfloat64m1x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(mask, base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_i8mf8x8_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], <vscale x 1 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 1 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.mask.triscv.vector.tuple_nxv1i8_8t.nxv1i64.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 1 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 1 x i64> [[BINDEX]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_i8mf8x8_m(vbool64_t mask, int8_t *base, vuint64m1_t bindex, vint8mf8x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(mask, base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_i8mf4x8_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], <vscale x 2 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.mask.triscv.vector.tuple_nxv2i8_8t.nxv2i64.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 2 x i64> [[BINDEX]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_i8mf4x8_m(vbool32_t mask, int8_t *base, vuint64m2_t bindex, vint8mf4x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(mask, base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_i8mf2x8_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], <vscale x 4 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.mask.triscv.vector.tuple_nxv4i8_8t.nxv4i64.nxv4i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 4 x i64> [[BINDEX]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_i8mf2x8_m(vbool16_t mask, int8_t *base, vuint64m4_t bindex, vint8mf2x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(mask, base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_i8m1x8_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], <vscale x 8 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.mask.triscv.vector.tuple_nxv8i8_8t.nxv8i64.nxv8i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 8 x i64> [[BINDEX]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_i8m1x8_m(vbool8_t mask, int8_t *base, vuint64m8_t bindex, vint8m1x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(mask, base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_i16mf4x8_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], <vscale x 1 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.mask.triscv.vector.tuple_nxv2i8_8t.nxv1i64.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 1 x i64> [[BINDEX]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_i16mf4x8_m(vbool64_t mask, int16_t *base, vuint64m1_t bindex, vint16mf4x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(mask, base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_i16mf2x8_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], <vscale x 2 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.mask.triscv.vector.tuple_nxv4i8_8t.nxv2i64.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 2 x i64> [[BINDEX]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_i16mf2x8_m(vbool32_t mask, int16_t *base, vuint64m2_t bindex, vint16mf2x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(mask, base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_i16m1x8_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], <vscale x 4 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.mask.triscv.vector.tuple_nxv8i8_8t.nxv4i64.nxv4i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 4 x i64> [[BINDEX]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_i16m1x8_m(vbool16_t mask, int16_t *base, vuint64m4_t bindex, vint16m1x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(mask, base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_i32mf2x8_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], <vscale x 1 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.mask.triscv.vector.tuple_nxv4i8_8t.nxv1i64.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 1 x i64> [[BINDEX]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_i32mf2x8_m(vbool64_t mask, int32_t *base, vuint64m1_t bindex, vint32mf2x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(mask, base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_i32m1x8_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], <vscale x 2 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.mask.triscv.vector.tuple_nxv8i8_8t.nxv2i64.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 2 x i64> [[BINDEX]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_i32m1x8_m(vbool32_t mask, int32_t *base, vuint64m2_t bindex, vint32m1x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(mask, base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_i64m1x8_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], <vscale x 1 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.mask.triscv.vector.tuple_nxv8i8_8t.nxv1i64.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 1 x i64> [[BINDEX]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_i64m1x8_m(vbool64_t mask, int64_t *base, vuint64m1_t bindex, vint64m1x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(mask, base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_u8mf8x8_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], <vscale x 1 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 1 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.mask.triscv.vector.tuple_nxv1i8_8t.nxv1i64.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 1 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 1 x i64> [[BINDEX]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_u8mf8x8_m(vbool64_t mask, uint8_t *base, vuint64m1_t bindex, vuint8mf8x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(mask, base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_u8mf4x8_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], <vscale x 2 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.mask.triscv.vector.tuple_nxv2i8_8t.nxv2i64.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 2 x i64> [[BINDEX]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_u8mf4x8_m(vbool32_t mask, uint8_t *base, vuint64m2_t bindex, vuint8mf4x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(mask, base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_u8mf2x8_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], <vscale x 4 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.mask.triscv.vector.tuple_nxv4i8_8t.nxv4i64.nxv4i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 4 x i64> [[BINDEX]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_u8mf2x8_m(vbool16_t mask, uint8_t *base, vuint64m4_t bindex, vuint8mf2x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(mask, base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_u8m1x8_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], <vscale x 8 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.mask.triscv.vector.tuple_nxv8i8_8t.nxv8i64.nxv8i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 8 x i64> [[BINDEX]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_u8m1x8_m(vbool8_t mask, uint8_t *base, vuint64m8_t bindex, vuint8m1x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(mask, base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_u16mf4x8_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], <vscale x 1 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.mask.triscv.vector.tuple_nxv2i8_8t.nxv1i64.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 1 x i64> [[BINDEX]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_u16mf4x8_m(vbool64_t mask, uint16_t *base, vuint64m1_t bindex, vuint16mf4x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(mask, base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_u16mf2x8_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], <vscale x 2 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.mask.triscv.vector.tuple_nxv4i8_8t.nxv2i64.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 2 x i64> [[BINDEX]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_u16mf2x8_m(vbool32_t mask, uint16_t *base, vuint64m2_t bindex, vuint16mf2x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(mask, base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_u16m1x8_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], <vscale x 4 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.mask.triscv.vector.tuple_nxv8i8_8t.nxv4i64.nxv4i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 4 x i64> [[BINDEX]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_u16m1x8_m(vbool16_t mask, uint16_t *base, vuint64m4_t bindex, vuint16m1x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(mask, base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_u32mf2x8_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], <vscale x 1 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.mask.triscv.vector.tuple_nxv4i8_8t.nxv1i64.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 1 x i64> [[BINDEX]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_u32mf2x8_m(vbool64_t mask, uint32_t *base, vuint64m1_t bindex, vuint32mf2x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(mask, base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_u32m1x8_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], <vscale x 2 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.mask.triscv.vector.tuple_nxv8i8_8t.nxv2i64.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 2 x i64> [[BINDEX]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_u32m1x8_m(vbool32_t mask, uint32_t *base, vuint64m2_t bindex, vuint32m1x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(mask, base, bindex, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsoxseg8ei64_v_u64m1x8_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], <vscale x 1 x i64> [[BINDEX:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsoxseg8.mask.triscv.vector.tuple_nxv8i8_8t.nxv1i64.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 8) [[V_TUPLE]], ptr [[BASE]], <vscale x 1 x i64> [[BINDEX]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    ret void
//
void test_vsoxseg8ei64_v_u64m1x8_m(vbool64_t mask, uint64_t *base, vuint64m1_t bindex, vuint64m1x8_t v_tuple, size_t vl) {
  return __riscv_vsoxseg8ei64(mask, base, bindex, v_tuple, vl);
}

