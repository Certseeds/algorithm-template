// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag string
//@Tag 字符串
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_535_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_535_TEST_HPP

#include "leetcode_535.cpp"
#include <catch_main.hpp>
#include <string>

namespace leetcode_535 {

TEST_CASE("1 [test_535]", "[test_535]") {
    Solution solution;
    static constexpr const char *const input{"you know the rules and so do I"};
    CHECK(input == solution.decode(solution.encode(input)));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_535_TEST_HPP
