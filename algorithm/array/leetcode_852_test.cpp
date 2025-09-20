// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_852_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_852_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_852.cpp"
#include <vector>

namespace leetcode_852 {
TEST_CASE("test case 1 [test_852]", "[test_852]") {
    Solution solution;
    const vector<int32_t> inputs{0, 1, 0};
    static constexpr const auto result{1};
    CHECK(result == solution.peakIndexInMountainArray(inputs));
}

TEST_CASE("test case 2 [test_852]", "[test_852]") {
    Solution solution;
    const vector<int32_t> inputs{0, 2, 1, 0};
    static constexpr const auto result{1};
    CHECK(result == solution.peakIndexInMountainArray(inputs));
}

TEST_CASE("test case 3 [test_852]", "[test_852]") {
    Solution solution;
    const vector<int32_t> inputs{0, 10, 5, 2};
    static constexpr const auto result{1};
    CHECK(result == solution.peakIndexInMountainArray(inputs));
}

TEST_CASE("test case 4 [test_852]", "[test_852]") {
    Solution solution;
    const vector<int32_t> inputs{3, 4, 5, 1};
    static constexpr const auto result{2};
    CHECK(result == solution.peakIndexInMountainArray(inputs));
}

TEST_CASE("test case 5 [test_852]", "[test_852]") {
    Solution solution;
    const vector<int32_t> inputs{24, 69, 100, 99, 79, 78, 67, 36, 26, 19};
    static constexpr const auto result{2};
    CHECK(result == solution.peakIndexInMountainArray(inputs));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_852_TEST_HPP
