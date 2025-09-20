// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2023  nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1365_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1365_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_1365.cpp"

namespace leetcode_1365 {
using std::vector;

using Catch::Matchers::Equals;

TEST_CASE("test case 1-1 {test_1365}", "{test_1365}") {
    const vector<int> nums{8, 1, 2, 2, 3};
    const vector<int> result{4, 0, 1, 1, 3};
    Solution solution;
    CHECK_THAT(result, Equals(solution.smallerNumbersThanCurrent(nums)));
}

TEST_CASE("test case 1-2 {test_1365}", "{test_1365}") {
    const vector<int> nums{6, 5, 4, 8};
    const vector<int> result{2, 1, 0, 3};
    Solution solution;
    CHECK_THAT(result, Equals(solution.smallerNumbersThanCurrent(nums)));
}

TEST_CASE("test case 1-3 {test_1365}", "{test_1365}") {
    const vector<int> nums{7, 7, 7, 7};
    const vector<int> result{0, 0, 0, 0};
    Solution solution;
    CHECK_THAT(result, Equals(solution.smallerNumbersThanCurrent(nums)));
}

TEST_CASE("test case 1-4 {test_1365}", "{test_1365}") {
    const vector<int> nums{0, 0, 0, 0};
    const vector<int> result{0, 0, 0, 0};
    Solution solution;
    CHECK_THAT(result, Equals(solution.smallerNumbersThanCurrent(nums)));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1365_TEST_HPP
