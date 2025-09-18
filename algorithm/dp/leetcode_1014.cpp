// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/

#include <vector>
#include <algorithm>
#include <cstdint>

#ifdef CS203_DSAA_TEST_MACRO
namespace leetcode_1014 {
using std::vector;
#endif

class Solution {
public:
    int32_t maxScoreSightseeingPair(const vector<int32_t> &nums) noexcept {
        const int32_t nums_size = nums.size();
        if (nums_size <= 1) {
            return 0x3f3f3f3f;
        }
        vector<int32_t> dp(nums_size + 1, 0);
        // dp[i] => 前个里哪一个充当 values[i]+i里的i
        dp[0] = 0; // can not match pair
        dp[1] = 0; // 还没成对
        dp[2] = 0; // 第二个(1th)之前的i序号为0
        int32_t maxDiff{nums[0] + 0 + nums[1] - 1};
        for (int32_t j{3}; j <= nums_size; j++) {
            const auto i = dp[j - 1];
            const int32_t base = nums[j - 1] - j + 1;
            const int32_t diff1 = base + nums[i] + i;
            const int32_t diff2 = base + nums[j - 2] + j - 2;
            if (diff2 > diff1) {
                dp[j] = j - 2;
            } else {
                dp[j] = i;
            }
            maxDiff = std::max({maxDiff, diff1, diff2});
        }
        return maxDiff;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
