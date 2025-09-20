// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day13
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_931_TEST_CPP
#define ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_931_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_931.cpp"

namespace leetcode_931 {
using std::vector;

TEST_CASE("1 [test_931]", "[test_931]") {
    const vector<vector<int32_t>> input{
            {2, 1, 3},
            {6, 5, 4},
            {7, 8, 9}
    };
    static constexpr const auto result{13};
    Solution solution;
    CHECK(result == solution.minFallingPathSum(input));
}

TEST_CASE("2 [test_931]", "[test_931]") {
    const vector<vector<int32_t>> input{
            {-19, 57},
            {-40, -5},
    };
    static constexpr const auto result{-59};
    Solution solution;
    CHECK(result == solution.minFallingPathSum(input));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_931_TEST_CPP
