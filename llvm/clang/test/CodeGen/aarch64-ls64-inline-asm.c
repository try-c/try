// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// RUN: %clang_cc1 -triple aarch64 -target-feature +ls64 -O1 -emit-llvm -x c %s -o - | FileCheck %s

struct foo { unsigned long long x[8]; };

// CHECK-LABEL: @load(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call i512 asm sideeffect "ld64b $0,[$1]", "=r,r,~{memory}"(ptr [[ADDR:%.*]]) #[[ATTR1:[0-9]+]], !srcloc !2
// CHECK-NEXT:    store i512 [[TMP0]], ptr [[OUTPUT:%.*]], align 8
// CHECK-NEXT:    ret void
//
void load(struct foo *output, void *addr)
{
    __asm__ volatile ("ld64b %0,[%1]" : "=r" (*output) : "r" (addr) : "memory");
}

// CHECK-LABEL: @store(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = load i512, ptr [[INPUT:%.*]], align 8
// CHECK-NEXT:    tail call void asm sideeffect "st64b $0,[$1]", "r,r,~{memory}"(i512 [[TMP0]], ptr [[ADDR:%.*]]) #[[ATTR1]], !srcloc !3
// CHECK-NEXT:    ret void
//
void store(const struct foo *input, void *addr)
{
    __asm__ volatile ("st64b %0,[%1]" : : "r" (*input), "r" (addr) : "memory" );
}

