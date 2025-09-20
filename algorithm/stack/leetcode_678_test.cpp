// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_STACK_LEETCODE_678_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_STACK_LEETCODE_678_TEST_HPP

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
#endif //ALGORITHM_TEMPLATE_ALGORITHM_STACK_LEETCODE_678_TEST_HPP
