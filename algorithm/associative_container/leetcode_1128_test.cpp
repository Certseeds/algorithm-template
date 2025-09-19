// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag associative_container

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_1128_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_1128_TEST_HPP

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
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_1128_TEST_HPP
