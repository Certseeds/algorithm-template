// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Description 最小路径和
//@Plan 动态规划入门 Day16
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_64_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_64_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_64.cpp"

namespace leetcode_64 {
using std::vector;

TEST_CASE("1 [test_64]", "[test_64]") {
    const vector<vector<int32_t>> input{{1, 3, 1},
                                        {1, 5, 1},
                                        {4, 2, 1}};
    static constexpr const auto result{7};
    Solution solution;
    CHECK(result == solution.minPathSum(input));
}

TEST_CASE("2 [test_64]", "[test_64]") {
    const vector<vector<int32_t>> input{{1, 2, 3},
                                        {4, 5, 6}};
    static constexpr const auto result{12};
    Solution solution;
    CHECK(result == solution.minPathSum(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_64_TEST_CPP
