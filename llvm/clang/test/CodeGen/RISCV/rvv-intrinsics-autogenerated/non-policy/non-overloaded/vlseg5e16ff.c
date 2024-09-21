// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 2
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +zvfhmin -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 5) @test_vlseg5e16ff_v_f16mf4x5
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { target("riscv.vector.tuple", <vscale x 2 x i8>, 5), i64 } @llvm.riscv.vlseg5ff.triscv.vector.tuple_nxv2i8_5t.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 5) poison, ptr [[BASE]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 2 x i8>, 5), i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 2 x i8>, 5), i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 5) [[TMP1]]
//
vfloat16mf4x5_t test_vlseg5e16ff_v_f16mf4x5(const _Float16 *base, size_t *new_vl, size_t vl) {
  return __riscv_vlseg5e16ff_v_f16mf4x5(base, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 5) @test_vlseg5e16ff_v_f16mf2x5
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { target("riscv.vector.tuple", <vscale x 4 x i8>, 5), i64 } @llvm.riscv.vlseg5ff.triscv.vector.tuple_nxv4i8_5t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 5) poison, ptr [[BASE]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 4 x i8>, 5), i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 4 x i8>, 5), i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 5) [[TMP1]]
//
vfloat16mf2x5_t test_vlseg5e16ff_v_f16mf2x5(const _Float16 *base, size_t *new_vl, size_t vl) {
  return __riscv_vlseg5e16ff_v_f16mf2x5(base, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 5) @test_vlseg5e16ff_v_f16m1x5
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { target("riscv.vector.tuple", <vscale x 8 x i8>, 5), i64 } @llvm.riscv.vlseg5ff.triscv.vector.tuple_nxv8i8_5t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 5) poison, ptr [[BASE]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 8 x i8>, 5), i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 8 x i8>, 5), i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 5) [[TMP1]]
//
vfloat16m1x5_t test_vlseg5e16ff_v_f16m1x5(const _Float16 *base, size_t *new_vl, size_t vl) {
  return __riscv_vlseg5e16ff_v_f16m1x5(base, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 5) @test_vlseg5e16ff_v_i16mf4x5
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { target("riscv.vector.tuple", <vscale x 2 x i8>, 5), i64 } @llvm.riscv.vlseg5ff.triscv.vector.tuple_nxv2i8_5t.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 5) poison, ptr [[BASE]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 2 x i8>, 5), i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 2 x i8>, 5), i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 5) [[TMP1]]
//
vint16mf4x5_t test_vlseg5e16ff_v_i16mf4x5(const int16_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vlseg5e16ff_v_i16mf4x5(base, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 5) @test_vlseg5e16ff_v_i16mf2x5
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { target("riscv.vector.tuple", <vscale x 4 x i8>, 5), i64 } @llvm.riscv.vlseg5ff.triscv.vector.tuple_nxv4i8_5t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 5) poison, ptr [[BASE]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 4 x i8>, 5), i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 4 x i8>, 5), i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 5) [[TMP1]]
//
vint16mf2x5_t test_vlseg5e16ff_v_i16mf2x5(const int16_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vlseg5e16ff_v_i16mf2x5(base, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 5) @test_vlseg5e16ff_v_i16m1x5
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { target("riscv.vector.tuple", <vscale x 8 x i8>, 5), i64 } @llvm.riscv.vlseg5ff.triscv.vector.tuple_nxv8i8_5t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 5) poison, ptr [[BASE]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 8 x i8>, 5), i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 8 x i8>, 5), i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 5) [[TMP1]]
//
vint16m1x5_t test_vlseg5e16ff_v_i16m1x5(const int16_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vlseg5e16ff_v_i16m1x5(base, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 5) @test_vlseg5e16ff_v_u16mf4x5
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { target("riscv.vector.tuple", <vscale x 2 x i8>, 5), i64 } @llvm.riscv.vlseg5ff.triscv.vector.tuple_nxv2i8_5t.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 5) poison, ptr [[BASE]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 2 x i8>, 5), i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 2 x i8>, 5), i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 5) [[TMP1]]
//
vuint16mf4x5_t test_vlseg5e16ff_v_u16mf4x5(const uint16_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vlseg5e16ff_v_u16mf4x5(base, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 5) @test_vlseg5e16ff_v_u16mf2x5
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { target("riscv.vector.tuple", <vscale x 4 x i8>, 5), i64 } @llvm.riscv.vlseg5ff.triscv.vector.tuple_nxv4i8_5t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 5) poison, ptr [[BASE]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 4 x i8>, 5), i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 4 x i8>, 5), i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 5) [[TMP1]]
//
vuint16mf2x5_t test_vlseg5e16ff_v_u16mf2x5(const uint16_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vlseg5e16ff_v_u16mf2x5(base, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 5) @test_vlseg5e16ff_v_u16m1x5
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { target("riscv.vector.tuple", <vscale x 8 x i8>, 5), i64 } @llvm.riscv.vlseg5ff.triscv.vector.tuple_nxv8i8_5t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 5) poison, ptr [[BASE]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 8 x i8>, 5), i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 8 x i8>, 5), i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 5) [[TMP1]]
//
vuint16m1x5_t test_vlseg5e16ff_v_u16m1x5(const uint16_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vlseg5e16ff_v_u16m1x5(base, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 5) @test_vlseg5e16ff_v_f16mf4x5_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { target("riscv.vector.tuple", <vscale x 2 x i8>, 5), i64 } @llvm.riscv.vlseg5ff.mask.triscv.vector.tuple_nxv2i8_5t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 2 x i8>, 5) poison, ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3, i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 2 x i8>, 5), i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 2 x i8>, 5), i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 5) [[TMP1]]
//
vfloat16mf4x5_t test_vlseg5e16ff_v_f16mf4x5_m(vbool64_t mask, const _Float16 *base, size_t *new_vl, size_t vl) {
  return __riscv_vlseg5e16ff_v_f16mf4x5_m(mask, base, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 5) @test_vlseg5e16ff_v_f16mf2x5_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { target("riscv.vector.tuple", <vscale x 4 x i8>, 5), i64 } @llvm.riscv.vlseg5ff.mask.triscv.vector.tuple_nxv4i8_5t.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 4 x i8>, 5) poison, ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3, i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 4 x i8>, 5), i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 4 x i8>, 5), i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 5) [[TMP1]]
