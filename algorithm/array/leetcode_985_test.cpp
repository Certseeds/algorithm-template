// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_985_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_985_TEST_HPP

#include <catch_main.hpp>
#include <vector>
#include "leetcode_985.cpp"

namespace leetcode_985 {
using Catch::Matchers::Equals;

TEST_CASE("test case 1 {test_985}", "{test_985}") {
    Solution solution;
    vector<int32_t> input{1, 2, 3, 4};
    const vector<vector<int32_t>> queries{
            {1,  0},
            {-3, 1},
            {-4, 0},
            {2,  3},
    };
    const vector<int32_t> result{8, 6, 2, 4};
    CHECK_THAT(result, Equals(solution.sumEvenAfterQueries(input, queries)));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_985_TEST_HPP
