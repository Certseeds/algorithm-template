// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_GRAPH_LEETCODE_797_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_GRAPH_LEETCODE_797_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include "leetcode_797.cpp"

namespace leetcode_797 {
using std::vector;

using Catch::Matchers::UnorderedEquals;

TEST_CASE("basic tests [test_797]", "[test_797]") {
    Solution s;
    const vector<vector<int32_t>> input{
            {4, 3, 1},
            {3, 2, 4},
            {3},
            {4},
            {}
    };
    const vector<vector<int32_t>> result{
            {0, 4},
            {0, 3, 4},
            {0, 1, 3, 4},
            {0, 1, 2, 3, 4},
            {0, 1, 4}
    };
    CHECK_THAT(result, UnorderedEquals(s.allPathsSourceTarget(input)));
    CHECK_THAT(result, UnorderedEquals(s.allPathsSourceTarget2(input)));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_GRAPH_LEETCODE_797_TEST_HPP
