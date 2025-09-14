// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 数组
//@Plan 剑指OfferII-I Day16
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_SO_61_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_SO_61_TEST_HPP

#include "leetcode_so_61.cpp"
#include <catch_main.hpp>

namespace leetcode_so_61 {

TEST_CASE("test case 1 [test_so_61]", "[test_so_61]") {
    auto sol = Solution();
    const vector<int32_t> input{10, 2};
    CHECK_FALSE(sol.isStraight(input));
}

TEST_CASE("test case 2 [test_so_61]", "[test_so_61]") {
    auto sol = Solution();
    const vector<int32_t> input{1, 2, 3, 4, 5};
    CHECK(sol.isStraight(input));
}

TEST_CASE("test case 3 [test_so_61]", "[test_so_61]") {
    auto sol = Solution();
    const vector<int32_t> input{12, 13, 7, 10, 8};
    CHECK_FALSE(sol.isStraight(input));
}

TEST_CASE("test case 4 [test_so_61]", "[test_so_61]") {
    auto sol = Solution();
    const vector<int32_t> input{0, 0, 1, 2, 5};
    CHECK(sol.isStraight(input));
}

TEST_CASE("test case 5 [test_so_61]", "[test_so_61]") {
    auto sol = Solution();
    const vector<int32_t> input{0, 0, 2, 2, 5};
    CHECK_FALSE(sol.isStraight(input));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_SO_61_TEST_HPP
