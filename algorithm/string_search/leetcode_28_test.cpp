// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag string
//@Tag 字符串
//@Tag 烤馍片
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_28_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_28_TEST_HPP

#include <catch_main.hpp>
#include <string>
#include "leetcode_28.cpp"

namespace leetcode_28 {
using std::string;

using Catch::Matchers::UnorderedEquals;

TEST_CASE("1 [test_28]", "[test_28]") {
    Solution solution;
    CHECK(solution.strStr("hello", "ll") == 2);
    CHECK(solution.strStr("aaaaa", "bba") == -1);
    CHECK(solution.strStr("aaaaa", "") == 0);
    CHECK(solution.strStr("a", "a") == 0);
    CHECK(solution.strStr("mississippi", "issi") == 1);
    CHECK(solution.strStr("mississippi", "issip") == 4);
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_28_TEST_HPP
