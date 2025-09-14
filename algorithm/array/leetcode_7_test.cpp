// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag array
//@Tag 数组

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_7_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_7_TEST_HPP

#include "leetcode_7.cpp"
#include <catch_main.hpp>

namespace leetcode_7 {
using std::vector;

TEST_CASE("1 [test_7]", "[test_7]") {
    auto clas = leetcode_7::Solution();
    CHECK(clas.reverse(123) == 321);
    CHECK(clas.reverse2(123) == 321);
    CHECK(clas.reverse3(123) == 321);
}

TEST_CASE("2 [test_7]", "[test_7]") {
    auto clas = leetcode_7::Solution();
    CHECK(clas.reverse(-123) == -321);
    CHECK(clas.reverse2(-123) == -321);
    CHECK(clas.reverse3(-123) == -321);
}

TEST_CASE("3 [test_7]", "[test_7]") {
    auto clas = leetcode_7::Solution();
    CHECK(clas.reverse(120) == 21);
    CHECK(clas.reverse2(120) == 21);
    CHECK(clas.reverse3(120) == 21);
}

TEST_CASE("4 [test_7]", "[test_7]") {
    auto clas = leetcode_7::Solution();
    CHECK(clas.reverse(0) == 0);
    CHECK(clas.reverse2(0) == 0);
    CHECK(clas.reverse3(0) == 0);
}

TEST_CASE("5 [test_7]", "[test_7]") {
    auto clas = leetcode_7::Solution();
    CHECK(clas.reverse(-2147483648) == 0);
    CHECK(clas.reverse2(-2147483648) == 0);
    CHECK(clas.reverse3(-2147483648) == 0);
}

TEST_CASE("6 [test_7]", "[test_7]") {
    auto clas = leetcode_7::Solution();
    CHECK(clas.reverse(1463847412) == 2147483641);
    CHECK(clas.reverse2(1463847412) == 2147483641);
    CHECK(clas.reverse3(1463847412) == 2147483641);
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_7_TEST_HPP
