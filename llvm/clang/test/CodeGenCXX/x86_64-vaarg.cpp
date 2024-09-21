// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// RUN: %clang_cc1 -triple x86_64-linux-gnu -emit-llvm -o - %s | FileCheck %s

typedef struct { struct {} a; } empty;

// CHECK-LABEL: @_Z17empty_record_testiz(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[Z_ADDR:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[LIST:%.*]] = alloca [1 x %struct.__va_list_tag], align 16
// CHECK-NEXT:    store i32 [[Z:%.*]], ptr [[Z_ADDR]], align 4
// CHECK-NEXT:    [[ARRAYDECAY:%.*]] = getelementptr inbounds [1 x %struct.__va_list_tag], ptr [[LIST]], i64 0, i64 0
// CHECK-NEXT:    call void @llvm.va_start.p0(ptr [[ARRAYDECAY]])
// CHECK-NEXT:    [[ARRAYDECAY1:%.*]] = getelementptr inbounds [1 x %struct.__va_list_tag], ptr [[LIST]], i64 0, i64 0
// CHECK-NEXT:    ret void
//
empty empty_record_test(int z, ...) {
  __builtin_va_list list;
  __builtin_va_start(list, z);
  return __builtin_va_arg(list, empty);
}

typedef struct {
  struct{} a;
  double b;
} s1;

// CHECK-LABEL: @_Z1fiz(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[RETVAL:%.*]] = alloca [[STRUCT_S1:%.*]], align 8
// CHECK-NEXT:    [[Z_ADDR:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[LIST:%.*]] = alloca [1 x %struct.__va_list_tag], align 16
// CHECK-NEXT:    [[TMP:%.*]] = alloca [[STRUCT_S1]], align 8
// CHECK-NEXT:    store i32 [[Z:%.*]], ptr [[Z_ADDR]], align 4
// CHECK-NEXT:    [[ARRAYDECAY:%.*]] = getelementptr inbounds [1 x %struct.__va_list_tag], ptr [[LIST]], i64 0, i64 0
// CHECK-NEXT:    call void @llvm.va_start.p0(ptr [[ARRAYDECAY]])
// CHECK-NEXT:    [[ARRAYDECAY1:%.*]] = getelementptr inbounds [1 x %struct.__va_list_tag], ptr [[LIST]], i64 0, i64 0
// CHECK-NEXT:    [[FP_OFFSET_P:%.*]] = getelementptr inbounds nuw [[STRUCT___VA_LIST_TAG:%.*]], ptr [[ARRAYDECAY1]], i32 0, i32 1
// CHECK-NEXT:    [[FP_OFFSET:%.*]] = load i32, ptr [[FP_OFFSET_P]], align 4
// CHECK-NEXT:    [[FITS_IN_FP:%.*]] = icmp ule i32 [[FP_OFFSET]], 160
// CHECK-NEXT:    br i1 [[FITS_IN_FP]], label [[VAARG_IN_REG:%.*]], label [[VAARG_IN_MEM:%.*]]
// CHECK:       vaarg.in_reg:
// CHECK-NEXT:    [[TMP0:%.*]] = getelementptr inbounds nuw [[STRUCT___VA_LIST_TAG]], ptr [[ARRAYDECAY1]], i32 0, i32 3
// CHECK-NEXT:    [[REG_SAVE_AREA:%.*]] = load ptr, ptr [[TMP0]], align 16
// CHECK-NEXT:    [[TMP1:%.*]] = getelementptr i8, ptr [[REG_SAVE_AREA]], i32 [[FP_OFFSET]]
// CHECK-NEXT:    [[TMP2:%.*]] = load double, ptr [[TMP1]], align 8
// CHECK-NEXT:    [[TMP3:%.*]] = getelementptr i8, ptr [[TMP]], i32 8
// CHECK-NEXT:    store double [[TMP2]], ptr [[TMP3]], align 8
// CHECK-NEXT:    [[TMP4:%.*]] = add i32 [[FP_OFFSET]], 16
// CHECK-NEXT:    store i32 [[TMP4]], ptr [[FP_OFFSET_P]], align 4
// CHECK-NEXT:    br label [[VAARG_END:%.*]]
// CHECK:       vaarg.in_mem:
// CHECK-NEXT:    [[OVERFLOW_ARG_AREA_P:%.*]] = getelementptr inbounds nuw [[STRUCT___VA_LIST_TAG]], ptr [[ARRAYDECAY1]], i32 0, i32 2
// CHECK-NEXT:    [[OVERFLOW_ARG_AREA:%.*]] = load ptr, ptr [[OVERFLOW_ARG_AREA_P]], align 8
// CHECK-NEXT:    [[OVERFLOW_ARG_AREA_NEXT:%.*]] = getelementptr i8, ptr [[OVERFLOW_ARG_AREA]], i32 16
// CHECK-NEXT:    store ptr [[OVERFLOW_ARG_AREA_NEXT]], ptr [[OVERFLOW_ARG_AREA_P]], align 8
// CHECK-NEXT:    br label [[VAARG_END]]
// CHECK:       vaarg.end:
// CHECK-NEXT:    [[VAARG_ADDR:%.*]] = phi ptr [ [[TMP]], [[VAARG_IN_REG]] ], [ [[OVERFLOW_ARG_AREA]], [[VAARG_IN_MEM]] ]
// CHECK-NEXT:    call void @llvm.memcpy.p0.p0.i64(ptr align 8 [[RETVAL]], ptr align 8 [[VAARG_ADDR]], i64 16, i1 false)
// CHECK-NEXT:    [[TMP5:%.*]] = getelementptr inbounds i8, ptr [[RETVAL]], i64 8
// CHECK-NEXT:    [[TMP6:%.*]] = load double, ptr [[TMP5]], align 8
// CHECK-NEXT:    ret double [[TMP6]]
//
s1 f(int z, ...) {
  __builtin_va_list list;
  __builtin_va_start(list, z);
  return __builtin_va_arg(list, s1);
}

