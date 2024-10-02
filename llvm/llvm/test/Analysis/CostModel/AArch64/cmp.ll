; NOTE: Assertions have been autogenerated by utils/update_analyze_test_checks.py
; RUN: opt -passes="print<cost-model>" 2>&1 -disable-output -mtriple=aarch64-- < %s | FileCheck %s --check-prefix=CHECK-THROUGHPUT
; RUN: opt -passes="print<cost-model>" 2>&1 -disable-output -cost-kind=code-size -mtriple=aarch64-- < %s | FileCheck %s --check-prefix=CHECK-SIZE

target datalayout = "e-m:e-i8:8:32-i16:16:32-i64:64-i128:128-n32:64-S128"

define void @cmps() {
; CHECK-THROUGHPUT-LABEL: 'cmps'
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %c8 = icmp slt i8 undef, undef
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %c16 = icmp ult i16 undef, undef
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %c32 = icmp sge i32 undef, undef
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %c64 = icmp ne i64 undef, undef
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 2 for instruction: %c128 = icmp ult i128 undef, undef
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %cv16i8 = icmp slt <16 x i8> undef, undef
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %cv8i16 = icmp ult <8 x i16> undef, undef
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %cv4i32 = icmp sge <4 x i32> undef, undef
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %cf16 = fcmp oge half undef, undef
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %cf32 = fcmp ogt float undef, undef
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %cf64 = fcmp ogt double undef, undef
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 22 for instruction: %cfv816 = fcmp olt <8 x half> undef, undef
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %cfv432 = fcmp oge <4 x float> undef, undef
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %cfv264 = fcmp oge <2 x double> undef, undef
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 0 for instruction: ret void
;
; CHECK-SIZE-LABEL: 'cmps'
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %c8 = icmp slt i8 undef, undef
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %c16 = icmp ult i16 undef, undef
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %c32 = icmp sge i32 undef, undef
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %c64 = icmp ne i64 undef, undef
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %c128 = icmp ult i128 undef, undef
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %cv16i8 = icmp slt <16 x i8> undef, undef
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %cv8i16 = icmp ult <8 x i16> undef, undef
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %cv4i32 = icmp sge <4 x i32> undef, undef
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %cf16 = fcmp oge half undef, undef
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %cf32 = fcmp ogt float undef, undef
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %cf64 = fcmp ogt double undef, undef
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %cfv816 = fcmp olt <8 x half> undef, undef
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %cfv432 = fcmp oge <4 x float> undef, undef
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %cfv264 = fcmp oge <2 x double> undef, undef
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: ret void
;
  %c8 = icmp slt i8 undef, undef
  %c16 = icmp ult i16 undef, undef
  %c32 = icmp sge i32 undef, undef
  %c64 = icmp ne i64 undef, undef
  %c128 = icmp ult i128 undef, undef
  %cv16i8 = icmp slt <16 x i8> undef, undef
  %cv8i16 = icmp ult <8 x i16> undef, undef
  %cv4i32 = icmp sge <4 x i32> undef, undef
  %cf16 = fcmp oge half undef, undef
  %cf32 = fcmp ogt float undef, undef
  %cf64 = fcmp ogt double undef, undef
  %cfv816 = fcmp olt <8 x half> undef, undef
  %cfv432 = fcmp oge <4 x float> undef, undef
  %cfv264 = fcmp oge <2 x double> undef, undef
  ret void
}


