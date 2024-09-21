// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --function-signature --check-globals --include-generated-funcs --replace-value-regex "__omp_offloading_[0-9a-z]+_[0-9a-z]+" "reduction_size[.].+[.]" "pl_cond[.].+[.|,]" --prefix-filecheck-ir-name _
// REQUIRES: amdgpu-registered-target

// RUN: %clang_cc1 -fopenmp -x c++ -std=c++11 -triple x86_64-unknown-unknown -fopenmp-targets=amdgcn-amd-amdhsa -emit-llvm-bc %s -o %t-ppc-host.bc
// RUN: %clang_cc1 -fopenmp -x c++ -std=c++11 -triple amdgcn-amd-amdhsa -fopenmp-targets=amdgcn-amd-amdhsa -emit-llvm %s -fopenmp-is-target-device -fopenmp-host-ir-file-path %t-ppc-host.bc -o - | FileCheck %s
// expected-no-diagnostics
#ifndef HEADER
#define HEADER

void foo(void);

struct S {
  int a;
  S() : a(1) {}
  ~S() { foo(); }
};

#pragma omp declare target
S A;
#pragma omp end declare target

#endif
//.
// CHECK: @__omp_rtl_debug_kind = weak_odr hidden addrspace(1) constant i32 0
// CHECK: @__omp_rtl_assume_teams_oversubscription = weak_odr hidden addrspace(1) constant i32 0
// CHECK: @__omp_rtl_assume_threads_oversubscription = weak_odr hidden addrspace(1) constant i32 0
// CHECK: @__omp_rtl_assume_no_thread_state = weak_odr hidden addrspace(1) constant i32 0
// CHECK: @__omp_rtl_assume_no_nested_parallelism = weak_odr hidden addrspace(1) constant i32 0
// CHECK: @A = addrspace(1) global %struct.S zeroinitializer, align 4
// CHECK: @llvm.global_ctors = appending global [1 x { i32, ptr, ptr }] [{ i32, ptr, ptr } { i32 65535, ptr @_GLOBAL__sub_I_amdgcn_target_global_constructor.cpp, ptr null }]
// CHECK: @llvm.global_dtors = appending global [1 x { i32, ptr, ptr }] [{ i32, ptr, ptr } { i32 65535, ptr @__dtor_A, ptr null }]
// CHECK: @__oclc_ABI_version = weak_odr hidden local_unnamed_addr addrspace(4) constant i32 500
//.
// CHECK-LABEL: define {{[^@]+}}@__cxx_global_var_init
// CHECK-SAME: () #[[ATTR0:[0-9]+]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    call void @_ZN1SC1Ev(ptr noundef nonnull align 4 dereferenceable(4) addrspacecast (ptr addrspace(1) @A to ptr)) #[[ATTR3:[0-9]+]]
// CHECK-NEXT:    ret void
//
//
// CHECK-LABEL: define {{[^@]+}}@_ZN1SC1Ev
// CHECK-SAME: (ptr noundef nonnull align 4 dereferenceable(4) [[THIS:%.*]]) unnamed_addr #[[ATTR1:[0-9]+]] comdat align 2 {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[THIS_ADDR:%.*]] = alloca ptr, align 8, addrspace(5)
// CHECK-NEXT:    [[THIS_ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[THIS_ADDR]] to ptr
// CHECK-NEXT:    store ptr [[THIS]], ptr [[THIS_ADDR_ASCAST]], align 8
// CHECK-NEXT:    [[THIS1:%.*]] = load ptr, ptr [[THIS_ADDR_ASCAST]], align 8
// CHECK-NEXT:    call void @_ZN1SC2Ev(ptr noundef nonnull align 4 dereferenceable(4) [[THIS1]]) #[[ATTR3]]
// CHECK-NEXT:    ret void
//
//
// CHECK-LABEL: define {{[^@]+}}@_ZN1SD1Ev
// CHECK-SAME: (ptr noundef nonnull align 4 dereferenceable(4) [[THIS:%.*]]) unnamed_addr #[[ATTR1]] comdat align 2 {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[THIS_ADDR:%.*]] = alloca ptr, align 8, addrspace(5)
// CHECK-NEXT:    [[THIS_ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[THIS_ADDR]] to ptr
// CHECK-NEXT:    store ptr [[THIS]], ptr [[THIS_ADDR_ASCAST]], align 8
// CHECK-NEXT:    [[THIS1:%.*]] = load ptr, ptr [[THIS_ADDR_ASCAST]], align 8
// CHECK-NEXT:    call void @_ZN1SD2Ev(ptr noundef nonnull align 4 dereferenceable(4) [[THIS1]]) #[[ATTR4:[0-9]+]]
// CHECK-NEXT:    ret void
//
//
// CHECK-LABEL: define {{[^@]+}}@__dtor_A
// CHECK-SAME: () #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    call void @_ZN1SD1Ev(ptr addrspacecast (ptr addrspace(1) @A to ptr))
// CHECK-NEXT:    ret void
//
//
// CHECK-LABEL: define {{[^@]+}}@_ZN1SC2Ev
// CHECK-SAME: (ptr noundef nonnull align 4 dereferenceable(4) [[THIS:%.*]]) unnamed_addr #[[ATTR1]] comdat align 2 {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[THIS_ADDR:%.*]] = alloca ptr, align 8, addrspace(5)
// CHECK-NEXT:    [[THIS_ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[THIS_ADDR]] to ptr
// CHECK-NEXT:    store ptr [[THIS]], ptr [[THIS_ADDR_ASCAST]], align 8
// CHECK-NEXT:    [[THIS1:%.*]] = load ptr, ptr [[THIS_ADDR_ASCAST]], align 8
// CHECK-NEXT:    [[A:%.*]] = getelementptr inbounds nuw [[STRUCT_S:%.*]], ptr [[THIS1]], i32 0, i32 0
// CHECK-NEXT:    store i32 1, ptr [[A]], align 4
// CHECK-NEXT:    ret void
//
//
// CHECK-LABEL: define {{[^@]+}}@_ZN1SD2Ev
// CHECK-SAME: (ptr noundef nonnull align 4 dereferenceable(4) [[THIS:%.*]]) unnamed_addr #[[ATTR1]] comdat align 2 {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[THIS_ADDR:%.*]] = alloca ptr, align 8, addrspace(5)
// CHECK-NEXT:    [[THIS_ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[THIS_ADDR]] to ptr
// CHECK-NEXT:    store ptr [[THIS]], ptr [[THIS_ADDR_ASCAST]], align 8
// CHECK-NEXT:    [[THIS1:%.*]] = load ptr, ptr [[THIS_ADDR_ASCAST]], align 8
// CHECK-NEXT:    call void @_Z3foov() #[[ATTR3]]
// CHECK-NEXT:    ret void
//
//
// CHECK-LABEL: define {{[^@]+}}@_GLOBAL__sub_I_amdgcn_target_global_constructor.cpp
// CHECK-SAME: () #[[ATTR0]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    call void @__cxx_global_var_init()
// CHECK-NEXT:    ret void
//
//.
// CHECK: attributes #[[ATTR0]] = { convergent noinline nounwind "no-trapping-math"="true" "stack-protector-buffer-size"="8" }
// CHECK: attributes #[[ATTR1]] = { convergent mustprogress noinline nounwind optnone "no-trapping-math"="true" "stack-protector-buffer-size"="8" }
// CHECK: attributes #[[ATTR2:[0-9]+]] = { convergent "no-trapping-math"="true" "stack-protector-buffer-size"="8" }
// CHECK: attributes #[[ATTR3]] = { convergent }
// CHECK: attributes #[[ATTR4]] = { convergent nounwind }
//.
// CHECK: [[META0:![0-9]+]] = !{i32 1, !"A", i32 0, i32 0}
// CHECK: [[META1:![0-9]+]] = !{i32 1, !"amdhsa_code_object_version", i32 500}
// CHECK: [[META2:![0-9]+]] = !{i32 1, !"wchar_size", i32 4}
// CHECK: [[META3:![0-9]+]] = !{i32 7, !"openmp", i32 51}
// CHECK: [[META4:![0-9]+]] = !{i32 7, !"openmp-device", i32 51}
// CHECK: [[META5:![0-9]+]] = !{!"{{.*}}clang version {{.*}}"}
//.
