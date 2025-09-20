// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag string
//@Tag 字符串]
//@Sword-Offer 50
//@Plan 数据结构入门 Day6
//@Plan 剑指OfferII-I Day05
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_387_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_387_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_387.cpp"
#include <cstdint>
#include <cstddef>
#include <string>

namespace leetcode_387 {

TEST_CASE("1 [test_387]", "[test_387]") {
    Solution solution;
    static constexpr const char *const input{"UD"};
    static constexpr const auto result{0};
    CHECK(result == solution.firstUniqChar(input));
    CHECK(result == solution.firstUniqChar2(input));
}

TEST_CASE("2 [test_387]", "[test_387]") {
    Solution solution;
    static constexpr const char *const input{"leetcode"};
    static constexpr const auto result{0};
    CHECK(result == solution.firstUniqChar(input));
    CHECK(result == solution.firstUniqChar2(input));
}

TEST_CASE("3 [test_387]", "[test_387]") {
    Solution solution;
    static constexpr const char *const input{"loveleetcode"};
    static constexpr const auto result{2};
    CHECK(result == solution.firstUniqChar(input));
    CHECK(result == solution.firstUniqChar2(input));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_387_TEST_HPP
