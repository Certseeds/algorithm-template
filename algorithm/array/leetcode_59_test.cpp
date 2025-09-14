// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag array
//@Tag 数组

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_59_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_59_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include "leetcode_59.cpp"

namespace leetcode_59 {
using std::vector;

using Catch::Matchers::Equals;

TEST_CASE("2 {test_59}", "{test_59}") {
    static constexpr const auto input{3};
    const vector<vector<int32_t>> result{{1, 2, 3},
                                         {8, 9, 4},
                                         {7, 6, 5}
    };
    Solution solution;
    CHECK_THAT(solution.generateMatrix(input), Equals(result));
}

TEST_CASE("1 {test_59}", "{test_59}") {
    static constexpr const auto input{8};
    const vector<vector<int32_t>> result{{1,  2,  3,  4,  5,  6,  7,  8},
                                         {28, 29, 30, 31, 32, 33, 34, 9},
                                         {27, 48, 49, 50, 51, 52, 35, 10},
                                         {26, 47, 60, 61, 62, 53, 36, 11},
                                         {25, 46, 59, 64, 63, 54, 37, 12},
                                         {24, 45, 58, 57, 56, 55, 38, 13},
                                         {23, 44, 43, 42, 41, 40, 39, 14},
                                         {22, 21, 20, 19, 18, 17, 16, 15}};
    const vector<vector<int32_t>> result2{{1, 2,  3,  4,  5,  6,  7,  9},
                                          {0, 29, 30, 31, 32, 33, 35, 10},
                                          {0, 28, 49, 50, 51, 53, 36, 11},
                                          {0, 27, 48, 61, 63, 54, 37, 12},
                                          {0, 26, 47, 60, 64, 55, 38, 13
                                          },
                                          {0, 25, 46, 59, 57, 56, 39, 14},
                                          {0, 24, 45, 43, 42, 41, 40, 15},
                                          {0,
                                              23, 21, 20, 19, 18, 17, 16}};
    Solution solution;
    CHECK_THAT(solution.generateMatrix(input), Equals(result));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_59_TEST_HPP
