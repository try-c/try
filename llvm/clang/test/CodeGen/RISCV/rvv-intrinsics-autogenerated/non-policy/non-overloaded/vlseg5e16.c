// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 2
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +zvfhmin -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 5) @test_vlseg5e16_v_f16mf4x5
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 2 x i8>, 5) @llvm.riscv.vlseg5.triscv.vector.tuple_nxv2i8_5t.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 5) poison, ptr [[BASE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 5) [[TMP0]]
//
vfloat16mf4x5_t test_vlseg5e16_v_f16mf4x5(const _Float16 *base, size_t vl) {
  return __riscv_vlseg5e16_v_f16mf4x5(base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 5) @test_vlseg5e16_v_f16mf2x5
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 5) @llvm.riscv.vlseg5.triscv.vector.tuple_nxv4i8_5t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 5) poison, ptr [[BASE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 5) [[TMP0]]
//
vfloat16mf2x5_t test_vlseg5e16_v_f16mf2x5(const _Float16 *base, size_t vl) {
  return __riscv_vlseg5e16_v_f16mf2x5(base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 5) @test_vlseg5e16_v_f16m1x5
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 5) @llvm.riscv.vlseg5.triscv.vector.tuple_nxv8i8_5t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 5) poison, ptr [[BASE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 5) [[TMP0]]
//
vfloat16m1x5_t test_vlseg5e16_v_f16m1x5(const _Float16 *base, size_t vl) {
  return __riscv_vlseg5e16_v_f16m1x5(base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 5) @test_vlseg5e16_v_i16mf4x5
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 2 x i8>, 5) @llvm.riscv.vlseg5.triscv.vector.tuple_nxv2i8_5t.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 5) poison, ptr [[BASE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 5) [[TMP0]]
//
vint16mf4x5_t test_vlseg5e16_v_i16mf4x5(const int16_t *base, size_t vl) {
  return __riscv_vlseg5e16_v_i16mf4x5(base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 5) @test_vlseg5e16_v_i16mf2x5
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 5) @llvm.riscv.vlseg5.triscv.vector.tuple_nxv4i8_5t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 5) poison, ptr [[BASE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 5) [[TMP0]]
//
vint16mf2x5_t test_vlseg5e16_v_i16mf2x5(const int16_t *base, size_t vl) {
  return __riscv_vlseg5e16_v_i16mf2x5(base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 5) @test_vlseg5e16_v_i16m1x5
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 5) @llvm.riscv.vlseg5.triscv.vector.tuple_nxv8i8_5t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 5) poison, ptr [[BASE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 5) [[TMP0]]
//
vint16m1x5_t test_vlseg5e16_v_i16m1x5(const int16_t *base, size_t vl) {
  return __riscv_vlseg5e16_v_i16m1x5(base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 5) @test_vlseg5e16_v_u16mf4x5
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 2 x i8>, 5) @llvm.riscv.vlseg5.triscv.vector.tuple_nxv2i8_5t.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 5) poison, ptr [[BASE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 5) [[TMP0]]
//
vuint16mf4x5_t test_vlseg5e16_v_u16mf4x5(const uint16_t *base, size_t vl) {
  return __riscv_vlseg5e16_v_u16mf4x5(base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 5) @test_vlseg5e16_v_u16mf2x5
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 5) @llvm.riscv.vlseg5.triscv.vector.tuple_nxv4i8_5t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 5) poison, ptr [[BASE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 5) [[TMP0]]
//
vuint16mf2x5_t test_vlseg5e16_v_u16mf2x5(const uint16_t *base, size_t vl) {
  return __riscv_vlseg5e16_v_u16mf2x5(base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 5) @test_vlseg5e16_v_u16m1x5
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 5) @llvm.riscv.vlseg5.triscv.vector.tuple_nxv8i8_5t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 5) poison, ptr [[BASE]], i64 [[VL]], i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 5) [[TMP0]]
//
vuint16m1x5_t test_vlseg5e16_v_u16m1x5(const uint16_t *base, size_t vl) {
  return __riscv_vlseg5e16_v_u16m1x5(base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 5) @test_vlseg5e16_v_f16mf4x5_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 2 x i8>, 5) @llvm.riscv.vlseg5.mask.triscv.vector.tuple_nxv2i8_5t.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 5) poison, ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 5) [[TMP0]]
