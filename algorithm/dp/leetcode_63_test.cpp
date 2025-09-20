// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag DP
//@Tag 动态规划
//@Description 不同路径2
//@Plan 动态规划入门 Day15
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_63_TEST_CPP
#define ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_63_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_63.cpp"

namespace leetcode_63 {
using std::vector;

TEST_CASE("1 [test_63]", "[test_63]") {
    const vector<vector<int32_t>> input{{0, 0, 0},
                                        {0, 1, 0},
                                        {0, 0, 0}};
    static constexpr const auto result{2};
    Solution solution;
    CHECK(result == solution.uniquePathsWithObstacles(input));
}

TEST_CASE("2 [test_63]", "[test_63]") {
    const vector<vector<int32_t>> input{{0, 1},
                                        {0, 0}};
    static constexpr const auto result{1};
    Solution solution;
    CHECK(result == solution.uniquePathsWithObstacles(input));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_63_TEST_CPP
