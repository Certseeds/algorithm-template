// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds

#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdint>

#ifdef CS203_DSAA_TEST_MACRO
namespace leetcode_918 {
using std::vector;
#endif

class Solution {
private:
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

    int32_t minSubArray2(const vector<int32_t> &nums) {
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
        int32_t minV{nums[0]};
        for (size_t i{2}; i <= nums_size; i++) {
            dp[i] = std::min(nums[i - 1], dp[i - 1] + nums[i - 1]);
            minV = std::min(minV, dp[i]);
        }
        return minV;
    }

public:
    int32_t maxSubarraySumCircular(const vector<int32_t> &nums) {
        const int32_t nums_size = nums.size();
        if (nums_size == 1) {
            return nums[0];
        }
        bool isAllPositive{true}, isAllNegative{true};
        std::for_each(nums.cbegin(), nums.cend(), [&isAllPositive, &isAllNegative](const auto v) {
            isAllPositive = isAllPositive && (v > 0);
            isAllNegative = isAllNegative && (v < 0);
        });
        if (isAllNegative) {
            return *std::max_element(nums.cbegin(), nums.cend());
        } else if (isAllPositive) {
            return std::accumulate(nums.cbegin(), nums.cend(), 0);
        }
        const int32_t normal = maxSubArray2(nums);
        const auto lastMax = [](const auto fst, const auto lst) {
            vector<int32_t> num(fst, lst);
            const auto num_size{num.size()};
            if (num_size == 1) {
                return num[0];
            }
            vector<int32_t> dp(num_size + 1, 0);
            dp[0] = 0; // 选0个一定为0
            dp[1] = num[0]; // 只选一个肯定是nums[0]
            for (size_t i{2}; i <= num_size; i++) {
                dp[i] = std::max(num[i - 1], dp[i - 1] + num[i - 1]);
            }
            return dp.back();
        };
        const auto fst = lastMax(nums.cbegin(), nums.cend()); // conti last's biggest value
        const auto lst = lastMax(nums.crbegin(), nums.crend()); // conti fst's biggest value
        int32_t lst_rightest{0}, fst_leftest;
        for (int32_t i{0}, sums{0}; i < nums_size; i++) {
            sums += nums[i];
            if (sums == lst) {
                lst_rightest = i;
            }
        }
        for (int32_t i{nums_size - 1}, sums{0}; i >= 0; i--) {
            sums += nums[i];
            if (sums == fst) {
                fst_leftest = i;
            }
        }
        if (fst_leftest < lst_rightest) {
            // 判定是否交叉,交叉了的话, 全部的和 - 中间的一块最小和
            return std::max(normal, std::accumulate(nums.cbegin(), nums.cend(), 0) - minSubArray2(nums));
        } else {
            // 没交差,直接判断一下
            return std::max(normal, fst + lst);
        }
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
