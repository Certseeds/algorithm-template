// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds

#ifdef CS203_DSAA_TEST_MACRO
namespace leetcode_198 {
using std::vector;
#endif

class Solution {
public:
    int64_t rob(const vector<int32_t> &nums) {
        const auto nums_size{nums.size()};
        if (nums_size <= 1) {
            return nums[0];
        }
        vector<int64_t> dp(nums_size + 1, 0); // 取得0个 只能得0
        dp[1] = nums[0];// then nums_size >= 2
        for (size_t i{2}; i <= nums_size; i++) {
            dp[i] = std::max(dp[i - 2] + nums[i - 1], dp[i - 1]);
        }
        return dp.back();
    }

    int64_t rob2(const vector<int32_t> &nums) {
        const auto nums_size{nums.size()};
        if (nums_size <= 1) {
            return nums[0];
        }
        std::array<int64_t, 3> dp{0, nums[0], 0};
        // 滚 动 数 组
        for (size_t i{2}; i <= nums_size; i++, dp[1] = dp[2]) {
            dp[2] = std::max(dp[0] + nums[i - 1], dp[1]);
            dp[0] = dp[1]; // 不确保执行顺序,所以不能都放过去
        }
        return dp[2];
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif