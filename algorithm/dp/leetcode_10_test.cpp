// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/
//@Tag DP
//@Tag 动态规划
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_10_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_10_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_10.cpp"

namespace leetcode_10 {
using std::string;

TEST_CASE("test case 1", "[test_10]") {
    Solution solution;
    CHECK_FALSE(solution.isMatch("aa", "a"));
    CHECK(solution.isMatch("aa", "a*"));
    CHECK(solution.isMatch("ab", ".*"));
    CHECK(solution.isMatch("aab", "c*a*b"));
    CHECK_FALSE(solution.isMatch("mississippi", "mis*is*p*."));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_10_TEST_CPP
