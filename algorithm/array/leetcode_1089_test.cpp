// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 数组
//@Tag 反演
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1089_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1089_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include "leetcode_1089.cpp"

namespace leetcode_1089 {
using std::vector;

vector<int32_t> duplicateZerosConst(const vector<int32_t> &arr) {
    vector<int32_t> will_return{arr};
    Solution solution;
    solution.duplicateZeros(will_return);
    return will_return;
}

using Catch::Matchers::Equals;

TEST_CASE("test case 1-1 {test_1089}", "{test_1089}") {
    const vector<int32_t> input{1, 1, 4, 5, 1, 4};
    const vector<int32_t> result{1, 1, 4, 5, 1, 4};
    CHECK_THAT(result, Equals(duplicateZerosConst(input)));
}

TEST_CASE("test case 1-2 {test_1089}", "{test_1089}") {
    const vector<int32_t> input{1, 0, 2, 0, 3, 4, 0};
    const vector<int32_t> result{1, 0, 0, 2, 0, 0, 3};
    CHECK_THAT(result, Equals(duplicateZerosConst(input)));
}

TEST_CASE("test case 1-3 {test_1089}", "{test_1089}") {
    const vector<int32_t> input{1, 9, 1, 9, 8, 1, 0};
    const vector<int32_t> result{1, 9, 1, 9, 8, 1, 0};
    CHECK_THAT(result, Equals(duplicateZerosConst(input)));
}

TEST_CASE("test case 1-4 {test_1089}", "{test_1089}") {
    const vector<int32_t> input{8, 5, 0, 9, 0, 3, 4, 7};
    const vector<int32_t> result{8, 5, 0, 0, 9, 0, 0, 3};
    CHECK_THAT(result, Equals(duplicateZerosConst(input)));
}

TEST_CASE("test case 1-5 {test_1089}", "{test_1089}") {
    const vector<int32_t> input{0, 1, 7, 6, 0, 2, 0, 7};
    const vector<int32_t> result{0, 0, 1, 7, 6, 0, 0, 2};
    CHECK_THAT(result, Equals(duplicateZerosConst(input)));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1089_TEST_HPP
