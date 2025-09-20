// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag string
//@Tag 字符串
//@Description 非常简单
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_784_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_784_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_784.cpp"
#include <string>
#include <vector>
#include <array>

namespace leetcode_784 {

using Catch::Matchers::UnorderedEquals;

TEST_CASE("1 [test_784]", "[test_784]") {
    Solution solution;
    static constexpr const char *const input{"a1b2"};
    static const std::array<const char *const, 4> arr{"a1b2", "a1B2", "A1b2", "A1B2"};
    const vector<string> output{arr.cbegin(), arr.cend()};
    CHECK_THAT(solution.letterCasePermutation(input), UnorderedEquals(output));
}

TEST_CASE("2 [test_784]", "[test_784]") {
    Solution solution;
    static constexpr const char *const input{"3z4"};
    static const std::array<const char *const, 2> arr{"3z4", "3Z4"};
    const vector<string> output{arr.cbegin(), arr.cend()};
    CHECK_THAT(solution.letterCasePermutation(input), UnorderedEquals(output));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_784_TEST_HPP
