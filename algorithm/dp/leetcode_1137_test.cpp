// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day1
//@Plan 剑指OfferII-I Day08
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_1137_TEST_CPP
#define ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_1137_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_1137.cpp"

namespace leetcode_1137 {
using std::array;


TEST_CASE("1 [test_1137]", "[test_1137]") {
    static constexpr const auto input{4};
    static constexpr const auto result{4};
    Solution solution;
    CHECK(result == solution.tribonacci(input));
}

TEST_CASE("2 [test_1137]", "[test_1137]") {
    static constexpr const auto input{0};
    static constexpr const auto result{0};
    Solution solution;
    CHECK(result == solution.tribonacci(input));
}

TEST_CASE("3 [test_1137]", "[test_1137]") {
    static constexpr const auto input{1};
    static constexpr const auto result{1};
    Solution solution;
    CHECK(result == solution.tribonacci(input));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_1137_TEST_CPP
