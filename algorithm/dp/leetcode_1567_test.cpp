// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day6
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_1567_TEST_CPP
#define ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_1567_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_1567.cpp"

namespace leetcode_1567 {
using std::vector;

TEST_CASE("1 [test_1567]", "[test_1567]") {
    const vector<int32_t> input{1, -2, -3, 4};
    static constexpr const auto result{4};
    Solution solution;
    CHECK(result == solution.getMaxLen(input));
}

TEST_CASE("2 [test_1567]", "[test_1567]") {
    const vector<int32_t> input{0, 1, -2, -3, -4};
    static constexpr const auto result{3};
    Solution solution;
    CHECK(result == solution.getMaxLen(input));

}

TEST_CASE("3 [test_1567]", "[test_1567]") {
    const vector<int32_t> input{-1, -2, -3, 0, 1};
    static constexpr const auto result{2};
    Solution solution;
    CHECK(result == solution.getMaxLen(input));
}

TEST_CASE("4 [test_1567]", "[test_1567]") {
    const vector<int32_t> input{-1, 2};
    static constexpr const auto result{1};
    Solution solution;
    CHECK(result == solution.getMaxLen(input));
}

TEST_CASE("5 [test_1567]", "[test_1567]") {
    const vector<int32_t> input{1, 2, 3, 5, -6, 4, 0, 10};
    static constexpr const auto result{4};
    Solution solution;
    CHECK(result == solution.getMaxLen(input));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_1567_TEST_CPP
