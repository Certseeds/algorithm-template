// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Description 不同路径
//@Plan 动态规划入门 Day15
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_62_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_62_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_62.cpp"

namespace leetcode_62 {
using std::vector;

TEST_CASE("1 [test_62]", "[test_62]") {
    static constexpr const size_t m{3}, n{7};
    static constexpr const auto result{28};
    Solution solution;
    CHECK(result == solution.uniquePaths(m, n));
}

TEST_CASE("2 [test_62]", "[test_62]") {
    static constexpr const size_t m{7}, n{3};
    static constexpr const auto result{28};
    Solution solution;
    CHECK(result == solution.uniquePaths(m, n));
}

TEST_CASE("3 [test_62]", "[test_62]") {
    static constexpr const size_t m{3}, n{3};
    static constexpr const auto result{6};
    Solution solution;
    CHECK(result == solution.uniquePaths(m, n));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_62_TEST_CPP
