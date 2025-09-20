// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag string
//@Tag 字符串
//@Tag 模拟
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_13_TEST_CPP
#define ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_13_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_13.cpp"
#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>

namespace leetcode_13 {

TEST_CASE("test case 1 [test_13]", "[test_13]") {
    Solution solution;
    CHECK(solution.romanToInt("III") == 3);
}

TEST_CASE("test case 2 [test_13]", "[test_13]") {
    Solution solution;
    CHECK(solution.romanToInt("IV") == 4);
}

TEST_CASE("test case 3 [test_13]", "[test_13]") {
    Solution solution;
    CHECK(solution.romanToInt("IX") == 9);
}

TEST_CASE("test case 4 [test_13]", "[test_13]") {
    Solution solution;
    CHECK(solution.romanToInt("LVIII") == 58);
}

TEST_CASE("test case 5 [test_13]", "[test_13]") {
    Solution solution;
    CHECK(solution.romanToInt("MCMXCIV") == 1994);
}

TEST_CASE("test case 6 [test_13]", "[test_13]") {
    Solution solution;
    CHECK(solution.romanToInt(
            "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMDXIV") ==
          114514);
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_13_TEST_CPP
