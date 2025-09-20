// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_1614_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_1614_TEST_HPP

#include "leetcode_1614.cpp"
#include <catch_main.hpp>

namespace leetcode_1614 {

TEST_CASE("1 [test_1614]", "[test_1614]") {
    Solution solution;
    CHECK(1 == solution.maxDepth("()"));
    CHECK(1 == solution.maxDepth("(*)"));
    CHECK(2 == solution.maxDepth("((*))"));
}

TEST_CASE("2 [test_1614]", "[test_1614]") {
    Solution solution;
    CHECK(3 == solution.maxDepth("(1+(2*3)+((8)/4))+1"));
    CHECK(3 == solution.maxDepth("(1)+((2))+(((3)))"));
    CHECK(1 == solution.maxDepth("1+(2*3)/(2-1)"));
    CHECK(0 == solution.maxDepth("1"));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_1614_TEST_HPP
