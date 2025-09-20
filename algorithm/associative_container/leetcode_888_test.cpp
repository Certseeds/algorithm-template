// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag associative_container
//@Tag hashset
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_888_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_888_TEST_HPP

#include "leetcode_888.cpp"
#include <catch_main.hpp>

namespace leetcode_888 {

using Catch::Matchers::Equals;

TEST_CASE("test case 1 {test_888}", "{test_888}") {
    const vector<int32_t> alice{1, 1};
    const vector<int32_t> tifa{2, 2};
    const vector<int32_t> cloud{1, 2};
    Solution solution;
    CHECK_THAT(cloud, Equals(solution.fairCandySwap(alice, tifa)));
}

TEST_CASE("test case 2 {test_888}", "{test_888}") {
    const vector<int32_t> alice{1, 1};
    const vector<int32_t> tifa{2, 3};
    const vector<int32_t> cloud{1, 2};
    Solution solution;
    CHECK_THAT(cloud, Equals(solution.fairCandySwap(alice, tifa)));
}

TEST_CASE("test case 3 {test_888}", "{test_888}") {
    const vector<int32_t> alice{2};
    const vector<int32_t> tifa{1, 3};
    const vector<int32_t> cloud{2, 3};
    Solution solution;
    CHECK_THAT(cloud, Equals(solution.fairCandySwap(alice, tifa)));
}

TEST_CASE("test case 4 {test_888}", "{test_888}") {
    const vector<int32_t> alice{1, 2, 5};
    const vector<int32_t> tifa{2, 4};
    const vector<int32_t> cloud{5, 4};
    Solution solution;
    CHECK_THAT(cloud, Equals(solution.fairCandySwap(alice, tifa)));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_888_TEST_HPP
