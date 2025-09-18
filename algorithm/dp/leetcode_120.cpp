// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/

#include <vector>
#include <algorithm>
#include <cstdint>

#ifdef CS203_DSAA_TEST_MACRO
namespace leetcode_120 {
using std::vector;
#endif

class Solution {
public:
    int32_t minimumTotal(const vector<vector<int32_t>> &triangle) {
        const size_t tri_height{triangle.size()};
        if (tri_height == 0) {
            return 0;
        } else if (tri_height == 1) {
            return triangle[0][0];
        }
        vector<int32_t> dps(tri_height, 0);
        dps[0] = triangle.front().front();
        for (size_t i{1}; i < tri_height; i++) {
            dps[i] = dps[i - 1] + triangle[i][i];
            for (size_t r{i - 1}; r > 0; r--) {
                dps[r] = std::min(dps[r - 1], dps[r]) + triangle[i][r];
            }
            dps[0] = dps[0] + triangle[i][0];
        }
        return *std::min_element(dps.cbegin(), dps.cend());
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif

