! RUN: bbc -emit-hlfir -fopenmp --force-byref-reduction %s -o - | FileCheck %s
! RUN: %flang_fc1 -emit-hlfir -fopenmp -mmlir --force-byref-reduction %s -o - | FileCheck %s

! CHECK-LABEL:   omp.declare_reduction @ior_byref_i32 : !fir.ref<i32>
! CHECK-SAME:    alloc {
! CHECK:            %[[REF:.*]] = fir.alloca i32
! CHECK:            omp.yield(%[[REF]] : !fir.ref<i32>)
! CHECK-LABEL:   } init {
! CHECK:         ^bb0(%[[VAL_0:.*]]: !fir.ref<i32>, %[[ALLOC:.*]]: !fir.ref<i32>):
! CHECK:            %[[C0_1:.*]] = arith.constant 0 : i32
! CHECK:            fir.store %[[C0_1]] to %[[ALLOC]] : !fir.ref<i32>
! CHECK:            omp.yield(%[[ALLOC]] : !fir.ref<i32>)

! CHECK-LABEL:   } combiner {
! CHECK:         ^bb0(%[[ARG0:.*]]: !fir.ref<i32>, %[[ARG1:.*]]: !fir.ref<i32>):
! CHECK:           %[[LD0:.*]] = fir.load %[[ARG0]] : !fir.ref<i32>
! CHECK:           %[[LD1:.*]] = fir.load %[[ARG1]] : !fir.ref<i32>
! CHECK:           %[[RES:.*]] = arith.ori %[[LD0]], %[[LD1]] : i32
! CHECK:           fir.store %[[RES]] to %[[ARG0]] : !fir.ref<i32>
! CHECK:           omp.yield(%[[ARG0]] : !fir.ref<i32>)
! CHECK:         }

! CHECK-LABEL:   func.func @_QPreduction_ior(
! CHECK-SAME:                                %[[VAL_0:.*]]: !fir.box<!fir.array<?xi32>> {fir.bindc_name = "y"}) {
! CHECK:           %[[VAL_1:.*]] = fir.alloca i32 {bindc_name = "i", uniq_name = "_QFreduction_iorEi"}
! CHECK:           %[[VAL_2:.*]]:2 = hlfir.declare %[[VAL_1]] {uniq_name = "_QFreduction_iorEi"} : (!fir.ref<i32>) -> (!fir.ref<i32>, !fir.ref<i32>)
! CHECK:           %[[VAL_3:.*]] = fir.alloca i32 {bindc_name = "x", uniq_name = "_QFreduction_iorEx"}
! CHECK:           %[[VAL_4:.*]]:2 = hlfir.declare %[[VAL_3]] {uniq_name = "_QFreduction_iorEx"} : (!fir.ref<i32>) -> (!fir.ref<i32>, !fir.ref<i32>)
! CHECK:           %[[VAL_5:.*]]:2 = hlfir.declare %[[VAL_0]] dummy_scope %{{[0-9]+}} {uniq_name = "_QFreduction_iorEy"} : (!fir.box<!fir.array<?xi32>>, !fir.dscope) -> (!fir.box<!fir.array<?xi32>>, !fir.box<!fir.array<?xi32>>)
! CHECK:           %[[VAL_6:.*]] = arith.constant 0 : i32
! CHECK:           hlfir.assign %[[VAL_6]] to %[[VAL_4]]#0 : i32, !fir.ref<i32>
! CHECK:           omp.parallel
! CHECK:             %[[VAL_7:.*]] = fir.alloca i32 {bindc_name = "i", pinned, {{.*}}}
! CHECK:             %[[VAL_8:.*]]:2 = hlfir.declare %[[VAL_7]] {uniq_name = "_QFreduction_iorEi"} : (!fir.ref<i32>) -> (!fir.ref<i32>, !fir.ref<i32>)
! CHECK:             %[[VAL_9:.*]] = arith.constant 1 : i32
! CHECK:             %[[VAL_10:.*]] = arith.constant 100 : i32
! CHECK:             %[[VAL_11:.*]] = arith.constant 1 : i32
! CHECK:             omp.wsloop reduction(byref @ior_byref_i32 %[[VAL_4]]#0 -> %[[VAL_12:.*]] : !fir.ref<i32>) {
! CHECK-NEXT:          omp.loop_nest (%[[VAL_13:.*]]) : i32 = (%[[VAL_9]]) to (%[[VAL_10]]) inclusive step (%[[VAL_11]]) {
! CHECK:                 %[[VAL_14:.*]]:2 = hlfir.declare %[[VAL_12]] {uniq_name = "_QFreduction_iorEx"} : (!fir.ref<i32>) -> (!fir.ref<i32>, !fir.ref<i32>)
! CHECK:                 fir.store %[[VAL_13]] to %[[VAL_8]]#1 : !fir.ref<i32>
! CHECK:                 %[[VAL_15:.*]] = fir.load %[[VAL_8]]#0 : !fir.ref<i32>
! CHECK:                 %[[VAL_16:.*]] = fir.convert %[[VAL_15]] : (i32) -> i64
! CHECK:                 %[[VAL_17:.*]] = hlfir.designate %[[VAL_5]]#0 (%[[VAL_16]])  : (!fir.box<!fir.array<?xi32>>, i64) -> !fir.ref<i32>
! CHECK:                 %[[VAL_18:.*]] = fir.load %[[VAL_14]]#0 : !fir.ref<i32>
! CHECK:                 %[[VAL_19:.*]] = fir.load %[[VAL_17]] : !fir.ref<i32>
! CHECK:                 %[[VAL_20:.*]] = arith.ori %[[VAL_18]], %[[VAL_19]] : i32
! CHECK:                 hlfir.assign %[[VAL_20]] to %[[VAL_14]]#0 : i32, !fir.ref<i32>
! CHECK:                 omp.yield
! CHECK:               omp.terminator
! CHECK:             omp.terminator



subroutine reduction_ior(y)
  integer :: x, y(:)
  x = 0
  !$omp parallel
  !$omp do reduction(ior:x)
  do i=1, 100
    x = ior(x, y(i))
  end do
  !$omp end do
  !$omp end parallel
  print *, x
end subroutine
