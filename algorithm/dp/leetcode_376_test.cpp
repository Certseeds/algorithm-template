// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day18

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_376_TEST_CPP
#define ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_376_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_376.cpp"

namespace leetcode_376 {
using std::vector;

TEST_CASE("1 [test_376]", "[test_376]") {
    const vector<int32_t> input{1, 7, 4, 9, 2, 5};
    static constexpr const auto result{6};
    Solution solution;
    CHECK(result == solution.wiggleMaxLength(input));
}

TEST_CASE("2 [test_376]", "[test_376]") {
    const vector<int32_t> input{1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    static constexpr const auto result{7};
    Solution solution;
    CHECK(result == solution.wiggleMaxLength(input));
}

TEST_CASE("3 [test_376]", "[test_376]") {
    const vector<int32_t> input{1, 2, 3, 4, 5, 6, 7, 8, 9};
    static constexpr const auto result{2};
    Solution solution;
    CHECK(result == solution.wiggleMaxLength(input));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_376_TEST_CPP
