// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag string
//@Tag 字符串
//@Tag HashMap
//@Tag 哈希表
//@Tag 滑动窗口
//@Plan 数据结构入门 Day10
//@Plan 剑指OfferII-I Day10
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_3_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_3_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_3.cpp"
#include <cassert>
#include <cstdint>
#include <string>
#include <iostream>

namespace leetcode_3 {

void warpper(const string &s, int32_t length) {
    Solution solution;
    CHECK(length == solution.lengthOfLongestSubstring(s));
    CHECK(length == solution.lengthOfLongestSubstring2(s));
    CHECK(length == solution.lengthOfLongestSubstring3(s));
}

TEST_CASE("1 [test_3]", "[test_3]") {
    string str{"abcabcbb"};
    warpper(str, 3);
}

TEST_CASE("2 [test_3]", "[test_3]") {
    string str{"bbbbb"};
    warpper(str, 1);
}

TEST_CASE("3 [test_3]", "[test_3]") {
    string str{"pwwkew"};
    warpper(str, 3);
}

TEST_CASE("4 [test_3]", "[test_3]") {
    Solution solution;
    string str{"abba"};
    std::cout << solution.lengthOfLongestSubstring(str) << std::endl;
    warpper(str, 2);
}

TEST_CASE("5 [test_3]", "[test_3]") {
    string str{" "};
    warpper(str, 1);
}

TEST_CASE("6 [test_3]", "[test_3]") {
    string str(3, '3');
    warpper(str, 1);
}

TEST_CASE("7 [test_3]", "[test_3]") {
    string str{"tmmzuxt"};
    warpper(str, 5);
}

TEST_CASE("8 [test_3]", "[test_3]") {
    string str{"1145141919810"};
    warpper(str, 4);
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_3_TEST_HPP
