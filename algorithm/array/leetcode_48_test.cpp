// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag array
//@Tag 数组

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_48_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_48_TEST_HPP

#include <catch_main.hpp>

#include "leetcode_48.cpp"

namespace leetcode_48 {
using std::vector;

using Catch::Matchers::Equals;

TEST_CASE("basic test [test_48]", "[test_48]") {
    vector<vector<int32_t>> input{
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    const vector<vector<int32_t>> result{
            {7, 4, 1},
            {8, 5, 2},
            {9, 6, 3}
    };
    Solution solution;
    solution.rotate(input);
    CHECK_THAT(result, Equals(input));
}

TEST_CASE("basic test 2 [test_48]", "[test_48]") {
    vector<vector<int32_t>> input{
            {5,  1,  9,  11},
            {2,  4,  8,  10},
            {13, 3,  6,  7},
            {15, 14, 12, 16}
    };
    const vector<vector<int32_t>> result{
            {15, 13, 2,  5},
            {14, 3,  4,  1},
            {12, 6,  8,  9},
            {16, 7,  10, 11}
    };
    Solution solution;
    solution.rotate(input);
    CHECK_THAT(result, Equals(input));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_48_TEST_HPP
