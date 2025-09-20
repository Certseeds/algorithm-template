// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
//@Tag array
//@Tag 数组
//@Tag 双指针
//@Plan 剑指OfferII-I Day13
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_SO_21_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_SO_21_TEST_HPP

#include "leetcode_so_21.cpp"
#include <catch_main.hpp>

namespace leetcode_so_21 {
using Catch::Matchers::Equals;

TEST_CASE("test case 1 [test_so_21]", "[test_so_21]") {
    auto sol = Solution();
    std::vector<int32_t> input{1, 2, 3, 4};
    const std::vector<int32_t> output{1, 3, 2, 4};
    CHECK_THAT(output, Equals(sol.exchange(input)));
}

TEST_CASE("test case 2 [test_so_21]", "[test_so_21]") {
    auto sol = Solution();
    std::vector<int32_t> input{1, 3, 5};
    const std::vector<int32_t> output{1, 3, 5};
    CHECK_THAT(output, Equals(sol.exchange(input)));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_SO_21_TEST_HPP
