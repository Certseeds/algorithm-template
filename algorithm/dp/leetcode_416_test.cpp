// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/
//@Tag DP
//@Tag 动态规划

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_416_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_416_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_416.cpp"

namespace leetcode_416 {
using std::vector;

TEST_CASE("1 [test_416]", "[test_416]") {
    const vector<int32_t> input{1, 5, 11, 5};
    Solution solution;
    CHECK(solution.canPartition(input));
    CHECK(solution.canPartition2(input));
}

TEST_CASE("2 [test_416]", "[test_416]") {
    const vector<int32_t> input{1, 2, 3, 5};
    Solution solution;
    CHECK_FALSE(solution.canPartition(input));
    CHECK_FALSE(solution.canPartition2(input));
}

TEST_CASE("3 [test_416]", "[test_416]") {
    const vector<int32_t> input{114514};
    Solution solution;
    CHECK_FALSE(solution.canPartition(input));
    CHECK_FALSE(solution.canPartition2(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_416_TEST_CPP
