// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
//@Tag array
//@Tag 数组
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_561_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_561_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_561.cpp"

namespace leetcode_561 {
TEST_CASE("test case 1 [test_561]", "[test_561]") {
    std::vector<int32_t> input{1, 1, 4, 5, 1, 4};
    static constexpr const auto result{6};
    Solution solution;
    CHECK(result == solution.arrayPairSum(input));
}

TEST_CASE("test case 2 [test_561]", "[test_561]") {
    std::vector<int32_t> input{1, 4, 3, 2};
    static constexpr const auto result{4};
    Solution solution;
    CHECK(result == solution.arrayPairSum(input));
}

TEST_CASE("test case 3 [test_561]", "[test_561]") {
    std::vector<int32_t> input{6, 2, 6, 5, 1, 2};
    static constexpr const auto result{9};
    Solution solution;
    CHECK(result == solution.arrayPairSum(input));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_561_TEST_HPP
