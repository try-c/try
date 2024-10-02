; NOTE: Assertions have been autogenerated by utils/update_analyze_test_checks.py UTC_ARGS: --version 4
; RUN: opt -passes='print<access-info>' -disable-output %s 2>&1 | FileCheck %s

target datalayout = "e-m:o-i64:64-i128:128-n32:64-S128"

declare void @llvm.assume(i1)

define void @different_non_constant_strides_known_forward(ptr %A) {
; CHECK-LABEL: 'different_non_constant_strides_known_forward'
; CHECK-NEXT:    loop:
; CHECK-NEXT:      Memory dependences are safe
; CHECK-NEXT:      Dependences:
; CHECK-NEXT:        Forward:
; CHECK-NEXT:            %l = load i32, ptr %gep.mul.2, align 4 ->
; CHECK-NEXT:            store i32 %add, ptr %gep, align 4
; CHECK-EMPTY:
; CHECK-NEXT:      Run-time memory checks:
; CHECK-NEXT:      Grouped accesses:
; CHECK-EMPTY:
; CHECK-NEXT:      Non vectorizable stores to invariant address were not found in loop.
; CHECK-NEXT:      SCEV assumptions:
; CHECK-EMPTY:
; CHECK-NEXT:      Expressions re-written:
;
entry:
  br label %loop

loop:
  %iv = phi i64 [ 0, %entry ], [ %iv.next, %loop ]
  %iv.mul.2 = shl nuw nsw i64 %iv, 1
  %gep.mul.2 = getelementptr inbounds i32, ptr %A, i64 %iv.mul.2
  %l = load i32, ptr %gep.mul.2, align 4
  %add = add nsw i32 %l, 5
  %gep = getelementptr inbounds i32, ptr %A, i64 %iv
  store i32 %add, ptr %gep, align 4
  %iv.next = add nuw nsw i64 %iv, 1
  %exitcond.not = icmp eq i64 %iv.next, 256
  br i1 %exitcond.not, label %exit, label %loop

exit:
  ret void
}

define void @different_non_constant_strides_known_forward_min_distance_3(ptr %A) {
; CHECK-LABEL: 'different_non_constant_strides_known_forward_min_distance_3'
; CHECK-NEXT:    loop:
; CHECK-NEXT:      Memory dependences are safe
; CHECK-NEXT:      Dependences:
; CHECK-NEXT:        Forward:
; CHECK-NEXT:            %l = load i32, ptr %gep.mul.2, align 4 ->
; CHECK-NEXT:            store i32 %add, ptr %gep, align 4
; CHECK-EMPTY:
; CHECK-NEXT:      Run-time memory checks:
; CHECK-NEXT:      Grouped accesses:
; CHECK-EMPTY:
; CHECK-NEXT:      Non vectorizable stores to invariant address were not found in loop.
; CHECK-NEXT:      SCEV assumptions:
; CHECK-EMPTY:
; CHECK-NEXT:      Expressions re-written:
;
entry:
  %A.3 = getelementptr inbounds i8, ptr %A, i64 3
  br label %loop

loop:
  %iv = phi i64 [ 0, %entry ], [ %iv.next, %loop ]
  %iv.mul.2 = shl nuw nsw i64 %iv, 1
  %gep.mul.2 = getelementptr inbounds i32, ptr %A.3, i64 %iv.mul.2
  %l = load i32, ptr %gep.mul.2, align 4
  %add = add nsw i32 %l, 5
  %gep = getelementptr inbounds i32, ptr %A, i64 %iv
  store i32 %add, ptr %gep, align 4
  %iv.next = add nuw nsw i64 %iv, 1
  %exitcond.not = icmp eq i64 %iv.next, 256
  br i1 %exitcond.not, label %exit, label %loop

exit:
  ret void
}

