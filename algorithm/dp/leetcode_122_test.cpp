// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Tag stack
//@Tag 单调栈
//@Linked 121
//@Plan 动态规划入门 Day7
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_122_TEST_CPP
#define ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_122_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_122.cpp"

namespace leetcode_122 {
using std::vector;

TEST_CASE("1 [test_122]", "[test_122]") {
    const vector<int32_t> input{7, 1, 5, 3, 6, 4};
    static constexpr const auto result{7};
    Solution solution;
    CHECK(result == solution.maxProfit(input));
    CHECK(result == solution.maxProfit2(input));
    CHECK(result == solution.maxProfit3(input));
    CHECK(result == solution.maxProfit4(input));
}

TEST_CASE("2 [test_122]", "[test_122]") {
    const vector<int32_t> input{7, 6, 4, 3, 1};
    static constexpr const auto result{0};
    Solution solution;
    CHECK(result == solution.maxProfit(input));
    CHECK(result == solution.maxProfit2(input));
    CHECK(result == solution.maxProfit3(input));
    CHECK(result == solution.maxProfit4(input));
}

TEST_CASE("3 [test_122]", "[test_122]") {
    const vector<int32_t> input{1, 2, 3, 4, 5};
    static constexpr const auto result{4};
    Solution solution;
    CHECK(result == solution.maxProfit(input));
    CHECK(result == solution.maxProfit2(input));
    CHECK(result == solution.maxProfit3(input));
    CHECK(result == solution.maxProfit4(input));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_122_TEST_CPP
