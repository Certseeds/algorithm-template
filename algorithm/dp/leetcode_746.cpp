// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds

#ifdef CS203_DSAA_TEST_MACRO

#include <vector>
#include <algorithm>
#include <array>
#include <cstdint>

namespace leetcode_746 {
using std::vector;
#endif

class Solution {
public:
    int32_t minCostClimbingStairs(const std::vector<int32_t> &cost) {
        const auto cost_size{cost.size()}; // always >= 2
        std::vector<int32_t> dp(cost.size() + 1, 0);
        for (size_t i{2}; i <= cost_size; i++) {
            dp[i] = std::min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp.back();
    }

    int32_t minCostClimbingStairs2(const std::vector<int32_t> &cost) {
        const auto cost_size{cost.size()}; // always >= 2
        std::array<int32_t, 3> dp{0, 0, 0};
        // 滚 动 数 组
        for (size_t i{2}; i <= cost_size; i++) {
            dp[2] = std::min(dp[1] + cost[i - 1], dp[0] + cost[i - 2]);
            dp[0] = dp[1];
            dp[1] = dp[2];
        }
        return dp[2];
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif