// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 2
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +zvfh -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 1 x i8>, 6) @test_vlseg6e8ff_v_i8mf8x6
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { target("riscv.vector.tuple", <vscale x 1 x i8>, 6), i64 } @llvm.riscv.vlseg6ff.triscv.vector.tuple_nxv1i8_6t.i64(target("riscv.vector.tuple", <vscale x 1 x i8>, 6) poison, ptr [[BASE]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 1 x i8>, 6), i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 1 x i8>, 6), i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 1 x i8>, 6) [[TMP1]]
//
vint8mf8x6_t test_vlseg6e8ff_v_i8mf8x6(const int8_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vlseg6e8ff_v_i8mf8x6(base, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 6) @test_vlseg6e8ff_v_i8mf4x6
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { target("riscv.vector.tuple", <vscale x 2 x i8>, 6), i64 } @llvm.riscv.vlseg6ff.triscv.vector.tuple_nxv2i8_6t.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 6) poison, ptr [[BASE]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 2 x i8>, 6), i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 2 x i8>, 6), i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 6) [[TMP1]]
//
vint8mf4x6_t test_vlseg6e8ff_v_i8mf4x6(const int8_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vlseg6e8ff_v_i8mf4x6(base, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 6) @test_vlseg6e8ff_v_i8mf2x6
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { target("riscv.vector.tuple", <vscale x 4 x i8>, 6), i64 } @llvm.riscv.vlseg6ff.triscv.vector.tuple_nxv4i8_6t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 6) poison, ptr [[BASE]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 4 x i8>, 6), i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 4 x i8>, 6), i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 6) [[TMP1]]
//
vint8mf2x6_t test_vlseg6e8ff_v_i8mf2x6(const int8_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vlseg6e8ff_v_i8mf2x6(base, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @test_vlseg6e8ff_v_i8m1x6
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { target("riscv.vector.tuple", <vscale x 8 x i8>, 6), i64 } @llvm.riscv.vlseg6ff.triscv.vector.tuple_nxv8i8_6t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 6) poison, ptr [[BASE]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 8 x i8>, 6), i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 8 x i8>, 6), i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[TMP1]]
//
vint8m1x6_t test_vlseg6e8ff_v_i8m1x6(const int8_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vlseg6e8ff_v_i8m1x6(base, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 1 x i8>, 6) @test_vlseg6e8ff_v_u8mf8x6
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { target("riscv.vector.tuple", <vscale x 1 x i8>, 6), i64 } @llvm.riscv.vlseg6ff.triscv.vector.tuple_nxv1i8_6t.i64(target("riscv.vector.tuple", <vscale x 1 x i8>, 6) poison, ptr [[BASE]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 1 x i8>, 6), i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 1 x i8>, 6), i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 1 x i8>, 6) [[TMP1]]
//
vuint8mf8x6_t test_vlseg6e8ff_v_u8mf8x6(const uint8_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vlseg6e8ff_v_u8mf8x6(base, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 6) @test_vlseg6e8ff_v_u8mf4x6
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { target("riscv.vector.tuple", <vscale x 2 x i8>, 6), i64 } @llvm.riscv.vlseg6ff.triscv.vector.tuple_nxv2i8_6t.i64(target("riscv.vector.tuple", <vscale x 2 x i8>, 6) poison, ptr [[BASE]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 2 x i8>, 6), i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 2 x i8>, 6), i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 6) [[TMP1]]
//
vuint8mf4x6_t test_vlseg6e8ff_v_u8mf4x6(const uint8_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vlseg6e8ff_v_u8mf4x6(base, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 6) @test_vlseg6e8ff_v_u8mf2x6
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { target("riscv.vector.tuple", <vscale x 4 x i8>, 6), i64 } @llvm.riscv.vlseg6ff.triscv.vector.tuple_nxv4i8_6t.i64(target("riscv.vector.tuple", <vscale x 4 x i8>, 6) poison, ptr [[BASE]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 4 x i8>, 6), i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 4 x i8>, 6), i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 6) [[TMP1]]
//
vuint8mf2x6_t test_vlseg6e8ff_v_u8mf2x6(const uint8_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vlseg6e8ff_v_u8mf2x6(base, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @test_vlseg6e8ff_v_u8m1x6
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { target("riscv.vector.tuple", <vscale x 8 x i8>, 6), i64 } @llvm.riscv.vlseg6ff.triscv.vector.tuple_nxv8i8_6t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 6) poison, ptr [[BASE]], i64 [[VL]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 8 x i8>, 6), i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 8 x i8>, 6), i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[TMP1]]
//
vuint8m1x6_t test_vlseg6e8ff_v_u8m1x6(const uint8_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vlseg6e8ff_v_u8m1x6(base, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 1 x i8>, 6) @test_vlseg6e8ff_v_i8mf8x6_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { target("riscv.vector.tuple", <vscale x 1 x i8>, 6), i64 } @llvm.riscv.vlseg6ff.mask.triscv.vector.tuple_nxv1i8_6t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 1 x i8>, 6) poison, ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3, i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 1 x i8>, 6), i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 1 x i8>, 6), i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 1 x i8>, 6) [[TMP1]]
//
vint8mf8x6_t test_vlseg6e8ff_v_i8mf8x6_m(vbool64_t mask, const int8_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vlseg6e8ff_v_i8mf8x6_m(mask, base, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 6) @test_vlseg6e8ff_v_i8mf4x6_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { target("riscv.vector.tuple", <vscale x 2 x i8>, 6), i64 } @llvm.riscv.vlseg6ff.mask.triscv.vector.tuple_nxv2i8_6t.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 2 x i8>, 6) poison, ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3, i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 2 x i8>, 6), i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 2 x i8>, 6), i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 6) [[TMP1]]
//
vint8mf4x6_t test_vlseg6e8ff_v_i8mf4x6_m(vbool32_t mask, const int8_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vlseg6e8ff_v_i8mf4x6_m(mask, base, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 6) @test_vlseg6e8ff_v_i8mf2x6_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { target("riscv.vector.tuple", <vscale x 4 x i8>, 6), i64 } @llvm.riscv.vlseg6ff.mask.triscv.vector.tuple_nxv4i8_6t.i64.nxv4i1(target("riscv.vector.tuple", <vscale x 4 x i8>, 6) poison, ptr [[BASE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 3, i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 4 x i8>, 6), i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 4 x i8>, 6), i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 6) [[TMP1]]
//
vint8mf2x6_t test_vlseg6e8ff_v_i8mf2x6_m(vbool16_t mask, const int8_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vlseg6e8ff_v_i8mf2x6_m(mask, base, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @test_vlseg6e8ff_v_i8m1x6_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { target("riscv.vector.tuple", <vscale x 8 x i8>, 6), i64 } @llvm.riscv.vlseg6ff.mask.triscv.vector.tuple_nxv8i8_6t.i64.nxv8i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 6) poison, ptr [[BASE]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 3, i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 8 x i8>, 6), i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 8 x i8>, 6), i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[TMP1]]
//
vint8m1x6_t test_vlseg6e8ff_v_i8m1x6_m(vbool8_t mask, const int8_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vlseg6e8ff_v_i8m1x6_m(mask, base, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 1 x i8>, 6) @test_vlseg6e8ff_v_u8mf8x6_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { target("riscv.vector.tuple", <vscale x 1 x i8>, 6), i64 } @llvm.riscv.vlseg6ff.mask.triscv.vector.tuple_nxv1i8_6t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 1 x i8>, 6) poison, ptr [[BASE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3, i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 1 x i8>, 6), i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 1 x i8>, 6), i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 1 x i8>, 6) [[TMP1]]
//
vuint8mf8x6_t test_vlseg6e8ff_v_u8mf8x6_m(vbool64_t mask, const uint8_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vlseg6e8ff_v_u8mf8x6_m(mask, base, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 2 x i8>, 6) @test_vlseg6e8ff_v_u8mf4x6_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { target("riscv.vector.tuple", <vscale x 2 x i8>, 6), i64 } @llvm.riscv.vlseg6ff.mask.triscv.vector.tuple_nxv2i8_6t.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 2 x i8>, 6) poison, ptr [[BASE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3, i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 2 x i8>, 6), i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 2 x i8>, 6), i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 2 x i8>, 6) [[TMP1]]
//
vuint8mf4x6_t test_vlseg6e8ff_v_u8mf4x6_m(vbool32_t mask, const uint8_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vlseg6e8ff_v_u8mf4x6_m(mask, base, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 4 x i8>, 6) @test_vlseg6e8ff_v_u8mf2x6_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { target("riscv.vector.tuple", <vscale x 4 x i8>, 6), i64 } @llvm.riscv.vlseg6ff.mask.triscv.vector.tuple_nxv4i8_6t.i64.nxv4i1(target("riscv.vector.tuple", <vscale x 4 x i8>, 6) poison, ptr [[BASE]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 3, i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 4 x i8>, 6), i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 4 x i8>, 6), i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 4 x i8>, 6) [[TMP1]]
//
vuint8mf2x6_t test_vlseg6e8ff_v_u8mf2x6_m(vbool16_t mask, const uint8_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vlseg6e8ff_v_u8mf2x6_m(mask, base, new_vl, vl);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 8 x i8>, 6) @test_vlseg6e8ff_v_u8m1x6_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], ptr noundef [[NEW_VL:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { target("riscv.vector.tuple", <vscale x 8 x i8>, 6), i64 } @llvm.riscv.vlseg6ff.mask.triscv.vector.tuple_nxv8i8_6t.i64.nxv8i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 6) poison, ptr [[BASE]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 3, i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 8 x i8>, 6), i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { target("riscv.vector.tuple", <vscale x 8 x i8>, 6), i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL]], align 8
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 8 x i8>, 6) [[TMP1]]
//
vuint8m1x6_t test_vlseg6e8ff_v_u8m1x6_m(vbool8_t mask, const uint8_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vlseg6e8ff_v_u8m1x6_m(mask, base, new_vl, vl);
}

