// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag array
//@Tag 数组
//@Tag 哈希表
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_219_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_219_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include "leetcode_219.cpp"

namespace leetcode_219 {
using std::vector;

TEST_CASE("test case 1 [test_219]", "[test_219]") {
    const vector<int32_t> input{1, 2, 3, 1};
    static constexpr const auto k{3};
    Solution solution;
    CHECK(solution.containsNearbyDuplicate(input, k));
}

TEST_CASE("test case 2 [test_219]", "[test_219]") {
    const vector<int32_t> input{1, 0, 1, 1};
    static constexpr const auto k{1};
    Solution solution;
    CHECK(solution.containsNearbyDuplicate(input, k));
}

TEST_CASE("test case 3 [test_219]", "[test_219]") {
    const vector<int32_t> input{1, 2, 3, 1, 2, 3};
    static constexpr const auto k{2};
    Solution solution;
    CHECK_FALSE(solution.containsNearbyDuplicate(input, k));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_219_TEST_HPP
