//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// UNSUPPORTED: c++03, c++11, c++14
// TODO: Change to XFAIL once https://github.com/llvm/llvm-project/issues/40340 is fixed
// UNSUPPORTED: availability-pmr-missing

// <memory_resource>

// template <class T> class polymorphic_allocator

// friend bool operator==(const polymorphic_allocator& a,
//                        const polymorphic_allocator& b) noexcept

#include <memory_resource>
#include <cassert>
#include <vector>

#include "test_macros.h"

int main(int, char**) {
  std::pmr::unsynchronized_pool_resource a;
  std::pmr::vector<int> vec(&a);

  assert(vec.get_allocator() == &a);
  static_assert(noexcept(vec.get_allocator() == &a));

  // LWG3683 added operator== after C++20. In C++20 operator!= is generated by
  // the compiler. Libc++ adds operator!= in C++17 as an extension. MSVC STL
  // and libstdc++ have done the same so test this extension unconditionally.
  std::pmr::unsynchronized_pool_resource b;

  assert(vec.get_allocator() != &b);
  static_assert(noexcept(vec.get_allocator() != &b));

  return 0;
}
