// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 2
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +zvfhmin -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local void @test_vsseg7e16_v_f16mf4x7
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 7) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg7.triscv.vector.tuple_nxv2i8_7t.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 7) [[V_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg7e16_v_f16mf4x7(_Float16 *base, vfloat16mf4x7_t v_tuple, size_t vl) {
  return __riscv_vsseg7e16_v_f16mf4x7(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg7e16_v_f16mf2x7
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 7) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg7.triscv.vector.tuple_nxv4i8_7t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 7) [[V_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg7e16_v_f16mf2x7(_Float16 *base, vfloat16mf2x7_t v_tuple, size_t vl) {
  return __riscv_vsseg7e16_v_f16mf2x7(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg7e16_v_f16m1x7
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 7) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg7.triscv.vector.tuple_nxv8i8_7t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 7) [[V_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg7e16_v_f16m1x7(_Float16 *base, vfloat16m1x7_t v_tuple, size_t vl) {
  return __riscv_vsseg7e16_v_f16m1x7(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg7e16_v_i16mf4x7
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 7) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg7.triscv.vector.tuple_nxv2i8_7t.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 7) [[V_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg7e16_v_i16mf4x7(int16_t *base, vint16mf4x7_t v_tuple, size_t vl) {
  return __riscv_vsseg7e16_v_i16mf4x7(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg7e16_v_i16mf2x7
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 7) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg7.triscv.vector.tuple_nxv4i8_7t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 7) [[V_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg7e16_v_i16mf2x7(int16_t *base, vint16mf2x7_t v_tuple, size_t vl) {
  return __riscv_vsseg7e16_v_i16mf2x7(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg7e16_v_i16m1x7
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 7) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg7.triscv.vector.tuple_nxv8i8_7t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 7) [[V_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg7e16_v_i16m1x7(int16_t *base, vint16m1x7_t v_tuple, size_t vl) {
  return __riscv_vsseg7e16_v_i16m1x7(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg7e16_v_u16mf4x7
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 7) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg7.triscv.vector.tuple_nxv2i8_7t.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 7) [[V_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg7e16_v_u16mf4x7(uint16_t *base, vuint16mf4x7_t v_tuple, size_t vl) {
  return __riscv_vsseg7e16_v_u16mf4x7(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg7e16_v_u16mf2x7
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 7) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg7.triscv.vector.tuple_nxv4i8_7t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 7) [[V_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg7e16_v_u16mf2x7(uint16_t *base, vuint16mf2x7_t v_tuple, size_t vl) {
  return __riscv_vsseg7e16_v_u16mf2x7(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg7e16_v_u16m1x7
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 7) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg7.triscv.vector.tuple_nxv8i8_7t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 7) [[V_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg7e16_v_u16m1x7(uint16_t *base, vuint16m1x7_t v_tuple, size_t vl) {
  return __riscv_vsseg7e16_v_u16m1x7(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg7e16_v_f16mf4x7_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 7) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg7.mask.triscv.vector.tuple_nxv2i8_7t.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 7) [[V_TUPLE]], ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg7e16_v_f16mf4x7_m(vbool64_t mask, _Float16 *base, vfloat16mf4x7_t v_tuple, size_t vl) {
  return __riscv_vsseg7e16_v_f16mf4x7_m(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg7e16_v_f16mf2x7_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 7) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg7.mask.triscv.vector.tuple_nxv4i8_7t.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 7) [[V_TUPLE]], ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg7e16_v_f16mf2x7_m(vbool32_t mask, _Float16 *base, vfloat16mf2x7_t v_tuple, size_t vl) {
  return __riscv_vsseg7e16_v_f16mf2x7_m(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg7e16_v_f16m1x7_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 7) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg7.mask.triscv.vector.tuple_nxv8i8_7t.nxv4i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 7) [[V_TUPLE]], ptr [[BASE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg7e16_v_f16m1x7_m(vbool16_t mask, _Float16 *base, vfloat16m1x7_t v_tuple, size_t vl) {
  return __riscv_vsseg7e16_v_f16m1x7_m(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg7e16_v_i16mf4x7_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 7) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg7.mask.triscv.vector.tuple_nxv2i8_7t.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 7) [[V_TUPLE]], ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg7e16_v_i16mf4x7_m(vbool64_t mask, int16_t *base, vint16mf4x7_t v_tuple, size_t vl) {
  return __riscv_vsseg7e16_v_i16mf4x7_m(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg7e16_v_i16mf2x7_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 7) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg7.mask.triscv.vector.tuple_nxv4i8_7t.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 7) [[V_TUPLE]], ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg7e16_v_i16mf2x7_m(vbool32_t mask, int16_t *base, vint16mf2x7_t v_tuple, size_t vl) {
  return __riscv_vsseg7e16_v_i16mf2x7_m(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg7e16_v_i16m1x7_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 7) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg7.mask.triscv.vector.tuple_nxv8i8_7t.nxv4i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 7) [[V_TUPLE]], ptr [[BASE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg7e16_v_i16m1x7_m(vbool16_t mask, int16_t *base, vint16m1x7_t v_tuple, size_t vl) {
  return __riscv_vsseg7e16_v_i16m1x7_m(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg7e16_v_u16mf4x7_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 7) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg7.mask.triscv.vector.tuple_nxv2i8_7t.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 7) [[V_TUPLE]], ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg7e16_v_u16mf4x7_m(vbool64_t mask, uint16_t *base, vuint16mf4x7_t v_tuple, size_t vl) {
  return __riscv_vsseg7e16_v_u16mf4x7_m(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg7e16_v_u16mf2x7_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 7) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg7.mask.triscv.vector.tuple_nxv4i8_7t.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 7) [[V_TUPLE]], ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg7e16_v_u16mf2x7_m(vbool32_t mask, uint16_t *base, vuint16mf2x7_t v_tuple, size_t vl) {
  return __riscv_vsseg7e16_v_u16mf2x7_m(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg7e16_v_u16m1x7_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 7) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg7.mask.triscv.vector.tuple_nxv8i8_7t.nxv4i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 7) [[V_TUPLE]], ptr [[BASE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg7e16_v_u16m1x7_m(vbool16_t mask, uint16_t *base, vuint16m1x7_t v_tuple, size_t vl) {
  return __riscv_vsseg7e16_v_u16m1x7_m(mask, base, v_tuple, vl);
}

