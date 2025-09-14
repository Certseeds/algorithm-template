// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 数组
//@Plan 数据结构入门 Day4
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_566_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_566_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include "leetcode_566.cpp"

namespace leetcode_566 {
using std::vector;

using Catch::Matchers::Equals;

TEST_CASE("test case 1 [test_566]", "[test_566]") {
    vector<vector<int32_t>> input{{1, 2},
                                  {3, 4}};
    static constexpr const auto r{1}, c{4};
    const vector<vector<int32_t>> result{{1, 2, 3, 4}};
    Solution solution;
    CHECK_THAT(solution.matrixReshape(input, r, c), Equals(result));
}

TEST_CASE("test case 2 [test_566]", "[test_566]") {
    vector<vector<int32_t>> input{{1, 2},
                                  {3, 4}};
    static constexpr const auto r{2}, c{4};
    const vector<vector<int32_t>> result{input};
    Solution solution;
    CHECK_THAT(solution.matrixReshape(input, r, c), Equals(result));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_566_TEST_HPP
