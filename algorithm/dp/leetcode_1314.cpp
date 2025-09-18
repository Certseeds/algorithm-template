// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/

#ifdef CS203_DSAA_TEST_MACRO

#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_1314 {
using std::vector;
#endif

class Solution {
private:
    vector<vector<int32_t>> init(const vector<vector<int32_t>> &matrix) {
        if (matrix.empty() || matrix.front().empty()) {
            return {};
        }
        const auto row{matrix.size()}, col{matrix.front().size()};
        vector<vector<int32_t>> range(row + 1, vector<int32_t>(col + 1));
        for (size_t i{0}; i < row; i++) {
            for (size_t j{0}; j < col; j++) {
                range[i + 1][j + 1] = range[i][j + 1] + range[i + 1][j] - range[i][j] + matrix[i][j];
            }
        }
        return range;
    }

public:
    vector<vector<int32_t>> matrixBlockSum(const vector<vector<int32_t>> &mat, int32_t K) {
        if (mat.empty() || mat.front().empty()) {
            return {};
        }
        const auto k = static_cast<size_t>(K);
        const auto row{mat.size()}, col{mat.front().size()};
        const vector<vector<int32_t>> dp{init(mat)};
        vector<vector<int32_t>> will_return(row, vector<int32_t>(col));
        for (size_t i{0}; i < row; ++i) {
            const size_t left{i > k ? i - k : 0};
            const size_t right{std::min(i + k, row - 1)};
            for (size_t j{0}; j < col; ++j) {
                const size_t head{j > k ? j - k : 0};
                const size_t loot{std::min(j + k, col - 1)};
                will_return[i][j] = dp[right + 1][loot + 1] - dp[left][loot + 1] - dp[right + 1][head] +
                                    dp[left][head];
            }
        }
        return will_return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