typedef struct {
  struct{} a[5];
  float b;
  float c;
} s2;

// CHECK-LABEL: @_Z2f2iz(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[RETVAL:%.*]] = alloca [[STRUCT_S2:%.*]], align 4
// CHECK-NEXT:    [[Z_ADDR:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[LIST:%.*]] = alloca [1 x %struct.__va_list_tag], align 16
// CHECK-NEXT:    [[TMP:%.*]] = alloca [[STRUCT_S2]], align 4
// CHECK-NEXT:    store i32 [[Z:%.*]], ptr [[Z_ADDR]], align 4
// CHECK-NEXT:    [[ARRAYDECAY:%.*]] = getelementptr inbounds [1 x %struct.__va_list_tag], ptr [[LIST]], i64 0, i64 0
// CHECK-NEXT:    call void @llvm.va_start.p0(ptr [[ARRAYDECAY]])
// CHECK-NEXT:    [[ARRAYDECAY1:%.*]] = getelementptr inbounds [1 x %struct.__va_list_tag], ptr [[LIST]], i64 0, i64 0
// CHECK-NEXT:    [[FP_OFFSET_P:%.*]] = getelementptr inbounds nuw [[STRUCT___VA_LIST_TAG:%.*]], ptr [[ARRAYDECAY1]], i32 0, i32 1
// CHECK-NEXT:    [[FP_OFFSET:%.*]] = load i32, ptr [[FP_OFFSET_P]], align 4
// CHECK-NEXT:    [[FITS_IN_FP:%.*]] = icmp ule i32 [[FP_OFFSET]], 160
// CHECK-NEXT:    br i1 [[FITS_IN_FP]], label [[VAARG_IN_REG:%.*]], label [[VAARG_IN_MEM:%.*]]
// CHECK:       vaarg.in_reg:
// CHECK-NEXT:    [[TMP0:%.*]] = getelementptr inbounds nuw [[STRUCT___VA_LIST_TAG]], ptr [[ARRAYDECAY1]], i32 0, i32 3
// CHECK-NEXT:    [[REG_SAVE_AREA:%.*]] = load ptr, ptr [[TMP0]], align 16
// CHECK-NEXT:    [[TMP1:%.*]] = getelementptr i8, ptr [[REG_SAVE_AREA]], i32 [[FP_OFFSET]]
// CHECK-NEXT:    [[TMP2:%.*]] = load <2 x float>, ptr [[TMP1]], align 4
// CHECK-NEXT:    [[TMP3:%.*]] = getelementptr i8, ptr [[TMP]], i32 8
// CHECK-NEXT:    store <2 x float> [[TMP2]], ptr [[TMP3]], align 4
// CHECK-NEXT:    [[TMP4:%.*]] = add i32 [[FP_OFFSET]], 16
// CHECK-NEXT:    store i32 [[TMP4]], ptr [[FP_OFFSET_P]], align 4
// CHECK-NEXT:    br label [[VAARG_END:%.*]]
// CHECK:       vaarg.in_mem:
// CHECK-NEXT:    [[OVERFLOW_ARG_AREA_P:%.*]] = getelementptr inbounds nuw [[STRUCT___VA_LIST_TAG]], ptr [[ARRAYDECAY1]], i32 0, i32 2
// CHECK-NEXT:    [[OVERFLOW_ARG_AREA:%.*]] = load ptr, ptr [[OVERFLOW_ARG_AREA_P]], align 8
// CHECK-NEXT:    [[OVERFLOW_ARG_AREA_NEXT:%.*]] = getelementptr i8, ptr [[OVERFLOW_ARG_AREA]], i32 16
// CHECK-NEXT:    store ptr [[OVERFLOW_ARG_AREA_NEXT]], ptr [[OVERFLOW_ARG_AREA_P]], align 8
// CHECK-NEXT:    br label [[VAARG_END]]
// CHECK:       vaarg.end:
// CHECK-NEXT:    [[VAARG_ADDR:%.*]] = phi ptr [ [[TMP]], [[VAARG_IN_REG]] ], [ [[OVERFLOW_ARG_AREA]], [[VAARG_IN_MEM]] ]
// CHECK-NEXT:    call void @llvm.memcpy.p0.p0.i64(ptr align 4 [[RETVAL]], ptr align 4 [[VAARG_ADDR]], i64 16, i1 false)
// CHECK-NEXT:    [[TMP5:%.*]] = getelementptr inbounds i8, ptr [[RETVAL]], i64 8
// CHECK-NEXT:    [[TMP6:%.*]] = load <2 x float>, ptr [[TMP5]], align 4
// CHECK-NEXT:    ret <2 x float> [[TMP6]]
//
s2 f2(int z, ...) {
  __builtin_va_list list;
  __builtin_va_start(list, z);
  return __builtin_va_arg(list, s2);
}

