// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds

#ifdef ALGORITHM_TEST_MACRO
#include <vector>
#include <string>
#include <cstdint>
namespace leetcode_5 {
using std::vector;
using std::string;
using std::pair;
#endif

class Solution {
public:
    string longestPalindrome(const string &s) {
        const size_t s_size = s.size();
        if (s_size <= 1) {
            return s;
        } else if (s_size == 2) {
            if (s[0] == s[1]) {
                return s;
            } else {
                return s.substr(0, 1);
            }
        }
        vector<vector<uint8_t>> dp(s_size, vector<uint8_t>(s_size, false));
        pair<size_t, size_t> begin_end{0, 1};
        size_t max_size = 1;
        for (size_t i{0}; i < s_size; i++) {
            dp[i][i] = true;
        }
        for (size_t i{0}; i < s_size - 1; i++) {
            dp[i][i + 1] = (s[i] == s[i + 1]);
            if (dp[i][i + 1]) {
                max_size = 2;
                begin_end = {i, max_size};
            }
        }
        for (size_t i{s_size}; i > 0; i--) {
            for (size_t j{i + 1}; j < s_size; j++) {
                dp[i - 1][j] = ((s[i - 1] == s[j]) && dp[i][j - 1]);
                if (j - i + 2 > max_size && dp[i - 1][j]) {
                    max_size = j - i + 2;
                    begin_end = {i - 1, max_size};
                }
            }
        }
        return s.substr(begin_end.first, begin_end.second);
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
