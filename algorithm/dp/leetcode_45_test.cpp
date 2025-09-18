// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day4
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_45_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_45_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_45.cpp"

namespace leetcode_45 {
using std::vector;

TEST_CASE("1 [test_45]", "[test_45]") {
    const vector<int32_t> inputs{2, 3, 1, 1, 4};
    static constexpr const auto result{2};
    Solution solution;
    CHECK(result == solution.jump(inputs));
    CHECK(result == solution.jump2(inputs));
}

TEST_CASE("2 [test_45]", "[test_45]") {
    const vector<int32_t> inputs{2, 3, 0, 1, 4};
    static constexpr const auto result{2};
    Solution solution;
    CHECK(result == solution.jump(inputs));
    CHECK(result == solution.jump2(inputs));
}

TEST_CASE("4 [test_45]", "[test_45]") {
    const vector<int32_t> inputs{3, 2, 1};
    static constexpr const auto result{1};
    Solution solution;
    CHECK(result == solution.jump(inputs));
    CHECK(result == solution.jump2(inputs));
}

TEST_CASE("3 [test_45]", "[test_45]") {
    const vector<int32_t> inputs{1, 2, 3};
    static constexpr const auto result{2};
    Solution solution;
    CHECK(result == solution.jump(inputs));
    CHECK(result == solution.jump2(inputs));
}

TEST_CASE("5 [test_45]", "[test_45]") {
    const vector<int32_t> inputs{2, 1, 1, 1, 1};
    static constexpr const auto result{3};
    Solution solution;
    CHECK(result == solution.jump(inputs));
    CHECK(result == solution.jump2(inputs));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_45_TEST_CPP
