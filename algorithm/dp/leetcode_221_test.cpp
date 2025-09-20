// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day16
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_221_TEST_CPP
#define ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_221_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_221.cpp"

namespace leetcode_221 {
using std::vector;

TEST_CASE("4 [test_221]", "[test_221]") {
    const vector<vector<char>> input{
            {'1', '1'},
            {'1', '1'},
    };
    static constexpr const auto result{4};
    Solution solution;
    CHECK(result == solution.maximalSquare(input));
    CHECK(result == solution.maximalSquare2(input));
}

TEST_CASE("1 [test_221]", "[test_221]") {
    const vector<vector<char>> input{
            {'1', '0', '1', '0', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '0', '1', '0'}
    };
    static constexpr const auto result{4};
    Solution solution;
    CHECK(result == solution.maximalSquare(input));
    CHECK(result == solution.maximalSquare2(input));
}

TEST_CASE("2 [test_221]", "[test_221]") {
    const vector<vector<char>> input{
            {'0', '1'},
            {'1', '0'},
    };
    static constexpr const auto result{1};
    Solution solution;
    CHECK(result == solution.maximalSquare(input));
    CHECK(result == solution.maximalSquare2(input));
}

TEST_CASE("3 [test_221]", "[test_221]") {
    const vector<vector<char>> input{{'0'},};
    static constexpr const auto result{0};
    Solution solution;
    CHECK(result == solution.maximalSquare(input));
    CHECK(result == solution.maximalSquare2(input));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_221_TEST_CPP
