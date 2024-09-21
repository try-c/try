// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 2
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +zvfh -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 6) @test_vlseg6e32_v_f32mf2x6
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 6) @llvm.riscv.vlseg6.triscv.vector.tuple_nxv4i8_6t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 6) poison, ptr [[BASE]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 6) [[TMP0]]
//
vfloat32mf2x6_t test_vlseg6e32_v_f32mf2x6(const float *base, size_t vl) {
  return __riscv_vlseg6e32_v_f32mf2x6(base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @test_vlseg6e32_v_f32m1x6
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @llvm.riscv.vlseg6.triscv.vector.tuple_nxv8i8_6t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 6) poison, ptr [[BASE]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[TMP0]]
//
vfloat32m1x6_t test_vlseg6e32_v_f32m1x6(const float *base, size_t vl) {
  return __riscv_vlseg6e32_v_f32m1x6(base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 6) @test_vlseg6e32_v_i32mf2x6
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 6) @llvm.riscv.vlseg6.triscv.vector.tuple_nxv4i8_6t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 6) poison, ptr [[BASE]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 6) [[TMP0]]
//
vint32mf2x6_t test_vlseg6e32_v_i32mf2x6(const int32_t *base, size_t vl) {
  return __riscv_vlseg6e32_v_i32mf2x6(base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @test_vlseg6e32_v_i32m1x6
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @llvm.riscv.vlseg6.triscv.vector.tuple_nxv8i8_6t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 6) poison, ptr [[BASE]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[TMP0]]
//
vint32m1x6_t test_vlseg6e32_v_i32m1x6(const int32_t *base, size_t vl) {
  return __riscv_vlseg6e32_v_i32m1x6(base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 6) @test_vlseg6e32_v_u32mf2x6
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 6) @llvm.riscv.vlseg6.triscv.vector.tuple_nxv4i8_6t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 6) poison, ptr [[BASE]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 6) [[TMP0]]
//
vuint32mf2x6_t test_vlseg6e32_v_u32mf2x6(const uint32_t *base, size_t vl) {
  return __riscv_vlseg6e32_v_u32mf2x6(base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @test_vlseg6e32_v_u32m1x6
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @llvm.riscv.vlseg6.triscv.vector.tuple_nxv8i8_6t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 6) poison, ptr [[BASE]], i64 [[VL]], i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[TMP0]]
//
vuint32m1x6_t test_vlseg6e32_v_u32m1x6(const uint32_t *base, size_t vl) {
  return __riscv_vlseg6e32_v_u32m1x6(base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 6) @test_vlseg6e32_v_f32mf2x6_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 6) @llvm.riscv.vlseg6.mask.triscv.vector.tuple_nxv4i8_6t.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 6) poison, ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 6) [[TMP0]]
//
vfloat32mf2x6_t test_vlseg6e32_v_f32mf2x6_m(vbool64_t mask, const float *base, size_t vl) {
  return __riscv_vlseg6e32_v_f32mf2x6_m(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @test_vlseg6e32_v_f32m1x6_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @llvm.riscv.vlseg6.mask.triscv.vector.tuple_nxv8i8_6t.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 6) poison, ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[TMP0]]
//
vfloat32m1x6_t test_vlseg6e32_v_f32m1x6_m(vbool32_t mask, const float *base, size_t vl) {
  return __riscv_vlseg6e32_v_f32m1x6_m(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 6) @test_vlseg6e32_v_i32mf2x6_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 6) @llvm.riscv.vlseg6.mask.triscv.vector.tuple_nxv4i8_6t.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 6) poison, ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 6) [[TMP0]]
//
vint32mf2x6_t test_vlseg6e32_v_i32mf2x6_m(vbool64_t mask, const int32_t *base, size_t vl) {
  return __riscv_vlseg6e32_v_i32mf2x6_m(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @test_vlseg6e32_v_i32m1x6_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @llvm.riscv.vlseg6.mask.triscv.vector.tuple_nxv8i8_6t.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 6) poison, ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[TMP0]]
//
vint32m1x6_t test_vlseg6e32_v_i32m1x6_m(vbool32_t mask, const int32_t *base, size_t vl) {
  return __riscv_vlseg6e32_v_i32m1x6_m(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 6) @test_vlseg6e32_v_u32mf2x6_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 4 x i8>, 6) @llvm.riscv.vlseg6.mask.triscv.vector.tuple_nxv4i8_6t.nxv1i1.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 6) poison, ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 6) [[TMP0]]
//
vuint32mf2x6_t test_vlseg6e32_v_u32mf2x6_m(vbool64_t mask, const uint32_t *base, size_t vl) {
  return __riscv_vlseg6e32_v_u32mf2x6_m(mask, base, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @test_vlseg6e32_v_u32m1x6_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @llvm.riscv.vlseg6.mask.triscv.vector.tuple_nxv8i8_6t.nxv2i1.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 6) poison, ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3, i64 5)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[TMP0]]
//
vuint32m1x6_t test_vlseg6e32_v_u32m1x6_m(vbool32_t mask, const uint32_t *base, size_t vl) {
  return __riscv_vlseg6e32_v_u32m1x6_m(mask, base, vl);
}

