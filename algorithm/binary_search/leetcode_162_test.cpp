// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanos

*/
//@Tag array
//@Tag 数组
//@Tag binary search
//@Tag 二分
//@Level Mid
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_162_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_162_TEST_HPP

#include "leetcode_162.cpp"
#include <catch_main.hpp>

namespace leetcode_162 {
using std::vector;
using Catch::Matchers::Contains;

TEST_CASE("1 [test_162]", "[test_162]") {
    const vector<int32_t> nums{1, 2, 3, 1};
    static constexpr const auto result{2};
    Solution solution;
    CHECK(result == solution.findPeakElement2(nums));
    CHECK(result == solution.findPeakElement(nums));
}

TEST_CASE("2 [test_162]", "[test_162]") {
    const vector<int32_t> nums{1, 2, 1, 3, 5, 6, 4};
    const vector<int32_t> resultList{1, 5};
    Solution solution;
    const auto v = solution.findPeakElement(nums);
    const auto v2 = solution.findPeakElement2(nums);
    CHECK_THAT(resultList, Contains<int32_t>(vector<int32_t>{v}));
    CHECK_THAT(resultList, Contains<int32_t>(vector<int32_t>{v2}));
}

TEST_CASE("3 [test_162]", "[test_162]") {
    const vector<int32_t> nums{1, 2, 3, 4, 3};
    static constexpr const auto result{3};
    Solution solution;
    CHECK(result == solution.findPeakElement(nums));
    CHECK(result == solution.findPeakElement2(nums));
}

TEST_CASE("4 [test_162]", "[test_162]") {
    const vector<int32_t> nums{1, 2, 1, 3, 5, 6, 4};
    const vector<int32_t> resultList{1, 5};
    Solution solution;
    const auto v = solution.findPeakElement(nums);
    const auto v2 = solution.findPeakElement2(nums);
    CHECK_THAT(resultList, Contains<int32_t>(vector<int32_t>{v}));
    CHECK_THAT(resultList, Contains<int32_t>(vector<int32_t>{v2}));
}
}

#endif //ALGORITHM_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_162_TEST_HPP