define void @different_non_constant_strides_known_forward_via_assume(ptr %A, i64 %scale) {
; CHECK-LABEL: 'different_non_constant_strides_known_forward_via_assume'
; CHECK-NEXT:    loop:
; CHECK-NEXT:      Report: cannot identify array bounds
; CHECK-NEXT:      Dependences:
; CHECK-NEXT:      Run-time memory checks:
; CHECK-NEXT:      Grouped accesses:
; CHECK-EMPTY:
; CHECK-NEXT:      Non vectorizable stores to invariant address were not found in loop.
; CHECK-NEXT:      SCEV assumptions:
; CHECK-EMPTY:
; CHECK-NEXT:      Expressions re-written:
;
entry:
  %c = icmp sgt i64 %scale, 0
  call void @llvm.assume(i1 %c)
  br label %loop

loop:
  %iv = phi i64 [ 0, %entry ], [ %iv.next, %loop ]
  %iv.mul.2 = shl nuw nsw i64 %iv, %scale
  %gep.mul.2 = getelementptr inbounds i32, ptr %A, i64 %iv.mul.2
  %l = load i32, ptr %gep.mul.2, align 4
  %add = add nsw i32 %l, 5
  %gep = getelementptr inbounds i32, ptr %A, i64 %iv
  store i32 %add, ptr %gep, align 4
  %iv.next = add nuw nsw i64 %iv, 1
  %exitcond.not = icmp eq i64 %iv.next, 256
  br i1 %exitcond.not, label %exit, label %loop

exit:
  ret void
}

define void @different_non_constant_strides_known_forward_via_assume_min_distance_3(ptr %A, i64 %scale) {
; CHECK-LABEL: 'different_non_constant_strides_known_forward_via_assume_min_distance_3'
; CHECK-NEXT:    loop:
; CHECK-NEXT:      Report: cannot identify array bounds
; CHECK-NEXT:      Dependences:
; CHECK-NEXT:      Run-time memory checks:
; CHECK-NEXT:      Grouped accesses:
; CHECK-EMPTY:
; CHECK-NEXT:      Non vectorizable stores to invariant address were not found in loop.
; CHECK-NEXT:      SCEV assumptions:
; CHECK-EMPTY:
; CHECK-NEXT:      Expressions re-written:
;
entry:
  %A.3 = getelementptr inbounds i8, ptr %A, i64 3
  %c = icmp sgt i64 %scale, 0
  call void @llvm.assume(i1 %c)
  br label %loop

loop:
  %iv = phi i64 [ 0, %entry ], [ %iv.next, %loop ]
  %iv.mul.2 = shl nuw nsw i64 %iv, %scale
  %gep.mul.2 = getelementptr inbounds i32, ptr %A.3, i64 %iv.mul.2
  %l = load i32, ptr %gep.mul.2, align 4
  %add = add nsw i32 %l, 5
  %gep = getelementptr inbounds i32, ptr %A, i64 %iv
  store i32 %add, ptr %gep, align 4
  %iv.next = add nuw nsw i64 %iv, 1
  %exitcond.not = icmp eq i64 %iv.next, 256
  br i1 %exitcond.not, label %exit, label %loop

exit:
  ret void
}

define void @different_non_constant_strides_not_known_forward(ptr %A, i64 %scale) {
; CHECK-LABEL: 'different_non_constant_strides_not_known_forward'
; CHECK-NEXT:    loop:
; CHECK-NEXT:      Report: cannot identify array bounds
; CHECK-NEXT:      Dependences:
; CHECK-NEXT:      Run-time memory checks:
; CHECK-NEXT:      Grouped accesses:
; CHECK-EMPTY:
; CHECK-NEXT:      Non vectorizable stores to invariant address were not found in loop.
; CHECK-NEXT:      SCEV assumptions:
; CHECK-EMPTY:
; CHECK-NEXT:      Expressions re-written:
;
entry:
  br label %loop

loop:
  %iv = phi i64 [ 0, %entry ], [ %iv.next, %loop ]
  %iv.mul.2 = shl nuw nsw i64 %iv, %scale
  %gep.mul.2 = getelementptr inbounds i32, ptr %A, i64 %iv.mul.2
  %l = load i32, ptr %gep.mul.2, align 4
  %add = add nsw i32 %l, 5
  %gep = getelementptr inbounds i32, ptr %A, i64 %iv
  store i32 %add, ptr %gep, align 4
  %iv.next = add nuw nsw i64 %iv, 1
  %exitcond.not = icmp eq i64 %iv.next, 256
  br i1 %exitcond.not, label %exit, label %loop

exit:
  ret void
}

