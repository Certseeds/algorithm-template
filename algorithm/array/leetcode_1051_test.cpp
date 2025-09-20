// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
//@Tag array
//@Tag 数组
//@Tag 排序
//@Tag 小规模数据集
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1051_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1051_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include "leetcode_1051.cpp"

namespace leetcode_1051 {
using std::vector;

TEST_CASE("test case 1-1 {test_1051}", "{test_1051}") {
    const vector<int32_t> input{1, 1, 4, 5, 1, 4};
    static constexpr const auto result{4};
    Solution solution;
    CHECK(result == solution.heightChecker(input));
    CHECK(result == solution.heightCheckerSmall(input));
}

TEST_CASE("test case 1-2 {test_1051}", "{test_1051}") {
    const vector<int32_t> input{5, 1, 2, 3, 4};
    static constexpr const auto result{5};
    Solution solution;
    CHECK(result == solution.heightChecker(input));
    CHECK(result == solution.heightCheckerSmall(input));
}

TEST_CASE("test case 1-3 {test_1051}", "{test_1051}") {
    const vector<int32_t> input{23, 52, 46, 7, 50, 87, 20, 32, 85, 65, 62, 34, 8, 86, 15, 66, 66, 30, 11, 96, 18, 26,
                                24, 10, 57, 13, 37, 69, 85, 6, 8, 17, 40, 88, 14, 72, 85, 51, 40, 38, 54, 65, 65, 27,
                                18, 59, 77, 12, 25, 46, 10, 19, 10, 28, 64, 79, 5, 88, 2, 1, 14, 50, 91, 34, 58, 32, 90,
                                67, 28, 81, 84, 76, 88, 45, 42, 54, 59, 56, 20, 6, 56, 51, 72, 69, 6, 48, 67, 68, 6, 10,
                                93, 69, 4, 29, 28};
    static constexpr const auto result{95};
    Solution solution;
    CHECK(result == solution.heightChecker(input));
    CHECK(result == solution.heightCheckerSmall(input));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1051_TEST_HPP
