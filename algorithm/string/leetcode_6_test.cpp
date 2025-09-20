// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag string
//@Tag 字符串
//@Tag 模仿
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_6_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_6_TEST_HPP

#include "leetcode_6.cpp"
#include <catch_main.hpp>
#include <string>
#include <cstdint>

namespace leetcode_6 {

TEST_CASE("test basic [test_6]", "[test_6]") {
    Solution solution;
    CHECK(solution.convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
    CHECK(solution.convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI");
    CHECK(solution.convert("A", 1) == "A");
    CHECK(solution.convert("AB", 2) == "AB");
    CHECK(solution.convert("ABC", 3) == "ABC");
    CHECK(solution.convert("ABCD", 4) == "ABCD");
    CHECK(solution.convert("ABCDE", 4) == "ABCED");
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_6_TEST_HPP
