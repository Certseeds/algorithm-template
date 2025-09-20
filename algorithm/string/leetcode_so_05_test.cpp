// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag string
//@Tag 字符串
//@Plan 剑指OfferII-I Day03
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_SO_05_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_SO_05_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_so_05.cpp"
#include <string>

namespace leetcode_so_05 {

TEST_CASE("1 [test_so_05]", "[test_so_05]") {
    Solution solution;
    static constexpr const char *const input{"We are happy."}, *const result{"We%20are%20happy."};
    CHECK(result == solution.replaceSpace(input));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_SO_05_TEST_HPP
