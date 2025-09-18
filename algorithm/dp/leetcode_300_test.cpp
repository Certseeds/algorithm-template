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
//@Plan 动态规划入门 Day18
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_300_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_300_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_300.cpp"

namespace leetcode_300 {
using std::vector;

TEST_CASE("0 [test_300]", "[test_300]") {
    const vector<int32_t> input{10, 9, 2, 5, 3, 7, 101, 18};
    static constexpr const auto result{4};
    Solution solution;
    CHECK(result == solution.lengthOfLIS(input));
}

TEST_CASE("1 [test_300]", "[test_300]") {
    const vector<int32_t> input{4, 10, 4, 3, 8, 9};
    static constexpr const auto result{3};
    Solution solution;
    CHECK(result == solution.lengthOfLIS(input));
}

TEST_CASE("2 [test_300]", "[test_300]") {
    const vector<int32_t> input{0, 1, 0, 3, 2, 3};
    static constexpr const auto result{4};
    Solution solution;
    CHECK(result == solution.lengthOfLIS(input));
}

TEST_CASE("3 [test_300]", "[test_300]") {
    const vector<int32_t> input{7, 7, 7, 7, 7, 7, 7};
    static constexpr const auto result{1};
    Solution solution;
    CHECK(result == solution.lengthOfLIS(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_300_TEST_CPP
