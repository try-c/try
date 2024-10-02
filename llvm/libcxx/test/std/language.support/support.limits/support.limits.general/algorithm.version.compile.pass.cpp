//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// WARNING: This test was generated by generate_feature_test_macro_components.py
// and should not be edited manually.
//
// clang-format off

// <algorithm>

// Test the feature test macros defined by <algorithm>

/*  Constant                                                Value
    __cpp_lib_clamp                                         201603L [C++17]
    __cpp_lib_constexpr_algorithms                          201806L [C++20]
    __cpp_lib_default_template_type_for_algorithm_values    202403L [C++26]
    __cpp_lib_freestanding_algorithm                        202311L [C++26]
    __cpp_lib_parallel_algorithm                            201603L [C++17]
    __cpp_lib_ranges                                        202110L [C++20]
                                                            202406L [C++23]
    __cpp_lib_ranges_contains                               202207L [C++23]
    __cpp_lib_ranges_find_last                              202207L [C++23]
    __cpp_lib_ranges_starts_ends_with                       202106L [C++23]
    __cpp_lib_robust_nonmodifying_seq_ops                   201304L [C++14]
    __cpp_lib_sample                                        201603L [C++17]
    __cpp_lib_shift                                         201806L [C++20]
*/

#include <algorithm>
#include "test_macros.h"

#if TEST_STD_VER < 14

# ifdef __cpp_lib_clamp
#   error "__cpp_lib_clamp should not be defined before c++17"
# endif

# ifdef __cpp_lib_constexpr_algorithms
#   error "__cpp_lib_constexpr_algorithms should not be defined before c++20"
# endif

# ifdef __cpp_lib_default_template_type_for_algorithm_values
#   error "__cpp_lib_default_template_type_for_algorithm_values should not be defined before c++26"
# endif

# ifdef __cpp_lib_freestanding_algorithm
#   error "__cpp_lib_freestanding_algorithm should not be defined before c++26"
# endif

# ifdef __cpp_lib_parallel_algorithm
#   error "__cpp_lib_parallel_algorithm should not be defined before c++17"
# endif

# ifdef __cpp_lib_ranges
#   error "__cpp_lib_ranges should not be defined before c++20"
# endif

# ifdef __cpp_lib_ranges_contains
#   error "__cpp_lib_ranges_contains should not be defined before c++23"
# endif

# ifdef __cpp_lib_ranges_find_last
#   error "__cpp_lib_ranges_find_last should not be defined before c++23"
# endif

# ifdef __cpp_lib_ranges_starts_ends_with
#   error "__cpp_lib_ranges_starts_ends_with should not be defined before c++23"
# endif

# ifdef __cpp_lib_robust_nonmodifying_seq_ops
#   error "__cpp_lib_robust_nonmodifying_seq_ops should not be defined before c++14"
# endif

# ifdef __cpp_lib_sample
#   error "__cpp_lib_sample should not be defined before c++17"
# endif

# ifdef __cpp_lib_shift
#   error "__cpp_lib_shift should not be defined before c++20"
# endif

#elif TEST_STD_VER == 14

# ifdef __cpp_lib_clamp
#   error "__cpp_lib_clamp should not be defined before c++17"
# endif

# ifdef __cpp_lib_constexpr_algorithms
#   error "__cpp_lib_constexpr_algorithms should not be defined before c++20"
# endif

# ifdef __cpp_lib_default_template_type_for_algorithm_values
#   error "__cpp_lib_default_template_type_for_algorithm_values should not be defined before c++26"
# endif

# ifdef __cpp_lib_freestanding_algorithm
#   error "__cpp_lib_freestanding_algorithm should not be defined before c++26"
# endif

# ifdef __cpp_lib_parallel_algorithm
#   error "__cpp_lib_parallel_algorithm should not be defined before c++17"
# endif

# ifdef __cpp_lib_ranges
#   error "__cpp_lib_ranges should not be defined before c++20"
# endif

# ifdef __cpp_lib_ranges_contains
#   error "__cpp_lib_ranges_contains should not be defined before c++23"
# endif

# ifdef __cpp_lib_ranges_find_last
#   error "__cpp_lib_ranges_find_last should not be defined before c++23"
# endif

# ifdef __cpp_lib_ranges_starts_ends_with
#   error "__cpp_lib_ranges_starts_ends_with should not be defined before c++23"
# endif

# ifndef __cpp_lib_robust_nonmodifying_seq_ops
#   error "__cpp_lib_robust_nonmodifying_seq_ops should be defined in c++14"
# endif
# if __cpp_lib_robust_nonmodifying_seq_ops != 201304L
#   error "__cpp_lib_robust_nonmodifying_seq_ops should have the value 201304L in c++14"
# endif

