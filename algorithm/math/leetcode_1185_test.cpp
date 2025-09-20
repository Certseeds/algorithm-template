// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022 nanoseeds

*/
//@Tag 常识
//@Tag 暴力
//@Tag 先验知识
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_1185_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_1185_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_1185.cpp"

namespace leetcode_1185 {

using Catch::Matchers::Equals;

TEST_CASE("1-1 [test_1185]", "[test_1185]") {
    Solution solution;
    CHECK(weekStrs[5] == solution.dayOfTheWeek(1, 1, 1971));
}

TEST_CASE("1-2 [test_1185]", "[test_1185]") {
    Solution solution;
    CHECK(weekStrs[5] == solution.dayOfTheWeek(15, 1, 1971));
}

TEST_CASE("1-3 [test_1185]", "[test_1185]") {
    Solution solution;
    CHECK(weekStrs[1] == solution.dayOfTheWeek(1, 2, 1971));
}

TEST_CASE("2-1 [test_1185]", "[test_1185]") {
    Solution solution;
    CHECK(weekStrs[6] == solution.dayOfTheWeek(31, 8, 2019));
}

TEST_CASE("2-2 [test_1185]", "[test_1185]") {
    Solution solution;
    CHECK(weekStrs[0] == solution.dayOfTheWeek(18, 7, 1999));
}

TEST_CASE("2-3 [test_1185]", "[test_1185]") {
    Solution solution;
    CHECK(weekStrs[0] == solution.dayOfTheWeek(15, 8, 1993));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_1185_TEST_HPP

