// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag DFS
//@Tag 深度优先遍历
//@Plan 剑指OfferII-I Day13
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_GRAPH_LEETCODE_SO_13_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_GRAPH_LEETCODE_SO_13_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include "leetcode_so_13.cpp"

namespace leetcode_so_13 {

TEST_CASE("basic tests [test_so_13]", "[test_so_13]") {
    Solution s;
    static constexpr const auto m{2}, n{3}, k{1};
    static constexpr const auto result{3};
    CHECK(result == s.movingCount(m, n, k));
}

TEST_CASE("basic tests 2 [test_so_13]", "[test_so_13]") {
    Solution s;
    static constexpr const auto m{3}, n{1}, k{0};
    static constexpr const auto result{1};
    CHECK(result == s.movingCount(m, n, k));
}

TEST_CASE("basic tests 3 [test_so_13]", "[test_so_13]") {
    Solution s;
    static constexpr const auto m{1}, n{2}, k{1};
    static constexpr const auto result{2};
    CHECK(result == s.movingCount(m, n, k));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_GRAPH_LEETCODE_SO_13_TEST_HPP
