// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1108_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1108_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <string>
#include "leetcode_1108.cpp"

namespace leetcode_1108 {
using std::string;

TEST_CASE("test case 1-1 {test_1108}", "{test_1108}") {
    static constexpr const char *const input{"1.1.1.1"};
    static constexpr const char *const result{"1[.]1[.]1[.]1"};
    Solution solution;
    CHECK(result == solution.defangIPaddr(input));
}

TEST_CASE("test case 1-2 {test_1108}", "{test_1108}") {
    static constexpr const char *const input{"255.100.50.0"};
    static constexpr const char *const result{"255[.]100[.]50[.]0"};
    Solution solution;
    CHECK(result == solution.defangIPaddr(input));
}

TEST_CASE("test case 1-3 {test_1108}", "{test_1108}") {
    static constexpr const char *const input{"114.141.91.8"};
    static constexpr const char *const result{"114[.]141[.]91[.]8"};
    Solution solution;
    CHECK(result == solution.defangIPaddr(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1108_TEST_HPP
