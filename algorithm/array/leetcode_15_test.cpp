// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag array
//@Tag 数组

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_15_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_15_TEST_HPP

#include "leetcode_15.cpp"
#include <catch_main.hpp>

namespace leetcode_15 {
using std::vector;

using Catch::Matchers::UnorderedEquals;

TEST_CASE("1 [test_15]", "[test_15]") {
    vector<int32_t> nums{-4, -1, -1, 0, 1, 2};
    auto clas = Solution();
    auto output = clas.threeSum(nums);
    const vector<vector<int32_t>> results{{-1, 0,  1},
                                          {-1, -1, 2}};
    CHECK_THAT(output, UnorderedEquals(results));
}

TEST_CASE("2 [test_15]", "[test_15]") {
    vector<int32_t> nums{};
    auto clas = Solution();
    auto output = clas.threeSum(nums);
    const vector<vector<int32_t>> results{};
    CHECK_THAT(output, UnorderedEquals(results));
}

TEST_CASE("3 [test_15]", "[test_15]") {
    vector<int32_t> nums{0};
    auto clas = Solution();
    auto output = clas.threeSum(nums);
    const vector<vector<int32_t>> results{};
    CHECK_THAT(output, UnorderedEquals(results));
}

TEST_CASE("8 [test_15]", "[test_15]") {
    vector<int32_t> nums{0, 0, 0};
    auto clas = Solution();
    auto output = clas.threeSum(nums);
    const vector<vector<int32_t>> results{{0, 0, 0}};
    CHECK_THAT(output, UnorderedEquals(results));
}

TEST_CASE("4 [test_15]", "[test_15]") {
    vector<int32_t> nums{-1, 0, 1, 2, -1, -4};
    auto clas = Solution();
    auto output = clas.threeSum(nums);
    const vector<vector<int32_t>> results{{-1, 0,  1},
                                          {-1, -1, 2}};
    CHECK_THAT(output, UnorderedEquals(results));
}

TEST_CASE("5 [test_15]", "[test_15]") {
    vector<int32_t> nums{};
    auto clas = Solution();
    auto output = clas.threeSum(nums);
    const vector<vector<int32_t>> results{};
    CHECK_THAT(output, UnorderedEquals(results));
}

TEST_CASE("6 [test_15]", "[test_15]") {
    vector<int32_t> nums{0};
    auto clas = Solution();
    auto output = clas.threeSum(nums);
    const vector<vector<int32_t>> results{};
    CHECK_THAT(output, UnorderedEquals(results));
}

TEST_CASE("7 [test_15]", "[test_15]") {
    vector<int32_t> nums{0, 0, 0};
    auto clas = Solution();
    auto output = clas.threeSum(nums);
    const vector<vector<int32_t>> results{{0, 0, 0}};
    CHECK_THAT(output, UnorderedEquals(results));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_15_TEST_HPP
