// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag array
//@Tag 数组
//@Tag 哈希表
//@Plan 数据结构入门 Day3
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_350_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_350_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include "leetcode_350.cpp"

namespace leetcode_350 {
using std::vector;

using Catch::Matchers::UnorderedEquals;

TEST_CASE("test case 1 [test_350]", "[test_350]") {
    const vector<int32_t> input1{1, 2, 2, 1}, input2{2, 2};
    const vector<int32_t> result{2, 2};
    Solution solution;
    CHECK_THAT(result, UnorderedEquals(solution.intersect(input1, input2)));
}

TEST_CASE("test case 2 [test_350]", "[test_350]") {
    const vector<int32_t> input1{4, 9, 5}, input2{9, 4, 9, 8, 4};
    const vector<int32_t> result{4, 9};
    Solution solution;
    CHECK_THAT(result, UnorderedEquals(solution.intersect(input1, input2)));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_350_TEST_HPP
