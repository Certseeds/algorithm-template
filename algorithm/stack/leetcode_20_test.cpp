// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag stack
//@Tag 栈
//@Plan 数据结构入门 Day9

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_20_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_20_TEST_HPP

#include "leetcode_20.cpp"
#include <catch_main.hpp>

namespace leetcode_20 {

TEST_CASE("test case 1 [test_20]", "[test_20]") {
    Solution solution;
    CHECK(solution.isValid("()"));
    CHECK(solution.isValid("()[]{}"));
    CHECK(solution.isValid("(()[]{})[()[]{}]{()[]{}}"));
    CHECK(solution.isValid("(((()[]{})[()[]{}]{()[]{}})[]{})[()[]{}]{()[]{}}"));
}

TEST_CASE("test case 0 [test_20]", "[test_20]") {
    Solution solution;
    CHECK_FALSE(solution.isValid("(]"));
    CHECK_FALSE(solution.isValid("(}"));
    CHECK_FALSE(solution.isValid("[}"));
    CHECK_FALSE(solution.isValid("[)"));
    CHECK_FALSE(solution.isValid("{)"));
    CHECK_FALSE(solution.isValid("{]"));
    CHECK_FALSE(solution.isValid("([)]"));
    CHECK_FALSE(solution.isValid("(((()[]{})[()[]{}]{()[]{}})[]{))[()[]{}]{()[]{}}"));
}

TEST_CASE("test case 2-2 [test_20]", "[test_20]") {
    Solution solution;
    CHECK_FALSE(solution.isValid("([)]"));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_20_TEST_HPP
