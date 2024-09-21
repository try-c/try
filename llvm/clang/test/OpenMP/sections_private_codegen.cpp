// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --function-signature --include-generated-funcs --replace-value-regex "__omp_offloading_[0-9a-z]+_[0-9a-z]+" "reduction_size[.].+[.]" "pl_cond[.].+[.|,]" --prefix-filecheck-ir-name _
// RUN: %clang_cc1 -verify -fopenmp -x c++ -triple x86_64-unknown-unknown -emit-llvm %s -o - | FileCheck %s --check-prefix=CHECK1
// RUN: %clang_cc1 -fopenmp -x c++ -std=c++11 -triple x86_64-unknown-unknown -emit-pch -o %t %s
// RUN: %clang_cc1 -fopenmp -x c++ -triple x86_64-unknown-unknown -std=c++11 -include-pch %t -verify %s -emit-llvm -o - | FileCheck %s --check-prefix=CHECK1
// RUN: %clang_cc1 -verify -fopenmp -x c++ -std=c++11 -DLAMBDA -triple x86_64-unknown-linux -emit-llvm %s -o - | FileCheck %s --check-prefix=CHECK3
// RUN: %clang_cc1 -verify -fopenmp -x c++ -fblocks -DBLOCKS -triple x86_64-unknown-linux -emit-llvm %s -o - | FileCheck %s --check-prefix=CHECK4

// RUN: %clang_cc1 -verify -fopenmp-simd -x c++ -triple x86_64-unknown-unknown -emit-llvm %s -o - | FileCheck %s --implicit-check-not="{{__kmpc|__tgt}}"
// RUN: %clang_cc1 -fopenmp-simd -x c++ -std=c++11 -triple x86_64-unknown-unknown -emit-pch -o %t %s
// RUN: %clang_cc1 -fopenmp-simd -x c++ -triple x86_64-unknown-unknown -std=c++11 -include-pch %t -verify %s -emit-llvm -o - | FileCheck %s --implicit-check-not="{{__kmpc|__tgt}}"
// RUN: %clang_cc1 -verify -fopenmp-simd -x c++ -std=c++11 -DLAMBDA -triple x86_64-unknown-linux -emit-llvm %s -o - | FileCheck %s --implicit-check-not="{{__kmpc|__tgt}}"
// RUN: %clang_cc1 -verify -fopenmp-simd -x c++ -fblocks -DBLOCKS -triple x86_64-unknown-linux -emit-llvm %s -o - | FileCheck %s --implicit-check-not="{{__kmpc|__tgt}}"
// expected-no-diagnostics
#ifndef HEADER
#define HEADER

template <class T>
struct S {
  T f;
  S(T a) : f(a) {}
  S() : f() {}
  operator T() { return T(); }
  ~S() {}
};

volatile double g;

template <typename T>
T tmain() {
  S<T> test;
  T t_var = T();
  T vec[] = {1, 2};
  S<T> s_arr[] = {1, 2};
  S<T> var(3);
#pragma omp parallel
#pragma omp sections private(t_var, vec, s_arr, s_arr, var, var)
  {
    vec[0] = t_var;
#pragma omp section
    s_arr[0] = var;
  }
  return T();
}

int main() {
  static int sivar;
#ifdef LAMBDA
  [&]() {
#pragma omp parallel
#pragma omp sections private(g, sivar)
  {
    {
      g = 1;
      sivar = 11;
    }
#pragma omp section
    [&]() {
      g = 2;
      sivar = 22;


    }();
  }
  }();
  return 0;
#elif defined(BLOCKS)
  ^{
#pragma omp parallel
#pragma omp sections private(g, sivar)
    {
    {
      g = 1;
      sivar = 111;
    }
#pragma omp section
    ^{
      g = 2;
      sivar = 222;
    }();
  }
  }();
  return 0;
#else
  S<float> test;
  int t_var = 0;
  int vec[] = {1, 2};
  S<float> s_arr[] = {1, 2};
  S<float> var(3);
#pragma omp parallel
#pragma omp sections private(t_var, vec, s_arr, s_arr, var, var, sivar)
  {
    {
    vec[0] = t_var;
    s_arr[0] = var;
    sivar = 2;
    }
  }
  return tmain<int>();
#endif
}




#endif

