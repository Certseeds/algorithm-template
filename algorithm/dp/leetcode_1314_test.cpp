// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag DP
//@Tag 动态规划
//@Description 经典小学数学题,交叉部分算面积
//@Plan 动态规划入门 Day14
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_1314_TEST_CPP
#define ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_1314_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_1314.cpp"

namespace leetcode_1314 {
using std::vector;

using Catch::Matchers::Equals;

TEST_CASE("1 [test_1314]", "[test_1314]") {
    const vector<vector<int32_t>> input{{1, 2, 3},
                                        {4, 5, 6},
                                        {7, 8, 9}};
    static constexpr const auto k1{1};
    const vector<vector<int32_t>> result1{{12, 21, 16},
                                          {27, 45, 33,},
                                          {24, 39, 28}};
    Solution solution;
    CHECK_THAT(result1, Equals(solution.matrixBlockSum(input, k1)));
    static constexpr const auto k2{2};
    const vector<vector<int32_t>> result2{{45, 45, 45},
                                          {45, 45, 45,},
                                          {45, 45, 45}};
    CHECK_THAT(result2, Equals(solution.matrixBlockSum(input, k2)));
}

TEST_CASE("2 [test_1314]", "[test_1314]") {
    const vector<vector<int32_t>> input{{67, 64, 78},
                                        {99, 98, 38},
                                        {82, 46, 46},
                                        {6,  52, 55},
                                        {55, 99, 45}};
    static constexpr const auto k{1};
    const vector<vector<int32_t>> result{{328, 444, 278},
                                         {456, 618, 370},
                                         {383, 522, 335},
                                         {340, 486, 343},
                                         {212, 312, 251}};
    Solution solution;
    CHECK_THAT(result, Equals(solution.matrixBlockSum(input, k)));
}

}

#endif //ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_1314_TEST_CPP
