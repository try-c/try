// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --function-signature --include-generated-funcs --replace-value-regex "__omp_offloading_[0-9a-z]+_[0-9a-z]+" "reduction_size[.].+[.]" "pl_cond[.].+[.|,]" --prefix-filecheck-ir-name _
// RUN: %clang_cc1 -verify -fopenmp -fopenmp-targets=x86_64-pc-linux-gnu  \
// RUN:  -x c++ -triple x86_64-unknown-linux-gnu -emit-llvm %s -o - \
// RUN:   | FileCheck %s

// expected-no-diagnostics


class A {
protected:
  int X;
  int Y;

public:
  A (int x, int y) : X { x }, Y { y } { };
};

class B : public A {
  using A::X;
  using A::Y;
public:
  int res;
  B (int x, int y) : A(x,y), res{0} {}
  void run (void) {
  #pragma omp target
     res = X + Y;
  }
};

template<typename T>
struct descriptor
{
  T *A;
  T *C;
  T *C_ref;
  unsigned M;
  unsigned K;
  unsigned N;
};

class BASE
{
};

//template<typename T>
class C : public BASE
{
public:
  void bar (descriptor<float> &d)
  {
     auto Asize = d.M * d.K;
     auto Csize = d.M * d.N;
     #pragma omp target data map(to:d.A[0:Asize]) map(from:d.C[0:Csize])
     {
       #pragma omp target teams firstprivate(Csize)
       for (int i = 0; i < Csize; ++i)
          d.C[i] = 1;
     }
     #pragma omp target map(from:d.C[0:Csize])
       for (int i = 0; i < Csize; ++i)
          d.C[i] = 1;
   }
};

void foo() {
  B b(2, 3);
  b.run();
  C c;
  descriptor<float> d;
  c.bar(d);
}

