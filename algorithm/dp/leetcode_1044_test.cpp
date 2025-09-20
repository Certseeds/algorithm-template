// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Description 最长公共字串

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_1044_TEST_CPP
#define ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_1044_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_1044.cpp"

namespace leetcode_1044 {
using std::string;

TEST_CASE("3 [test_1044]", "[test_1044]") {
    constexpr const char *const input{"banana"};
    constexpr const char *const output{"ana"};
    Solution solution;
    const string result{solution.longestDupSubstring(input)};
    CHECK(result == output);
}

TEST_CASE("2 [test_1044]", "[test_1044]") {
    constexpr const char *const input{"abcd"};
    constexpr const char *const output{""};
    Solution solution;
    const string result{solution.longestDupSubstring(input)};
    CHECK(result == output);
}

TEST_CASE("1 [test_1044]", "[test_1044]") {
    constexpr const char *const input{"efg"};
    constexpr const char *const output{""};
    Solution solution;
    const string result{solution.longestDupSubstring(input)};
    CHECK(result == output);
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_1044_TEST_CPP
