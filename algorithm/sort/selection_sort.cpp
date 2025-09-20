/**
 * @Github: https://github.com/Certseeds/algorithm_template
 * @Author: nanoseeds
 * @Date: 2020-07-22 22:54:21
 * @LastEditors: nanoseeds
 */
// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
#include "sort_wrapper.hpp"

using std::vector;

void selection_sort(vector<int32_t> &nums);

void sort_warpper(vector<int32_t> &nums) {
    selection_sort(nums);
}

void selection_sort(vector<int32_t> &nums) {
    int32_t will_return{0};
    const auto nums_size = static_cast<int32_t>(nums.size());
    for (int i = 0; i < nums_size - 1; ++i) {
        ++will_return;
        int k = i;
        for (int j = i + 1; j < nums_size; ++j) {
            ++will_return;
            ++will_return;
            if (nums[k] > nums[j]) {
                k = j;
            }
        }
        ++will_return;
        ++will_return;
        std::swap(nums[i], nums[k]);
    }
    ++will_return;
}
