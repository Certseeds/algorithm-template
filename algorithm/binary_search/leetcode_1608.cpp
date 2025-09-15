// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <algorithm>
#include <vector>

namespace leetcode_1608 {
using std::vector;

#endif


class Solution {
public:
    int32_t specialArray(const vector<int32_t> &nums_) {
        vector<int32_t> nums{nums_};
        std::sort(nums.begin(), nums.end());
        const auto nums_size{nums.size()};
        int32_t left{0}, right = std::min(static_cast<int32_t>(nums_size), nums.back());
        while (left < right) {
            const auto mid = (right - left) / 2 + left;
            const auto num = std::lower_bound(nums.begin(), nums.end(), mid);
            const auto diff = std::distance(num,nums.end());
            if (diff > mid) {
                left = mid + 1;
            } else if (diff < mid) {
                right = mid;
            } else {
                return mid;
            }
        }
        const auto mid = (right - left) / 2 + left;
        const auto num = std::lower_bound(nums.begin(), nums.end(), mid);
        const auto diff = std::distance(num,nums.end());
        if (diff == mid) {
            return mid;
        }
        // ps, the last step is better for
        return -1;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
