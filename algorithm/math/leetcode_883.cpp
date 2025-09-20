// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO

#include <cstdint>
#include <vector>
#include <algorithm>

namespace leetcode_883 {
using std::vector;
#endif

class Solution {
public:
    int32_t projectionArea(const vector<vector<int32_t>> &grid) {
        const auto m{grid.size()};
        if (m == 0) {
            return 0;
        }
        int willreturn{0};
        for (size_t i{0}; i < m; ++i) {
            int max1{0}, max2{0};
            for (size_t j{0}; j < m; ++j) {
                if (grid[i][j]) {
                    willreturn++;
                }
                max1 = std::max(max1, grid[j][i]);
                max2 = std::max(max2, grid[i][j]);
            }
            willreturn += (max1 + max2);
        }
        return willreturn;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
