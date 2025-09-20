// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day1
//@Plan 剑指OfferII-I Day08
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_509_TEST_CPP
#define ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_509_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_509.cpp"

namespace leetcode_509 {

TEST_CASE("1 [test_509]", "[test_509]") {
    static constexpr const auto input{2};
    static constexpr const auto result{1};
    Solution solution;
    CHECK(result == solution.fib(input));
}

TEST_CASE("2 [test_509]", "[test_509]") {
    static constexpr const auto input{3};
    static constexpr const auto result{2};
    Solution solution;
    CHECK(result == solution.fib(input));
}

TEST_CASE("3 [test_509]", "[test_509]") {
    static constexpr const auto input{4};
    static constexpr const auto result{3};
    Solution solution;
    CHECK(result == solution.fib(input));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_509_TEST_CPP
