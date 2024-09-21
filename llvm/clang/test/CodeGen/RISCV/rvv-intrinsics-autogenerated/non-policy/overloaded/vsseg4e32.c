// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 2
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +zvfh -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e32_v_f32mf2x4
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 4) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.triscv.vector.tuple_nxv4i8_4t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 4) [[V_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e32_v_f32mf2x4(float *base, vfloat32mf2x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e32(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e32_v_f32m1x4
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 4) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.triscv.vector.tuple_nxv8i8_4t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 4) [[V_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e32_v_f32m1x4(float *base, vfloat32m1x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e32(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e32_v_f32m2x4
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 4) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.triscv.vector.tuple_nxv16i8_4t.i64(target("riscv.vector.tuple", <vscale x 16 x i8>, 4) [[V_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e32_v_f32m2x4(float *base, vfloat32m2x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e32(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e32_v_i32mf2x4
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 4) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.triscv.vector.tuple_nxv4i8_4t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 4) [[V_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e32_v_i32mf2x4(int32_t *base, vint32mf2x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e32(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e32_v_i32m1x4
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 4) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.triscv.vector.tuple_nxv8i8_4t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 4) [[V_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e32_v_i32m1x4(int32_t *base, vint32m1x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e32(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e32_v_i32m2x4
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 4) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.triscv.vector.tuple_nxv16i8_4t.i64(target("riscv.vector.tuple", <vscale x 16 x i8>, 4) [[V_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e32_v_i32m2x4(int32_t *base, vint32m2x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e32(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e32_v_u32mf2x4
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 4) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.triscv.vector.tuple_nxv4i8_4t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 4) [[V_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e32_v_u32mf2x4(uint32_t *base, vuint32mf2x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e32(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e32_v_u32m1x4
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 4) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.triscv.vector.tuple_nxv8i8_4t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 4) [[V_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e32_v_u32m1x4(uint32_t *base, vuint32m1x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e32(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e32_v_u32m2x4
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 4) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.triscv.vector.tuple_nxv16i8_4t.i64(target("riscv.vector.tuple", <vscale x 16 x i8>, 4) [[V_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e32_v_u32m2x4(uint32_t *base, vuint32m2x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e32(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e32_v_f32mf2x4_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 4) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.mask.triscv.vector.tuple_nxv4i8_4t.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 4) [[V_TUPLE]], ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e32_v_f32mf2x4_m(vbool64_t mask, float *base, vfloat32mf2x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e32(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e32_v_f32m1x4_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 4) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.mask.triscv.vector.tuple_nxv8i8_4t.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 4) [[V_TUPLE]], ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e32_v_f32m1x4_m(vbool32_t mask, float *base, vfloat32m1x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e32(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e32_v_f32m2x4_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 4) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.mask.triscv.vector.tuple_nxv16i8_4t.nxv4i1.i64(target("riscv.vector.tuple", <vscale x 16 x i8>, 4) [[V_TUPLE]], ptr [[BASE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e32_v_f32m2x4_m(vbool16_t mask, float *base, vfloat32m2x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e32(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e32_v_i32mf2x4_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 4) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.mask.triscv.vector.tuple_nxv4i8_4t.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 4) [[V_TUPLE]], ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e32_v_i32mf2x4_m(vbool64_t mask, int32_t *base, vint32mf2x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e32(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e32_v_i32m1x4_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 4) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.mask.triscv.vector.tuple_nxv8i8_4t.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 4) [[V_TUPLE]], ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e32_v_i32m1x4_m(vbool32_t mask, int32_t *base, vint32m1x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e32(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e32_v_i32m2x4_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 4) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.mask.triscv.vector.tuple_nxv16i8_4t.nxv4i1.i64(target("riscv.vector.tuple", <vscale x 16 x i8>, 4) [[V_TUPLE]], ptr [[BASE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e32_v_i32m2x4_m(vbool16_t mask, int32_t *base, vint32m2x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e32(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e32_v_u32mf2x4_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 4) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.mask.triscv.vector.tuple_nxv4i8_4t.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 4) [[V_TUPLE]], ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e32_v_u32mf2x4_m(vbool64_t mask, uint32_t *base, vuint32mf2x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e32(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e32_v_u32m1x4_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 4) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.mask.triscv.vector.tuple_nxv8i8_4t.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 4) [[V_TUPLE]], ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e32_v_u32m1x4_m(vbool32_t mask, uint32_t *base, vuint32m1x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e32(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg4e32_v_u32m2x4_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 4) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg4.mask.triscv.vector.tuple_nxv16i8_4t.nxv4i1.i64(target("riscv.vector.tuple", <vscale x 16 x i8>, 4) [[V_TUPLE]], ptr [[BASE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg4e32_v_u32m2x4_m(vbool16_t mask, uint32_t *base, vuint32m2x4_t v_tuple, size_t vl) {
  return __riscv_vsseg4e32(mask, base, v_tuple, vl);
}

