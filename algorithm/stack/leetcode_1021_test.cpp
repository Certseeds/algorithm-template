// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_STACK_LEETCODE_1021_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_STACK_LEETCODE_1021_TEST_HPP

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
#endif //ALGORITHM_TEMPLATE_ALGORITHM_STACK_LEETCODE_1021_TEST_HPP
