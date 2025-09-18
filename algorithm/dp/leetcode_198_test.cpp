// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day3
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_198_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_198_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_198.cpp"

namespace leetcode_198 {
using std::vector;

TEST_CASE("1 [test_198]", "[test_198]") {
    const vector<int32_t> input{1, 2, 3, 1};
    static constexpr const auto output{static_cast<int64_t>(4)};
    Solution solution;
    CHECK(output == solution.rob(input));
    CHECK(output == solution.rob2(input));
}

TEST_CASE("2 [test_198]", "[test_198]") {
    const vector<int32_t> input{2, 7, 9, 3, 1};
    static constexpr const auto output{static_cast<int64_t>(12)};
    Solution solution;
    CHECK(output == solution.rob(input));
    CHECK(output == solution.rob2(input));
}

TEST_CASE("3 [test_198]", "[test_198]") {
    const vector<int32_t> input{1, 1};
    static constexpr const auto output{static_cast<int64_t>(1)};
    Solution solution;
    CHECK(output == solution.rob(input));
    CHECK(output == solution.rob2(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_198_TEST_CPP
