// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
//@Tag array
//@Tag 数组
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1329_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1329_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <string>

#include "leetcode_1329.cpp"

using Catch::Matchers::Equals;

namespace leetcode_1329 {
using std::vector;
using std::string;

TEST_CASE("test case 1-1 {test_1329}", "{test_1329}") {
    const vector<vector<int>> matrix{
            {5,  1,  4,},
            {1,  1,  4},
            {19, 19, 810,},
    };
    Solution solution;
    const auto result = solution.diagonalSort(matrix);
    const vector<vector<int>> output{
            {1,  1,  4},
            {1,  5,  4,},
            {19, 19, 810,},
    };
    CHECK_THAT(output, Equals(result));

}

TEST_CASE("test case 1-2 {test_1329}", "{test_1329}") {
    const vector<vector<int>> matrix{
            {1, 3,  2,},
            {4, 15, 6,},
            {4, 7,  6},
    };
    Solution solution;
    const auto result = solution.diagonalSort(matrix);
    const vector<vector<int>> output{
            {1, 3, 2,},
            {4, 6, 6,},
            {4, 7, 15},
    };
    CHECK_THAT(output, Equals(result));
}

TEST_CASE("test case 1-3 {test_1329}", "{test_1329}") {
    const vector<vector<int>> matrix{{3, 3, 1, 1},
                                     {2, 2, 1, 2},
                                     {1, 1, 1, 2}};
    Solution solution;
    const auto result = solution.diagonalSort(matrix);
    const vector<vector<int>> output{{1, 1, 1, 1},
                                     {1, 2, 2, 2},
                                     {1, 2, 3, 3}};
    CHECK_THAT(output, Equals(result));
}

TEST_CASE("test case 1-4 {test_1329}", "{test_1329}") {
    const vector<vector<int>> matrix{{11, 25, 66, 1,  69, 7},
                                     {23, 55, 17, 45, 15, 52},
                                     {75, 31, 36, 44, 58, 8},
                                     {22, 27, 33, 25, 68, 4},
                                     {84, 28, 14, 11, 5,  50}};
    Solution solution;
    const auto result = solution.diagonalSort(matrix);
    const vector<vector<int>> output{{5,  17, 4,  1,  52, 7},
                                     {11, 11, 25, 45, 8,  69},
                                     {14, 23, 25, 44, 58, 15},
                                     {22, 27, 31, 36, 50, 66},
                                     {84, 28, 75, 33, 55, 68}};
    CHECK_THAT(output, Equals(result));
}

TEST_CASE("test case 1-5 {test_1329}", "{test_1329}") {
    const vector<vector<int>> matrix{{3, 9},
                                     {2, 4},
                                     {1, 2},
                                     {9, 8},
                                     {7, 3}};
    Solution solution;
    const auto result = solution.diagonalSort(matrix);
    const vector<vector<int>> output{{3, 9},
                                     {2, 4},
                                     {1, 2},
                                     {3, 8},
                                     {7, 9}};
    CHECK_THAT(output, Equals(result));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1329_TEST_HPP