// CHECK-LABEL: @store2(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = load i32, ptr [[IN:%.*]], align 4, !tbaa [[TBAA4:![0-9]+]]
// CHECK-NEXT:    [[CONV:%.*]] = sext i32 [[TMP0]] to i64
// CHECK-NEXT:    [[ARRAYIDX1:%.*]] = getelementptr inbounds i8, ptr [[IN]], i64 4
// CHECK-NEXT:    [[TMP1:%.*]] = load i32, ptr [[ARRAYIDX1]], align 4, !tbaa [[TBAA4]]
// CHECK-NEXT:    [[CONV2:%.*]] = sext i32 [[TMP1]] to i64
// CHECK-NEXT:    [[ARRAYIDX4:%.*]] = getelementptr inbounds i8, ptr [[IN]], i64 16
// CHECK-NEXT:    [[TMP2:%.*]] = load i32, ptr [[ARRAYIDX4]], align 4, !tbaa [[TBAA4]]
// CHECK-NEXT:    [[CONV5:%.*]] = sext i32 [[TMP2]] to i64
// CHECK-NEXT:    [[ARRAYIDX7:%.*]] = getelementptr inbounds i8, ptr [[IN]], i64 64
// CHECK-NEXT:    [[TMP3:%.*]] = load i32, ptr [[ARRAYIDX7]], align 4, !tbaa [[TBAA4]]
// CHECK-NEXT:    [[CONV8:%.*]] = sext i32 [[TMP3]] to i64
// CHECK-NEXT:    [[ARRAYIDX10:%.*]] = getelementptr inbounds i8, ptr [[IN]], i64 100
// CHECK-NEXT:    [[TMP4:%.*]] = load i32, ptr [[ARRAYIDX10]], align 4, !tbaa [[TBAA4]]
// CHECK-NEXT:    [[CONV11:%.*]] = sext i32 [[TMP4]] to i64
// CHECK-NEXT:    [[ARRAYIDX13:%.*]] = getelementptr inbounds i8, ptr [[IN]], i64 144
// CHECK-NEXT:    [[TMP5:%.*]] = load i32, ptr [[ARRAYIDX13]], align 4, !tbaa [[TBAA4]]
// CHECK-NEXT:    [[CONV14:%.*]] = sext i32 [[TMP5]] to i64
// CHECK-NEXT:    [[ARRAYIDX16:%.*]] = getelementptr inbounds i8, ptr [[IN]], i64 196
// CHECK-NEXT:    [[TMP6:%.*]] = load i32, ptr [[ARRAYIDX16]], align 4, !tbaa [[TBAA4]]
// CHECK-NEXT:    [[CONV17:%.*]] = sext i32 [[TMP6]] to i64
// CHECK-NEXT:    [[ARRAYIDX19:%.*]] = getelementptr inbounds i8, ptr [[IN]], i64 256
// CHECK-NEXT:    [[TMP7:%.*]] = load i32, ptr [[ARRAYIDX19]], align 4, !tbaa [[TBAA4]]
// CHECK-NEXT:    [[CONV20:%.*]] = sext i32 [[TMP7]] to i64
// CHECK-NEXT:    [[S_SROA_10_0_INSERT_EXT:%.*]] = zext i64 [[CONV20]] to i512
// CHECK-NEXT:    [[S_SROA_10_0_INSERT_SHIFT:%.*]] = shl nuw i512 [[S_SROA_10_0_INSERT_EXT]], 448
// CHECK-NEXT:    [[S_SROA_9_0_INSERT_EXT:%.*]] = zext i64 [[CONV17]] to i512
// CHECK-NEXT:    [[S_SROA_9_0_INSERT_SHIFT:%.*]] = shl nuw nsw i512 [[S_SROA_9_0_INSERT_EXT]], 384
// CHECK-NEXT:    [[S_SROA_9_0_INSERT_INSERT:%.*]] = or disjoint i512 [[S_SROA_10_0_INSERT_SHIFT]], [[S_SROA_9_0_INSERT_SHIFT]]
// CHECK-NEXT:    [[S_SROA_8_0_INSERT_EXT:%.*]] = zext i64 [[CONV14]] to i512
// CHECK-NEXT:    [[S_SROA_8_0_INSERT_SHIFT:%.*]] = shl nuw nsw i512 [[S_SROA_8_0_INSERT_EXT]], 320
// CHECK-NEXT:    [[S_SROA_8_0_INSERT_INSERT:%.*]] = or disjoint i512 [[S_SROA_9_0_INSERT_INSERT]], [[S_SROA_8_0_INSERT_SHIFT]]
// CHECK-NEXT:    [[S_SROA_7_0_INSERT_EXT:%.*]] = zext i64 [[CONV11]] to i512
// CHECK-NEXT:    [[S_SROA_7_0_INSERT_SHIFT:%.*]] = shl nuw nsw i512 [[S_SROA_7_0_INSERT_EXT]], 256
// CHECK-NEXT:    [[S_SROA_7_0_INSERT_INSERT:%.*]] = or disjoint i512 [[S_SROA_8_0_INSERT_INSERT]], [[S_SROA_7_0_INSERT_SHIFT]]
// CHECK-NEXT:    [[S_SROA_6_0_INSERT_EXT:%.*]] = zext i64 [[CONV8]] to i512
// CHECK-NEXT:    [[S_SROA_6_0_INSERT_SHIFT:%.*]] = shl nuw nsw i512 [[S_SROA_6_0_INSERT_EXT]], 192
// CHECK-NEXT:    [[S_SROA_6_0_INSERT_INSERT:%.*]] = or disjoint i512 [[S_SROA_7_0_INSERT_INSERT]], [[S_SROA_6_0_INSERT_SHIFT]]
// CHECK-NEXT:    [[S_SROA_5_0_INSERT_EXT:%.*]] = zext i64 [[CONV5]] to i512
// CHECK-NEXT:    [[S_SROA_5_0_INSERT_SHIFT:%.*]] = shl nuw nsw i512 [[S_SROA_5_0_INSERT_EXT]], 128
// CHECK-NEXT:    [[S_SROA_4_0_INSERT_EXT:%.*]] = zext i64 [[CONV2]] to i512
// CHECK-NEXT:    [[S_SROA_4_0_INSERT_SHIFT:%.*]] = shl nuw nsw i512 [[S_SROA_4_0_INSERT_EXT]], 64
// CHECK-NEXT:    [[S_SROA_4_0_INSERT_MASK:%.*]] = or disjoint i512 [[S_SROA_6_0_INSERT_INSERT]], [[S_SROA_5_0_INSERT_SHIFT]]
// CHECK-NEXT:    [[S_SROA_0_0_INSERT_EXT:%.*]] = zext i64 [[CONV]] to i512
// CHECK-NEXT:    [[S_SROA_0_0_INSERT_MASK:%.*]] = or disjoint i512 [[S_SROA_4_0_INSERT_MASK]], [[S_SROA_4_0_INSERT_SHIFT]]
// CHECK-NEXT:    [[S_SROA_0_0_INSERT_INSERT:%.*]] = or i512 [[S_SROA_0_0_INSERT_MASK]], [[S_SROA_0_0_INSERT_EXT]]
// CHECK-NEXT:    tail call void asm sideeffect "st64b $0,[$1]", "r,r,~{memory}"(i512 [[S_SROA_0_0_INSERT_INSERT]], ptr [[ADDR:%.*]]) #[[ATTR1]], !srcloc !8
// CHECK-NEXT:    ret void
//
void store2(int *in, void *addr)
{
    struct foo s = { in[0], in[1], in[4], in[16], in[25], in[36], in[49], in[64] };
    __asm__ volatile ("st64b %0,[%1]" : : "r" (s), "r" (addr) : "memory" );
}