typedef struct {
  struct{} a;
  long long b;
} s3;

// CHECK-LABEL: @_Z2f3iz(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[RETVAL:%.*]] = alloca [[STRUCT_S3:%.*]], align 8
// CHECK-NEXT:    [[Z_ADDR:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[LIST:%.*]] = alloca [1 x %struct.__va_list_tag], align 16
// CHECK-NEXT:    [[TMP:%.*]] = alloca [[STRUCT_S3]], align 8
// CHECK-NEXT:    store i32 [[Z:%.*]], ptr [[Z_ADDR]], align 4
// CHECK-NEXT:    [[ARRAYDECAY:%.*]] = getelementptr inbounds [1 x %struct.__va_list_tag], ptr [[LIST]], i64 0, i64 0
// CHECK-NEXT:    call void @llvm.va_start.p0(ptr [[ARRAYDECAY]])
// CHECK-NEXT:    [[ARRAYDECAY1:%.*]] = getelementptr inbounds [1 x %struct.__va_list_tag], ptr [[LIST]], i64 0, i64 0
// CHECK-NEXT:    [[GP_OFFSET_P:%.*]] = getelementptr inbounds nuw [[STRUCT___VA_LIST_TAG:%.*]], ptr [[ARRAYDECAY1]], i32 0, i32 0
// CHECK-NEXT:    [[GP_OFFSET:%.*]] = load i32, ptr [[GP_OFFSET_P]], align 16
// CHECK-NEXT:    [[FITS_IN_GP:%.*]] = icmp ule i32 [[GP_OFFSET]], 40
// CHECK-NEXT:    br i1 [[FITS_IN_GP]], label [[VAARG_IN_REG:%.*]], label [[VAARG_IN_MEM:%.*]]
// CHECK:       vaarg.in_reg:
// CHECK-NEXT:    [[TMP0:%.*]] = getelementptr inbounds nuw [[STRUCT___VA_LIST_TAG]], ptr [[ARRAYDECAY1]], i32 0, i32 3
// CHECK-NEXT:    [[REG_SAVE_AREA:%.*]] = load ptr, ptr [[TMP0]], align 16
// CHECK-NEXT:    [[TMP1:%.*]] = getelementptr i8, ptr [[REG_SAVE_AREA]], i32 [[GP_OFFSET]]
// CHECK-NEXT:    [[TMP2:%.*]] = load i64, ptr [[TMP1]], align 8
// CHECK-NEXT:    [[TMP3:%.*]] = getelementptr i8, ptr [[TMP]], i32 8
// CHECK-NEXT:    store i64 [[TMP2]], ptr [[TMP3]], align 8
// CHECK-NEXT:    [[TMP4:%.*]] = add i32 [[GP_OFFSET]], 8
// CHECK-NEXT:    store i32 [[TMP4]], ptr [[GP_OFFSET_P]], align 16
// CHECK-NEXT:    br label [[VAARG_END:%.*]]
// CHECK:       vaarg.in_mem:
// CHECK-NEXT:    [[OVERFLOW_ARG_AREA_P:%.*]] = getelementptr inbounds nuw [[STRUCT___VA_LIST_TAG]], ptr [[ARRAYDECAY1]], i32 0, i32 2
// CHECK-NEXT:    [[OVERFLOW_ARG_AREA:%.*]] = load ptr, ptr [[OVERFLOW_ARG_AREA_P]], align 8
// CHECK-NEXT:    [[OVERFLOW_ARG_AREA_NEXT:%.*]] = getelementptr i8, ptr [[OVERFLOW_ARG_AREA]], i32 16
// CHECK-NEXT:    store ptr [[OVERFLOW_ARG_AREA_NEXT]], ptr [[OVERFLOW_ARG_AREA_P]], align 8
// CHECK-NEXT:    br label [[VAARG_END]]
// CHECK:       vaarg.end:
// CHECK-NEXT:    [[VAARG_ADDR:%.*]] = phi ptr [ [[TMP]], [[VAARG_IN_REG]] ], [ [[OVERFLOW_ARG_AREA]], [[VAARG_IN_MEM]] ]
// CHECK-NEXT:    call void @llvm.memcpy.p0.p0.i64(ptr align 8 [[RETVAL]], ptr align 8 [[VAARG_ADDR]], i64 16, i1 false)
// CHECK-NEXT:    [[TMP5:%.*]] = getelementptr inbounds i8, ptr [[RETVAL]], i64 8
// CHECK-NEXT:    [[TMP6:%.*]] = load i64, ptr [[TMP5]], align 8
// CHECK-NEXT:    ret i64 [[TMP6]]
//
s3 f3(int z, ...) {
  __builtin_va_list list;
  __builtin_va_start(list, z);
  return __builtin_va_arg(list, s3);
}

