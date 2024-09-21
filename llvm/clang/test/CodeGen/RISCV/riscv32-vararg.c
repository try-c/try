// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 2
// RUN: %clang_cc1 -triple riscv32 -emit-llvm %s -o - | FileCheck %s
// RUN: %clang_cc1 -triple riscv32 -target-feature +f -target-abi ilp32f -emit-llvm %s -o - \
// RUN:     | FileCheck %s -check-prefixes=CHECK,CHECK-ILP32F
// RUN: %clang_cc1 -triple riscv32 -target-feature +d -target-feature +f -target-abi ilp32d -emit-llvm %s -o - \
// RUN:     | FileCheck %s -check-prefixes=CHECK,CHECK-ILP32D
// RUN: %clang_cc1 -triple riscv32 -target-abi ilp32e -emit-llvm %s -o - \
// RUN:     | FileCheck %s -check-prefixes=CHECK,CHECK-ILP32E

#include <stddef.h>
#include <stdint.h>

struct tiny {
  uint8_t a, b, c, d;
};
struct small {
  int32_t a, *b;
};
struct small_aligned {
  int64_t a;
};
struct large {
  int32_t a, b, c, d;
};

// Ensure that ABI lowering happens as expected for vararg calls. For RV32
// with the base integer calling convention there will be no observable
// differences in the lowered IR for a call with varargs vs without.

int f_va_callee(int, ...);

// CHECK-LABEL: define dso_local void @f_va_caller
// CHECK-SAME: () #[[ATTR0:[0-9]+]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[DOTCOMPOUNDLITERAL:%.*]] = alloca [[STRUCT_TINY:%.*]], align 1
// CHECK-NEXT:    [[DOTCOMPOUNDLITERAL1:%.*]] = alloca [[STRUCT_SMALL:%.*]], align 4
// CHECK-NEXT:    [[DOTCOMPOUNDLITERAL4:%.*]] = alloca [[STRUCT_SMALL_ALIGNED:%.*]], align 8
// CHECK-NEXT:    [[DOTCOMPOUNDLITERAL6:%.*]] = alloca [[STRUCT_LARGE:%.*]], align 4
// CHECK-NEXT:    [[BYVAL_TEMP:%.*]] = alloca [[STRUCT_LARGE]], align 4
// CHECK-NEXT:    [[A:%.*]] = getelementptr inbounds nuw [[STRUCT_TINY]], ptr [[DOTCOMPOUNDLITERAL]], i32 0, i32 0
// CHECK-NEXT:    store i8 6, ptr [[A]], align 1
// CHECK-NEXT:    [[B:%.*]] = getelementptr inbounds nuw [[STRUCT_TINY]], ptr [[DOTCOMPOUNDLITERAL]], i32 0, i32 1
// CHECK-NEXT:    store i8 7, ptr [[B]], align 1
// CHECK-NEXT:    [[C:%.*]] = getelementptr inbounds nuw [[STRUCT_TINY]], ptr [[DOTCOMPOUNDLITERAL]], i32 0, i32 2
// CHECK-NEXT:    store i8 8, ptr [[C]], align 1
// CHECK-NEXT:    [[D:%.*]] = getelementptr inbounds nuw [[STRUCT_TINY]], ptr [[DOTCOMPOUNDLITERAL]], i32 0, i32 3
// CHECK-NEXT:    store i8 9, ptr [[D]], align 1
// CHECK-NEXT:    [[A2:%.*]] = getelementptr inbounds nuw [[STRUCT_SMALL]], ptr [[DOTCOMPOUNDLITERAL1]], i32 0, i32 0
// CHECK-NEXT:    store i32 10, ptr [[A2]], align 4
// CHECK-NEXT:    [[B3:%.*]] = getelementptr inbounds nuw [[STRUCT_SMALL]], ptr [[DOTCOMPOUNDLITERAL1]], i32 0, i32 1
// CHECK-NEXT:    store ptr null, ptr [[B3]], align 4
// CHECK-NEXT:    [[A5:%.*]] = getelementptr inbounds nuw [[STRUCT_SMALL_ALIGNED]], ptr [[DOTCOMPOUNDLITERAL4]], i32 0, i32 0
// CHECK-NEXT:    store i64 11, ptr [[A5]], align 8
// CHECK-NEXT:    [[A7:%.*]] = getelementptr inbounds nuw [[STRUCT_LARGE]], ptr [[DOTCOMPOUNDLITERAL6]], i32 0, i32 0
// CHECK-NEXT:    store i32 12, ptr [[A7]], align 4
// CHECK-NEXT:    [[B8:%.*]] = getelementptr inbounds nuw [[STRUCT_LARGE]], ptr [[DOTCOMPOUNDLITERAL6]], i32 0, i32 1
// CHECK-NEXT:    store i32 13, ptr [[B8]], align 4
// CHECK-NEXT:    [[C9:%.*]] = getelementptr inbounds nuw [[STRUCT_LARGE]], ptr [[DOTCOMPOUNDLITERAL6]], i32 0, i32 2
// CHECK-NEXT:    store i32 14, ptr [[C9]], align 4
// CHECK-NEXT:    [[D10:%.*]] = getelementptr inbounds nuw [[STRUCT_LARGE]], ptr [[DOTCOMPOUNDLITERAL6]], i32 0, i32 3
// CHECK-NEXT:    store i32 15, ptr [[D10]], align 4
// CHECK-NEXT:    [[TMP0:%.*]] = load i32, ptr [[DOTCOMPOUNDLITERAL]], align 1
// CHECK-NEXT:    [[TMP1:%.*]] = load [2 x i32], ptr [[DOTCOMPOUNDLITERAL1]], align 4
// CHECK-NEXT:    [[COERCE_DIVE:%.*]] = getelementptr inbounds nuw [[STRUCT_SMALL_ALIGNED]], ptr [[DOTCOMPOUNDLITERAL4]], i32 0, i32 0
// CHECK-NEXT:    [[TMP2:%.*]] = load i64, ptr [[COERCE_DIVE]], align 8
// CHECK-NEXT:    call void @llvm.memcpy.p0.p0.i32(ptr align 4 [[BYVAL_TEMP]], ptr align 4 [[DOTCOMPOUNDLITERAL6]], i32 16, i1 false)
// CHECK-NEXT:    [[CALL:%.*]] = call i32 (i32, ...) @f_va_callee(i32 noundef 1, i32 noundef 2, i64 noundef 3, double noundef 4.000000e+00, double noundef 5.000000e+00, i32 [[TMP0]], [2 x i32] [[TMP1]], i64 [[TMP2]], ptr noundef [[BYVAL_TEMP]])
// CHECK-NEXT:    ret void
//
void f_va_caller(void) {
  f_va_callee(1, 2, 3LL, 4.0f, 5.0, (struct tiny){6, 7, 8, 9},
              (struct small){10, NULL}, (struct small_aligned){11},
              (struct large){12, 13, 14, 15});
}

// CHECK-LABEL: define dso_local i32 @f_va_1
// CHECK-SAME: (ptr noundef [[FMT:%.*]], ...) #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[FMT_ADDR:%.*]] = alloca ptr, align 4
// CHECK-NEXT:    [[VA:%.*]] = alloca ptr, align 4
// CHECK-NEXT:    [[V:%.*]] = alloca i32, align 4
// CHECK-NEXT:    store ptr [[FMT]], ptr [[FMT_ADDR]], align 4
// CHECK-NEXT:    call void @llvm.va_start.p0(ptr [[VA]])
// CHECK-NEXT:    [[ARGP_CUR:%.*]] = load ptr, ptr [[VA]], align 4
// CHECK-NEXT:    [[ARGP_NEXT:%.*]] = getelementptr inbounds i8, ptr [[ARGP_CUR]], i32 4
// CHECK-NEXT:    store ptr [[ARGP_NEXT]], ptr [[VA]], align 4
// CHECK-NEXT:    [[TMP0:%.*]] = load i32, ptr [[ARGP_CUR]], align 4
// CHECK-NEXT:    store i32 [[TMP0]], ptr [[V]], align 4
// CHECK-NEXT:    call void @llvm.va_end.p0(ptr [[VA]])
// CHECK-NEXT:    [[TMP1:%.*]] = load i32, ptr [[V]], align 4
// CHECK-NEXT:    ret i32 [[TMP1]]
//
int f_va_1(char *fmt, ...) {
  __builtin_va_list va;

  __builtin_va_start(va, fmt);
  int v = __builtin_va_arg(va, int);
  __builtin_va_end(va);

  return v;
}

