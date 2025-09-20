// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag string
//@Tag 字符串
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_38_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_38_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_38.cpp"
#include <cassert>
#include <cstdint>
#include <string>

namespace leetcode_38 {

TEST_CASE("1 [test_38]", "[test_38]") {
    Solution solution;
    CHECK(solution.countAndSay(1) == "1");
    CHECK(solution.countAndSay(2) == "11");
    CHECK(solution.countAndSay(3) == "21");
    CHECK(solution.countAndSay(4) == "1211");
    CHECK(solution.countAndSay(5) == "111221");
    CHECK(solution.countAndSay(6) == "312211");
    CHECK(solution.countAndSay(7) == "13112221");
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_38_TEST_HPP
