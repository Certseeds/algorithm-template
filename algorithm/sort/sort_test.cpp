// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <catch_main.hpp>
#include "sort_wrapper.hpp"

using std::vector;
using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;

TEST_CASE("empty", "[sort]") {
    vector<int> nums{};
    vector<int> nums_result(nums);
    sort_warpper(nums);
    std::sort(nums_result.begin(), nums_result.end());
    CHECK_THAT(nums, Equals(nums_result));
}

TEST_CASE("size 1", "[sort]") {
    vector<int> nums{rand() % 0x3f3f};
    vector<int> nums_result(nums);
    sort_warpper(nums);
    std::sort(nums_result.begin(), nums_result.end());
    CHECK_THAT(nums, Equals(nums_result));
}

TEST_CASE("basic test", "[sort]") {
    vector<int> nums{3, 2, 1, 5, 6, 4};
    vector<int> nums_result(nums);
    sort_warpper(nums);
    std::sort(nums_result.begin(), nums_result.end());
    CHECK_THAT(nums, Equals(nums_result));
}

TEST_CASE("basic test_2", "[sort]") {
    vector<int> nums{3, 2, 3, 1, 2, 4, 5, 5, 6};
    vector<int> nums_result(nums);
    sort_warpper(nums);
    std::sort(nums_result.begin(), nums_result.end());
    CHECK_THAT(nums, Equals(nums_result));
}

TEST_CASE("basic test_3", "[sort]") {
    vector<int> nums{1, 1, 4, 5, 1, 4, 1, 9, 1, 9, 8, 1, 0};
    vector<int> nums_result(nums);
    sort_warpper(nums);
    std::sort(nums_result.begin(), nums_result.end());
    CHECK_THAT(nums, Equals(nums_result));
}

TEST_CASE("random test", "[sort]") {
    vector<int> nums{};
    nums.reserve(1145);
    for (int i = 0; i < 1145; ++i) {
        nums.push_back(rand() % 114514);
    }
    vector<int> nums_result(nums);
    sort_warpper(nums);
    std::sort(nums_result.begin(), nums_result.end());
    CHECK_THAT(nums, Equals(nums_result));
}
