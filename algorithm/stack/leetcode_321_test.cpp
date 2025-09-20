// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag stack
//@Tag 栈
//@Tag 单调栈
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_STACK_LEETCODE_321_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_STACK_LEETCODE_321_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_321.cpp"

using std::vector;
using Catch::Matchers::Equals;
namespace leetcode_321 {

TEST_CASE("2 [test_321]", "[test_321]") {
    const vector<int32_t> nums1{6, 7};
    const vector<int32_t> nums2{6, 0, 7};
    static constexpr const auto k{5};
    const vector<int32_t> number{6, 7, 6, 0, 7};
    Solution solution;
    CHECK_THAT(number, Equals(solution.maxNumber(nums1, nums2, k)));
}

TEST_CASE("3 [test_321]", "[test_321]") {
    const vector<int32_t> nums1{3, 9};
    const vector<int32_t> nums2{8, 9};
    static constexpr const auto k{3};
    const vector<int32_t> number{9, 8, 9};
    Solution solution;
    CHECK_THAT(number, Equals(solution.maxNumber(nums1, nums2, k)));
}

TEST_CASE("1 [test_321]", "[test_321]") {
    const vector<int32_t> nums1{3, 4, 6, 5};
    const vector<int32_t> nums2{9, 1, 2, 5, 8, 3};
    static constexpr const auto k{5};
    const vector<int32_t> number{9, 8, 6, 5, 3};
    Solution solution;
    CHECK_THAT(number, Equals(solution.maxNumber(nums1, nums2, k)));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_STACK_LEETCODE_321_TEST_HPP
