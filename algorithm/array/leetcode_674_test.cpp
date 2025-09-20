// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
//@Tag array
//@Tag 数组
//@Tag 暴力解法
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_674_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_674_TEST_HPP

#include <catch_main.hpp>

#include "leetcode_674.cpp"

namespace leetcode_674 {
using std::vector;

TEST_CASE("test case 1 [test_674]", "[test_674]") {
    vector<int32_t> input{4, 2, 3};
    static constexpr const auto result{2};
    Solution solution;
    CHECK(result == solution.findLengthOfLCIS(input));
}

TEST_CASE("test case 2 [test_674]", "[test_674]") {
    vector<int32_t> input{1, 3, 5, 4, 7};
    static constexpr const auto result{3};
    Solution solution;
    CHECK(result == solution.findLengthOfLCIS(input));
}

TEST_CASE("test case 3 [test_674]", "[test_674]") {
    vector<int32_t> input{2, 2, 2, 2, 2};
    static constexpr const auto result{1};
    Solution solution;
    CHECK(result == solution.findLengthOfLCIS(input));
}

TEST_CASE("test case 4 [test_674]", "[test_674]") {
    vector<int32_t> input{1};
    static constexpr const auto result{1};
    Solution solution;
    CHECK(result == solution.findLengthOfLCIS(input));
}

TEST_CASE("test case 5 [test_674]", "[test_674]") {
    vector<int32_t> input{};
    static constexpr const auto result{0};
    Solution solution;
    CHECK(result == solution.findLengthOfLCIS(input));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_674_TEST_HPP