// An "aligned" register pair (where the first register is even-numbered) is
// used to pass varargs with 2x xlen alignment and 2x xlen size. Ensure the
// correct offsets are used.

// CHECK-ILP32F-LABEL: define dso_local double @f_va_2
// CHECK-ILP32F-SAME: (ptr noundef [[FMT:%.*]], ...) #[[ATTR0]] {
// CHECK-ILP32F-NEXT:  entry:
// CHECK-ILP32F-NEXT:    [[FMT_ADDR:%.*]] = alloca ptr, align 4
// CHECK-ILP32F-NEXT:    [[VA:%.*]] = alloca ptr, align 4
// CHECK-ILP32F-NEXT:    [[V:%.*]] = alloca double, align 8
// CHECK-ILP32F-NEXT:    store ptr [[FMT]], ptr [[FMT_ADDR]], align 4
// CHECK-ILP32F-NEXT:    call void @llvm.va_start.p0(ptr [[VA]])
// CHECK-ILP32F-NEXT:    [[ARGP_CUR:%.*]] = load ptr, ptr [[VA]], align 4
// CHECK-ILP32F-NEXT:    [[TMP0:%.*]] = getelementptr inbounds i8, ptr [[ARGP_CUR]], i32 7
// CHECK-ILP32F-NEXT:    [[ARGP_CUR_ALIGNED:%.*]] = call ptr @llvm.ptrmask.p0.i32(ptr [[TMP0]], i32 -8)
// CHECK-ILP32F-NEXT:    [[ARGP_NEXT:%.*]] = getelementptr inbounds i8, ptr [[ARGP_CUR_ALIGNED]], i32 8
// CHECK-ILP32F-NEXT:    store ptr [[ARGP_NEXT]], ptr [[VA]], align 4
// CHECK-ILP32F-NEXT:    [[TMP1:%.*]] = load double, ptr [[ARGP_CUR_ALIGNED]], align 8
// CHECK-ILP32F-NEXT:    store double [[TMP1]], ptr [[V]], align 8
// CHECK-ILP32F-NEXT:    call void @llvm.va_end.p0(ptr [[VA]])
// CHECK-ILP32F-NEXT:    [[TMP2:%.*]] = load double, ptr [[V]], align 8
// CHECK-ILP32F-NEXT:    ret double [[TMP2]]
//
// CHECK-ILP32D-LABEL: define dso_local double @f_va_2
// CHECK-ILP32D-SAME: (ptr noundef [[FMT:%.*]], ...) #[[ATTR0]] {
// CHECK-ILP32D-NEXT:  entry:
// CHECK-ILP32D-NEXT:    [[FMT_ADDR:%.*]] = alloca ptr, align 4
// CHECK-ILP32D-NEXT:    [[VA:%.*]] = alloca ptr, align 4
// CHECK-ILP32D-NEXT:    [[V:%.*]] = alloca double, align 8
// CHECK-ILP32D-NEXT:    store ptr [[FMT]], ptr [[FMT_ADDR]], align 4
// CHECK-ILP32D-NEXT:    call void @llvm.va_start.p0(ptr [[VA]])
// CHECK-ILP32D-NEXT:    [[ARGP_CUR:%.*]] = load ptr, ptr [[VA]], align 4
// CHECK-ILP32D-NEXT:    [[TMP0:%.*]] = getelementptr inbounds i8, ptr [[ARGP_CUR]], i32 7
// CHECK-ILP32D-NEXT:    [[ARGP_CUR_ALIGNED:%.*]] = call ptr @llvm.ptrmask.p0.i32(ptr [[TMP0]], i32 -8)
// CHECK-ILP32D-NEXT:    [[ARGP_NEXT:%.*]] = getelementptr inbounds i8, ptr [[ARGP_CUR_ALIGNED]], i32 8
// CHECK-ILP32D-NEXT:    store ptr [[ARGP_NEXT]], ptr [[VA]], align 4
// CHECK-ILP32D-NEXT:    [[TMP1:%.*]] = load double, ptr [[ARGP_CUR_ALIGNED]], align 8
// CHECK-ILP32D-NEXT:    store double [[TMP1]], ptr [[V]], align 8
// CHECK-ILP32D-NEXT:    call void @llvm.va_end.p0(ptr [[VA]])
// CHECK-ILP32D-NEXT:    [[TMP2:%.*]] = load double, ptr [[V]], align 8
// CHECK-ILP32D-NEXT:    ret double [[TMP2]]
//
// CHECK-ILP32E-LABEL: define dso_local double @f_va_2
// CHECK-ILP32E-SAME: (ptr noundef [[FMT:%.*]], ...) #[[ATTR0]] {
// CHECK-ILP32E-NEXT:  entry:
// CHECK-ILP32E-NEXT:    [[FMT_ADDR:%.*]] = alloca ptr, align 4
// CHECK-ILP32E-NEXT:    [[VA:%.*]] = alloca ptr, align 4
// CHECK-ILP32E-NEXT:    [[V:%.*]] = alloca double, align 8
// CHECK-ILP32E-NEXT:    store ptr [[FMT]], ptr [[FMT_ADDR]], align 4
// CHECK-ILP32E-NEXT:    call void @llvm.va_start.p0(ptr [[VA]])
// CHECK-ILP32E-NEXT:    [[ARGP_CUR:%.*]] = load ptr, ptr [[VA]], align 4
// CHECK-ILP32E-NEXT:    [[ARGP_NEXT:%.*]] = getelementptr inbounds i8, ptr [[ARGP_CUR]], i32 8
// CHECK-ILP32E-NEXT:    store ptr [[ARGP_NEXT]], ptr [[VA]], align 4
// CHECK-ILP32E-NEXT:    [[TMP0:%.*]] = load double, ptr [[ARGP_CUR]], align 4
// CHECK-ILP32E-NEXT:    store double [[TMP0]], ptr [[V]], align 8
// CHECK-ILP32E-NEXT:    call void @llvm.va_end.p0(ptr [[VA]])
// CHECK-ILP32E-NEXT:    [[TMP1:%.*]] = load double, ptr [[V]], align 8
// CHECK-ILP32E-NEXT:    ret double [[TMP1]]
//
double f_va_2(char *fmt, ...) {
  __builtin_va_list va;

  __builtin_va_start(va, fmt);
  double v = __builtin_va_arg(va, double);
  __builtin_va_end(va);

  return v;
}

// Two "aligned" register pairs.

