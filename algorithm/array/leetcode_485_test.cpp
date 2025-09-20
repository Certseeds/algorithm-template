// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag array
//@Tag 数组
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_485_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_485_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include "leetcode_485.cpp"

namespace leetcode_485 {
using std::vector;

TEST_CASE("test case 1 [test_485]", "[test_485]") {
    const vector<int32_t> input{1, 0, 1, 1, 0, 1};
    static constexpr const auto result{2};
    Solution solution;
    CHECK(result == solution.findMaxConsecutiveOnes(input));
}

TEST_CASE("test case 2 [test_485]", "[test_485]") {
    const vector<int32_t> input{1, 1, 0, 1, 1, 1};
    static constexpr const auto result{3};
    Solution solution;
    CHECK(result == solution.findMaxConsecutiveOnes(input));
}

TEST_CASE("test case 3 [test_485]", "[test_485]") {
    const vector<int32_t> input{1};
    static constexpr const auto result{1};
    Solution solution;
    CHECK(result == solution.findMaxConsecutiveOnes(input));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_485_TEST_HPP