# ifdef __cpp_lib_sample
#   error "__cpp_lib_sample should not be defined before c++17"
# endif

# ifdef __cpp_lib_shift
#   error "__cpp_lib_shift should not be defined before c++20"
# endif

#elif TEST_STD_VER == 17

# ifndef __cpp_lib_clamp
#   error "__cpp_lib_clamp should be defined in c++17"
# endif
# if __cpp_lib_clamp != 201603L
#   error "__cpp_lib_clamp should have the value 201603L in c++17"
# endif

# ifdef __cpp_lib_constexpr_algorithms
#   error "__cpp_lib_constexpr_algorithms should not be defined before c++20"
# endif

# ifdef __cpp_lib_default_template_type_for_algorithm_values
#   error "__cpp_lib_default_template_type_for_algorithm_values should not be defined before c++26"
# endif

# ifdef __cpp_lib_freestanding_algorithm
#   error "__cpp_lib_freestanding_algorithm should not be defined before c++26"
# endif

# if !defined(_LIBCPP_VERSION)
#   ifndef __cpp_lib_parallel_algorithm
#     error "__cpp_lib_parallel_algorithm should be defined in c++17"
#   endif
#   if __cpp_lib_parallel_algorithm != 201603L
#     error "__cpp_lib_parallel_algorithm should have the value 201603L in c++17"
#   endif
# else // _LIBCPP_VERSION
#   ifdef __cpp_lib_parallel_algorithm
#     error "__cpp_lib_parallel_algorithm should not be defined because it is unimplemented in libc++!"
#   endif
# endif

# ifdef __cpp_lib_ranges
#   error "__cpp_lib_ranges should not be defined before c++20"
# endif

# ifdef __cpp_lib_ranges_contains
#   error "__cpp_lib_ranges_contains should not be defined before c++23"
# endif

# ifdef __cpp_lib_ranges_find_last
#   error "__cpp_lib_ranges_find_last should not be defined before c++23"
# endif

# ifdef __cpp_lib_ranges_starts_ends_with
#   error "__cpp_lib_ranges_starts_ends_with should not be defined before c++23"
# endif

# ifndef __cpp_lib_robust_nonmodifying_seq_ops
#   error "__cpp_lib_robust_nonmodifying_seq_ops should be defined in c++17"
# endif
# if __cpp_lib_robust_nonmodifying_seq_ops != 201304L
#   error "__cpp_lib_robust_nonmodifying_seq_ops should have the value 201304L in c++17"
# endif

# ifndef __cpp_lib_sample
#   error "__cpp_lib_sample should be defined in c++17"
# endif
# if __cpp_lib_sample != 201603L
#   error "__cpp_lib_sample should have the value 201603L in c++17"
# endif

# ifdef __cpp_lib_shift
#   error "__cpp_lib_shift should not be defined before c++20"
# endif

#elif TEST_STD_VER == 20

# ifndef __cpp_lib_clamp
#   error "__cpp_lib_clamp should be defined in c++20"
# endif
# if __cpp_lib_clamp != 201603L
#   error "__cpp_lib_clamp should have the value 201603L in c++20"
# endif

# ifndef __cpp_lib_constexpr_algorithms
#   error "__cpp_lib_constexpr_algorithms should be defined in c++20"
# endif
# if __cpp_lib_constexpr_algorithms != 201806L
#   error "__cpp_lib_constexpr_algorithms should have the value 201806L in c++20"
# endif

# ifdef __cpp_lib_default_template_type_for_algorithm_values
#   error "__cpp_lib_default_template_type_for_algorithm_values should not be defined before c++26"
# endif

# ifdef __cpp_lib_freestanding_algorithm
#   error "__cpp_lib_freestanding_algorithm should not be defined before c++26"
# endif

# if !defined(_LIBCPP_VERSION)
#   ifndef __cpp_lib_parallel_algorithm
#     error "__cpp_lib_parallel_algorithm should be defined in c++20"
#   endif
#   if __cpp_lib_parallel_algorithm != 201603L
#     error "__cpp_lib_parallel_algorithm should have the value 201603L in c++20"
#   endif
# else // _LIBCPP_VERSION
#   ifdef __cpp_lib_parallel_algorithm
#     error "__cpp_lib_parallel_algorithm should not be defined because it is unimplemented in libc++!"
#   endif
# endif

# ifndef __cpp_lib_ranges
#   error "__cpp_lib_ranges should be defined in c++20"
# endif
# if __cpp_lib_ranges != 202110L
#   error "__cpp_lib_ranges should have the value 202110L in c++20"
# endif

