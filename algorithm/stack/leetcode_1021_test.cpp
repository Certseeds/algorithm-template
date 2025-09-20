// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_1021_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_1021_TEST_HPP

#include "leetcode_1021.cpp"
#include <catch_main.hpp>

namespace leetcode_1021 {

TEST_CASE("1 [test_1021]", "[test_1021]") {
    static constexpr const char *const input{"(()())(())"};
    static constexpr const char *const result{"()()()"};
    Solution solution;
    CHECK(result == solution.removeOuterParentheses(input));
}

TEST_CASE("2 [test_1021]", "[test_1021]") {
    static constexpr const char *const input{"(())(()()())((()))"};
    static constexpr const char *const result{"()()()()(())"};
    Solution solution;
    CHECK(result == solution.removeOuterParentheses(input));
}

TEST_CASE("3 [test_1021]", "[test_1021]") {
    static constexpr const char *const input{"()()"};
    static constexpr const char *const result{""};
    Solution solution;
    CHECK(result == solution.removeOuterParentheses(input));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_1021_TEST_HPP
