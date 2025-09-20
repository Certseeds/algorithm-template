// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag DP
//@Tag 动态规划
//@Description 斐波那契?
//@Plan 动态规划入门 Day2
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_746_TEST_CPP
#define ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_746_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_746.cpp"

namespace leetcode_746 {
using std::vector;

TEST_CASE("1 [test_746]", "[test_746]") {
    const vector<int32_t> input{10, 15, 20};
    static constexpr const auto output{15};
    Solution solution;
    CHECK(output == solution.minCostClimbingStairs(input));
    CHECK(output == solution.minCostClimbingStairs2(input));
}

TEST_CASE("2 [test_746]", "[test_746]") {
    const vector<int32_t> input{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    static constexpr const auto output{6};
    // 0 -> 2 -> 4 ->6 -> 7 -> 9 -> out六跳,每跳cost 1
    Solution solution;
    CHECK(output == solution.minCostClimbingStairs(input));
    CHECK(output == solution.minCostClimbingStairs2(input));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_746_TEST_CPP
