// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include "sort_wrapper.hpp"

using std::vector;

void heap_sort(vector<int32_t> &nums);

void heapsort_rec(vector<int32_t> &nums, int index, int length);

void sort_warpper(vector<int32_t> &nums) {
    heap_sort(nums);
}

void heap_sort(vector<int32_t> &nums) {
    const int32_t nums_size{static_cast<int32_t>(nums.size())};
    const int32_t beginIndex = (nums_size / 2) - 1;
    for (int32_t i = beginIndex; i >= 0; --i) {
        heapsort_rec(nums, i, nums_size - 1);
    }
    for (int32_t i = nums_size - 1; i > 0; --i) {
        std::swap(nums[0], nums[i]);
        heapsort_rec(nums, 0, i - 1);
    }
}

void heapsort_rec(vector<int32_t> &nums, int index, int length) {
    const int32_t left = index * 2 + 1;
    const int32_t right = left + 1;
    int32_t son_max = left;
    if (left > length) {
        return;
    }
    if (right <= length && nums[right] > nums[left]) {
        son_max = right;
    }
    if (nums[son_max] > nums[index]) {
        std::swap(nums[son_max], nums[index]);
        heapsort_rec(nums, son_max, length);
    }
}
