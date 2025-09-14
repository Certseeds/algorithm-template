// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 数组
//@Tag 暴力解法
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1020_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1020_TEST_HPP

#include <catch_main.hpp>

#include "leetcode_1020.cpp"

namespace leetcode_1020 {
using std::vector;

TEST_CASE("test case 4 {test_1020}", "{test_1020}") {
    const vector<vector<int32_t>> input{
            {0},
            {1},
            {1},
            {0},
            {0}
    };
    static constexpr const auto result{0};
    Solution solution;
    CHECK(result == solution.numEnclaves(input));
}

TEST_CASE("test case 6 {test_1020}", "{test_1020}") {
    const vector<vector<int32_t>> input{{0, 1, 1, 0, 0}};
    static constexpr const auto result{0};
    Solution solution;
    CHECK(result == solution.numEnclaves(input));
}

TEST_CASE("test case 3 {test_1020}", "{test_1020}") {
    const vector<vector<int32_t>> input{
            {0, 1, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 0},
    };
    static constexpr const auto result{0};
    Solution solution;
    CHECK(result == solution.numEnclaves(input));
}

TEST_CASE("test case 2 {test_1020}", "{test_1020}") {
    const vector<vector<int32_t>> input{
            {0, 1, 1, 0},
            {1, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 1, 0},
    };
    static constexpr const auto result{0};
    Solution solution;
    CHECK(result == solution.numEnclaves(input));
}

TEST_CASE("test case 1 {test_1020}", "{test_1020}") {
    const vector<vector<int32_t>> input{
            {0, 0, 0, 0},
            {1, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0},
    };
    static constexpr const auto result{3};
    Solution solution;
    CHECK(result == solution.numEnclaves(input));
}

TEST_CASE("test case 5 {test_1020}", "{test_1020}") {
    const vector<vector<int32_t>> input{{0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1},
                                        {1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0},
                                        {0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0},
                                        {1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1},
                                        {0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0},
                                        {1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1},
                                        {0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0},
                                        {0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0},
                                        {1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0},
                                        {1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1}};
    static constexpr const auto result{7};
    Solution solution;
    CHECK(result == solution.numEnclaves(input));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1020_TEST_HPP
