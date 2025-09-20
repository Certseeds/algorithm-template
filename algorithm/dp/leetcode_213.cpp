// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds

#ifdef ALGORITHM_TEST_MACRO

#include <cstddef>
#include <cstdint>
#include <vector>

namespace leetcode_213 {
using std::vector;
#endif

class Solution {
public:
    int64_t rob(const vector<int32_t> &nums) {
        const auto nums_size{nums.size()};
        vector<int32_t> values(nums);
        if (nums_size <= 1) {
            return values[0];
        }
        vector<int64_t> dp(nums_size + 1, 0); // 取得0个 只能得0
        dp[1] = 0;// then nums_size >= 2
        values[0] = 0;
        for (size_t i{2}; i <= nums_size; i++) {
            dp[i] = std::max(dp[i - 2] + values[i - 1], dp[i - 1]);
        }
        const auto nums1{dp.back()}; // 置首个为0, 弃用的结果
        values[0] = nums[0];
        std::fill(std::begin(dp), std::end(dp), 0);
        dp[1] = values[0];
        values[nums_size - 1] = 0;
        for (size_t i{2}; i <= nums_size; i++) {
            dp[i] = std::max(dp[i - 2] + values[i - 1], dp[i - 1]);
        }
        const auto nums2{dp.back()};// 置末尾为0, 弃用的结果
        return std::max(nums1, nums2);
    }

};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
