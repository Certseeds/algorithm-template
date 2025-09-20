// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds

#include <vector>
#include <string>
#include <algorithm>
#include <cstdint>

#ifdef ALGORITHM_TEST_MACRO
namespace leetcode_72 {
using std::vector;
using std::string;
#endif

class Solution {
public:
    int32_t minDistance(const string &word1, const string &word2) {
        const size_t fst_size{word1.size()}, snd_size{word2.size()};
        vector<vector<size_t>> dp(fst_size + 1, vector<size_t>(snd_size + 1, 0));
        // dp[i][j], word1[0~i],word2[0~j]的编辑距离
        // 将增,删,改 规约成
        // A增,B增,A改, 再规约成
        // A最后增, B最后增, A任意改
        for (size_t i{0}; i <= fst_size; i++) {
            dp[i][0] = i;
        }
        for (size_t i{1}; i <= snd_size; i++) {
            dp[0][i] = i;
        }
        for (size_t i{1}; i <= fst_size; i++) {
            for (size_t j{1}; j <= snd_size; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = std::min({dp[i - 1][j - 1], dp[i][j - 1] + 1, dp[i - 1][j] + 1});
                    // 分别对应不改,B增,A增
                } else {
                    // 分别对应改,B增,A增
                    dp[i][j] = 1 + std::min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]});
                }
            }
        }
        return static_cast<int32_t>(dp.back().back());
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