; Tests with accesses with strides with different signs.
define void @strides_with_different_directions_1(ptr %A) {
; CHECK-LABEL: 'strides_with_different_directions_1'
; CHECK-NEXT:    loop:
; CHECK-NEXT:      Report: unsafe dependent memory operations in loop. Use #pragma clang loop distribute(enable) to allow loop distribution to attempt to isolate the offending operations into a separate loop
; CHECK-NEXT:  Unknown data dependence.
; CHECK-NEXT:      Dependences:
; CHECK-NEXT:        Unknown:
; CHECK-NEXT:            %l = load i32, ptr %gep.mul.2, align 4 ->
; CHECK-NEXT:            store i32 %add, ptr %gep, align 4
; CHECK-EMPTY:
; CHECK-NEXT:      Run-time memory checks:
; CHECK-NEXT:      Grouped accesses:
; CHECK-EMPTY:
; CHECK-NEXT:      Non vectorizable stores to invariant address were not found in loop.
; CHECK-NEXT:      SCEV assumptions:
; CHECK-EMPTY:
; CHECK-NEXT:      Expressions re-written:
;
entry:
  br label %loop

loop:
  %iv.1 = phi i64 [ 0, %entry ], [ %iv.1.next, %loop ]
  %iv.2 = phi i64 [ 300, %entry ], [ %iv.2.next, %loop ]
  %gep.mul.2 = getelementptr inbounds i32, ptr %A, i64 %iv.1
  %l = load i32, ptr %gep.mul.2, align 4
  %add = add nsw i32 %l, 5
  %gep = getelementptr inbounds i32, ptr %A, i64 %iv.2
  store i32 %add, ptr %gep, align 4
  %iv.1.next = add nuw nsw i64 %iv.1, 1
  %iv.2.next = add nsw i64 %iv.2, -1
  %exitcond.not = icmp eq i64 %iv.1.next, 256
  br i1 %exitcond.not, label %exit, label %loop

exit:
  ret void
}

define void @strides_with_different_directions_2(ptr %A) {
; CHECK-LABEL: 'strides_with_different_directions_2'
; CHECK-NEXT:    loop:
; CHECK-NEXT:      Report: unsafe dependent memory operations in loop. Use #pragma clang loop distribute(enable) to allow loop distribution to attempt to isolate the offending operations into a separate loop
; CHECK-NEXT:  Unknown data dependence.
; CHECK-NEXT:      Dependences:
; CHECK-NEXT:        Unknown:
; CHECK-NEXT:            %l = load i32, ptr %gep.mul.2, align 4 ->
; CHECK-NEXT:            store i32 %add, ptr %gep, align 4
; CHECK-EMPTY:
; CHECK-NEXT:      Run-time memory checks:
; CHECK-NEXT:      Grouped accesses:
; CHECK-EMPTY:
; CHECK-NEXT:      Non vectorizable stores to invariant address were not found in loop.
; CHECK-NEXT:      SCEV assumptions:
; CHECK-EMPTY:
; CHECK-NEXT:      Expressions re-written:
;
entry:
  br label %loop

loop:
  %iv.1 = phi i64 [ 0, %entry ], [ %iv.1.next, %loop ]
  %iv.2 = phi i64 [ 300, %entry ], [ %iv.2.next, %loop ]
  %gep.mul.2 = getelementptr inbounds i32, ptr %A, i64 %iv.2
  %l = load i32, ptr %gep.mul.2, align 4
  %add = add nsw i32 %l, 5
  %gep = getelementptr inbounds i32, ptr %A, i64 %iv.1
  store i32 %add, ptr %gep, align 4
  %iv.1.next = add nuw nsw i64 %iv.1, 1
  %iv.2.next = add nsw i64 %iv.2, -1
  %exitcond.not = icmp eq i64 %iv.1.next, 256
  br i1 %exitcond.not, label %exit, label %loop

exit:
  ret void
}

