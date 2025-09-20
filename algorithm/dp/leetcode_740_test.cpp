// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day3
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_740_TEST_CPP
#define ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_740_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_740.cpp"

namespace leetcode_740 {
using std::vector;

TEST_CASE("1 [test_740]", "[test_740]") {
    const vector<int32_t> input{3, 4, 2};
    static constexpr const auto result{6};
    Solution solution;
    CHECK(result == solution.deleteAndEarn(input));
}

TEST_CASE("2 [test_740]", "[test_740]") {
    const vector<int32_t> input{2, 2, 3, 3, 3, 4};
    static constexpr const auto result{9};
    Solution solution;
    CHECK(result == solution.deleteAndEarn(input));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_740_TEST_CPP
