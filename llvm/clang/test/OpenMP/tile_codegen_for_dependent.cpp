// Check code generation
// RUN: %clang_cc1 -verify -triple x86_64-pc-linux-gnu -fopenmp -emit-llvm %s -o - | FileCheck %s --check-prefix=IR

// Check same results after serialization round-trip
// RUN: %clang_cc1 -verify -triple x86_64-pc-linux-gnu -fopenmp -emit-pch -o %t %s
// RUN: %clang_cc1 -verify -triple x86_64-pc-linux-gnu -fopenmp -include-pch %t -emit-llvm %s -o - | FileCheck %s --check-prefix=IR
// expected-no-diagnostics

// The loop trip count used by #pragma omp for depends on code generated
// by #pragma omp file. Check that theses PreInits are emitted before
// the code generated by #pragma omp for.

#ifndef HEADER
#define HEADER

// placeholder for loop body code.
extern "C" void body(...) {}


// IR-LABEL: define {{.*}}@func(
// IR-NEXT:  [[ENTRY:.*]]:
// IR-NEXT:    %[[START_ADDR:.+]] = alloca i32, align 4
// IR-NEXT:    %[[END_ADDR:.+]] = alloca i32, align 4
// IR-NEXT:    %[[STEP_ADDR:.+]] = alloca i32, align 4
// IR-NEXT:    %[[DOTOMP_IV:.+]] = alloca i32, align 4
// IR-NEXT:    %[[TMP:.+]] = alloca i32, align 4
// IR-NEXT:    %[[I:.+]] = alloca i32, align 4
// IR-NEXT:    %[[DOTCAPTURE_EXPR_:.+]] = alloca i32, align 4
// IR-NEXT:    %[[DOTCAPTURE_EXPR_1:.+]] = alloca i32, align 4
// IR-NEXT:    %[[DOTNEW_STEP:.+]] = alloca i32, align 4
// IR-NEXT:    %[[DOTCAPTURE_EXPR_2:.+]] = alloca i32, align 4
// IR-NEXT:    %[[DOTCAPTURE_EXPR_5:.+]] = alloca i32, align 4
// IR-NEXT:    %[[DOTCAPTURE_EXPR_7:.+]] = alloca i32, align 4
// IR-NEXT:    %[[DOTFLOOR_0_IV_I:.+]] = alloca i32, align 4
// IR-NEXT:    %[[DOTOMP_LB:.+]] = alloca i32, align 4
// IR-NEXT:    %[[DOTOMP_UB:.+]] = alloca i32, align 4
// IR-NEXT:    %[[DOTOMP_STRIDE:.+]] = alloca i32, align 4
// IR-NEXT:    %[[DOTOMP_IS_LAST:.+]] = alloca i32, align 4
// IR-NEXT:    %[[DOTFLOOR_0_IV_I11:.+]] = alloca i32, align 4
// IR-NEXT:    %[[DOTTILE_0_IV_I:.+]] = alloca i32, align 4
// IR-NEXT:    %[[TMP0:.+]] = call i32 @__kmpc_global_thread_num(ptr @[[GLOB2:.+]])
// IR-NEXT:    store i32 %[[START:.+]], ptr %[[START_ADDR]], align 4
// IR-NEXT:    store i32 %[[END:.+]], ptr %[[END_ADDR]], align 4
// IR-NEXT:    store i32 %[[STEP:.+]], ptr %[[STEP_ADDR]], align 4
// IR-NEXT:    %[[TMP1:.+]] = load i32, ptr %[[START_ADDR]], align 4
// IR-NEXT:    store i32 %[[TMP1]], ptr %[[I]], align 4
// IR-NEXT:    %[[TMP2:.+]] = load i32, ptr %[[START_ADDR]], align 4
// IR-NEXT:    store i32 %[[TMP2]], ptr %[[DOTCAPTURE_EXPR_]], align 4
// IR-NEXT:    %[[TMP3:.+]] = load i32, ptr %[[END_ADDR]], align 4
// IR-NEXT:    store i32 %[[TMP3]], ptr %[[DOTCAPTURE_EXPR_1]], align 4
// IR-NEXT:    %[[TMP4:.+]] = load i32, ptr %[[STEP_ADDR]], align 4
// IR-NEXT:    store i32 %[[TMP4]], ptr %[[DOTNEW_STEP]], align 4
// IR-NEXT:    %[[TMP5:.+]] = load i32, ptr %[[DOTCAPTURE_EXPR_1]], align 4
// IR-NEXT:    %[[TMP6:.+]] = load i32, ptr %[[DOTCAPTURE_EXPR_]], align 4
// IR-NEXT:    %[[SUB:.+]] = sub i32 %[[TMP5]], %[[TMP6]]
// IR-NEXT:    %[[SUB3:.+]] = sub i32 %[[SUB]], 1
// IR-NEXT:    %[[TMP7:.+]] = load i32, ptr %[[DOTNEW_STEP]], align 4
// IR-NEXT:    %[[ADD:.+]] = add i32 %[[SUB3]], %[[TMP7]]
// IR-NEXT:    %[[TMP8:.+]] = load i32, ptr %[[DOTNEW_STEP]], align 4
// IR-NEXT:    %[[DIV:.+]] = udiv i32 %[[ADD]], %[[TMP8]]
// IR-NEXT:    %[[SUB4:.+]] = sub i32 %[[DIV]], 1
// IR-NEXT:    store i32 %[[SUB4]], ptr %[[DOTCAPTURE_EXPR_2]], align 4
// IR-NEXT:    %[[TMP9:.+]] = load i32, ptr %[[DOTCAPTURE_EXPR_2]], align 4
// IR-NEXT:    %[[ADD6:.+]] = add i32 %[[TMP9]], 1
// IR-NEXT:    store i32 %[[ADD6]], ptr %[[DOTCAPTURE_EXPR_5]], align 4
// IR-NEXT:    %[[TMP10:.+]] = load i32, ptr %[[DOTCAPTURE_EXPR_5]], align 4
// IR-NEXT:    %[[SUB8:.+]] = sub i32 %[[TMP10]], -3
// IR-NEXT:    %[[DIV9:.+]] = udiv i32 %[[SUB8]], 4
// IR-NEXT:    %[[SUB10:.+]] = sub i32 %[[DIV9]], 1
// IR-NEXT:    store i32 %[[SUB10]], ptr %[[DOTCAPTURE_EXPR_7]], align 4
// IR-NEXT:    store i32 0, ptr %[[DOTFLOOR_0_IV_I]], align 4
// IR-NEXT:    %[[TMP11:.+]] = load i32, ptr %[[DOTCAPTURE_EXPR_5]], align 4
// IR-NEXT:    %[[CMP:.+]] = icmp ult i32 0, %[[TMP11]]
// IR-NEXT:    br i1 %[[CMP]], label %[[OMP_PRECOND_THEN:.+]], label %[[OMP_PRECOND_END:.+]]
// IR-EMPTY:
// IR-NEXT:  [[OMP_PRECOND_THEN]]:
// IR-NEXT:    store i32 0, ptr %[[DOTOMP_LB]], align 4
// IR-NEXT:    %[[TMP12:.+]] = load i32, ptr %[[DOTCAPTURE_EXPR_7]], align 4
// IR-NEXT:    store i32 %[[TMP12]], ptr %[[DOTOMP_UB]], align 4
// IR-NEXT:    store i32 1, ptr %[[DOTOMP_STRIDE]], align 4
// IR-NEXT:    store i32 0, ptr %[[DOTOMP_IS_LAST]], align 4
// IR-NEXT:    call void @__kmpc_for_static_init_4u(ptr @[[GLOB1:.+]], i32 %[[TMP0]], i32 34, ptr %[[DOTOMP_IS_LAST]], ptr %[[DOTOMP_LB]], ptr %[[DOTOMP_UB]], ptr %[[DOTOMP_STRIDE]], i32 1, i32 1)
// IR-NEXT:    %[[TMP13:.+]] = load i32, ptr %[[DOTOMP_UB]], align 4
// IR-NEXT:    %[[TMP14:.+]] = load i32, ptr %[[DOTCAPTURE_EXPR_7]], align 4
// IR-NEXT:    %[[CMP12:.+]] = icmp ugt i32 %[[TMP13]], %[[TMP14]]
// IR-NEXT:    br i1 %[[CMP12]], label %[[COND_TRUE:.+]], label %[[COND_FALSE:.+]]
// IR-EMPTY:
// IR-NEXT:  [[COND_TRUE]]:
// IR-NEXT:    %[[TMP15:.+]] = load i32, ptr %[[DOTCAPTURE_EXPR_7]], align 4
// IR-NEXT:    br label %[[COND_END:.+]]
// IR-EMPTY:
// IR-NEXT:  [[COND_FALSE]]:
// IR-NEXT:    %[[TMP16:.+]] = load i32, ptr %[[DOTOMP_UB]], align 4
// IR-NEXT:    br label %[[COND_END]]
// IR-EMPTY:
// IR-NEXT:  [[COND_END]]:
// IR-NEXT:    %[[COND:.+]] = phi i32 [ %[[TMP15]], %[[COND_TRUE]] ], [ %[[TMP16]], %[[COND_FALSE]] ]
// IR-NEXT:    store i32 %[[COND]], ptr %[[DOTOMP_UB]], align 4
// IR-NEXT:    %[[TMP17:.+]] = load i32, ptr %[[DOTOMP_LB]], align 4
// IR-NEXT:    store i32 %[[TMP17]], ptr %[[DOTOMP_IV]], align 4
// IR-NEXT:    br label %[[OMP_INNER_FOR_COND:.+]]
// IR-EMPTY:
// IR-NEXT:  [[OMP_INNER_FOR_COND]]:
// IR-NEXT:    %[[TMP18:.+]] = load i32, ptr %[[DOTOMP_IV]], align 4
// IR-NEXT:    %[[TMP19:.+]] = load i32, ptr %[[DOTOMP_UB]], align 4
// IR-NEXT:    %[[ADD13:.+]] = add i32 %[[TMP19]], 1
// IR-NEXT:    %[[CMP14:.+]] = icmp ult i32 %[[TMP18]], %[[ADD13]]
// IR-NEXT:    br i1 %[[CMP14]], label %[[OMP_INNER_FOR_BODY:.+]], label %[[OMP_INNER_FOR_END:.+]]
// IR-EMPTY:
// IR-NEXT:  [[OMP_INNER_FOR_BODY]]:
// IR-NEXT:    %[[TMP20:.+]] = load i32, ptr %[[DOTOMP_IV]], align 4
// IR-NEXT:    %[[MUL:.+]] = mul i32 %[[TMP20]], 4
// IR-NEXT:    %[[ADD15:.+]] = add i32 0, %[[MUL]]
// IR-NEXT:    store i32 %[[ADD15]], ptr %[[DOTFLOOR_0_IV_I11]], align 4
// IR-NEXT:    %[[TMP21:.+]] = load i32, ptr %[[DOTFLOOR_0_IV_I11]], align 4
// IR-NEXT:    store i32 %[[TMP21]], ptr %[[DOTTILE_0_IV_I]], align 4
// IR-NEXT:    br label %[[FOR_COND:.+]]
// IR-EMPTY:
// IR-NEXT:  [[FOR_COND]]:
// IR-NEXT:    %[[TMP22:.+]] = load i32, ptr %[[DOTTILE_0_IV_I]], align 4
// IR-NEXT:    %[[TMP23:.+]] = load i32, ptr %[[DOTCAPTURE_EXPR_2]], align 4
// IR-NEXT:    %[[ADD16:.+]] = add i32 %[[TMP23]], 1
// IR-NEXT:    %[[TMP24:.+]] = load i32, ptr %[[DOTFLOOR_0_IV_I11]], align 4
// IR-NEXT:    %[[ADD17:.+]] = add i32 %[[TMP24]], 4
// IR-NEXT:    %[[CMP18:.+]] = icmp ult i32 %[[ADD16]], %[[ADD17]]
// IR-NEXT:    br i1 %[[CMP18]], label %[[COND_TRUE19:.+]], label %[[COND_FALSE21:.+]]
// IR-EMPTY:
// IR-NEXT:  [[COND_TRUE19]]:
// IR-NEXT:    %[[TMP25:.+]] = load i32, ptr %[[DOTCAPTURE_EXPR_2]], align 4
// IR-NEXT:    %[[ADD20:.+]] = add i32 %[[TMP25]], 1
// IR-NEXT:    br label %[[COND_END23:.+]]
// IR-EMPTY:
// IR-NEXT:  [[COND_FALSE21]]:
// IR-NEXT:    %[[TMP26:.+]] = load i32, ptr %[[DOTFLOOR_0_IV_I11]], align 4
// IR-NEXT:    %[[ADD22:.+]] = add i32 %[[TMP26]], 4
// IR-NEXT:    br label %[[COND_END23]]
// IR-EMPTY:
// IR-NEXT:  [[COND_END23]]:
// IR-NEXT:    %[[COND24:.+]] = phi i32 [ %[[ADD20]], %[[COND_TRUE19]] ], [ %[[ADD22]], %[[COND_FALSE21]] ]
// IR-NEXT:    %[[CMP25:.+]] = icmp ult i32 %[[TMP22]], %[[COND24]]
// IR-NEXT:    br i1 %[[CMP25]], label %[[FOR_BODY:.+]], label %[[FOR_END:.+]]
// IR-EMPTY:
// IR-NEXT:  [[FOR_BODY]]:
// IR-NEXT:    %[[TMP27:.+]] = load i32, ptr %[[DOTCAPTURE_EXPR_]], align 4
// IR-NEXT:    %[[TMP28:.+]] = load i32, ptr %[[DOTTILE_0_IV_I]], align 4
// IR-NEXT:    %[[TMP29:.+]] = load i32, ptr %[[DOTNEW_STEP]], align 4
// IR-NEXT:    %[[MUL26:.+]] = mul i32 %[[TMP28]], %[[TMP29]]
// IR-NEXT:    %[[ADD27:.+]] = add i32 %[[TMP27]], %[[MUL26]]
// IR-NEXT:    store i32 %[[ADD27]], ptr %[[I]], align 4
// IR-NEXT:    %[[TMP30:.+]] = load i32, ptr %[[START_ADDR]], align 4
// IR-NEXT:    %[[TMP31:.+]] = load i32, ptr %[[END_ADDR]], align 4
// IR-NEXT:    %[[TMP32:.+]] = load i32, ptr %[[STEP_ADDR]], align 4
// IR-NEXT:    %[[TMP33:.+]] = load i32, ptr %[[I]], align 4
// IR-NEXT:    call void (...) @body(i32 noundef %[[TMP30]], i32 noundef %[[TMP31]], i32 noundef %[[TMP32]], i32 noundef %[[TMP33]])
// IR-NEXT:    br label %[[FOR_INC:.+]]
// IR-EMPTY:
// IR-NEXT:  [[FOR_INC]]:
// IR-NEXT:    %[[TMP34:.+]] = load i32, ptr %[[DOTTILE_0_IV_I]], align 4
// IR-NEXT:    %[[INC:.+]] = add i32 %[[TMP34]], 1
// IR-NEXT:    store i32 %[[INC]], ptr %[[DOTTILE_0_IV_I]], align 4
// IR-NEXT:    br label %[[FOR_COND]], !llvm.loop ![[LOOP3:[0-9]+]]
// IR-EMPTY:
// IR-NEXT:  [[FOR_END]]:
// IR-NEXT:    br label %[[OMP_BODY_CONTINUE:.+]]
// IR-EMPTY:
// IR-NEXT:  [[OMP_BODY_CONTINUE]]:
// IR-NEXT:    br label %[[OMP_INNER_FOR_INC:.+]]
// IR-EMPTY:
// IR-NEXT:  [[OMP_INNER_FOR_INC]]:
// IR-NEXT:    %[[TMP35:.+]] = load i32, ptr %[[DOTOMP_IV]], align 4
// IR-NEXT:    %[[ADD28:.+]] = add i32 %[[TMP35]], 1
// IR-NEXT:    store i32 %[[ADD28]], ptr %[[DOTOMP_IV]], align 4
// IR-NEXT:    br label %[[OMP_INNER_FOR_COND]]
// IR-EMPTY:
// IR-NEXT:  [[OMP_INNER_FOR_END]]:
// IR-NEXT:    br label %[[OMP_LOOP_EXIT:.+]]
// IR-EMPTY:
// IR-NEXT:  [[OMP_LOOP_EXIT]]:
// IR-NEXT:    call void @__kmpc_for_static_fini(ptr @[[GLOB1]], i32 %[[TMP0]])
// IR-NEXT:    br label %[[OMP_PRECOND_END]]
// IR-EMPTY:
// IR-NEXT:  [[OMP_PRECOND_END]]:
// IR-NEXT:    call void @__kmpc_barrier(ptr @[[GLOB3:.+]], i32 %[[TMP0]])
// IR-NEXT:    ret void
// IR-NEXT:  }
extern "C" void func(int start, int end, int step) {
#pragma omp for
#pragma omp tile sizes(4)
  for (int i = start; i < end; i += step)
    body(start, end, step, i);
}

#endif /* HEADER */
