// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022 nanos

*/
//@Tag DP
//@Tag 动态规划

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_1277_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_1277_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_1277.cpp"

namespace leetcode_1277 {
using std::string;

using Catch::Matchers::Equals;

TEST_CASE("1 [test_1277]", "[test_1277]") {
    const vector<vector<int32_t>> matrix{
            {0, 1, 1},
            {1, 1, 0},
            {1, 0, 1}
    };
    constexpr const auto result{6};
    Solution solution;
    const auto output{solution.countSquares(matrix)};
    CHECK(output == result);
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_1277_TEST_CPP
