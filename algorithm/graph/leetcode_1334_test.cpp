// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_GRAPH_LEETCODE_1334_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_GRAPH_LEETCODE_1334_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include "leetcode_1334.cpp"

namespace leetcode_1334 {
using std::vector;

using Catch::Matchers::UnorderedEquals;

TEST_CASE("basic tests [test_1334]", "[test_1334]") {
    Solution s;
    const vector<vector<int32_t>> vec{
            {0, 1, 3},
            {1, 2, 1},
            {1, 3, 4},
            {2, 3, 1},
    };
    constexpr const auto n{4}, distanceThreshold{4};
    CHECK(3 == s.findTheCity(n, vec, distanceThreshold));
}

TEST_CASE("basic tests 2 [test_1334]", "[test_1334]") {
    Solution s;
    const vector<vector<int32_t>> vec{
            {0, 1, 2},
            {0, 4, 8},
            {1, 2, 3},
            {1, 4, 2},
            {2, 3, 1},
            {3, 4, 1},
    };
    constexpr const auto n{5}, distanceThreshold{2};
    CHECK(0 == s.findTheCity(n, vec, distanceThreshold));
}

TEST_CASE("basic tests 3 [test_1334]", "[test_1334]") {
    Solution s;
    const vector<vector<int32_t>> vec{
            {0, 2, 3996},
            {0, 3, 7495},
            {0, 4, 5966},
            {0, 5, 3399},
            {0, 6, 6},
            {0, 7, 2904},
            {1, 2, 1079},
            {1, 4, 2262},
            {1, 5, 6327},
            {1, 6, 2458},
            {1, 7, 7782},
            {2, 6, 1390},
            {3, 4, 7284},
            {3, 7, 2336},
            {4, 5, 5055},
            {4, 6, 2857},
            {4, 7, 7558},
            {5, 7, 2870},
            {6, 7, 2202},
    };
    constexpr const auto n{8}, distanceThreshold{7937};
    CHECK(7 == s.findTheCity(n, vec, distanceThreshold));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_GRAPH_LEETCODE_1334_TEST_HPP
