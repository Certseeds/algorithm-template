// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 双指针
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_986_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_986_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_986.cpp"
#include <vector>

namespace leetcode_986 {
using Catch::Matchers::Equals;

TEST_CASE("test case 1 {test_986}", "{test_986}") {
    Solution solution;
    const vector<vector<int32_t>> fst{{0,  2},
                                      {5,  10},
                                      {13, 23},
                                      {24, 25}};
    const vector<vector<int32_t>> snd{{1,  5},
                                      {8,  12},
                                      {15, 24},
                                      {25, 26}};
    const vector<vector<int32_t>> result{{1,  2},
                                         {5,  5},
                                         {8,  10},
                                         {15, 23},
                                         {24, 24},
                                         {25, 25}};
    CHECK_THAT(result, Equals(solution.intervalIntersection(fst, snd)));
}

TEST_CASE("test case 3 {test_986}", "{test_986}") {
    Solution solution;
    const vector<vector<int32_t>> fst{{17, 20}};
    const vector<vector<int32_t>> snd{{2,  3},
                                      {6,  8},
                                      {12, 14},
                                      {19, 20}};
    const vector<vector<int32_t>> result{{19, 20}};
    CHECK_THAT(result, Equals(solution.intervalIntersection(fst, snd)));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_986_TEST_HPP