define void @andcmp() {
; CHECK-THROUGHPUT-LABEL: 'andcmp'
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %a8 = and i8 undef, undef
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %c8 = icmp eq i8 %a8, 0
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %a16 = and i16 undef, undef
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %c16 = icmp ne i16 %a16, 0
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %a32 = and i32 undef, undef
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 0 for instruction: %c32 = icmp eq i32 %a32, 0
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %a64 = and i64 undef, undef
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 0 for instruction: %c64 = icmp ne i64 %a64, 0
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 2 for instruction: %a128 = and i128 undef, undef
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 2 for instruction: %c128 = icmp eq i128 %a128, 0
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %av16i8 = and <16 x i8> undef, undef
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %cv16i8 = icmp ne <16 x i8> %av16i8, zeroinitializer
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %av8i16 = and <8 x i16> undef, undef
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %cv8i16 = icmp eq <8 x i16> %av8i16, zeroinitializer
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %av4i32 = and <4 x i32> undef, undef
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %cv4i32 = icmp ne <4 x i32> %av4i32, zeroinitializer
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %c32not0 = icmp eq i32 %a32, 1
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %c64sle = icmp sle i64 %a64, 0
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 0 for instruction: ret void
;
; CHECK-SIZE-LABEL: 'andcmp'
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %a8 = and i8 undef, undef
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %c8 = icmp eq i8 %a8, 0
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %a16 = and i16 undef, undef
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %c16 = icmp ne i16 %a16, 0
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %a32 = and i32 undef, undef
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %c32 = icmp eq i32 %a32, 0
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %a64 = and i64 undef, undef
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %c64 = icmp ne i64 %a64, 0
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %a128 = and i128 undef, undef
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %c128 = icmp eq i128 %a128, 0
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %av16i8 = and <16 x i8> undef, undef
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %cv16i8 = icmp ne <16 x i8> %av16i8, zeroinitializer
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %av8i16 = and <8 x i16> undef, undef
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %cv8i16 = icmp eq <8 x i16> %av8i16, zeroinitializer
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %av4i32 = and <4 x i32> undef, undef
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %cv4i32 = icmp ne <4 x i32> %av4i32, zeroinitializer
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %c32not0 = icmp eq i32 %a32, 1
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %c64sle = icmp sle i64 %a64, 0
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: ret void
;
  %a8 = and i8 undef, undef
  %c8 = icmp eq i8 %a8, 0
  %a16 = and i16 undef, undef
  %c16 = icmp ne i16 %a16, 0
  %a32 = and i32 undef, undef
  %c32 = icmp eq i32 %a32, 0
  %a64 = and i64 undef, undef
  %c64 = icmp ne i64 %a64, 0
  %a128 = and i128 undef, undef
  %c128 = icmp eq i128 %a128, zeroinitializer
  %av16i8 = and <16 x i8> undef, undef
  %cv16i8 = icmp ne <16 x i8> %av16i8, zeroinitializer
  %av8i16 = and <8 x i16> undef, undef
  %cv8i16 = icmp eq <8 x i16> %av8i16, zeroinitializer
  %av4i32 = and <4 x i32> undef, undef
  %cv4i32 = icmp ne <4 x i32> %av4i32, zeroinitializer

  %c32not0 = icmp eq i32 %a32, 1
  %c64sle = icmp sle i64 %a64, 0
  ret void
}

