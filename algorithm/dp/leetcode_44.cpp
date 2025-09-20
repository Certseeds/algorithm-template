// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds

#include <vector>
#include <string>
#include <cstdint>

#ifdef CS203_DSAA_TEST_MACRO
namespace leetcode_44 {
using std::vector;
using std::string;
#endif

class Solution {
public:
    bool isMatch(const string &s, const string &p) {
        const auto s_size{s.size()}, p_size{p.size()};
        vector<vector<uint8_t>> DP(s_size + 1, vector<uint8_t>(p_size + 1, false));
        DP[0][0] = true;
        for (size_t i{1}; i <= p_size; i++) {
            DP[0][i] = (p[i - 1] == '*') && DP[0][i - 1];
        }
        for (size_t i{1}; i <= s_size; i++) {
            for (size_t j{1}; j <= p_size; j++) {
                switch (p[j - 1]) {
                    case '?': {
                        DP[i][j] = DP[i - 1][j - 1];
                        break;
                    }
                    case '*': {
                        DP[i][j] = DP[i][j - 1] || DP[i - 1][j];
                        break;
                    }
                    default: {
                        DP[i][j] = DP[i - 1][j - 1] && (s[i - 1] == p[j - 1]);
                        break;
                    }
                }
            }
        }
        return DP.back().back();
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
