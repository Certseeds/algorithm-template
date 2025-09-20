// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag array
//@Tag 数组

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_56_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_56_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include "leetcode_56.cpp"

namespace leetcode_56 {
using std::vector;

using Catch::Matchers::Equals;

TEST_CASE("1 {test_56}", "{test_56}") {
    const vector<vector<int32_t>> inputs{{1,  3},
                                         {2,  6},
                                         {8,  10},
                                         {15, 18}};
    const vector<vector<int32_t>> result{{{1, 6}, {8, 10}, {15, 18}}};
    Solution solution;
    CHECK_THAT(solution.merge(inputs), Equals(result));
}

TEST_CASE("2 {test_56}", "{test_56}") {
    const vector<vector<int32_t>> inputs{{1, 4},
                                         {4, 5}};
    const vector<vector<int32_t>> result{{{1, 5}}};
    Solution solution;
    CHECK_THAT(solution.merge(inputs), Equals(result));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_56_TEST_HPP
