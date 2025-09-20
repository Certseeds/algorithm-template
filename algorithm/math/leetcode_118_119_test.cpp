// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag list
//@Tag 数学问题
//@Plan 动态规划入门 Day12
//@Plan 数据结构入门 Day4
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_118_119_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_118_119_TEST_HPP


#include <catch_main.hpp>
#include "leetcode_118_119.cpp"

namespace leetcode_118 {

using Catch::Matchers::Equals;

TEST_CASE("1 [test_118]", "[test_118]") {
    static constexpr const auto input{5};
    const vector<vector<int32_t>> result{
            {1},
            {1, 1},
            {1, 2, 1},
            {1, 3, 3, 1},
            {1, 4, 6, 4, 1},
    };
    Solution solution;
    CHECK_THAT(result, Equals(solution.generate(input)));
}


TEST_CASE("2 [test_118]", "[test_118]") {
    static constexpr const auto input{1};
    const vector<vector<int32_t>> result{
            {1},
    };
    Solution solution;
    CHECK_THAT(result, Equals(solution.generate(input)));
}
}
namespace leetcode_119 {

using Catch::Matchers::Equals;

TEST_CASE("1 [test_119]", "[test_119]") {
    static constexpr const auto input{3};
    const vector<int32_t> result{1, 3, 3, 1};
    Solution119 solution;
    CHECK_THAT(result, Equals(solution.getRow(input)));
    CHECK_THAT(result, Equals(solution.getRowN(input)));
}


TEST_CASE("2 [test_119]", "[test_119]") {
    static constexpr const auto input{1};
    const vector<int32_t> result{1, 1};
    Solution119 solution;
    CHECK_THAT(result, Equals(solution.getRow(input)));
    CHECK_THAT(result, Equals(solution.getRowN(input)));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_118_119_TEST_HPP
