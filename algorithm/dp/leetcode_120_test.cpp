// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day13
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_120_TEST_CPP
#define ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_120_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_120.cpp"

namespace leetcode_120 {
using std::vector;

TEST_CASE("1 [test_120]", "[test_120]") {
    const vector<vector<int32_t>> input{
            {1},
    };
    static constexpr const auto result{1};
    Solution solution;
    CHECK(result == solution.minimumTotal(input));
}

TEST_CASE("2 [test_120]", "[test_120]") {
    const vector<vector<int32_t>> input{
            {2},
            {3, 4},
            {5, 6, 7},
            {4, 1, 8, 3},
    };
    static constexpr const auto result{11};
    Solution solution;
    CHECK(result == solution.minimumTotal(input));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_120_TEST_CPP
