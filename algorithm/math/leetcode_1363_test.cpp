
// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022 nanoseeds

*/
//@Tag 数学
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_1363_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_1363_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include "leetcode_1363.cpp"

namespace leetcode_1363 {
using Catch::Matchers::Equals;

TEST_CASE("1-1 [test_1363]", "[test_1363]") {
    const vector<int32_t> input{8, 1, 9};
    constexpr const char *const result{"981"};
    Solution solution;
    Optimize optimize;
    CHECK(result == solution.largestMultipleOfThree(input));
    CHECK(result == optimize.largestMultipleOfThree(input));
}

TEST_CASE("1-2 [test_1363]", "[test_1363]") {
    const vector<int32_t> input{8, 6, 7, 1, 0};
    constexpr const char *const result{"8760"};
    Solution solution;
    Optimize optimize;
    CHECK(result == solution.largestMultipleOfThree(input));
    CHECK(result == optimize.largestMultipleOfThree(input));
}

TEST_CASE("1-3 [test_1363]", "[test_1363]") {
    const vector<int32_t> input{1};
    constexpr const char *const result{""};
    Solution solution;
    Optimize optimize;
    CHECK(result == solution.largestMultipleOfThree(input));
    CHECK(result == optimize.largestMultipleOfThree(input));
}

TEST_CASE("1-4 [test_1363]", "[test_1363]") {
    const vector<int32_t> input{0, 0, 0, 0, 0, 0};
    constexpr const char *const result{"0"};
    Solution solution;
    Optimize optimize;
    CHECK(result == solution.largestMultipleOfThree(input));
    CHECK(result == optimize.largestMultipleOfThree(input));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_1363_TEST_HPP