typedef struct {
  struct{} a[7];
  short b;
  int c;
} s4;

// CHECK-LABEL: @_Z2f4iz(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[RETVAL:%.*]] = alloca [[STRUCT_S4:%.*]], align 4
// CHECK-NEXT:    [[Z_ADDR:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[LIST:%.*]] = alloca [1 x %struct.__va_list_tag], align 16
// CHECK-NEXT:    [[TMP:%.*]] = alloca [[STRUCT_S4]], align 4
// CHECK-NEXT:    store i32 [[Z:%.*]], ptr [[Z_ADDR]], align 4
// CHECK-NEXT:    [[ARRAYDECAY:%.*]] = getelementptr inbounds [1 x %struct.__va_list_tag], ptr [[LIST]], i64 0, i64 0
// CHECK-NEXT:    call void @llvm.va_start.p0(ptr [[ARRAYDECAY]])
// CHECK-NEXT:    [[ARRAYDECAY1:%.*]] = getelementptr inbounds [1 x %struct.__va_list_tag], ptr [[LIST]], i64 0, i64 0
// CHECK-NEXT:    [[GP_OFFSET_P:%.*]] = getelementptr inbounds nuw [[STRUCT___VA_LIST_TAG:%.*]], ptr [[ARRAYDECAY1]], i32 0, i32 0
// CHECK-NEXT:    [[GP_OFFSET:%.*]] = load i32, ptr [[GP_OFFSET_P]], align 16
// CHECK-NEXT:    [[FITS_IN_GP:%.*]] = icmp ule i32 [[GP_OFFSET]], 40
// CHECK-NEXT:    br i1 [[FITS_IN_GP]], label [[VAARG_IN_REG:%.*]], label [[VAARG_IN_MEM:%.*]]
// CHECK:       vaarg.in_reg:
// CHECK-NEXT:    [[TMP0:%.*]] = getelementptr inbounds nuw [[STRUCT___VA_LIST_TAG]], ptr [[ARRAYDECAY1]], i32 0, i32 3
// CHECK-NEXT:    [[REG_SAVE_AREA:%.*]] = load ptr, ptr [[TMP0]], align 16
// CHECK-NEXT:    [[TMP1:%.*]] = getelementptr i8, ptr [[REG_SAVE_AREA]], i32 [[GP_OFFSET]]
// CHECK-NEXT:    [[TMP2:%.*]] = load i64, ptr [[TMP1]], align 4
// CHECK-NEXT:    [[TMP3:%.*]] = getelementptr i8, ptr [[TMP]], i32 8
// CHECK-NEXT:    store i64 [[TMP2]], ptr [[TMP3]], align 4
// CHECK-NEXT:    [[TMP4:%.*]] = add i32 [[GP_OFFSET]], 8
// CHECK-NEXT:    store i32 [[TMP4]], ptr [[GP_OFFSET_P]], align 16
// CHECK-NEXT:    br label [[VAARG_END:%.*]]
// CHECK:       vaarg.in_mem:
// CHECK-NEXT:    [[OVERFLOW_ARG_AREA_P:%.*]] = getelementptr inbounds nuw [[STRUCT___VA_LIST_TAG]], ptr [[ARRAYDECAY1]], i32 0, i32 2
// CHECK-NEXT:    [[OVERFLOW_ARG_AREA:%.*]] = load ptr, ptr [[OVERFLOW_ARG_AREA_P]], align 8
// CHECK-NEXT:    [[OVERFLOW_ARG_AREA_NEXT:%.*]] = getelementptr i8, ptr [[OVERFLOW_ARG_AREA]], i32 16
// CHECK-NEXT:    store ptr [[OVERFLOW_ARG_AREA_NEXT]], ptr [[OVERFLOW_ARG_AREA_P]], align 8
// CHECK-NEXT:    br label [[VAARG_END]]
// CHECK:       vaarg.end:
// CHECK-NEXT:    [[VAARG_ADDR:%.*]] = phi ptr [ [[TMP]], [[VAARG_IN_REG]] ], [ [[OVERFLOW_ARG_AREA]], [[VAARG_IN_MEM]] ]
// CHECK-NEXT:    call void @llvm.memcpy.p0.p0.i64(ptr align 4 [[RETVAL]], ptr align 4 [[VAARG_ADDR]], i64 16, i1 false)
// CHECK-NEXT:    [[TMP5:%.*]] = getelementptr inbounds i8, ptr [[RETVAL]], i64 8
// CHECK-NEXT:    [[TMP6:%.*]] = load i64, ptr [[TMP5]], align 4
// CHECK-NEXT:    ret i64 [[TMP6]]
//
s4 f4(int z, ...) {
  __builtin_va_list list;
  __builtin_va_start(list, z);
  return __builtin_va_arg(list, s4);
}

