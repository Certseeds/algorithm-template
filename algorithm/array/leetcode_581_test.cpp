// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_581_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_581_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include "leetcode_581.cpp"

namespace leetcode_581 {
using std::vector;

TEST_CASE("test case 1 [test_581]", "[test_581]") {
    vector<int32_t> input{1, 1, 4, 5, 1, 4};
    static constexpr const auto result{4};
    Solution solution;
    CHECK(result == solution.findUnsortedSubarray(input));
    CHECK(result == solution.findUnsortedSubarray2(input));
}

TEST_CASE("test case 2 [test_581]", "[test_581]") {
    vector<int32_t> input{2, 6, 4, 8, 10, 9, 15};
    static constexpr const auto result{5};
    Solution solution;
    CHECK(result == solution.findUnsortedSubarray(input));
    CHECK(result == solution.findUnsortedSubarray2(input));
}

TEST_CASE("test case 3 [test_581]", "[test_581]") {
    vector<int32_t> input{1, 2, 3, 4};
    static constexpr const auto result{0};
    Solution solution;
    CHECK(result == solution.findUnsortedSubarray(input));
    CHECK(result == solution.findUnsortedSubarray2(input));
}

TEST_CASE("test case 4 [test_581]", "[test_581]") {
    vector<int32_t> input{1};
    static constexpr const auto result{0};
    Solution solution;
    CHECK(result == solution.findUnsortedSubarray(input));
    CHECK(result == solution.findUnsortedSubarray2(input));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_581_TEST_HPP
