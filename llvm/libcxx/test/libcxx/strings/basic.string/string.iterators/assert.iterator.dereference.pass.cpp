//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <string>

// Dereference non-dereferenceable iterator.

// REQUIRES: has-unix-headers, libcpp-has-abi-bounded-iterators-in-string
// UNSUPPORTED: libcpp-hardening-mode=none, c++03

#include <string>

#include "check_assertion.h"
#include "min_allocator.h"

template <class C>
void test() {
  C c(1, '\0');
  typename C::iterator i = c.end();
  TEST_LIBCPP_ASSERT_FAILURE(*i, "__bounded_iter::operator*: Attempt to dereference an iterator at the end");
}

int main(int, char**) {
  test<std::string>();
  test<std::basic_string<char, std::char_traits<char>, min_allocator<char> > >();

  return 0;
}
