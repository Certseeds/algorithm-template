// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag array
//@Tag 数组
//@Tag 二分搜索
//@Plan 剑指OfferII-I Day05
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_240_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_240_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include "leetcode_240.cpp"

namespace leetcode_240 {
using std::vector;

TEST_CASE("test case 1 {test_240}", "{test_240}") {
    const vector<vector<int32_t>> input{
            {1,  4,  7,  11, 15},
            {2,  5,  8,  12, 19},
            {3,  6,  9,  16, 22},
            {10, 13, 14, 17, 24},
            {18, 21, 23, 26, 30}
    };
    static constexpr const auto k{5};
    Solution solution;
    CHECK(solution.findNumberIn2DArray(input, k));
    CHECK(solution.findNumberIn2DArrayZ(input, k));
}

TEST_CASE("test case 2 {test_240}", "{test_240}") {
    const vector<vector<int32_t>> input{
            {1,  4,  7,  11, 15},
            {2,  5,  8,  12, 19},
            {3,  6,  9,  16, 22},
            {10, 13, 14, 17, 24},
            {18, 21, 23, 26, 30}
    };
    static constexpr const auto k{20};
    Solution solution;
    CHECK_FALSE(solution.findNumberIn2DArray(input, k));
    CHECK_FALSE(solution.findNumberIn2DArrayZ(input, k));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_240_TEST_HPP
