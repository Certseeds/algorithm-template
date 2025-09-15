// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022 nanos

*/
//@Tag array
//@Tag 数组
//@Tag binary search
//@Tag 二分
//@Tag 多重二分
//@Level Mid
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_1237_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_1237_TEST_HPP

#include "leetcode_1237.cpp"
#include <catch_main.hpp>

namespace leetcode_1237 {
using std::vector;
using CustomFunction = std::function<int32_t(int32_t x, int32_t y)>;
using Catch::Matchers::Equals;

TEST_CASE("1 [test_1237]", "[test_1237]") {
    const auto func = [](int32_t x, int32_t y) {
        return x + y;
    };
    static constexpr const auto z{5};
    Solution solution;
    const auto result = solution.findSolution(func, z);
    const vector<vector<int32_t>> output{{1, 4},
                                         {2, 3},
                                         {3, 2},
                                         {4, 1}};
    CHECK_THAT(output, Equals(result));
}

TEST_CASE("2 [test_1237]", "[test_1237]") {
    const auto func = [](int32_t x, int32_t y) {
        return x * y;
    };
    static constexpr const auto z{5};
    Solution solution;
    const auto result = solution.findSolution(func, z);
    const vector<vector<int32_t>> output{{1, 5}, // it's not the age of traditional addition
                                         {5, 1}};
    CHECK_THAT(output, Equals(result));
}

}

#endif //CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_1237_TEST_HPP
