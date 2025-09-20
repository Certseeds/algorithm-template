// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds

#ifdef CS203_DSAA_TEST_MACRO

#include <vector>
#include <cstdint>
#include <algorithm>

namespace leetcode_561 {
using std::vector;
#endif

class Solution {
public:
    int32_t arrayPairSum(std::vector<int32_t> &nums) {
        const size_t nums_size{nums.size()};
        std::sort(nums.begin(), nums.end());
        int32_t temp{0};
        for (size_t i{0}; i < nums_size; i += 2) {
            temp += nums[i];
        }
        return temp;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
