// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
//@Tag array
//@Tag

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_867_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_867_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_922.cpp"
#include <vector>

namespace leetcode_922 {

void judgement(const vector<int32_t> &nums) {
    const auto nums_size{nums.size()};
    CHECK(nums_size % 2 == 0);
    for (size_t i{0}; i < nums_size; ++i) {
        CHECK(static_cast<bool>(nums[i] % 2) == static_cast<bool>( i % 2));
    }
}

TEST_CASE("test case 1 {test_922}", "{test_922}") {
    Solution solution;
    vector<int32_t> input{4, 2, 5, 7};
    judgement(solution.sortArrayByParityII(input));
}

TEST_CASE("test case 2 {test_922}", "{test_922}") {
    Solution solution;
    vector<int32_t> input{1, 1, 4, 5, 4, 4};
    judgement(solution.sortArrayByParityII(input));
}

TEST_CASE("test case 3 {test_922}", "{test_922}") {
    Solution solution;
    vector<int32_t> input{1, 9, 2, 9, 8, 1, 0, 0};
    judgement(solution.sortArrayByParityII(input));
}

TEST_CASE("test case 4 {test_922}", "{test_922}") {
    Solution solution;
    vector<int32_t> input{8, 5, 2, 7};
    judgement(solution.sortArrayByParityII(input));
}
}
#endif // ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_922_TEST_HPP
