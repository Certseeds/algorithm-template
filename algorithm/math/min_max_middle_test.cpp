// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag list
//@Tag 数学
//@Description 最大值
//@Description 最小值

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_MIN_MAX_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_MIN_MAX_HPP

#include <catch_main.hpp>
#include "min_max_middle.cpp"

namespace leetcode_minmax {

TEST_CASE("basic test [test_minmax]", "[test_minmax]") {
    const vector<int32_t> input{1, 2, 0};
    const static constexpr auto min{0}, max{2};
    Solution solution;
    CHECK(min == solution.minV(input));
    CHECK(max == solution.maxV(input));
    CHECK(minmax{min, max} == solution.minMaxV(input));
}

TEST_CASE("basic test 2 [test_minmax]", "[test_minmax]") {
    const vector<int32_t> input{3, 4, -1, 1};
    const static constexpr auto min{-1}, max{4};
    Solution solution;
    CHECK(min == solution.minV(input));
    CHECK(max == solution.maxV(input));
    CHECK(minmax{min, max} == solution.minMaxV(input));
}

TEST_CASE("basic test 3 [test_minmax]", "[test_minmax]") {
    const vector<int32_t> input{7, 8, 9, 11, 12};
    const static constexpr auto min{7}, max{12};
    Solution solution;
    CHECK(min == solution.minV(input));
    CHECK(max == solution.maxV(input));
    CHECK(minmax{min, max} == solution.minMaxV(input));
}

TEST_CASE("basic test 4 [test_minmax]", "[test_minmax]") {
    const vector<int32_t> input{1};
    const static constexpr auto min{1}, max{1};
    Solution solution;
    CHECK(min == solution.minV(input));
    CHECK(max == solution.maxV(input));
    CHECK(minmax{min, max} == solution.minMaxV(input));
}

TEST_CASE("basic test 5 [test_minmax]", "[test_minmax]") {
    const vector<int32_t> input{1, 2, 2, 1, 1, 3, 3, 4, 5};
    const static constexpr auto min{1}, max{5};
    Solution solution;
    CHECK(min == solution.minV(input));
    CHECK(max == solution.maxV(input));
    CHECK(minmax{min, max} == solution.minMaxV(input));
}

TEST_CASE("basic test 6 [test_minmax]", "[test_minmax]") {
    vector<int32_t> input{1, 1, 8, 1, 0, 4, 1, 9, 1, 9, 4, 1, 5};
    Solution solution;
    CHECK(9 == solution.partition(input, 0, 12));
}

TEST_CASE("basic test 7 [test_minmax]", "[test_minmax]") {
    vector<int32_t> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Solution solution;
    for (int32_t i{1}; i < 10; i++) {
        CHECK(i == solution.middleV(input, 0, 9, i));
    }
    for (int32_t i{1}; i < 9; i++) {
        CHECK(i == solution.middleV(input, 0, 8, i));
    }
}

TEST_CASE("basic test 8 [test_minmax]", "[test_minmax]") {
    vector<int32_t> input{1, 4, 5, 7, 8, 9, 6, 2, 3, 10};
    Solution solution;
    for (int32_t i{1}; i < 10; i++) {
        CHECK(i == solution.middleV(input, 0, 9, i));
    }
    for (int32_t i{1}; i < 9; i++) {
        CHECK(i == solution.middleV(input, 0, 8, i));
    }
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_MIN_MAX_HPP