typedef struct {
  struct{} a[5];
  float b;
  int c;
} s5;

// CHECK-LABEL: @_Z2f5iz(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[RETVAL:%.*]] = alloca [[STRUCT_S5:%.*]], align 4
// CHECK-NEXT:    [[Z_ADDR:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[LIST:%.*]] = alloca [1 x %struct.__va_list_tag], align 16
// CHECK-NEXT:    [[TMP:%.*]] = alloca [[STRUCT_S5]], align 4
// CHECK-NEXT:    store i32 [[Z:%.*]], ptr [[Z_ADDR]], align 4
// CHECK-NEXT:    [[ARRAYDECAY:%.*]] = getelementptr inbounds [1 x %struct.__va_list_tag], ptr [[LIST]], i64 0, i64 0
// CHECK-NEXT:    call void @llvm.va_start.p0(ptr [[ARRAYDECAY]])
// CHECK-NEXT:    [[ARRAYDECAY1:%.*]] = getelementptr inbounds [1 x %struct.__va_list_tag], ptr [[LIST]], i64 0, i64 0
// CHECK-NEXT:    [[GP_OFFSET_P:%.*]] = getelementptr inbounds nuw [[STRUCT___VA_LIST_TAG:%.*]], ptr [[ARRAYDECAY1]], i32 0, i32 0
// CHECK-NEXT:    [[GP_OFFSET:%.*]] = load i32, ptr [[GP_OFFSET_P]], align 16
// CHECK-NEXT:    [[FITS_IN_GP:%.*]] = icmp ule i32 [[GP_OFFSET]], 40
// CHECK-NEXT:    br i1 [[FITS_IN_GP]], label [[VAARG_IN_REG:%.*]], label [[VAARG_IN_MEM:%.*]]
// CHECK:       vaarg.in_reg:
// CHECK-NEXT:    [[TMP0:%.*]] = getelementptr inbounds nuw [[STRUCT___VA_LIST_TAG]], ptr [[ARRAYDECAY1]], i32 0, i32 3
// CHECK-NEXT:    [[REG_SAVE_AREA:%.*]] = load ptr, ptr [[TMP0]], align 16
// CHECK-NEXT:    [[TMP1:%.*]] = getelementptr i8, ptr [[REG_SAVE_AREA]], i32 [[GP_OFFSET]]
// CHECK-NEXT:    [[TMP2:%.*]] = load i64, ptr [[TMP1]], align 4
// CHECK-NEXT:    [[TMP3:%.*]] = getelementptr i8, ptr [[TMP]], i32 8
// CHECK-NEXT:    store i64 [[TMP2]], ptr [[TMP3]], align 4
// CHECK-NEXT:    [[TMP4:%.*]] = add i32 [[GP_OFFSET]], 8
// CHECK-NEXT:    store i32 [[TMP4]], ptr [[GP_OFFSET_P]], align 16
// CHECK-NEXT:    br label [[VAARG_END:%.*]]
// CHECK:       vaarg.in_mem:
// CHECK-NEXT:    [[OVERFLOW_ARG_AREA_P:%.*]] = getelementptr inbounds nuw [[STRUCT___VA_LIST_TAG]], ptr [[ARRAYDECAY1]], i32 0, i32 2
// CHECK-NEXT:    [[OVERFLOW_ARG_AREA:%.*]] = load ptr, ptr [[OVERFLOW_ARG_AREA_P]], align 8
// CHECK-NEXT:    [[OVERFLOW_ARG_AREA_NEXT:%.*]] = getelementptr i8, ptr [[OVERFLOW_ARG_AREA]], i32 16
// CHECK-NEXT:    store ptr [[OVERFLOW_ARG_AREA_NEXT]], ptr [[OVERFLOW_ARG_AREA_P]], align 8
// CHECK-NEXT:    br label [[VAARG_END]]
// CHECK:       vaarg.end:
// CHECK-NEXT:    [[VAARG_ADDR:%.*]] = phi ptr [ [[TMP]], [[VAARG_IN_REG]] ], [ [[OVERFLOW_ARG_AREA]], [[VAARG_IN_MEM]] ]
// CHECK-NEXT:    call void @llvm.memcpy.p0.p0.i64(ptr align 4 [[RETVAL]], ptr align 4 [[VAARG_ADDR]], i64 16, i1 false)
// CHECK-NEXT:    [[TMP5:%.*]] = getelementptr inbounds i8, ptr [[RETVAL]], i64 8
// CHECK-NEXT:    [[TMP6:%.*]] = load i64, ptr [[TMP5]], align 4
// CHECK-NEXT:    ret i64 [[TMP6]]
//
s5 f5(int z, ...) {
  __builtin_va_list list;
  __builtin_va_start(list, z);
  return __builtin_va_arg(list, s5);
}

