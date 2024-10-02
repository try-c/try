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

// UNSUPPORTED: no-filesystem

// <filesystem>

// Test the feature test macros defined by <filesystem>

/*  Constant                 Value
    __cpp_lib_char8_t        201907L [C++20]
    __cpp_lib_filesystem     201703L [C++17]
    __cpp_lib_format_path    202403L [C++26]
*/

#include <filesystem>
#include "test_macros.h"

#if TEST_STD_VER < 14

# ifdef __cpp_lib_char8_t
#   error "__cpp_lib_char8_t should not be defined before c++20"
# endif

# ifdef __cpp_lib_filesystem
#   error "__cpp_lib_filesystem should not be defined before c++17"
# endif

# ifdef __cpp_lib_format_path
#   error "__cpp_lib_format_path should not be defined before c++26"
# endif

#elif TEST_STD_VER == 14

# ifdef __cpp_lib_char8_t
#   error "__cpp_lib_char8_t should not be defined before c++20"
# endif

# ifdef __cpp_lib_filesystem
#   error "__cpp_lib_filesystem should not be defined before c++17"
# endif

# ifdef __cpp_lib_format_path
#   error "__cpp_lib_format_path should not be defined before c++26"
# endif

#elif TEST_STD_VER == 17

# ifdef __cpp_lib_char8_t
#   error "__cpp_lib_char8_t should not be defined before c++20"
# endif

# if !defined(_LIBCPP_VERSION) || (!defined(_LIBCPP_HAS_NO_FILESYSTEM) && _LIBCPP_AVAILABILITY_HAS_FILESYSTEM_LIBRARY)
#   ifndef __cpp_lib_filesystem
#     error "__cpp_lib_filesystem should be defined in c++17"
#   endif
#   if __cpp_lib_filesystem != 201703L
#     error "__cpp_lib_filesystem should have the value 201703L in c++17"
#   endif
# else
#   ifdef __cpp_lib_filesystem
#     error "__cpp_lib_filesystem should not be defined when the requirement '!defined(_LIBCPP_VERSION) || (!defined(_LIBCPP_HAS_NO_FILESYSTEM) && _LIBCPP_AVAILABILITY_HAS_FILESYSTEM_LIBRARY)' is not met!"
#   endif
# endif

# ifdef __cpp_lib_format_path
#   error "__cpp_lib_format_path should not be defined before c++26"
# endif

#elif TEST_STD_VER == 20

# if defined(__cpp_char8_t)
#   ifndef __cpp_lib_char8_t
#     error "__cpp_lib_char8_t should be defined in c++20"
#   endif
#   if __cpp_lib_char8_t != 201907L
#     error "__cpp_lib_char8_t should have the value 201907L in c++20"
#   endif
# else
#   ifdef __cpp_lib_char8_t
#     error "__cpp_lib_char8_t should not be defined when the requirement 'defined(__cpp_char8_t)' is not met!"
#   endif
# endif

# if !defined(_LIBCPP_VERSION) || (!defined(_LIBCPP_HAS_NO_FILESYSTEM) && _LIBCPP_AVAILABILITY_HAS_FILESYSTEM_LIBRARY)
#   ifndef __cpp_lib_filesystem
#     error "__cpp_lib_filesystem should be defined in c++20"
#   endif
#   if __cpp_lib_filesystem != 201703L
#     error "__cpp_lib_filesystem should have the value 201703L in c++20"
#   endif
# else
#   ifdef __cpp_lib_filesystem
#     error "__cpp_lib_filesystem should not be defined when the requirement '!defined(_LIBCPP_VERSION) || (!defined(_LIBCPP_HAS_NO_FILESYSTEM) && _LIBCPP_AVAILABILITY_HAS_FILESYSTEM_LIBRARY)' is not met!"
#   endif
# endif

# ifdef __cpp_lib_format_path
#   error "__cpp_lib_format_path should not be defined before c++26"
# endif

#elif TEST_STD_VER == 23

# if defined(__cpp_char8_t)
#   ifndef __cpp_lib_char8_t
#     error "__cpp_lib_char8_t should be defined in c++23"
#   endif
#   if __cpp_lib_char8_t != 201907L
#     error "__cpp_lib_char8_t should have the value 201907L in c++23"
#   endif
# else
#   ifdef __cpp_lib_char8_t
#     error "__cpp_lib_char8_t should not be defined when the requirement 'defined(__cpp_char8_t)' is not met!"
#   endif
# endif

# if !defined(_LIBCPP_VERSION) || (!defined(_LIBCPP_HAS_NO_FILESYSTEM) && _LIBCPP_AVAILABILITY_HAS_FILESYSTEM_LIBRARY)
#   ifndef __cpp_lib_filesystem
#     error "__cpp_lib_filesystem should be defined in c++23"
#   endif
#   if __cpp_lib_filesystem != 201703L
#     error "__cpp_lib_filesystem should have the value 201703L in c++23"
#   endif
# else
#   ifdef __cpp_lib_filesystem
#     error "__cpp_lib_filesystem should not be defined when the requirement '!defined(_LIBCPP_VERSION) || (!defined(_LIBCPP_HAS_NO_FILESYSTEM) && _LIBCPP_AVAILABILITY_HAS_FILESYSTEM_LIBRARY)' is not met!"
#   endif
# endif

# ifdef __cpp_lib_format_path
#   error "__cpp_lib_format_path should not be defined before c++26"
# endif

#elif TEST_STD_VER > 23

# if defined(__cpp_char8_t)
#   ifndef __cpp_lib_char8_t
#     error "__cpp_lib_char8_t should be defined in c++26"
#   endif
#   if __cpp_lib_char8_t != 201907L
#     error "__cpp_lib_char8_t should have the value 201907L in c++26"
#   endif
# else
#   ifdef __cpp_lib_char8_t
#     error "__cpp_lib_char8_t should not be defined when the requirement 'defined(__cpp_char8_t)' is not met!"
#   endif
# endif

# if !defined(_LIBCPP_VERSION) || (!defined(_LIBCPP_HAS_NO_FILESYSTEM) && _LIBCPP_AVAILABILITY_HAS_FILESYSTEM_LIBRARY)
#   ifndef __cpp_lib_filesystem
#     error "__cpp_lib_filesystem should be defined in c++26"
#   endif
#   if __cpp_lib_filesystem != 201703L
#     error "__cpp_lib_filesystem should have the value 201703L in c++26"
#   endif
# else
#   ifdef __cpp_lib_filesystem
#     error "__cpp_lib_filesystem should not be defined when the requirement '!defined(_LIBCPP_VERSION) || (!defined(_LIBCPP_HAS_NO_FILESYSTEM) && _LIBCPP_AVAILABILITY_HAS_FILESYSTEM_LIBRARY)' is not met!"
#   endif
# endif

# if !defined(_LIBCPP_VERSION)
#   ifndef __cpp_lib_format_path
#     error "__cpp_lib_format_path should be defined in c++26"
#   endif
#   if __cpp_lib_format_path != 202403L
#     error "__cpp_lib_format_path should have the value 202403L in c++26"
#   endif
# else // _LIBCPP_VERSION
#   ifdef __cpp_lib_format_path
#     error "__cpp_lib_format_path should not be defined because it is unimplemented in libc++!"
#   endif
# endif

#endif // TEST_STD_VER > 23

