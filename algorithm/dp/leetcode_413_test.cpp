// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day10

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_413_TEST_CPP
#define ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_413_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_413.cpp"

namespace leetcode_413 {
using std::vector;

TEST_CASE("1 [test_413]", "[test_413]") {
    const vector<int32_t> input{1, 2, 3, 4};
    static constexpr const auto output{3};
    Solution solution;
    CHECK(output == solution.numberOfArithmeticSlices(input));
}

TEST_CASE("2 [test_413]", "[test_413]") {
    const vector<int32_t> input{1};
    static constexpr const auto output{0};
    Solution solution;
    CHECK(output == solution.numberOfArithmeticSlices(input));
}

TEST_CASE("3 [test_413]", "[test_413]") {
    const vector<int32_t> input{1, 2, 3, 8, 9, 10};
    static constexpr const auto output{2};
    Solution solution;
    CHECK(output == solution.numberOfArithmeticSlices(input));
}

TEST_CASE("4 [test_413]", "[test_413]") {
    const vector<int32_t> input{2, 1, 3, 4, 2, 3};
    static constexpr const auto output{0};
    Solution solution;
    CHECK(output == solution.numberOfArithmeticSlices(input));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_413_TEST_CPP