typedef struct {
  long long a;
  struct{} b;
} s6;

// CHECK-LABEL: @_Z2f6iz(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[RETVAL:%.*]] = alloca [[STRUCT_S6:%.*]], align 8
// CHECK-NEXT:    [[Z_ADDR:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[LIST:%.*]] = alloca [1 x %struct.__va_list_tag], align 16
// CHECK-NEXT:    [[TMP:%.*]] = alloca [[STRUCT_S6]], align 8
// CHECK-NEXT:    store i32 [[Z:%.*]], ptr [[Z_ADDR]], align 4
// CHECK-NEXT:    [[ARRAYDECAY:%.*]] = getelementptr inbounds [1 x %struct.__va_list_tag], ptr [[LIST]], i64 0, i64 0
// CHECK-NEXT:    call void @llvm.va_start.p0(ptr [[ARRAYDECAY]])
// CHECK-NEXT:    [[ARRAYDECAY1:%.*]] = getelementptr inbounds [1 x %struct.__va_list_tag], ptr [[LIST]], i64 0, i64 0
// CHECK-NEXT:    [[GP_OFFSET_P:%.*]] = getelementptr inbounds nuw [[STRUCT___VA_LIST_TAG:%.*]], ptr [[ARRAYDECAY1]], i32 0, i32 0
// CHECK-NEXT:    [[GP_OFFSET:%.*]] = load i32, ptr [[GP_OFFSET_P]], align 16
// CHECK-NEXT:    [[FITS_IN_GP:%.*]] = icmp ule i32 [[GP_OFFSET]], 40
// CHECK-NEXT:    br i1 [[FITS_IN_GP]], label [[VAARG_IN_REG:%.*]], label [[VAARG_IN_MEM:%.*]]
// CHECK:       vaarg.in_reg:
// CHECK-NEXT:    [[TMP0:%.*]] = getelementptr inbounds nuw [[STRUCT___VA_LIST_TAG]], ptr [[ARRAYDECAY1]], i32 0, i32 3
// CHECK-NEXT:    [[REG_SAVE_AREA:%.*]] = load ptr, ptr [[TMP0]], align 16
// CHECK-NEXT:    [[TMP1:%.*]] = getelementptr i8, ptr [[REG_SAVE_AREA]], i32 [[GP_OFFSET]]
// CHECK-NEXT:    [[TMP2:%.*]] = load i64, ptr [[TMP1]], align 8
// CHECK-NEXT:    [[TMP3:%.*]] = getelementptr i8, ptr [[TMP]], i32 0
// CHECK-NEXT:    store i64 [[TMP2]], ptr [[TMP3]], align 8
// CHECK-NEXT:    [[TMP4:%.*]] = add i32 [[GP_OFFSET]], 8
// CHECK-NEXT:    store i32 [[TMP4]], ptr [[GP_OFFSET_P]], align 16
// CHECK-NEXT:    br label [[VAARG_END:%.*]]
// CHECK:       vaarg.in_mem:
// CHECK-NEXT:    [[OVERFLOW_ARG_AREA_P:%.*]] = getelementptr inbounds nuw [[STRUCT___VA_LIST_TAG]], ptr [[ARRAYDECAY1]], i32 0, i32 2
// CHECK-NEXT:    [[OVERFLOW_ARG_AREA:%.*]] = load ptr, ptr [[OVERFLOW_ARG_AREA_P]], align 8
// CHECK-NEXT:    [[OVERFLOW_ARG_AREA_NEXT:%.*]] = getelementptr i8, ptr [[OVERFLOW_ARG_AREA]], i32 16
// CHECK-NEXT:    store ptr [[OVERFLOW_ARG_AREA_NEXT]], ptr [[OVERFLOW_ARG_AREA_P]], align 8
// CHECK-NEXT:    br label [[VAARG_END]]
// CHECK:       vaarg.end:
// CHECK-NEXT:    [[VAARG_ADDR:%.*]] = phi ptr [ [[TMP]], [[VAARG_IN_REG]] ], [ [[OVERFLOW_ARG_AREA]], [[VAARG_IN_MEM]] ]
// CHECK-NEXT:    call void @llvm.memcpy.p0.p0.i64(ptr align 8 [[RETVAL]], ptr align 8 [[VAARG_ADDR]], i64 16, i1 false)
// CHECK-NEXT:    [[COERCE_DIVE:%.*]] = getelementptr inbounds nuw [[STRUCT_S6]], ptr [[RETVAL]], i32 0, i32 0
// CHECK-NEXT:    [[TMP5:%.*]] = load i64, ptr [[COERCE_DIVE]], align 8
// CHECK-NEXT:    ret i64 [[TMP5]]
//
s6 f6(int z, ...) {
  __builtin_va_list list;
  __builtin_va_start(list, z);
  return __builtin_va_arg(list, s6);
}
