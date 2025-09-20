// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag string
//@Tag 字符串
//@Tag 模拟
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_8_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_8_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_8.cpp"

namespace leetcode_8 {

TEST_CASE("1 [test_8]", "[test_8]") {
    Solution solution;
    CHECK(solution.myAtoi("42") == 42);
    CHECK(solution.myAtoi("65537") == 65537);
    CHECK(solution.myAtoi("114514") == 114514);
    CHECK(solution.myAtoi("1919810") == 1919810);
}

TEST_CASE("2 [test_8]", "[test_8]") {
    Solution solution;
    CHECK(solution.myAtoi("+42") == 42);
    CHECK(solution.myAtoi("+65537") == 65537);
    CHECK(solution.myAtoi("+114514") == 114514);
    CHECK(solution.myAtoi("+1919810") == 1919810);
}

TEST_CASE("3 [test_8]", "[test_8]") {
    Solution solution;
    CHECK(solution.myAtoi("-42") == -42);
    CHECK(solution.myAtoi("-65537") == -65537);
    CHECK(solution.myAtoi("-114514") == -114514);
    CHECK(solution.myAtoi("-1919810") == -1919810);
}

TEST_CASE("4 [test_8]", "[test_8]") {
    Solution solution;
    CHECK(solution.myAtoi("  -42") == -42);
    CHECK(solution.myAtoi("  -65537") == -65537);
    CHECK(solution.myAtoi("    -114514") == -114514);
    CHECK(solution.myAtoi("     -1919810") == -1919810);
}

TEST_CASE("5 [test_8]", "[test_8]") {
    Solution solution;
    CHECK(solution.myAtoi("114514 with meaningless words") == 114514);
    CHECK(solution.myAtoi("meaningless words with -65537") == 0);
    CHECK(solution.myAtoi("2147483647") == std::numeric_limits<int32_t>::max());
    CHECK(solution.myAtoi("-2147483648") == std::numeric_limits<int32_t>::min());
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_8_TEST_HPP
