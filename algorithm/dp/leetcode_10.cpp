// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/

#include <vector>
#include <string>
#include <cstdint>

#ifdef CS203_DSAA_TEST_MACRO
namespace leetcode_10 {
using std::vector;
using std::string;
#endif

class Solution {
public:
    bool isMatch(const string &s, const string &p) {
        static constexpr const auto func = [](const auto x, const auto y) {
            return y == '.' || x == y;
        };
        const auto s_size{s.size()}, p_size{p.size()};
        vector<vector<uint8_t>> DP(s_size + 1, vector<uint8_t>(p_size + 1, false));
        DP[0][0] = true;
        for (size_t j{1}; j <= p_size; ++j) {
            DP[0][j] = (p[j - 1] == '*' && DP[0][j - 2]);
        }
        for (size_t i{1}; i <= s_size; ++i) {
            const auto s_char{s[i - 1]};
            for (size_t j{1}; j <= p_size; ++j) {
                const auto p_char{p[j - 1]};
                if (p[j - 1] == '*') { // p[0], j =1 will not appear '*'
                    const auto p_last_char{p[j - 2]};
                    DP[i][j] = DP[i][j - 2] || (func(s_char, p_last_char) && DP[i - 1][j]);
                } else if (func(s_char, p_char)) {
                    DP[i][j] = DP[i - 1][j - 1];
                }
            }
        }
        return DP.back().back();
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
