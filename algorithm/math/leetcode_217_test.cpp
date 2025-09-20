// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag list
//@Tag 链表
//@Plan 数据结构入门 Day1
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_217_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_217_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_217.cpp"

namespace leetcode_217 {

TEST_CASE("1 [test_217]", "[test_217]") {
    const vector<int32_t> input{3, 4, 3};
    Solution solution;
    CHECK(solution.containsDuplicate(input));
}

TEST_CASE("2 [test_217]", "[test_217]") {
    const vector<int32_t> input{1, 0, 1, 1, 0, 1};
    Solution solution;
    CHECK(solution.containsDuplicate(input));
}

TEST_CASE("3 [test_217]", "[test_217]") {
    const vector<int32_t> input{1};
    Solution solution;
    CHECK_FALSE(solution.containsDuplicate(input));
}

TEST_CASE("4 [test_217]", "[test_217]") {
    const vector<int32_t> input{1, 1, 4, 5, 1, 4, 1, 9, 1};
    Solution solution;
    CHECK(solution.containsDuplicate(input));
}

TEST_CASE("5 [test_217]", "[test_217]") {
    const vector<int32_t> input{2, 2, 1, 1, 1, 2, 2};
    Solution solution;
    CHECK(solution.containsDuplicate(input));
}

TEST_CASE("6 [test_217]", "[test_217]") {
    const vector<int32_t> input{1, 2, 3, 4};
    Solution solution;
    CHECK_FALSE(solution.containsDuplicate(input));
}

TEST_CASE("7 [test_217]", "[test_217]") {
    const vector<int32_t> input{1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    Solution solution;
    CHECK(solution.containsDuplicate(input));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_217_TEST_HPP

