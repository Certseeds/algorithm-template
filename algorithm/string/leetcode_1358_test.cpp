// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag string
//@Tag 字符串

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_1358_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_1358_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_1358.cpp"
#include <cstdint>
#include <cstddef>
#include <string>

namespace leetcode_1358 {

TEST_CASE("1 [test_1358]", "[test_1358]") {
    Solution solution;
    constexpr const char *const input{"abcabc"};
    constexpr const auto result{10};
    CHECK(result == solution.numberOfSubstrings(input));
}

TEST_CASE("2 [test_1358]", "[test_1358]") {
    Solution solution;
    constexpr const char *const input{"aaacb"};
    constexpr const auto result{3};
    CHECK(result == solution.numberOfSubstrings(input));
}

TEST_CASE("3 [test_1358]", "[test_1358]") {
    Solution solution;
    constexpr const char *const input{"abc"};
    constexpr const auto result{1};
    CHECK(result == solution.numberOfSubstrings(input));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_1358_TEST_HPP
