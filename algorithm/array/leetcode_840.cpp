// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO

#include <vector>
#include <cstddef>

namespace leetcode_840 {
using std::vector;
#endif

class Solution {
private:
    bool isMagic(const vector<vector<int32_t>> &grid, size_t x, size_t y) {
        for (size_t i{0}; i < 3; ++i) {
            for (size_t j{0}; j < 3; ++j) {
                if (grid[x + i][y + j] > 9 || grid[x + i][y + j] < 1) {
                    return false;
                }
            }
        }
        return (
                // 中间需要是五
                grid[x + 1][y + 1] == 5 &&
                grid[x][y] + grid[x + 2][y + 2] == 10 &&
                grid[x + 1][y] + grid[x + 1][y + 2] == 10 &&
                grid[x + 2][y] + grid[x][y + 2] == 10 &&
                grid[x][y] != grid[x + 2][y + 2] &&
                grid[x + 1][y] != grid[x + 1][y + 2] &&
                grid[x + 2][y] != grid[x][y + 2] &&
                grid[x][y] + grid[x][y + 1] + grid[x][y + 2] == 15 &&
                grid[x][y] + grid[x + 1][y] + grid[x + 2][y] == 15 &&
                grid[x + 2][y] + grid[x + 2][y + 1] + grid[x + 2][y + 2] == 15
        );
    }

public:
    int32_t numMagicSquaresInside(const vector<vector<int32_t>> &grid) {
        const auto m{grid.size()};
        if (m < 3) {
            return 0;
        }
        const auto n{grid.size()};
        if (n < 3) {
            return 0;
        }
        int count = 0;
        for (size_t i{0}; i + 3 <= m; ++i) {
            for (size_t j{0}; j + 3 <= n; ++j) {
                count += isMagic(grid, i, j);
            }
        }
        return count;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
