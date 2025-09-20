// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag DP
//@Tag 动态规划
//@Plan 数据结构基础 Day3
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_435_TEST_CPP
#define ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_435_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_435.cpp"

namespace leetcode_435 {
using std::vector;

TEST_CASE("1 [test_435]", "[test_435]") {
    const vector<vector<int32_t>> input{
            {1, 2},
            {2, 3},
            {3, 4},
            {1, 3},
    };
    static constexpr const auto result{1};
    Solution solution;
    CHECK(result == solution.eraseOverlapIntervals(input));
}

TEST_CASE("2 [test_435]", "[test_435]") {
    const vector<vector<int32_t>> input{
            {1, 2},
            {1, 2},
            {1, 2},
    };
    static constexpr const auto result{2};
    Solution solution;
    CHECK(result == solution.eraseOverlapIntervals(input));
}

TEST_CASE("3 [test_435]", "[test_435]") {
    const vector<vector<int32_t>> input{
            {1, 2},
            {2, 3},
    };
    static constexpr const auto result{0};
    Solution solution;
    CHECK(result == solution.eraseOverlapIntervals(input));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_435_TEST_CPP
