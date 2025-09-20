// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_316_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_316_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_316.cpp"

namespace leetcode_316 {

using Catch::Matchers::Equals;

TEST_CASE("2 [test_316]", "[test_316]") {
    static constexpr const char *const input{"cbacdcbc"}, *const output{"acdb"};
    Solution solution;
    CHECK_THAT(output, Equals(solution.removeDuplicateLetters(input)));
}

TEST_CASE("1 [test_316]", "[test_316]") {
    static constexpr const char *const input{"bcabc"}, *const output{"abc"};
    Solution solution;
    CHECK_THAT(output, Equals(solution.removeDuplicateLetters(input)));
}

TEST_CASE("3 [test_316]", "[test_316]") {
    static constexpr const char *const input{"cdadabcc"}, *const output{"adbc"};
    Solution solution;
    CHECK_THAT(output, Equals(solution.removeDuplicateLetters(input)));
}

TEST_CASE("4 [test_316]", "[test_316]") {
    static constexpr const char *const input{"abcd"}, *const output{"abcd"};
    Solution solution;
    CHECK_THAT(output, Equals(solution.removeDuplicateLetters(input)));
}

TEST_CASE("5 [test_316]", "[test_316]") {
    static constexpr const char *const input{"bddbccd"}, *const output{"bcd"};
    Solution solution;
    CHECK_THAT(output, Equals(solution.removeDuplicateLetters(input)));
}

TEST_CASE("6 [test_316]", "[test_316]") {
    static constexpr const char *const input{"thesqtitxyetpxloeevdeqifkz"};
    Solution solution;
    solution.removeDuplicateLetters(input);
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_316_TEST_HPP
