// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <cstdint>
#include <cstddef>
#include <vector>
#include <algorithm>

namespace leetcode_283 {
using std::vector;
#endif

class Solution {
public:
    void moveZeroes(vector<int32_t> &nums) {
        const auto nums_size{nums.size()};
        int64_t fill{0};
        for (size_t i{0}; i < nums_size; i++) {
            if (nums[i] != 0) {
                nums[fill] = nums[i];
                fill++;
            }
        }
        std::fill(nums.begin() + fill, nums.end(), 0);
    }

    void moveZeroes2(vector<int32_t> &nums) {
        const auto nums_size{nums.size()};
        for (size_t left{0}, right{0}; right < nums_size; right++) {
            if (nums[right] != 0) {
                std::swap(nums[left], nums[right]);
                left++;
            }
        }
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
