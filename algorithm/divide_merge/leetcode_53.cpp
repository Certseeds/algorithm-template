// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO

#include <vector>
#include <cstdint>
#include <cstddef>
#include <string>
#include <algorithm>

namespace leetcode_53 {
using std::string;
using std::vector;
using std::max;
#endif

class Solution {
private:
    // [begin,end)
    int32_t maxSubArrayHelper(const vector<int32_t> &nums, size_t begin, size_t end) {
        if (begin + 1 == end) {
            return nums[begin];
        }
        const auto half{begin + (end - begin) / 2};
        const auto left{maxSubArrayHelper(nums, begin, half)},
                right{maxSubArrayHelper(nums, half, end)};
        int32_t max_left{-0x3f3f3f3f}, left_sum{0}, max_right{-0x3f3f3f3f}, right_sum{0};
        for (size_t left_order{half}; left_order >= begin + 1; left_order--) {
            // 无符号数判断的时候不要-1 > 0, 而是用 > 1
            left_sum += nums[left_order - 1];
            max_left = std::max(max_left, left_sum);
        }
        for (size_t right_order{half}; right_order < end; right_order++) {
            right_sum += nums[right_order];
            max_right = std::max(max_right, right_sum);
        }
        return std::max({left, right, max_left + max_right});
    }

public:
    int32_t maxSubArray(const vector<int32_t> &nums) {
        return maxSubArrayHelper(nums, 0, nums.size());
    }

    int32_t maxSubArray2(const vector<int32_t> &nums) {
        const auto nums_size{nums.size()};
        if (nums_size == 1) {
            return nums[0];
        }
        vector<int32_t> dp(nums_size + 1, 0);
        // dp[i] 考虑前第i个的最大值 X 带有第i个的最大值 √(不然不能直接用dp[i-1]+nums[i-1])
        // 若带前面的,则为 dp[i-1]+nums[i-1]
        // 若不带前面的,则为 nums[i-1]
        dp[0] = 0; // 选0个一定为0
        dp[1] = nums[0]; // 只选一个肯定是nums[0]
        int32_t maxV{nums[0]};
        for (size_t i{2}; i <= nums_size; i++) {
            dp[i] = std::max(nums[i - 1], dp[i - 1] + nums[i - 1]);
            maxV = std::max(maxV, dp[i]);
        }
        return maxV;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
