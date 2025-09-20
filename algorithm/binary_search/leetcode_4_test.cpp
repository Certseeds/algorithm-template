// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanos

*/
//@Tag array
//@Tag 数组
//@Tag binary search
//@Tag 二分
//@Level Hard
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_4_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_4_TEST_HPP

#include "leetcode_4.cpp"
#include <catch_main.hpp>

namespace leetcode_4 {
using std::vector;

TEST_CASE("1 [test_4]", "[test_4]") {
    const vector<int32_t> num1{1, 3};
    const vector<int32_t> num2{2};
    Solution solution;
    CHECK(solution.findMedianSortedArraysOn(num1, num2) == 2);
    CHECK(solution.findMedianSortedArraysOlogN(num1, num2) == 2);
    CHECK(solution.findMedianSortedArraysOlogN2(num1, num2) == 2);
}

TEST_CASE("2 [test_4]", "[test_4]") {
    const vector<int32_t> num1{1, 3};
    const vector<int32_t> num2{2, 4};
    Solution solution;
    CHECK(solution.findMedianSortedArraysOn(num1, num2) == 2.5f);
    CHECK(solution.findMedianSortedArraysOlogN(num1, num2) == 2.5f);
    CHECK(solution.findMedianSortedArraysOlogN2(num1, num2) == 2.5f);
}

TEST_CASE("3 [test_4]", "[test_4]") {
    const vector<int32_t> num1{0, 0};
    const vector<int32_t> num2{0, 0};
    Solution solution;
    CHECK(solution.findMedianSortedArraysOn(num1, num2) == 0);
    CHECK(solution.findMedianSortedArraysOlogN(num1, num2) == 0);
    CHECK(solution.findMedianSortedArraysOlogN2(num1, num2) == 0);
}

TEST_CASE("4 [test_4]", "[test_4]") {
    const vector<int32_t> num1{1};
    const vector<int32_t> num2{};
    Solution solution;
    CHECK(solution.findMedianSortedArraysOn(num1, num2) == 1);
    CHECK(solution.findMedianSortedArraysOlogN(num1, num2) == 1);
    CHECK(solution.findMedianSortedArraysOlogN2(num1, num2) == 1);
}

TEST_CASE("5 [test_4]", "[test_4]") {
    const vector<int32_t> num1{2};
    const vector<int32_t> num2{};
    Solution solution;
    CHECK(solution.findMedianSortedArraysOn(num1, num2) == 2);
    CHECK(solution.findMedianSortedArraysOlogN(num1, num2) == 2);
    CHECK(solution.findMedianSortedArraysOlogN2(num1, num2) == 2);
}

TEST_CASE("6 [test_4]", "[test_4]") {
    const vector<int32_t> num1{2, 2, 4, 4};
    const vector<int32_t> num2{2, 2, 4, 4};
    Solution solution;
    CHECK(solution.findMedianSortedArraysOlogN(num1, num2) == 3.0f);
    CHECK(solution.findMedianSortedArraysOlogN2(num1, num2) == 3.0f);
}
}

#endif //ALGORITHM_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_4_TEST_HPP
