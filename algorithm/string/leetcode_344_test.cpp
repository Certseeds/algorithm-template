// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag string
//@Tag 字符串
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_344_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_344_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_344.cpp"
#include <string>
#include <vector>

namespace leetcode_344 {

using Catch::Matchers::Equals;

TEST_CASE("1 [test_344]", "[test_344]") {
    Solution solution;
    static constexpr const char input[]{"hello"};
    vector<char> vInput{std::cbegin(input), std::cend(input)};
    const vector<char> result{std::crbegin(input), std::crend(input)};
    solution.reverseString(vInput);
    CHECK_THAT(result, Equals(vInput));
}

TEST_CASE("2 [test_344]", "[test_344]") {
    Solution solution;
    static constexpr const char input[]{"hannah"};
    vector<char> vInput{std::cbegin(input), std::cend(input)};
    const vector<char> result{std::crbegin(input), std::crend(input)};
    solution.reverseString(vInput);
    CHECK_THAT(result, Equals(vInput));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_344_TEST_HPP
