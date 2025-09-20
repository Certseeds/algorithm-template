/**
 * @Github: https://github.com/Certseeds/algorithm_template
 * @Author: nanoseeds
 * @Date: 2020-07-22 22:51:11
 * @LastEditors: nanoseeds
 */
// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
#include "sort_wrapper.hpp"

using std::vector;

void bubble_sort(vector<int32_t> &nums);

void sort_warpper(vector<int32_t> &nums) {
    bubble_sort(nums);
}

void bubble_sort(vector<int32_t> &nums) {
    for (size_t i{0}, nums_size{nums.size()}; i < nums_size; i++) {
        for (size_t j{0}; j < nums_size - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                std::swap(nums[j], nums[j + 1]);
            }
        }
    }
}
