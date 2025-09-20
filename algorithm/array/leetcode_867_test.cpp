// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
//@Tag array
//@Tag 数组
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_867_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_867_TEST_HPP

#include <catch_main.hpp>
#include <vector>
#include "leetcode_867.cpp"

namespace leetcode_867 {

using Catch::Matchers::Equals;

TEST_CASE("test case 1 {test_867}", "{test_867}") {
    Solution solution;
    const vector<vector<int32_t>> inputs{{{1, 2, 3},
                                          {4, 5, 6},
                                          {7, 8, 9}}};
    const vector<vector<int32_t>> result{{{1, 4, 7},
                                          {2, 5, 8},
                                          {3, 6, 9}}};
    CHECK_THAT(result, Equals(solution.transpose(inputs)));
}

TEST_CASE("test case 2 {test_867}", "{test_867}") {
    Solution solution;
    const vector<vector<int32_t>> inputs{{1, 2, 3},
                                         {4, 5, 6}};
    const vector<vector<int32_t>> result{{1, 4},
                                         {2, 5},
                                         {3, 6}};
    CHECK_THAT(result, Equals(solution.transpose(inputs)));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_867_TEST_HPP
