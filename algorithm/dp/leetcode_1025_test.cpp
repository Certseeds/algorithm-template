// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Tag 位运算
//@Tag 数学归纳法

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_1025_TEST_CPP
#define ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_1025_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_1025.cpp"

namespace leetcode_1025 {

TEST_CASE("1 [test_1025]", "[test_1025]") {
    static constexpr const auto input{1};
    Solution solution;
    CHECK_FALSE(solution.divisorGame(input));
    CHECK_FALSE(solution.divisorGame2(input));
}

TEST_CASE("2 [test_1025]", "[test_1025]") {
    static constexpr const auto input{2};
    Solution solution;
    CHECK(solution.divisorGame(input));
    CHECK(solution.divisorGame2(input));
}

TEST_CASE("3 [test_1025]", "[test_1025]") {
    static constexpr const auto input{11};
    Solution solution;
    CHECK_FALSE(solution.divisorGame(input));
    CHECK_FALSE(solution.divisorGame2(input));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_1025_TEST_CPP
