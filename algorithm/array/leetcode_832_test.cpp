// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_832_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_832_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_832.cpp"
#include <vector>

namespace leetcode_832 {
using Catch::Matchers::Equals;

TEST_CASE("test case 1 [test_832]", "[test_832]") {
    Solution solution;
    vector<vector<int32_t>> inputs{{1, 1, 0},
                                   {1, 0, 1},
                                   {0, 0, 0}};
    const vector<vector<int32_t>> result{
            {1, 0, 0},
            {0, 1, 0},
            {1, 1, 1},
    };
    CHECK_THAT(result, Equals(solution.flipAndInvertImage(inputs)));
}

TEST_CASE("test case 2 [test_832]", "[test_832]") {
    Solution solution;
    vector<vector<int32_t>> inputs{{1, 1, 0, 0},
                                   {1, 0, 0, 1},
                                   {0, 1, 1, 1},
                                   {1, 0, 1, 0}
    };
    const vector<vector<int32_t>> result{
            {1, 1, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 1},
            {1, 0, 1, 0}
    };
    CHECK_THAT(result, Equals(solution.flipAndInvertImage(inputs)));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_832_TEST_HPP
