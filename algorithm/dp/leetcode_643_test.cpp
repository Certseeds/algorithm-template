// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanos

*/
//@Tag DP
//@Tag 动态规划

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_643_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_643_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_643.cpp"

namespace leetcode_643 {
using std::vector;

TEST_CASE("1 [test_643]", "[test_643]") {
    const vector<int32_t> input{1, 12, -5, -6, 50, 3};
    static constexpr const auto k{4};
    static const auto result{Catch::Approx(12.75).epsilon(0.0001)};
    Solution solution;
    CHECK(result == solution.findMaxAverage(input, k));
}

TEST_CASE("2 [test_643]", "[test_643]") {
    const vector<int32_t> input{5};
    static constexpr const auto k{1};
    static const auto result{Catch::Approx(5.0).epsilon(0.0001)};
    Solution solution;
    CHECK(result == solution.findMaxAverage(input, k));
}

TEST_CASE("3 [test_643]", "[test_643]") {
    const vector<int32_t> input{1, 1, 4, 5, 1, 4};
    static constexpr const auto k{2};
    static const auto result{Catch::Approx(4.5).epsilon(0.0001)};
    Solution solution;
    CHECK(result == solution.findMaxAverage(input, k));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_643_TEST_CPP
