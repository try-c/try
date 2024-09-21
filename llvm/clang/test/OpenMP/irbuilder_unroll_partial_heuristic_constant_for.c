// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --function-signature --include-generated-funcs --replace-value-regex "__omp_offloading_[0-9a-z]+_[0-9a-z]+" "reduction_  size[.].+[.]" "pl_cond[.].+[.|,]" --prefix-filecheck-ir-name _
// RUN: %clang_cc1 -fopenmp-enable-irbuilder -verify -fopenmp -x c -triple x86_64-unknown-unknown -emit-llvm %s -o - | FileCheck %s
// expected-no-diagnostics

// REQUIRES: x86-registered-target

// TODO: The unroll-factor heuristic might be able to use the information that the trip count is constant, but currently is not able to determine that.

#ifndef HEADER
#define HEADER

double sind(double);


void unroll_partial_heuristic_constant_for(float *a, float *b, float *c, float *d, float *e, float offset) {
#pragma omp for
#pragma omp unroll partial
  for (int i = 0; i < 128; i++) {
    a[i] += sind(b[i]) * c[i] * d[i] * e[i] + offset;
  }
}

#endif // HEADER





// CHECK-LABEL: define {{[^@]+}}@unroll_partial_heuristic_constant_for
// CHECK-SAME: (ptr noundef [[A:%.*]], ptr noundef [[B:%.*]], ptr noundef [[C:%.*]], ptr noundef [[D:%.*]], ptr noundef [[E:%.*]], float noundef [[OFFSET:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[A_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[B_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[C_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[D_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[E_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[OFFSET_ADDR:%.*]] = alloca float, align 4
// CHECK-NEXT:    [[I:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[AGG_CAPTURED:%.*]] = alloca [[STRUCT_ANON:%.*]], align 8
// CHECK-NEXT:    [[AGG_CAPTURED1:%.*]] = alloca [[STRUCT_ANON_0:%.*]], align 4
// CHECK-NEXT:    [[DOTCOUNT_ADDR:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[P_LASTITER:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[P_LOWERBOUND:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[P_UPPERBOUND:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[P_STRIDE:%.*]] = alloca i32, align 4
// CHECK-NEXT:    store ptr [[A]], ptr [[A_ADDR]], align 8
// CHECK-NEXT:    store ptr [[B]], ptr [[B_ADDR]], align 8
// CHECK-NEXT:    store ptr [[C]], ptr [[C_ADDR]], align 8
// CHECK-NEXT:    store ptr [[D]], ptr [[D_ADDR]], align 8
// CHECK-NEXT:    store ptr [[E]], ptr [[E_ADDR]], align 8
// CHECK-NEXT:    store float [[OFFSET]], ptr [[OFFSET_ADDR]], align 4
// CHECK-NEXT:    store i32 0, ptr [[I]], align 4
// CHECK-NEXT:    [[TMP0:%.*]] = getelementptr inbounds nuw [[STRUCT_ANON]], ptr [[AGG_CAPTURED]], i32 0, i32 0
// CHECK-NEXT:    store ptr [[I]], ptr [[TMP0]], align 8
// CHECK-NEXT:    [[TMP1:%.*]] = getelementptr inbounds nuw [[STRUCT_ANON_0]], ptr [[AGG_CAPTURED1]], i32 0, i32 0
// CHECK-NEXT:    [[TMP2:%.*]] = load i32, ptr [[I]], align 4
// CHECK-NEXT:    store i32 [[TMP2]], ptr [[TMP1]], align 4
// CHECK-NEXT:    call void @__captured_stmt(ptr [[DOTCOUNT_ADDR]], ptr [[AGG_CAPTURED]])
// CHECK-NEXT:    [[DOTCOUNT:%.*]] = load i32, ptr [[DOTCOUNT_ADDR]], align 4
// CHECK-NEXT:    br label [[OMP_LOOP_PREHEADER:%.*]]
// CHECK:       omp_loop.preheader:
// CHECK-NEXT:    [[TMP3:%.*]] = udiv i32 [[DOTCOUNT]], 4
// CHECK-NEXT:    [[TMP4:%.*]] = urem i32 [[DOTCOUNT]], 4
// CHECK-NEXT:    [[TMP5:%.*]] = icmp ne i32 [[TMP4]], 0
// CHECK-NEXT:    [[TMP6:%.*]] = zext i1 [[TMP5]] to i32
// CHECK-NEXT:    [[OMP_FLOOR0_TRIPCOUNT:%.*]] = add nuw i32 [[TMP3]], [[TMP6]]
// CHECK-NEXT:    br label [[OMP_FLOOR0_PREHEADER:%.*]]
// CHECK:       omp_floor0.preheader:
// CHECK-NEXT:    store i32 0, ptr [[P_LOWERBOUND]], align 4
// CHECK-NEXT:    [[TMP7:%.*]] = sub i32 [[OMP_FLOOR0_TRIPCOUNT]], 1
// CHECK-NEXT:    store i32 [[TMP7]], ptr [[P_UPPERBOUND]], align 4
// CHECK-NEXT:    store i32 1, ptr [[P_STRIDE]], align 4
// CHECK-NEXT:    [[OMP_GLOBAL_THREAD_NUM:%.*]] = call i32 @__kmpc_global_thread_num(ptr @[[GLOB1:[0-9]+]])
// CHECK-NEXT:    call void @__kmpc_for_static_init_4u(ptr @[[GLOB1]], i32 [[OMP_GLOBAL_THREAD_NUM]], i32 34, ptr [[P_LASTITER]], ptr [[P_LOWERBOUND]], ptr [[P_UPPERBOUND]], ptr [[P_STRIDE]], i32 1, i32 0)
// CHECK-NEXT:    [[TMP8:%.*]] = load i32, ptr [[P_LOWERBOUND]], align 4
// CHECK-NEXT:    [[TMP9:%.*]] = load i32, ptr [[P_UPPERBOUND]], align 4
// CHECK-NEXT:    [[TMP10:%.*]] = sub i32 [[TMP9]], [[TMP8]]
// CHECK-NEXT:    [[TMP11:%.*]] = add i32 [[TMP10]], 1
// CHECK-NEXT:    br label [[OMP_FLOOR0_HEADER:%.*]]
// CHECK:       omp_floor0.header:
// CHECK-NEXT:    [[OMP_FLOOR0_IV:%.*]] = phi i32 [ 0, [[OMP_FLOOR0_PREHEADER]] ], [ [[OMP_FLOOR0_NEXT:%.*]], [[OMP_FLOOR0_INC:%.*]] ]
// CHECK-NEXT:    br label [[OMP_FLOOR0_COND:%.*]]
// CHECK:       omp_floor0.cond:
// CHECK-NEXT:    [[OMP_FLOOR0_CMP:%.*]] = icmp ult i32 [[OMP_FLOOR0_IV]], [[TMP11]]
// CHECK-NEXT:    br i1 [[OMP_FLOOR0_CMP]], label [[OMP_FLOOR0_BODY:%.*]], label [[OMP_FLOOR0_EXIT:%.*]]
// CHECK:       omp_floor0.body:
// CHECK-NEXT:    [[TMP12:%.*]] = add i32 [[OMP_FLOOR0_IV]], [[TMP8]]
// CHECK-NEXT:    [[TMP13:%.*]] = icmp eq i32 [[TMP12]], [[OMP_FLOOR0_TRIPCOUNT]]
// CHECK-NEXT:    [[TMP14:%.*]] = select i1 [[TMP13]], i32 [[TMP4]], i32 4
// CHECK-NEXT:    br label [[OMP_TILE0_PREHEADER:%.*]]
// CHECK:       omp_tile0.preheader:
// CHECK-NEXT:    br label [[OMP_TILE0_HEADER:%.*]]
// CHECK:       omp_tile0.header:
// CHECK-NEXT:    [[OMP_TILE0_IV:%.*]] = phi i32 [ 0, [[OMP_TILE0_PREHEADER]] ], [ [[OMP_TILE0_NEXT:%.*]], [[OMP_TILE0_INC:%.*]] ]
// CHECK-NEXT:    br label [[OMP_TILE0_COND:%.*]]
// CHECK:       omp_tile0.cond:
// CHECK-NEXT:    [[OMP_TILE0_CMP:%.*]] = icmp ult i32 [[OMP_TILE0_IV]], [[TMP14]]
// CHECK-NEXT:    br i1 [[OMP_TILE0_CMP]], label [[OMP_TILE0_BODY:%.*]], label [[OMP_TILE0_EXIT:%.*]]
// CHECK:       omp_tile0.body:
// CHECK-NEXT:    [[TMP15:%.*]] = mul nuw i32 4, [[TMP12]]
// CHECK-NEXT:    [[TMP16:%.*]] = add nuw i32 [[TMP15]], [[OMP_TILE0_IV]]
// CHECK-NEXT:    br label [[OMP_LOOP_BODY:%.*]]
// CHECK:       omp_loop.body:
// CHECK-NEXT:    call void @__captured_stmt.1(ptr [[I]], i32 [[TMP16]], ptr [[AGG_CAPTURED1]])
// CHECK-NEXT:    [[TMP17:%.*]] = load ptr, ptr [[B_ADDR]], align 8
// CHECK-NEXT:    [[TMP18:%.*]] = load i32, ptr [[I]], align 4
// CHECK-NEXT:    [[IDXPROM:%.*]] = sext i32 [[TMP18]] to i64
// CHECK-NEXT:    [[ARRAYIDX:%.*]] = getelementptr inbounds float, ptr [[TMP17]], i64 [[IDXPROM]]
// CHECK-NEXT:    [[TMP19:%.*]] = load float, ptr [[ARRAYIDX]], align 4
// CHECK-NEXT:    [[CONV:%.*]] = fpext float [[TMP19]] to double
// CHECK-NEXT:    [[CALL:%.*]] = call double @sind(double noundef [[CONV]])
// CHECK-NEXT:    [[TMP20:%.*]] = load ptr, ptr [[C_ADDR]], align 8
// CHECK-NEXT:    [[TMP21:%.*]] = load i32, ptr [[I]], align 4
// CHECK-NEXT:    [[IDXPROM2:%.*]] = sext i32 [[TMP21]] to i64
// CHECK-NEXT:    [[ARRAYIDX3:%.*]] = getelementptr inbounds float, ptr [[TMP20]], i64 [[IDXPROM2]]
// CHECK-NEXT:    [[TMP22:%.*]] = load float, ptr [[ARRAYIDX3]], align 4
// CHECK-NEXT:    [[CONV4:%.*]] = fpext float [[TMP22]] to double
// CHECK-NEXT:    [[MUL:%.*]] = fmul double [[CALL]], [[CONV4]]
// CHECK-NEXT:    [[TMP23:%.*]] = load ptr, ptr [[D_ADDR]], align 8
// CHECK-NEXT:    [[TMP24:%.*]] = load i32, ptr [[I]], align 4
// CHECK-NEXT:    [[IDXPROM5:%.*]] = sext i32 [[TMP24]] to i64
// CHECK-NEXT:    [[ARRAYIDX6:%.*]] = getelementptr inbounds float, ptr [[TMP23]], i64 [[IDXPROM5]]
// CHECK-NEXT:    [[TMP25:%.*]] = load float, ptr [[ARRAYIDX6]], align 4
// CHECK-NEXT:    [[CONV7:%.*]] = fpext float [[TMP25]] to double
// CHECK-NEXT:    [[MUL8:%.*]] = fmul double [[MUL]], [[CONV7]]
// CHECK-NEXT:    [[TMP26:%.*]] = load ptr, ptr [[E_ADDR]], align 8
// CHECK-NEXT:    [[TMP27:%.*]] = load i32, ptr [[I]], align 4
// CHECK-NEXT:    [[IDXPROM9:%.*]] = sext i32 [[TMP27]] to i64
// CHECK-NEXT:    [[ARRAYIDX10:%.*]] = getelementptr inbounds float, ptr [[TMP26]], i64 [[IDXPROM9]]
// CHECK-NEXT:    [[TMP28:%.*]] = load float, ptr [[ARRAYIDX10]], align 4
// CHECK-NEXT:    [[CONV11:%.*]] = fpext float [[TMP28]] to double
// CHECK-NEXT:    [[MUL12:%.*]] = fmul double [[MUL8]], [[CONV11]]
// CHECK-NEXT:    [[TMP29:%.*]] = load float, ptr [[OFFSET_ADDR]], align 4
// CHECK-NEXT:    [[CONV13:%.*]] = fpext float [[TMP29]] to double
// CHECK-NEXT:    [[ADD:%.*]] = fadd double [[MUL12]], [[CONV13]]
// CHECK-NEXT:    [[TMP30:%.*]] = load ptr, ptr [[A_ADDR]], align 8
// CHECK-NEXT:    [[TMP31:%.*]] = load i32, ptr [[I]], align 4
// CHECK-NEXT:    [[IDXPROM14:%.*]] = sext i32 [[TMP31]] to i64
// CHECK-NEXT:    [[ARRAYIDX15:%.*]] = getelementptr inbounds float, ptr [[TMP30]], i64 [[IDXPROM14]]
// CHECK-NEXT:    [[TMP32:%.*]] = load float, ptr [[ARRAYIDX15]], align 4
// CHECK-NEXT:    [[CONV16:%.*]] = fpext float [[TMP32]] to double
// CHECK-NEXT:    [[ADD17:%.*]] = fadd double [[CONV16]], [[ADD]]
// CHECK-NEXT:    [[CONV18:%.*]] = fptrunc double [[ADD17]] to float
// CHECK-NEXT:    store float [[CONV18]], ptr [[ARRAYIDX15]], align 4
// CHECK-NEXT:    br label [[OMP_TILE0_INC]]
// CHECK:       omp_tile0.inc:
// CHECK-NEXT:    [[OMP_TILE0_NEXT]] = add nuw i32 [[OMP_TILE0_IV]], 1
// CHECK-NEXT:    br label [[OMP_TILE0_HEADER]], !llvm.loop [[LOOP3:![0-9]+]]
// CHECK:       omp_tile0.exit:
// CHECK-NEXT:    br label [[OMP_TILE0_AFTER:%.*]]
// CHECK:       omp_tile0.after:
// CHECK-NEXT:    br label [[OMP_FLOOR0_INC]]
// CHECK:       omp_floor0.inc:
// CHECK-NEXT:    [[OMP_FLOOR0_NEXT]] = add nuw i32 [[OMP_FLOOR0_IV]], 1
// CHECK-NEXT:    br label [[OMP_FLOOR0_HEADER]]
// CHECK:       omp_floor0.exit:
// CHECK-NEXT:    call void @__kmpc_for_static_fini(ptr @[[GLOB1]], i32 [[OMP_GLOBAL_THREAD_NUM]])
// CHECK-NEXT:    [[OMP_GLOBAL_THREAD_NUM19:%.*]] = call i32 @__kmpc_global_thread_num(ptr @[[GLOB1]])
// CHECK-NEXT:    call void @__kmpc_barrier(ptr @[[GLOB2:[0-9]+]], i32 [[OMP_GLOBAL_THREAD_NUM19]])
// CHECK-NEXT:    br label [[OMP_FLOOR0_AFTER:%.*]]
// CHECK:       omp_floor0.after:
// CHECK-NEXT:    br label [[OMP_LOOP_AFTER:%.*]]
// CHECK:       omp_loop.after:
// CHECK-NEXT:    ret void
//
//
// CHECK-LABEL: define {{[^@]+}}@__captured_stmt
// CHECK-SAME: (ptr noundef nonnull align 4 dereferenceable(4) [[DISTANCE:%.*]], ptr noalias noundef [[__CONTEXT:%.*]]) #[[ATTR0]] {
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
// CHECK-NEXT:    store i32 128, ptr [[DOTSTOP]], align 4
// CHECK-NEXT:    store i32 1, ptr [[DOTSTEP]], align 4
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
// CHECK-SAME: (ptr noundef nonnull align 4 dereferenceable(4) [[LOOPVAR:%.*]], i32 noundef [[LOGICAL:%.*]], ptr noalias noundef [[__CONTEXT:%.*]]) #[[ATTR0]] {
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
// CHECK-NEXT:    [[MUL:%.*]] = mul i32 1, [[TMP3]]
// CHECK-NEXT:    [[ADD:%.*]] = add i32 [[TMP2]], [[MUL]]
// CHECK-NEXT:    [[TMP4:%.*]] = load ptr, ptr [[LOOPVAR_ADDR]], align 8
// CHECK-NEXT:    store i32 [[ADD]], ptr [[TMP4]], align 4
// CHECK-NEXT:    ret void
//
