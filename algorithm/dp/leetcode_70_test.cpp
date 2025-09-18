// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Description 斐波那契?
//@Plan 动态规划入门 Day2
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_70_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_70_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_70.cpp"

namespace leetcode_70 {
using std::vector;

TEST_CASE("1 [test_70]", "[test_70]") {
    static constexpr const auto input{2}, result{2};
    Solution solution;
    CHECK(result == solution.climbStairs(input));
}

TEST_CASE("2 [test_70]", "[test_70]") {
    static constexpr const auto input{3}, result{3};
    Solution solution;
    CHECK(result == solution.climbStairs(input));
}

TEST_CASE("3 [test_70]", "[test_70]") {
    static constexpr const auto input{4}, result{5};
    Solution solution;
    CHECK(result == solution.climbStairs(input));
}

TEST_CASE("4 [test_70]", "[test_70]") {
    static constexpr const auto input{5}, result{8};
    Solution solution;
    CHECK(result == solution.climbStairs(input));
}

TEST_CASE("5 [test_70]", "[test_70]") {
    static constexpr const auto input{6}, result{13};
    Solution solution;
    CHECK(result == solution.climbStairs(input));
}
}

#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_70_TEST_CPP
