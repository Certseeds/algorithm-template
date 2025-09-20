// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_GRAPH_LEETCODE_743_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_GRAPH_LEETCODE_743_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include "leetcode_743.cpp"

namespace leetcode_743 {
using std::vector;

TEST_CASE("basic tests [test_743]", "[test_743]") {
    Solution s;
    const vector<vector<int32_t>> input{
            {2, 1, 1},
            {2, 3, 1},
            {3, 4, 1}
    };
    static constexpr const auto n{4}, k{2};
    static constexpr const auto result{2};
    CHECK(result == s.networkDelayTime(input, n, k));
}

TEST_CASE("basic tests 2[test_743]", "[test_743]") {
    Solution s;
    const vector<vector<int32_t>> input{
            {1, 2, 1},
    };
    static constexpr const auto n{2}, k{1};
    static constexpr const auto result{1};
    CHECK(result == s.networkDelayTime(input, n, k));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_GRAPH_LEETCODE_743_TEST_HPP
