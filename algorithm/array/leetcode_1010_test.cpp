// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 数组
//@Tag 暴力解法
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1010_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1010_TEST_HPP

#include "leetcode_1010.cpp"
#include <catch_main.hpp>

namespace leetcode_1010 {
using std::vector;


TEST_CASE("test case 1 {test_1010}", "{test_1010}") {
    auto sol = Solution();
    const vector<int32_t> input{30, 20, 150, 100, 40};
    static constexpr const auto result{3};
    CHECK(result == sol.numPairsDivisibleBy60(input));
}

TEST_CASE("test case 2 {test_1010}", "{test_1010}") {
    auto sol = Solution();
    const vector<int32_t> input{60, 60, 60};
    static constexpr const auto result{3};
    CHECK(result == sol.numPairsDivisibleBy60(input));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1010_TEST_HPP
