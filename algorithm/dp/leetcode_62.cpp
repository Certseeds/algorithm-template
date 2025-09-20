// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds

#ifdef CS203_DSAA_TEST_MACRO
#include <vector>
#include <cstdint>
namespace leetcode_62 {
using std::vector;
#endif

class Solution {
public:
    int uniquePaths(size_t m, size_t n) {
        vector<vector<int32_t>> DP(m, vector<int32_t>(n, 1));
        for (size_t i{1}; i < m; i++) {
            for (size_t j{1}; j < n; j++) {
                DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
            }
        }
        return DP.back().back();
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
