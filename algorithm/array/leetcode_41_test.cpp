// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag array
//@Tag 数组

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_41_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_41_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include "leetcode_41.cpp"

namespace leetcode_41 {
using std::vector;

TEST_CASE("basic test [test_41]", "[test_41]") {
    const vector<int32_t> cinput{1, 2, 0};
    vector<int32_t> input{cinput}, input2{cinput};
    const static constexpr auto result{3};
    Solution solution;
    CHECK(result == solution.firstMissingPositive(input));
    CHECK(result == solution.firstMissingPositive2(input2));
}

TEST_CASE("basic test 2 [test_41]", "[test_41]") {
    const vector<int32_t> cinput{3, 4, -1, 1};
    vector<int32_t> input{cinput}, input2{cinput};
    const static constexpr auto result{2};
    Solution solution;
    CHECK(result == solution.firstMissingPositive(input));
    CHECK(result == solution.firstMissingPositive2(input2));
}

TEST_CASE("basic test 3 [test_41]", "[test_41]") {
    const vector<int32_t> cinput{7, 8, 9, 11, 12};
    vector<int32_t> input{cinput}, input2{cinput};
    const static constexpr auto result{1};
    Solution solution;
    CHECK(result == solution.firstMissingPositive(input));
    CHECK(result == solution.firstMissingPositive2(input2));
}

TEST_CASE("basic test 4 [test_41]", "[test_41]") {
    const vector<int32_t> cinput{1};
    vector<int32_t> input{cinput}, input2{cinput};
    const static constexpr auto result{2};
    Solution solution;
    CHECK(result == solution.firstMissingPositive(input));
    CHECK(result == solution.firstMissingPositive2(input2));
}

TEST_CASE("basic test 6 [test_41]", "[test_41]") {
    const vector<int32_t> cinput{0, 1, 2};
    vector<int32_t> input{cinput}, input2{cinput};
    const static constexpr auto result{3};
    Solution solution;
    CHECK(result == solution.firstMissingPositive(input));
    CHECK(result == solution.firstMissingPositive2(input2));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_41_TEST_HPP
