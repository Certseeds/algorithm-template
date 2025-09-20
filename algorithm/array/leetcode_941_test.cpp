// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
//@Tag array
//@Tag

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_867_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_867_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_941.cpp"
#include <vector>

namespace leetcode_941 {
TEST_CASE("test case 1 {test_941}", "{test_941}") {
    Solution solution;
    const vector<int32_t> input{4, 5, 10, 7};
    CHECK(solution.validMountainArray(input));
}

TEST_CASE("test case 2 {test_941}", "{test_941}") {
    Solution solution;
    const vector<int32_t> input{0, 3, 2, 1};
    CHECK(solution.validMountainArray(input));
}

TEST_CASE("test case 3 {test_941}", "{test_941}") {
    Solution solution;
    const vector<int32_t> input{114, 514, 191};
    CHECK(solution.validMountainArray(input));
}

TEST_CASE("test case 4 {test_941}", "{test_941}") {
    Solution solution;
    const vector<int32_t> input{1, 8, 0};
    CHECK(solution.validMountainArray(input));
}

TEST_CASE("test case 5 {test_941}", "{test_941}") {
    Solution solution;
    const vector<int32_t> input{9, 1, 9};
    CHECK_FALSE(solution.validMountainArray(input));
}
}

#endif // ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_941_TEST_HPP
