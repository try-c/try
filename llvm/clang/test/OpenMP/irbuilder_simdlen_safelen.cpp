// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --function-signature --check-globals --include-generated-funcs --replace-value-regex "__omp_offloading_[0-9a-z]+_[0-9a-z]+" "reduction_  size[.].+[.]" "pl_cond[.].+[.|,]" --prefix-filecheck-ir-name _
// RUN: %clang_cc1 -fopenmp-enable-irbuilder -verify -fopenmp -fopenmp-version=45 -x c++ -triple x86_64-unknown-unknown -emit-llvm %s -o - | FileCheck %s
// expected-no-diagnostics

struct S {
  int a, b;
};

struct P {
  int a, b;
};

void simple(float *a, float *b, int *c) {
  S s, *p;
  P pp;
#pragma omp simd safelen(3) simdlen(2)
  for (int i = 3; i < 32; i += 5) {
    a[i] = b[i] + s.a + p->a;
  }

#pragma omp simd
  for (int j = 3; j < 32; j += 5) {
    c[j] = pp.a;
  }
}
// CHECK-LABEL: define {{[^@]+}}@_Z6simplePfS_Pi
// CHECK-SAME: (ptr noundef [[A:%.*]], ptr noundef [[B:%.*]], ptr noundef [[C:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[A_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[B_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[C_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[S:%.*]] = alloca [[STRUCT_S:%.*]], align 4
// CHECK-NEXT:    [[P:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[PP:%.*]] = alloca [[STRUCT_P:%.*]], align 4
// CHECK-NEXT:    [[I:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[AGG_CAPTURED:%.*]] = alloca [[STRUCT_ANON:%.*]], align 8
// CHECK-NEXT:    [[AGG_CAPTURED1:%.*]] = alloca [[STRUCT_ANON_0:%.*]], align 4
// CHECK-NEXT:    [[DOTCOUNT_ADDR:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[J:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[AGG_CAPTURED8:%.*]] = alloca [[STRUCT_ANON_1:%.*]], align 8
// CHECK-NEXT:    [[AGG_CAPTURED9:%.*]] = alloca [[STRUCT_ANON_2:%.*]], align 4
// CHECK-NEXT:    [[DOTCOUNT_ADDR10:%.*]] = alloca i32, align 4
// CHECK-NEXT:    store ptr [[A]], ptr [[A_ADDR]], align 8
// CHECK-NEXT:    store ptr [[B]], ptr [[B_ADDR]], align 8
// CHECK-NEXT:    store ptr [[C]], ptr [[C_ADDR]], align 8
// CHECK-NEXT:    store i32 3, ptr [[I]], align 4
// CHECK-NEXT:    [[TMP0:%.*]] = getelementptr inbounds nuw [[STRUCT_ANON]], ptr [[AGG_CAPTURED]], i32 0, i32 0
// CHECK-NEXT:    store ptr [[I]], ptr [[TMP0]], align 8
// CHECK-NEXT:    [[TMP1:%.*]] = getelementptr inbounds nuw [[STRUCT_ANON_0]], ptr [[AGG_CAPTURED1]], i32 0, i32 0
// CHECK-NEXT:    [[TMP2:%.*]] = load i32, ptr [[I]], align 4
// CHECK-NEXT:    store i32 [[TMP2]], ptr [[TMP1]], align 4
// CHECK-NEXT:    call void @__captured_stmt(ptr [[DOTCOUNT_ADDR]], ptr [[AGG_CAPTURED]])
// CHECK-NEXT:    [[DOTCOUNT:%.*]] = load i32, ptr [[DOTCOUNT_ADDR]], align 4
// CHECK-NEXT:    br label [[OMP_LOOP_PREHEADER:%.*]]
// CHECK:       omp_loop.preheader:
// CHECK-NEXT:    br label [[OMP_LOOP_HEADER:%.*]]
// CHECK:       omp_loop.header:
// CHECK-NEXT:    [[OMP_LOOP_IV:%.*]] = phi i32 [ 0, [[OMP_LOOP_PREHEADER]] ], [ [[OMP_LOOP_NEXT:%.*]], [[OMP_LOOP_INC:%.*]] ]
// CHECK-NEXT:    br label [[OMP_LOOP_COND:%.*]]
// CHECK:       omp_loop.cond:
// CHECK-NEXT:    [[OMP_LOOP_CMP:%.*]] = icmp ult i32 [[OMP_LOOP_IV]], [[DOTCOUNT]]
// CHECK-NEXT:    br i1 [[OMP_LOOP_CMP]], label [[OMP_LOOP_BODY:%.*]], label [[OMP_LOOP_EXIT:%.*]]
// CHECK:       omp_loop.body:
// CHECK-NEXT:    call void @__captured_stmt.1(ptr [[I]], i32 [[OMP_LOOP_IV]], ptr [[AGG_CAPTURED1]])
// CHECK-NEXT:    [[TMP3:%.*]] = load ptr, ptr [[B_ADDR]], align 8
// CHECK-NEXT:    [[TMP4:%.*]] = load i32, ptr [[I]], align 4
// CHECK-NEXT:    [[IDXPROM:%.*]] = sext i32 [[TMP4]] to i64
// CHECK-NEXT:    [[ARRAYIDX:%.*]] = getelementptr inbounds float, ptr [[TMP3]], i64 [[IDXPROM]]
// CHECK-NEXT:    [[TMP5:%.*]] = load float, ptr [[ARRAYIDX]], align 4
// CHECK-NEXT:    [[A2:%.*]] = getelementptr inbounds nuw [[STRUCT_S]], ptr [[S]], i32 0, i32 0
// CHECK-NEXT:    [[TMP6:%.*]] = load i32, ptr [[A2]], align 4
// CHECK-NEXT:    [[CONV:%.*]] = sitofp i32 [[TMP6]] to float
// CHECK-NEXT:    [[ADD:%.*]] = fadd float [[TMP5]], [[CONV]]
// CHECK-NEXT:    [[TMP7:%.*]] = load ptr, ptr [[P]], align 8
// CHECK-NEXT:    [[A3:%.*]] = getelementptr inbounds nuw [[STRUCT_S]], ptr [[TMP7]], i32 0, i32 0
// CHECK-NEXT:    [[TMP8:%.*]] = load i32, ptr [[A3]], align 4
// CHECK-NEXT:    [[CONV4:%.*]] = sitofp i32 [[TMP8]] to float
// CHECK-NEXT:    [[ADD5:%.*]] = fadd float [[ADD]], [[CONV4]]
// CHECK-NEXT:    [[TMP9:%.*]] = load ptr, ptr [[A_ADDR]], align 8
// CHECK-NEXT:    [[TMP10:%.*]] = load i32, ptr [[I]], align 4
// CHECK-NEXT:    [[IDXPROM6:%.*]] = sext i32 [[TMP10]] to i64
// CHECK-NEXT:    [[ARRAYIDX7:%.*]] = getelementptr inbounds float, ptr [[TMP9]], i64 [[IDXPROM6]]
// CHECK-NEXT:    store float [[ADD5]], ptr [[ARRAYIDX7]], align 4
// CHECK-NEXT:    br label [[OMP_LOOP_INC]]
// CHECK:       omp_loop.inc:
// CHECK-NEXT:    [[OMP_LOOP_NEXT]] = add nuw i32 [[OMP_LOOP_IV]], 1
// CHECK-NEXT:    br label [[OMP_LOOP_HEADER]], !llvm.loop [[LOOP3:![0-9]+]]
// CHECK:       omp_loop.exit:
// CHECK-NEXT:    br label [[OMP_LOOP_AFTER:%.*]]
// CHECK:       omp_loop.after:
// CHECK-NEXT:    store i32 3, ptr [[J]], align 4
// CHECK-NEXT:    [[TMP11:%.*]] = getelementptr inbounds nuw [[STRUCT_ANON_1]], ptr [[AGG_CAPTURED8]], i32 0, i32 0
// CHECK-NEXT:    store ptr [[J]], ptr [[TMP11]], align 8
// CHECK-NEXT:    [[TMP12:%.*]] = getelementptr inbounds nuw [[STRUCT_ANON_2]], ptr [[AGG_CAPTURED9]], i32 0, i32 0
// CHECK-NEXT:    [[TMP13:%.*]] = load i32, ptr [[J]], align 4
// CHECK-NEXT:    store i32 [[TMP13]], ptr [[TMP12]], align 4
// CHECK-NEXT:    call void @__captured_stmt.2(ptr [[DOTCOUNT_ADDR10]], ptr [[AGG_CAPTURED8]])
// CHECK-NEXT:    [[DOTCOUNT11:%.*]] = load i32, ptr [[DOTCOUNT_ADDR10]], align 4
// CHECK-NEXT:    br label [[OMP_LOOP_PREHEADER12:%.*]]
// CHECK:       omp_loop.preheader12:
// CHECK-NEXT:    br label [[OMP_LOOP_HEADER13:%.*]]
// CHECK:       omp_loop.header13:
// CHECK-NEXT:    [[OMP_LOOP_IV19:%.*]] = phi i32 [ 0, [[OMP_LOOP_PREHEADER12]] ], [ [[OMP_LOOP_NEXT21:%.*]], [[OMP_LOOP_INC16:%.*]] ]
// CHECK-NEXT:    br label [[OMP_LOOP_COND14:%.*]]
// CHECK:       omp_loop.cond14:
// CHECK-NEXT:    [[OMP_LOOP_CMP20:%.*]] = icmp ult i32 [[OMP_LOOP_IV19]], [[DOTCOUNT11]]
// CHECK-NEXT:    br i1 [[OMP_LOOP_CMP20]], label [[OMP_LOOP_BODY15:%.*]], label [[OMP_LOOP_EXIT17:%.*]]
// CHECK:       omp_loop.body15:
// CHECK-NEXT:    call void @__captured_stmt.3(ptr [[J]], i32 [[OMP_LOOP_IV19]], ptr [[AGG_CAPTURED9]]), !llvm.access.group [[ACC_GRP6:![0-9]+]]
// CHECK-NEXT:    [[A22:%.*]] = getelementptr inbounds nuw [[STRUCT_P]], ptr [[PP]], i32 0, i32 0
// CHECK-NEXT:    [[TMP14:%.*]] = load i32, ptr [[A22]], align 4, !llvm.access.group [[ACC_GRP6]]
// CHECK-NEXT:    [[TMP15:%.*]] = load ptr, ptr [[C_ADDR]], align 8, !llvm.access.group [[ACC_GRP6]]
// CHECK-NEXT:    [[TMP16:%.*]] = load i32, ptr [[J]], align 4, !llvm.access.group [[ACC_GRP6]]
// CHECK-NEXT:    [[IDXPROM23:%.*]] = sext i32 [[TMP16]] to i64
// CHECK-NEXT:    [[ARRAYIDX24:%.*]] = getelementptr inbounds i32, ptr [[TMP15]], i64 [[IDXPROM23]]
// CHECK-NEXT:    store i32 [[TMP14]], ptr [[ARRAYIDX24]], align 4, !llvm.access.group [[ACC_GRP6]]
// CHECK-NEXT:    br label [[OMP_LOOP_INC16]]
// CHECK:       omp_loop.inc16:
// CHECK-NEXT:    [[OMP_LOOP_NEXT21]] = add nuw i32 [[OMP_LOOP_IV19]], 1
// CHECK-NEXT:    br label [[OMP_LOOP_HEADER13]], !llvm.loop [[LOOP7:![0-9]+]]
// CHECK:       omp_loop.exit17:
// CHECK-NEXT:    br label [[OMP_LOOP_AFTER18:%.*]]
// CHECK:       omp_loop.after18:
// CHECK-NEXT:    ret void
//
//
// CHECK-LABEL: define {{[^@]+}}@__captured_stmt
// CHECK-SAME: (ptr noundef nonnull align 4 dereferenceable(4) [[DISTANCE:%.*]], ptr noalias noundef [[__CONTEXT:%.*]]) #[[ATTR1:[0-9]+]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[DISTANCE_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[__CONTEXT_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[DOTSTART:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[DOTSTOP:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[DOTSTEP:%.*]] = alloca i32, align 4
// CHECK-NEXT:    store ptr [[DISTANCE]], ptr [[DISTANCE_ADDR]], align 8
// CHECK-NEXT:    store ptr [[__CONTEXT]], ptr [[__CONTEXT_ADDR]], align 8
// CHECK-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[__CONTEXT_ADDR]], align 8
// CHECK-NEXT:    [[TMP1:%.*]] = getelementptr inbounds nuw [[STRUCT_ANON:%.*]], ptr [[TMP0]], i32 0, i32 0
// CHECK-NEXT:    [[TMP2:%.*]] = load ptr, ptr [[TMP1]], align 8
// CHECK-NEXT:    [[TMP3:%.*]] = load i32, ptr [[TMP2]], align 4
// CHECK-NEXT:    store i32 [[TMP3]], ptr [[DOTSTART]], align 4
// CHECK-NEXT:    store i32 32, ptr [[DOTSTOP]], align 4
// CHECK-NEXT:    store i32 5, ptr [[DOTSTEP]], align 4
// CHECK-NEXT:    [[TMP4:%.*]] = load i32, ptr [[DOTSTART]], align 4
// CHECK-NEXT:    [[TMP5:%.*]] = load i32, ptr [[DOTSTOP]], align 4
// CHECK-NEXT:    [[CMP:%.*]] = icmp slt i32 [[TMP4]], [[TMP5]]
// CHECK-NEXT:    br i1 [[CMP]], label [[COND_TRUE:%.*]], label [[COND_FALSE:%.*]]
// CHECK:       cond.true:
// CHECK-NEXT:    [[TMP6:%.*]] = load i32, ptr [[DOTSTOP]], align 4
// CHECK-NEXT:    [[TMP7:%.*]] = load i32, ptr [[DOTSTART]], align 4
// CHECK-NEXT:    [[SUB:%.*]] = sub nsw i32 [[TMP6]], [[TMP7]]
// CHECK-NEXT:    [[TMP8:%.*]] = load i32, ptr [[DOTSTEP]], align 4
// CHECK-NEXT:    [[SUB1:%.*]] = sub i32 [[TMP8]], 1
// CHECK-NEXT:    [[ADD:%.*]] = add i32 [[SUB]], [[SUB1]]
// CHECK-NEXT:    [[TMP9:%.*]] = load i32, ptr [[DOTSTEP]], align 4
// CHECK-NEXT:    [[DIV:%.*]] = udiv i32 [[ADD]], [[TMP9]]
// CHECK-NEXT:    br label [[COND_END:%.*]]
// CHECK:       cond.false:
// CHECK-NEXT:    br label [[COND_END]]
// CHECK:       cond.end:
// CHECK-NEXT:    [[COND:%.*]] = phi i32 [ [[DIV]], [[COND_TRUE]] ], [ 0, [[COND_FALSE]] ]
// CHECK-NEXT:    [[TMP10:%.*]] = load ptr, ptr [[DISTANCE_ADDR]], align 8
// CHECK-NEXT:    store i32 [[COND]], ptr [[TMP10]], align 4
// CHECK-NEXT:    ret void
//
//
// CHECK-LABEL: define {{[^@]+}}@__captured_stmt.1
// CHECK-SAME: (ptr noundef nonnull align 4 dereferenceable(4) [[LOOPVAR:%.*]], i32 noundef [[LOGICAL:%.*]], ptr noalias noundef [[__CONTEXT:%.*]]) #[[ATTR1]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[LOOPVAR_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[LOGICAL_ADDR:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[__CONTEXT_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    store ptr [[LOOPVAR]], ptr [[LOOPVAR_ADDR]], align 8
// CHECK-NEXT:    store i32 [[LOGICAL]], ptr [[LOGICAL_ADDR]], align 4
// CHECK-NEXT:    store ptr [[__CONTEXT]], ptr [[__CONTEXT_ADDR]], align 8
// CHECK-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[__CONTEXT_ADDR]], align 8
// CHECK-NEXT:    [[TMP1:%.*]] = getelementptr inbounds nuw [[STRUCT_ANON_0:%.*]], ptr [[TMP0]], i32 0, i32 0
// CHECK-NEXT:    [[TMP2:%.*]] = load i32, ptr [[TMP1]], align 4
// CHECK-NEXT:    [[TMP3:%.*]] = load i32, ptr [[LOGICAL_ADDR]], align 4
// CHECK-NEXT:    [[MUL:%.*]] = mul i32 5, [[TMP3]]
// CHECK-NEXT:    [[ADD:%.*]] = add i32 [[TMP2]], [[MUL]]
// CHECK-NEXT:    [[TMP4:%.*]] = load ptr, ptr [[LOOPVAR_ADDR]], align 8
// CHECK-NEXT:    store i32 [[ADD]], ptr [[TMP4]], align 4
// CHECK-NEXT:    ret void
//
//
// CHECK-LABEL: define {{[^@]+}}@__captured_stmt.2
// CHECK-SAME: (ptr noundef nonnull align 4 dereferenceable(4) [[DISTANCE:%.*]], ptr noalias noundef [[__CONTEXT:%.*]]) #[[ATTR1]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[DISTANCE_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[__CONTEXT_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[DOTSTART:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[DOTSTOP:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[DOTSTEP:%.*]] = alloca i32, align 4
// CHECK-NEXT:    store ptr [[DISTANCE]], ptr [[DISTANCE_ADDR]], align 8
// CHECK-NEXT:    store ptr [[__CONTEXT]], ptr [[__CONTEXT_ADDR]], align 8
// CHECK-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[__CONTEXT_ADDR]], align 8
// CHECK-NEXT:    [[TMP1:%.*]] = getelementptr inbounds nuw [[STRUCT_ANON_1:%.*]], ptr [[TMP0]], i32 0, i32 0
// CHECK-NEXT:    [[TMP2:%.*]] = load ptr, ptr [[TMP1]], align 8
// CHECK-NEXT:    [[TMP3:%.*]] = load i32, ptr [[TMP2]], align 4
// CHECK-NEXT:    store i32 [[TMP3]], ptr [[DOTSTART]], align 4
// CHECK-NEXT:    store i32 32, ptr [[DOTSTOP]], align 4
// CHECK-NEXT:    store i32 5, ptr [[DOTSTEP]], align 4
// CHECK-NEXT:    [[TMP4:%.*]] = load i32, ptr [[DOTSTART]], align 4
// CHECK-NEXT:    [[TMP5:%.*]] = load i32, ptr [[DOTSTOP]], align 4
// CHECK-NEXT:    [[CMP:%.*]] = icmp slt i32 [[TMP4]], [[TMP5]]
// CHECK-NEXT:    br i1 [[CMP]], label [[COND_TRUE:%.*]], label [[COND_FALSE:%.*]]
// CHECK:       cond.true:
// CHECK-NEXT:    [[TMP6:%.*]] = load i32, ptr [[DOTSTOP]], align 4
// CHECK-NEXT:    [[TMP7:%.*]] = load i32, ptr [[DOTSTART]], align 4
// CHECK-NEXT:    [[SUB:%.*]] = sub nsw i32 [[TMP6]], [[TMP7]]
// CHECK-NEXT:    [[TMP8:%.*]] = load i32, ptr [[DOTSTEP]], align 4
// CHECK-NEXT:    [[SUB1:%.*]] = sub i32 [[TMP8]], 1
// CHECK-NEXT:    [[ADD:%.*]] = add i32 [[SUB]], [[SUB1]]
// CHECK-NEXT:    [[TMP9:%.*]] = load i32, ptr [[DOTSTEP]], align 4
// CHECK-NEXT:    [[DIV:%.*]] = udiv i32 [[ADD]], [[TMP9]]
// CHECK-NEXT:    br label [[COND_END:%.*]]
// CHECK:       cond.false:
// CHECK-NEXT:    br label [[COND_END]]
// CHECK:       cond.end:
// CHECK-NEXT:    [[COND:%.*]] = phi i32 [ [[DIV]], [[COND_TRUE]] ], [ 0, [[COND_FALSE]] ]
// CHECK-NEXT:    [[TMP10:%.*]] = load ptr, ptr [[DISTANCE_ADDR]], align 8
// CHECK-NEXT:    store i32 [[COND]], ptr [[TMP10]], align 4
// CHECK-NEXT:    ret void
//
//
// CHECK-LABEL: define {{[^@]+}}@__captured_stmt.3
// CHECK-SAME: (ptr noundef nonnull align 4 dereferenceable(4) [[LOOPVAR:%.*]], i32 noundef [[LOGICAL:%.*]], ptr noalias noundef [[__CONTEXT:%.*]]) #[[ATTR1]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[LOOPVAR_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[LOGICAL_ADDR:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[__CONTEXT_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    store ptr [[LOOPVAR]], ptr [[LOOPVAR_ADDR]], align 8
// CHECK-NEXT:    store i32 [[LOGICAL]], ptr [[LOGICAL_ADDR]], align 4
// CHECK-NEXT:    store ptr [[__CONTEXT]], ptr [[__CONTEXT_ADDR]], align 8
// CHECK-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[__CONTEXT_ADDR]], align 8
// CHECK-NEXT:    [[TMP1:%.*]] = getelementptr inbounds nuw [[STRUCT_ANON_2:%.*]], ptr [[TMP0]], i32 0, i32 0
// CHECK-NEXT:    [[TMP2:%.*]] = load i32, ptr [[TMP1]], align 4
// CHECK-NEXT:    [[TMP3:%.*]] = load i32, ptr [[LOGICAL_ADDR]], align 4
// CHECK-NEXT:    [[MUL:%.*]] = mul i32 5, [[TMP3]]
// CHECK-NEXT:    [[ADD:%.*]] = add i32 [[TMP2]], [[MUL]]
// CHECK-NEXT:    [[TMP4:%.*]] = load ptr, ptr [[LOOPVAR_ADDR]], align 8
// CHECK-NEXT:    store i32 [[ADD]], ptr [[TMP4]], align 4
// CHECK-NEXT:    ret void
//
//.
// CHECK: attributes #[[ATTR0]] = { mustprogress noinline nounwind optnone "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-features"="+cx8,+mmx,+sse,+sse2,+x87" }
// CHECK: attributes #[[ATTR1]] = { noinline nounwind optnone "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-features"="+cx8,+mmx,+sse,+sse2,+x87" }
//.
// CHECK: [[META0:![0-9]+]] = !{i32 1, !"wchar_size", i32 4}
// CHECK: [[META1:![0-9]+]] = !{i32 7, !"openmp", i32 45}
// CHECK: [[META2:![0-9]+]] = !{!"{{.*}}clang version {{.*}}"}
// CHECK: [[LOOP3]] = distinct !{[[LOOP3]], [[META4:![0-9]+]], [[META5:![0-9]+]]}
// CHECK: [[META4]] = !{!"llvm.loop.vectorize.enable", i1 true}
// CHECK: [[META5]] = !{!"llvm.loop.vectorize.width", i32 2}
// CHECK: [[ACC_GRP6]] = distinct !{}
// CHECK: [[LOOP7]] = distinct !{[[LOOP7]], [[META8:![0-9]+]], [[META4]]}
// CHECK: [[META8]] = !{!"llvm.loop.parallel_accesses", [[ACC_GRP6]]}
//.
