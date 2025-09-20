

// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022 nanoseeds

*/
//@Tag 数学
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_1402_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_1402_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include "leetcode_1402.cpp"

namespace leetcode_1402 {
using Catch::Matchers::Equals;

TEST_CASE("1-1 [test_1402]", "[test_1402]") {
    const vector<int32_t> input{1, 1, 4, 5, 1, 4};
    constexpr const auto result{72};
    Solution solution;
    CHECK(result == solution.maxSatisfaction(input));
}

TEST_CASE("1-2 [test_1402]", "[test_1402]") {
    const vector<int32_t> input{21, 4, 7};
    constexpr const auto result{81};
    Solution solution;
    CHECK(result == solution.maxSatisfaction(input));
}

TEST_CASE("1-3 [test_1402]", "[test_1402]") {
    const vector<int32_t> input{-1, 0, 5, -8, -9};
    constexpr const auto result{14};
    Solution solution;
    CHECK(result == solution.maxSatisfaction(input));
}

TEST_CASE("1-4 [test_1402]", "[test_1402]") {
    const vector<int32_t> input{2, 4, 3};
    constexpr const auto result{20};
    Solution solution;
    CHECK(result == solution.maxSatisfaction(input));
}

TEST_CASE("1-5 [test_1402]", "[test_1402]") {
    const vector<int32_t> input{-1, -4, -5};
    constexpr const auto result{0};
    Solution solution;
    CHECK(result == solution.maxSatisfaction(input));
}

TEST_CASE("1-6 [test_1402]", "[test_1402]") {
    const vector<int32_t> input{2, -2, -3, 1};
    constexpr const auto result{6};
    Solution solution;
    CHECK(result == solution.maxSatisfaction(input));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_1402_TEST_HPP

