// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_830_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_830_TEST_HPP

#include <catch_main.hpp>
#include <vector>
#include <string>
#include "leetcode_830.cpp"

namespace leetcode_830 {
using Catch::Matchers::Equals;

TEST_CASE("test case 1 [test_830]", "[test_830]") {
    Solution solution;
    static constexpr const char *const input{"abbxxxxzzy"};
    const vector<vector<int32_t>> output{{3, 6}};
    CHECK_THAT(output, Equals(solution.largeGroupPositions(input)));
}

TEST_CASE("test case 2 [test_830]", "[test_830]") {
    Solution solution;
    static constexpr const char *const input{"abc"};
    const vector<vector<int32_t>> output{};
    CHECK_THAT(output, Equals(solution.largeGroupPositions(input)));
}

TEST_CASE("test case 3 [test_830]", "[test_830]") {
    Solution solution;
    static constexpr const char *const input{"abcdddeeeeaabbbcd"};
    const vector<vector<int32_t>> output{{3,  5},
                                         {6,  9},
                                         {12, 14}};
    CHECK_THAT(output, Equals(solution.largeGroupPositions(input)));
}

TEST_CASE("test case 4 [test_830]", "[test_830]") {
    Solution solution;
    static constexpr const char *const input{"abz"};
    const vector<vector<int32_t>> output{};
    CHECK_THAT(output, Equals(solution.largeGroupPositions(input)));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_830_TEST_HPP
