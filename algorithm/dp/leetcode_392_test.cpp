// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanos

*/
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day19

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_392_TEST_CPP
#define ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_392_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_392.cpp"

namespace leetcode_392 {
using std::vector;

TEST_CASE("1 [test_392]", "[test_392]") {
    static constexpr const char *const s{"abc"}, *const t{"ahbgdc"};
    Solution solution;
    CHECK(solution.isSubsequence(s, t));
}

TEST_CASE("2 [test_392]", "[test_392]") {
    static constexpr const char *const s{"axc"}, *const t{"ahbgdc"};
    Solution solution;
    CHECK_FALSE(solution.isSubsequence(s, t));
}

TEST_CASE("3 [test_392]", "[test_392]") {
    static constexpr const char *const s{"114514"}, *const t{"1919810"};
    Solution solution;
    CHECK_FALSE(solution.isSubsequence(s, t));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_392_TEST_CPP
