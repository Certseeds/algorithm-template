// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag DP
//@Tag 动态规划

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_174_TEST_CPP
#define ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_174_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_174.cpp"

namespace leetcode_174 {
using std::vector;

TEST_CASE("1 [test_174]", "[test_174]") {
    const vector<vector<int32_t>> inputs{{-2, -3,  3},
                                         {-5, -10, 1},
                                         {10, 30,  -5}};
    static constexpr const auto result{7};
    Solution solution;
    CHECK(result == solution.calculateMinimumHP(inputs));
}

TEST_CASE("2 [test_174]", "[test_174]") {
    const vector<vector<int32_t>> inputs{{0, -3}};
    static constexpr const auto result{4};
    Solution solution;
    CHECK(result == solution.calculateMinimumHP(inputs));
}

TEST_CASE("3 [test_174]", "[test_174]") {
    const vector<vector<int32_t>> inputs{{0}};
    static constexpr const auto result{1};
    Solution solution;
    CHECK(result == solution.calculateMinimumHP(inputs));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_174_TEST_CPP
