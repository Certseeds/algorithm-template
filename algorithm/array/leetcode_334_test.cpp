// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag array
//@Tag 数组
//@Tag DP
//@Plan 数据结构基础 Day4
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_334_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_334_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_334.cpp"

namespace leetcode_334 {
using std::vector;

using Catch::Matchers::UnorderedEquals;

TEST_CASE("test case 1 [test_334]", "[test_334]") {
    const vector<int32_t> input{1, 2, 3, 4, 5};
    Solution solution;
    CHECK(solution.increasingTriplet(input));
}

TEST_CASE("test case 2 [test_334]", "[test_334]") {
    const vector<int32_t> input{5, 4, 3, 2, 1};
    Solution solution;
    CHECK_FALSE(solution.increasingTriplet(input));
}

TEST_CASE("test case 3 [test_334]", "[test_334]") {
    const vector<int32_t> input{1, 1, 4, 5, 1, 4};
    Solution solution;
    CHECK(solution.increasingTriplet(input));
}

TEST_CASE("test case 4 [test_334]", "[test_334]") {
    const vector<int32_t> input{5, 1, 6};
    Solution solution;
    CHECK_FALSE(solution.increasingTriplet(input));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_334_TEST_HPP
