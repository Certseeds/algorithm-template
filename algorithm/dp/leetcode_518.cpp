// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds

#ifdef ALGORITHM_TEST_MACRO
#include <cstddef>
#include <cstdint>
#include <vector>
namespace leetcode_518 {
using std::vector;
#endif

class Solution {
public:
    int32_t change(int32_t amount, const vector<int32_t> &coins) {
        if (amount == 0) {
            return coins.empty() ? 0 : 1;
        }
        const auto coins_size{coins.size()}, amount_size{static_cast<size_t>(amount)};
        // dp[i][j]代表使用前i种硬币,在j金额下能够凑出的硬币组合数
        vector<vector<int32_t>> dp(coins_size + 1, vector<int32_t>(amount_size + 1, 0));
        dp[0][0] = 0; // 没有硬币,也没有金额,无法做任何事
        for (size_t i{1}; i <= coins_size; i++) {
            dp[i][0] = 0; // 世界上没有空硬币,因此完全无法拼凑出来
        }
        for (int32_t i{1}; i <= amount; i++) {
            dp[0][i] = 0; // 没有硬币,无法拼出任何金额
        }
        for (size_t i{1}; i <= coins_size; i++) {
            const auto coin{coins[i - 1]};
            for (int32_t j{1}; j <= amount; j++) {
                dp[i][j] = dp[i - 1][j]; // 不使用当前硬币情况下的默认值
            }
            for (size_t coinNum{1}; coinNum * coin <= amount_size; coinNum++) {
                const auto coinSum{coinNum * coin};
                dp[i][coinSum] += 1;// 只使用了当前硬币情况下, 多一种情况
                for (size_t j{coinSum + 1}; j <= amount_size; j++) {
                    dp[i][j] += dp[i - 1][j - coinSum];
                }
            }
        }
        return dp.back().back();
    }

    int32_t change2(int32_t amount, const vector<int32_t> &coins) {
        const auto coins_size{coins.size()}, amount_size{static_cast<size_t>(amount)};
        // ~dp[i][j]代表使用前i种硬币,在j金额下能够凑出的硬币组合数~
        // dp[j]代表j金额下凑出的硬币组合数
        vector<int32_t> dp(amount_size + 1, 0);
        dp[0] = 1; // 只有没有金额才能不用硬币拼凑出
        for (size_t i{1}; i <= coins_size; i++) {
            const auto coin{coins[i - 1]}; // i代表使用前i种硬币
            for (int32_t j = coin; j <= amount; j++) {
                dp[j] += dp[j - coin];
            }
        }
        return dp.back();
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
