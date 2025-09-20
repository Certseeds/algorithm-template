// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
//@Tag associative_container

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_1128_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_1128_TEST_HPP

#include "leetcode_1128.cpp"
#include <catch_main.hpp>

namespace leetcode_1128 {

TEST_CASE("test case 1 {test_1128}", "{test_1128}") {
    const vector<vector<int32_t>> input{{1, 2},
                                    {2, 1},
                                    {3, 4},
                                    {5, 6}};
    Solution solution;
    CHECK(1 == solution.numEquivDominoPairs(input));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_1128_TEST_HPP
