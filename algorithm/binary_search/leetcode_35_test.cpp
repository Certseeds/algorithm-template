// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_35_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_35_TEST_HPP

#include "leetcode_35.cpp"
#include <catch_main.hpp>
// 实质上是寻找第一个大于等于target的数字的下标
// 如果目标不存在,则返回第一个大于其的位置减一

namespace binary_search::leetcode_35 {

TEST_CASE("test case 1", "[test leetcode_35]") {
    const vector<int32_t> input{1, 3, 5, 6};
    static constexpr const auto target{5}, result{2};
    Solution solution;
    CHECK(result == solution.searchInsert(input, target));
    CHECK(result == solution.searchInsert2(input, target));
}

TEST_CASE("test case 2", "[test leetcode_35]") {
    const vector<int32_t> input{1, 3, 5, 6};
    static constexpr const auto target{2}, result{1};
    Solution solution;
    CHECK(result == solution.searchInsert(input, target));
    CHECK(result == solution.searchInsert2(input, target));
}

TEST_CASE("test case 3", "[test leetcode_35]") {
    const vector<int32_t> input{1, 3, 5, 6};
    static constexpr const auto target{7}, result{4};
    Solution solution;
    CHECK(result == solution.searchInsert(input, target));
    CHECK(result == solution.searchInsert2(input, target));
}

TEST_CASE("test case 4", "[test leetcode_35]") {
    const vector<int32_t> input{1, 3, 5, 6};
    static constexpr const auto target{0}, result{0};
    Solution solution;
    CHECK(result == solution.searchInsert(input, target));
    CHECK(result == solution.searchInsert2(input, target));
}

TEST_CASE("test case 5", "[test leetcode_35]") {
    const vector<int32_t> input{1};
    static constexpr const auto target{0}, result{0};
    Solution solution;
    CHECK(result == solution.searchInsert(input, target));
    CHECK(result == solution.searchInsert2(input, target));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_35_TEST_HPP

