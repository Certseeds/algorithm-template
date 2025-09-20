/**
 * @Github: https://github.com/Certseeds/algorithm_template
 * @Author: nanoseeds
 * @Date: 2020-07-22 22:57:16
 * @LastEditors: nanoseeds
 */
// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
#include <cstring>
#include "sort_wrapper.hpp"

using std::vector;

void merge_sort(vector<int32_t> &nums);

void mergesort_rec(vector<int32_t> &nums, vector<int32_t> &zeros, int begin, int end);

void sort_warpper(vector<int32_t> &nums) {
    merge_sort(nums);
}

void merge_sort(vector<int32_t> &nums) {
    vector<int32_t> zeros(nums);
    mergesort_rec(nums, zeros, 0, nums.size() - 1);
}

void mergesort_rec(vector<int32_t> &nums, vector<int32_t> &zeros, int begin, int end) {
    if (begin >= end) {
        return;
    } else if (begin + 1 == end) {
        if (nums[begin] > nums[end]) {
            std::swap(nums[begin], nums[end]);
        }
    }
    const int32_t middle = begin + (end - begin) / 2;;
    mergesort_rec(nums, zeros, begin, middle);
    mergesort_rec(nums, zeros, middle + 1, end);
    int pos = begin;
    int start1 = begin;
    int start2 = middle + 1;
    while (start1 <= middle && start2 <= end) {
        if (nums[start1] < nums[start2]) {
            zeros[pos] = nums[start1];
            ++start1;
        } else {
            zeros[pos] = nums[start2];
            ++start2;
        }
        ++pos;
    }
    while (start1 <= middle) {
        zeros[pos] = nums[start1];
        ++pos;
        ++start1;
    }
    while (start2 <= end) {
        zeros[pos] = nums[start2];
        ++pos;
        ++start2;
    }
    memcpy(reinterpret_cast<void *>(&nums[begin]), reinterpret_cast<void *>(&zeros[begin]),
           sizeof(int32_t) * (end - begin + 1));
}
