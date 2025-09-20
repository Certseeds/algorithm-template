// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_867_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_867_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_908.cpp"
#include <vector>

namespace leetcode_908 {

TEST_CASE("test case 1 {test_908}", "{test_908}") {
    Solution solution;
    const vector<int32_t> input{1};
    static constexpr const auto k{0};
    static constexpr const auto result{0};
    CHECK(result == solution.smallestRangeI(input, k));
}

TEST_CASE("test case 2 {test_908}", "{test_908}") {
    Solution solution;
    const vector<int32_t> input{0, 10};
    static constexpr const auto k{2};
    static constexpr const auto result{6};
    CHECK(result == solution.smallestRangeI(input, k));
}

TEST_CASE("test case 3 {test_908}", "{test_908}") {
    Solution solution;
    const vector<int32_t> input{1, 3, 6};
    static constexpr const auto k{3};
    static constexpr const auto result{0};
    CHECK(result == solution.smallestRangeI(input, k));
}

TEST_CASE("test case 4 {test_908}", "{test_908}") {
    Solution solution;
    const vector<int32_t> input{2, 7, 2};
    static constexpr const auto k{1};
    static constexpr const auto result{3};
    CHECK(result == solution.smallestRangeI(input, k));
}
}

#endif // ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_908_TEST_HPP
