// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 数组
//@Tag 暴力解法
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_697_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_697_TEST_HPP

#include <catch_main.hpp>

#include "leetcode_697.cpp"

namespace leetcode_697 {
using std::vector;

TEST_CASE("test case 1 [test_697]", "[test_697]") {
    vector<int32_t> input{1, 2, 2, 3, 1};
    static constexpr const auto result{2};
    Solution solution;
    CHECK(result == solution.findShortestSubArray(input));
}

TEST_CASE("test case 2 [test_697]", "[test_697]") {
    vector<int32_t> input{1, 2, 2, 3, 1, 4, 2};
    static constexpr const auto result{6};
    Solution solution;
    CHECK(result == solution.findShortestSubArray(input));
}

TEST_CASE("test case 3 [test_697]", "[test_697]") {
    vector<int32_t> input{2, 1};
    static constexpr const auto result{1};
    Solution solution;
    CHECK(result == solution.findShortestSubArray(input));
}

TEST_CASE("test case 4 [test_697]", "[test_697]") {
    vector<int32_t> input{};
    static constexpr const auto result{0};
    Solution solution;
    CHECK(result == solution.findShortestSubArray(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_697_TEST_HPP
