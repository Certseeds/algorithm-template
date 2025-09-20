/*
 * @Github: https://github.com/Certseeds/algorithm_template
 * @Author: nanoseeds
 * @Date: 2020-07-18 21:00:45
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-07-18 21:03:33
 */
// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/

#include "sort_wrapper.hpp"

using std::vector;

void quick_sort(vector<int> &nums);

inline int get_rand(int left, int right);

void rec_quicksort(vector<int> &nums, int left, int right);

int partition(vector<int> &nums, int left, int right, int pivotIndex);

void sort_warpper(vector<int32_t> &nums) {
    quick_sort(nums);
}

void quick_sort(vector<int> &nums) {
    rec_quicksort(nums, 0, static_cast<int>(nums.size() - 1));
}

void rec_quicksort(vector<int> &nums, int left, int right) {
    if (left >= right) {
        return;
    }
    const int32_t rand_posi = get_rand(left, right);
    const int32_t final_posi = partition(nums, left, right, rand_posi);
    rec_quicksort(nums, left, final_posi - 1);
    rec_quicksort(nums, final_posi + 1, right);
}

inline int get_rand(int left, int right) {
    return rand() % (right - left + 1) + left;
}

int partition(vector<int> &nums, int left, int right, int pivotIndex) {
    const int pivotValue = nums[pivotIndex];
    std::swap(nums[pivotIndex], nums[right]); // 把pivot移到結尾
    int storeIndex = left;
    for (int i = left; i < right; ++i) {
        if (nums[i] <= pivotValue) {
            std::swap(nums[storeIndex], nums[i]);
            ++storeIndex;
        }
    }
    std::swap(nums[right], nums[storeIndex]);
    return storeIndex;
}