// CHECK-ILP32F-LABEL: define dso_local double @f_va_3
// CHECK-ILP32F-SAME: (ptr noundef [[FMT:%.*]], ...) #[[ATTR0]] {
// CHECK-ILP32F-NEXT:  entry:
// CHECK-ILP32F-NEXT:    [[FMT_ADDR:%.*]] = alloca ptr, align 4
// CHECK-ILP32F-NEXT:    [[VA:%.*]] = alloca ptr, align 4
// CHECK-ILP32F-NEXT:    [[V:%.*]] = alloca double, align 8
// CHECK-ILP32F-NEXT:    [[W:%.*]] = alloca i32, align 4
// CHECK-ILP32F-NEXT:    [[X:%.*]] = alloca double, align 8
// CHECK-ILP32F-NEXT:    store ptr [[FMT]], ptr [[FMT_ADDR]], align 4
// CHECK-ILP32F-NEXT:    call void @llvm.va_start.p0(ptr [[VA]])
// CHECK-ILP32F-NEXT:    [[ARGP_CUR:%.*]] = load ptr, ptr [[VA]], align 4
// CHECK-ILP32F-NEXT:    [[TMP0:%.*]] = getelementptr inbounds i8, ptr [[ARGP_CUR]], i32 7
// CHECK-ILP32F-NEXT:    [[ARGP_CUR_ALIGNED:%.*]] = call ptr @llvm.ptrmask.p0.i32(ptr [[TMP0]], i32 -8)
// CHECK-ILP32F-NEXT:    [[ARGP_NEXT:%.*]] = getelementptr inbounds i8, ptr [[ARGP_CUR_ALIGNED]], i32 8
// CHECK-ILP32F-NEXT:    store ptr [[ARGP_NEXT]], ptr [[VA]], align 4
// CHECK-ILP32F-NEXT:    [[TMP1:%.*]] = load double, ptr [[ARGP_CUR_ALIGNED]], align 8
// CHECK-ILP32F-NEXT:    store double [[TMP1]], ptr [[V]], align 8
// CHECK-ILP32F-NEXT:    [[ARGP_CUR1:%.*]] = load ptr, ptr [[VA]], align 4
// CHECK-ILP32F-NEXT:    [[ARGP_NEXT2:%.*]] = getelementptr inbounds i8, ptr [[ARGP_CUR1]], i32 4
// CHECK-ILP32F-NEXT:    store ptr [[ARGP_NEXT2]], ptr [[VA]], align 4
// CHECK-ILP32F-NEXT:    [[TMP2:%.*]] = load i32, ptr [[ARGP_CUR1]], align 4
// CHECK-ILP32F-NEXT:    store i32 [[TMP2]], ptr [[W]], align 4
// CHECK-ILP32F-NEXT:    [[ARGP_CUR3:%.*]] = load ptr, ptr [[VA]], align 4
// CHECK-ILP32F-NEXT:    [[TMP3:%.*]] = getelementptr inbounds i8, ptr [[ARGP_CUR3]], i32 7
// CHECK-ILP32F-NEXT:    [[ARGP_CUR3_ALIGNED:%.*]] = call ptr @llvm.ptrmask.p0.i32(ptr [[TMP3]], i32 -8)
// CHECK-ILP32F-NEXT:    [[ARGP_NEXT4:%.*]] = getelementptr inbounds i8, ptr [[ARGP_CUR3_ALIGNED]], i32 8
// CHECK-ILP32F-NEXT:    store ptr [[ARGP_NEXT4]], ptr [[VA]], align 4
// CHECK-ILP32F-NEXT:    [[TMP4:%.*]] = load double, ptr [[ARGP_CUR3_ALIGNED]], align 8
// CHECK-ILP32F-NEXT:    store double [[TMP4]], ptr [[X]], align 8
// CHECK-ILP32F-NEXT:    call void @llvm.va_end.p0(ptr [[VA]])
// CHECK-ILP32F-NEXT:    [[TMP5:%.*]] = load double, ptr [[V]], align 8
// CHECK-ILP32F-NEXT:    [[TMP6:%.*]] = load double, ptr [[X]], align 8
// CHECK-ILP32F-NEXT:    [[ADD:%.*]] = fadd double [[TMP5]], [[TMP6]]
// CHECK-ILP32F-NEXT:    ret double [[ADD]]
//
// CHECK-ILP32D-LABEL: define dso_local double @f_va_3
// CHECK-ILP32D-SAME: (ptr noundef [[FMT:%.*]], ...) #[[ATTR0]] {
// CHECK-ILP32D-NEXT:  entry:
// CHECK-ILP32D-NEXT:    [[FMT_ADDR:%.*]] = alloca ptr, align 4
// CHECK-ILP32D-NEXT:    [[VA:%.*]] = alloca ptr, align 4
// CHECK-ILP32D-NEXT:    [[V:%.*]] = alloca double, align 8
// CHECK-ILP32D-NEXT:    [[W:%.*]] = alloca i32, align 4
// CHECK-ILP32D-NEXT:    [[X:%.*]] = alloca double, align 8
// CHECK-ILP32D-NEXT:    store ptr [[FMT]], ptr [[FMT_ADDR]], align 4
// CHECK-ILP32D-NEXT:    call void @llvm.va_start.p0(ptr [[VA]])
// CHECK-ILP32D-NEXT:    [[ARGP_CUR:%.*]] = load ptr, ptr [[VA]], align 4
// CHECK-ILP32D-NEXT:    [[TMP0:%.*]] = getelementptr inbounds i8, ptr [[ARGP_CUR]], i32 7
// CHECK-ILP32D-NEXT:    [[ARGP_CUR_ALIGNED:%.*]] = call ptr @llvm.ptrmask.p0.i32(ptr [[TMP0]], i32 -8)
// CHECK-ILP32D-NEXT:    [[ARGP_NEXT:%.*]] = getelementptr inbounds i8, ptr [[ARGP_CUR_ALIGNED]], i32 8
// CHECK-ILP32D-NEXT:    store ptr [[ARGP_NEXT]], ptr [[VA]], align 4
// CHECK-ILP32D-NEXT:    [[TMP1:%.*]] = load double, ptr [[ARGP_CUR_ALIGNED]], align 8
// CHECK-ILP32D-NEXT:    store double [[TMP1]], ptr [[V]], align 8
// CHECK-ILP32D-NEXT:    [[ARGP_CUR1:%.*]] = load ptr, ptr [[VA]], align 4
// CHECK-ILP32D-NEXT:    [[ARGP_NEXT2:%.*]] = getelementptr inbounds i8, ptr [[ARGP_CUR1]], i32 4
// CHECK-ILP32D-NEXT:    store ptr [[ARGP_NEXT2]], ptr [[VA]], align 4
// CHECK-ILP32D-NEXT:    [[TMP2:%.*]] = load i32, ptr [[ARGP_CUR1]], align 4
// CHECK-ILP32D-NEXT:    store i32 [[TMP2]], ptr [[W]], align 4
// CHECK-ILP32D-NEXT:    [[ARGP_CUR3:%.*]] = load ptr, ptr [[VA]], align 4
// CHECK-ILP32D-NEXT:    [[TMP3:%.*]] = getelementptr inbounds i8, ptr [[ARGP_CUR3]], i32 7
// CHECK-ILP32D-NEXT:    [[ARGP_CUR3_ALIGNED:%.*]] = call ptr @llvm.ptrmask.p0.i32(ptr [[TMP3]], i32 -8)
// CHECK-ILP32D-NEXT:    [[ARGP_NEXT4:%.*]] = getelementptr inbounds i8, ptr [[ARGP_CUR3_ALIGNED]], i32 8
// CHECK-ILP32D-NEXT:    store ptr [[ARGP_NEXT4]], ptr [[VA]], align 4
// CHECK-ILP32D-NEXT:    [[TMP4:%.*]] = load double, ptr [[ARGP_CUR3_ALIGNED]], align 8
// CHECK-ILP32D-NEXT:    store double [[TMP4]], ptr [[X]], align 8
// CHECK-ILP32D-NEXT:    call void @llvm.va_end.p0(ptr [[VA]])
// CHECK-ILP32D-NEXT:    [[TMP5:%.*]] = load double, ptr [[V]], align 8
// CHECK-ILP32D-NEXT:    [[TMP6:%.*]] = load double, ptr [[X]], align 8
// CHECK-ILP32D-NEXT:    [[ADD:%.*]] = fadd double [[TMP5]], [[TMP6]]
// CHECK-ILP32D-NEXT:    ret double [[ADD]]
//
// CHECK-ILP32E-LABEL: define dso_local double @f_va_3
// CHECK-ILP32E-SAME: (ptr noundef [[FMT:%.*]], ...) #[[ATTR0]] {
// CHECK-ILP32E-NEXT:  entry:
// CHECK-ILP32E-NEXT:    [[FMT_ADDR:%.*]] = alloca ptr, align 4
// CHECK-ILP32E-NEXT:    [[VA:%.*]] = alloca ptr, align 4
// CHECK-ILP32E-NEXT:    [[V:%.*]] = alloca double, align 8
// CHECK-ILP32E-NEXT:    [[W:%.*]] = alloca i32, align 4
// CHECK-ILP32E-NEXT:    [[X:%.*]] = alloca double, align 8
// CHECK-ILP32E-NEXT:    store ptr [[FMT]], ptr [[FMT_ADDR]], align 4
// CHECK-ILP32E-NEXT:    call void @llvm.va_start.p0(ptr [[VA]])
// CHECK-ILP32E-NEXT:    [[ARGP_CUR:%.*]] = load ptr, ptr [[VA]], align 4
// CHECK-ILP32E-NEXT:    [[ARGP_NEXT:%.*]] = getelementptr inbounds i8, ptr [[ARGP_CUR]], i32 8
// CHECK-ILP32E-NEXT:    store ptr [[ARGP_NEXT]], ptr [[VA]], align 4
// CHECK-ILP32E-NEXT:    [[TMP0:%.*]] = load double, ptr [[ARGP_CUR]], align 4
// CHECK-ILP32E-NEXT:    store double [[TMP0]], ptr [[V]], align 8
// CHECK-ILP32E-NEXT:    [[ARGP_CUR1:%.*]] = load ptr, ptr [[VA]], align 4
// CHECK-ILP32E-NEXT:    [[ARGP_NEXT2:%.*]] = getelementptr inbounds i8, ptr [[ARGP_CUR1]], i32 4
// CHECK-ILP32E-NEXT:    store ptr [[ARGP_NEXT2]], ptr [[VA]], align 4
// CHECK-ILP32E-NEXT:    [[TMP1:%.*]] = load i32, ptr [[ARGP_CUR1]], align 4
// CHECK-ILP32E-NEXT:    store i32 [[TMP1]], ptr [[W]], align 4
// CHECK-ILP32E-NEXT:    [[ARGP_CUR3:%.*]] = load ptr, ptr [[VA]], align 4
// CHECK-ILP32E-NEXT:    [[ARGP_NEXT4:%.*]] = getelementptr inbounds i8, ptr [[ARGP_CUR3]], i32 8
// CHECK-ILP32E-NEXT:    store ptr [[ARGP_NEXT4]], ptr [[VA]], align 4
// CHECK-ILP32E-NEXT:    [[TMP2:%.*]] = load double, ptr [[ARGP_CUR3]], align 4
// CHECK-ILP32E-NEXT:    store double [[TMP2]], ptr [[X]], align 8
// CHECK-ILP32E-NEXT:    call void @llvm.va_end.p0(ptr [[VA]])
// CHECK-ILP32E-NEXT:    [[TMP3:%.*]] = load double, ptr [[V]], align 8
// CHECK-ILP32E-NEXT:    [[TMP4:%.*]] = load double, ptr [[X]], align 8
// CHECK-ILP32E-NEXT:    [[ADD:%.*]] = fadd double [[TMP3]], [[TMP4]]
// CHECK-ILP32E-NEXT:    ret double [[ADD]]
//
double f_va_3(char *fmt, ...) {
  __builtin_va_list va;

  __builtin_va_start(va, fmt);
  double v = __builtin_va_arg(va, double);
  int w = __builtin_va_arg(va, int);
  double x = __builtin_va_arg(va, double);
  __builtin_va_end(va);

  return v + x;
}

