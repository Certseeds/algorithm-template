// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Plan 数据结构入门 Day9
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_STACK_LEETCODE_232_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_STACK_LEETCODE_232_TEST_HPP

#include "leetcode_232.cpp"
#include <catch_main.hpp>
#include <memory>

namespace leetcode_232 {

TEST_CASE("1 [test_232]", "[test_232]") {
    Solution solution;
    const auto pointer = std::unique_ptr<MyQueue>(solution.pure());
    CHECK(pointer->empty());
    pointer->push(1);
    pointer->push(2);
    CHECK(1 == pointer->peek());
    CHECK(1 == pointer->pop());
    CHECK_FALSE(pointer->empty());
    CHECK(2 == pointer->peek());
    CHECK(2 == pointer->pop());
    CHECK(pointer->empty());
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_STACK_LEETCODE_232_TEST_HPP
