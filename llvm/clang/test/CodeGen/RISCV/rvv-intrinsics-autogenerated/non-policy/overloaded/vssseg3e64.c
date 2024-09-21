// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 2
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +zvfh -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local void @test_vssseg3e64_v_f64m1x3
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg3.triscv.vector.tuple_nxv8i8_3t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[V_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 6)
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg3e64_v_f64m1x3(double *base, ptrdiff_t bstride, vfloat64m1x3_t v_tuple, size_t vl) {
  return __riscv_vssseg3e64(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg3e64_v_f64m2x3
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg3.triscv.vector.tuple_nxv16i8_3t.i64(target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[V_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 6)
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg3e64_v_f64m2x3(double *base, ptrdiff_t bstride, vfloat64m2x3_t v_tuple, size_t vl) {
  return __riscv_vssseg3e64(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg3e64_v_i64m1x3
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg3.triscv.vector.tuple_nxv8i8_3t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[V_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 6)
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg3e64_v_i64m1x3(int64_t *base, ptrdiff_t bstride, vint64m1x3_t v_tuple, size_t vl) {
  return __riscv_vssseg3e64(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg3e64_v_i64m2x3
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg3.triscv.vector.tuple_nxv16i8_3t.i64(target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[V_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 6)
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg3e64_v_i64m2x3(int64_t *base, ptrdiff_t bstride, vint64m2x3_t v_tuple, size_t vl) {
  return __riscv_vssseg3e64(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg3e64_v_u64m1x3
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg3.triscv.vector.tuple_nxv8i8_3t.i64(target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[V_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 6)
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg3e64_v_u64m1x3(uint64_t *base, ptrdiff_t bstride, vuint64m1x3_t v_tuple, size_t vl) {
  return __riscv_vssseg3e64(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg3e64_v_u64m2x3
// CHECK-RV64-SAME: (ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg3.triscv.vector.tuple_nxv16i8_3t.i64(target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[V_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], i64 [[VL]], i64 6)
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg3e64_v_u64m2x3(uint64_t *base, ptrdiff_t bstride, vuint64m2x3_t v_tuple, size_t vl) {
  return __riscv_vssseg3e64(base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg3e64_v_f64m1x3_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg3.mask.triscv.vector.tuple_nxv8i8_3t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[V_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 6)
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg3e64_v_f64m1x3_m(vbool64_t mask, double *base, ptrdiff_t bstride, vfloat64m1x3_t v_tuple, size_t vl) {
  return __riscv_vssseg3e64(mask, base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg3e64_v_f64m2x3_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg3.mask.triscv.vector.tuple_nxv16i8_3t.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[V_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 6)
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg3e64_v_f64m2x3_m(vbool32_t mask, double *base, ptrdiff_t bstride, vfloat64m2x3_t v_tuple, size_t vl) {
  return __riscv_vssseg3e64(mask, base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg3e64_v_i64m1x3_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg3.mask.triscv.vector.tuple_nxv8i8_3t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[V_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 6)
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg3e64_v_i64m1x3_m(vbool64_t mask, int64_t *base, ptrdiff_t bstride, vint64m1x3_t v_tuple, size_t vl) {
  return __riscv_vssseg3e64(mask, base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg3e64_v_i64m2x3_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg3.mask.triscv.vector.tuple_nxv16i8_3t.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[V_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 6)
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg3e64_v_i64m2x3_m(vbool32_t mask, int64_t *base, ptrdiff_t bstride, vint64m2x3_t v_tuple, size_t vl) {
  return __riscv_vssseg3e64(mask, base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg3e64_v_u64m1x3_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg3.mask.triscv.vector.tuple_nxv8i8_3t.i64.nxv1i1(target("riscv.vector.tuple", <vscale x 8 x i8>, 3) [[V_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 6)
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg3e64_v_u64m1x3_m(vbool64_t mask, uint64_t *base, ptrdiff_t bstride, vuint64m1x3_t v_tuple, size_t vl) {
  return __riscv_vssseg3e64(mask, base, bstride, v_tuple, vl);
}

// CHECK-RV64-LABEL: define dso_local void @test_vssseg3e64_v_u64m2x3_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], ptr noundef [[BASE:%.*]], i64 noundef [[BSTRIDE:%.*]], target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[V_TUPLE:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg3.mask.triscv.vector.tuple_nxv16i8_3t.i64.nxv2i1(target("riscv.vector.tuple", <vscale x 16 x i8>, 3) [[V_TUPLE]], ptr [[BASE]], i64 [[BSTRIDE]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 6)
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg3e64_v_u64m2x3_m(vbool32_t mask, uint64_t *base, ptrdiff_t bstride, vuint64m2x3_t v_tuple, size_t vl) {
  return __riscv_vssseg3e64(mask, base, bstride, v_tuple, vl);
}

