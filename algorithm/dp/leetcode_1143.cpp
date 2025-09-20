// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanos

*/

#include <vector>
#include <string>
#include <algorithm>
#include <cstdint>

#ifdef CS203_DSAA_TEST_MACRO
namespace leetcode_1143 {
using std::vector;
using std::string;
#endif

class Solution {
public:
    int32_t longestCommonSubsequence2(const string &text1, const string &text2) {
        const auto fst_size{text1.size()}, snd_size{text2.size()};
        vector<vector<int32_t>> dp(fst_size + 1, vector<int32_t>(snd_size + 1, 0));
        // init vector for 0 can except init [0][...],[...][0] to 0
        for (size_t i{1}; i <= fst_size; i++) {
            for (size_t j{1}; j <= snd_size; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp.back().back();
    }

    int32_t longestCommonSubsequence(const string &text1, const string &text2) {
        const auto fst_size{text1.size()}, snd_size{text2.size()};
        vector<int32_t> fst(snd_size + 1, 0), snd(snd_size + 1, 0);
        // init vector for 0 can except init [0][...],[...][0] to 0
        for (size_t i{1}; i <= fst_size; i++) {
            for (size_t j{1}; j <= snd_size; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    snd[j] = fst[j - 1] + 1;
                } else {
                    snd[j] = std::max(snd[j - 1], fst[j]);
                }
            }
            std::swap(fst, snd);
        }
        return fst.back();
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
