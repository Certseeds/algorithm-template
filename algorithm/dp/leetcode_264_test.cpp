// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day11
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_264_TEST_CPP
#define ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_264_TEST_CPP

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
#endif //ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_264_TEST_CPP