define void @strides_with_different_directions_3(ptr %A) {
; CHECK-LABEL: 'strides_with_different_directions_3'
; CHECK-NEXT:    loop:
; CHECK-NEXT:      Report: unsafe dependent memory operations in loop. Use #pragma clang loop distribute(enable) to allow loop distribution to attempt to isolate the offending operations into a separate loop
; CHECK-NEXT:  Unknown data dependence.
; CHECK-NEXT:      Dependences:
; CHECK-NEXT:        Unknown:
; CHECK-NEXT:            %l = load i32, ptr %gep.mul.2, align 4 ->
; CHECK-NEXT:            store i32 %add, ptr %gep, align 4
; CHECK-EMPTY:
; CHECK-NEXT:      Run-time memory checks:
; CHECK-NEXT:      Grouped accesses:
; CHECK-EMPTY:
; CHECK-NEXT:      Non vectorizable stores to invariant address were not found in loop.
; CHECK-NEXT:      SCEV assumptions:
; CHECK-EMPTY:
; CHECK-NEXT:      Expressions re-written:
;
entry:
  br label %loop

loop:
  %iv.1 = phi i64 [ 0, %entry ], [ %iv.1.next, %loop ]
  %iv.2 = phi i64 [ 600, %entry ], [ %iv.2.next, %loop ]
  %gep.mul.2 = getelementptr inbounds i32, ptr %A, i64 %iv.1
  %l = load i32, ptr %gep.mul.2, align 4
  %add = add nsw i32 %l, 5
  %gep = getelementptr inbounds i32, ptr %A, i64 %iv.2
  store i32 %add, ptr %gep, align 4
  %iv.1.next = add nuw nsw i64 %iv.1, 1
  %iv.2.next = add nsw i64 %iv.2, -2
  %exitcond.not = icmp eq i64 %iv.1.next, 256
  br i1 %exitcond.not, label %exit, label %loop

exit:
  ret void
}

define void @strides_with_different_directions_4(ptr %A) {
; CHECK-LABEL: 'strides_with_different_directions_4'
; CHECK-NEXT:    loop:
; CHECK-NEXT:      Report: unsafe dependent memory operations in loop. Use #pragma clang loop distribute(enable) to allow loop distribution to attempt to isolate the offending operations into a separate loop
; CHECK-NEXT:  Unknown data dependence.
; CHECK-NEXT:      Dependences:
; CHECK-NEXT:        Unknown:
; CHECK-NEXT:            %l = load i32, ptr %gep.mul.2, align 4 ->
; CHECK-NEXT:            store i32 %add, ptr %gep, align 4
; CHECK-EMPTY:
; CHECK-NEXT:      Run-time memory checks:
; CHECK-NEXT:      Grouped accesses:
; CHECK-EMPTY:
; CHECK-NEXT:      Non vectorizable stores to invariant address were not found in loop.
; CHECK-NEXT:      SCEV assumptions:
; CHECK-EMPTY:
; CHECK-NEXT:      Expressions re-written:
;
entry:
  br label %loop

loop:
  %iv.1 = phi i64 [ 0, %entry ], [ %iv.1.next, %loop ]
  %iv.2 = phi i64 [ 600, %entry ], [ %iv.2.next, %loop ]
  %gep.mul.2 = getelementptr inbounds i32, ptr %A, i64 %iv.2
  %l = load i32, ptr %gep.mul.2, align 4
  %add = add nsw i32 %l, 5
  %gep = getelementptr inbounds i32, ptr %A, i64 %iv.1
  store i32 %add, ptr %gep, align 4
  %iv.1.next = add nuw nsw i64 %iv.1, 1
  %iv.2.next = add nsw i64 %iv.2, -2
  %exitcond.not = icmp eq i64 %iv.1.next, 256
  br i1 %exitcond.not, label %exit, label %loop

exit:
  ret void
}

