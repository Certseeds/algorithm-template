// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_605_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_605_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include "leetcode_605.cpp"

namespace leetcode_605 {
using std::vector;

TEST_CASE("test case 1 [test_605]", "[test_605]") {
    vector<int32_t> input{1, 0, 0, 0, 1};
    static constexpr const auto n{1};
    Solution solution;
    CHECK(solution.canPlaceFlowers(input, n));
}

TEST_CASE("test case 2 [test_605]", "[test_605]") {
    vector<int32_t> input{1, 0, 0, 0, 1};
    static constexpr const auto n{2};
    Solution solution;
    CHECK_FALSE(solution.canPlaceFlowers(input, n));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_605_TEST_HPP
