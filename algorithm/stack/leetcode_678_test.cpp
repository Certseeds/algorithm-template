// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_678_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_678_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_678.cpp"

namespace leetcode_678 {

TEST_CASE("1 [test_678]", "[test_678]") {
    Solution solution;
    CHECK(solution.checkValidString("()"));
    CHECK(solution.checkValidString("(*)"));
    CHECK(solution.checkValidString("(*))"));
}

TEST_CASE("2 [test_678]", "[test_678]") {
    Solution solution;
    CHECK_FALSE(solution.checkValidString(
            "(((((*(((((*((**(((*)*((((**))*)*)))))))))((*(((((**(**)"));
    CHECK_FALSE(solution.checkValidString(
            "(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())"));
}

TEST_CASE("2-1 [test_678]", "[test_678]") {
    Solution solution;
    CHECK(solution.checkValidString2("()"));
    CHECK(solution.checkValidString2("(*)"));
    CHECK(solution.checkValidString2("(*))"));
}

TEST_CASE("2-2 [test_678]", "[test_678]") {
    Solution solution;
    CHECK_FALSE(solution.checkValidString2(
            "(((((*(((((*((**(((*)*((((**))*)*)))))))))((*(((((**(**)"));
    CHECK_FALSE(solution.checkValidString2(
            "(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())"));

}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_678_TEST_HPP
