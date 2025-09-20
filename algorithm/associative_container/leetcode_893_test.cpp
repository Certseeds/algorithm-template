// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag associative_container
//@Tag arrays as hashmap
//@Tag 自定义hash函数
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_893_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_893_TEST_HPP

#include "leetcode_893.cpp"
#include <catch_main.hpp>

namespace leetcode_893 {

TEST_CASE("test case 1 {test_893}", "{test_893}") {
    static constexpr const std::array<const char *const, 6> input{"abc", "deq", "mee", "aqq", "dkd", "ccc"};
    static constexpr const auto result{6};
    Solution solution;
    CHECK(result == solution.numSpecialEquivGroups({input.cbegin(), input.cend()}));
}

TEST_CASE("test case 2 {test_893}", "{test_893}") {
    static constexpr const std::array<const char *const, 6> input{"abcd", "cdab", "cbad", "xyzz", "zzxy", "zzyx"};
    static constexpr const auto result{3};
    Solution solution;
    CHECK(result == solution.numSpecialEquivGroups({input.cbegin(), input.cend()}));
}

TEST_CASE("test case 3 {test_893}", "{test_893}") {
    static constexpr const std::array<const char *const, 6> input{"abc", "acb", "bac", "bca", "cab", "cba"};
    static constexpr const auto result{3};
    Solution solution;
    CHECK(result == solution.numSpecialEquivGroups({input.cbegin(), input.cend()}));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_893_TEST_HPP