// CHECK-ILP32F-LABEL: define dso_local i32 @f_va_4
// CHECK-ILP32F-SAME: (ptr noundef [[FMT:%.*]], ...) #[[ATTR0]] {
// CHECK-ILP32F-NEXT:  entry:
// CHECK-ILP32F-NEXT:    [[FMT_ADDR:%.*]] = alloca ptr, align 4
// CHECK-ILP32F-NEXT:    [[VA:%.*]] = alloca ptr, align 4
// CHECK-ILP32F-NEXT:    [[V:%.*]] = alloca i32, align 4
// CHECK-ILP32F-NEXT:    [[LD:%.*]] = alloca fp128, align 16
// CHECK-ILP32F-NEXT:    [[TS:%.*]] = alloca [[STRUCT_TINY:%.*]], align 1
// CHECK-ILP32F-NEXT:    [[SS:%.*]] = alloca [[STRUCT_SMALL:%.*]], align 4
// CHECK-ILP32F-NEXT:    [[LS:%.*]] = alloca [[STRUCT_LARGE:%.*]], align 4
// CHECK-ILP32F-NEXT:    [[RET:%.*]] = alloca i32, align 4
// CHECK-ILP32F-NEXT:    store ptr [[FMT]], ptr [[FMT_ADDR]], align 4
// CHECK-ILP32F-NEXT:    call void @llvm.va_start.p0(ptr [[VA]])
// CHECK-ILP32F-NEXT:    [[ARGP_CUR:%.*]] = load ptr, ptr [[VA]], align 4
// CHECK-ILP32F-NEXT:    [[ARGP_NEXT:%.*]] = getelementptr inbounds i8, ptr [[ARGP_CUR]], i32 4
// CHECK-ILP32F-NEXT:    store ptr [[ARGP_NEXT]], ptr [[VA]], align 4
// CHECK-ILP32F-NEXT:    [[TMP0:%.*]] = load i32, ptr [[ARGP_CUR]], align 4
// CHECK-ILP32F-NEXT:    store i32 [[TMP0]], ptr [[V]], align 4
// CHECK-ILP32F-NEXT:    [[ARGP_CUR1:%.*]] = load ptr, ptr [[VA]], align 4
// CHECK-ILP32F-NEXT:    [[ARGP_NEXT2:%.*]] = getelementptr inbounds i8, ptr [[ARGP_CUR1]], i32 4
// CHECK-ILP32F-NEXT:    store ptr [[ARGP_NEXT2]], ptr [[VA]], align 4
// CHECK-ILP32F-NEXT:    [[TMP1:%.*]] = load ptr, ptr [[ARGP_CUR1]], align 4
// CHECK-ILP32F-NEXT:    [[TMP2:%.*]] = load fp128, ptr [[TMP1]], align 16
// CHECK-ILP32F-NEXT:    store fp128 [[TMP2]], ptr [[LD]], align 16
// CHECK-ILP32F-NEXT:    [[ARGP_CUR3:%.*]] = load ptr, ptr [[VA]], align 4
// CHECK-ILP32F-NEXT:    [[ARGP_NEXT4:%.*]] = getelementptr inbounds i8, ptr [[ARGP_CUR3]], i32 4
// CHECK-ILP32F-NEXT:    store ptr [[ARGP_NEXT4]], ptr [[VA]], align 4
// CHECK-ILP32F-NEXT:    call void @llvm.memcpy.p0.p0.i32(ptr align 1 [[TS]], ptr align 4 [[ARGP_CUR3]], i32 4, i1 false)
// CHECK-ILP32F-NEXT:    [[ARGP_CUR5:%.*]] = load ptr, ptr [[VA]], align 4
// CHECK-ILP32F-NEXT:    [[ARGP_NEXT6:%.*]] = getelementptr inbounds i8, ptr [[ARGP_CUR5]], i32 8
// CHECK-ILP32F-NEXT:    store ptr [[ARGP_NEXT6]], ptr [[VA]], align 4
// CHECK-ILP32F-NEXT:    call void @llvm.memcpy.p0.p0.i32(ptr align 4 [[SS]], ptr align 4 [[ARGP_CUR5]], i32 8, i1 false)
// CHECK-ILP32F-NEXT:    [[ARGP_CUR7:%.*]] = load ptr, ptr [[VA]], align 4
// CHECK-ILP32F-NEXT:    [[ARGP_NEXT8:%.*]] = getelementptr inbounds i8, ptr [[ARGP_CUR7]], i32 4
// CHECK-ILP32F-NEXT:    store ptr [[ARGP_NEXT8]], ptr [[VA]], align 4
// CHECK-ILP32F-NEXT:    [[TMP3:%.*]] = load ptr, ptr [[ARGP_CUR7]], align 4
// CHECK-ILP32F-NEXT:    call void @llvm.memcpy.p0.p0.i32(ptr align 4 [[LS]], ptr align 4 [[TMP3]], i32 16, i1 false)
// CHECK-ILP32F-NEXT:    call void @llvm.va_end.p0(ptr [[VA]])
// CHECK-ILP32F-NEXT:    [[TMP4:%.*]] = load i32, ptr [[V]], align 4
// CHECK-ILP32F-NEXT:    [[CONV:%.*]] = sitofp i32 [[TMP4]] to fp128
// CHECK-ILP32F-NEXT:    [[TMP5:%.*]] = load fp128, ptr [[LD]], align 16
// CHECK-ILP32F-NEXT:    [[ADD:%.*]] = fadd fp128 [[CONV]], [[TMP5]]
// CHECK-ILP32F-NEXT:    [[CONV9:%.*]] = fptosi fp128 [[ADD]] to i32
// CHECK-ILP32F-NEXT:    store i32 [[CONV9]], ptr [[RET]], align 4
// CHECK-ILP32F-NEXT:    [[TMP6:%.*]] = load i32, ptr [[RET]], align 4
// CHECK-ILP32F-NEXT:    [[A:%.*]] = getelementptr inbounds nuw [[STRUCT_TINY]], ptr [[TS]], i32 0, i32 0
// CHECK-ILP32F-NEXT:    [[TMP7:%.*]] = load i8, ptr [[A]], align 1
// CHECK-ILP32F-NEXT:    [[CONV10:%.*]] = zext i8 [[TMP7]] to i32
// CHECK-ILP32F-NEXT:    [[ADD11:%.*]] = add nsw i32 [[TMP6]], [[CONV10]]
// CHECK-ILP32F-NEXT:    [[B:%.*]] = getelementptr inbounds nuw [[STRUCT_TINY]], ptr [[TS]], i32 0, i32 1
// CHECK-ILP32F-NEXT:    [[TMP8:%.*]] = load i8, ptr [[B]], align 1
// CHECK-ILP32F-NEXT:    [[CONV12:%.*]] = zext i8 [[TMP8]] to i32
// CHECK-ILP32F-NEXT:    [[ADD13:%.*]] = add nsw i32 [[ADD11]], [[CONV12]]
// CHECK-ILP32F-NEXT:    [[C:%.*]] = getelementptr inbounds nuw [[STRUCT_TINY]], ptr [[TS]], i32 0, i32 2
// CHECK-ILP32F-NEXT:    [[TMP9:%.*]] = load i8, ptr [[C]], align 1
// CHECK-ILP32F-NEXT:    [[CONV14:%.*]] = zext i8 [[TMP9]] to i32
// CHECK-ILP32F-NEXT:    [[ADD15:%.*]] = add nsw i32 [[ADD13]], [[CONV14]]
// CHECK-ILP32F-NEXT:    [[D:%.*]] = getelementptr inbounds nuw [[STRUCT_TINY]], ptr [[TS]], i32 0, i32 3
// CHECK-ILP32F-NEXT:    [[TMP10:%.*]] = load i8, ptr [[D]], align 1
// CHECK-ILP32F-NEXT:    [[CONV16:%.*]] = zext i8 [[TMP10]] to i32
// CHECK-ILP32F-NEXT:    [[ADD17:%.*]] = add nsw i32 [[ADD15]], [[CONV16]]
// CHECK-ILP32F-NEXT:    store i32 [[ADD17]], ptr [[RET]], align 4
// CHECK-ILP32F-NEXT:    [[TMP11:%.*]] = load i32, ptr [[RET]], align 4
// CHECK-ILP32F-NEXT:    [[A18:%.*]] = getelementptr inbounds nuw [[STRUCT_SMALL]], ptr [[SS]], i32 0, i32 0
// CHECK-ILP32F-NEXT:    [[TMP12:%.*]] = load i32, ptr [[A18]], align 4
// CHECK-ILP32F-NEXT:    [[ADD19:%.*]] = add nsw i32 [[TMP11]], [[TMP12]]
// CHECK-ILP32F-NEXT:    [[B20:%.*]] = getelementptr inbounds nuw [[STRUCT_SMALL]], ptr [[SS]], i32 0, i32 1
// CHECK-ILP32F-NEXT:    [[TMP13:%.*]] = load ptr, ptr [[B20]], align 4
// CHECK-ILP32F-NEXT:    [[TMP14:%.*]] = ptrtoint ptr [[TMP13]] to i32
// CHECK-ILP32F-NEXT:    [[ADD21:%.*]] = add nsw i32 [[ADD19]], [[TMP14]]
// CHECK-ILP32F-NEXT:    store i32 [[ADD21]], ptr [[RET]], align 4
// CHECK-ILP32F-NEXT:    [[TMP15:%.*]] = load i32, ptr [[RET]], align 4
// CHECK-ILP32F-NEXT:    [[A22:%.*]] = getelementptr inbounds nuw [[STRUCT_LARGE]], ptr [[LS]], i32 0, i32 0
// CHECK-ILP32F-NEXT:    [[TMP16:%.*]] = load i32, ptr [[A22]], align 4
// CHECK-ILP32F-NEXT:    [[ADD23:%.*]] = add nsw i32 [[TMP15]], [[TMP16]]
// CHECK-ILP32F-NEXT:    [[B24:%.*]] = getelementptr inbounds nuw [[STRUCT_LARGE]], ptr [[LS]], i32 0, i32 1
// CHECK-ILP32F-NEXT:    [[TMP17:%.*]] = load i32, ptr [[B24]], align 4
// CHECK-ILP32F-NEXT:    [[ADD25:%.*]] = add nsw i32 [[ADD23]], [[TMP17]]
// CHECK-ILP32F-NEXT:    [[C26:%.*]] = getelementptr inbounds nuw [[STRUCT_LARGE]], ptr [[LS]], i32 0, i32 2
// CHECK-ILP32F-NEXT:    [[TMP18:%.*]] = load i32, ptr [[C26]], align 4
// CHECK-ILP32F-NEXT:    [[ADD27:%.*]] = add nsw i32 [[ADD25]], [[TMP18]]
// CHECK-ILP32F-NEXT:    [[D28:%.*]] = getelementptr inbounds nuw [[STRUCT_LARGE]], ptr [[LS]], i32 0, i32 3
// CHECK-ILP32F-NEXT:    [[TMP19:%.*]] = load i32, ptr [[D28]], align 4
// CHECK-ILP32F-NEXT:    [[ADD29:%.*]] = add nsw i32 [[ADD27]], [[TMP19]]
// CHECK-ILP32F-NEXT:    store i32 [[ADD29]], ptr [[RET]], align 4
// CHECK-ILP32F-NEXT:    [[TMP20:%.*]] = load i32, ptr [[RET]], align 4
// CHECK-ILP32F-NEXT:    ret i32 [[TMP20]]
//
// CHECK-ILP32D-LABEL: define dso_local i32 @f_va_4
// CHECK-ILP32D-SAME: (ptr noundef [[FMT:%.*]], ...) #[[ATTR0]] {
// CHECK-ILP32D-NEXT:  entry:
// CHECK-ILP32D-NEXT:    [[FMT_ADDR:%.*]] = alloca ptr, align 4
// CHECK-ILP32D-NEXT:    [[VA:%.*]] = alloca ptr, align 4
// CHECK-ILP32D-NEXT:    [[V:%.*]] = alloca i32, align 4
// CHECK-ILP32D-NEXT:    [[LD:%.*]] = alloca fp128, align 16
// CHECK-ILP32D-NEXT:    [[TS:%.*]] = alloca [[STRUCT_TINY:%.*]], align 1
// CHECK-ILP32D-NEXT:    [[SS:%.*]] = alloca [[STRUCT_SMALL:%.*]], align 4
// CHECK-ILP32D-NEXT:    [[LS:%.*]] = alloca [[STRUCT_LARGE:%.*]], align 4
// CHECK-ILP32D-NEXT:    [[RET:%.*]] = alloca i32, align 4
// CHECK-ILP32D-NEXT:    store ptr [[FMT]], ptr [[FMT_ADDR]], align 4
// CHECK-ILP32D-NEXT:    call void @llvm.va_start.p0(ptr [[VA]])
// CHECK-ILP32D-NEXT:    [[ARGP_CUR:%.*]] = load ptr, ptr [[VA]], align 4
// CHECK-ILP32D-NEXT:    [[ARGP_NEXT:%.*]] = getelementptr inbounds i8, ptr [[ARGP_CUR]], i32 4
// CHECK-ILP32D-NEXT:    store ptr [[ARGP_NEXT]], ptr [[VA]], align 4
// CHECK-ILP32D-NEXT:    [[TMP0:%.*]] = load i32, ptr [[ARGP_CUR]], align 4
// CHECK-ILP32D-NEXT:    store i32 [[TMP0]], ptr [[V]], align 4
// CHECK-ILP32D-NEXT:    [[ARGP_CUR1:%.*]] = load ptr, ptr [[VA]], align 4
// CHECK-ILP32D-NEXT:    [[ARGP_NEXT2:%.*]] = getelementptr inbounds i8, ptr [[ARGP_CUR1]], i32 4
// CHECK-ILP32D-NEXT:    store ptr [[ARGP_NEXT2]], ptr [[VA]], align 4
// CHECK-ILP32D-NEXT:    [[TMP1:%.*]] = load ptr, ptr [[ARGP_CUR1]], align 4
// CHECK-ILP32D-NEXT:    [[TMP2:%.*]] = load fp128, ptr [[TMP1]], align 16
// CHECK-ILP32D-NEXT:    store fp128 [[TMP2]], ptr [[LD]], align 16
// CHECK-ILP32D-NEXT:    [[ARGP_CUR3:%.*]] = load ptr, ptr [[VA]], align 4
// CHECK-ILP32D-NEXT:    [[ARGP_NEXT4:%.*]] = getelementptr inbounds i8, ptr [[ARGP_CUR3]], i32 4
// CHECK-ILP32D-NEXT:    store ptr [[ARGP_NEXT4]], ptr [[VA]], align 4
// CHECK-ILP32D-NEXT:    call void @llvm.memcpy.p0.p0.i32(ptr align 1 [[TS]], ptr align 4 [[ARGP_CUR3]], i32 4, i1 false)
// CHECK-ILP32D-NEXT:    [[ARGP_CUR5:%.*]] = load ptr, ptr [[VA]], align 4
// CHECK-ILP32D-NEXT:    [[ARGP_NEXT6:%.*]] = getelementptr inbounds i8, ptr [[ARGP_CUR5]], i32 8
// CHECK-ILP32D-NEXT:    store ptr [[ARGP_NEXT6]], ptr [[VA]], align 4
// CHECK-ILP32D-NEXT:    call void @llvm.memcpy.p0.p0.i32(ptr align 4 [[SS]], ptr align 4 [[ARGP_CUR5]], i32 8, i1 false)
// CHECK-ILP32D-NEXT:    [[ARGP_CUR7:%.*]] = load ptr, ptr [[VA]], align 4
// CHECK-ILP32D-NEXT:    [[ARGP_NEXT8:%.*]] = getelementptr inbounds i8, ptr [[ARGP_CUR7]], i32 4
// CHECK-ILP32D-NEXT:    store ptr [[ARGP_NEXT8]], ptr [[VA]], align 4
// CHECK-ILP32D-NEXT:    [[TMP3:%.*]] = load ptr, ptr [[ARGP_CUR7]], align 4
// CHECK-ILP32D-NEXT:    call void @llvm.memcpy.p0.p0.i32(ptr align 4 [[LS]], ptr align 4 [[TMP3]], i32 16, i1 false)
// CHECK-ILP32D-NEXT:    call void @llvm.va_end.p0(ptr [[VA]])
// CHECK-ILP32D-NEXT:    [[TMP4:%.*]] = load i32, ptr [[V]], align 4
// CHECK-ILP32D-NEXT:    [[CONV:%.*]] = sitofp i32 [[TMP4]] to fp128
// CHECK-ILP32D-NEXT:    [[TMP5:%.*]] = load fp128, ptr [[LD]], align 16
// CHECK-ILP32D-NEXT:    [[ADD:%.*]] = fadd fp128 [[CONV]], [[TMP5]]
// CHECK-ILP32D-NEXT:    [[CONV9:%.*]] = fptosi fp128 [[ADD]] to i32
// CHECK-ILP32D-NEXT:    store i32 [[CONV9]], ptr [[RET]], align 4
// CHECK-ILP32D-NEXT:    [[TMP6:%.*]] = load i32, ptr [[RET]], align 4
// CHECK-ILP32D-NEXT:    [[A:%.*]] = getelementptr inbounds nuw [[STRUCT_TINY]], ptr [[TS]], i32 0, i32 0
// CHECK-ILP32D-NEXT:    [[TMP7:%.*]] = load i8, ptr [[A]], align 1
// CHECK-ILP32D-NEXT:    [[CONV10:%.*]] = zext i8 [[TMP7]] to i32
// CHECK-ILP32D-NEXT:    [[ADD11:%.*]] = add nsw i32 [[TMP6]], [[CONV10]]
// CHECK-ILP32D-NEXT:    [[B:%.*]] = getelementptr inbounds nuw [[STRUCT_TINY]], ptr [[TS]], i32 0, i32 1
// CHECK-ILP32D-NEXT:    [[TMP8:%.*]] = load i8, ptr [[B]], align 1
// CHECK-ILP32D-NEXT:    [[CONV12:%.*]] = zext i8 [[TMP8]] to i32
// CHECK-ILP32D-NEXT:    [[ADD13:%.*]] = add nsw i32 [[ADD11]], [[CONV12]]
// CHECK-ILP32D-NEXT:    [[C:%.*]] = getelementptr inbounds nuw [[STRUCT_TINY]], ptr [[TS]], i32 0, i32 2
// CHECK-ILP32D-NEXT:    [[TMP9:%.*]] = load i8, ptr [[C]], align 1
// CHECK-ILP32D-NEXT:    [[CONV14:%.*]] = zext i8 [[TMP9]] to i32
// CHECK-ILP32D-NEXT:    [[ADD15:%.*]] = add nsw i32 [[ADD13]], [[CONV14]]
// CHECK-ILP32D-NEXT:    [[D:%.*]] = getelementptr inbounds nuw [[STRUCT_TINY]], ptr [[TS]], i32 0, i32 3
// CHECK-ILP32D-NEXT:    [[TMP10:%.*]] = load i8, ptr [[D]], align 1
// CHECK-ILP32D-NEXT:    [[CONV16:%.*]] = zext i8 [[TMP10]] to i32
// CHECK-ILP32D-NEXT:    [[ADD17:%.*]] = add nsw i32 [[ADD15]], [[CONV16]]
// CHECK-ILP32D-NEXT:    store i32 [[ADD17]], ptr [[RET]], align 4
// CHECK-ILP32D-NEXT:    [[TMP11:%.*]] = load i32, ptr [[RET]], align 4
// CHECK-ILP32D-NEXT:    [[A18:%.*]] = getelementptr inbounds nuw [[STRUCT_SMALL]], ptr [[SS]], i32 0, i32 0
// CHECK-ILP32D-NEXT:    [[TMP12:%.*]] = load i32, ptr [[A18]], align 4
// CHECK-ILP32D-NEXT:    [[ADD19:%.*]] = add nsw i32 [[TMP11]], [[TMP12]]
// CHECK-ILP32D-NEXT:    [[B20:%.*]] = getelementptr inbounds nuw [[STRUCT_SMALL]], ptr [[SS]], i32 0, i32 1
// CHECK-ILP32D-NEXT:    [[TMP13:%.*]] = load ptr, ptr [[B20]], align 4
// CHECK-ILP32D-NEXT:    [[TMP14:%.*]] = ptrtoint ptr [[TMP13]] to i32
// CHECK-ILP32D-NEXT:    [[ADD21:%.*]] = add nsw i32 [[ADD19]], [[TMP14]]
// CHECK-ILP32D-NEXT:    store i32 [[ADD21]], ptr [[RET]], align 4
// CHECK-ILP32D-NEXT:    [[TMP15:%.*]] = load i32, ptr [[RET]], align 4
// CHECK-ILP32D-NEXT:    [[A22:%.*]] = getelementptr inbounds nuw [[STRUCT_LARGE]], ptr [[LS]], i32 0, i32 0
// CHECK-ILP32D-NEXT:    [[TMP16:%.*]] = load i32, ptr [[A22]], align 4
// CHECK-ILP32D-NEXT:    [[ADD23:%.*]] = add nsw i32 [[TMP15]], [[TMP16]]
// CHECK-ILP32D-NEXT:    [[B24:%.*]] = getelementptr inbounds nuw [[STRUCT_LARGE]], ptr [[LS]], i32 0, i32 1
// CHECK-ILP32D-NEXT:    [[TMP17:%.*]] = load i32, ptr [[B24]], align 4
// CHECK-ILP32D-NEXT:    [[ADD25:%.*]] = add nsw i32 [[ADD23]], [[TMP17]]
// CHECK-ILP32D-NEXT:    [[C26:%.*]] = getelementptr inbounds nuw [[STRUCT_LARGE]], ptr [[LS]], i32 0, i32 2
// CHECK-ILP32D-NEXT:    [[TMP18:%.*]] = load i32, ptr [[C26]], align 4
// CHECK-ILP32D-NEXT:    [[ADD27:%.*]] = add nsw i32 [[ADD25]], [[TMP18]]
// CHECK-ILP32D-NEXT:    [[D28:%.*]] = getelementptr inbounds nuw [[STRUCT_LARGE]], ptr [[LS]], i32 0, i32 3
// CHECK-ILP32D-NEXT:    [[TMP19:%.*]] = load i32, ptr [[D28]], align 4
// CHECK-ILP32D-NEXT:    [[ADD29:%.*]] = add nsw i32 [[ADD27]], [[TMP19]]
// CHECK-ILP32D-NEXT:    store i32 [[ADD29]], ptr [[RET]], align 4
// CHECK-ILP32D-NEXT:    [[TMP20:%.*]] = load i32, ptr [[RET]], align 4
// CHECK-ILP32D-NEXT:    ret i32 [[TMP20]]
//
// CHECK-ILP32E-LABEL: define dso_local i32 @f_va_4
// CHECK-ILP32E-SAME: (ptr noundef [[FMT:%.*]], ...) #[[ATTR0]] {
// CHECK-ILP32E-NEXT:  entry:
// CHECK-ILP32E-NEXT:    [[FMT_ADDR:%.*]] = alloca ptr, align 4
// CHECK-ILP32E-NEXT:    [[VA:%.*]] = alloca ptr, align 4
// CHECK-ILP32E-NEXT:    [[V:%.*]] = alloca i32, align 4
// CHECK-ILP32E-NEXT:    [[LD:%.*]] = alloca fp128, align 16
// CHECK-ILP32E-NEXT:    [[TS:%.*]] = alloca [[STRUCT_TINY:%.*]], align 1
// CHECK-ILP32E-NEXT:    [[SS:%.*]] = alloca [[STRUCT_SMALL:%.*]], align 4
// CHECK-ILP32E-NEXT:    [[LS:%.*]] = alloca [[STRUCT_LARGE:%.*]], align 4
// CHECK-ILP32E-NEXT:    [[RET:%.*]] = alloca i32, align 4
// CHECK-ILP32E-NEXT:    store ptr [[FMT]], ptr [[FMT_ADDR]], align 4
// CHECK-ILP32E-NEXT:    call void @llvm.va_start.p0(ptr [[VA]])
// CHECK-ILP32E-NEXT:    [[ARGP_CUR:%.*]] = load ptr, ptr [[VA]], align 4
// CHECK-ILP32E-NEXT:    [[ARGP_NEXT:%.*]] = getelementptr inbounds i8, ptr [[ARGP_CUR]], i32 4
// CHECK-ILP32E-NEXT:    store ptr [[ARGP_NEXT]], ptr [[VA]], align 4
// CHECK-ILP32E-NEXT:    [[TMP0:%.*]] = load i32, ptr [[ARGP_CUR]], align 4
// CHECK-ILP32E-NEXT:    store i32 [[TMP0]], ptr [[V]], align 4
// CHECK-ILP32E-NEXT:    [[ARGP_CUR1:%.*]] = load ptr, ptr [[VA]], align 4
// CHECK-ILP32E-NEXT:    [[ARGP_NEXT2:%.*]] = getelementptr inbounds i8, ptr [[ARGP_CUR1]], i32 4
// CHECK-ILP32E-NEXT:    store ptr [[ARGP_NEXT2]], ptr [[VA]], align 4
// CHECK-ILP32E-NEXT:    [[TMP1:%.*]] = load ptr, ptr [[ARGP_CUR1]], align 4
// CHECK-ILP32E-NEXT:    [[TMP2:%.*]] = load fp128, ptr [[TMP1]], align 4
// CHECK-ILP32E-NEXT:    store fp128 [[TMP2]], ptr [[LD]], align 16
// CHECK-ILP32E-NEXT:    [[ARGP_CUR3:%.*]] = load ptr, ptr [[VA]], align 4
// CHECK-ILP32E-NEXT:    [[ARGP_NEXT4:%.*]] = getelementptr inbounds i8, ptr [[ARGP_CUR3]], i32 4
// CHECK-ILP32E-NEXT:    store ptr [[ARGP_NEXT4]], ptr [[VA]], align 4
// CHECK-ILP32E-NEXT:    call void @llvm.memcpy.p0.p0.i32(ptr align 1 [[TS]], ptr align 4 [[ARGP_CUR3]], i32 4, i1 false)
// CHECK-ILP32E-NEXT:    [[ARGP_CUR5:%.*]] = load ptr, ptr [[VA]], align 4
// CHECK-ILP32E-NEXT:    [[ARGP_NEXT6:%.*]] = getelementptr inbounds i8, ptr [[ARGP_CUR5]], i32 8
// CHECK-ILP32E-NEXT:    store ptr [[ARGP_NEXT6]], ptr [[VA]], align 4
// CHECK-ILP32E-NEXT:    call void @llvm.memcpy.p0.p0.i32(ptr align 4 [[SS]], ptr align 4 [[ARGP_CUR5]], i32 8, i1 false)
// CHECK-ILP32E-NEXT:    [[ARGP_CUR7:%.*]] = load ptr, ptr [[VA]], align 4
// CHECK-ILP32E-NEXT:    [[ARGP_NEXT8:%.*]] = getelementptr inbounds i8, ptr [[ARGP_CUR7]], i32 4
// CHECK-ILP32E-NEXT:    store ptr [[ARGP_NEXT8]], ptr [[VA]], align 4
// CHECK-ILP32E-NEXT:    [[TMP3:%.*]] = load ptr, ptr [[ARGP_CUR7]], align 4
// CHECK-ILP32E-NEXT:    call void @llvm.memcpy.p0.p0.i32(ptr align 4 [[LS]], ptr align 4 [[TMP3]], i32 16, i1 false)
// CHECK-ILP32E-NEXT:    call void @llvm.va_end.p0(ptr [[VA]])
// CHECK-ILP32E-NEXT:    [[TMP4:%.*]] = load i32, ptr [[V]], align 4
// CHECK-ILP32E-NEXT:    [[CONV:%.*]] = sitofp i32 [[TMP4]] to fp128
// CHECK-ILP32E-NEXT:    [[TMP5:%.*]] = load fp128, ptr [[LD]], align 16
// CHECK-ILP32E-NEXT:    [[ADD:%.*]] = fadd fp128 [[CONV]], [[TMP5]]
// CHECK-ILP32E-NEXT:    [[CONV9:%.*]] = fptosi fp128 [[ADD]] to i32
// CHECK-ILP32E-NEXT:    store i32 [[CONV9]], ptr [[RET]], align 4
// CHECK-ILP32E-NEXT:    [[TMP6:%.*]] = load i32, ptr [[RET]], align 4
// CHECK-ILP32E-NEXT:    [[A:%.*]] = getelementptr inbounds nuw [[STRUCT_TINY]], ptr [[TS]], i32 0, i32 0
// CHECK-ILP32E-NEXT:    [[TMP7:%.*]] = load i8, ptr [[A]], align 1
// CHECK-ILP32E-NEXT:    [[CONV10:%.*]] = zext i8 [[TMP7]] to i32
// CHECK-ILP32E-NEXT:    [[ADD11:%.*]] = add nsw i32 [[TMP6]], [[CONV10]]
// CHECK-ILP32E-NEXT:    [[B:%.*]] = getelementptr inbounds nuw [[STRUCT_TINY]], ptr [[TS]], i32 0, i32 1
// CHECK-ILP32E-NEXT:    [[TMP8:%.*]] = load i8, ptr [[B]], align 1
// CHECK-ILP32E-NEXT:    [[CONV12:%.*]] = zext i8 [[TMP8]] to i32
// CHECK-ILP32E-NEXT:    [[ADD13:%.*]] = add nsw i32 [[ADD11]], [[CONV12]]
// CHECK-ILP32E-NEXT:    [[C:%.*]] = getelementptr inbounds nuw [[STRUCT_TINY]], ptr [[TS]], i32 0, i32 2
// CHECK-ILP32E-NEXT:    [[TMP9:%.*]] = load i8, ptr [[C]], align 1
// CHECK-ILP32E-NEXT:    [[CONV14:%.*]] = zext i8 [[TMP9]] to i32
// CHECK-ILP32E-NEXT:    [[ADD15:%.*]] = add nsw i32 [[ADD13]], [[CONV14]]
// CHECK-ILP32E-NEXT:    [[D:%.*]] = getelementptr inbounds nuw [[STRUCT_TINY]], ptr [[TS]], i32 0, i32 3
// CHECK-ILP32E-NEXT:    [[TMP10:%.*]] = load i8, ptr [[D]], align 1
// CHECK-ILP32E-NEXT:    [[CONV16:%.*]] = zext i8 [[TMP10]] to i32
// CHECK-ILP32E-NEXT:    [[ADD17:%.*]] = add nsw i32 [[ADD15]], [[CONV16]]
// CHECK-ILP32E-NEXT:    store i32 [[ADD17]], ptr [[RET]], align 4
// CHECK-ILP32E-NEXT:    [[TMP11:%.*]] = load i32, ptr [[RET]], align 4
// CHECK-ILP32E-NEXT:    [[A18:%.*]] = getelementptr inbounds nuw [[STRUCT_SMALL]], ptr [[SS]], i32 0, i32 0
// CHECK-ILP32E-NEXT:    [[TMP12:%.*]] = load i32, ptr [[A18]], align 4
// CHECK-ILP32E-NEXT:    [[ADD19:%.*]] = add nsw i32 [[TMP11]], [[TMP12]]
// CHECK-ILP32E-NEXT:    [[B20:%.*]] = getelementptr inbounds nuw [[STRUCT_SMALL]], ptr [[SS]], i32 0, i32 1
// CHECK-ILP32E-NEXT:    [[TMP13:%.*]] = load ptr, ptr [[B20]], align 4
// CHECK-ILP32E-NEXT:    [[TMP14:%.*]] = ptrtoint ptr [[TMP13]] to i32
// CHECK-ILP32E-NEXT:    [[ADD21:%.*]] = add nsw i32 [[ADD19]], [[TMP14]]
// CHECK-ILP32E-NEXT:    store i32 [[ADD21]], ptr [[RET]], align 4
// CHECK-ILP32E-NEXT:    [[TMP15:%.*]] = load i32, ptr [[RET]], align 4
// CHECK-ILP32E-NEXT:    [[A22:%.*]] = getelementptr inbounds nuw [[STRUCT_LARGE]], ptr [[LS]], i32 0, i32 0
// CHECK-ILP32E-NEXT:    [[TMP16:%.*]] = load i32, ptr [[A22]], align 4
// CHECK-ILP32E-NEXT:    [[ADD23:%.*]] = add nsw i32 [[TMP15]], [[TMP16]]
// CHECK-ILP32E-NEXT:    [[B24:%.*]] = getelementptr inbounds nuw [[STRUCT_LARGE]], ptr [[LS]], i32 0, i32 1
// CHECK-ILP32E-NEXT:    [[TMP17:%.*]] = load i32, ptr [[B24]], align 4
// CHECK-ILP32E-NEXT:    [[ADD25:%.*]] = add nsw i32 [[ADD23]], [[TMP17]]
// CHECK-ILP32E-NEXT:    [[C26:%.*]] = getelementptr inbounds nuw [[STRUCT_LARGE]], ptr [[LS]], i32 0, i32 2
// CHECK-ILP32E-NEXT:    [[TMP18:%.*]] = load i32, ptr [[C26]], align 4
// CHECK-ILP32E-NEXT:    [[ADD27:%.*]] = add nsw i32 [[ADD25]], [[TMP18]]
// CHECK-ILP32E-NEXT:    [[D28:%.*]] = getelementptr inbounds nuw [[STRUCT_LARGE]], ptr [[LS]], i32 0, i32 3
// CHECK-ILP32E-NEXT:    [[TMP19:%.*]] = load i32, ptr [[D28]], align 4
// CHECK-ILP32E-NEXT:    [[ADD29:%.*]] = add nsw i32 [[ADD27]], [[TMP19]]
// CHECK-ILP32E-NEXT:    store i32 [[ADD29]], ptr [[RET]], align 4
// CHECK-ILP32E-NEXT:    [[TMP20:%.*]] = load i32, ptr [[RET]], align 4
// CHECK-ILP32E-NEXT:    ret i32 [[TMP20]]
//
int f_va_4(char *fmt, ...) {
  __builtin_va_list va;

  __builtin_va_start(va, fmt);
  int v = __builtin_va_arg(va, int);
  long double ld = __builtin_va_arg(va, long double);
  struct tiny ts = __builtin_va_arg(va, struct tiny);
  struct small ss = __builtin_va_arg(va, struct small);
  struct large ls = __builtin_va_arg(va, struct large);
  __builtin_va_end(va);

  int ret = (int)((long double)v + ld);
  ret = ret + ts.a + ts.b + ts.c + ts.d;
  ret = ret + ss.a + (int)ss.b;
  ret = ret + ls.a + ls.b + ls.c + ls.d;

  return ret;
}
