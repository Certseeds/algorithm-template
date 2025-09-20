// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag array
//@Tag 数组
//@Tag binary search
//@Tag 二分
//@Level Mid
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_1608_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_1608_TEST_HPP

#include "leetcode_1608.cpp"
#include <catch_main.hpp>

namespace leetcode_1608 {
using std::vector;

TEST_CASE("1 [test_1608]", "[test_1608]") {
    const vector<int32_t> nums{3, 5};
    constexpr const auto result{2};
    Solution solution;
    CHECK(result == solution.specialArray(nums));
}

TEST_CASE("2 [test_1608]", "[test_1608]") {
    const vector<int32_t> nums{0, 4, 3, 4, 0};
    constexpr const auto result{3};
    Solution solution;
    CHECK(result == solution.specialArray(nums));
}

TEST_CASE("3 [test_1608]", "[test_1608]") {
    const vector<int32_t> nums{3, 6, 7, 7, 0};
    constexpr const auto result{-1};
    Solution solution;
    CHECK(result == solution.specialArray(nums));
}
}

#endif //ALGORITHM_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_1608_TEST_HPP
