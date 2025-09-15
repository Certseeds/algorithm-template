/*
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Author: nanoseeds
 * @Date: 2020-08-01 17:39:45
 * @LastEditors: nanoseeds
 */
// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
// refer https://leetcode-cn.com/problems/rotate-array/
// 189
#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <algorithm>

using Catch::Matchers::Equals;
using std::vector;
using num_t = int32_t;

// nums 一个有序数组, 集体右移k个位置(k>=0)
// [first,last] !!
void reserve(vector<num_t> &nums, num_t first, num_t last) {
    while (first <= last) {
        std::swap(nums[first], nums[last]);
        first++;
        last--;
    }
}

void rorate_array_min(vector<num_t> &nums, num_t k) {
    if (0 == k) {
        return;
    }
    const auto nums_size = static_cast<num_t>(nums.size());
    k = k % nums_size;
    reserve(nums, 0, nums_size - 1);
    reserve(nums, 0, k - 1);
    reserve(nums, k, nums_size - 1);
}

void brute_force(vector<num_t> &nums, num_t k) {
    if (0 == k) {
        return;
    }
    const auto nums_size = static_cast<num_t>(nums.size());
    k = k % nums_size;
    vector<num_t> backend(k, 0);
    for (auto i = 0; i < k; i++) {
        backend[k - i - 1] = nums.back();
        nums.pop_back();
    }
    for (auto iter = backend.rbegin(); iter != backend.rend(); iter++) {
        nums.insert(nums.begin(), *iter);
    }
}

TEST_CASE("test case `for`", "[test binary search - rotate_array_min]") {
    vector<vector<num_t>> vec_list{
            {3,  1},
            {1,  3,    5},
            {3,  1,    3},
            {3,  3,    1, 3},
            {3,  4,    5, 1, 2},
            {2,  2,    2, 0, 1},
            {5,  6,    7, 1, 2, 3, 4},
            {-1, -100, 3, 99},
    };
    for (auto &vec: vec_list) {
        for (auto i = 0u; i < vec.size() * 2 + 1; i++) {
            vector<num_t> vec_2{vec};
            brute_force(vec, static_cast<num_t>(i));
            rorate_array_min(vec_2, static_cast<num_t>(i));
            CHECK_THAT(vec, Equals(vec_2));
        }
    }
}
