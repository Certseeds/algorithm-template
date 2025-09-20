// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day6
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_152_TEST_CPP
#define ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_152_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_152.cpp"

namespace leetcode_152 {
using std::vector;

TEST_CASE("1 [test_152]", "[test_152]") {
    const vector<int32_t> input{1, 5, 11, 5};
    static constexpr const auto result{275};
    Solution solution;
    CHECK(result == solution.maxProduct(input));
    CHECK(result == solution.maxProduct2(input));
}

TEST_CASE("2 [test_152]", "[test_152]") {
    const vector<int32_t> input{-2, 0, -1};
    static constexpr const auto result{0};
    Solution solution;
    CHECK(result == solution.maxProduct(input));
    CHECK(result == solution.maxProduct2(input));
}

TEST_CASE("3 [test_152]", "[test_152]") {
    const vector<int32_t> input{2, 3, -2, 4};
    static constexpr const auto result{6};
    Solution solution;
    CHECK(result == solution.maxProduct(input));
    CHECK(result == solution.maxProduct2(input));
}

TEST_CASE("4 [test_152]", "[test_152]") {
    const vector<int32_t> input{-2, 4, -3};
    static constexpr const auto result{24};
    Solution solution;
    CHECK(result == solution.maxProduct(input));
    CHECK(result == solution.maxProduct2(input));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_152_TEST_CPP
