// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag array
//@Tag 数组
//@Tag 双指针
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_17_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_17_TEST_HPP

#include "leetcode_17.cpp"
#include <catch_main.hpp>

namespace leetcode_17 {
using std::vector;
using std::string;

using Catch::Matchers::UnorderedEquals;

TEST_CASE("test case 1 [test_17]", "[test_17]") {
    auto clas = Solution();
    CHECK_THAT(clas.letterCombinations("23"),
               UnorderedEquals<string>({"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}));
}

TEST_CASE("test case 2 [test_17]", "[test_17]") {
    auto clas = Solution();
    CHECK_THAT(clas.letterCombinations(""),
               UnorderedEquals<string>({}));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_17_TEST_HPP
