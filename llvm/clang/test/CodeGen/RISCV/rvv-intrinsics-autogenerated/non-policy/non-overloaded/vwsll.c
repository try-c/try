// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 2
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zvl512b \
// RUN:   -target-feature +zvbb \
// RUN:   -target-feature +zvbc \
// RUN:   -target-feature +zvkb \
// RUN:   -target-feature +zvkg \
// RUN:   -target-feature +zvkned \
// RUN:   -target-feature +zvknhb \
// RUN:   -target-feature +zvksed \
// RUN:   -target-feature +zvksh \
// RUN:   -disable-O0-optnone \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x i16> @test_vwsll_vv_u16mf4
// CHECK-RV64-SAME: (<vscale x 1 x i8> [[VS2:%.*]], <vscale x 1 x i8> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i16> @llvm.riscv.vwsll.nxv1i16.nxv1i8.nxv1i8.i64(<vscale x 1 x i16> poison, <vscale x 1 x i8> [[VS2]], <vscale x 1 x i8> [[VS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i16> [[TMP0]]
//
vuint16mf4_t test_vwsll_vv_u16mf4(vuint8mf8_t vs2, vuint8mf8_t vs1, size_t vl) {
  return __riscv_vwsll_vv_u16mf4(vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x i16> @test_vwsll_vx_u16mf4
// CHECK-RV64-SAME: (<vscale x 1 x i8> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i16> @llvm.riscv.vwsll.nxv1i16.nxv1i8.i64.i64(<vscale x 1 x i16> poison, <vscale x 1 x i8> [[VS2]], i64 [[RS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i16> [[TMP0]]
//
vuint16mf4_t test_vwsll_vx_u16mf4(vuint8mf8_t vs2, size_t rs1, size_t vl) {
  return __riscv_vwsll_vx_u16mf4(vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i16> @test_vwsll_vv_u16mf2
// CHECK-RV64-SAME: (<vscale x 2 x i8> [[VS2:%.*]], <vscale x 2 x i8> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i16> @llvm.riscv.vwsll.nxv2i16.nxv2i8.nxv2i8.i64(<vscale x 2 x i16> poison, <vscale x 2 x i8> [[VS2]], <vscale x 2 x i8> [[VS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i16> [[TMP0]]
//
vuint16mf2_t test_vwsll_vv_u16mf2(vuint8mf4_t vs2, vuint8mf4_t vs1, size_t vl) {
  return __riscv_vwsll_vv_u16mf2(vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i16> @test_vwsll_vx_u16mf2
// CHECK-RV64-SAME: (<vscale x 2 x i8> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i16> @llvm.riscv.vwsll.nxv2i16.nxv2i8.i64.i64(<vscale x 2 x i16> poison, <vscale x 2 x i8> [[VS2]], i64 [[RS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i16> [[TMP0]]
//
vuint16mf2_t test_vwsll_vx_u16mf2(vuint8mf4_t vs2, size_t rs1, size_t vl) {
  return __riscv_vwsll_vx_u16mf2(vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i16> @test_vwsll_vv_u16m1
// CHECK-RV64-SAME: (<vscale x 4 x i8> [[VS2:%.*]], <vscale x 4 x i8> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i16> @llvm.riscv.vwsll.nxv4i16.nxv4i8.nxv4i8.i64(<vscale x 4 x i16> poison, <vscale x 4 x i8> [[VS2]], <vscale x 4 x i8> [[VS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i16> [[TMP0]]
//
vuint16m1_t test_vwsll_vv_u16m1(vuint8mf2_t vs2, vuint8mf2_t vs1, size_t vl) {
  return __riscv_vwsll_vv_u16m1(vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i16> @test_vwsll_vx_u16m1
// CHECK-RV64-SAME: (<vscale x 4 x i8> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i16> @llvm.riscv.vwsll.nxv4i16.nxv4i8.i64.i64(<vscale x 4 x i16> poison, <vscale x 4 x i8> [[VS2]], i64 [[RS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i16> [[TMP0]]
//
vuint16m1_t test_vwsll_vx_u16m1(vuint8mf2_t vs2, size_t rs1, size_t vl) {
  return __riscv_vwsll_vx_u16m1(vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x i16> @test_vwsll_vv_u16m2
// CHECK-RV64-SAME: (<vscale x 8 x i8> [[VS2:%.*]], <vscale x 8 x i8> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i16> @llvm.riscv.vwsll.nxv8i16.nxv8i8.nxv8i8.i64(<vscale x 8 x i16> poison, <vscale x 8 x i8> [[VS2]], <vscale x 8 x i8> [[VS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x i16> [[TMP0]]
//
vuint16m2_t test_vwsll_vv_u16m2(vuint8m1_t vs2, vuint8m1_t vs1, size_t vl) {
  return __riscv_vwsll_vv_u16m2(vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x i16> @test_vwsll_vx_u16m2
// CHECK-RV64-SAME: (<vscale x 8 x i8> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i16> @llvm.riscv.vwsll.nxv8i16.nxv8i8.i64.i64(<vscale x 8 x i16> poison, <vscale x 8 x i8> [[VS2]], i64 [[RS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x i16> [[TMP0]]
//
vuint16m2_t test_vwsll_vx_u16m2(vuint8m1_t vs2, size_t rs1, size_t vl) {
  return __riscv_vwsll_vx_u16m2(vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x i16> @test_vwsll_vv_u16m4
// CHECK-RV64-SAME: (<vscale x 16 x i8> [[VS2:%.*]], <vscale x 16 x i8> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i16> @llvm.riscv.vwsll.nxv16i16.nxv16i8.nxv16i8.i64(<vscale x 16 x i16> poison, <vscale x 16 x i8> [[VS2]], <vscale x 16 x i8> [[VS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 16 x i16> [[TMP0]]
//
vuint16m4_t test_vwsll_vv_u16m4(vuint8m2_t vs2, vuint8m2_t vs1, size_t vl) {
  return __riscv_vwsll_vv_u16m4(vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x i16> @test_vwsll_vx_u16m4
// CHECK-RV64-SAME: (<vscale x 16 x i8> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i16> @llvm.riscv.vwsll.nxv16i16.nxv16i8.i64.i64(<vscale x 16 x i16> poison, <vscale x 16 x i8> [[VS2]], i64 [[RS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 16 x i16> [[TMP0]]
//
vuint16m4_t test_vwsll_vx_u16m4(vuint8m2_t vs2, size_t rs1, size_t vl) {
  return __riscv_vwsll_vx_u16m4(vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 32 x i16> @test_vwsll_vv_u16m8
// CHECK-RV64-SAME: (<vscale x 32 x i8> [[VS2:%.*]], <vscale x 32 x i8> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x i16> @llvm.riscv.vwsll.nxv32i16.nxv32i8.nxv32i8.i64(<vscale x 32 x i16> poison, <vscale x 32 x i8> [[VS2]], <vscale x 32 x i8> [[VS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 32 x i16> [[TMP0]]
//
vuint16m8_t test_vwsll_vv_u16m8(vuint8m4_t vs2, vuint8m4_t vs1, size_t vl) {
  return __riscv_vwsll_vv_u16m8(vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 32 x i16> @test_vwsll_vx_u16m8
// CHECK-RV64-SAME: (<vscale x 32 x i8> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x i16> @llvm.riscv.vwsll.nxv32i16.nxv32i8.i64.i64(<vscale x 32 x i16> poison, <vscale x 32 x i8> [[VS2]], i64 [[RS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 32 x i16> [[TMP0]]
//
vuint16m8_t test_vwsll_vx_u16m8(vuint8m4_t vs2, size_t rs1, size_t vl) {
  return __riscv_vwsll_vx_u16m8(vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x i32> @test_vwsll_vv_u32mf2
// CHECK-RV64-SAME: (<vscale x 1 x i16> [[VS2:%.*]], <vscale x 1 x i16> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i32> @llvm.riscv.vwsll.nxv1i32.nxv1i16.nxv1i16.i64(<vscale x 1 x i32> poison, <vscale x 1 x i16> [[VS2]], <vscale x 1 x i16> [[VS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i32> [[TMP0]]
//
vuint32mf2_t test_vwsll_vv_u32mf2(vuint16mf4_t vs2, vuint16mf4_t vs1, size_t vl) {
  return __riscv_vwsll_vv_u32mf2(vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x i32> @test_vwsll_vx_u32mf2
// CHECK-RV64-SAME: (<vscale x 1 x i16> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i32> @llvm.riscv.vwsll.nxv1i32.nxv1i16.i64.i64(<vscale x 1 x i32> poison, <vscale x 1 x i16> [[VS2]], i64 [[RS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i32> [[TMP0]]
//
vuint32mf2_t test_vwsll_vx_u32mf2(vuint16mf4_t vs2, size_t rs1, size_t vl) {
  return __riscv_vwsll_vx_u32mf2(vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i32> @test_vwsll_vv_u32m1
// CHECK-RV64-SAME: (<vscale x 2 x i16> [[VS2:%.*]], <vscale x 2 x i16> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.riscv.vwsll.nxv2i32.nxv2i16.nxv2i16.i64(<vscale x 2 x i32> poison, <vscale x 2 x i16> [[VS2]], <vscale x 2 x i16> [[VS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
vuint32m1_t test_vwsll_vv_u32m1(vuint16mf2_t vs2, vuint16mf2_t vs1, size_t vl) {
  return __riscv_vwsll_vv_u32m1(vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i32> @test_vwsll_vx_u32m1
// CHECK-RV64-SAME: (<vscale x 2 x i16> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.riscv.vwsll.nxv2i32.nxv2i16.i64.i64(<vscale x 2 x i32> poison, <vscale x 2 x i16> [[VS2]], i64 [[RS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
vuint32m1_t test_vwsll_vx_u32m1(vuint16mf2_t vs2, size_t rs1, size_t vl) {
  return __riscv_vwsll_vx_u32m1(vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i32> @test_vwsll_vv_u32m2
// CHECK-RV64-SAME: (<vscale x 4 x i16> [[VS2:%.*]], <vscale x 4 x i16> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i32> @llvm.riscv.vwsll.nxv4i32.nxv4i16.nxv4i16.i64(<vscale x 4 x i32> poison, <vscale x 4 x i16> [[VS2]], <vscale x 4 x i16> [[VS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
vuint32m2_t test_vwsll_vv_u32m2(vuint16m1_t vs2, vuint16m1_t vs1, size_t vl) {
  return __riscv_vwsll_vv_u32m2(vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i32> @test_vwsll_vx_u32m2
// CHECK-RV64-SAME: (<vscale x 4 x i16> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i32> @llvm.riscv.vwsll.nxv4i32.nxv4i16.i64.i64(<vscale x 4 x i32> poison, <vscale x 4 x i16> [[VS2]], i64 [[RS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
vuint32m2_t test_vwsll_vx_u32m2(vuint16m1_t vs2, size_t rs1, size_t vl) {
  return __riscv_vwsll_vx_u32m2(vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x i32> @test_vwsll_vv_u32m4
// CHECK-RV64-SAME: (<vscale x 8 x i16> [[VS2:%.*]], <vscale x 8 x i16> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i32> @llvm.riscv.vwsll.nxv8i32.nxv8i16.nxv8i16.i64(<vscale x 8 x i32> poison, <vscale x 8 x i16> [[VS2]], <vscale x 8 x i16> [[VS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x i32> [[TMP0]]
//
vuint32m4_t test_vwsll_vv_u32m4(vuint16m2_t vs2, vuint16m2_t vs1, size_t vl) {
  return __riscv_vwsll_vv_u32m4(vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x i32> @test_vwsll_vx_u32m4
// CHECK-RV64-SAME: (<vscale x 8 x i16> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i32> @llvm.riscv.vwsll.nxv8i32.nxv8i16.i64.i64(<vscale x 8 x i32> poison, <vscale x 8 x i16> [[VS2]], i64 [[RS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x i32> [[TMP0]]
//
vuint32m4_t test_vwsll_vx_u32m4(vuint16m2_t vs2, size_t rs1, size_t vl) {
  return __riscv_vwsll_vx_u32m4(vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x i32> @test_vwsll_vv_u32m8
// CHECK-RV64-SAME: (<vscale x 16 x i16> [[VS2:%.*]], <vscale x 16 x i16> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i32> @llvm.riscv.vwsll.nxv16i32.nxv16i16.nxv16i16.i64(<vscale x 16 x i32> poison, <vscale x 16 x i16> [[VS2]], <vscale x 16 x i16> [[VS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 16 x i32> [[TMP0]]
//
vuint32m8_t test_vwsll_vv_u32m8(vuint16m4_t vs2, vuint16m4_t vs1, size_t vl) {
  return __riscv_vwsll_vv_u32m8(vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x i32> @test_vwsll_vx_u32m8
// CHECK-RV64-SAME: (<vscale x 16 x i16> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i32> @llvm.riscv.vwsll.nxv16i32.nxv16i16.i64.i64(<vscale x 16 x i32> poison, <vscale x 16 x i16> [[VS2]], i64 [[RS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 16 x i32> [[TMP0]]
//
vuint32m8_t test_vwsll_vx_u32m8(vuint16m4_t vs2, size_t rs1, size_t vl) {
  return __riscv_vwsll_vx_u32m8(vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x i64> @test_vwsll_vv_u64m1
// CHECK-RV64-SAME: (<vscale x 1 x i32> [[VS2:%.*]], <vscale x 1 x i32> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vwsll.nxv1i64.nxv1i32.nxv1i32.i64(<vscale x 1 x i64> poison, <vscale x 1 x i32> [[VS2]], <vscale x 1 x i32> [[VS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vuint64m1_t test_vwsll_vv_u64m1(vuint32mf2_t vs2, vuint32mf2_t vs1, size_t vl) {
  return __riscv_vwsll_vv_u64m1(vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x i64> @test_vwsll_vx_u64m1
// CHECK-RV64-SAME: (<vscale x 1 x i32> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vwsll.nxv1i64.nxv1i32.i64.i64(<vscale x 1 x i64> poison, <vscale x 1 x i32> [[VS2]], i64 [[RS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vuint64m1_t test_vwsll_vx_u64m1(vuint32mf2_t vs2, size_t rs1, size_t vl) {
  return __riscv_vwsll_vx_u64m1(vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i64> @test_vwsll_vv_u64m2
// CHECK-RV64-SAME: (<vscale x 2 x i32> [[VS2:%.*]], <vscale x 2 x i32> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vwsll.nxv2i64.nxv2i32.nxv2i32.i64(<vscale x 2 x i64> poison, <vscale x 2 x i32> [[VS2]], <vscale x 2 x i32> [[VS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vuint64m2_t test_vwsll_vv_u64m2(vuint32m1_t vs2, vuint32m1_t vs1, size_t vl) {
  return __riscv_vwsll_vv_u64m2(vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i64> @test_vwsll_vx_u64m2
// CHECK-RV64-SAME: (<vscale x 2 x i32> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vwsll.nxv2i64.nxv2i32.i64.i64(<vscale x 2 x i64> poison, <vscale x 2 x i32> [[VS2]], i64 [[RS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vuint64m2_t test_vwsll_vx_u64m2(vuint32m1_t vs2, size_t rs1, size_t vl) {
  return __riscv_vwsll_vx_u64m2(vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i64> @test_vwsll_vv_u64m4
// CHECK-RV64-SAME: (<vscale x 4 x i32> [[VS2:%.*]], <vscale x 4 x i32> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vwsll.nxv4i64.nxv4i32.nxv4i32.i64(<vscale x 4 x i64> poison, <vscale x 4 x i32> [[VS2]], <vscale x 4 x i32> [[VS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vuint64m4_t test_vwsll_vv_u64m4(vuint32m2_t vs2, vuint32m2_t vs1, size_t vl) {
  return __riscv_vwsll_vv_u64m4(vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i64> @test_vwsll_vx_u64m4
// CHECK-RV64-SAME: (<vscale x 4 x i32> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vwsll.nxv4i64.nxv4i32.i64.i64(<vscale x 4 x i64> poison, <vscale x 4 x i32> [[VS2]], i64 [[RS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vuint64m4_t test_vwsll_vx_u64m4(vuint32m2_t vs2, size_t rs1, size_t vl) {
  return __riscv_vwsll_vx_u64m4(vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x i64> @test_vwsll_vv_u64m8
// CHECK-RV64-SAME: (<vscale x 8 x i32> [[VS2:%.*]], <vscale x 8 x i32> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vwsll.nxv8i64.nxv8i32.nxv8i32.i64(<vscale x 8 x i64> poison, <vscale x 8 x i32> [[VS2]], <vscale x 8 x i32> [[VS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP0]]
//
vuint64m8_t test_vwsll_vv_u64m8(vuint32m4_t vs2, vuint32m4_t vs1, size_t vl) {
  return __riscv_vwsll_vv_u64m8(vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x i64> @test_vwsll_vx_u64m8
// CHECK-RV64-SAME: (<vscale x 8 x i32> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vwsll.nxv8i64.nxv8i32.i64.i64(<vscale x 8 x i64> poison, <vscale x 8 x i32> [[VS2]], i64 [[RS1]], i64 [[VL]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP0]]
//
vuint64m8_t test_vwsll_vx_u64m8(vuint32m4_t vs2, size_t rs1, size_t vl) {
  return __riscv_vwsll_vx_u64m8(vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x i16> @test_vwsll_vv_u16mf4_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], <vscale x 1 x i8> [[VS2:%.*]], <vscale x 1 x i8> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i16> @llvm.riscv.vwsll.mask.nxv1i16.nxv1i8.nxv1i8.i64(<vscale x 1 x i16> poison, <vscale x 1 x i8> [[VS2]], <vscale x 1 x i8> [[VS1]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i16> [[TMP0]]
//
vuint16mf4_t test_vwsll_vv_u16mf4_m(vbool64_t mask, vuint8mf8_t vs2, vuint8mf8_t vs1, size_t vl) {
  return __riscv_vwsll_vv_u16mf4_m(mask, vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x i16> @test_vwsll_vx_u16mf4_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], <vscale x 1 x i8> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i16> @llvm.riscv.vwsll.mask.nxv1i16.nxv1i8.i64.i64(<vscale x 1 x i16> poison, <vscale x 1 x i8> [[VS2]], i64 [[RS1]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i16> [[TMP0]]
//
vuint16mf4_t test_vwsll_vx_u16mf4_m(vbool64_t mask, vuint8mf8_t vs2, size_t rs1, size_t vl) {
  return __riscv_vwsll_vx_u16mf4_m(mask, vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i16> @test_vwsll_vv_u16mf2_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], <vscale x 2 x i8> [[VS2:%.*]], <vscale x 2 x i8> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i16> @llvm.riscv.vwsll.mask.nxv2i16.nxv2i8.nxv2i8.i64(<vscale x 2 x i16> poison, <vscale x 2 x i8> [[VS2]], <vscale x 2 x i8> [[VS1]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i16> [[TMP0]]
//
vuint16mf2_t test_vwsll_vv_u16mf2_m(vbool32_t mask, vuint8mf4_t vs2, vuint8mf4_t vs1, size_t vl) {
  return __riscv_vwsll_vv_u16mf2_m(mask, vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i16> @test_vwsll_vx_u16mf2_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], <vscale x 2 x i8> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i16> @llvm.riscv.vwsll.mask.nxv2i16.nxv2i8.i64.i64(<vscale x 2 x i16> poison, <vscale x 2 x i8> [[VS2]], i64 [[RS1]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i16> [[TMP0]]
//
vuint16mf2_t test_vwsll_vx_u16mf2_m(vbool32_t mask, vuint8mf4_t vs2, size_t rs1, size_t vl) {
  return __riscv_vwsll_vx_u16mf2_m(mask, vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i16> @test_vwsll_vv_u16m1_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], <vscale x 4 x i8> [[VS2:%.*]], <vscale x 4 x i8> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i16> @llvm.riscv.vwsll.mask.nxv4i16.nxv4i8.nxv4i8.i64(<vscale x 4 x i16> poison, <vscale x 4 x i8> [[VS2]], <vscale x 4 x i8> [[VS1]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i16> [[TMP0]]
//
vuint16m1_t test_vwsll_vv_u16m1_m(vbool16_t mask, vuint8mf2_t vs2, vuint8mf2_t vs1, size_t vl) {
  return __riscv_vwsll_vv_u16m1_m(mask, vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i16> @test_vwsll_vx_u16m1_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], <vscale x 4 x i8> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i16> @llvm.riscv.vwsll.mask.nxv4i16.nxv4i8.i64.i64(<vscale x 4 x i16> poison, <vscale x 4 x i8> [[VS2]], i64 [[RS1]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i16> [[TMP0]]
//
vuint16m1_t test_vwsll_vx_u16m1_m(vbool16_t mask, vuint8mf2_t vs2, size_t rs1, size_t vl) {
  return __riscv_vwsll_vx_u16m1_m(mask, vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x i16> @test_vwsll_vv_u16m2_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], <vscale x 8 x i8> [[VS2:%.*]], <vscale x 8 x i8> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i16> @llvm.riscv.vwsll.mask.nxv8i16.nxv8i8.nxv8i8.i64(<vscale x 8 x i16> poison, <vscale x 8 x i8> [[VS2]], <vscale x 8 x i8> [[VS1]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i16> [[TMP0]]
//
vuint16m2_t test_vwsll_vv_u16m2_m(vbool8_t mask, vuint8m1_t vs2, vuint8m1_t vs1, size_t vl) {
  return __riscv_vwsll_vv_u16m2_m(mask, vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x i16> @test_vwsll_vx_u16m2_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], <vscale x 8 x i8> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i16> @llvm.riscv.vwsll.mask.nxv8i16.nxv8i8.i64.i64(<vscale x 8 x i16> poison, <vscale x 8 x i8> [[VS2]], i64 [[RS1]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i16> [[TMP0]]
//
vuint16m2_t test_vwsll_vx_u16m2_m(vbool8_t mask, vuint8m1_t vs2, size_t rs1, size_t vl) {
  return __riscv_vwsll_vx_u16m2_m(mask, vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x i16> @test_vwsll_vv_u16m4_m
// CHECK-RV64-SAME: (<vscale x 16 x i1> [[MASK:%.*]], <vscale x 16 x i8> [[VS2:%.*]], <vscale x 16 x i8> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i16> @llvm.riscv.vwsll.mask.nxv16i16.nxv16i8.nxv16i8.i64(<vscale x 16 x i16> poison, <vscale x 16 x i8> [[VS2]], <vscale x 16 x i8> [[VS1]], <vscale x 16 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 16 x i16> [[TMP0]]
//
vuint16m4_t test_vwsll_vv_u16m4_m(vbool4_t mask, vuint8m2_t vs2, vuint8m2_t vs1, size_t vl) {
  return __riscv_vwsll_vv_u16m4_m(mask, vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x i16> @test_vwsll_vx_u16m4_m
// CHECK-RV64-SAME: (<vscale x 16 x i1> [[MASK:%.*]], <vscale x 16 x i8> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i16> @llvm.riscv.vwsll.mask.nxv16i16.nxv16i8.i64.i64(<vscale x 16 x i16> poison, <vscale x 16 x i8> [[VS2]], i64 [[RS1]], <vscale x 16 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 16 x i16> [[TMP0]]
//
vuint16m4_t test_vwsll_vx_u16m4_m(vbool4_t mask, vuint8m2_t vs2, size_t rs1, size_t vl) {
  return __riscv_vwsll_vx_u16m4_m(mask, vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 32 x i16> @test_vwsll_vv_u16m8_m
// CHECK-RV64-SAME: (<vscale x 32 x i1> [[MASK:%.*]], <vscale x 32 x i8> [[VS2:%.*]], <vscale x 32 x i8> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x i16> @llvm.riscv.vwsll.mask.nxv32i16.nxv32i8.nxv32i8.i64(<vscale x 32 x i16> poison, <vscale x 32 x i8> [[VS2]], <vscale x 32 x i8> [[VS1]], <vscale x 32 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 32 x i16> [[TMP0]]
//
vuint16m8_t test_vwsll_vv_u16m8_m(vbool2_t mask, vuint8m4_t vs2, vuint8m4_t vs1, size_t vl) {
  return __riscv_vwsll_vv_u16m8_m(mask, vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 32 x i16> @test_vwsll_vx_u16m8_m
// CHECK-RV64-SAME: (<vscale x 32 x i1> [[MASK:%.*]], <vscale x 32 x i8> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x i16> @llvm.riscv.vwsll.mask.nxv32i16.nxv32i8.i64.i64(<vscale x 32 x i16> poison, <vscale x 32 x i8> [[VS2]], i64 [[RS1]], <vscale x 32 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 32 x i16> [[TMP0]]
//
vuint16m8_t test_vwsll_vx_u16m8_m(vbool2_t mask, vuint8m4_t vs2, size_t rs1, size_t vl) {
  return __riscv_vwsll_vx_u16m8_m(mask, vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x i32> @test_vwsll_vv_u32mf2_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], <vscale x 1 x i16> [[VS2:%.*]], <vscale x 1 x i16> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i32> @llvm.riscv.vwsll.mask.nxv1i32.nxv1i16.nxv1i16.i64(<vscale x 1 x i32> poison, <vscale x 1 x i16> [[VS2]], <vscale x 1 x i16> [[VS1]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i32> [[TMP0]]
//
vuint32mf2_t test_vwsll_vv_u32mf2_m(vbool64_t mask, vuint16mf4_t vs2, vuint16mf4_t vs1, size_t vl) {
  return __riscv_vwsll_vv_u32mf2_m(mask, vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x i32> @test_vwsll_vx_u32mf2_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], <vscale x 1 x i16> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i32> @llvm.riscv.vwsll.mask.nxv1i32.nxv1i16.i64.i64(<vscale x 1 x i32> poison, <vscale x 1 x i16> [[VS2]], i64 [[RS1]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i32> [[TMP0]]
//
vuint32mf2_t test_vwsll_vx_u32mf2_m(vbool64_t mask, vuint16mf4_t vs2, size_t rs1, size_t vl) {
  return __riscv_vwsll_vx_u32mf2_m(mask, vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i32> @test_vwsll_vv_u32m1_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], <vscale x 2 x i16> [[VS2:%.*]], <vscale x 2 x i16> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.riscv.vwsll.mask.nxv2i32.nxv2i16.nxv2i16.i64(<vscale x 2 x i32> poison, <vscale x 2 x i16> [[VS2]], <vscale x 2 x i16> [[VS1]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
vuint32m1_t test_vwsll_vv_u32m1_m(vbool32_t mask, vuint16mf2_t vs2, vuint16mf2_t vs1, size_t vl) {
  return __riscv_vwsll_vv_u32m1_m(mask, vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i32> @test_vwsll_vx_u32m1_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], <vscale x 2 x i16> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.riscv.vwsll.mask.nxv2i32.nxv2i16.i64.i64(<vscale x 2 x i32> poison, <vscale x 2 x i16> [[VS2]], i64 [[RS1]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
vuint32m1_t test_vwsll_vx_u32m1_m(vbool32_t mask, vuint16mf2_t vs2, size_t rs1, size_t vl) {
  return __riscv_vwsll_vx_u32m1_m(mask, vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i32> @test_vwsll_vv_u32m2_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], <vscale x 4 x i16> [[VS2:%.*]], <vscale x 4 x i16> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i32> @llvm.riscv.vwsll.mask.nxv4i32.nxv4i16.nxv4i16.i64(<vscale x 4 x i32> poison, <vscale x 4 x i16> [[VS2]], <vscale x 4 x i16> [[VS1]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
vuint32m2_t test_vwsll_vv_u32m2_m(vbool16_t mask, vuint16m1_t vs2, vuint16m1_t vs1, size_t vl) {
  return __riscv_vwsll_vv_u32m2_m(mask, vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i32> @test_vwsll_vx_u32m2_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], <vscale x 4 x i16> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i32> @llvm.riscv.vwsll.mask.nxv4i32.nxv4i16.i64.i64(<vscale x 4 x i32> poison, <vscale x 4 x i16> [[VS2]], i64 [[RS1]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
vuint32m2_t test_vwsll_vx_u32m2_m(vbool16_t mask, vuint16m1_t vs2, size_t rs1, size_t vl) {
  return __riscv_vwsll_vx_u32m2_m(mask, vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x i32> @test_vwsll_vv_u32m4_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], <vscale x 8 x i16> [[VS2:%.*]], <vscale x 8 x i16> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i32> @llvm.riscv.vwsll.mask.nxv8i32.nxv8i16.nxv8i16.i64(<vscale x 8 x i32> poison, <vscale x 8 x i16> [[VS2]], <vscale x 8 x i16> [[VS1]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i32> [[TMP0]]
//
vuint32m4_t test_vwsll_vv_u32m4_m(vbool8_t mask, vuint16m2_t vs2, vuint16m2_t vs1, size_t vl) {
  return __riscv_vwsll_vv_u32m4_m(mask, vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x i32> @test_vwsll_vx_u32m4_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], <vscale x 8 x i16> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i32> @llvm.riscv.vwsll.mask.nxv8i32.nxv8i16.i64.i64(<vscale x 8 x i32> poison, <vscale x 8 x i16> [[VS2]], i64 [[RS1]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i32> [[TMP0]]
//
vuint32m4_t test_vwsll_vx_u32m4_m(vbool8_t mask, vuint16m2_t vs2, size_t rs1, size_t vl) {
  return __riscv_vwsll_vx_u32m4_m(mask, vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x i32> @test_vwsll_vv_u32m8_m
// CHECK-RV64-SAME: (<vscale x 16 x i1> [[MASK:%.*]], <vscale x 16 x i16> [[VS2:%.*]], <vscale x 16 x i16> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i32> @llvm.riscv.vwsll.mask.nxv16i32.nxv16i16.nxv16i16.i64(<vscale x 16 x i32> poison, <vscale x 16 x i16> [[VS2]], <vscale x 16 x i16> [[VS1]], <vscale x 16 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 16 x i32> [[TMP0]]
//
vuint32m8_t test_vwsll_vv_u32m8_m(vbool4_t mask, vuint16m4_t vs2, vuint16m4_t vs1, size_t vl) {
  return __riscv_vwsll_vv_u32m8_m(mask, vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 16 x i32> @test_vwsll_vx_u32m8_m
// CHECK-RV64-SAME: (<vscale x 16 x i1> [[MASK:%.*]], <vscale x 16 x i16> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i32> @llvm.riscv.vwsll.mask.nxv16i32.nxv16i16.i64.i64(<vscale x 16 x i32> poison, <vscale x 16 x i16> [[VS2]], i64 [[RS1]], <vscale x 16 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 16 x i32> [[TMP0]]
//
vuint32m8_t test_vwsll_vx_u32m8_m(vbool4_t mask, vuint16m4_t vs2, size_t rs1, size_t vl) {
  return __riscv_vwsll_vx_u32m8_m(mask, vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x i64> @test_vwsll_vv_u64m1_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], <vscale x 1 x i32> [[VS2:%.*]], <vscale x 1 x i32> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vwsll.mask.nxv1i64.nxv1i32.nxv1i32.i64(<vscale x 1 x i64> poison, <vscale x 1 x i32> [[VS2]], <vscale x 1 x i32> [[VS1]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vuint64m1_t test_vwsll_vv_u64m1_m(vbool64_t mask, vuint32mf2_t vs2, vuint32mf2_t vs1, size_t vl) {
  return __riscv_vwsll_vv_u64m1_m(mask, vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 1 x i64> @test_vwsll_vx_u64m1_m
// CHECK-RV64-SAME: (<vscale x 1 x i1> [[MASK:%.*]], <vscale x 1 x i32> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vwsll.mask.nxv1i64.nxv1i32.i64.i64(<vscale x 1 x i64> poison, <vscale x 1 x i32> [[VS2]], i64 [[RS1]], <vscale x 1 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vuint64m1_t test_vwsll_vx_u64m1_m(vbool64_t mask, vuint32mf2_t vs2, size_t rs1, size_t vl) {
  return __riscv_vwsll_vx_u64m1_m(mask, vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i64> @test_vwsll_vv_u64m2_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], <vscale x 2 x i32> [[VS2:%.*]], <vscale x 2 x i32> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vwsll.mask.nxv2i64.nxv2i32.nxv2i32.i64(<vscale x 2 x i64> poison, <vscale x 2 x i32> [[VS2]], <vscale x 2 x i32> [[VS1]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vuint64m2_t test_vwsll_vv_u64m2_m(vbool32_t mask, vuint32m1_t vs2, vuint32m1_t vs1, size_t vl) {
  return __riscv_vwsll_vv_u64m2_m(mask, vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 2 x i64> @test_vwsll_vx_u64m2_m
// CHECK-RV64-SAME: (<vscale x 2 x i1> [[MASK:%.*]], <vscale x 2 x i32> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vwsll.mask.nxv2i64.nxv2i32.i64.i64(<vscale x 2 x i64> poison, <vscale x 2 x i32> [[VS2]], i64 [[RS1]], <vscale x 2 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vuint64m2_t test_vwsll_vx_u64m2_m(vbool32_t mask, vuint32m1_t vs2, size_t rs1, size_t vl) {
  return __riscv_vwsll_vx_u64m2_m(mask, vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i64> @test_vwsll_vv_u64m4_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], <vscale x 4 x i32> [[VS2:%.*]], <vscale x 4 x i32> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vwsll.mask.nxv4i64.nxv4i32.nxv4i32.i64(<vscale x 4 x i64> poison, <vscale x 4 x i32> [[VS2]], <vscale x 4 x i32> [[VS1]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vuint64m4_t test_vwsll_vv_u64m4_m(vbool16_t mask, vuint32m2_t vs2, vuint32m2_t vs1, size_t vl) {
  return __riscv_vwsll_vv_u64m4_m(mask, vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i64> @test_vwsll_vx_u64m4_m
// CHECK-RV64-SAME: (<vscale x 4 x i1> [[MASK:%.*]], <vscale x 4 x i32> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vwsll.mask.nxv4i64.nxv4i32.i64.i64(<vscale x 4 x i64> poison, <vscale x 4 x i32> [[VS2]], i64 [[RS1]], <vscale x 4 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vuint64m4_t test_vwsll_vx_u64m4_m(vbool16_t mask, vuint32m2_t vs2, size_t rs1, size_t vl) {
  return __riscv_vwsll_vx_u64m4_m(mask, vs2, rs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x i64> @test_vwsll_vv_u64m8_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], <vscale x 8 x i32> [[VS2:%.*]], <vscale x 8 x i32> [[VS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vwsll.mask.nxv8i64.nxv8i32.nxv8i32.i64(<vscale x 8 x i64> poison, <vscale x 8 x i32> [[VS2]], <vscale x 8 x i32> [[VS1]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP0]]
//
vuint64m8_t test_vwsll_vv_u64m8_m(vbool8_t mask, vuint32m4_t vs2, vuint32m4_t vs1, size_t vl) {
  return __riscv_vwsll_vv_u64m8_m(mask, vs2, vs1, vl);
}

// CHECK-RV64-LABEL: define dso_local <vscale x 8 x i64> @test_vwsll_vx_u64m8_m
// CHECK-RV64-SAME: (<vscale x 8 x i1> [[MASK:%.*]], <vscale x 8 x i32> [[VS2:%.*]], i64 noundef [[RS1:%.*]], i64 noundef [[VL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vwsll.mask.nxv8i64.nxv8i32.i64.i64(<vscale x 8 x i64> poison, <vscale x 8 x i32> [[VS2]], i64 [[RS1]], <vscale x 8 x i1> [[MASK]], i64 [[VL]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP0]]
//
vuint64m8_t test_vwsll_vx_u64m8_m(vbool8_t mask, vuint32m4_t vs2, size_t rs1, size_t vl) {
  return __riscv_vwsll_vx_u64m8_m(mask, vs2, rs1, vl);
}

