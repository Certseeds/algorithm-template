// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds

#ifdef ALGORITHM_TEST_MACRO

#include <cstddef>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <numeric>

namespace leetcode_931 {
using std::vector;
#endif

class Solution {
public:
    int32_t minFallingPathSum(const vector<vector<int32_t>> &matrix) {
        if (matrix.empty() || matrix.front().empty()) {
            return 0;
        }
        const auto row{matrix.size()}, col{matrix.front().size()};
        if (col == 1) {
            return std::accumulate(matrix.cbegin(), matrix.cend(), 0,
                                   [](auto &fir, const auto &sec) { return fir + sec[0]; });
        }
        vector<int32_t> last(row, 0), now(row, 0);
        for (size_t line{0}; line < row; line++) {
            now[0] = matrix[line][0] + std::min(last[0], last[1]);
            for (size_t j{1}; j < col - 1; j++) {
                now[j] = matrix[line][j] + std::min({last[j], last[j - 1], last[j + 1]});
            }
            now[col - 1] = matrix[line][col - 1] + std::min(last[col - 2], last[col - 1]);
            std::swap(now, last);
        }
        return *std::min_element(last.cbegin(), last.cend());
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
