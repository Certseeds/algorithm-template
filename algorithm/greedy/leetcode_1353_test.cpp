// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag 贪心算法
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_1353_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_1353_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include "leetcode_1353.cpp"

namespace leetcode_1353 {

TEST_CASE("test case 1 [test_1353]", "[test_1353]") {
    const vector<vector<int32_t>> input{{1, 2},
                                        {2, 3},
                                        {3, 4}};
    constexpr const auto result{3};
    Solution solution;
    CHECK(result == solution.maxEvents(input));
}

TEST_CASE("test case 2 [test_1353]", "[test_1353]") {
    const vector<vector<int32_t>> input{{1, 2},
                                        {1, 2},
                                        {2, 3},
                                        {3, 4}};
    constexpr const auto result{4};
    Solution solution;
    CHECK(result == solution.maxEvents(input));
}

TEST_CASE("test case 3 [test_1353]", "[test_1353]") {
    const vector<vector<int32_t>> input{{1, 2},
                                        {1, 2},
                                        {3, 3},
                                        {1, 5},
                                        {1, 5}};
    constexpr const auto result{5};
    Solution solution;
    CHECK(result == solution.maxEvents(input));
}

TEST_CASE("test case 4 [test_1353]", "[test_1353]") {
    const vector<vector<int32_t>> input{{1, 1},
                                        {4, 5},
                                        {1, 4},
                                        {1, 9},
                                        {1, 9},
                                        {8, 10}};
    constexpr const auto result{6};
    Solution solution;
    CHECK(result == solution.maxEvents(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_1353_TEST_HPP
