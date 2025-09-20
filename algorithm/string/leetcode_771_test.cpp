// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag string
//@Tag 字符串
//@Description 非常简单
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_771_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_771_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_771.cpp"
#include <string>

namespace leetcode_771 {

TEST_CASE("1 [test_771]", "[test_771]") {
    Solution solution;
    static constexpr const char *const jewels{"aA"}, *const stones{"aAAbbbb"};
    static constexpr const auto output{3};
    CHECK(output == solution.numJewelsInStones(jewels, stones));
}

TEST_CASE("2 [test_771]", "[test_771]") {
    Solution solution;
    static constexpr const char *const jewels{"z"}, *const stones{"ZZ"};
    static constexpr const auto output{0};
    CHECK(output == solution.numJewelsInStones(jewels, stones));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_771_TEST_HPP