//
vfloat16mf2x5_t test_vlseg5e16ff_v_f16mf2x5_m(vbool32_t mask, const _Float16 *base, size_t *new_vl, size_t vl) {
  return __riscv_vlseg5e16ff_v_f16mf2x5_m(mask, base, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 5) @test_vlseg5e16ff_v_f16m1x5_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { target("riscv.vector.tuple", <vscale x 8 x i8>, 5), i64 } @llvm.riscv.vlseg5ff.mask.triscv.vector.tuple_nxv8i8_5t.i64.nxv4i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 5) poison, ptr [[BASE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 3, i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 8 x i8>, 5), i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 8 x i8>, 5), i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 5) [[TMP1]]
//
vfloat16m1x5_t test_vlseg5e16ff_v_f16m1x5_m(vbool16_t mask, const _Float16 *base, size_t *new_vl, size_t vl) {
  return __riscv_vlseg5e16ff_v_f16m1x5_m(mask, base, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 5) @test_vlseg5e16ff_v_i16mf4x5_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { target("riscv.vector.tuple", <vscale x 2 x i8>, 5), i64 } @llvm.riscv.vlseg5ff.mask.triscv.vector.tuple_nxv2i8_5t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 2 x i8>, 5) poison, ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3, i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 2 x i8>, 5), i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 2 x i8>, 5), i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 5) [[TMP1]]
//
vint16mf4x5_t test_vlseg5e16ff_v_i16mf4x5_m(vbool64_t mask, const int16_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vlseg5e16ff_v_i16mf4x5_m(mask, base, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 5) @test_vlseg5e16ff_v_i16mf2x5_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { target("riscv.vector.tuple", <vscale x 4 x i8>, 5), i64 } @llvm.riscv.vlseg5ff.mask.triscv.vector.tuple_nxv4i8_5t.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 4 x i8>, 5) poison, ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3, i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 4 x i8>, 5), i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 4 x i8>, 5), i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 5) [[TMP1]]
//
vint16mf2x5_t test_vlseg5e16ff_v_i16mf2x5_m(vbool32_t mask, const int16_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vlseg5e16ff_v_i16mf2x5_m(mask, base, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 5) @test_vlseg5e16ff_v_i16m1x5_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { target("riscv.vector.tuple", <vscale x 8 x i8>, 5), i64 } @llvm.riscv.vlseg5ff.mask.triscv.vector.tuple_nxv8i8_5t.i64.nxv4i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 5) poison, ptr [[BASE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 3, i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 8 x i8>, 5), i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 8 x i8>, 5), i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 5) [[TMP1]]
//
vint16m1x5_t test_vlseg5e16ff_v_i16m1x5_m(vbool16_t mask, const int16_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vlseg5e16ff_v_i16m1x5_m(mask, base, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 5) @test_vlseg5e16ff_v_u16mf4x5_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { target("riscv.vector.tuple", <vscale x 2 x i8>, 5), i64 } @llvm.riscv.vlseg5ff.mask.triscv.vector.tuple_nxv2i8_5t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 2 x i8>, 5) poison, ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3, i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 2 x i8>, 5), i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 2 x i8>, 5), i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 5) [[TMP1]]
//
vuint16mf4x5_t test_vlseg5e16ff_v_u16mf4x5_m(vbool64_t mask, const uint16_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vlseg5e16ff_v_u16mf4x5_m(mask, base, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 5) @test_vlseg5e16ff_v_u16mf2x5_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { target("riscv.vector.tuple", <vscale x 4 x i8>, 5), i64 } @llvm.riscv.vlseg5ff.mask.triscv.vector.tuple_nxv4i8_5t.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 4 x i8>, 5) poison, ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3, i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 4 x i8>, 5), i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 4 x i8>, 5), i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 5) [[TMP1]]
//
vuint16mf2x5_t test_vlseg5e16ff_v_u16mf2x5_m(vbool32_t mask, const uint16_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vlseg5e16ff_v_u16mf2x5_m(mask, base, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 5) @test_vlseg5e16ff_v_u16m1x5_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { target("riscv.vector.tuple", <vscale x 8 x i8>, 5), i64 } @llvm.riscv.vlseg5ff.mask.triscv.vector.tuple_nxv8i8_5t.i64.nxv4i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 5) poison, ptr [[BASE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 3, i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 8 x i8>, 5), i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 8 x i8>, 5), i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 5) [[TMP1]]
//
vuint16m1x5_t test_vlseg5e16ff_v_u16m1x5_m(vbool16_t mask, const uint16_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vlseg5e16ff_v_u16m1x5_m(mask, base, new_vl, vl);
}