define void @non_constant_strides_with_different_directions_1(ptr %A) {
; CHECK-LABEL: 'non_constant_strides_with_different_directions_1'
; CHECK-NEXT:    loop:
; CHECK-NEXT:      Report: unsafe dependent memory operations in loop. Use #pragma clang loop distribute(enable) to allow loop distribution to attempt to isolate the offending operations into a separate loop
; CHECK-NEXT:  Unknown data dependence.
; CHECK-NEXT:      Dependences:
; CHECK-NEXT:        Unknown:
; CHECK-NEXT:            %l = load i32, ptr %gep.mul.2, align 4 ->
; CHECK-NEXT:            store i32 %add, ptr %gep, align 4
; CHECK-EMPTY:
; CHECK-NEXT:      Run-time memory checks:
; CHECK-NEXT:      Grouped accesses:
; CHECK-EMPTY:
; CHECK-NEXT:      Non vectorizable stores to invariant address were not found in loop.
; CHECK-NEXT:      SCEV assumptions:
; CHECK-EMPTY:
; CHECK-NEXT:      Expressions re-written:
;
entry:
  br label %loop

loop:
  %iv.1 = phi i64 [ 0, %entry ], [ %iv.1.next, %loop ]
  %iv.2 = phi i64 [ 300, %entry ], [ %iv.2.next, %loop ]
  %iv.mul.2 = shl nuw nsw i64 %iv.1, 1
  %gep.mul.2 = getelementptr inbounds i32, ptr %A, i64 %iv.mul.2
  %l = load i32, ptr %gep.mul.2, align 4
  %add = add nsw i32 %l, 5
  %gep = getelementptr inbounds i32, ptr %A, i64 %iv.2
  store i32 %add, ptr %gep, align 4
  %iv.1.next = add nuw nsw i64 %iv.1, 1
  %iv.2.next = add nsw i64 %iv.2, -1
  %exitcond.not = icmp eq i64 %iv.1.next, 256
  br i1 %exitcond.not, label %exit, label %loop

exit:
  ret void
}

define void @non_constant_strides_with_different_directions_2(ptr %A) {
; CHECK-LABEL: 'non_constant_strides_with_different_directions_2'
; CHECK-NEXT:    loop:
; CHECK-NEXT:      Report: unsafe dependent memory operations in loop. Use #pragma clang loop distribute(enable) to allow loop distribution to attempt to isolate the offending operations into a separate loop
; CHECK-NEXT:  Unknown data dependence.
; CHECK-NEXT:      Dependences:
; CHECK-NEXT:        Unknown:
; CHECK-NEXT:            %l = load i32, ptr %gep.mul.2, align 4 ->
; CHECK-NEXT:            store i32 %add, ptr %gep, align 4
; CHECK-EMPTY:
; CHECK-NEXT:      Run-time memory checks:
; CHECK-NEXT:      Grouped accesses:
; CHECK-EMPTY:
; CHECK-NEXT:      Non vectorizable stores to invariant address were not found in loop.
; CHECK-NEXT:      SCEV assumptions:
; CHECK-EMPTY:
; CHECK-NEXT:      Expressions re-written:
;
entry:
  br label %loop

loop:
  %iv.1 = phi i64 [ 0, %entry ], [ %iv.1.next, %loop ]
  %iv.2 = phi i64 [ 300, %entry ], [ %iv.2.next, %loop ]
  %iv.mul.2 = shl nuw nsw i64 %iv.2, 1
  %gep.mul.2 = getelementptr inbounds i32, ptr %A, i64 %iv.mul.2
  %l = load i32, ptr %gep.mul.2, align 4
  %add = add nsw i32 %l, 5
  %gep = getelementptr inbounds i32, ptr %A, i64 %iv.1
  store i32 %add, ptr %gep, align 4
  %iv.1.next = add nuw nsw i64 %iv.1, 1
  %iv.2.next = add nsw i64 %iv.2, -1
  %exitcond.not = icmp eq i64 %iv.1.next, 256
  br i1 %exitcond.not, label %exit, label %loop

exit:
  ret void
}
