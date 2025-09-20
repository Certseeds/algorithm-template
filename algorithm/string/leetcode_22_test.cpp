// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag string
//@Tag 字符串
//@Tag DP
//@Tag 回溯
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_22_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_22_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_22.cpp"
#include <cassert>
#include <cstdint>
#include <string>
#include <vector>

namespace leetcode_22 {

static const vector<string> gene5{
        "((()))",
        "(()())",
        "(())()",
        "()(())",
        "()()()"
};
using Catch::Matchers::UnorderedEquals;

TEST_CASE("1 [test_22]", "[test_22]") {
    Solution solution;
    CHECK(solution.generateParenthesis(1).size() == 1);
    CHECK(solution.generateParenthesis(2).size() == 2);
    CHECK(solution.generateParenthesis(3).size() == 5);
    CHECK(solution.generateParenthesis(4).size() == 14);
    CHECK_THAT(solution.generateParenthesis(3), UnorderedEquals(gene5));
}

TEST_CASE("2 [test_22]", "[test_22]") {
    Solution solution;
    for (int32_t i{1}; i < 5; i++) {
        CHECK_THAT(solution.generateParenthesis(i), UnorderedEquals(solution.generateParenthesis(i)));
    }
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_22_TEST_HPP
