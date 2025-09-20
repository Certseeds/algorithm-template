// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag array
//@Tag 数组
//@Tag 哈希表
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_448_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_448_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include "leetcode_448.cpp"

namespace leetcode_448 {
using std::vector;

using Catch::Matchers::UnorderedEquals;

TEST_CASE("test case 1 [test_448]", "[test_448]") {
    const vector<int32_t> input{4, 3, 2, 7, 8, 2, 3, 1};
    const vector<int32_t> result{5, 6};
    Solution solution;
    CHECK_THAT(solution.findDisappearedNumbers(input), UnorderedEquals(result));
}

TEST_CASE("test case 2 [test_448]", "[test_448]") {
    const vector<int32_t> input{1, 1};
    const vector<int32_t> result{2};
    Solution solution;
    CHECK_THAT(solution.findDisappearedNumbers(input), UnorderedEquals(result));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_448_TEST_HPP
