// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
//@Tag array
//@Tag
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_977_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_977_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_977.cpp"
#include <vector>

namespace leetcode_977 {
using Catch::Matchers::Equals;

TEST_CASE("test case 1 {test_977}", "{test_977}") {
    Solution solution;
    const vector<int32_t> input{-4, -1, 0, 3, 10};
    const vector<int32_t> result{0, 1, 9, 16, 100};
    CHECK_THAT(result, Equals(solution.sortedSquares(input)));
}

TEST_CASE("test case 2 {test_977}", "{test_977}") {
    Solution solution;
    const vector<int32_t> input{-7, -3, 2, 3, 11};
    const vector<int32_t> result{4, 9, 9, 49, 121};
    CHECK_THAT(result, Equals(solution.sortedSquares(input)));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_977_TEST_HPP
