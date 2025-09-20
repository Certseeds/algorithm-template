// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag stack
//@Tag 栈
//@Tag 动态规划
//@Tag DP
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_STACK_LEETCODE_32_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_STACK_LEETCODE_32_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_32.cpp"

namespace leetcode_32 {

TEST_CASE("test case 1 [test_32]", "[test_32]") {
    Solution solution;
    CHECK(0 == solution.longestValidParentheses(""));
    CHECK(2 == solution.longestValidParentheses("(()"));
    CHECK(2 == solution.longestValidParentheses("())"));
    CHECK(4 == solution.longestValidParentheses(")()())"));
    CHECK(6 == solution.longestValidParentheses("()(())"));
    CHECK(2 == solution.longestValidParentheses("()(()"));
    CHECK(6 == solution.longestValidParentheses("(()())"));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_STACK_LEETCODE_32_TEST_HPP
