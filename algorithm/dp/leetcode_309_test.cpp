// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Tag stack
//@Tag 单调栈
//@Linked 121 122
//@Plan 动态规划入门 Day8

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_309_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_309_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_309.cpp"

namespace leetcode_309 {
using std::vector;

TEST_CASE("0 [test_309]", "[test_309]") {
    const vector<int32_t> input{1, 2, 3, 0, 2};
    static constexpr const auto result{3};
    Solution solution;
    CHECK(result == solution.maxProfit(input));
    CHECK(result == solution.maxProfit2(input));
}

TEST_CASE("1 [test_309]", "[test_309]") {
    const vector<int32_t> input{7, 1, 5, 3, 6, 4};
    static constexpr const auto result{5};
    Solution solution;
    CHECK(result == solution.maxProfit(input));
    CHECK(result == solution.maxProfit2(input));
}

TEST_CASE("2 [test_309]", "[test_309]") {
    const vector<int32_t> input{7, 6, 4, 3, 1};
    static constexpr const auto result{0};
    Solution solution;
    CHECK(result == solution.maxProfit(input));
    CHECK(result == solution.maxProfit2(input));
}

TEST_CASE("3 [test_309]", "[test_309]") {
    const vector<int32_t> input{1, 2, 3, 4, 5};
    static constexpr const auto result{4};
    Solution solution;
    CHECK(result == solution.maxProfit(input));
    CHECK(result == solution.maxProfit2(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_309_TEST_CPP
