// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 5
// RUN: %clang_cc1 -include __clang_hip_runtime_wrapper.h      \
// RUN:   -internal-isystem %S/../../lib/Headers/cuda_wrappers \
// RUN:   -internal-isystem %S/Inputs/include \
// RUN:   -triple amdgcn-amd-amdhsa -aux-triple x86_64-unknown-unknown \
// RUN:   -target-cpu gfx906 -emit-llvm %s -fcuda-is-device -o - \
// RUN:   -D __CLANG_GPU_DISABLE_MATH_WRAPPERS | FileCheck -check-prefix=AMDGPU %s

// RUN: %clang_cc1 -include __clang_cuda_runtime_wrapper.h      \
// RUN:   -internal-isystem %S/../../lib/Headers/cuda_wrappers \
// RUN:   -internal-isystem %S/Inputs/include \
// RUN:   -triple nvptx64-nvidia-cuda -aux-triple x86_64-unknown-unknown \
// RUN:   -target-cpu sm_90 -emit-llvm %s -fcuda-is-device -o - \
// RUN:   -D __CLANG_GPU_DISABLE_MATH_WRAPPERS | FileCheck -check-prefix=NVPTX %s

extern "C" double sin(double x);

// AMDGPU-LABEL: define dso_local noundef double @_Z3food(
// AMDGPU-SAME: double noundef [[X:%.*]]) #[[ATTR0:[0-9]+]] {
// AMDGPU-NEXT:  [[ENTRY:.*:]]
// AMDGPU-NEXT:    [[RETVAL:%.*]] = alloca double, align 8, addrspace(5)
// AMDGPU-NEXT:    [[X_ADDR:%.*]] = alloca double, align 8, addrspace(5)
// AMDGPU-NEXT:    [[RETVAL_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[RETVAL]] to ptr
// AMDGPU-NEXT:    [[X_ADDR_ASCAST:%.*]] = addrspacecast ptr addrspace(5) [[X_ADDR]] to ptr
// AMDGPU-NEXT:    store double [[X]], ptr [[X_ADDR_ASCAST]], align 8
// AMDGPU-NEXT:    [[TMP0:%.*]] = load double, ptr [[X_ADDR_ASCAST]], align 8
// AMDGPU-NEXT:    [[TMP1:%.*]] = call double @llvm.sin.f64(double [[TMP0]])
// AMDGPU-NEXT:    ret double [[TMP1]]
//
// NVPTX-LABEL: define dso_local noundef double @_Z3food(
// NVPTX-SAME: double noundef [[X:%.*]]) #[[ATTR0:[0-9]+]] {
// NVPTX-NEXT:  [[ENTRY:.*:]]
// NVPTX-NEXT:    [[X_ADDR:%.*]] = alloca double, align 8
// NVPTX-NEXT:    store double [[X]], ptr [[X_ADDR]], align 8
// NVPTX-NEXT:    [[TMP0:%.*]] = load double, ptr [[X_ADDR]], align 8
// NVPTX-NEXT:    [[TMP1:%.*]] = call double @llvm.sin.f64(double [[TMP0]])
// NVPTX-NEXT:    ret double [[TMP1]]
//
double foo(double x) {
  return sin(x);
}
