// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/

#ifdef CS203_DSAA_TEST_MACRO

#include <numeric>

namespace leetcode_416 {
using std::vector;
#endif

class Solution {
public:
    bool canPartition(const vector<int32_t> &nums) {
        const auto nums_size{nums.size()};
        if (nums_size <= 1) {
            return false;
        }
        const int32_t sum = std::accumulate(nums.cbegin(), nums.cend(), 0);
        if (sum % 2 == 1) {
            return false;
        }
        const auto target = sum / 2;
        vector<vector<uint8_t>> dp(nums_size + 1, vector<uint8_t>(target + 1, false));
        dp[0][0] = true;
        for (int32_t i{1}; i <= target; i++) {
            dp[0][i] = false; // 无论怎样, 前0种无法装满任何有量的背包
        }
        for (size_t i{1}; i <= nums_size; i++) {
            dp[i][0] = true; // 无论怎样,0量的背包可以被0个物体组合装满
        }
        for (size_t i{1}; i <= nums_size; i++) {
            for (int32_t j{1}; j <= target; j++) {
                dp[i][j] = dp[i][j] || dp[i - 1][j];
                if (j >= nums[i - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp.back().back();
    }

    bool canPartition2(const vector<int32_t> &nums) {
        const auto nums_size{nums.size()};
        if (nums_size <= 1) {
            return false;
        }
        const int32_t sum = std::accumulate(nums.cbegin(), nums.cend(), 0);
        if (sum % 2 == 1) {
            return false;
        }
        const auto target = sum / 2;
        vector<uint8_t> last(target + 1, false), now(target + 1, false);
        last[0] = true;
        for (size_t i{1}; i <= nums_size; i++) {
            now[0] = true;
            for (int32_t j{1}; j <= target; j++) {
                now[j] = now[j] || last[j];
                if (j >= nums[i - 1]) {
                    now[j] = now[j] || last[j - nums[i - 1]];
                }
            }
            std::swap(last, now);
        }
        return last.back();
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
