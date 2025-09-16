// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022 nanoseeds

*/
//@Tag 数学图像
//@Tag 归纳
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_1252_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_1252_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_1252.cpp"

namespace leetcode_1252 {

using Catch::Matchers::Equals;

TEST_CASE("1-1 [test_1252]", "[test_1252]") {
    constexpr const auto m{5}, n{6};
    const vector<vector<int32_t>> indices{{1, 1},
                                          {4, 5},
                                          {1, 4}};
    Solution solution;
    const auto result = solution.oddCells(m, n, indices);
    constexpr const auto output{15};
    CHECK(output == result);
}

TEST_CASE("1-2 [test_1252]", "[test_1252]") {
    constexpr const auto m{2}, n{3};
    const vector<vector<int32_t>> indices{{0, 1},
                                          {1, 1},
                                          {0, 1},
                                          {1, 1},
                                          {0, 1},
                                          {1, 1}};
    Solution solution;
    const auto result = solution.oddCells(m, n, indices);
    constexpr const auto output{6};
    CHECK(output == result);
}

TEST_CASE("1-3 [test_1252]", "[test_1252]") {
    constexpr const auto m{2}, n{2};
    const vector<vector<int32_t>> indices{{0, 0},
                                          {1, 1},
                                          {0, 0},
                                          {1, 1},
                                          {0, 0},
                                          {1, 1}};
    Solution solution;
    const auto result = solution.oddCells(m, n, indices);
    constexpr const auto output{0};
    CHECK(output == result);
}

TEST_CASE("2-1 [test_1252]", "[test_1252]") {
    constexpr const auto m{48}, n{37};
    const vector<vector<int32_t>> indices{{40, 5}};
    Solution solution;
    const auto result = solution.oddCells(m, n, indices);
    constexpr const auto output{83};
    CHECK(output == result);
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_1252_TEST_HPP