define void @uscmp() {
; CHECK-THROUGHPUT-LABEL: 'uscmp'
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 4 for instruction: %u8 = call i8 @llvm.ucmp.i8.i8(i8 undef, i8 undef)
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 4 for instruction: %u16 = call i16 @llvm.ucmp.i16.i16(i16 undef, i16 undef)
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 4 for instruction: %u32 = call i32 @llvm.ucmp.i32.i32(i32 undef, i32 undef)
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 4 for instruction: %u64 = call i64 @llvm.ucmp.i64.i64(i64 undef, i64 undef)
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 98 for instruction: %uv16i8 = call <16 x i8> @llvm.ucmp.v16i8.v16i8(<16 x i8> undef, <16 x i8> undef)
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 50 for instruction: %uv8i16 = call <8 x i16> @llvm.ucmp.v8i16.v8i16(<8 x i16> undef, <8 x i16> undef)
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 26 for instruction: %uv4i32 = call <4 x i32> @llvm.ucmp.v4i32.v4i32(<4 x i32> undef, <4 x i32> undef)
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 4 for instruction: %s8 = call i8 @llvm.scmp.i8.i8(i8 undef, i8 undef)
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 4 for instruction: %s16 = call i16 @llvm.scmp.i16.i16(i16 undef, i16 undef)
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 4 for instruction: %s32 = call i32 @llvm.scmp.i32.i32(i32 undef, i32 undef)
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 4 for instruction: %s64 = call i64 @llvm.scmp.i64.i64(i64 undef, i64 undef)
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 98 for instruction: %sv16i8 = call <16 x i8> @llvm.scmp.v16i8.v16i8(<16 x i8> undef, <16 x i8> undef)
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 50 for instruction: %sv8i16 = call <8 x i16> @llvm.scmp.v8i16.v8i16(<8 x i16> undef, <8 x i16> undef)
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 26 for instruction: %sv4i32 = call <4 x i32> @llvm.scmp.v4i32.v4i32(<4 x i32> undef, <4 x i32> undef)
; CHECK-THROUGHPUT-NEXT:  Cost Model: Found an estimated cost of 0 for instruction: ret void
;
; CHECK-SIZE-LABEL: 'uscmp'
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 4 for instruction: %u8 = call i8 @llvm.ucmp.i8.i8(i8 undef, i8 undef)
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 4 for instruction: %u16 = call i16 @llvm.ucmp.i16.i16(i16 undef, i16 undef)
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 4 for instruction: %u32 = call i32 @llvm.ucmp.i32.i32(i32 undef, i32 undef)
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 4 for instruction: %u64 = call i64 @llvm.ucmp.i64.i64(i64 undef, i64 undef)
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 4 for instruction: %uv16i8 = call <16 x i8> @llvm.ucmp.v16i8.v16i8(<16 x i8> undef, <16 x i8> undef)
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 4 for instruction: %uv8i16 = call <8 x i16> @llvm.ucmp.v8i16.v8i16(<8 x i16> undef, <8 x i16> undef)
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 4 for instruction: %uv4i32 = call <4 x i32> @llvm.ucmp.v4i32.v4i32(<4 x i32> undef, <4 x i32> undef)
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 4 for instruction: %s8 = call i8 @llvm.scmp.i8.i8(i8 undef, i8 undef)
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 4 for instruction: %s16 = call i16 @llvm.scmp.i16.i16(i16 undef, i16 undef)
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 4 for instruction: %s32 = call i32 @llvm.scmp.i32.i32(i32 undef, i32 undef)
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 4 for instruction: %s64 = call i64 @llvm.scmp.i64.i64(i64 undef, i64 undef)
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 4 for instruction: %sv16i8 = call <16 x i8> @llvm.scmp.v16i8.v16i8(<16 x i8> undef, <16 x i8> undef)
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 4 for instruction: %sv8i16 = call <8 x i16> @llvm.scmp.v8i16.v8i16(<8 x i16> undef, <8 x i16> undef)
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 4 for instruction: %sv4i32 = call <4 x i32> @llvm.scmp.v4i32.v4i32(<4 x i32> undef, <4 x i32> undef)
; CHECK-SIZE-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: ret void
;
  %u8 = call i8 @llvm.ucmp(i8 undef, i8 undef)
  %u16 = call i16 @llvm.ucmp(i16 undef, i16 undef)
  %u32 = call i32 @llvm.ucmp(i32 undef, i32 undef)
  %u64 = call i64 @llvm.ucmp(i64 undef, i64 undef)
  %uv16i8 = call <16 x i8> @llvm.ucmp(<16 x i8> undef, <16 x i8> undef)
  %uv8i16 = call <8 x i16> @llvm.ucmp(<8 x i16> undef, <8 x i16> undef)
  %uv4i32 = call <4 x i32> @llvm.ucmp(<4 x i32> undef, <4 x i32> undef)
  %s8 = call i8 @llvm.scmp(i8 undef, i8 undef)
  %s16 = call i16 @llvm.scmp(i16 undef, i16 undef)
  %s32 = call i32 @llvm.scmp(i32 undef, i32 undef)
  %s64 = call i64 @llvm.scmp(i64 undef, i64 undef)
  %sv16i8 = call <16 x i8> @llvm.scmp(<16 x i8> undef, <16 x i8> undef)
  %sv8i16 = call <8 x i16> @llvm.scmp(<8 x i16> undef, <8 x i16> undef)
  %sv4i32 = call <4 x i32> @llvm.scmp(<4 x i32> undef, <4 x i32> undef)
  ret void
}
