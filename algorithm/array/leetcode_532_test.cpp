// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag array
//@Tag 数组
//@Tag 暴力枚举
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_532_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_532_TEST_HPP

#include "leetcode_532.cpp"
#include <catch_main.hpp>

namespace leetcode_532 {

TEST_CASE("test case 1 [test_532]", "[test_532]") {
    auto sol = Solution();
    std::vector<int32_t> input{3, 1, 4, 1, 5};
    static constexpr const auto k{2}, result{2};
    CHECK(result == sol.findPairs(input, k));
}

TEST_CASE("test case 2 [test_532]", "[test_532]") {
    auto sol = Solution();
    std::vector<int32_t> input{3, 1, 4, 2, 5};
    static constexpr const auto k{1}, result{4};
    CHECK(result == sol.findPairs(input, k));
}

TEST_CASE("test case 3 [test_532]", "[test_532]") {
    auto sol = Solution();
    std::vector<int32_t> input{1, 3, 1, 5, 4};
    static constexpr const auto k{0}, result{1};
    CHECK(result == sol.findPairs(input, k));
}

TEST_CASE("test case 4 [test_532]", "[test_532]") {
    auto sol = Solution();
    std::vector<int32_t> input{1, 2, 4, 4, 3, 3, 0, 9, 2, 3};
    static constexpr const auto k{3}, result{2};
    CHECK(result == sol.findPairs(input, k));
}

TEST_CASE("test case 5 [test_532]", "[test_532]") {
    auto sol = Solution();
    std::vector<int32_t> input{-1, -2, -3};
    static constexpr const auto k{1}, result{2};
    CHECK(result == sol.findPairs(input, k));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_532_TEST_HPP
