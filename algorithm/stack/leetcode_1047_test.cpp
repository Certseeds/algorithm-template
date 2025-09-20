// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_STACK_LEETCODE_1047_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_STACK_LEETCODE_1047_TEST_HPP

#include "leetcode_1047.cpp"
#include <catch_main.hpp>

namespace leetcode_1047 {

TEST_CASE("1 [test_1047]", "[test_1047]") {
    static constexpr const char *const input{"abbaca"};
    static constexpr const char *const result{"ca"};
    Solution solution;
    CHECK(result == solution.removeDuplicates(input));
}

TEST_CASE("2 [test_1047]", "[test_1047]") {
    static constexpr const char *const input{"114514"};
    static constexpr const char *const result{"4514"};
    Solution solution;
    CHECK(result == solution.removeDuplicates(input));
}

TEST_CASE("3 [test_1047]", "[test_1047]") {
    static constexpr const char *const input{"1919810"};
    static constexpr const char *const result{"1919810"};
    Solution solution;
    CHECK(result == solution.removeDuplicates(input));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_STACK_LEETCODE_1047_TEST_HPP
