// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag array
//@Tag 数组
//@Tag 暴力枚举
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_500_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_500_TEST_HPP

#include "leetcode_500.cpp"
#include <catch_main.hpp>

namespace leetcode_500 {
using Catch::Matchers::Equals;

TEST_CASE("test case 1 [test_500]", "[test_500]") {
    auto sol = Solution();
    static constexpr const std::array<const char *const, 6> input{"Metal", "Gear", "Soild", "Venom", "Phantom", "Pain"};
    const std::vector<std::string> result{};
    CHECK_THAT(result, Equals(sol.findWords({std::cbegin(input), std::cend(input)})));
}

TEST_CASE("test case 2 [test_500]", "[test_500]") {
    auto sol = Solution();
    static constexpr const std::array<const char *const, 4> input{"Hello", "Alaska", "Dad", "Peace"};
    const std::vector<std::string> result{"Alaska", "Dad"};
    CHECK_THAT(result, Equals(sol.findWords({std::cbegin(input), std::cend(input)})));
}

TEST_CASE("test case 3 [test_500]", "[test_500]") {
    auto sol = Solution();
    static constexpr const std::array<const char *const, 3> input{"omk", "adsdf", "sfd"};
    const std::vector<std::string> result{"adsdf", "sfd"};
    CHECK_THAT(result, Equals(sol.findWords({std::cbegin(input), std::cend(input)})));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_500_TEST_HPP
