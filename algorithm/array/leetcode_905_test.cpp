// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 双指针

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_905_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_905_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_905.cpp"
#include <vector>

using Catch::Matchers::Equals;
namespace leetcode_905 {
TEST_CASE("test case 1 {test_905}", "{test_905}") {
    Solution solution;
    vector<int32_t> input{3, 1, 2, 4};
    const vector<int32_t> result{4, 2, 1, 3};
    CHECK_THAT(result, Equals(solution.sortArrayByParity(input)));
}

TEST_CASE("test case 2 {test_905}", "{test_905}") {
    Solution solution;
    vector<int32_t> input{0};
    const vector<int32_t> result{0};
    CHECK_THAT(result, Equals(solution.sortArrayByParity(input)));
}
}

#endif // CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_905_TEST_HPP
