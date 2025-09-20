// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag stack
//@Tag 栈
//@Tag 单调栈
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_STACK_LEETCODE_84_85_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_STACK_LEETCODE_84_85_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <limits>
#include <vector>
#include "leetcode_84_85.cpp"

using std::vector;
namespace leetcode_84 {

TEST_CASE("test case 1 [test_84]", "[test_84]") {
    const vector<int32_t> input{2, 1, 5, 6, 2, 3};
    static constexpr const auto result{10};
    Solution solution;
    CHECK(result == solution.largestRectangleArea(input));
}

TEST_CASE("test case 2 [test_84]", "[test_84]") {
    const vector<int32_t> input{4, 2, 0, 3, 2, 5};
    static constexpr const auto result{6};
    Solution solution;
    CHECK(result == solution.largestRectangleArea(input));
}

TEST_CASE("test case 3 [test_84]", "[test_84]") {
    const vector<int32_t> input{0, 1, 0, 3, 1, 0, 1, 3, 2, 1, 2, 1};
    static constexpr const auto result{6};
    Solution solution;
    CHECK(result == solution.largestRectangleArea(input));
}

TEST_CASE("test case 1 [test_85]", "[test_85]") {
    const vector<vector<char>> input{
            {'1', '0', '1', '0', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '0', '1', '1'},
    };
    static constexpr const auto result{6};
    Solution solution;
    CHECK(result == solution.maximalRectangle(input));
}

TEST_CASE("test case 2 [test_85]", "[test_85]") {
    const vector<vector<char>> input{};
    static constexpr const auto result{0};
    Solution solution;
    CHECK(result == solution.maximalRectangle(input));
}

TEST_CASE("test case 3 [test_85]", "[test_85]") {
    const vector<vector<char>> input{
            {'1'}
    };
    static constexpr const auto result{1};
    Solution solution;
    CHECK(result == solution.maximalRectangle(input));
}

TEST_CASE("test case 4 [test_85]", "[test_85]") {
    const vector<vector<char>> input{
            {'0', '0'}
    };
    static constexpr const auto result{0};
    Solution solution;
    CHECK(result == solution.maximalRectangle(input));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_STACK_LEETCODE_84_85_TEST_HPP