# ifdef __cpp_lib_ranges_contains
#   error "__cpp_lib_ranges_contains should not be defined before c++23"
# endif

# ifdef __cpp_lib_ranges_find_last
#   error "__cpp_lib_ranges_find_last should not be defined before c++23"
# endif

# ifdef __cpp_lib_ranges_starts_ends_with
#   error "__cpp_lib_ranges_starts_ends_with should not be defined before c++23"
# endif

# ifndef __cpp_lib_robust_nonmodifying_seq_ops
#   error "__cpp_lib_robust_nonmodifying_seq_ops should be defined in c++20"
# endif
# if __cpp_lib_robust_nonmodifying_seq_ops != 201304L
#   error "__cpp_lib_robust_nonmodifying_seq_ops should have the value 201304L in c++20"
# endif

# ifndef __cpp_lib_sample
#   error "__cpp_lib_sample should be defined in c++20"
# endif
# if __cpp_lib_sample != 201603L
#   error "__cpp_lib_sample should have the value 201603L in c++20"
# endif

# ifndef __cpp_lib_shift
#   error "__cpp_lib_shift should be defined in c++20"
# endif
# if __cpp_lib_shift != 201806L
#   error "__cpp_lib_shift should have the value 201806L in c++20"
# endif

#elif TEST_STD_VER == 23

# ifndef __cpp_lib_clamp
#   error "__cpp_lib_clamp should be defined in c++23"
# endif
# if __cpp_lib_clamp != 201603L
#   error "__cpp_lib_clamp should have the value 201603L in c++23"
# endif

# ifndef __cpp_lib_constexpr_algorithms
#   error "__cpp_lib_constexpr_algorithms should be defined in c++23"
# endif
# if __cpp_lib_constexpr_algorithms != 201806L
#   error "__cpp_lib_constexpr_algorithms should have the value 201806L in c++23"
# endif

# ifdef __cpp_lib_default_template_type_for_algorithm_values
#   error "__cpp_lib_default_template_type_for_algorithm_values should not be defined before c++26"
# endif

# ifdef __cpp_lib_freestanding_algorithm
#   error "__cpp_lib_freestanding_algorithm should not be defined before c++26"
# endif

# if !defined(_LIBCPP_VERSION)
#   ifndef __cpp_lib_parallel_algorithm
#     error "__cpp_lib_parallel_algorithm should be defined in c++23"
#   endif
#   if __cpp_lib_parallel_algorithm != 201603L
#     error "__cpp_lib_parallel_algorithm should have the value 201603L in c++23"
#   endif
# else // _LIBCPP_VERSION
#   ifdef __cpp_lib_parallel_algorithm
#     error "__cpp_lib_parallel_algorithm should not be defined because it is unimplemented in libc++!"
#   endif
# endif

# ifndef __cpp_lib_ranges
#   error "__cpp_lib_ranges should be defined in c++23"
# endif
# if __cpp_lib_ranges != 202406L
#   error "__cpp_lib_ranges should have the value 202406L in c++23"
# endif

# ifndef __cpp_lib_ranges_contains
#   error "__cpp_lib_ranges_contains should be defined in c++23"
# endif
# if __cpp_lib_ranges_contains != 202207L
#   error "__cpp_lib_ranges_contains should have the value 202207L in c++23"
# endif

# ifndef __cpp_lib_ranges_find_last
#   error "__cpp_lib_ranges_find_last should be defined in c++23"
# endif
# if __cpp_lib_ranges_find_last != 202207L
#   error "__cpp_lib_ranges_find_last should have the value 202207L in c++23"
# endif

# ifndef __cpp_lib_ranges_starts_ends_with
#   error "__cpp_lib_ranges_starts_ends_with should be defined in c++23"
# endif
# if __cpp_lib_ranges_starts_ends_with != 202106L
#   error "__cpp_lib_ranges_starts_ends_with should have the value 202106L in c++23"
# endif

# ifndef __cpp_lib_robust_nonmodifying_seq_ops
#   error "__cpp_lib_robust_nonmodifying_seq_ops should be defined in c++23"
# endif
# if __cpp_lib_robust_nonmodifying_seq_ops != 201304L
#   error "__cpp_lib_robust_nonmodifying_seq_ops should have the value 201304L in c++23"
# endif

# ifndef __cpp_lib_sample
#   error "__cpp_lib_sample should be defined in c++23"
# endif
# if __cpp_lib_sample != 201603L
#   error "__cpp_lib_sample should have the value 201603L in c++23"
# endif

