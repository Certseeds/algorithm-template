// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/

#ifdef CS203_DSAA_TEST_MACRO
#include <vector>
#include <cstdint>
namespace leetcode_63 {
using std::vector;
#endif

class Solution {
public:
    int32_t uniquePathsWithObstacles(const vector<vector<int>> &obs) {
        const size_t m{obs.size()};
        if (m == 0) {
            return 0;
        }
        const size_t n{obs[0].size()};
        vector<vector<int32_t>> DP(m, vector<int32_t>(n, 0));
        DP[0][0] = (obs[0][0] == 0);
        for (size_t i{1}; i < m; i++) {
            DP[i][0] = (DP[i - 1][0] != 0) && (obs[i][0] == 0);
        }
        for (size_t i{1}; i < n; i++) {
            DP[0][i] = (DP[0][i - 1] != 0) && (obs[0][i] == 0);
        }
        for (size_t i{1}; i < m; i++) {
            for (size_t j{1}; j < n; j++) {
                if (obs[i][j] == 0) {
                    DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
                }
            }
        }
        return DP.back().back();
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