// CHECK-LABEL: define {{[^@]+}}@_Z3foov
// CHECK-SAME: () #[[ATTR0:[0-9]+]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[B:%.*]] = alloca [[CLASS_B:%.*]], align 4
// CHECK-NEXT:    [[C:%.*]] = alloca [[CLASS_C:%.*]], align 1
// CHECK-NEXT:    [[D:%.*]] = alloca [[STRUCT_DESCRIPTOR:%.*]], align 8
// CHECK-NEXT:    call void @_ZN1BC1Eii(ptr noundef nonnull align 4 dereferenceable(12) [[B]], i32 noundef 2, i32 noundef 3)
// CHECK-NEXT:    call void @_ZN1B3runEv(ptr noundef nonnull align 4 dereferenceable(12) [[B]])
// CHECK-NEXT:    call void @_ZN1C3barER10descriptorIfE(ptr noundef nonnull align 1 dereferenceable(1) [[C]], ptr noundef nonnull align 8 dereferenceable(40) [[D]])
// CHECK-NEXT:    ret void
//
//
// CHECK-LABEL: define {{[^@]+}}@_ZN1BC1Eii
// CHECK-SAME: (ptr noundef nonnull align 4 dereferenceable(12) [[THIS:%.*]], i32 noundef [[X:%.*]], i32 noundef [[Y:%.*]]) unnamed_addr #[[ATTR0]] comdat align 2 {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[THIS_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[X_ADDR:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[Y_ADDR:%.*]] = alloca i32, align 4
// CHECK-NEXT:    store ptr [[THIS]], ptr [[THIS_ADDR]], align 8
// CHECK-NEXT:    store i32 [[X]], ptr [[X_ADDR]], align 4
// CHECK-NEXT:    store i32 [[Y]], ptr [[Y_ADDR]], align 4
// CHECK-NEXT:    [[THIS1:%.*]] = load ptr, ptr [[THIS_ADDR]], align 8
// CHECK-NEXT:    [[TMP0:%.*]] = load i32, ptr [[X_ADDR]], align 4
// CHECK-NEXT:    [[TMP1:%.*]] = load i32, ptr [[Y_ADDR]], align 4
// CHECK-NEXT:    call void @_ZN1BC2Eii(ptr noundef nonnull align 4 dereferenceable(12) [[THIS1]], i32 noundef [[TMP0]], i32 noundef [[TMP1]])
// CHECK-NEXT:    ret void
//
//
// CHECK-LABEL: define {{[^@]+}}@_ZN1B3runEv
// CHECK-SAME: (ptr noundef nonnull align 4 dereferenceable(12) [[THIS:%.*]]) #[[ATTR0]] comdat align 2 {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[THIS_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[DOTOFFLOAD_BASEPTRS:%.*]] = alloca [4 x ptr], align 8
// CHECK-NEXT:    [[DOTOFFLOAD_PTRS:%.*]] = alloca [4 x ptr], align 8
// CHECK-NEXT:    [[DOTOFFLOAD_MAPPERS:%.*]] = alloca [4 x ptr], align 8
// CHECK-NEXT:    [[KERNEL_ARGS:%.*]] = alloca [[STRUCT___TGT_KERNEL_ARGUMENTS:%.*]], align 8
// CHECK-NEXT:    store ptr [[THIS]], ptr [[THIS_ADDR]], align 8
// CHECK-NEXT:    [[THIS1:%.*]] = load ptr, ptr [[THIS_ADDR]], align 8
// CHECK-NEXT:    [[RES:%.*]] = getelementptr inbounds nuw [[CLASS_B:%.*]], ptr [[THIS1]], i32 0, i32 1
// CHECK-NEXT:    [[X:%.*]] = getelementptr inbounds nuw [[CLASS_A:%.*]], ptr [[THIS1]], i32 0, i32 0
// CHECK-NEXT:    [[Y:%.*]] = getelementptr inbounds nuw [[CLASS_A]], ptr [[THIS1]], i32 0, i32 1
// CHECK-NEXT:    [[TMP0:%.*]] = getelementptr inbounds [4 x ptr], ptr [[DOTOFFLOAD_BASEPTRS]], i32 0, i32 0
// CHECK-NEXT:    store ptr [[THIS1]], ptr [[TMP0]], align 8
// CHECK-NEXT:    [[TMP1:%.*]] = getelementptr inbounds [4 x ptr], ptr [[DOTOFFLOAD_PTRS]], i32 0, i32 0
// CHECK-NEXT:    store ptr [[THIS1]], ptr [[TMP1]], align 8
// CHECK-NEXT:    [[TMP2:%.*]] = getelementptr inbounds [4 x ptr], ptr [[DOTOFFLOAD_MAPPERS]], i64 0, i64 0
// CHECK-NEXT:    store ptr null, ptr [[TMP2]], align 8
// CHECK-NEXT:    [[TMP3:%.*]] = getelementptr inbounds [4 x ptr], ptr [[DOTOFFLOAD_BASEPTRS]], i32 0, i32 1
// CHECK-NEXT:    store ptr [[THIS1]], ptr [[TMP3]], align 8
// CHECK-NEXT:    [[TMP4:%.*]] = getelementptr inbounds [4 x ptr], ptr [[DOTOFFLOAD_PTRS]], i32 0, i32 1
// CHECK-NEXT:    store ptr [[RES]], ptr [[TMP4]], align 8
// CHECK-NEXT:    [[TMP5:%.*]] = getelementptr inbounds [4 x ptr], ptr [[DOTOFFLOAD_MAPPERS]], i64 0, i64 1
// CHECK-NEXT:    store ptr null, ptr [[TMP5]], align 8
// CHECK-NEXT:    [[TMP6:%.*]] = getelementptr inbounds [4 x ptr], ptr [[DOTOFFLOAD_BASEPTRS]], i32 0, i32 2
// CHECK-NEXT:    store ptr [[THIS1]], ptr [[TMP6]], align 8
// CHECK-NEXT:    [[TMP7:%.*]] = getelementptr inbounds [4 x ptr], ptr [[DOTOFFLOAD_PTRS]], i32 0, i32 2
// CHECK-NEXT:    store ptr [[X]], ptr [[TMP7]], align 8
// CHECK-NEXT:    [[TMP8:%.*]] = getelementptr inbounds [4 x ptr], ptr [[DOTOFFLOAD_MAPPERS]], i64 0, i64 2
// CHECK-NEXT:    store ptr null, ptr [[TMP8]], align 8
// CHECK-NEXT:    [[TMP9:%.*]] = getelementptr inbounds [4 x ptr], ptr [[DOTOFFLOAD_BASEPTRS]], i32 0, i32 3
// CHECK-NEXT:    store ptr [[THIS1]], ptr [[TMP9]], align 8
// CHECK-NEXT:    [[TMP10:%.*]] = getelementptr inbounds [4 x ptr], ptr [[DOTOFFLOAD_PTRS]], i32 0, i32 3
// CHECK-NEXT:    store ptr [[Y]], ptr [[TMP10]], align 8
// CHECK-NEXT:    [[TMP11:%.*]] = getelementptr inbounds [4 x ptr], ptr [[DOTOFFLOAD_MAPPERS]], i64 0, i64 3
// CHECK-NEXT:    store ptr null, ptr [[TMP11]], align 8
// CHECK-NEXT:    [[TMP12:%.*]] = getelementptr inbounds [4 x ptr], ptr [[DOTOFFLOAD_BASEPTRS]], i32 0, i32 0
// CHECK-NEXT:    [[TMP13:%.*]] = getelementptr inbounds [4 x ptr], ptr [[DOTOFFLOAD_PTRS]], i32 0, i32 0
// CHECK-NEXT:    [[TMP14:%.*]] = getelementptr inbounds nuw [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS]], i32 0, i32 0
// CHECK-NEXT:    store i32 3, ptr [[TMP14]], align 4
// CHECK-NEXT:    [[TMP15:%.*]] = getelementptr inbounds nuw [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS]], i32 0, i32 1
// CHECK-NEXT:    store i32 4, ptr [[TMP15]], align 4
// CHECK-NEXT:    [[TMP16:%.*]] = getelementptr inbounds nuw [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS]], i32 0, i32 2
// CHECK-NEXT:    store ptr [[TMP12]], ptr [[TMP16]], align 8
// CHECK-NEXT:    [[TMP17:%.*]] = getelementptr inbounds nuw [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS]], i32 0, i32 3
// CHECK-NEXT:    store ptr [[TMP13]], ptr [[TMP17]], align 8
// CHECK-NEXT:    [[TMP18:%.*]] = getelementptr inbounds nuw [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS]], i32 0, i32 4
// CHECK-NEXT:    store ptr @.offload_sizes, ptr [[TMP18]], align 8
// CHECK-NEXT:    [[TMP19:%.*]] = getelementptr inbounds nuw [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS]], i32 0, i32 5
// CHECK-NEXT:    store ptr @.offload_maptypes, ptr [[TMP19]], align 8
// CHECK-NEXT:    [[TMP20:%.*]] = getelementptr inbounds nuw [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS]], i32 0, i32 6
// CHECK-NEXT:    store ptr null, ptr [[TMP20]], align 8
// CHECK-NEXT:    [[TMP21:%.*]] = getelementptr inbounds nuw [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS]], i32 0, i32 7
// CHECK-NEXT:    store ptr null, ptr [[TMP21]], align 8
// CHECK-NEXT:    [[TMP22:%.*]] = getelementptr inbounds nuw [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS]], i32 0, i32 8
// CHECK-NEXT:    store i64 0, ptr [[TMP22]], align 8
// CHECK-NEXT:    [[TMP23:%.*]] = getelementptr inbounds nuw [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS]], i32 0, i32 9
// CHECK-NEXT:    store i64 0, ptr [[TMP23]], align 8
// CHECK-NEXT:    [[TMP24:%.*]] = getelementptr inbounds nuw [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS]], i32 0, i32 10
// CHECK-NEXT:    store [3 x i32] [i32 -1, i32 0, i32 0], ptr [[TMP24]], align 4
// CHECK-NEXT:    [[TMP25:%.*]] = getelementptr inbounds nuw [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS]], i32 0, i32 11
// CHECK-NEXT:    store [3 x i32] zeroinitializer, ptr [[TMP25]], align 4
// CHECK-NEXT:    [[TMP26:%.*]] = getelementptr inbounds nuw [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS]], i32 0, i32 12
// CHECK-NEXT:    store i32 0, ptr [[TMP26]], align 4
// CHECK-NEXT:    [[TMP27:%.*]] = call i32 @__tgt_target_kernel(ptr @[[GLOB1:[0-9]+]], i64 -1, i32 -1, i32 0, ptr @.{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}__ZN1B3runEv_l25.region_id, ptr [[KERNEL_ARGS]])
// CHECK-NEXT:    [[TMP28:%.*]] = icmp ne i32 [[TMP27]], 0
// CHECK-NEXT:    br i1 [[TMP28]], label [[OMP_OFFLOAD_FAILED:%.*]], label [[OMP_OFFLOAD_CONT:%.*]]
// CHECK:       omp_offload.failed:
// CHECK-NEXT:    call void @{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}__ZN1B3runEv_l25(ptr [[THIS1]]) #[[ATTR2:[0-9]+]]
// CHECK-NEXT:    br label [[OMP_OFFLOAD_CONT]]
// CHECK:       omp_offload.cont:
// CHECK-NEXT:    ret void
//
//
// CHECK-LABEL: define {{[^@]+}}@_ZN1C3barER10descriptorIfE
// CHECK-SAME: (ptr noundef nonnull align 1 dereferenceable(1) [[THIS:%.*]], ptr noundef nonnull align 8 dereferenceable(40) [[D:%.*]]) #[[ATTR0]] comdat align 2 {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[THIS_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[D_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[ASIZE:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[CSIZE:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[DOTOFFLOAD_BASEPTRS:%.*]] = alloca [3 x ptr], align 8
// CHECK-NEXT:    [[DOTOFFLOAD_PTRS:%.*]] = alloca [3 x ptr], align 8
// CHECK-NEXT:    [[DOTOFFLOAD_MAPPERS:%.*]] = alloca [3 x ptr], align 8
// CHECK-NEXT:    [[DOTOFFLOAD_SIZES:%.*]] = alloca [3 x i64], align 8
// CHECK-NEXT:    [[TMP:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[_TMP8:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[CSIZE_CASTED:%.*]] = alloca i64, align 8
// CHECK-NEXT:    [[DOTOFFLOAD_BASEPTRS9:%.*]] = alloca [2 x ptr], align 8
// CHECK-NEXT:    [[DOTOFFLOAD_PTRS10:%.*]] = alloca [2 x ptr], align 8
// CHECK-NEXT:    [[DOTOFFLOAD_MAPPERS11:%.*]] = alloca [2 x ptr], align 8
// CHECK-NEXT:    [[KERNEL_ARGS:%.*]] = alloca [[STRUCT___TGT_KERNEL_ARGUMENTS:%.*]], align 8
// CHECK-NEXT:    [[_TMP12:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[CSIZE_CASTED13:%.*]] = alloca i64, align 8
// CHECK-NEXT:    [[DOTOFFLOAD_BASEPTRS18:%.*]] = alloca [3 x ptr], align 8
// CHECK-NEXT:    [[DOTOFFLOAD_PTRS19:%.*]] = alloca [3 x ptr], align 8
// CHECK-NEXT:    [[DOTOFFLOAD_MAPPERS20:%.*]] = alloca [3 x ptr], align 8
// CHECK-NEXT:    [[DOTOFFLOAD_SIZES21:%.*]] = alloca [3 x i64], align 8
// CHECK-NEXT:    [[KERNEL_ARGS22:%.*]] = alloca [[STRUCT___TGT_KERNEL_ARGUMENTS]], align 8
// CHECK-NEXT:    store ptr [[THIS]], ptr [[THIS_ADDR]], align 8
// CHECK-NEXT:    store ptr [[D]], ptr [[D_ADDR]], align 8
// CHECK-NEXT:    [[THIS1:%.*]] = load ptr, ptr [[THIS_ADDR]], align 8
// CHECK-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[D_ADDR]], align 8
// CHECK-NEXT:    [[M:%.*]] = getelementptr inbounds nuw [[STRUCT_DESCRIPTOR:%.*]], ptr [[TMP0]], i32 0, i32 3
// CHECK-NEXT:    [[TMP1:%.*]] = load i32, ptr [[M]], align 8
// CHECK-NEXT:    [[TMP2:%.*]] = load ptr, ptr [[D_ADDR]], align 8
// CHECK-NEXT:    [[K:%.*]] = getelementptr inbounds nuw [[STRUCT_DESCRIPTOR]], ptr [[TMP2]], i32 0, i32 4
// CHECK-NEXT:    [[TMP3:%.*]] = load i32, ptr [[K]], align 4
// CHECK-NEXT:    [[MUL:%.*]] = mul i32 [[TMP1]], [[TMP3]]
// CHECK-NEXT:    store i32 [[MUL]], ptr [[ASIZE]], align 4
// CHECK-NEXT:    [[TMP4:%.*]] = load ptr, ptr [[D_ADDR]], align 8
// CHECK-NEXT:    [[M2:%.*]] = getelementptr inbounds nuw [[STRUCT_DESCRIPTOR]], ptr [[TMP4]], i32 0, i32 3
// CHECK-NEXT:    [[TMP5:%.*]] = load i32, ptr [[M2]], align 8
// CHECK-NEXT:    [[TMP6:%.*]] = load ptr, ptr [[D_ADDR]], align 8
// CHECK-NEXT:    [[N:%.*]] = getelementptr inbounds nuw [[STRUCT_DESCRIPTOR]], ptr [[TMP6]], i32 0, i32 5
// CHECK-NEXT:    [[TMP7:%.*]] = load i32, ptr [[N]], align 8
// CHECK-NEXT:    [[MUL3:%.*]] = mul i32 [[TMP5]], [[TMP7]]
// CHECK-NEXT:    store i32 [[MUL3]], ptr [[CSIZE]], align 4
// CHECK-NEXT:    [[TMP8:%.*]] = load ptr, ptr [[D_ADDR]], align 8
// CHECK-NEXT:    [[TMP9:%.*]] = load ptr, ptr [[D_ADDR]], align 8
// CHECK-NEXT:    [[A:%.*]] = getelementptr inbounds nuw [[STRUCT_DESCRIPTOR]], ptr [[TMP9]], i32 0, i32 0
// CHECK-NEXT:    [[TMP10:%.*]] = load ptr, ptr [[D_ADDR]], align 8
// CHECK-NEXT:    [[A4:%.*]] = getelementptr inbounds nuw [[STRUCT_DESCRIPTOR]], ptr [[TMP10]], i32 0, i32 0
// CHECK-NEXT:    [[TMP11:%.*]] = load ptr, ptr [[A4]], align 8
// CHECK-NEXT:    [[ARRAYIDX:%.*]] = getelementptr inbounds float, ptr [[TMP11]], i64 0
// CHECK-NEXT:    [[TMP12:%.*]] = load i32, ptr [[ASIZE]], align 4
// CHECK-NEXT:    [[CONV:%.*]] = zext i32 [[TMP12]] to i64
// CHECK-NEXT:    [[TMP13:%.*]] = mul nuw i64 [[CONV]], 4
// CHECK-NEXT:    [[TMP14:%.*]] = load ptr, ptr [[D_ADDR]], align 8
// CHECK-NEXT:    [[TMP15:%.*]] = load ptr, ptr [[D_ADDR]], align 8
// CHECK-NEXT:    [[C:%.*]] = getelementptr inbounds nuw [[STRUCT_DESCRIPTOR]], ptr [[TMP15]], i32 0, i32 1
// CHECK-NEXT:    [[TMP16:%.*]] = load ptr, ptr [[D_ADDR]], align 8
// CHECK-NEXT:    [[C5:%.*]] = getelementptr inbounds nuw [[STRUCT_DESCRIPTOR]], ptr [[TMP16]], i32 0, i32 1
// CHECK-NEXT:    [[TMP17:%.*]] = load ptr, ptr [[C5]], align 8
// CHECK-NEXT:    [[ARRAYIDX6:%.*]] = getelementptr inbounds float, ptr [[TMP17]], i64 0
// CHECK-NEXT:    [[TMP18:%.*]] = load i32, ptr [[CSIZE]], align 4
// CHECK-NEXT:    [[CONV7:%.*]] = zext i32 [[TMP18]] to i64
// CHECK-NEXT:    [[TMP19:%.*]] = mul nuw i64 [[CONV7]], 4
// CHECK-NEXT:    [[TMP20:%.*]] = getelementptr ptr, ptr [[C]], i32 1
// CHECK-NEXT:    [[TMP21:%.*]] = ptrtoint ptr [[TMP20]] to i64
// CHECK-NEXT:    [[TMP22:%.*]] = ptrtoint ptr [[A]] to i64
// CHECK-NEXT:    [[TMP23:%.*]] = sub i64 [[TMP21]], [[TMP22]]
// CHECK-NEXT:    [[TMP24:%.*]] = sdiv exact i64 [[TMP23]], ptrtoint (ptr getelementptr (i8, ptr null, i32 1) to i64)
// CHECK-NEXT:    [[TMP25:%.*]] = getelementptr inbounds [3 x ptr], ptr [[DOTOFFLOAD_BASEPTRS]], i32 0, i32 0
// CHECK-NEXT:    store ptr [[TMP8]], ptr [[TMP25]], align 8
// CHECK-NEXT:    [[TMP26:%.*]] = getelementptr inbounds [3 x ptr], ptr [[DOTOFFLOAD_PTRS]], i32 0, i32 0
// CHECK-NEXT:    store ptr [[A]], ptr [[TMP26]], align 8
// CHECK-NEXT:    [[TMP27:%.*]] = getelementptr inbounds [3 x i64], ptr [[DOTOFFLOAD_SIZES]], i32 0, i32 0
// CHECK-NEXT:    store i64 [[TMP24]], ptr [[TMP27]], align 8
// CHECK-NEXT:    [[TMP28:%.*]] = getelementptr inbounds [3 x ptr], ptr [[DOTOFFLOAD_MAPPERS]], i64 0, i64 0
// CHECK-NEXT:    store ptr null, ptr [[TMP28]], align 8
// CHECK-NEXT:    [[TMP29:%.*]] = getelementptr inbounds [3 x ptr], ptr [[DOTOFFLOAD_BASEPTRS]], i32 0, i32 1
// CHECK-NEXT:    store ptr [[A]], ptr [[TMP29]], align 8
// CHECK-NEXT:    [[TMP30:%.*]] = getelementptr inbounds [3 x ptr], ptr [[DOTOFFLOAD_PTRS]], i32 0, i32 1
// CHECK-NEXT:    store ptr [[ARRAYIDX]], ptr [[TMP30]], align 8
// CHECK-NEXT:    [[TMP31:%.*]] = getelementptr inbounds [3 x i64], ptr [[DOTOFFLOAD_SIZES]], i32 0, i32 1
// CHECK-NEXT:    store i64 [[TMP13]], ptr [[TMP31]], align 8
// CHECK-NEXT:    [[TMP32:%.*]] = getelementptr inbounds [3 x ptr], ptr [[DOTOFFLOAD_MAPPERS]], i64 0, i64 1
// CHECK-NEXT:    store ptr null, ptr [[TMP32]], align 8
// CHECK-NEXT:    [[TMP33:%.*]] = getelementptr inbounds [3 x ptr], ptr [[DOTOFFLOAD_BASEPTRS]], i32 0, i32 2
// CHECK-NEXT:    store ptr [[C]], ptr [[TMP33]], align 8
// CHECK-NEXT:    [[TMP34:%.*]] = getelementptr inbounds [3 x ptr], ptr [[DOTOFFLOAD_PTRS]], i32 0, i32 2
// CHECK-NEXT:    store ptr [[ARRAYIDX6]], ptr [[TMP34]], align 8
// CHECK-NEXT:    [[TMP35:%.*]] = getelementptr inbounds [3 x i64], ptr [[DOTOFFLOAD_SIZES]], i32 0, i32 2
// CHECK-NEXT:    store i64 [[TMP19]], ptr [[TMP35]], align 8
// CHECK-NEXT:    [[TMP36:%.*]] = getelementptr inbounds [3 x ptr], ptr [[DOTOFFLOAD_MAPPERS]], i64 0, i64 2
// CHECK-NEXT:    store ptr null, ptr [[TMP36]], align 8
// CHECK-NEXT:    [[TMP37:%.*]] = getelementptr inbounds [3 x ptr], ptr [[DOTOFFLOAD_BASEPTRS]], i32 0, i32 0
// CHECK-NEXT:    [[TMP38:%.*]] = getelementptr inbounds [3 x ptr], ptr [[DOTOFFLOAD_PTRS]], i32 0, i32 0
// CHECK-NEXT:    [[TMP39:%.*]] = getelementptr inbounds [3 x i64], ptr [[DOTOFFLOAD_SIZES]], i32 0, i32 0
// CHECK-NEXT:    call void @__tgt_target_data_begin_mapper(ptr @[[GLOB1]], i64 -1, i32 3, ptr [[TMP37]], ptr [[TMP38]], ptr [[TMP39]], ptr @.offload_maptypes.1, ptr null, ptr null)
// CHECK-NEXT:    [[TMP40:%.*]] = load ptr, ptr [[D_ADDR]], align 8
// CHECK-NEXT:    store ptr [[TMP40]], ptr [[TMP]], align 8
// CHECK-NEXT:    [[TMP41:%.*]] = load ptr, ptr [[TMP]], align 8
// CHECK-NEXT:    store ptr [[TMP41]], ptr [[_TMP8]], align 8
// CHECK-NEXT:    [[TMP42:%.*]] = load i32, ptr [[CSIZE]], align 4
// CHECK-NEXT:    store i32 [[TMP42]], ptr [[CSIZE_CASTED]], align 4
// CHECK-NEXT:    [[TMP43:%.*]] = load i64, ptr [[CSIZE_CASTED]], align 8
// CHECK-NEXT:    [[TMP44:%.*]] = load ptr, ptr [[_TMP8]], align 8
// CHECK-NEXT:    [[TMP45:%.*]] = load ptr, ptr [[_TMP8]], align 8
// CHECK-NEXT:    [[TMP46:%.*]] = load ptr, ptr [[_TMP8]], align 8
// CHECK-NEXT:    [[TMP47:%.*]] = getelementptr inbounds [2 x ptr], ptr [[DOTOFFLOAD_BASEPTRS9]], i32 0, i32 0
// CHECK-NEXT:    store i64 [[TMP43]], ptr [[TMP47]], align 8
// CHECK-NEXT:    [[TMP48:%.*]] = getelementptr inbounds [2 x ptr], ptr [[DOTOFFLOAD_PTRS10]], i32 0, i32 0
// CHECK-NEXT:    store i64 [[TMP43]], ptr [[TMP48]], align 8
// CHECK-NEXT:    [[TMP49:%.*]] = getelementptr inbounds [2 x ptr], ptr [[DOTOFFLOAD_MAPPERS11]], i64 0, i64 0
// CHECK-NEXT:    store ptr null, ptr [[TMP49]], align 8
// CHECK-NEXT:    [[TMP50:%.*]] = getelementptr inbounds [2 x ptr], ptr [[DOTOFFLOAD_BASEPTRS9]], i32 0, i32 1
// CHECK-NEXT:    store ptr [[TMP45]], ptr [[TMP50]], align 8
// CHECK-NEXT:    [[TMP51:%.*]] = getelementptr inbounds [2 x ptr], ptr [[DOTOFFLOAD_PTRS10]], i32 0, i32 1
// CHECK-NEXT:    store ptr [[TMP46]], ptr [[TMP51]], align 8
// CHECK-NEXT:    [[TMP52:%.*]] = getelementptr inbounds [2 x ptr], ptr [[DOTOFFLOAD_MAPPERS11]], i64 0, i64 1
// CHECK-NEXT:    store ptr null, ptr [[TMP52]], align 8
// CHECK-NEXT:    [[TMP53:%.*]] = getelementptr inbounds [2 x ptr], ptr [[DOTOFFLOAD_BASEPTRS9]], i32 0, i32 0
// CHECK-NEXT:    [[TMP54:%.*]] = getelementptr inbounds [2 x ptr], ptr [[DOTOFFLOAD_PTRS10]], i32 0, i32 0
// CHECK-NEXT:    [[TMP55:%.*]] = getelementptr inbounds nuw [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS]], i32 0, i32 0
// CHECK-NEXT:    store i32 3, ptr [[TMP55]], align 4
// CHECK-NEXT:    [[TMP56:%.*]] = getelementptr inbounds nuw [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS]], i32 0, i32 1
// CHECK-NEXT:    store i32 2, ptr [[TMP56]], align 4
// CHECK-NEXT:    [[TMP57:%.*]] = getelementptr inbounds nuw [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS]], i32 0, i32 2
// CHECK-NEXT:    store ptr [[TMP53]], ptr [[TMP57]], align 8
// CHECK-NEXT:    [[TMP58:%.*]] = getelementptr inbounds nuw [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS]], i32 0, i32 3
// CHECK-NEXT:    store ptr [[TMP54]], ptr [[TMP58]], align 8
// CHECK-NEXT:    [[TMP59:%.*]] = getelementptr inbounds nuw [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS]], i32 0, i32 4
// CHECK-NEXT:    store ptr @.offload_sizes.2, ptr [[TMP59]], align 8
// CHECK-NEXT:    [[TMP60:%.*]] = getelementptr inbounds nuw [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS]], i32 0, i32 5
// CHECK-NEXT:    store ptr @.offload_maptypes.3, ptr [[TMP60]], align 8
// CHECK-NEXT:    [[TMP61:%.*]] = getelementptr inbounds nuw [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS]], i32 0, i32 6
// CHECK-NEXT:    store ptr null, ptr [[TMP61]], align 8
// CHECK-NEXT:    [[TMP62:%.*]] = getelementptr inbounds nuw [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS]], i32 0, i32 7
// CHECK-NEXT:    store ptr null, ptr [[TMP62]], align 8
// CHECK-NEXT:    [[TMP63:%.*]] = getelementptr inbounds nuw [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS]], i32 0, i32 8
// CHECK-NEXT:    store i64 0, ptr [[TMP63]], align 8
// CHECK-NEXT:    [[TMP64:%.*]] = getelementptr inbounds nuw [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS]], i32 0, i32 9
// CHECK-NEXT:    store i64 0, ptr [[TMP64]], align 8
// CHECK-NEXT:    [[TMP65:%.*]] = getelementptr inbounds nuw [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS]], i32 0, i32 10
// CHECK-NEXT:    store [3 x i32] zeroinitializer, ptr [[TMP65]], align 4
// CHECK-NEXT:    [[TMP66:%.*]] = getelementptr inbounds nuw [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS]], i32 0, i32 11
// CHECK-NEXT:    store [3 x i32] zeroinitializer, ptr [[TMP66]], align 4
// CHECK-NEXT:    [[TMP67:%.*]] = getelementptr inbounds nuw [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS]], i32 0, i32 12
// CHECK-NEXT:    store i32 0, ptr [[TMP67]], align 4
// CHECK-NEXT:    [[TMP68:%.*]] = call i32 @__tgt_target_kernel(ptr @[[GLOB1]], i64 -1, i32 0, i32 0, ptr @.{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}__ZN1C3barER10descriptorIfE_l55.region_id, ptr [[KERNEL_ARGS]])
// CHECK-NEXT:    [[TMP69:%.*]] = icmp ne i32 [[TMP68]], 0
// CHECK-NEXT:    br i1 [[TMP69]], label [[OMP_OFFLOAD_FAILED:%.*]], label [[OMP_OFFLOAD_CONT:%.*]]
// CHECK:       omp_offload.failed:
// CHECK-NEXT:    call void @{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}__ZN1C3barER10descriptorIfE_l55(i64 [[TMP43]], ptr [[TMP44]]) #[[ATTR2]]
// CHECK-NEXT:    br label [[OMP_OFFLOAD_CONT]]
// CHECK:       omp_offload.cont:
// CHECK-NEXT:    [[TMP70:%.*]] = getelementptr inbounds [3 x ptr], ptr [[DOTOFFLOAD_BASEPTRS]], i32 0, i32 0
// CHECK-NEXT:    [[TMP71:%.*]] = getelementptr inbounds [3 x ptr], ptr [[DOTOFFLOAD_PTRS]], i32 0, i32 0
// CHECK-NEXT:    [[TMP72:%.*]] = getelementptr inbounds [3 x i64], ptr [[DOTOFFLOAD_SIZES]], i32 0, i32 0
// CHECK-NEXT:    call void @__tgt_target_data_end_mapper(ptr @[[GLOB1]], i64 -1, i32 3, ptr [[TMP70]], ptr [[TMP71]], ptr [[TMP72]], ptr @.offload_maptypes.1, ptr null, ptr null)
// CHECK-NEXT:    [[TMP73:%.*]] = load ptr, ptr [[D_ADDR]], align 8
// CHECK-NEXT:    store ptr [[TMP73]], ptr [[_TMP12]], align 8
// CHECK-NEXT:    [[TMP74:%.*]] = load i32, ptr [[CSIZE]], align 4
// CHECK-NEXT:    store i32 [[TMP74]], ptr [[CSIZE_CASTED13]], align 4
// CHECK-NEXT:    [[TMP75:%.*]] = load i64, ptr [[CSIZE_CASTED13]], align 8
// CHECK-NEXT:    [[TMP76:%.*]] = load ptr, ptr [[_TMP12]], align 8
// CHECK-NEXT:    [[TMP77:%.*]] = load ptr, ptr [[_TMP12]], align 8
// CHECK-NEXT:    [[TMP78:%.*]] = load ptr, ptr [[_TMP12]], align 8
// CHECK-NEXT:    [[C14:%.*]] = getelementptr inbounds nuw [[STRUCT_DESCRIPTOR]], ptr [[TMP78]], i32 0, i32 1
// CHECK-NEXT:    [[TMP79:%.*]] = load ptr, ptr [[_TMP12]], align 8
// CHECK-NEXT:    [[C15:%.*]] = getelementptr inbounds nuw [[STRUCT_DESCRIPTOR]], ptr [[TMP79]], i32 0, i32 1
// CHECK-NEXT:    [[TMP80:%.*]] = load ptr, ptr [[C15]], align 8
// CHECK-NEXT:    [[ARRAYIDX16:%.*]] = getelementptr inbounds float, ptr [[TMP80]], i64 0
// CHECK-NEXT:    [[TMP81:%.*]] = load i32, ptr [[CSIZE]], align 4
// CHECK-NEXT:    [[CONV17:%.*]] = zext i32 [[TMP81]] to i64
// CHECK-NEXT:    [[TMP82:%.*]] = mul nuw i64 [[CONV17]], 4
// CHECK-NEXT:    [[TMP83:%.*]] = getelementptr ptr, ptr [[C14]], i32 1
// CHECK-NEXT:    [[TMP84:%.*]] = ptrtoint ptr [[TMP83]] to i64
// CHECK-NEXT:    [[TMP85:%.*]] = ptrtoint ptr [[C14]] to i64
// CHECK-NEXT:    [[TMP86:%.*]] = sub i64 [[TMP84]], [[TMP85]]
// CHECK-NEXT:    [[TMP87:%.*]] = sdiv exact i64 [[TMP86]], ptrtoint (ptr getelementptr (i8, ptr null, i32 1) to i64)
// CHECK-NEXT:    call void @llvm.memcpy.p0.p0.i64(ptr align 8 [[DOTOFFLOAD_SIZES21]], ptr align 8 @.offload_sizes.4, i64 24, i1 false)
// CHECK-NEXT:    [[TMP88:%.*]] = getelementptr inbounds [3 x ptr], ptr [[DOTOFFLOAD_BASEPTRS18]], i32 0, i32 0
// CHECK-NEXT:    store i64 [[TMP75]], ptr [[TMP88]], align 8
// CHECK-NEXT:    [[TMP89:%.*]] = getelementptr inbounds [3 x ptr], ptr [[DOTOFFLOAD_PTRS19]], i32 0, i32 0
// CHECK-NEXT:    store i64 [[TMP75]], ptr [[TMP89]], align 8
// CHECK-NEXT:    [[TMP90:%.*]] = getelementptr inbounds [3 x ptr], ptr [[DOTOFFLOAD_MAPPERS20]], i64 0, i64 0
// CHECK-NEXT:    store ptr null, ptr [[TMP90]], align 8
// CHECK-NEXT:    [[TMP91:%.*]] = getelementptr inbounds [3 x ptr], ptr [[DOTOFFLOAD_BASEPTRS18]], i32 0, i32 1
// CHECK-NEXT:    store ptr [[TMP77]], ptr [[TMP91]], align 8
// CHECK-NEXT:    [[TMP92:%.*]] = getelementptr inbounds [3 x ptr], ptr [[DOTOFFLOAD_PTRS19]], i32 0, i32 1
// CHECK-NEXT:    store ptr [[C14]], ptr [[TMP92]], align 8
// CHECK-NEXT:    [[TMP93:%.*]] = getelementptr inbounds [3 x i64], ptr [[DOTOFFLOAD_SIZES21]], i32 0, i32 1
// CHECK-NEXT:    store i64 [[TMP87]], ptr [[TMP93]], align 8
// CHECK-NEXT:    [[TMP94:%.*]] = getelementptr inbounds [3 x ptr], ptr [[DOTOFFLOAD_MAPPERS20]], i64 0, i64 1
// CHECK-NEXT:    store ptr null, ptr [[TMP94]], align 8
// CHECK-NEXT:    [[TMP95:%.*]] = getelementptr inbounds [3 x ptr], ptr [[DOTOFFLOAD_BASEPTRS18]], i32 0, i32 2
// CHECK-NEXT:    store ptr [[C14]], ptr [[TMP95]], align 8
// CHECK-NEXT:    [[TMP96:%.*]] = getelementptr inbounds [3 x ptr], ptr [[DOTOFFLOAD_PTRS19]], i32 0, i32 2
// CHECK-NEXT:    store ptr [[ARRAYIDX16]], ptr [[TMP96]], align 8
// CHECK-NEXT:    [[TMP97:%.*]] = getelementptr inbounds [3 x i64], ptr [[DOTOFFLOAD_SIZES21]], i32 0, i32 2
// CHECK-NEXT:    store i64 [[TMP82]], ptr [[TMP97]], align 8
// CHECK-NEXT:    [[TMP98:%.*]] = getelementptr inbounds [3 x ptr], ptr [[DOTOFFLOAD_MAPPERS20]], i64 0, i64 2
// CHECK-NEXT:    store ptr null, ptr [[TMP98]], align 8
// CHECK-NEXT:    [[TMP99:%.*]] = getelementptr inbounds [3 x ptr], ptr [[DOTOFFLOAD_BASEPTRS18]], i32 0, i32 0
// CHECK-NEXT:    [[TMP100:%.*]] = getelementptr inbounds [3 x ptr], ptr [[DOTOFFLOAD_PTRS19]], i32 0, i32 0
// CHECK-NEXT:    [[TMP101:%.*]] = getelementptr inbounds [3 x i64], ptr [[DOTOFFLOAD_SIZES21]], i32 0, i32 0
// CHECK-NEXT:    [[TMP102:%.*]] = getelementptr inbounds nuw [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS22]], i32 0, i32 0
// CHECK-NEXT:    store i32 3, ptr [[TMP102]], align 4
// CHECK-NEXT:    [[TMP103:%.*]] = getelementptr inbounds nuw [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS22]], i32 0, i32 1
// CHECK-NEXT:    store i32 3, ptr [[TMP103]], align 4
// CHECK-NEXT:    [[TMP104:%.*]] = getelementptr inbounds nuw [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS22]], i32 0, i32 2
// CHECK-NEXT:    store ptr [[TMP99]], ptr [[TMP104]], align 8
// CHECK-NEXT:    [[TMP105:%.*]] = getelementptr inbounds nuw [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS22]], i32 0, i32 3
// CHECK-NEXT:    store ptr [[TMP100]], ptr [[TMP105]], align 8
// CHECK-NEXT:    [[TMP106:%.*]] = getelementptr inbounds nuw [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS22]], i32 0, i32 4
// CHECK-NEXT:    store ptr [[TMP101]], ptr [[TMP106]], align 8
// CHECK-NEXT:    [[TMP107:%.*]] = getelementptr inbounds nuw [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS22]], i32 0, i32 5
// CHECK-NEXT:    store ptr @.offload_maptypes.5, ptr [[TMP107]], align 8
// CHECK-NEXT:    [[TMP108:%.*]] = getelementptr inbounds nuw [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS22]], i32 0, i32 6
// CHECK-NEXT:    store ptr null, ptr [[TMP108]], align 8
// CHECK-NEXT:    [[TMP109:%.*]] = getelementptr inbounds nuw [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS22]], i32 0, i32 7
// CHECK-NEXT:    store ptr null, ptr [[TMP109]], align 8
// CHECK-NEXT:    [[TMP110:%.*]] = getelementptr inbounds nuw [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS22]], i32 0, i32 8
// CHECK-NEXT:    store i64 0, ptr [[TMP110]], align 8
// CHECK-NEXT:    [[TMP111:%.*]] = getelementptr inbounds nuw [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS22]], i32 0, i32 9
// CHECK-NEXT:    store i64 0, ptr [[TMP111]], align 8
// CHECK-NEXT:    [[TMP112:%.*]] = getelementptr inbounds nuw [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS22]], i32 0, i32 10
// CHECK-NEXT:    store [3 x i32] [i32 -1, i32 0, i32 0], ptr [[TMP112]], align 4
// CHECK-NEXT:    [[TMP113:%.*]] = getelementptr inbounds nuw [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS22]], i32 0, i32 11
// CHECK-NEXT:    store [3 x i32] zeroinitializer, ptr [[TMP113]], align 4
// CHECK-NEXT:    [[TMP114:%.*]] = getelementptr inbounds nuw [[STRUCT___TGT_KERNEL_ARGUMENTS]], ptr [[KERNEL_ARGS22]], i32 0, i32 12
// CHECK-NEXT:    store i32 0, ptr [[TMP114]], align 4
// CHECK-NEXT:    [[TMP115:%.*]] = call i32 @__tgt_target_kernel(ptr @[[GLOB1]], i64 -1, i32 -1, i32 0, ptr @.{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}__ZN1C3barER10descriptorIfE_l59.region_id, ptr [[KERNEL_ARGS22]])
// CHECK-NEXT:    [[TMP116:%.*]] = icmp ne i32 [[TMP115]], 0
// CHECK-NEXT:    br i1 [[TMP116]], label [[OMP_OFFLOAD_FAILED23:%.*]], label [[OMP_OFFLOAD_CONT24:%.*]]
// CHECK:       omp_offload.failed23:
// CHECK-NEXT:    call void @{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}__ZN1C3barER10descriptorIfE_l59(i64 [[TMP75]], ptr [[TMP76]]) #[[ATTR2]]
// CHECK-NEXT:    br label [[OMP_OFFLOAD_CONT24]]
// CHECK:       omp_offload.cont24:
// CHECK-NEXT:    ret void
//
//
// CHECK-LABEL: define {{[^@]+}}@_ZN1BC2Eii
// CHECK-SAME: (ptr noundef nonnull align 4 dereferenceable(12) [[THIS:%.*]], i32 noundef [[X:%.*]], i32 noundef [[Y:%.*]]) unnamed_addr #[[ATTR0]] comdat align 2 {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[THIS_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[X_ADDR:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[Y_ADDR:%.*]] = alloca i32, align 4
// CHECK-NEXT:    store ptr [[THIS]], ptr [[THIS_ADDR]], align 8
// CHECK-NEXT:    store i32 [[X]], ptr [[X_ADDR]], align 4
// CHECK-NEXT:    store i32 [[Y]], ptr [[Y_ADDR]], align 4
// CHECK-NEXT:    [[THIS1:%.*]] = load ptr, ptr [[THIS_ADDR]], align 8
// CHECK-NEXT:    [[TMP0:%.*]] = load i32, ptr [[X_ADDR]], align 4
// CHECK-NEXT:    [[TMP1:%.*]] = load i32, ptr [[Y_ADDR]], align 4
// CHECK-NEXT:    call void @_ZN1AC2Eii(ptr noundef nonnull align 4 dereferenceable(8) [[THIS1]], i32 noundef [[TMP0]], i32 noundef [[TMP1]])
// CHECK-NEXT:    [[RES:%.*]] = getelementptr inbounds nuw [[CLASS_B:%.*]], ptr [[THIS1]], i32 0, i32 1
// CHECK-NEXT:    store i32 0, ptr [[RES]], align 4
// CHECK-NEXT:    ret void
//
//
// CHECK-LABEL: define {{[^@]+}}@_ZN1AC2Eii
// CHECK-SAME: (ptr noundef nonnull align 4 dereferenceable(8) [[THIS:%.*]], i32 noundef [[X:%.*]], i32 noundef [[Y:%.*]]) unnamed_addr #[[ATTR0]] comdat align 2 {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[THIS_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[X_ADDR:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[Y_ADDR:%.*]] = alloca i32, align 4
// CHECK-NEXT:    store ptr [[THIS]], ptr [[THIS_ADDR]], align 8
// CHECK-NEXT:    store i32 [[X]], ptr [[X_ADDR]], align 4
// CHECK-NEXT:    store i32 [[Y]], ptr [[Y_ADDR]], align 4
// CHECK-NEXT:    [[THIS1:%.*]] = load ptr, ptr [[THIS_ADDR]], align 8
// CHECK-NEXT:    [[X:%.*]] = getelementptr inbounds nuw [[CLASS_A:%.*]], ptr [[THIS1]], i32 0, i32 0
// CHECK-NEXT:    [[TMP0:%.*]] = load i32, ptr [[X_ADDR]], align 4
// CHECK-NEXT:    store i32 [[TMP0]], ptr [[X]], align 4
// CHECK-NEXT:    [[Y:%.*]] = getelementptr inbounds nuw [[CLASS_A]], ptr [[THIS1]], i32 0, i32 1
// CHECK-NEXT:    [[TMP1:%.*]] = load i32, ptr [[Y_ADDR]], align 4
// CHECK-NEXT:    store i32 [[TMP1]], ptr [[Y]], align 4
// CHECK-NEXT:    ret void
//
//
// CHECK-LABEL: define {{[^@]+}}@{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}__ZN1B3runEv_l25
// CHECK-SAME: (ptr noundef [[THIS:%.*]]) #[[ATTR1:[0-9]+]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[THIS_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    store ptr [[THIS]], ptr [[THIS_ADDR]], align 8
// CHECK-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[THIS_ADDR]], align 8
// CHECK-NEXT:    [[X:%.*]] = getelementptr inbounds nuw [[CLASS_A:%.*]], ptr [[TMP0]], i32 0, i32 0
// CHECK-NEXT:    [[TMP1:%.*]] = load i32, ptr [[X]], align 4
// CHECK-NEXT:    [[Y:%.*]] = getelementptr inbounds nuw [[CLASS_A]], ptr [[TMP0]], i32 0, i32 1
// CHECK-NEXT:    [[TMP2:%.*]] = load i32, ptr [[Y]], align 4
// CHECK-NEXT:    [[ADD:%.*]] = add nsw i32 [[TMP1]], [[TMP2]]
// CHECK-NEXT:    [[RES:%.*]] = getelementptr inbounds nuw [[CLASS_B:%.*]], ptr [[TMP0]], i32 0, i32 1
// CHECK-NEXT:    store i32 [[ADD]], ptr [[RES]], align 4
// CHECK-NEXT:    ret void
//
//
// CHECK-LABEL: define {{[^@]+}}@{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}__ZN1C3barER10descriptorIfE_l55
// CHECK-SAME: (i64 noundef [[CSIZE:%.*]], ptr noundef nonnull align 8 dereferenceable(40) [[D:%.*]]) #[[ATTR1]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[CSIZE_ADDR:%.*]] = alloca i64, align 8
// CHECK-NEXT:    [[D_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[TMP:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[CSIZE_CASTED:%.*]] = alloca i64, align 8
// CHECK-NEXT:    store i64 [[CSIZE]], ptr [[CSIZE_ADDR]], align 8
// CHECK-NEXT:    store ptr [[D]], ptr [[D_ADDR]], align 8
// CHECK-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[D_ADDR]], align 8
// CHECK-NEXT:    store ptr [[TMP0]], ptr [[TMP]], align 8
// CHECK-NEXT:    [[TMP1:%.*]] = load i32, ptr [[CSIZE_ADDR]], align 4
// CHECK-NEXT:    store i32 [[TMP1]], ptr [[CSIZE_CASTED]], align 4
// CHECK-NEXT:    [[TMP2:%.*]] = load i64, ptr [[CSIZE_CASTED]], align 8
// CHECK-NEXT:    [[TMP3:%.*]] = load ptr, ptr [[TMP]], align 8
// CHECK-NEXT:    call void (ptr, i32, ptr, ...) @__kmpc_fork_teams(ptr @[[GLOB1]], i32 2, ptr @{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}__ZN1C3barER10descriptorIfE_l55.omp_outlined, i64 [[TMP2]], ptr [[TMP3]])
// CHECK-NEXT:    ret void
//
//
// CHECK-LABEL: define {{[^@]+}}@{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}__ZN1C3barER10descriptorIfE_l55.omp_outlined
// CHECK-SAME: (ptr noalias noundef [[DOTGLOBAL_TID_:%.*]], ptr noalias noundef [[DOTBOUND_TID_:%.*]], i64 noundef [[CSIZE:%.*]], ptr noundef nonnull align 8 dereferenceable(40) [[D:%.*]]) #[[ATTR1]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[DOTGLOBAL_TID__ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[DOTBOUND_TID__ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[CSIZE_ADDR:%.*]] = alloca i64, align 8
// CHECK-NEXT:    [[D_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[TMP:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[I:%.*]] = alloca i32, align 4
// CHECK-NEXT:    store ptr [[DOTGLOBAL_TID_]], ptr [[DOTGLOBAL_TID__ADDR]], align 8
// CHECK-NEXT:    store ptr [[DOTBOUND_TID_]], ptr [[DOTBOUND_TID__ADDR]], align 8
// CHECK-NEXT:    store i64 [[CSIZE]], ptr [[CSIZE_ADDR]], align 8
// CHECK-NEXT:    store ptr [[D]], ptr [[D_ADDR]], align 8
// CHECK-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[D_ADDR]], align 8
// CHECK-NEXT:    store ptr [[TMP0]], ptr [[TMP]], align 8
// CHECK-NEXT:    store i32 0, ptr [[I]], align 4
// CHECK-NEXT:    br label [[FOR_COND:%.*]]
// CHECK:       for.cond:
// CHECK-NEXT:    [[TMP1:%.*]] = load i32, ptr [[I]], align 4
// CHECK-NEXT:    [[TMP2:%.*]] = load i32, ptr [[CSIZE_ADDR]], align 4
// CHECK-NEXT:    [[CMP:%.*]] = icmp ult i32 [[TMP1]], [[TMP2]]
// CHECK-NEXT:    br i1 [[CMP]], label [[FOR_BODY:%.*]], label [[FOR_END:%.*]]
// CHECK:       for.body:
// CHECK-NEXT:    [[TMP3:%.*]] = load ptr, ptr [[TMP]], align 8
// CHECK-NEXT:    [[C:%.*]] = getelementptr inbounds nuw [[STRUCT_DESCRIPTOR:%.*]], ptr [[TMP3]], i32 0, i32 1
// CHECK-NEXT:    [[TMP4:%.*]] = load ptr, ptr [[C]], align 8
// CHECK-NEXT:    [[TMP5:%.*]] = load i32, ptr [[I]], align 4
// CHECK-NEXT:    [[IDXPROM:%.*]] = sext i32 [[TMP5]] to i64
// CHECK-NEXT:    [[ARRAYIDX:%.*]] = getelementptr inbounds float, ptr [[TMP4]], i64 [[IDXPROM]]
// CHECK-NEXT:    store float 1.000000e+00, ptr [[ARRAYIDX]], align 4
// CHECK-NEXT:    br label [[FOR_INC:%.*]]
// CHECK:       for.inc:
// CHECK-NEXT:    [[TMP6:%.*]] = load i32, ptr [[I]], align 4
// CHECK-NEXT:    [[INC:%.*]] = add nsw i32 [[TMP6]], 1
// CHECK-NEXT:    store i32 [[INC]], ptr [[I]], align 4
// CHECK-NEXT:    br label [[FOR_COND]], !llvm.loop [[LOOP6:![0-9]+]]
// CHECK:       for.end:
// CHECK-NEXT:    ret void
//
//
// CHECK-LABEL: define {{[^@]+}}@{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}__ZN1C3barER10descriptorIfE_l59
// CHECK-SAME: (i64 noundef [[CSIZE:%.*]], ptr noundef nonnull align 8 dereferenceable(40) [[D:%.*]]) #[[ATTR1]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[CSIZE_ADDR:%.*]] = alloca i64, align 8
// CHECK-NEXT:    [[D_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[TMP:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[I:%.*]] = alloca i32, align 4
// CHECK-NEXT:    store i64 [[CSIZE]], ptr [[CSIZE_ADDR]], align 8
// CHECK-NEXT:    store ptr [[D]], ptr [[D_ADDR]], align 8
// CHECK-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[D_ADDR]], align 8
// CHECK-NEXT:    store ptr [[TMP0]], ptr [[TMP]], align 8
// CHECK-NEXT:    store i32 0, ptr [[I]], align 4
// CHECK-NEXT:    br label [[FOR_COND:%.*]]
// CHECK:       for.cond:
// CHECK-NEXT:    [[TMP1:%.*]] = load i32, ptr [[I]], align 4
// CHECK-NEXT:    [[TMP2:%.*]] = load i32, ptr [[CSIZE_ADDR]], align 4
// CHECK-NEXT:    [[CMP:%.*]] = icmp ult i32 [[TMP1]], [[TMP2]]
// CHECK-NEXT:    br i1 [[CMP]], label [[FOR_BODY:%.*]], label [[FOR_END:%.*]]
// CHECK:       for.body:
// CHECK-NEXT:    [[TMP3:%.*]] = load ptr, ptr [[TMP]], align 8
// CHECK-NEXT:    [[C:%.*]] = getelementptr inbounds nuw [[STRUCT_DESCRIPTOR:%.*]], ptr [[TMP3]], i32 0, i32 1
// CHECK-NEXT:    [[TMP4:%.*]] = load ptr, ptr [[C]], align 8
// CHECK-NEXT:    [[TMP5:%.*]] = load i32, ptr [[I]], align 4
// CHECK-NEXT:    [[IDXPROM:%.*]] = sext i32 [[TMP5]] to i64
// CHECK-NEXT:    [[ARRAYIDX:%.*]] = getelementptr inbounds float, ptr [[TMP4]], i64 [[IDXPROM]]
// CHECK-NEXT:    store float 1.000000e+00, ptr [[ARRAYIDX]], align 4
// CHECK-NEXT:    br label [[FOR_INC:%.*]]
// CHECK:       for.inc:
// CHECK-NEXT:    [[TMP6:%.*]] = load i32, ptr [[I]], align 4
// CHECK-NEXT:    [[INC:%.*]] = add nsw i32 [[TMP6]], 1
// CHECK-NEXT:    store i32 [[INC]], ptr [[I]], align 4
// CHECK-NEXT:    br label [[FOR_COND]], !llvm.loop [[LOOP10:![0-9]+]]
// CHECK:       for.end:
// CHECK-NEXT:    ret void
//
