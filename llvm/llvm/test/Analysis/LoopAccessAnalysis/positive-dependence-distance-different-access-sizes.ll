; NOTE: Assertions have been autogenerated by utils/update_analyze_test_checks.py UTC_ARGS: --version 4
; RUN: opt -passes='print<access-info>' -disable-output %s 2>&1 | FileCheck %s

target datalayout = "e-m:o-i64:64-i128:128-n32:64-S128"

; TODO: No runtime checks should be needed, as the distance between accesses
; is large enough to need runtime checks.
define void @test_distance_positive_independent_via_trip_count(ptr %A) {
; CHECK-LABEL: 'test_distance_positive_independent_via_trip_count'
; CHECK-NEXT:    loop:
; CHECK-NEXT:      Memory dependences are safe with run-time checks
; CHECK-NEXT:      Dependences:
; CHECK-NEXT:      Run-time memory checks:
; CHECK-NEXT:      Check 0:
; CHECK-NEXT:        Comparing group ([[GRP1:0x[0-9a-f]+]]):
; CHECK-NEXT:          %gep.A.400 = getelementptr inbounds i32, ptr %A.400, i64 %iv
; CHECK-NEXT:        Against group ([[GRP2:0x[0-9a-f]+]]):
; CHECK-NEXT:          %gep.A = getelementptr inbounds i8, ptr %A, i64 %iv
; CHECK-NEXT:      Grouped accesses:
; CHECK-NEXT:        Group [[GRP1]]:
; CHECK-NEXT:          (Low: (400 + %A)<nuw> High: (804 + %A))
; CHECK-NEXT:            Member: {(400 + %A)<nuw>,+,4}<nuw><%loop>
; CHECK-NEXT:        Group [[GRP2]]:
; CHECK-NEXT:          (Low: %A High: (101 + %A))
; CHECK-NEXT:            Member: {%A,+,1}<nuw><%loop>
; CHECK-EMPTY:
; CHECK-NEXT:      Non vectorizable stores to invariant address were not found in loop.
; CHECK-NEXT:      SCEV assumptions:
; CHECK-EMPTY:
; CHECK-NEXT:      Expressions re-written:
;
entry:
  %A.400 = getelementptr inbounds i8, ptr %A, i64 400
  br label %loop

loop:
  %iv = phi i64 [ 0, %entry ], [ %iv.next, %loop ]
  %gep.A.400 = getelementptr inbounds i32, ptr %A.400, i64 %iv
  %gep.A = getelementptr inbounds i8, ptr %A, i64 %iv
  %l = load i8, ptr %gep.A, align 1
  %ext = zext i8 %l to i32
  store i32 %ext, ptr %gep.A.400, align 4
  %iv.next = add nuw nsw i64 %iv, 1
  %ec = icmp eq i64 %iv, 100
  br i1 %ec, label %exit, label %loop

exit:
  ret void
}

; TODO: Currently this is considered vectorizable with runtime checks, but the
; runtime checks are never true.
define void @test_distance_positive_backwards(ptr %A) {
; CHECK-LABEL: 'test_distance_positive_backwards'
; CHECK-NEXT:    loop:
; CHECK-NEXT:      Memory dependences are safe with run-time checks
; CHECK-NEXT:      Dependences:
; CHECK-NEXT:      Run-time memory checks:
; CHECK-NEXT:      Check 0:
; CHECK-NEXT:        Comparing group ([[GRP3:0x[0-9a-f]+]]):
; CHECK-NEXT:          %gep.A.400 = getelementptr inbounds i32, ptr %A.1, i64 %iv
; CHECK-NEXT:        Against group ([[GRP4:0x[0-9a-f]+]]):
; CHECK-NEXT:          %gep.A = getelementptr inbounds i8, ptr %A, i64 %iv
; CHECK-NEXT:      Grouped accesses:
; CHECK-NEXT:        Group [[GRP3]]:
; CHECK-NEXT:          (Low: (1 + %A)<nuw> High: (405 + %A))
; CHECK-NEXT:            Member: {(1 + %A)<nuw>,+,4}<nuw><%loop>
; CHECK-NEXT:        Group [[GRP4]]:
; CHECK-NEXT:          (Low: %A High: (101 + %A))
; CHECK-NEXT:            Member: {%A,+,1}<nuw><%loop>
; CHECK-EMPTY:
; CHECK-NEXT:      Non vectorizable stores to invariant address were not found in loop.
; CHECK-NEXT:      SCEV assumptions:
; CHECK-EMPTY:
; CHECK-NEXT:      Expressions re-written:
;
entry:
  %A.1 = getelementptr inbounds i8, ptr %A, i64 1
  br label %loop

loop:
  %iv = phi i64 [ 0, %entry ], [ %iv.next, %loop ]
  %gep.A.400 = getelementptr inbounds i32, ptr %A.1, i64 %iv
  %gep.A = getelementptr inbounds i8, ptr %A, i64 %iv
  %l = load i8, ptr %gep.A, align 1
  %ext = zext i8 %l to i32
  store i32 %ext, ptr %gep.A.400, align 4
  %iv.next = add nuw nsw i64 %iv, 1
  %ec = icmp eq i64 %iv, 100
  br i1 %ec, label %exit, label %loop

exit:
  ret void
}

define void @test_distance_positive_via_assume(ptr %A, i64 %off) {
; CHECK-LABEL: 'test_distance_positive_via_assume'
; CHECK-NEXT:    loop:
; CHECK-NEXT:      Memory dependences are safe with run-time checks
; CHECK-NEXT:      Dependences:
; CHECK-NEXT:      Run-time memory checks:
; CHECK-NEXT:      Check 0:
; CHECK-NEXT:        Comparing group ([[GRP5:0x[0-9a-f]+]]):
; CHECK-NEXT:          %gep.A.400 = getelementptr inbounds i32, ptr %A.off, i64 %iv
; CHECK-NEXT:        Against group ([[GRP6:0x[0-9a-f]+]]):
; CHECK-NEXT:          %gep.A = getelementptr inbounds i8, ptr %A, i64 %iv
; CHECK-NEXT:      Grouped accesses:
; CHECK-NEXT:        Group [[GRP5]]:
; CHECK-NEXT:          (Low: (%off + %A) High: (404 + %off + %A))
; CHECK-NEXT:            Member: {(%off + %A),+,4}<nw><%loop>
; CHECK-NEXT:        Group [[GRP6]]:
; CHECK-NEXT:          (Low: %A High: (101 + %A))
; CHECK-NEXT:            Member: {%A,+,1}<nuw><%loop>
; CHECK-EMPTY:
; CHECK-NEXT:      Non vectorizable stores to invariant address were not found in loop.
; CHECK-NEXT:      SCEV assumptions:
; CHECK-EMPTY:
; CHECK-NEXT:      Expressions re-written:
;
entry:
  %c = icmp sgt i64 %off, 0
  call void @llvm.assume(i1 %c)
  %A.off = getelementptr inbounds i8, ptr %A, i64 %off
  br label %loop

loop:
  %iv = phi i64 [ 0, %entry ], [ %iv.next, %loop ]
  %gep.A.400 = getelementptr inbounds i32, ptr %A.off, i64 %iv
  %gep.A = getelementptr inbounds i8, ptr %A, i64 %iv
  %l = load i8, ptr %gep.A, align 1
  %ext = zext i8 %l to i32
  store i32 %ext, ptr %gep.A.400, align 4
  %iv.next = add nuw nsw i64 %iv, 1
  %ec = icmp eq i64 %iv, 100
  br i1 %ec, label %exit, label %loop

exit:
  ret void
}

declare void @llvm.assume(i1)
