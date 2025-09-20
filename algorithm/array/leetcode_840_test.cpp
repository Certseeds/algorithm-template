// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
//@Tag array
//@Tag 数组
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_840_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_840_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_840.cpp"
#include <vector>

namespace leetcode_840 {
TEST_CASE("test case 1 [test_840]", "[test_840]") {
    Solution solution;
    const vector<vector<int32_t>> inputs{{4, 3, 8, 4},
                                         {9, 5, 1, 9},
                                         {2, 7, 6, 2}};
    static constexpr const auto result{1};
    CHECK(result == solution.numMagicSquaresInside(inputs));
}

TEST_CASE("test case 2 [test_840]", "[test_840]") {
    Solution solution;
    const vector<vector<int32_t>> inputs{{8}};
    static constexpr const auto result{0};
    CHECK(result == solution.numMagicSquaresInside(inputs));
}

TEST_CASE("test case 3 [test_840]", "[test_840]") {
    Solution solution;
    const vector<vector<int32_t>> inputs{{1, 1, 4},
                                         {5, 1, 4}};
    static constexpr const auto result{0};
    CHECK(result == solution.numMagicSquaresInside(inputs));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_840_TEST_HPP
