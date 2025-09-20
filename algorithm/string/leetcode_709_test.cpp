// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag string
//@Tag 字符串
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_709_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_709_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_709.cpp"
#include <string>

namespace leetcode_709 {

using Catch::Matchers::Equals;

TEST_CASE("1 [test_709]", "[test_709]") {
    Solution solution;
    static constexpr const char *const input{"UD"}, *const output{"ud"};
    CHECK_THAT(output, Equals(solution.toLowerCase(input)));
}

TEST_CASE("2 [test_709]", "[test_709]") {
    Solution solution;
    static constexpr const char *const input{"LoL"}, *const output{"lol"};
    CHECK_THAT(output, Equals(solution.toLowerCase(input)));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_709_TEST_HPP
