// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 2
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +zvfhmin -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local void @test_vsseg3e16_v_f16mf4x3
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg3.triscv.vector.tuple_nxv2i8_3t.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[V_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg3e16_v_f16mf4x3(_Float16 *base, vfloat16mf4x3_t v_tuple, size_t vl) {
  return __riscv_vsseg3e16(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg3e16_v_f16mf2x3
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg3.triscv.vector.tuple_nxv4i8_3t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[V_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg3e16_v_f16mf2x3(_Float16 *base, vfloat16mf2x3_t v_tuple, size_t vl) {
  return __riscv_vsseg3e16(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg3e16_v_f16m1x3
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg3.triscv.vector.tuple_nxv8i8_3t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[V_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg3e16_v_f16m1x3(_Float16 *base, vfloat16m1x3_t v_tuple, size_t vl) {
  return __riscv_vsseg3e16(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg3e16_v_f16m2x3
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg3.triscv.vector.tuple_nxv16i8_3t.i64(target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[V_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg3e16_v_f16m2x3(_Float16 *base, vfloat16m2x3_t v_tuple, size_t vl) {
  return __riscv_vsseg3e16(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg3e16_v_i16mf4x3
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg3.triscv.vector.tuple_nxv2i8_3t.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[V_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg3e16_v_i16mf4x3(int16_t *base, vint16mf4x3_t v_tuple, size_t vl) {
  return __riscv_vsseg3e16(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg3e16_v_i16mf2x3
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg3.triscv.vector.tuple_nxv4i8_3t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[V_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg3e16_v_i16mf2x3(int16_t *base, vint16mf2x3_t v_tuple, size_t vl) {
  return __riscv_vsseg3e16(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg3e16_v_i16m1x3
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg3.triscv.vector.tuple_nxv8i8_3t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[V_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg3e16_v_i16m1x3(int16_t *base, vint16m1x3_t v_tuple, size_t vl) {
  return __riscv_vsseg3e16(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg3e16_v_i16m2x3
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg3.triscv.vector.tuple_nxv16i8_3t.i64(target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[V_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg3e16_v_i16m2x3(int16_t *base, vint16m2x3_t v_tuple, size_t vl) {
  return __riscv_vsseg3e16(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg3e16_v_u16mf4x3
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg3.triscv.vector.tuple_nxv2i8_3t.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[V_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg3e16_v_u16mf4x3(uint16_t *base, vuint16mf4x3_t v_tuple, size_t vl) {
  return __riscv_vsseg3e16(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg3e16_v_u16mf2x3
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg3.triscv.vector.tuple_nxv4i8_3t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[V_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg3e16_v_u16mf2x3(uint16_t *base, vuint16mf2x3_t v_tuple, size_t vl) {
  return __riscv_vsseg3e16(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg3e16_v_u16m1x3
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg3.triscv.vector.tuple_nxv8i8_3t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[V_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg3e16_v_u16m1x3(uint16_t *base, vuint16m1x3_t v_tuple, size_t vl) {
  return __riscv_vsseg3e16(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg3e16_v_u16m2x3
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg3.triscv.vector.tuple_nxv16i8_3t.i64(target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[V_TUPLE]], ptr [[BASE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg3e16_v_u16m2x3(uint16_t *base, vuint16m2x3_t v_tuple, size_t vl) {
  return __riscv_vsseg3e16(base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg3e16_v_f16mf4x3_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg3.mask.triscv.vector.tuple_nxv2i8_3t.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[V_TUPLE]], ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg3e16_v_f16mf4x3_m(vbool64_t mask, _Float16 *base, vfloat16mf4x3_t v_tuple, size_t vl) {
  return __riscv_vsseg3e16(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg3e16_v_f16mf2x3_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg3.mask.triscv.vector.tuple_nxv4i8_3t.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[V_TUPLE]], ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg3e16_v_f16mf2x3_m(vbool32_t mask, _Float16 *base, vfloat16mf2x3_t v_tuple, size_t vl) {
  return __riscv_vsseg3e16(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg3e16_v_f16m1x3_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg3.mask.triscv.vector.tuple_nxv8i8_3t.nxv4i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[V_TUPLE]], ptr [[BASE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg3e16_v_f16m1x3_m(vbool16_t mask, _Float16 *base, vfloat16m1x3_t v_tuple, size_t vl) {
  return __riscv_vsseg3e16(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg3e16_v_f16m2x3_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg3.mask.triscv.vector.tuple_nxv16i8_3t.nxv8i1.i64(target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[V_TUPLE]], ptr [[BASE]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg3e16_v_f16m2x3_m(vbool8_t mask, _Float16 *base, vfloat16m2x3_t v_tuple, size_t vl) {
  return __riscv_vsseg3e16(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg3e16_v_i16mf4x3_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg3.mask.triscv.vector.tuple_nxv2i8_3t.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[V_TUPLE]], ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg3e16_v_i16mf4x3_m(vbool64_t mask, int16_t *base, vint16mf4x3_t v_tuple, size_t vl) {
  return __riscv_vsseg3e16(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg3e16_v_i16mf2x3_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg3.mask.triscv.vector.tuple_nxv4i8_3t.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[V_TUPLE]], ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg3e16_v_i16mf2x3_m(vbool32_t mask, int16_t *base, vint16mf2x3_t v_tuple, size_t vl) {
  return __riscv_vsseg3e16(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg3e16_v_i16m1x3_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg3.mask.triscv.vector.tuple_nxv8i8_3t.nxv4i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[V_TUPLE]], ptr [[BASE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg3e16_v_i16m1x3_m(vbool16_t mask, int16_t *base, vint16m1x3_t v_tuple, size_t vl) {
  return __riscv_vsseg3e16(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg3e16_v_i16m2x3_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg3.mask.triscv.vector.tuple_nxv16i8_3t.nxv8i1.i64(target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[V_TUPLE]], ptr [[BASE]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg3e16_v_i16m2x3_m(vbool8_t mask, int16_t *base, vint16m2x3_t v_tuple, size_t vl) {
  return __riscv_vsseg3e16(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg3e16_v_u16mf4x3_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg3.mask.triscv.vector.tuple_nxv2i8_3t.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 3) [[V_TUPLE]], ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg3e16_v_u16mf4x3_m(vbool64_t mask, uint16_t *base, vuint16mf4x3_t v_tuple, size_t vl) {
  return __riscv_vsseg3e16(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg3e16_v_u16mf2x3_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg3.mask.triscv.vector.tuple_nxv4i8_3t.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 3) [[V_TUPLE]], ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg3e16_v_u16mf2x3_m(vbool32_t mask, uint16_t *base, vuint16mf2x3_t v_tuple, size_t vl) {
  return __riscv_vsseg3e16(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg3e16_v_u16m1x3_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg3.mask.triscv.vector.tuple_nxv8i8_3t.nxv4i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[V_TUPLE]], ptr [[BASE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg3e16_v_u16m1x3_m(vbool16_t mask, uint16_t *base, vuint16m1x3_t v_tuple, size_t vl) {
  return __riscv_vsseg3e16(mask, base, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vsseg3e16_v_u16m2x3_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg3.mask.triscv.vector.tuple_nxv16i8_3t.nxv8i1.i64(target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[V_TUPLE]], ptr [[BASE]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg3e16_v_u16m2x3_m(vbool8_t mask, uint16_t *base, vuint16m2x3_t v_tuple, size_t vl) {
  return __riscv_vsseg3e16(mask, base, v_tuple, vl);
}

