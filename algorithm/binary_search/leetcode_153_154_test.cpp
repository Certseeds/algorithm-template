// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag array
//@Tag 数组
//@Tag binary search
//@Tag 二分
//@Level Mid
//@Sword-Offer 11
//@Plan 剑指OfferII-I Day05
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_153_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_153_TEST_HPP

#include "leetcode_153_154.cpp"
#include <catch_main.hpp>

namespace leetcode_153 {
using std::vector;
using leetcode_154::Solution;

TEST_CASE("1 [test_153]", "[test_153]") {
    const vector<int32_t> input{3, 4, 5, 1, 2};
    static constexpr const auto result{1};
    Solution solution;
    CHECK(result == solution.findMin(input));
}

TEST_CASE("2 [test_153]", "[test_153]") {
    const vector<int32_t> input{4, 5, 6, 7, 0, 1, 2};
    static constexpr const auto result{0};
    Solution solution;
    CHECK(result == solution.findMin(input));
}

TEST_CASE("3 [test_153]", "[test_153]") {
    const vector<int32_t> input{11, 13, 15, 17};
    static constexpr const auto result{11};
    Solution solution;
    CHECK(result == solution.findMin(input));
}

TEST_CASE("test case 4 [test_153]", "[test_153]") {
    const vector<int32_t> input{1, 2, 5};
    static constexpr const auto result{1};
    Solution solution;
    CHECK(result == solution.findMin(input));
}

TEST_CASE("test case 5 [test_153]", "[test_153]") {
    const vector<int32_t> input{2, 114, 514, 0, 1};
    static constexpr const auto result{0};
    Solution solution;
    CHECK(result == solution.findMin(input));
}
}

namespace leetcode_154 {
using std::vector;

TEST_CASE("test case 2 [test_154]", "[test_154]") {
    const vector<int32_t> input{2, 2, 2, 0, 1};
    static constexpr const auto result{0};
    Solution solution;
    CHECK(result == solution.findMin(input));
}
}

#endif //ALGORITHM_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_153_TEST_HPP
