! RUN: bbc -emit-hlfir -fopenmp --force-byref-reduction -o - %s 2>&1 | FileCheck %s
! RUN: %flang_fc1 -emit-hlfir -fopenmp -mmlir --force-byref-reduction -o - %s 2>&1 | FileCheck %s

! NOTE: Assertions have been autogenerated by utils/generate-test-checks.py

!CHECK-LABEL: omp.declare_reduction @max_byref_f32 : !fir.ref<f32>
!CHECK-SAME: alloc {
!CHECK:   %[[REF:.*]] = fir.alloca f32
!CHECK:   omp.yield(%[[REF]] : !fir.ref<f32>)
!CHECK-LABEL: } init {
!CHECK:   %[[MINIMUM_VAL:.*]] = arith.constant -3.40282347E+38 : f32
!CHECK:   fir.store %[[MINIMUM_VAL]] to %[[ALLOC:.*]] : !fir.ref<f32>
!CHECK:   omp.yield(%[[ALLOC]] : !fir.ref<f32>)
!CHECK: combiner
!CHECK: ^bb0(%[[ARG0:.*]]: !fir.ref<f32>, %[[ARG1:.*]]: !fir.ref<f32>):
!CHECK:   %[[LD0:.*]] = fir.load %[[ARG0]] : !fir.ref<f32>
!CHECK:   %[[LD1:.*]] = fir.load %[[ARG1]] : !fir.ref<f32>
!CHECK:   %[[RES:.*]] = arith.maxnumf %[[LD0]], %[[LD1]] {{.*}}: f32
!CHECK:   fir.store %[[RES]] to %[[ARG0]] : !fir.ref<f32>
!CHECK:   omp.yield(%[[ARG0]] : !fir.ref<f32>)

!CHECK-LABEL: omp.declare_reduction @max_byref_i32 : !fir.ref<i32>
!CHECK-SAME: alloc {
!CHECK:   %[[REF:.*]] = fir.alloca i32
!CHECK:   omp.yield(%[[REF]] : !fir.ref<i32>)
!CHECK-LABEL: } init {
!CHECK:   %[[MINIMUM_VAL:.*]] = arith.constant -2147483648 : i32
!CHECK:   fir.store %[[MINIMUM_VAL]] to %[[ALLOC:.*]] : !fir.ref<i32>
!CHECK:   omp.yield(%[[ALLOC]] : !fir.ref<i32>)
!CHECK: combiner
!CHECK: ^bb0(%[[ARG0:.*]]: !fir.ref<i32>, %[[ARG1:.*]]: !fir.ref<i32>):
!CHECK:   %[[LD0:.*]] = fir.load %[[ARG0]] : !fir.ref<i32>
!CHECK:   %[[LD1:.*]] = fir.load %[[ARG1]] : !fir.ref<i32>
!CHECK:   %[[RES:.*]] = arith.maxsi %[[LD0]], %[[LD1]] : i32
!CHECK:   fir.store %[[RES]] to %[[ARG0]] : !fir.ref<i32>
!CHECK:   omp.yield(%[[ARG0]] : !fir.ref<i32>)

! CHECK-LABEL:   func.func @_QPreduction_max_int(
! CHECK-SAME:                                    %[[VAL_0:.*]]: !fir.box<!fir.array<?xi32>> {fir.bindc_name = "y"}) {
! CHECK:           %[[VAL_1:.*]] = fir.alloca i32 {bindc_name = "i", uniq_name = "_QFreduction_max_intEi"}
! CHECK:           %[[VAL_2:.*]]:2 = hlfir.declare %[[VAL_1]] {uniq_name = "_QFreduction_max_intEi"} : (!fir.ref<i32>) -> (!fir.ref<i32>, !fir.ref<i32>)
! CHECK:           %[[VAL_3:.*]] = fir.alloca i32 {bindc_name = "x", uniq_name = "_QFreduction_max_intEx"}
! CHECK:           %[[VAL_4:.*]]:2 = hlfir.declare %[[VAL_3]] {uniq_name = "_QFreduction_max_intEx"} : (!fir.ref<i32>) -> (!fir.ref<i32>, !fir.ref<i32>)
! CHECK:           %[[VAL_5:.*]]:2 = hlfir.declare %[[VAL_0]] dummy_scope %{{[0-9]+}} {uniq_name = "_QFreduction_max_intEy"} : (!fir.box<!fir.array<?xi32>>, !fir.dscope) -> (!fir.box<!fir.array<?xi32>>, !fir.box<!fir.array<?xi32>>)
! CHECK:           %[[VAL_6:.*]] = arith.constant 0 : i32
! CHECK:           hlfir.assign %[[VAL_6]] to %[[VAL_4]]#0 : i32, !fir.ref<i32>
! CHECK:           omp.parallel {
! CHECK:             %[[VAL_7:.*]] = fir.alloca i32 {bindc_name = "i", pinned, {{.*}}}
! CHECK:             %[[VAL_8:.*]]:2 = hlfir.declare %[[VAL_7]] {uniq_name = "_QFreduction_max_intEi"} : (!fir.ref<i32>) -> (!fir.ref<i32>, !fir.ref<i32>)
! CHECK:             %[[VAL_9:.*]] = arith.constant 1 : i32
! CHECK:             %[[VAL_10:.*]] = arith.constant 100 : i32
! CHECK:             %[[VAL_11:.*]] = arith.constant 1 : i32
! CHECK:             omp.wsloop reduction(byref @max_byref_i32 %[[VAL_4]]#0 -> %[[VAL_12:.*]] : !fir.ref<i32>) {
! CHECK-NEXT:          omp.loop_nest (%[[VAL_13:.*]]) : i32 = (%[[VAL_9]]) to (%[[VAL_10]]) inclusive step (%[[VAL_11]]) {
! CHECK:                 %[[VAL_14:.*]]:2 = hlfir.declare %[[VAL_12]] {uniq_name = "_QFreduction_max_intEx"} : (!fir.ref<i32>) -> (!fir.ref<i32>, !fir.ref<i32>)
! CHECK:                 fir.store %[[VAL_13]] to %[[VAL_8]]#1 : !fir.ref<i32>
! CHECK:                 %[[VAL_15:.*]] = fir.load %[[VAL_8]]#0 : !fir.ref<i32>
! CHECK:                 %[[VAL_16:.*]] = fir.convert %[[VAL_15]] : (i32) -> i64
! CHECK:                 %[[VAL_17:.*]] = hlfir.designate %[[VAL_5]]#0 (%[[VAL_16]])  : (!fir.box<!fir.array<?xi32>>, i64) -> !fir.ref<i32>
! CHECK:                 %[[VAL_18:.*]] = fir.load %[[VAL_14]]#0 : !fir.ref<i32>
! CHECK:                 %[[VAL_19:.*]] = fir.load %[[VAL_17]] : !fir.ref<i32>
! CHECK:                 %[[VAL_20:.*]] = arith.cmpi sgt, %[[VAL_18]], %[[VAL_19]] : i32
! CHECK:                 %[[VAL_21:.*]] = arith.select %[[VAL_20]], %[[VAL_18]], %[[VAL_19]] : i32
! CHECK:                 hlfir.assign %[[VAL_21]] to %[[VAL_14]]#0 : i32, !fir.ref<i32>
! CHECK:                 omp.yield
! CHECK:               omp.terminator
! CHECK:             omp.terminator

! CHECK-LABEL:   func.func @_QPreduction_max_real(
! CHECK-SAME:                                     %[[VAL_0:.*]]: !fir.box<!fir.array<?xf32>> {fir.bindc_name = "y"}) {
! CHECK:           %[[VAL_1:.*]] = fir.alloca i32 {bindc_name = "i", uniq_name = "_QFreduction_max_realEi"}
! CHECK:           %[[VAL_2:.*]]:2 = hlfir.declare %[[VAL_1]] {uniq_name = "_QFreduction_max_realEi"} : (!fir.ref<i32>) -> (!fir.ref<i32>, !fir.ref<i32>)
! CHECK:           %[[VAL_3:.*]] = fir.alloca f32 {bindc_name = "x", uniq_name = "_QFreduction_max_realEx"}
! CHECK:           %[[VAL_4:.*]]:2 = hlfir.declare %[[VAL_3]] {uniq_name = "_QFreduction_max_realEx"} : (!fir.ref<f32>) -> (!fir.ref<f32>, !fir.ref<f32>)
! CHECK:           %[[VAL_5:.*]]:2 = hlfir.declare %[[VAL_0]] dummy_scope %{{[0-9]+}} {uniq_name = "_QFreduction_max_realEy"} : (!fir.box<!fir.array<?xf32>>, !fir.dscope) -> (!fir.box<!fir.array<?xf32>>, !fir.box<!fir.array<?xf32>>)
! CHECK:           %[[VAL_6:.*]] = arith.constant 0.000000e+00 : f32
! CHECK:           hlfir.assign %[[VAL_6]] to %[[VAL_4]]#0 : f32, !fir.ref<f32>
! CHECK:           omp.parallel {
! CHECK:             %[[VAL_7:.*]] = fir.alloca i32 {bindc_name = "i", pinned, {{.*}}}
! CHECK:             %[[VAL_8:.*]]:2 = hlfir.declare %[[VAL_7]] {uniq_name = "_QFreduction_max_realEi"} : (!fir.ref<i32>) -> (!fir.ref<i32>, !fir.ref<i32>)
! CHECK:             %[[VAL_9:.*]] = arith.constant 1 : i32
! CHECK:             %[[VAL_10:.*]] = arith.constant 100 : i32
! CHECK:             %[[VAL_11:.*]] = arith.constant 1 : i32
! CHECK:             omp.wsloop reduction(byref @max_byref_f32 %[[VAL_4]]#0 -> %[[VAL_12:.*]] : !fir.ref<f32>) {
! CHECK-NEXT:          omp.loop_nest (%[[VAL_13:.*]]) : i32 = (%[[VAL_9]]) to (%[[VAL_10]]) inclusive step (%[[VAL_11]]) {
! CHECK:                 %[[VAL_14:.*]]:2 = hlfir.declare %[[VAL_12]] {uniq_name = "_QFreduction_max_realEx"} : (!fir.ref<f32>) -> (!fir.ref<f32>, !fir.ref<f32>)
! CHECK:                 fir.store %[[VAL_13]] to %[[VAL_8]]#1 : !fir.ref<i32>
! CHECK:                 %[[VAL_15:.*]] = fir.load %[[VAL_8]]#0 : !fir.ref<i32>
! CHECK:                 %[[VAL_16:.*]] = fir.convert %[[VAL_15]] : (i32) -> i64
! CHECK:                 %[[VAL_17:.*]] = hlfir.designate %[[VAL_5]]#0 (%[[VAL_16]])  : (!fir.box<!fir.array<?xf32>>, i64) -> !fir.ref<f32>
! CHECK:                 %[[VAL_18:.*]] = fir.load %[[VAL_17]] : !fir.ref<f32>
! CHECK:                 %[[VAL_19:.*]] = fir.load %[[VAL_14]]#0 : !fir.ref<f32>
! CHECK:                 %[[VAL_20:.*]] = arith.cmpf ogt, %[[VAL_18]], %[[VAL_19]] fastmath<contract> : f32
! CHECK:                 %[[VAL_21:.*]] = arith.select %[[VAL_20]], %[[VAL_18]], %[[VAL_19]] : f32
! CHECK:                 hlfir.assign %[[VAL_21]] to %[[VAL_14]]#0 : f32, !fir.ref<f32>
! CHECK:                 omp.yield
! CHECK:               omp.terminator
! CHECK:             omp.terminator
! CHECK:           omp.parallel {
! CHECK:             %[[VAL_30:.*]] = fir.alloca i32 {bindc_name = "i", pinned, {{.*}}}
! CHECK:             %[[VAL_31:.*]]:2 = hlfir.declare %[[VAL_30]] {uniq_name = "_QFreduction_max_realEi"} : (!fir.ref<i32>) -> (!fir.ref<i32>, !fir.ref<i32>)
! CHECK:             %[[VAL_32:.*]] = arith.constant 1 : i32
! CHECK:             %[[VAL_33:.*]] = arith.constant 100 : i32
! CHECK:             %[[VAL_34:.*]] = arith.constant 1 : i32
! CHECK:             omp.wsloop reduction(byref @max_byref_f32 %[[VAL_4]]#0 -> %[[VAL_35:.*]] : !fir.ref<f32>) {
! CHECK-NEXT:          omp.loop_nest (%[[VAL_36:.*]]) : i32 = (%[[VAL_32]]) to (%[[VAL_33]]) inclusive step (%[[VAL_34]]) {
! CHECK:                 %[[VAL_37:.*]]:2 = hlfir.declare %[[VAL_35]] {uniq_name = "_QFreduction_max_realEx"} : (!fir.ref<f32>) -> (!fir.ref<f32>, !fir.ref<f32>)
! CHECK:                 fir.store %[[VAL_36]] to %[[VAL_31]]#1 : !fir.ref<i32>
! CHECK:                 %[[VAL_38:.*]] = fir.load %[[VAL_31]]#0 : !fir.ref<i32>
! CHECK:                 %[[VAL_39:.*]] = fir.convert %[[VAL_38]] : (i32) -> i64
! CHECK:                 %[[VAL_40:.*]] = hlfir.designate %[[VAL_5]]#0 (%[[VAL_39]])  : (!fir.box<!fir.array<?xf32>>, i64) -> !fir.ref<f32>
! CHECK:                 %[[VAL_41:.*]] = fir.load %[[VAL_40]] : !fir.ref<f32>
! CHECK:                 %[[VAL_42:.*]] = fir.load %[[VAL_37]]#0 : !fir.ref<f32>
! CHECK:                 %[[VAL_43:.*]] = arith.cmpf ogt, %[[VAL_41]], %[[VAL_42]] fastmath<contract> : f32
! CHECK:                 fir.if %[[VAL_43]] {
! CHECK:                   %[[VAL_44:.*]] = fir.load %[[VAL_31]]#0 : !fir.ref<i32>
! CHECK:                   %[[VAL_45:.*]] = fir.convert %[[VAL_44]] : (i32) -> i64
! CHECK:                   %[[VAL_46:.*]] = hlfir.designate %[[VAL_5]]#0 (%[[VAL_45]])  : (!fir.box<!fir.array<?xf32>>, i64) -> !fir.ref<f32>
! CHECK:                   %[[VAL_47:.*]] = fir.load %[[VAL_46]] : !fir.ref<f32>
! CHECK:                   hlfir.assign %[[VAL_47]] to %[[VAL_37]]#0 : f32, !fir.ref<f32>
! CHECK:                 }
! CHECK:                 omp.yield
! CHECK:               omp.terminator
! CHECK:             omp.terminator



subroutine reduction_max_int(y)
  integer :: x, y(:)
  x = 0
  !$omp parallel
  !$omp do reduction(max:x)
  do i=1, 100
    x = max(x, y(i))
  end do
  !$omp end do
  !$omp end parallel
  print *, x
end subroutine

subroutine reduction_max_real(y)
  real :: x, y(:)
  x = 0.0
  !$omp parallel
  !$omp do reduction(max:x)
  do i=1, 100
    x = max(y(i), x)
  end do
  !$omp end do
  !$omp end parallel
  print *, x

  !$omp parallel
  !$omp do reduction(max:x)
  do i=1, 100
    if (y(i) .gt. x) x = y(i)
  end do
  !$omp end do
  !$omp end parallel
  print *, x
end subroutine
