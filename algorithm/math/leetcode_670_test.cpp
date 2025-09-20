// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag Math
//@Tag 数学

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_670_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_670_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include "leetcode_670.cpp"

namespace leetcode_670 {

TEST_CASE("1 [test_670]", "[test_670]") {
    static constexpr const auto input{2763};
    static constexpr const auto result{7263};
    Solution solution;
    CHECK(result == solution.maximumSwap(input));
    CHECK(result == solution.maximumSwap2(input));
}

TEST_CASE("2 [test_670]", "[test_670]") {
    static constexpr const auto input{9973};
    static constexpr const auto result{9973};
    Solution solution;
    CHECK(result == solution.maximumSwap(input));
    CHECK(result == solution.maximumSwap2(input));
}

TEST_CASE("3 [test_670]", "[test_670]") {
    static constexpr const auto input{114514};
    static constexpr const auto result{514114};
    Solution solution;
    CHECK(result == solution.maximumSwap(input));
    CHECK(result == solution.maximumSwap2(input));
}

TEST_CASE("4 [test_670]", "[test_670]") {
    static constexpr const auto input{1919810};
    static constexpr const auto result{9911810};
    Solution solution;
    CHECK(result == solution.maximumSwap(input));
    CHECK(result == solution.maximumSwap2(input));
}

TEST_CASE("5 [test_670]", "[test_670]") {
    static constexpr const auto input{99901};
    static constexpr const auto result{99910};
    Solution solution;
    CHECK(result == solution.maximumSwap(input));
    CHECK(result == solution.maximumSwap2(input));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_670_TEST_HPP

