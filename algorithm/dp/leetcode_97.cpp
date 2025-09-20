// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanos

*/

#include <vector>
#include <string>
#include <cstdint>

#ifdef CS203_DSAA_TEST_MACRO
namespace leetcode_97 {
using std::vector;
using std::string;
#endif

class Solution {
public:
    bool isInterleave(const string &s1, const string &s2, const string &s3) {
        const auto s1_size{s1.size()}, s2_size{s2.size()}, s3_size{s3.size()};
        if (s1_size + s2_size != s3_size) {
            return false;
        } else if (s1_size == 0) {
            return s2 == s3;
        } else if (s2_size == 0) {
            return s1 == s3;
        }
        vector<vector<uint8_t>> dp(s1_size + 1, vector<uint8_t>(s2_size + 1, false));
        dp[0][0] = true;
        for (size_t i{1}; i <= s1_size && dp[i - 1][0]; i++) {
            dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
        }
        for (size_t i{1}; i <= s2_size && dp[0][i - 1]; i++) {
            dp[0][i] = dp[0][i - 1] && (s2[i - 1] == s3[i - 1]);
        }
        for (size_t i{1}; i <= s1_size; i++) {
            for (size_t j{1}; j <= s2_size; j++) {
                const char char1{s1[i - 1]}, char2{s2[j - 1]}, char3{s3[i + j - 1]};
                if (char1 == char3) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
                if (char2 == char3) {
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
                }
            }
        }
        return dp.back().back();
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
