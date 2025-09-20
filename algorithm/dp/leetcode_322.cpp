// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanos

*/

#ifdef CS203_DSAA_TEST_MACRO
namespace leetcode_322 {
using std::vector;
#endif

class Solution {
public:
    int32_t coinChange(const vector<int32_t> &coins, int32_t amount) {
        vector<int32_t> input{};
        for (const auto coinNum: coins) {
            if (coinNum <= amount) {
                input.push_back(coinNum);
            }
        }
        std::sort(input.begin(), input.end());
        // dp[i][j]代表 使用前i种硬币,组合出j面值需要的最小数量
        vector<vector<int32_t>> dp(input.size() + 1, vector<int32_t>(amount + 1, 0x3f3f3f3f));
        dp[0][0] = 0;
        for (int32_t i{1}; i <= amount; i++) {
            dp[0][i] = 0x3f3f3f3f; // 无论怎样, 前0种无法搭配出任何面值
        }
        for (size_t i{1}; i <= input.size(); i++) {
            dp[i][0] = 0; // 无论怎样,0面值可以被0个组合出来
        }
        for (size_t i{1}; i <= input.size(); i++) {
            const auto coin{input[i - 1]};
            for (int32_t j{1}; j <= amount; j++) {
                dp[i][j] = std::min(dp[i][j], dp[i - 1][j]);
                if (j >= coin) {
                    // 此处因为是完全背包,所以可以用循环取值的方法求,O(n)
                    // 优化一下 就变成了dp[i][j-coin], 由本行上一个组成
                    // 简化重复计算,因为计算[i][j]的[i-1][j-coin],[i-1][j-2coin]的话,
                    // 实际上[i][j-coin]已经计算了 [i-1][j-2coin],[i-1][j-3coin]...等等,所以只需要对比一次就ok
                    dp[i][j] = std::min(dp[i][j], dp[i][j - coin] + 1);
                }
                //for (int32_t k{j}, count{0}; k >= 0; k -= coin, count++) {
                //    dp[i][j] = std::min(dp[i][j], dp[i - 1][k] + count);
                //}
            }
        }
        return dp.back().back() >= 0x3f3f3f3f ? -1 : dp.back().back();
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
