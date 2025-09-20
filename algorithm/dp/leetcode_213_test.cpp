// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day3
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_213_TEST_CPP
#define ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_213_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_213.cpp"

namespace leetcode_213 {
using std::vector;

TEST_CASE("1 [test_213]", "[test_213]") {
    const vector<int32_t> input{2, 3, 2};
    static constexpr const auto output{static_cast<int64_t>(3)};
    Solution solution;
    CHECK(output == solution.rob(input));
}

TEST_CASE("2 [test_213]", "[test_213]") {
    const vector<int32_t> input{1, 2, 3, 1};
    static constexpr const auto output{static_cast<int64_t>(4)};
    Solution solution;
    CHECK(output == solution.rob(input));
}

TEST_CASE("3 [test_213]", "[test_213]") {
    const vector<int32_t> input{1, 1};
    static constexpr const auto output{static_cast<int64_t>(1)};
    Solution solution;
    CHECK(output == solution.rob(input));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_213_TEST_CPP