// CHECK1-LABEL: define {{[^@]+}}@main
// CHECK1-SAME: () #[[ATTR0:[0-9]+]] {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[RETVAL:%.*]] = alloca i32, align 4
// CHECK1-NEXT:    [[TEST:%.*]] = alloca [[STRUCT_S:%.*]], align 4
// CHECK1-NEXT:    [[T_VAR:%.*]] = alloca i32, align 4
// CHECK1-NEXT:    [[VEC:%.*]] = alloca [2 x i32], align 4
// CHECK1-NEXT:    [[S_ARR:%.*]] = alloca [2 x %struct.S], align 4
// CHECK1-NEXT:    [[VAR:%.*]] = alloca [[STRUCT_S]], align 4
// CHECK1-NEXT:    store i32 0, ptr [[RETVAL]], align 4
// CHECK1-NEXT:    call void @_ZN1SIfEC1Ev(ptr noundef nonnull align 4 dereferenceable(4) [[TEST]])
// CHECK1-NEXT:    store i32 0, ptr [[T_VAR]], align 4
// CHECK1-NEXT:    call void @llvm.memcpy.p0.p0.i64(ptr align 4 [[VEC]], ptr align 4 @__const.main.vec, i64 8, i1 false)
// CHECK1-NEXT:    call void @_ZN1SIfEC1Ef(ptr noundef nonnull align 4 dereferenceable(4) [[S_ARR]], float noundef 1.000000e+00)
// CHECK1-NEXT:    [[ARRAYINIT_ELEMENT:%.*]] = getelementptr inbounds [[STRUCT_S]], ptr [[S_ARR]], i64 1
// CHECK1-NEXT:    call void @_ZN1SIfEC1Ef(ptr noundef nonnull align 4 dereferenceable(4) [[ARRAYINIT_ELEMENT]], float noundef 2.000000e+00)
// CHECK1-NEXT:    call void @_ZN1SIfEC1Ef(ptr noundef nonnull align 4 dereferenceable(4) [[VAR]], float noundef 3.000000e+00)
// CHECK1-NEXT:    call void (ptr, i32, ptr, ...) @__kmpc_fork_call(ptr @[[GLOB3:[0-9]+]], i32 0, ptr @main.omp_outlined)
// CHECK1-NEXT:    [[CALL:%.*]] = call noundef i32 @_Z5tmainIiET_v()
// CHECK1-NEXT:    store i32 [[CALL]], ptr [[RETVAL]], align 4
// CHECK1-NEXT:    call void @_ZN1SIfED1Ev(ptr noundef nonnull align 4 dereferenceable(4) [[VAR]]) #[[ATTR4:[0-9]+]]
// CHECK1-NEXT:    [[ARRAY_BEGIN:%.*]] = getelementptr inbounds [2 x %struct.S], ptr [[S_ARR]], i32 0, i32 0
// CHECK1-NEXT:    [[TMP0:%.*]] = getelementptr inbounds [[STRUCT_S]], ptr [[ARRAY_BEGIN]], i64 2
// CHECK1-NEXT:    br label [[ARRAYDESTROY_BODY:%.*]]
// CHECK1:       arraydestroy.body:
// CHECK1-NEXT:    [[ARRAYDESTROY_ELEMENTPAST:%.*]] = phi ptr [ [[TMP0]], [[ENTRY:%.*]] ], [ [[ARRAYDESTROY_ELEMENT:%.*]], [[ARRAYDESTROY_BODY]] ]
// CHECK1-NEXT:    [[ARRAYDESTROY_ELEMENT]] = getelementptr inbounds [[STRUCT_S]], ptr [[ARRAYDESTROY_ELEMENTPAST]], i64 -1
// CHECK1-NEXT:    call void @_ZN1SIfED1Ev(ptr noundef nonnull align 4 dereferenceable(4) [[ARRAYDESTROY_ELEMENT]]) #[[ATTR4]]
// CHECK1-NEXT:    [[ARRAYDESTROY_DONE:%.*]] = icmp eq ptr [[ARRAYDESTROY_ELEMENT]], [[ARRAY_BEGIN]]
// CHECK1-NEXT:    br i1 [[ARRAYDESTROY_DONE]], label [[ARRAYDESTROY_DONE1:%.*]], label [[ARRAYDESTROY_BODY]]
// CHECK1:       arraydestroy.done1:
// CHECK1-NEXT:    call void @_ZN1SIfED1Ev(ptr noundef nonnull align 4 dereferenceable(4) [[TEST]]) #[[ATTR4]]
// CHECK1-NEXT:    [[TMP1:%.*]] = load i32, ptr [[RETVAL]], align 4
// CHECK1-NEXT:    ret i32 [[TMP1]]
//
//
// CHECK1-LABEL: define {{[^@]+}}@_ZN1SIfEC1Ev
// CHECK1-SAME: (ptr noundef nonnull align 4 dereferenceable(4) [[THIS:%.*]]) unnamed_addr #[[ATTR1:[0-9]+]] comdat align 2 {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[THIS_ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    store ptr [[THIS]], ptr [[THIS_ADDR]], align 8
// CHECK1-NEXT:    [[THIS1:%.*]] = load ptr, ptr [[THIS_ADDR]], align 8
// CHECK1-NEXT:    call void @_ZN1SIfEC2Ev(ptr noundef nonnull align 4 dereferenceable(4) [[THIS1]])
// CHECK1-NEXT:    ret void
//
//
// CHECK1-LABEL: define {{[^@]+}}@_ZN1SIfEC1Ef
// CHECK1-SAME: (ptr noundef nonnull align 4 dereferenceable(4) [[THIS:%.*]], float noundef [[A:%.*]]) unnamed_addr #[[ATTR1]] comdat align 2 {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[THIS_ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[A_ADDR:%.*]] = alloca float, align 4
// CHECK1-NEXT:    store ptr [[THIS]], ptr [[THIS_ADDR]], align 8
// CHECK1-NEXT:    store float [[A]], ptr [[A_ADDR]], align 4
// CHECK1-NEXT:    [[THIS1:%.*]] = load ptr, ptr [[THIS_ADDR]], align 8
// CHECK1-NEXT:    [[TMP0:%.*]] = load float, ptr [[A_ADDR]], align 4
// CHECK1-NEXT:    call void @_ZN1SIfEC2Ef(ptr noundef nonnull align 4 dereferenceable(4) [[THIS1]], float noundef [[TMP0]])
// CHECK1-NEXT:    ret void
//
//
// CHECK1-LABEL: define {{[^@]+}}@main.omp_outlined
// CHECK1-SAME: (ptr noalias noundef [[DOTGLOBAL_TID_:%.*]], ptr noalias noundef [[DOTBOUND_TID_:%.*]]) #[[ATTR3:[0-9]+]] {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[DOTGLOBAL_TID__ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[DOTBOUND_TID__ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[DOTOMP_SECTIONS_LB_:%.*]] = alloca i32, align 4
// CHECK1-NEXT:    [[DOTOMP_SECTIONS_UB_:%.*]] = alloca i32, align 4
// CHECK1-NEXT:    [[DOTOMP_SECTIONS_ST_:%.*]] = alloca i32, align 4
// CHECK1-NEXT:    [[DOTOMP_SECTIONS_IL_:%.*]] = alloca i32, align 4
// CHECK1-NEXT:    [[DOTOMP_SECTIONS_IV_:%.*]] = alloca i32, align 4
// CHECK1-NEXT:    [[T_VAR:%.*]] = alloca i32, align 4
// CHECK1-NEXT:    [[VEC:%.*]] = alloca [2 x i32], align 4
// CHECK1-NEXT:    [[S_ARR:%.*]] = alloca [2 x %struct.S], align 4
// CHECK1-NEXT:    [[VAR:%.*]] = alloca [[STRUCT_S:%.*]], align 4
// CHECK1-NEXT:    [[SIVAR:%.*]] = alloca i32, align 4
// CHECK1-NEXT:    store ptr [[DOTGLOBAL_TID_]], ptr [[DOTGLOBAL_TID__ADDR]], align 8
// CHECK1-NEXT:    store ptr [[DOTBOUND_TID_]], ptr [[DOTBOUND_TID__ADDR]], align 8
// CHECK1-NEXT:    store i32 0, ptr [[DOTOMP_SECTIONS_LB_]], align 4
// CHECK1-NEXT:    store i32 0, ptr [[DOTOMP_SECTIONS_UB_]], align 4
// CHECK1-NEXT:    store i32 1, ptr [[DOTOMP_SECTIONS_ST_]], align 4
// CHECK1-NEXT:    store i32 0, ptr [[DOTOMP_SECTIONS_IL_]], align 4
// CHECK1-NEXT:    [[ARRAY_BEGIN:%.*]] = getelementptr inbounds [2 x %struct.S], ptr [[S_ARR]], i32 0, i32 0
// CHECK1-NEXT:    [[ARRAYCTOR_END:%.*]] = getelementptr inbounds [[STRUCT_S]], ptr [[ARRAY_BEGIN]], i64 2
// CHECK1-NEXT:    br label [[ARRAYCTOR_LOOP:%.*]]
// CHECK1:       arrayctor.loop:
// CHECK1-NEXT:    [[ARRAYCTOR_CUR:%.*]] = phi ptr [ [[ARRAY_BEGIN]], [[ENTRY:%.*]] ], [ [[ARRAYCTOR_NEXT:%.*]], [[ARRAYCTOR_LOOP]] ]
// CHECK1-NEXT:    call void @_ZN1SIfEC1Ev(ptr noundef nonnull align 4 dereferenceable(4) [[ARRAYCTOR_CUR]])
// CHECK1-NEXT:    [[ARRAYCTOR_NEXT]] = getelementptr inbounds [[STRUCT_S]], ptr [[ARRAYCTOR_CUR]], i64 1
// CHECK1-NEXT:    [[ARRAYCTOR_DONE:%.*]] = icmp eq ptr [[ARRAYCTOR_NEXT]], [[ARRAYCTOR_END]]
// CHECK1-NEXT:    br i1 [[ARRAYCTOR_DONE]], label [[ARRAYCTOR_CONT:%.*]], label [[ARRAYCTOR_LOOP]]
// CHECK1:       arrayctor.cont:
// CHECK1-NEXT:    call void @_ZN1SIfEC1Ev(ptr noundef nonnull align 4 dereferenceable(4) [[VAR]])
// CHECK1-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[DOTGLOBAL_TID__ADDR]], align 8
// CHECK1-NEXT:    [[TMP1:%.*]] = load i32, ptr [[TMP0]], align 4
// CHECK1-NEXT:    call void @__kmpc_for_static_init_4(ptr @[[GLOB1:[0-9]+]], i32 [[TMP1]], i32 34, ptr [[DOTOMP_SECTIONS_IL_]], ptr [[DOTOMP_SECTIONS_LB_]], ptr [[DOTOMP_SECTIONS_UB_]], ptr [[DOTOMP_SECTIONS_ST_]], i32 1, i32 1)
// CHECK1-NEXT:    [[TMP2:%.*]] = load i32, ptr [[DOTOMP_SECTIONS_UB_]], align 4
// CHECK1-NEXT:    [[TMP3:%.*]] = icmp slt i32 [[TMP2]], 0
// CHECK1-NEXT:    [[TMP4:%.*]] = select i1 [[TMP3]], i32 [[TMP2]], i32 0
// CHECK1-NEXT:    store i32 [[TMP4]], ptr [[DOTOMP_SECTIONS_UB_]], align 4
// CHECK1-NEXT:    [[TMP5:%.*]] = load i32, ptr [[DOTOMP_SECTIONS_LB_]], align 4
// CHECK1-NEXT:    store i32 [[TMP5]], ptr [[DOTOMP_SECTIONS_IV_]], align 4
// CHECK1-NEXT:    br label [[OMP_INNER_FOR_COND:%.*]]
// CHECK1:       omp.inner.for.cond:
// CHECK1-NEXT:    [[TMP6:%.*]] = load i32, ptr [[DOTOMP_SECTIONS_IV_]], align 4
// CHECK1-NEXT:    [[TMP7:%.*]] = load i32, ptr [[DOTOMP_SECTIONS_UB_]], align 4
// CHECK1-NEXT:    [[CMP:%.*]] = icmp sle i32 [[TMP6]], [[TMP7]]
// CHECK1-NEXT:    br i1 [[CMP]], label [[OMP_INNER_FOR_BODY:%.*]], label [[OMP_INNER_FOR_END:%.*]]
// CHECK1:       omp.inner.for.body:
// CHECK1-NEXT:    [[TMP8:%.*]] = load i32, ptr [[DOTOMP_SECTIONS_IV_]], align 4
// CHECK1-NEXT:    switch i32 [[TMP8]], label [[DOTOMP_SECTIONS_EXIT:%.*]] [
// CHECK1-NEXT:      i32 0, label [[DOTOMP_SECTIONS_CASE:%.*]]
// CHECK1-NEXT:    ]
// CHECK1:       .omp.sections.case:
// CHECK1-NEXT:    [[TMP9:%.*]] = load i32, ptr [[T_VAR]], align 4
// CHECK1-NEXT:    [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x i32], ptr [[VEC]], i64 0, i64 0
// CHECK1-NEXT:    store i32 [[TMP9]], ptr [[ARRAYIDX]], align 4
// CHECK1-NEXT:    [[ARRAYIDX1:%.*]] = getelementptr inbounds [2 x %struct.S], ptr [[S_ARR]], i64 0, i64 0
// CHECK1-NEXT:    call void @llvm.memcpy.p0.p0.i64(ptr align 4 [[ARRAYIDX1]], ptr align 4 [[VAR]], i64 4, i1 false)
// CHECK1-NEXT:    store i32 2, ptr [[SIVAR]], align 4
// CHECK1-NEXT:    br label [[DOTOMP_SECTIONS_EXIT]]
// CHECK1:       .omp.sections.exit:
// CHECK1-NEXT:    br label [[OMP_INNER_FOR_INC:%.*]]
// CHECK1:       omp.inner.for.inc:
// CHECK1-NEXT:    [[TMP10:%.*]] = load i32, ptr [[DOTOMP_SECTIONS_IV_]], align 4
// CHECK1-NEXT:    [[INC:%.*]] = add nsw i32 [[TMP10]], 1
// CHECK1-NEXT:    store i32 [[INC]], ptr [[DOTOMP_SECTIONS_IV_]], align 4
// CHECK1-NEXT:    br label [[OMP_INNER_FOR_COND]]
// CHECK1:       omp.inner.for.end:
// CHECK1-NEXT:    [[TMP11:%.*]] = load ptr, ptr [[DOTGLOBAL_TID__ADDR]], align 8
// CHECK1-NEXT:    [[TMP12:%.*]] = load i32, ptr [[TMP11]], align 4
// CHECK1-NEXT:    call void @__kmpc_for_static_fini(ptr @[[GLOB1]], i32 [[TMP12]])
// CHECK1-NEXT:    call void @_ZN1SIfED1Ev(ptr noundef nonnull align 4 dereferenceable(4) [[VAR]]) #[[ATTR4]]
// CHECK1-NEXT:    [[ARRAY_BEGIN2:%.*]] = getelementptr inbounds [2 x %struct.S], ptr [[S_ARR]], i32 0, i32 0
// CHECK1-NEXT:    [[TMP13:%.*]] = getelementptr inbounds [[STRUCT_S]], ptr [[ARRAY_BEGIN2]], i64 2
// CHECK1-NEXT:    br label [[ARRAYDESTROY_BODY:%.*]]
// CHECK1:       arraydestroy.body:
// CHECK1-NEXT:    [[ARRAYDESTROY_ELEMENTPAST:%.*]] = phi ptr [ [[TMP13]], [[OMP_INNER_FOR_END]] ], [ [[ARRAYDESTROY_ELEMENT:%.*]], [[ARRAYDESTROY_BODY]] ]
// CHECK1-NEXT:    [[ARRAYDESTROY_ELEMENT]] = getelementptr inbounds [[STRUCT_S]], ptr [[ARRAYDESTROY_ELEMENTPAST]], i64 -1
// CHECK1-NEXT:    call void @_ZN1SIfED1Ev(ptr noundef nonnull align 4 dereferenceable(4) [[ARRAYDESTROY_ELEMENT]]) #[[ATTR4]]
// CHECK1-NEXT:    [[ARRAYDESTROY_DONE:%.*]] = icmp eq ptr [[ARRAYDESTROY_ELEMENT]], [[ARRAY_BEGIN2]]
// CHECK1-NEXT:    br i1 [[ARRAYDESTROY_DONE]], label [[ARRAYDESTROY_DONE3:%.*]], label [[ARRAYDESTROY_BODY]]
// CHECK1:       arraydestroy.done3:
// CHECK1-NEXT:    [[TMP14:%.*]] = load ptr, ptr [[DOTGLOBAL_TID__ADDR]], align 8
// CHECK1-NEXT:    [[TMP15:%.*]] = load i32, ptr [[TMP14]], align 4
// CHECK1-NEXT:    call void @__kmpc_barrier(ptr @[[GLOB2:[0-9]+]], i32 [[TMP15]])
// CHECK1-NEXT:    ret void
//
//
// CHECK1-LABEL: define {{[^@]+}}@_ZN1SIfED1Ev
// CHECK1-SAME: (ptr noundef nonnull align 4 dereferenceable(4) [[THIS:%.*]]) unnamed_addr #[[ATTR1]] comdat align 2 {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[THIS_ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    store ptr [[THIS]], ptr [[THIS_ADDR]], align 8
// CHECK1-NEXT:    [[THIS1:%.*]] = load ptr, ptr [[THIS_ADDR]], align 8
// CHECK1-NEXT:    call void @_ZN1SIfED2Ev(ptr noundef nonnull align 4 dereferenceable(4) [[THIS1]]) #[[ATTR4]]
// CHECK1-NEXT:    ret void
//
//
// CHECK1-LABEL: define {{[^@]+}}@_Z5tmainIiET_v
// CHECK1-SAME: () #[[ATTR1]] comdat {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[RETVAL:%.*]] = alloca i32, align 4
// CHECK1-NEXT:    [[TEST:%.*]] = alloca [[STRUCT_S_0:%.*]], align 4
// CHECK1-NEXT:    [[T_VAR:%.*]] = alloca i32, align 4
// CHECK1-NEXT:    [[VEC:%.*]] = alloca [2 x i32], align 4
// CHECK1-NEXT:    [[S_ARR:%.*]] = alloca [2 x %struct.S.0], align 4
// CHECK1-NEXT:    [[VAR:%.*]] = alloca [[STRUCT_S_0]], align 4
// CHECK1-NEXT:    call void @_ZN1SIiEC1Ev(ptr noundef nonnull align 4 dereferenceable(4) [[TEST]])
// CHECK1-NEXT:    store i32 0, ptr [[T_VAR]], align 4
// CHECK1-NEXT:    call void @llvm.memcpy.p0.p0.i64(ptr align 4 [[VEC]], ptr align 4 @__const._Z5tmainIiET_v.vec, i64 8, i1 false)
// CHECK1-NEXT:    call void @_ZN1SIiEC1Ei(ptr noundef nonnull align 4 dereferenceable(4) [[S_ARR]], i32 noundef 1)
// CHECK1-NEXT:    [[ARRAYINIT_ELEMENT:%.*]] = getelementptr inbounds [[STRUCT_S_0]], ptr [[S_ARR]], i64 1
// CHECK1-NEXT:    call void @_ZN1SIiEC1Ei(ptr noundef nonnull align 4 dereferenceable(4) [[ARRAYINIT_ELEMENT]], i32 noundef 2)
// CHECK1-NEXT:    call void @_ZN1SIiEC1Ei(ptr noundef nonnull align 4 dereferenceable(4) [[VAR]], i32 noundef 3)
// CHECK1-NEXT:    call void (ptr, i32, ptr, ...) @__kmpc_fork_call(ptr @[[GLOB3]], i32 0, ptr @_Z5tmainIiET_v.omp_outlined)
// CHECK1-NEXT:    store i32 0, ptr [[RETVAL]], align 4
// CHECK1-NEXT:    call void @_ZN1SIiED1Ev(ptr noundef nonnull align 4 dereferenceable(4) [[VAR]]) #[[ATTR4]]
// CHECK1-NEXT:    [[ARRAY_BEGIN:%.*]] = getelementptr inbounds [2 x %struct.S.0], ptr [[S_ARR]], i32 0, i32 0
// CHECK1-NEXT:    [[TMP0:%.*]] = getelementptr inbounds [[STRUCT_S_0]], ptr [[ARRAY_BEGIN]], i64 2
// CHECK1-NEXT:    br label [[ARRAYDESTROY_BODY:%.*]]
// CHECK1:       arraydestroy.body:
// CHECK1-NEXT:    [[ARRAYDESTROY_ELEMENTPAST:%.*]] = phi ptr [ [[TMP0]], [[ENTRY:%.*]] ], [ [[ARRAYDESTROY_ELEMENT:%.*]], [[ARRAYDESTROY_BODY]] ]
// CHECK1-NEXT:    [[ARRAYDESTROY_ELEMENT]] = getelementptr inbounds [[STRUCT_S_0]], ptr [[ARRAYDESTROY_ELEMENTPAST]], i64 -1
// CHECK1-NEXT:    call void @_ZN1SIiED1Ev(ptr noundef nonnull align 4 dereferenceable(4) [[ARRAYDESTROY_ELEMENT]]) #[[ATTR4]]
// CHECK1-NEXT:    [[ARRAYDESTROY_DONE:%.*]] = icmp eq ptr [[ARRAYDESTROY_ELEMENT]], [[ARRAY_BEGIN]]
// CHECK1-NEXT:    br i1 [[ARRAYDESTROY_DONE]], label [[ARRAYDESTROY_DONE1:%.*]], label [[ARRAYDESTROY_BODY]]
// CHECK1:       arraydestroy.done1:
// CHECK1-NEXT:    call void @_ZN1SIiED1Ev(ptr noundef nonnull align 4 dereferenceable(4) [[TEST]]) #[[ATTR4]]
// CHECK1-NEXT:    [[TMP1:%.*]] = load i32, ptr [[RETVAL]], align 4
// CHECK1-NEXT:    ret i32 [[TMP1]]
//
//
// CHECK1-LABEL: define {{[^@]+}}@_ZN1SIfEC2Ev
// CHECK1-SAME: (ptr noundef nonnull align 4 dereferenceable(4) [[THIS:%.*]]) unnamed_addr #[[ATTR1]] comdat align 2 {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[THIS_ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    store ptr [[THIS]], ptr [[THIS_ADDR]], align 8
// CHECK1-NEXT:    [[THIS1:%.*]] = load ptr, ptr [[THIS_ADDR]], align 8
// CHECK1-NEXT:    [[F:%.*]] = getelementptr inbounds nuw [[STRUCT_S:%.*]], ptr [[THIS1]], i32 0, i32 0
// CHECK1-NEXT:    store float 0.000000e+00, ptr [[F]], align 4
// CHECK1-NEXT:    ret void
//
//
// CHECK1-LABEL: define {{[^@]+}}@_ZN1SIfEC2Ef
// CHECK1-SAME: (ptr noundef nonnull align 4 dereferenceable(4) [[THIS:%.*]], float noundef [[A:%.*]]) unnamed_addr #[[ATTR1]] comdat align 2 {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[THIS_ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[A_ADDR:%.*]] = alloca float, align 4
// CHECK1-NEXT:    store ptr [[THIS]], ptr [[THIS_ADDR]], align 8
// CHECK1-NEXT:    store float [[A]], ptr [[A_ADDR]], align 4
// CHECK1-NEXT:    [[THIS1:%.*]] = load ptr, ptr [[THIS_ADDR]], align 8
// CHECK1-NEXT:    [[F:%.*]] = getelementptr inbounds nuw [[STRUCT_S:%.*]], ptr [[THIS1]], i32 0, i32 0
// CHECK1-NEXT:    [[TMP0:%.*]] = load float, ptr [[A_ADDR]], align 4
// CHECK1-NEXT:    store float [[TMP0]], ptr [[F]], align 4
// CHECK1-NEXT:    ret void
//
//
// CHECK1-LABEL: define {{[^@]+}}@_ZN1SIfED2Ev
// CHECK1-SAME: (ptr noundef nonnull align 4 dereferenceable(4) [[THIS:%.*]]) unnamed_addr #[[ATTR1]] comdat align 2 {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[THIS_ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    store ptr [[THIS]], ptr [[THIS_ADDR]], align 8
// CHECK1-NEXT:    [[THIS1:%.*]] = load ptr, ptr [[THIS_ADDR]], align 8
// CHECK1-NEXT:    ret void
//
//
// CHECK1-LABEL: define {{[^@]+}}@_ZN1SIiEC1Ev
// CHECK1-SAME: (ptr noundef nonnull align 4 dereferenceable(4) [[THIS:%.*]]) unnamed_addr #[[ATTR1]] comdat align 2 {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[THIS_ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    store ptr [[THIS]], ptr [[THIS_ADDR]], align 8
// CHECK1-NEXT:    [[THIS1:%.*]] = load ptr, ptr [[THIS_ADDR]], align 8
// CHECK1-NEXT:    call void @_ZN1SIiEC2Ev(ptr noundef nonnull align 4 dereferenceable(4) [[THIS1]])
// CHECK1-NEXT:    ret void
//
//
// CHECK1-LABEL: define {{[^@]+}}@_ZN1SIiEC1Ei
// CHECK1-SAME: (ptr noundef nonnull align 4 dereferenceable(4) [[THIS:%.*]], i32 noundef [[A:%.*]]) unnamed_addr #[[ATTR1]] comdat align 2 {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[THIS_ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[A_ADDR:%.*]] = alloca i32, align 4
// CHECK1-NEXT:    store ptr [[THIS]], ptr [[THIS_ADDR]], align 8
// CHECK1-NEXT:    store i32 [[A]], ptr [[A_ADDR]], align 4
// CHECK1-NEXT:    [[THIS1:%.*]] = load ptr, ptr [[THIS_ADDR]], align 8
// CHECK1-NEXT:    [[TMP0:%.*]] = load i32, ptr [[A_ADDR]], align 4
// CHECK1-NEXT:    call void @_ZN1SIiEC2Ei(ptr noundef nonnull align 4 dereferenceable(4) [[THIS1]], i32 noundef [[TMP0]])
// CHECK1-NEXT:    ret void
//
//
// CHECK1-LABEL: define {{[^@]+}}@_Z5tmainIiET_v.omp_outlined
// CHECK1-SAME: (ptr noalias noundef [[DOTGLOBAL_TID_:%.*]], ptr noalias noundef [[DOTBOUND_TID_:%.*]]) #[[ATTR3]] {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[DOTGLOBAL_TID__ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[DOTBOUND_TID__ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[DOTOMP_SECTIONS_LB_:%.*]] = alloca i32, align 4
// CHECK1-NEXT:    [[DOTOMP_SECTIONS_UB_:%.*]] = alloca i32, align 4
// CHECK1-NEXT:    [[DOTOMP_SECTIONS_ST_:%.*]] = alloca i32, align 4
// CHECK1-NEXT:    [[DOTOMP_SECTIONS_IL_:%.*]] = alloca i32, align 4
// CHECK1-NEXT:    [[DOTOMP_SECTIONS_IV_:%.*]] = alloca i32, align 4
// CHECK1-NEXT:    [[T_VAR:%.*]] = alloca i32, align 4
// CHECK1-NEXT:    [[VEC:%.*]] = alloca [2 x i32], align 4
// CHECK1-NEXT:    [[S_ARR:%.*]] = alloca [2 x %struct.S.0], align 4
// CHECK1-NEXT:    [[VAR:%.*]] = alloca [[STRUCT_S_0:%.*]], align 4
// CHECK1-NEXT:    store ptr [[DOTGLOBAL_TID_]], ptr [[DOTGLOBAL_TID__ADDR]], align 8
// CHECK1-NEXT:    store ptr [[DOTBOUND_TID_]], ptr [[DOTBOUND_TID__ADDR]], align 8
// CHECK1-NEXT:    store i32 0, ptr [[DOTOMP_SECTIONS_LB_]], align 4
// CHECK1-NEXT:    store i32 1, ptr [[DOTOMP_SECTIONS_UB_]], align 4
// CHECK1-NEXT:    store i32 1, ptr [[DOTOMP_SECTIONS_ST_]], align 4
// CHECK1-NEXT:    store i32 0, ptr [[DOTOMP_SECTIONS_IL_]], align 4
// CHECK1-NEXT:    [[ARRAY_BEGIN:%.*]] = getelementptr inbounds [2 x %struct.S.0], ptr [[S_ARR]], i32 0, i32 0
// CHECK1-NEXT:    [[ARRAYCTOR_END:%.*]] = getelementptr inbounds [[STRUCT_S_0]], ptr [[ARRAY_BEGIN]], i64 2
// CHECK1-NEXT:    br label [[ARRAYCTOR_LOOP:%.*]]
// CHECK1:       arrayctor.loop:
// CHECK1-NEXT:    [[ARRAYCTOR_CUR:%.*]] = phi ptr [ [[ARRAY_BEGIN]], [[ENTRY:%.*]] ], [ [[ARRAYCTOR_NEXT:%.*]], [[ARRAYCTOR_LOOP]] ]
// CHECK1-NEXT:    call void @_ZN1SIiEC1Ev(ptr noundef nonnull align 4 dereferenceable(4) [[ARRAYCTOR_CUR]])
// CHECK1-NEXT:    [[ARRAYCTOR_NEXT]] = getelementptr inbounds [[STRUCT_S_0]], ptr [[ARRAYCTOR_CUR]], i64 1
// CHECK1-NEXT:    [[ARRAYCTOR_DONE:%.*]] = icmp eq ptr [[ARRAYCTOR_NEXT]], [[ARRAYCTOR_END]]
// CHECK1-NEXT:    br i1 [[ARRAYCTOR_DONE]], label [[ARRAYCTOR_CONT:%.*]], label [[ARRAYCTOR_LOOP]]
// CHECK1:       arrayctor.cont:
// CHECK1-NEXT:    call void @_ZN1SIiEC1Ev(ptr noundef nonnull align 4 dereferenceable(4) [[VAR]])
// CHECK1-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[DOTGLOBAL_TID__ADDR]], align 8
// CHECK1-NEXT:    [[TMP1:%.*]] = load i32, ptr [[TMP0]], align 4
// CHECK1-NEXT:    call void @__kmpc_for_static_init_4(ptr @[[GLOB1]], i32 [[TMP1]], i32 34, ptr [[DOTOMP_SECTIONS_IL_]], ptr [[DOTOMP_SECTIONS_LB_]], ptr [[DOTOMP_SECTIONS_UB_]], ptr [[DOTOMP_SECTIONS_ST_]], i32 1, i32 1)
// CHECK1-NEXT:    [[TMP2:%.*]] = load i32, ptr [[DOTOMP_SECTIONS_UB_]], align 4
// CHECK1-NEXT:    [[TMP3:%.*]] = icmp slt i32 [[TMP2]], 1
// CHECK1-NEXT:    [[TMP4:%.*]] = select i1 [[TMP3]], i32 [[TMP2]], i32 1
// CHECK1-NEXT:    store i32 [[TMP4]], ptr [[DOTOMP_SECTIONS_UB_]], align 4
// CHECK1-NEXT:    [[TMP5:%.*]] = load i32, ptr [[DOTOMP_SECTIONS_LB_]], align 4
// CHECK1-NEXT:    store i32 [[TMP5]], ptr [[DOTOMP_SECTIONS_IV_]], align 4
// CHECK1-NEXT:    br label [[OMP_INNER_FOR_COND:%.*]]
// CHECK1:       omp.inner.for.cond:
// CHECK1-NEXT:    [[TMP6:%.*]] = load i32, ptr [[DOTOMP_SECTIONS_IV_]], align 4
// CHECK1-NEXT:    [[TMP7:%.*]] = load i32, ptr [[DOTOMP_SECTIONS_UB_]], align 4
// CHECK1-NEXT:    [[CMP:%.*]] = icmp sle i32 [[TMP6]], [[TMP7]]
// CHECK1-NEXT:    br i1 [[CMP]], label [[OMP_INNER_FOR_BODY:%.*]], label [[OMP_INNER_FOR_END:%.*]]
// CHECK1:       omp.inner.for.body:
// CHECK1-NEXT:    [[TMP8:%.*]] = load i32, ptr [[DOTOMP_SECTIONS_IV_]], align 4
// CHECK1-NEXT:    switch i32 [[TMP8]], label [[DOTOMP_SECTIONS_EXIT:%.*]] [
// CHECK1-NEXT:      i32 0, label [[DOTOMP_SECTIONS_CASE:%.*]]
// CHECK1-NEXT:      i32 1, label [[DOTOMP_SECTIONS_CASE1:%.*]]
// CHECK1-NEXT:    ]
// CHECK1:       .omp.sections.case:
// CHECK1-NEXT:    [[TMP9:%.*]] = load i32, ptr [[T_VAR]], align 4
// CHECK1-NEXT:    [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x i32], ptr [[VEC]], i64 0, i64 0
// CHECK1-NEXT:    store i32 [[TMP9]], ptr [[ARRAYIDX]], align 4
// CHECK1-NEXT:    br label [[DOTOMP_SECTIONS_EXIT]]
// CHECK1:       .omp.sections.case1:
// CHECK1-NEXT:    [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x %struct.S.0], ptr [[S_ARR]], i64 0, i64 0
// CHECK1-NEXT:    call void @llvm.memcpy.p0.p0.i64(ptr align 4 [[ARRAYIDX2]], ptr align 4 [[VAR]], i64 4, i1 false)
// CHECK1-NEXT:    br label [[DOTOMP_SECTIONS_EXIT]]
// CHECK1:       .omp.sections.exit:
// CHECK1-NEXT:    br label [[OMP_INNER_FOR_INC:%.*]]
// CHECK1:       omp.inner.for.inc:
// CHECK1-NEXT:    [[TMP10:%.*]] = load i32, ptr [[DOTOMP_SECTIONS_IV_]], align 4
// CHECK1-NEXT:    [[INC:%.*]] = add nsw i32 [[TMP10]], 1
// CHECK1-NEXT:    store i32 [[INC]], ptr [[DOTOMP_SECTIONS_IV_]], align 4
// CHECK1-NEXT:    br label [[OMP_INNER_FOR_COND]]
// CHECK1:       omp.inner.for.end:
// CHECK1-NEXT:    [[TMP11:%.*]] = load ptr, ptr [[DOTGLOBAL_TID__ADDR]], align 8
// CHECK1-NEXT:    [[TMP12:%.*]] = load i32, ptr [[TMP11]], align 4
// CHECK1-NEXT:    call void @__kmpc_for_static_fini(ptr @[[GLOB1]], i32 [[TMP12]])
// CHECK1-NEXT:    call void @_ZN1SIiED1Ev(ptr noundef nonnull align 4 dereferenceable(4) [[VAR]]) #[[ATTR4]]
// CHECK1-NEXT:    [[ARRAY_BEGIN3:%.*]] = getelementptr inbounds [2 x %struct.S.0], ptr [[S_ARR]], i32 0, i32 0
// CHECK1-NEXT:    [[TMP13:%.*]] = getelementptr inbounds [[STRUCT_S_0]], ptr [[ARRAY_BEGIN3]], i64 2
// CHECK1-NEXT:    br label [[ARRAYDESTROY_BODY:%.*]]
// CHECK1:       arraydestroy.body:
// CHECK1-NEXT:    [[ARRAYDESTROY_ELEMENTPAST:%.*]] = phi ptr [ [[TMP13]], [[OMP_INNER_FOR_END]] ], [ [[ARRAYDESTROY_ELEMENT:%.*]], [[ARRAYDESTROY_BODY]] ]
// CHECK1-NEXT:    [[ARRAYDESTROY_ELEMENT]] = getelementptr inbounds [[STRUCT_S_0]], ptr [[ARRAYDESTROY_ELEMENTPAST]], i64 -1
// CHECK1-NEXT:    call void @_ZN1SIiED1Ev(ptr noundef nonnull align 4 dereferenceable(4) [[ARRAYDESTROY_ELEMENT]]) #[[ATTR4]]
// CHECK1-NEXT:    [[ARRAYDESTROY_DONE:%.*]] = icmp eq ptr [[ARRAYDESTROY_ELEMENT]], [[ARRAY_BEGIN3]]
// CHECK1-NEXT:    br i1 [[ARRAYDESTROY_DONE]], label [[ARRAYDESTROY_DONE4:%.*]], label [[ARRAYDESTROY_BODY]]
// CHECK1:       arraydestroy.done4:
// CHECK1-NEXT:    [[TMP14:%.*]] = load ptr, ptr [[DOTGLOBAL_TID__ADDR]], align 8
// CHECK1-NEXT:    [[TMP15:%.*]] = load i32, ptr [[TMP14]], align 4
// CHECK1-NEXT:    call void @__kmpc_barrier(ptr @[[GLOB2]], i32 [[TMP15]])
// CHECK1-NEXT:    ret void
//
//
// CHECK1-LABEL: define {{[^@]+}}@_ZN1SIiED1Ev
// CHECK1-SAME: (ptr noundef nonnull align 4 dereferenceable(4) [[THIS:%.*]]) unnamed_addr #[[ATTR1]] comdat align 2 {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[THIS_ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    store ptr [[THIS]], ptr [[THIS_ADDR]], align 8
// CHECK1-NEXT:    [[THIS1:%.*]] = load ptr, ptr [[THIS_ADDR]], align 8
// CHECK1-NEXT:    call void @_ZN1SIiED2Ev(ptr noundef nonnull align 4 dereferenceable(4) [[THIS1]]) #[[ATTR4]]
// CHECK1-NEXT:    ret void
//
//
// CHECK1-LABEL: define {{[^@]+}}@_ZN1SIiEC2Ev
// CHECK1-SAME: (ptr noundef nonnull align 4 dereferenceable(4) [[THIS:%.*]]) unnamed_addr #[[ATTR1]] comdat align 2 {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[THIS_ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    store ptr [[THIS]], ptr [[THIS_ADDR]], align 8
// CHECK1-NEXT:    [[THIS1:%.*]] = load ptr, ptr [[THIS_ADDR]], align 8
// CHECK1-NEXT:    [[F:%.*]] = getelementptr inbounds nuw [[STRUCT_S_0:%.*]], ptr [[THIS1]], i32 0, i32 0
// CHECK1-NEXT:    store i32 0, ptr [[F]], align 4
// CHECK1-NEXT:    ret void
//
//
// CHECK1-LABEL: define {{[^@]+}}@_ZN1SIiEC2Ei
// CHECK1-SAME: (ptr noundef nonnull align 4 dereferenceable(4) [[THIS:%.*]], i32 noundef [[A:%.*]]) unnamed_addr #[[ATTR1]] comdat align 2 {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[THIS_ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[A_ADDR:%.*]] = alloca i32, align 4
// CHECK1-NEXT:    store ptr [[THIS]], ptr [[THIS_ADDR]], align 8
// CHECK1-NEXT:    store i32 [[A]], ptr [[A_ADDR]], align 4
// CHECK1-NEXT:    [[THIS1:%.*]] = load ptr, ptr [[THIS_ADDR]], align 8
// CHECK1-NEXT:    [[F:%.*]] = getelementptr inbounds nuw [[STRUCT_S_0:%.*]], ptr [[THIS1]], i32 0, i32 0
// CHECK1-NEXT:    [[TMP0:%.*]] = load i32, ptr [[A_ADDR]], align 4
// CHECK1-NEXT:    store i32 [[TMP0]], ptr [[F]], align 4
// CHECK1-NEXT:    ret void
//
//
// CHECK1-LABEL: define {{[^@]+}}@_ZN1SIiED2Ev
// CHECK1-SAME: (ptr noundef nonnull align 4 dereferenceable(4) [[THIS:%.*]]) unnamed_addr #[[ATTR1]] comdat align 2 {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[THIS_ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    store ptr [[THIS]], ptr [[THIS_ADDR]], align 8
// CHECK1-NEXT:    [[THIS1:%.*]] = load ptr, ptr [[THIS_ADDR]], align 8
// CHECK1-NEXT:    ret void
//
//
// CHECK3-LABEL: define {{[^@]+}}@main
// CHECK3-SAME: () #[[ATTR0:[0-9]+]] {
// CHECK3-NEXT:  entry:
// CHECK3-NEXT:    [[RETVAL:%.*]] = alloca i32, align 4
// CHECK3-NEXT:    [[REF_TMP:%.*]] = alloca [[CLASS_ANON:%.*]], align 1
// CHECK3-NEXT:    store i32 0, ptr [[RETVAL]], align 4
// CHECK3-NEXT:    call void @"_ZZ4mainENK3$_0clEv"(ptr noundef nonnull align 1 dereferenceable(1) [[REF_TMP]])
// CHECK3-NEXT:    ret i32 0
//
//
// CHECK4-LABEL: define {{[^@]+}}@main
// CHECK4-SAME: () #[[ATTR1:[0-9]+]] {
// CHECK4-NEXT:  entry:
// CHECK4-NEXT:    [[RETVAL:%.*]] = alloca i32, align 4
// CHECK4-NEXT:    store i32 0, ptr [[RETVAL]], align 4
// CHECK4-NEXT:    [[TMP0:%.*]] = load ptr, ptr getelementptr inbounds nuw ([[STRUCT___BLOCK_LITERAL_GENERIC:%.*]], ptr @__block_literal_global, i32 0, i32 3), align 8
// CHECK4-NEXT:    call void [[TMP0]](ptr noundef @__block_literal_global)
// CHECK4-NEXT:    ret i32 0
//
//
// CHECK4-LABEL: define {{[^@]+}}@__main_block_invoke
// CHECK4-SAME: (ptr noundef [[DOTBLOCK_DESCRIPTOR:%.*]]) #[[ATTR2:[0-9]+]] {
// CHECK4-NEXT:  entry:
// CHECK4-NEXT:    [[DOTBLOCK_DESCRIPTOR_ADDR:%.*]] = alloca ptr, align 8
// CHECK4-NEXT:    [[BLOCK_ADDR:%.*]] = alloca ptr, align 8
// CHECK4-NEXT:    store ptr [[DOTBLOCK_DESCRIPTOR]], ptr [[DOTBLOCK_DESCRIPTOR_ADDR]], align 8
// CHECK4-NEXT:    store ptr [[DOTBLOCK_DESCRIPTOR]], ptr [[BLOCK_ADDR]], align 8
// CHECK4-NEXT:    call void (ptr, i32, ptr, ...) @__kmpc_fork_call(ptr @[[GLOB3:[0-9]+]], i32 0, ptr @__main_block_invoke.omp_outlined)
// CHECK4-NEXT:    ret void
//
//
// CHECK4-LABEL: define {{[^@]+}}@__main_block_invoke.omp_outlined
// CHECK4-SAME: (ptr noalias noundef [[DOTGLOBAL_TID_:%.*]], ptr noalias noundef [[DOTBOUND_TID_:%.*]]) #[[ATTR3:[0-9]+]] {
// CHECK4-NEXT:  entry:
// CHECK4-NEXT:    [[DOTGLOBAL_TID__ADDR:%.*]] = alloca ptr, align 8
// CHECK4-NEXT:    [[DOTBOUND_TID__ADDR:%.*]] = alloca ptr, align 8
// CHECK4-NEXT:    [[DOTOMP_SECTIONS_LB_:%.*]] = alloca i32, align 4
// CHECK4-NEXT:    [[DOTOMP_SECTIONS_UB_:%.*]] = alloca i32, align 4
// CHECK4-NEXT:    [[DOTOMP_SECTIONS_ST_:%.*]] = alloca i32, align 4
// CHECK4-NEXT:    [[DOTOMP_SECTIONS_IL_:%.*]] = alloca i32, align 4
// CHECK4-NEXT:    [[DOTOMP_SECTIONS_IV_:%.*]] = alloca i32, align 4
// CHECK4-NEXT:    [[G:%.*]] = alloca double, align 8
// CHECK4-NEXT:    [[SIVAR:%.*]] = alloca i32, align 4
// CHECK4-NEXT:    [[BLOCK:%.*]] = alloca <{ ptr, i32, i32, ptr, ptr, double, i32 }>, align 8
// CHECK4-NEXT:    store ptr [[DOTGLOBAL_TID_]], ptr [[DOTGLOBAL_TID__ADDR]], align 8
// CHECK4-NEXT:    store ptr [[DOTBOUND_TID_]], ptr [[DOTBOUND_TID__ADDR]], align 8
// CHECK4-NEXT:    store i32 0, ptr [[DOTOMP_SECTIONS_LB_]], align 4
// CHECK4-NEXT:    store i32 1, ptr [[DOTOMP_SECTIONS_UB_]], align 4
// CHECK4-NEXT:    store i32 1, ptr [[DOTOMP_SECTIONS_ST_]], align 4
// CHECK4-NEXT:    store i32 0, ptr [[DOTOMP_SECTIONS_IL_]], align 4
// CHECK4-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[DOTGLOBAL_TID__ADDR]], align 8
// CHECK4-NEXT:    [[TMP1:%.*]] = load i32, ptr [[TMP0]], align 4
// CHECK4-NEXT:    call void @__kmpc_for_static_init_4(ptr @[[GLOB1:[0-9]+]], i32 [[TMP1]], i32 34, ptr [[DOTOMP_SECTIONS_IL_]], ptr [[DOTOMP_SECTIONS_LB_]], ptr [[DOTOMP_SECTIONS_UB_]], ptr [[DOTOMP_SECTIONS_ST_]], i32 1, i32 1)
// CHECK4-NEXT:    [[TMP2:%.*]] = load i32, ptr [[DOTOMP_SECTIONS_UB_]], align 4
// CHECK4-NEXT:    [[TMP3:%.*]] = icmp slt i32 [[TMP2]], 1
// CHECK4-NEXT:    [[TMP4:%.*]] = select i1 [[TMP3]], i32 [[TMP2]], i32 1
// CHECK4-NEXT:    store i32 [[TMP4]], ptr [[DOTOMP_SECTIONS_UB_]], align 4
// CHECK4-NEXT:    [[TMP5:%.*]] = load i32, ptr [[DOTOMP_SECTIONS_LB_]], align 4
// CHECK4-NEXT:    store i32 [[TMP5]], ptr [[DOTOMP_SECTIONS_IV_]], align 4
// CHECK4-NEXT:    br label [[OMP_INNER_FOR_COND:%.*]]
// CHECK4:       omp.inner.for.cond:
// CHECK4-NEXT:    [[TMP6:%.*]] = load i32, ptr [[DOTOMP_SECTIONS_IV_]], align 4
// CHECK4-NEXT:    [[TMP7:%.*]] = load i32, ptr [[DOTOMP_SECTIONS_UB_]], align 4
// CHECK4-NEXT:    [[CMP:%.*]] = icmp sle i32 [[TMP6]], [[TMP7]]
// CHECK4-NEXT:    br i1 [[CMP]], label [[OMP_INNER_FOR_BODY:%.*]], label [[OMP_INNER_FOR_END:%.*]]
// CHECK4:       omp.inner.for.body:
// CHECK4-NEXT:    [[TMP8:%.*]] = load i32, ptr [[DOTOMP_SECTIONS_IV_]], align 4
// CHECK4-NEXT:    switch i32 [[TMP8]], label [[DOTOMP_SECTIONS_EXIT:%.*]] [
// CHECK4-NEXT:      i32 0, label [[DOTOMP_SECTIONS_CASE:%.*]]
// CHECK4-NEXT:      i32 1, label [[DOTOMP_SECTIONS_CASE1:%.*]]
// CHECK4-NEXT:    ]
// CHECK4:       .omp.sections.case:
// CHECK4-NEXT:    store double 1.000000e+00, ptr [[G]], align 8
// CHECK4-NEXT:    store i32 111, ptr [[SIVAR]], align 4
// CHECK4-NEXT:    br label [[DOTOMP_SECTIONS_EXIT]]
// CHECK4:       .omp.sections.case1:
// CHECK4-NEXT:    [[BLOCK_ISA:%.*]] = getelementptr inbounds nuw <{ ptr, i32, i32, ptr, ptr, double, i32 }>, ptr [[BLOCK]], i32 0, i32 0
// CHECK4-NEXT:    store ptr @_NSConcreteStackBlock, ptr [[BLOCK_ISA]], align 8
// CHECK4-NEXT:    [[BLOCK_FLAGS:%.*]] = getelementptr inbounds nuw <{ ptr, i32, i32, ptr, ptr, double, i32 }>, ptr [[BLOCK]], i32 0, i32 1
// CHECK4-NEXT:    store i32 1073741824, ptr [[BLOCK_FLAGS]], align 8
// CHECK4-NEXT:    [[BLOCK_RESERVED:%.*]] = getelementptr inbounds nuw <{ ptr, i32, i32, ptr, ptr, double, i32 }>, ptr [[BLOCK]], i32 0, i32 2
// CHECK4-NEXT:    store i32 0, ptr [[BLOCK_RESERVED]], align 4
// CHECK4-NEXT:    [[BLOCK_INVOKE:%.*]] = getelementptr inbounds nuw <{ ptr, i32, i32, ptr, ptr, double, i32 }>, ptr [[BLOCK]], i32 0, i32 3
// CHECK4-NEXT:    store ptr @_block_invoke, ptr [[BLOCK_INVOKE]], align 8
// CHECK4-NEXT:    [[BLOCK_DESCRIPTOR:%.*]] = getelementptr inbounds nuw <{ ptr, i32, i32, ptr, ptr, double, i32 }>, ptr [[BLOCK]], i32 0, i32 4
// CHECK4-NEXT:    store ptr @__block_descriptor_tmp.1, ptr [[BLOCK_DESCRIPTOR]], align 8
// CHECK4-NEXT:    [[BLOCK_CAPTURED:%.*]] = getelementptr inbounds nuw <{ ptr, i32, i32, ptr, ptr, double, i32 }>, ptr [[BLOCK]], i32 0, i32 5
// CHECK4-NEXT:    [[TMP9:%.*]] = load volatile double, ptr [[G]], align 8
// CHECK4-NEXT:    store volatile double [[TMP9]], ptr [[BLOCK_CAPTURED]], align 8
// CHECK4-NEXT:    [[BLOCK_CAPTURED2:%.*]] = getelementptr inbounds nuw <{ ptr, i32, i32, ptr, ptr, double, i32 }>, ptr [[BLOCK]], i32 0, i32 6
// CHECK4-NEXT:    [[TMP10:%.*]] = load i32, ptr [[SIVAR]], align 4
// CHECK4-NEXT:    store i32 [[TMP10]], ptr [[BLOCK_CAPTURED2]], align 8
// CHECK4-NEXT:    [[TMP11:%.*]] = getelementptr inbounds nuw [[STRUCT___BLOCK_LITERAL_GENERIC:%.*]], ptr [[BLOCK]], i32 0, i32 3
// CHECK4-NEXT:    [[TMP12:%.*]] = load ptr, ptr [[TMP11]], align 8
// CHECK4-NEXT:    call void [[TMP12]](ptr noundef [[BLOCK]])
// CHECK4-NEXT:    br label [[DOTOMP_SECTIONS_EXIT]]
// CHECK4:       .omp.sections.exit:
// CHECK4-NEXT:    br label [[OMP_INNER_FOR_INC:%.*]]
// CHECK4:       omp.inner.for.inc:
// CHECK4-NEXT:    [[TMP13:%.*]] = load i32, ptr [[DOTOMP_SECTIONS_IV_]], align 4
// CHECK4-NEXT:    [[INC:%.*]] = add nsw i32 [[TMP13]], 1
// CHECK4-NEXT:    store i32 [[INC]], ptr [[DOTOMP_SECTIONS_IV_]], align 4
// CHECK4-NEXT:    br label [[OMP_INNER_FOR_COND]]
// CHECK4:       omp.inner.for.end:
// CHECK4-NEXT:    call void @__kmpc_for_static_fini(ptr @[[GLOB1]], i32 [[TMP1]])
// CHECK4-NEXT:    call void @__kmpc_barrier(ptr @[[GLOB2:[0-9]+]], i32 [[TMP1]])
// CHECK4-NEXT:    ret void
//
//
// CHECK4-LABEL: define {{[^@]+}}@_block_invoke
// CHECK4-SAME: (ptr noundef [[DOTBLOCK_DESCRIPTOR:%.*]]) #[[ATTR2]] {
// CHECK4-NEXT:  entry:
// CHECK4-NEXT:    [[DOTBLOCK_DESCRIPTOR_ADDR:%.*]] = alloca ptr, align 8
// CHECK4-NEXT:    [[BLOCK_ADDR:%.*]] = alloca ptr, align 8
// CHECK4-NEXT:    store ptr [[DOTBLOCK_DESCRIPTOR]], ptr [[DOTBLOCK_DESCRIPTOR_ADDR]], align 8
// CHECK4-NEXT:    store ptr [[DOTBLOCK_DESCRIPTOR]], ptr [[BLOCK_ADDR]], align 8
// CHECK4-NEXT:    [[BLOCK_CAPTURE_ADDR:%.*]] = getelementptr inbounds nuw <{ ptr, i32, i32, ptr, ptr, double, i32 }>, ptr [[DOTBLOCK_DESCRIPTOR]], i32 0, i32 5
// CHECK4-NEXT:    store double 2.000000e+00, ptr [[BLOCK_CAPTURE_ADDR]], align 8
// CHECK4-NEXT:    [[BLOCK_CAPTURE_ADDR1:%.*]] = getelementptr inbounds nuw <{ ptr, i32, i32, ptr, ptr, double, i32 }>, ptr [[DOTBLOCK_DESCRIPTOR]], i32 0, i32 6
// CHECK4-NEXT:    store i32 222, ptr [[BLOCK_CAPTURE_ADDR1]], align 8
// CHECK4-NEXT:    ret void
//
