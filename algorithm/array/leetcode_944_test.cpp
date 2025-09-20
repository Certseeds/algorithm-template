// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
//@Tag array
//@Tag
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_944_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_944_TEST_HPP

#include <catch_main.hpp>
#include <vector>
#include <string>
#include <array>
#include "leetcode_944.cpp"

namespace leetcode_944 {
TEST_CASE("test case 1 {test_944}", "{test_944}") {
    Solution solution;
    static constexpr const std::array<const char *const, 3> input{
            "abc", "bce", "cae"
    };
    static constexpr const auto result{1};
    CHECK(result == solution.minDeletionSize({input.begin(), input.end()}));
}

TEST_CASE("test case 2 {test_944}", "{test_944}") {
    Solution solution;
    static constexpr const std::array<const char *const, 2> input{
            "a", "b"
    };
    static constexpr const auto result{0};
    CHECK(result == solution.minDeletionSize({input.begin(), input.end()}));
}

TEST_CASE("test case 3 {test_944}", "{test_944}") {
    Solution solution;
    static constexpr const std::array<const char *const, 3> input{
            "zyx", "wvu", "tsr"
    };
    static constexpr const auto result{3};
    CHECK(result == solution.minDeletionSize({input.begin(), input.end()}));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_944_TEST_HPP
