// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag list
//@Tag 链表

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_9_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_9_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_9.cpp"

namespace leetcode_9 {

TEST_CASE("test case 1 [test_9]", "[test_9]") {
    static constexpr const auto input{121};
    Solution solution;
    CHECK(solution.isPalindrome(input));
}

TEST_CASE("test case 2 [test_9]", "[test_9]") {
    static constexpr const auto input{-121};
    Solution solution;
    CHECK_FALSE(solution.isPalindrome(input));
}

TEST_CASE("test case 3 [test_9]", "[test_9]") {
    static constexpr const auto input{120};
    Solution solution;
    CHECK_FALSE(solution.isPalindrome(input));
}

TEST_CASE("test case 4 [test_9]", "[test_9]") {
    static constexpr const auto input{10};
    Solution solution;
    CHECK_FALSE(solution.isPalindrome(input));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_9_TEST_HPP
