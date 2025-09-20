// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
//@Tag string
//@Tag 字符串
//@Plan 数据结构入门 Day6

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_383_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_383_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_383.cpp"
#include <cstdint>
#include <cstddef>
#include <string>

namespace leetcode_383 {

TEST_CASE("1 [test_383]", "[test_383]") {
    Solution solution;
    static constexpr const char *const inputR{"UD"}, *const inputM{"AUOKD"};
    CHECK(solution.canConstruct(inputR, inputM));
}

TEST_CASE("2 [test_383]", "[test_383]") {
    Solution solution;
    static constexpr const char *const inputR{"a"}, *const inputM{"b"};
    CHECK_FALSE(solution.canConstruct(inputR, inputM));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_383_TEST_HPP
