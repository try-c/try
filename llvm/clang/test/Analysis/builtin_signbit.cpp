// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 3
// RUN: %clang_cc1 -triple powerpc-linux-gnu -emit-llvm \
// RUN:   -O0 %s -o - | FileCheck %s --check-prefixes=CHECK-BE32
// RUN: %clang_cc1 -triple powerpc64-linux-gnu -emit-llvm \
// RUN:   -O0 %s -o - | FileCheck %s --check-prefixes=CHECK-BE64
// RUN: %clang_cc1 -triple powerpc64le-linux-gnu -emit-llvm \
// RUN:   -O0 %s -o - | FileCheck %s --check-prefixes=CHECK-LE

bool b;
double d = -1.0;
long double ld = -1.0L;
// CHECK-BE32-LABEL: define dso_local void @_Z12test_signbitv(
// CHECK-BE32-SAME: ) #[[ATTR0:[0-9]+]] {
// CHECK-BE32-NEXT:  entry:
// CHECK-BE32-NEXT:    store i8 0, ptr @b, align 1
// CHECK-BE32-NEXT:    [[TMP0:%.*]] = load ppc_fp128, ptr @ld, align 16
// CHECK-BE32-NEXT:    [[TMP1:%.*]] = bitcast ppc_fp128 [[TMP0]] to i128
// CHECK-BE32-NEXT:    [[TMP2:%.*]] = lshr i128 [[TMP1]], 64
// CHECK-BE32-NEXT:    [[TMP3:%.*]] = trunc i128 [[TMP2]] to i64
// CHECK-BE32-NEXT:    [[TMP4:%.*]] = icmp slt i64 [[TMP3]], 0
// CHECK-BE32-NEXT:    [[FROMBOOL:%.*]] = zext i1 [[TMP4]] to i8
// CHECK-BE32-NEXT:    store i8 [[FROMBOOL]], ptr @b, align 1
// CHECK-BE32-NEXT:    store i8 0, ptr @b, align 1
// CHECK-BE32-NEXT:    [[TMP5:%.*]] = load double, ptr @d, align 8
// CHECK-BE32-NEXT:    [[CONV:%.*]] = fptrunc double [[TMP5]] to float
// CHECK-BE32-NEXT:    [[TMP6:%.*]] = bitcast float [[CONV]] to i32
// CHECK-BE32-NEXT:    [[TMP7:%.*]] = icmp slt i32 [[TMP6]], 0
// CHECK-BE32-NEXT:    [[FROMBOOL1:%.*]] = zext i1 [[TMP7]] to i8
// CHECK-BE32-NEXT:    store i8 [[FROMBOOL1]], ptr @b, align 1
// CHECK-BE32-NEXT:    store i8 0, ptr @b, align 1
// CHECK-BE32-NEXT:    [[TMP8:%.*]] = load ppc_fp128, ptr @ld, align 16
// CHECK-BE32-NEXT:    [[TMP9:%.*]] = bitcast ppc_fp128 [[TMP8]] to i128
// CHECK-BE32-NEXT:    [[TMP10:%.*]] = lshr i128 [[TMP9]], 64
// CHECK-BE32-NEXT:    [[TMP11:%.*]] = trunc i128 [[TMP10]] to i64
// CHECK-BE32-NEXT:    [[TMP12:%.*]] = icmp slt i64 [[TMP11]], 0
// CHECK-BE32-NEXT:    [[FROMBOOL2:%.*]] = zext i1 [[TMP12]] to i8
// CHECK-BE32-NEXT:    store i8 [[FROMBOOL2]], ptr @b, align 1
// CHECK-BE32-NEXT:    ret void
//
// CHECK-BE64-LABEL: define dso_local void @_Z12test_signbitv(
// CHECK-BE64-SAME: ) #[[ATTR0:[0-9]+]] {
// CHECK-BE64-NEXT:  entry:
// CHECK-BE64-NEXT:    store i8 0, ptr @b, align 1
// CHECK-BE64-NEXT:    [[TMP0:%.*]] = load ppc_fp128, ptr @ld, align 16
// CHECK-BE64-NEXT:    [[TMP1:%.*]] = bitcast ppc_fp128 [[TMP0]] to i128
// CHECK-BE64-NEXT:    [[TMP2:%.*]] = lshr i128 [[TMP1]], 64
// CHECK-BE64-NEXT:    [[TMP3:%.*]] = trunc i128 [[TMP2]] to i64
// CHECK-BE64-NEXT:    [[TMP4:%.*]] = icmp slt i64 [[TMP3]], 0
// CHECK-BE64-NEXT:    [[FROMBOOL:%.*]] = zext i1 [[TMP4]] to i8
// CHECK-BE64-NEXT:    store i8 [[FROMBOOL]], ptr @b, align 1
// CHECK-BE64-NEXT:    store i8 0, ptr @b, align 1
// CHECK-BE64-NEXT:    [[TMP5:%.*]] = load double, ptr @d, align 8
// CHECK-BE64-NEXT:    [[CONV:%.*]] = fptrunc double [[TMP5]] to float
// CHECK-BE64-NEXT:    [[TMP6:%.*]] = bitcast float [[CONV]] to i32
// CHECK-BE64-NEXT:    [[TMP7:%.*]] = icmp slt i32 [[TMP6]], 0
// CHECK-BE64-NEXT:    [[FROMBOOL1:%.*]] = zext i1 [[TMP7]] to i8
// CHECK-BE64-NEXT:    store i8 [[FROMBOOL1]], ptr @b, align 1
// CHECK-BE64-NEXT:    store i8 0, ptr @b, align 1
// CHECK-BE64-NEXT:    [[TMP8:%.*]] = load ppc_fp128, ptr @ld, align 16
// CHECK-BE64-NEXT:    [[TMP9:%.*]] = bitcast ppc_fp128 [[TMP8]] to i128
// CHECK-BE64-NEXT:    [[TMP10:%.*]] = lshr i128 [[TMP9]], 64
// CHECK-BE64-NEXT:    [[TMP11:%.*]] = trunc i128 [[TMP10]] to i64
// CHECK-BE64-NEXT:    [[TMP12:%.*]] = icmp slt i64 [[TMP11]], 0
// CHECK-BE64-NEXT:    [[FROMBOOL2:%.*]] = zext i1 [[TMP12]] to i8
// CHECK-BE64-NEXT:    store i8 [[FROMBOOL2]], ptr @b, align 1
// CHECK-BE64-NEXT:    ret void
//
// CHECK-LE-LABEL: define dso_local void @_Z12test_signbitv(
// CHECK-LE-SAME: ) #[[ATTR0:[0-9]+]] {
// CHECK-LE-NEXT:  entry:
// CHECK-LE-NEXT:    store i8 0, ptr @b, align 1
// CHECK-LE-NEXT:    [[TMP0:%.*]] = load ppc_fp128, ptr @ld, align 16
// CHECK-LE-NEXT:    [[TMP1:%.*]] = bitcast ppc_fp128 [[TMP0]] to i128
// CHECK-LE-NEXT:    [[TMP2:%.*]] = trunc i128 [[TMP1]] to i64
// CHECK-LE-NEXT:    [[TMP3:%.*]] = icmp slt i64 [[TMP2]], 0
// CHECK-LE-NEXT:    [[FROMBOOL:%.*]] = zext i1 [[TMP3]] to i8
// CHECK-LE-NEXT:    store i8 [[FROMBOOL]], ptr @b, align 1
// CHECK-LE-NEXT:    store i8 0, ptr @b, align 1
// CHECK-LE-NEXT:    [[TMP4:%.*]] = load double, ptr @d, align 8
// CHECK-LE-NEXT:    [[CONV:%.*]] = fptrunc double [[TMP4]] to float
// CHECK-LE-NEXT:    [[TMP5:%.*]] = bitcast float [[CONV]] to i32
// CHECK-LE-NEXT:    [[TMP6:%.*]] = icmp slt i32 [[TMP5]], 0
// CHECK-LE-NEXT:    [[FROMBOOL1:%.*]] = zext i1 [[TMP6]] to i8
// CHECK-LE-NEXT:    store i8 [[FROMBOOL1]], ptr @b, align 1
// CHECK-LE-NEXT:    store i8 0, ptr @b, align 1
// CHECK-LE-NEXT:    [[TMP7:%.*]] = load ppc_fp128, ptr @ld, align 16
// CHECK-LE-NEXT:    [[TMP8:%.*]] = bitcast ppc_fp128 [[TMP7]] to i128
// CHECK-LE-NEXT:    [[TMP9:%.*]] = trunc i128 [[TMP8]] to i64
// CHECK-LE-NEXT:    [[TMP10:%.*]] = icmp slt i64 [[TMP9]], 0
// CHECK-LE-NEXT:    [[FROMBOOL2:%.*]] = zext i1 [[TMP10]] to i8
// CHECK-LE-NEXT:    store i8 [[FROMBOOL2]], ptr @b, align 1
// CHECK-LE-NEXT:    ret void
//
void test_signbit()
{
  b = __builtin_signbit(1.0L);

  b = __builtin_signbit(ld);

  b = __builtin_signbitf(1.0);

  b = __builtin_signbitf(d);

  b = __builtin_signbitl(1.0L);

  b = __builtin_signbitl(ld);
}
