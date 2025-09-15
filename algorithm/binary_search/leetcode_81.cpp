// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/
#ifdef CS203_DSAA_TEST_MACRO
#include <cstdint>
#include <cstddef>
#include <vector>
namespace leetcode_81 {
using std::vector;

#endif


class Solution {
public:
    bool search(const vector<int32_t> &nums, int32_t target) {
        const auto nums_size{nums.size()};
        if (nums.empty()) {
            return false;
        } else if (nums_size == 1) {
            return nums[0] == target;
        }
        size_t first{0}, maxv{1};
        while (maxv * 2 < nums_size) {
            maxv *= 2;
        }
        while (first < nums_size && 0 < maxv) {
            if (const auto next{first + maxv};next >= nums_size || nums[next] < nums[first]) {
                maxv /= 2;
            } else if (nums[next] == nums[first]) {
                first++;
            } else if (nums[next] > nums[first]) {
                first = next;
            }
        }
        const auto &binary_search_find_first_equal = [target, &nums](auto begin, auto end) {
            int32_t middle{0};
            while (begin < end) {
                middle = (end - begin) / 2 + begin;
                if (target == nums[middle]) {
                    return true;
                } else if (target > nums[middle]) {
                    begin = middle + 1;
                } else {
                    end = middle;
                }
            }
            return false;
        };
        return binary_search_find_first_equal(static_cast<size_t>(0), first + 1) ||
               binary_search_find_first_equal(first + 1, nums.size());
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
