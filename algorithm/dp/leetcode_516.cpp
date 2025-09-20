// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds

#include <vector>
#include <string>
#include <algorithm>
#include <cstdint>

#ifdef CS203_DSAA_TEST_MACRO
namespace leetcode_516 {
using std::vector;
using std::string;
#endif

class Solution {
public:
    int32_t longestPalindromeSubseq(const string &s) {
        const auto s_size{s.size()};
        if (s.size() <= 1) {
            return static_cast<int32_t>(s_size);
        }
        vector<vector<int32_t>> dp(s_size, vector<int32_t>(s_size, 0));
        int32_t will_return{0};
        for (size_t i{s_size}; i > 0; --i) {
            const auto now{i - 1}; // 不需要+1,-1来回切换,好看多了
            dp[now][now] = 1;
            const auto ch1{s[now]};
            for (size_t j{now + 1}; j < s_size; ++j) {
                const auto ch2{s[j]};
                if (ch1 == ch2) {
                    dp[now][j] = dp[now + 1][j - 1] + 2;
                } else {
                    dp[now][j] = std::max(dp[now + 1][j], dp[now][j - 1]);
                    // dp[i][j] 指的是 (i,j)的子序列的最大长度,因此需要在这里递归的去掉左侧或去掉右侧来匹配
                }
                will_return = std::max(will_return, dp[now][j]);
            }
        }

        return will_return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
