// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_766_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_766_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include "leetcode_766.cpp"

namespace leetcode_766 {
using std::vector;

TEST_CASE("test case 2 [test_766]", "[test_766]") {
    vector<vector<int32_t>> input{
            {1, 2, 3, 4},
            {5, 1, 2, 3},
            {9, 5, 1, 2},
    };
    Solution solution;
    CHECK(solution.isToeplitzMatrix(input));
}

TEST_CASE("test case 1 [test_766]", "[test_766]") {
    vector<vector<int32_t>> input{
            {1, 2},
            {2, 2},
    };
    Solution solution;
    CHECK_FALSE(solution.isToeplitzMatrix(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_766_TEST_HPP
