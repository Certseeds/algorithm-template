// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day4
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_55_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_55_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_55.cpp"

namespace leetcode_55 {
using std::vector;

TEST_CASE("1 [test_55]", "[test_55]") {
    const vector<int32_t> inputs{2, 3, 1, 1, 4};
    Solution solution;
    CHECK(solution.canJump(inputs));
}

TEST_CASE("2 [test_55]", "[test_55]") {
    const vector<int32_t> inputs{3, 2, 1, 0, 4};
    Solution solution;
    CHECK_FALSE(solution.canJump(inputs));
}

TEST_CASE("3 [test_55]", "[test_55]") {
    const vector<int32_t> inputs{0};
    Solution solution;
    CHECK(solution.canJump(inputs));
}

TEST_CASE("4 [test_55]", "[test_55]") {
    const vector<int32_t> inputs{2, 0, 0};
    Solution solution;
    CHECK(solution.canJump(inputs));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_55_TEST_CPP
