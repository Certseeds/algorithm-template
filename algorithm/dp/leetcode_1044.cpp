// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/

#include <string>
#include <vector>
#include <algorithm>
#include <cstdint>

#ifdef CS203_DSAA_TEST_MACRO
namespace leetcode_1044 {
using std::string;
using std::vector;
#endif

class Solution {
private:
    // 缺点在于很慢,对拍可以用
    // 由于实际上最长公共子串包括字符串自己
    // 因此,排除掉之后,所有的公共子串信息实际上是副产物
    // 题目相当于要求返回次长的字串. 所以效率提不上去
    // 因此,如果有意的把自己和自己重复的场景去掉, 就可以提高效率
    string longestDupSubstringN2(const string &s) {
        const auto ssize{s.size()};
        vector<vector<size_t>> dp(ssize + 1, vector<size_t>(ssize + 1, 0));
        // dp[i][j], from i to j's longest dup substring
        size_t max_value{0};
        for (size_t i{1}; i <= ssize; ++i) {
            for (size_t j{1}; j <= ssize; ++j) {
                if (i == j) {
                    dp[i][j] = 0;
                    continue;
                }
                if (s[i - 1] == s[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    max_value = std::max(max_value, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        if (max_value < 2) {
            return "";
        }
        for (size_t i{1}; i <= ssize; ++i) {
            for (size_t j{1}; j <= ssize; ++j) {
                if (dp[i][j] == max_value) {
                    return s.substr(i - max_value, max_value);
                }
            }
        }
        return "";
    }

public:
    string longestDupSubstring(const string &s) {
        return longestDupSubstringN2(s); // TODO,优化,估计会挪到二分或者hash那边去?
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
