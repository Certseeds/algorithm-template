// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/

#ifdef CS203_DSAA_TEST_MACRO

#include <cstdint>
#include <vector>

namespace leetcode_724 {
using std::vector;
#endif

class Solution {
public:
    int32_t pivotIndex(vector<int32_t> &nums) {
        const auto nums_size{nums.size()};
        vector<int32_t> accu(nums_size + 2, 0);
        for (size_t i{1}; i <= nums_size; ++i) {
            accu[i] = nums[i - 1];
            accu[i] += accu[i - 1];
        }
        accu[nums_size + 1] = accu[nums_size];
        for (size_t i{1}; i <= nums_size; ++i) {
            if (accu[i - 1] + accu[i] == accu.back()) { // 可见此处可优化
                return static_cast<int>(i) - 1;
            }
        }
        return -1;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
