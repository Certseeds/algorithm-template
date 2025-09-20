// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag string
//@Tag 字符串
//@Plan 数据结构入门 Day6

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_242_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_242_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_242.cpp"
#include <cassert>
#include <cstdint>
#include <string>

namespace leetcode_242 {

TEST_CASE("1 [test_242]", "[test_242]") {
    Solution solution;
    static constexpr const char *const s{"anagram"}, *const t{"nagaram"};
    CHECK(solution.isAnagram(s, t));
}

TEST_CASE("2 [test_242]", "[test_242]") {
    Solution solution;
    static constexpr const char *const s{"rat"}, *const t{"cat"};
    CHECK_FALSE(solution.isAnagram(s, t));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_242_TEST_HPP
