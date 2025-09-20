// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds

#ifdef CS203_DSAA_TEST_MACRO

#include <cstdint>
#include <vector>

namespace leetcode_747 {
using std::vector;
#endif

class Solution {
public:
    int32_t dominantIndex(std::vector<int32_t> &nums) {
        const auto nums_size{nums.size()};
        size_t pos{0};
        int32_t lastMax{-1}, maxV{-1};
        for (size_t i{0}; i < nums_size; ++i) {
            if (maxV < nums[i]) {
                pos = i;
                maxV = nums[i];
            }
        }
        for (size_t i{0}; i < nums_size; ++i) {
            if (nums[i] != maxV && lastMax < nums[i]) {
                lastMax = nums[i];
            }
        }
        if (lastMax * 2 <= maxV) {
            return pos;
        }
        return -1;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
