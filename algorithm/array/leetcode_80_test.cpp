// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag array
//@Tag 数组
//@Tag 双指针
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_80_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_80_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include "leetcode_80.cpp"

namespace leetcode_80 {
using std::vector;

using Catch::Matchers::Equals;

TEST_CASE("1 [test_80]", "[test_80]") {
    vector<int32_t> input{0, 0, 1, 1, 1, 1, 2, 3, 3};
    const vector<int32_t> result{0, 0, 1, 1, 2, 3, 3};
    Solution solution;
    const auto size = solution.removeDuplicates(input);
    input.resize(size);
    CHECK_THAT(input, Equals(result));
}

TEST_CASE("2 [test_80]", "[test_80]") {
    vector<int32_t> input{1, 1, 1, 2, 2, 3};
    const vector<int32_t> result{1, 1, 2, 2, 3};
    Solution solution;
    const auto size = solution.removeDuplicates(input);
    input.resize(size);
    CHECK_THAT(input, Equals(result));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_80_TEST_HPP
