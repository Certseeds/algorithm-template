// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds

#ifdef CS203_DSAA_TEST_MACRO

#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_674 {
using std::vector;
#endif

class Solution {
public:
    int32_t findLengthOfLCIS(const vector<int32_t> &nums) {
        int32_t will_Return{!nums.empty()}, maxv{1};
        for (size_t i{1}, size{nums.size()}; i < size; ++i) {
            maxv = (nums[i] > nums[i - 1]) ? (maxv + 1) : 1;
            will_Return = std::max(will_Return, maxv);
        }
        return will_Return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
