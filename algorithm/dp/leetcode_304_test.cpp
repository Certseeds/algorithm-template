// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Description 经典小学数学题,交叉部分算面积
//@Plan 动态规划入门 Day14
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_304_TEST_CPP
#define ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_304_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_304.cpp"
#include <memory>

namespace leetcode_304 {
using std::vector;

using Catch::Matchers::Equals;

TEST_CASE("1 [test_304]", "[test_304]") {
    const vector<vector<int32_t>> input{
            {3, 0, 1, 4, 2},
            {5, 6, 3, 2, 1},
            {1, 2, 0, 1, 5},
            {4, 1, 0, 1, 7},
            {1, 0, 3, 0, 5}};
    const auto matrix{std::make_unique<NumMatrix>(input)};
    static constexpr const auto result1{8}, result2{11}, result3{12};
    CHECK(result1 == matrix->sumRegion(2, 1, 4, 3));
    CHECK(result2 == matrix->sumRegion(1, 1, 2, 2));
    CHECK(result3 == matrix->sumRegion(1, 2, 2, 4));
}

}

#endif //ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_304_TEST_CPP
