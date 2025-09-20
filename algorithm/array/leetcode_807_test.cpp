// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
//@Tag array
//@Tag 数组

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_807_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_807_TEST_HPP

#include <catch_main.hpp>


#include "leetcode_807.cpp"

namespace leetcode_807 {
using std::vector;
using std::array;

TEST_CASE("test case 1 {test_807}", "{test_807}") {
    Solution solution;
    const vector<vector<int32_t>> heights{
            {3, 0, 8, 4},
            {2, 4, 5, 7},
            {9, 2, 6, 3},
            {0, 3, 1, 0}
    };
    static constexpr const auto result{35};
    CHECK(result == solution.maxIncreaseKeepingSkyline(heights));
}

TEST_CASE("test case 2 {test_807}", "{test_807}") {
    Solution solution;
    const vector<vector<int32_t>> heights{
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}
    };
    static constexpr const auto result{0};
    CHECK(result == solution.maxIncreaseKeepingSkyline(heights));
}
}
#endif // ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_807_TEST_HPP
