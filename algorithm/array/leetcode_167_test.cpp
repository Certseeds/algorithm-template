// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag array
//@Tag 数组
//@Tag 双指针
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_167_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_167_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include "leetcode_167.cpp"

namespace leetcode_167 {
using std::vector;

using Catch::Matchers::Equals;

TEST_CASE("test case 1 [test_167]", "[test_167]") {
    const vector<int32_t> input{2, 7, 11, 15};
    static constexpr const auto target{9};
    const vector<int32_t> result{1, 2};
    Solution solution;
    CHECK_THAT(solution.twoSum(input, target), Equals(result));
    CHECK_THAT(solution.twoSum2(input, target), Equals(result));
}

TEST_CASE("test case 2 [test_167]", "[test_167]") {
    const vector<int32_t> input{2, 3, 4};
    static constexpr const auto target{6};
    const vector<int32_t> result{1, 3};
    Solution solution;
    CHECK_THAT(solution.twoSum(input, target), Equals(result));
    CHECK_THAT(solution.twoSum2(input, target), Equals(result));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_167_TEST_HPP