//
vfloat16mf4x5_t test_vlseg5e16_v_f16mf4x5_m(vbool64_t mask, const _Float16 *base, size_t vl) {
  return __riscv_vlseg5e16_v_f16mf4x5_m(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 5) @test_vlseg5e16_v_f16mf2x5_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 5) @llvm.riscv.vlseg5.mask.triscv.vector.tuple_nxv4i8_5t.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 5) poison, ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 5) [[TMP0]]
//
vfloat16mf2x5_t test_vlseg5e16_v_f16mf2x5_m(vbool32_t mask, const _Float16 *base, size_t vl) {
  return __riscv_vlseg5e16_v_f16mf2x5_m(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 5) @test_vlseg5e16_v_f16m1x5_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 5) @llvm.riscv.vlseg5.mask.triscv.vector.tuple_nxv8i8_5t.nxv4i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 5) poison, ptr [[BASE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 3, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 5) [[TMP0]]
//
vfloat16m1x5_t test_vlseg5e16_v_f16m1x5_m(vbool16_t mask, const _Float16 *base, size_t vl) {
  return __riscv_vlseg5e16_v_f16m1x5_m(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 5) @test_vlseg5e16_v_i16mf4x5_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 2 x i8>, 5) @llvm.riscv.vlseg5.mask.triscv.vector.tuple_nxv2i8_5t.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 5) poison, ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 5) [[TMP0]]
//
vint16mf4x5_t test_vlseg5e16_v_i16mf4x5_m(vbool64_t mask, const int16_t *base, size_t vl) {
  return __riscv_vlseg5e16_v_i16mf4x5_m(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 5) @test_vlseg5e16_v_i16mf2x5_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 5) @llvm.riscv.vlseg5.mask.triscv.vector.tuple_nxv4i8_5t.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 5) poison, ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 5) [[TMP0]]
//
vint16mf2x5_t test_vlseg5e16_v_i16mf2x5_m(vbool32_t mask, const int16_t *base, size_t vl) {
  return __riscv_vlseg5e16_v_i16mf2x5_m(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 5) @test_vlseg5e16_v_i16m1x5_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 5) @llvm.riscv.vlseg5.mask.triscv.vector.tuple_nxv8i8_5t.nxv4i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 5) poison, ptr [[BASE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 3, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 5) [[TMP0]]
//
vint16m1x5_t test_vlseg5e16_v_i16m1x5_m(vbool16_t mask, const int16_t *base, size_t vl) {
  return __riscv_vlseg5e16_v_i16m1x5_m(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 5) @test_vlseg5e16_v_u16mf4x5_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 2 x i8>, 5) @llvm.riscv.vlseg5.mask.triscv.vector.tuple_nxv2i8_5t.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 5) poison, ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 5) [[TMP0]]
//
vuint16mf4x5_t test_vlseg5e16_v_u16mf4x5_m(vbool64_t mask, const uint16_t *base, size_t vl) {
  return __riscv_vlseg5e16_v_u16mf4x5_m(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 5) @test_vlseg5e16_v_u16mf2x5_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 5) @llvm.riscv.vlseg5.mask.triscv.vector.tuple_nxv4i8_5t.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 5) poison, ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 5) [[TMP0]]
//
vuint16mf2x5_t test_vlseg5e16_v_u16mf2x5_m(vbool32_t mask, const uint16_t *base, size_t vl) {
  return __riscv_vlseg5e16_v_u16mf2x5_m(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 5) @test_vlseg5e16_v_u16m1x5_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 5) @llvm.riscv.vlseg5.mask.triscv.vector.tuple_nxv8i8_5t.nxv4i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 5) poison, ptr [[BASE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 3, i64 4)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 5) [[TMP0]]
//
vuint16m1x5_t test_vlseg5e16_v_u16m1x5_m(vbool16_t mask, const uint16_t *base, size_t vl) {
  return __riscv_vlseg5e16_v_u16m1x5_m(mask, base, vl);
}

