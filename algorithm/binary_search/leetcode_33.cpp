// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <cstdint>
#include <vector>

namespace leetcode_33 {
using std::vector;
#endif

class Solution {
public:
    int32_t search(const vector<int32_t> &nums, int32_t target) {
        const auto nums_size{static_cast<int32_t>(nums.size())};
        if (nums.empty()) {
            return -1;
        } else if (nums_size == 1) {
            return (nums[0] == target) ? 0 : -1;
        }
        int32_t minv{nums.back()}, first{0}, maxv{1};
        while (maxv * 2 < nums_size) {
            maxv *= 2;
        }
        while (maxv != 0) {
            //cout << first <<" " << maxv << lastl;
            if (first + maxv < nums_size && nums[first + maxv] > minv) {
                first += maxv;
            }
            maxv /= 2;
        }
        const auto &binary_search_find_first_equal = [target, &nums](auto begin, auto end) {
            int32_t middle{0};
            while (begin < static_cast<int32_t>(end)) {
                middle = (end - begin) / 2 + begin;
                if (target == nums[middle]) {
                    return middle;
                } else if (target > nums[middle]) {
                    begin = middle + 1;
                } else {
                    end = middle;
                }
            }
            return -1;
        };
        if (const int x1{binary_search_find_first_equal(0, first + 1)};x1 != -1) {
            return x1;
        }
        return binary_search_find_first_equal(first + 1, nums.size());
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
