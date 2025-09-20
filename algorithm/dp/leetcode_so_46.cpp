// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds

#include <vector>
#include <cstdint>

#ifdef CS203_DSAA_TEST_MACRO
namespace leetcode_so_46 {
using std::vector;
#endif

class Solution {
public:
    int32_t translateNum(int32_t num) {
        if (num < 10) {
            return 1;
        }
        vector<int32_t> nums{};
        while (num > 0) {
            nums.push_back(num % 10);
            num /= 10;
        }
        vector<int32_t> numbers{nums.rbegin(), nums.rend()};
        const auto nums_size{numbers.size()}; // 此时至少为2
        vector<int32_t> dp(nums_size + 1);
        dp[0] = 1;// 空白只有一种可能
        dp[1] = 1; // 一位只有一种可能
        for (size_t i{2}; i <= nums_size; ++i) { // 滚动数组不进行优化
            const auto two{numbers[i - 2] * 10 + numbers[i - 1]};
            if (10 <= two && two <= 25) {
                dp[i] += dp[i - 2];
            }
            dp[i] += dp[i - 1];
        }
        return dp.back();
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
