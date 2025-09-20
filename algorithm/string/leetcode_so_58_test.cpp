// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag string
//@Tag 字符串
//@Plan 剑指OfferII-I Day03
//@Plan 剑指OfferII-I Day13
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_SO_58_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_SO_58_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_so_58.cpp"
#include <string>

namespace leetcode_so_58 {

using Catch::Matchers::Equals;

TEST_CASE("2 [test_so_58 i]", "[test_so_58]") {
    Solution solution;
    static constexpr const char *const input{"  hello world!  "}, *const result{"world! hello"};
    CHECK_THAT(solution.reverseWords(input), Equals(result));
}

TEST_CASE("1 [test_so_58 i]", "[test_so_58]") {
    Solution solution;
    static constexpr const char *const input{"I am a aritist."}, *const result{"aritist. a am I"};
    CHECK_THAT(solution.reverseWords(input), Equals(result));
}

TEST_CASE("1 [test_so_58 ii]", "[test_so_58]") {
    Solution solution;
    static constexpr const char *const input{"abcdefg"}, *const result{"cdefgab"};
    static constexpr const auto n{2};
    CHECK_THAT(solution.reverseLeftWords(input, n), Equals(result));
}

TEST_CASE("2 [test_so_58 ii]", "[test_so_58]") {
    Solution solution;
    static constexpr const char *const input{"lrloseumgh"}, *const result{"umghlrlose"};
    static constexpr const auto n{6};
    CHECK_THAT(solution.reverseLeftWords(input, n), Equals(result));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_SO_58_TEST_HPP
