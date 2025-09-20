// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag DFS
//@Tag 深度优先遍历
//@Plan 剑指OfferII-I Day13
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_GRAPH_LEETCODE_SO_12_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_GRAPH_LEETCODE_SO_12_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <string>
#include "leetcode_so_12.cpp"

namespace leetcode_so_12 {
using std::vector;
using std::string;

TEST_CASE("basic tests [test_so_12]", "[test_so_12]") {
    Solution s;
    const vector<vector<char>> input{
            {'a', 'b', 'c', 'e'},
            {'s', 'f', 'c', 's'},
            {'a', 'd', 'e', 'e'},
    };
    static constexpr const char *const word{"abcced"};
    CHECK(s.exist(input, word));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_GRAPH_LEETCODE_SO_12_TEST_HPP
