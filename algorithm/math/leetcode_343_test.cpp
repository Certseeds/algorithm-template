// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag Math
//@Tag 数学
//@Plan 动态规划入门 Day21
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_343_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_343_TEST_HPP

#include <catch_main.hpp>
#include <cassert>
#include <cstdint>
#include "leetcode_343.cpp"

namespace leetcode_343 {

TEST_CASE("1 [test_343]", "[test_343]") {
    static constexpr const auto input{2};
    static constexpr const auto result{1};
    Solution solution;
    CHECK(result == solution.integerBreak(input));
}

TEST_CASE("2 [test_343]", "[test_343]") {
    static constexpr const auto input{10};
    static constexpr const auto result{36};
    Solution solution;
    CHECK(result == solution.integerBreak(input));
}

TEST_CASE("3 [test_343]", "[test_343]") {
    static constexpr const auto input{45};
    static constexpr const auto result{14348907};
    Solution solution;
    CHECK(result == solution.integerBreak(input));
}

TEST_CASE("4 [test_343]", "[test_343]") {
    static constexpr const int64_t input{114};
    static constexpr const int64_t result{1350851717672992089};
    Solution solution;
    CHECK(result == solution.integerBreak(input));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_343_TEST_HPP

