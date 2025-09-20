// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag list
//@Tag 链表

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_43_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_43_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_43.cpp"

namespace leetcode_43 {

TEST_CASE("1 [test _43]", "[test _43]") {
    const string num1{"9"};
    const string num2{"9"};
    const string result{"81"};
    Solution solution;
    CHECK(result == solution.multiply(num1, num2));
}

TEST_CASE("2 [test _43]", "[test _43]") {
    const string num1{"2"};
    const string num2{"3"};
    const string result{"6"};
    Solution solution;
    CHECK(result == solution.multiply(num1, num2));
}

TEST_CASE("3 [test _43]", "[test _43]") {
    const string num1{"123"};
    const string num2{"456"};
    const string result{"56088"};
    Solution solution;
    CHECK(result == solution.multiply(num1, num2));
}

TEST_CASE("4 [test _43]", "[test _43]") {
    const string num1{"114514"};
    const string num2{"1919810"};
    const string result{"219845122340"};
    Solution solution;
    CHECK(result == solution.multiply(num1, num2));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_43_TEST_HPP
