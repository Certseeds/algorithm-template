// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 数组
//@Tag 暴力解法
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_661_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_661_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include "leetcode_661.cpp"

namespace leetcode_661 {
using std::vector;

using Catch::Matchers::Equals;

TEST_CASE("test case 1 [test_661]", "[test_661]") {
    vector<vector<int32_t>> input{{1, 1, 1},
                                  {1, 0, 1},
                                  {1, 1, 1},};
    const vector<vector<int32_t>> result{{0, 0, 0},
                                         {0, 0, 0},
                                         {0, 0, 0},};
    Solution solution;
    CHECK_THAT(solution.imageSmoother(input), Equals(result));
}

TEST_CASE("test case 2 [test_661]", "[test_661]") {
    vector<vector<int32_t>> input{{1, 1, 1},};
    const vector<vector<int32_t>> result{{1, 1, 1},};
    Solution solution;
    CHECK_THAT(solution.imageSmoother(input), Equals(result));
}

TEST_CASE("test case 3 [test_661]", "[test_661]") {
    vector<vector<int32_t>> input{{1},
                                  {1},
                                  {1},};
    const vector<vector<int32_t>> result{{1},
                                         {1},
                                         {1},};
    Solution solution;
    CHECK_THAT(solution.imageSmoother(input), Equals(result));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_661_TEST_HPP
