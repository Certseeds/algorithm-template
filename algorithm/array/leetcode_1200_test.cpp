// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
//@Tag array
//@Tag 数组
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1200_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1200_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <string>
#include "leetcode_1200.cpp"

namespace leetcode_1200 {
using std::vector;
using std::string;

using Catch::Matchers::Equals;

TEST_CASE("test case 1-1 {test_1200}", "{test_1200}") {
    const vector<int32_t> distance{1, 4, 5,};
    const vector<vector<int32_t>> output{{4, 5}};
    Solution solution;
    CHECK_THAT(output, Equals(solution.minimumAbsDifference(distance)));
}

TEST_CASE("test case 1-2 {test_1200}", "{test_1200}") {
    const vector<int32_t> distance{1, 9, 8, 0};
    const vector<vector<int32_t>> output{{0, 1},
                                         {8, 9}};
    Solution solution;
    CHECK_THAT(output, Equals(solution.minimumAbsDifference(distance)));
}

TEST_CASE("test case 1-3 {test_1200}", "{test_1200}") {
    const vector<int32_t> distance{11, 45, 14, 191, 98, 10};
    const vector<vector<int32_t>> output{{10, 11}};
    Solution solution;
    CHECK_THAT(output, Equals(solution.minimumAbsDifference(distance)));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1200_TEST_HPP
