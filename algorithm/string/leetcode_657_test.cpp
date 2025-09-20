// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag string
//@Tag 字符串
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_657_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_657_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_657.cpp"
#include <string>

namespace leetcode_657 {

TEST_CASE("1 [test_657]", "[test_657]") {
    Solution solution;
    static constexpr const char *const input{"UD"};
    CHECK(solution.judgeCircle(input));
}

TEST_CASE("2 [test_657]", "[test_657]") {
    Solution solution;
    static constexpr const char *const input{"LL"};
    CHECK_FALSE(solution.judgeCircle(input));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_657_TEST_HPP
