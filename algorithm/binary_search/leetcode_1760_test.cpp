// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag array
//@Tag 数组
//@Tag binary search
//@Tag 二分
//@Level Mid
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_1760_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_1760_TEST_HPP

#include "leetcode_1760.cpp"
#include <catch_main.hpp>

namespace leetcode_1760 {
using std::vector;

TEST_CASE("1 [test_1760]", "[test_1760]") {
    const vector<int32_t> nums{9};
    constexpr const auto operations{3};
    constexpr const auto minResult{3};
    Solution solution;
    CHECK(minResult == solution.minimumSize(nums, operations));
}


TEST_CASE("2 [test_1760]", "[test_1760]") {
    const vector<int32_t> nums{2, 2, 4, 8};
    constexpr const auto operations{4};
    constexpr const auto minResult{2};
    Solution solution;
    CHECK(minResult == solution.minimumSize(nums, operations));
}
}

#endif //ALGORITHM_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_1760_TEST_HPP
