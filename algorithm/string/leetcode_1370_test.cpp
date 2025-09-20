// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2023 nanoseeds

*/
//@Tag string
//@Tag 字符串

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_1370_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_1370_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_1370.cpp"
#include <cstdint>
#include <cstddef>
#include <string>

namespace leetcode_1370 {

TEST_CASE("1 [test_1370]", "[test_1370]") {
    Solution solution;
    constexpr const char *const input{"aaaabbbbcccc"};
    constexpr const char *const result{"abccbaabccba"};
    CHECK(result == solution.sortString(input));
}

TEST_CASE("2 [test_1370]", "[test_1370]") {
    Solution solution;
    constexpr const char *const input{"youknowtherulesandsodoi"};
    constexpr const char *const result{"adehiklnorstuwyusonedoo"};
    CHECK(result == solution.sortString(input));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_1370_TEST_HPP
