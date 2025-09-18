// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/

#ifdef CS203_DSAA_TEST_MACRO
namespace leetcode_300 {
using std::vector;
#endif

class Solution {
public:
    int32_t lengthOfLIS(const vector<int32_t> &nums) {
        const auto nums_size{nums.size()};
        if (nums_size <= 1) {
            return static_cast<int32_t>(nums_size);
        }
        vector<int32_t> dp(nums_size, 1);
        // 难点在DP定义上, 如何定义子问题,让问题能够连接起来
        // [j] 以j为结尾的最长严格递增子序列
        int32_t will_return{1};
        for (size_t i{1}; i < nums_size; i++) {
            for (size_t j{0}; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
                will_return = std::max(will_return, dp[i]);
            }
        }
        return will_return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
