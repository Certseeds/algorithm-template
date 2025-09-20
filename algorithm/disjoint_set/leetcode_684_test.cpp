// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanos

*/
//@Tag disjoint_set
//@Tag 并查集
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_684_TEST_CPP
#define ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_684_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_684.cpp"

namespace leetcode_684 {
using std::vector;

using Catch::Matchers::Equals;

TEST_CASE("1 [test_684]", "[test_684]") {
    const vector<vector<int32_t>> edges{{1, 2},
                                        {1, 3},
                                        {2, 3}};
    const vector<int32_t> results{2, 3};
    Solution solution;
    CHECK_THAT(solution.findRedundantConnection(edges), Equals(results));
}

TEST_CASE("2 [test_684]", "[test_684]") {
    const vector<vector<int32_t>> edges{{1, 2},
                                        {2, 3},
                                        {3, 4},
                                        {1, 4},
                                        {1, 5}};
    const vector<int32_t> results{1, 4};
    Solution solution;
    CHECK_THAT(solution.findRedundantConnection(edges), Equals(results));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_684_TEST_CPP
