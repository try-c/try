//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <memory>

// template<class Y, class D, class A> shared_ptr(Y* p, D d, A a);

#include <memory>
#include <cassert>
#include "test_macros.h"
#include "deleter_types.h"
#include "test_allocator.h"
#include "min_allocator.h"

#include "types.h"
struct A
{
    static int count;

    A() {++count;}
    A(const A&) {++count;}
    ~A() {--count;}
};

int A::count = 0;

// LWG 3233. Broken requirements for shared_ptr converting constructors
// https://cplusplus.github.io/LWG/issue3233
// https://llvm.org/PR60258
// Invalid constructor SFINAE for std::shared_ptr's array ctors
static_assert( std::is_constructible<std::shared_ptr<int>,  int*, test_deleter<int>, test_allocator<int> >::value, "");
static_assert(!std::is_constructible<std::shared_ptr<int>,  int*, bad_deleter, test_allocator<int> >::value, "");
static_assert( std::is_constructible<std::shared_ptr<base>,  derived*, test_deleter<base>, test_allocator<base> >::value, "");
static_assert(!std::is_constructible<std::shared_ptr<A>,  int*, test_deleter<A>, test_allocator<A> >::value, "");

#if TEST_STD_VER >= 17
static_assert( std::is_constructible<std::shared_ptr<int[]>,  int*, test_deleter<int>, test_allocator<int> >::value, "");
static_assert(!std::is_constructible<std::shared_ptr<int[]>,  int*, bad_deleter, test_allocator<int> >::value, "");
static_assert(!std::is_constructible<std::shared_ptr<int[]>,  int(*)[], test_deleter<int>, test_allocator<int> >::value, "");
static_assert( std::is_constructible<std::shared_ptr<int[5]>, int*, test_deleter<int>, test_allocator<int> >::value, "");
static_assert(!std::is_constructible<std::shared_ptr<int[5]>, int*, bad_deleter, test_allocator<int> >::value, "");
static_assert(!std::is_constructible<std::shared_ptr<int[5]>, int(*)[5], test_deleter<int>, test_allocator<int> >::value, "");
#endif


int main(int, char**)
{
    {
        test_allocator_statistics alloc_stats;
        {
            A* ptr = new A;
            std::shared_ptr<A> p(ptr, test_deleter<A>(3), test_allocator<A>(5, &alloc_stats));
            assert(A::count == 1);
            assert(p.use_count() == 1);
            assert(p.get() == ptr);
            assert(test_deleter<A>::count == 1);
            assert(test_deleter<A>::dealloc_count == 0);
#ifndef TEST_HAS_NO_RTTI
            test_deleter<A>* d = std::get_deleter<test_deleter<A> >(p);
            assert(d);
            assert(d->state() == 3);
#endif
            assert(alloc_stats.count == 1);
            assert(alloc_stats.alloc_count == 1);
        }
        assert(A::count == 0);
        assert(test_deleter<A>::count == 0);
        assert(test_deleter<A>::dealloc_count == 1);
        assert(alloc_stats.count == 0);
        assert(alloc_stats.alloc_count == 0);
        test_deleter<A>::dealloc_count = 0;
    }

    {
        test_allocator_statistics alloc_stats;
        {
            A const* ptr = new A;
            std::shared_ptr<A const> p(ptr, test_deleter<A const>(3), test_allocator<A>(5, &alloc_stats));
            assert(A::count == 1);
            assert(p.use_count() == 1);
            assert(p.get() == ptr);
            assert(test_deleter<A const>::count == 1);
            assert(test_deleter<A const>::dealloc_count == 0);
#ifndef TEST_HAS_NO_RTTI
            test_deleter<A const>* d = std::get_deleter<test_deleter<A const> >(p);
            assert(d);
            assert(d->state() == 3);
#endif
            assert(alloc_stats.count == 1);
            assert(alloc_stats.alloc_count == 1);
        }
        assert(A::count == 0);
        assert(test_deleter<A const>::count == 0);
        assert(test_deleter<A const>::dealloc_count == 1);
        assert(alloc_stats.count == 0);
        assert(alloc_stats.alloc_count == 0);
        test_deleter<A const>::dealloc_count = 0;
    }

    // Test an allocator with a minimal interface
    {
        A* ptr = new A;
        std::shared_ptr<A> p(ptr, test_deleter<A>(3), bare_allocator<void>());
        assert(A::count == 1);
        assert(p.use_count() == 1);
        assert(p.get() == ptr);
        assert(test_deleter<A>::count == 1);
        assert(test_deleter<A>::dealloc_count == 0);
#ifndef TEST_HAS_NO_RTTI
        test_deleter<A>* d = std::get_deleter<test_deleter<A> >(p);
        assert(d);
        assert(d->state() == 3);
#endif
    }
    assert(A::count == 0);
    assert(test_deleter<A>::count == 0);
    assert(test_deleter<A>::dealloc_count == 1);
    test_deleter<A>::dealloc_count = 0;

#if TEST_STD_VER >= 11
    // Test an allocator that returns class-type pointers
    {
        A* ptr = new A;
        std::shared_ptr<A> p(ptr, test_deleter<A>(3), min_allocator<void>());
        assert(A::count == 1);
        assert(p.use_count() == 1);
        assert(p.get() == ptr);
        assert(test_deleter<A>::count == 1);
        assert(test_deleter<A>::dealloc_count == 0);
#ifndef TEST_HAS_NO_RTTI
        test_deleter<A>* d = std::get_deleter<test_deleter<A> >(p);
        assert(d);
        assert(d->state() == 3);
#endif
    }
    assert(A::count == 0);
    assert(test_deleter<A>::count == 0);
    assert(test_deleter<A>::dealloc_count == 1);

    {
        move_deleter<int> d(0);
        std::shared_ptr<int> p2(new int, std::move(d), std::allocator<int>());
        std::shared_ptr<int> p3(nullptr, std::move(d), std::allocator<int>());
    }
#endif // TEST_STD_VER >= 11

    {
        // Make sure we can't construct with:
        //    a) a deleter that doesn't have an operator ()(int*)
        //    b) a deleter that doesn't have a move constructor.
        static_assert(!std::is_constructible<std::shared_ptr<int>, int*, bad_deleter,
                                             test_allocator<A> >::value, "");
        static_assert(!std::is_constructible<std::shared_ptr<int>, int*, no_move_deleter,
                                             test_allocator<A> >::value, "");

        // Make sure that we can construct a shared_ptr where the element type and pointer type
        // aren't "convertible" but are "compatible".
        static_assert(!std::is_constructible<std::shared_ptr<derived[4]>,
                                             base[4], test_deleter<derived[4]>,
                                             test_allocator<derived[4]> >::value, "");
    }

  return 0;
}
