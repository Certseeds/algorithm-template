// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO

#include <vector>
#include <limits>
#include <algorithm>
#include <cstdint>
#include <cstddef>

namespace leetcode_334 {
using std::vector;
using std::int32_t;
#endif

class Solution {
public:
    bool increasingTriplet(const vector<int32_t> &nums) {
        const auto nums_size{nums.size()};
        if (nums_size < 3) {
            return false;
        }
        vector<int32_t> dp(nums_size, 0);
        // dp[i]代表 第i个元素之前的最小元素
        // 此处可以发现其实只用到了dp[i],dp[i-1],可以做空间压缩
        dp[0] = std::numeric_limits<int32_t>::max(); // 第0个前面没有元素,所以置为int32_t的最大值
        int32_t maxMin{std::numeric_limits<int32_t>::max()};
        for (size_t i{1}; i + 1 < nums_size; ++i) {
            dp[i] = std::min(dp[i - 1], nums[i - 1]);
            if (nums[i] > dp[i]) {
                maxMin = std::min(maxMin, nums[i]);
            }
            if (nums[i + 1] > maxMin) {
                return true;
            }
        }
        return false;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif

