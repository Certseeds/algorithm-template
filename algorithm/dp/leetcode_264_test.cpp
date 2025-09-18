// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day11
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_264_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_264_TEST_CPP

#include <catch_main.hpp>

#include "leetcode_264.cpp"

namespace leetcode_264 {
using std::vector;

TEST_CASE("1 [test_264]", "[test_264]") {
    static constexpr const auto input{10};
    static constexpr const auto result{12};
    Solution solution;
    CHECK(result == solution.nthUglyNumber(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_264_TEST_CPP
