// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag string
//@Tag 字符串
//@Tag 模拟
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_14_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_14_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_14.cpp"
#include <cassert>
#include <cstdint>
#include <string>
#include <vector>

namespace leetcode_14 {

using Catch::Matchers::Equals;

TEST_CASE("test case 1 [test_14]", "[test_14]") {
    Solution solution;
    const vector<string> strs{"flower", "flow", "flight"};
    static constexpr const char *const result{"fl"};
    CHECK_THAT(result, Equals(solution.longestCommonPrefix(strs)));
}

TEST_CASE("test case 2 [test_14]", "[test_14]") {
    Solution solution;
    const vector<string> strs{"dog", "racecar", "car"};
    CHECK(solution.longestCommonPrefix(strs).empty());

}

TEST_CASE("test case 3 [test_14]", "[test_14]") {
    Solution solution;
    const vector<string> strs{};
    CHECK(solution.longestCommonPrefix(strs).empty());
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_14_TEST_HPP