# ifndef __cpp_lib_shift
#   error "__cpp_lib_shift should be defined in c++23"
# endif
# if __cpp_lib_shift != 201806L
#   error "__cpp_lib_shift should have the value 201806L in c++23"
# endif

#elif TEST_STD_VER > 23

# ifndef __cpp_lib_clamp
#   error "__cpp_lib_clamp should be defined in c++26"
# endif
# if __cpp_lib_clamp != 201603L
#   error "__cpp_lib_clamp should have the value 201603L in c++26"
# endif

# ifndef __cpp_lib_constexpr_algorithms
#   error "__cpp_lib_constexpr_algorithms should be defined in c++26"
# endif
# if __cpp_lib_constexpr_algorithms != 201806L
#   error "__cpp_lib_constexpr_algorithms should have the value 201806L in c++26"
# endif

# if !defined(_LIBCPP_VERSION)
#   ifndef __cpp_lib_default_template_type_for_algorithm_values
#     error "__cpp_lib_default_template_type_for_algorithm_values should be defined in c++26"
#   endif
#   if __cpp_lib_default_template_type_for_algorithm_values != 202403L
#     error "__cpp_lib_default_template_type_for_algorithm_values should have the value 202403L in c++26"
#   endif
# else // _LIBCPP_VERSION
#   ifdef __cpp_lib_default_template_type_for_algorithm_values
#     error "__cpp_lib_default_template_type_for_algorithm_values should not be defined because it is unimplemented in libc++!"
#   endif
# endif

# if !defined(_LIBCPP_VERSION)
#   ifndef __cpp_lib_freestanding_algorithm
#     error "__cpp_lib_freestanding_algorithm should be defined in c++26"
#   endif
#   if __cpp_lib_freestanding_algorithm != 202311L
#     error "__cpp_lib_freestanding_algorithm should have the value 202311L in c++26"
#   endif
# else // _LIBCPP_VERSION
#   ifdef __cpp_lib_freestanding_algorithm
#     error "__cpp_lib_freestanding_algorithm should not be defined because it is unimplemented in libc++!"
#   endif
# endif

# if !defined(_LIBCPP_VERSION)
#   ifndef __cpp_lib_parallel_algorithm
#     error "__cpp_lib_parallel_algorithm should be defined in c++26"
#   endif
#   if __cpp_lib_parallel_algorithm != 201603L
#     error "__cpp_lib_parallel_algorithm should have the value 201603L in c++26"
#   endif
# else // _LIBCPP_VERSION
#   ifdef __cpp_lib_parallel_algorithm
#     error "__cpp_lib_parallel_algorithm should not be defined because it is unimplemented in libc++!"
#   endif
# endif

# ifndef __cpp_lib_ranges
#   error "__cpp_lib_ranges should be defined in c++26"
# endif
# if __cpp_lib_ranges != 202406L
#   error "__cpp_lib_ranges should have the value 202406L in c++26"
# endif

# ifndef __cpp_lib_ranges_contains
#   error "__cpp_lib_ranges_contains should be defined in c++26"
# endif
# if __cpp_lib_ranges_contains != 202207L
#   error "__cpp_lib_ranges_contains should have the value 202207L in c++26"
# endif

# ifndef __cpp_lib_ranges_find_last
#   error "__cpp_lib_ranges_find_last should be defined in c++26"
# endif
# if __cpp_lib_ranges_find_last != 202207L
#   error "__cpp_lib_ranges_find_last should have the value 202207L in c++26"
# endif

# ifndef __cpp_lib_ranges_starts_ends_with
#   error "__cpp_lib_ranges_starts_ends_with should be defined in c++26"
# endif
# if __cpp_lib_ranges_starts_ends_with != 202106L
#   error "__cpp_lib_ranges_starts_ends_with should have the value 202106L in c++26"
# endif

# ifndef __cpp_lib_robust_nonmodifying_seq_ops
#   error "__cpp_lib_robust_nonmodifying_seq_ops should be defined in c++26"
# endif
# if __cpp_lib_robust_nonmodifying_seq_ops != 201304L
#   error "__cpp_lib_robust_nonmodifying_seq_ops should have the value 201304L in c++26"
# endif

# ifndef __cpp_lib_sample
#   error "__cpp_lib_sample should be defined in c++26"
# endif
# if __cpp_lib_sample != 201603L
#   error "__cpp_lib_sample should have the value 201603L in c++26"
# endif

# ifndef __cpp_lib_shift
#   error "__cpp_lib_shift should be defined in c++26"
# endif
# if __cpp_lib_shift != 201806L
#   error "__cpp_lib_shift should have the value 201806L in c++26"
# endif

#endif // TEST_STD_VER > 23

