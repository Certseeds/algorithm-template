// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/

#ifdef CS203_DSAA_TEST_MACRO
#include <cstddef>
#include <cstdint>
#include <vector>
namespace leetcode_221 {
using std::vector;
#endif

class Solution {
private:
    static constexpr const auto base{'0'};

public:
    int32_t maximalSquare(const vector<vector<char>> &matrix) {
        if (matrix.empty() || matrix.front().empty()) {
            return {};
        }
        const auto row{matrix.size()}, col{matrix.front().size()};
        vector<vector<int32_t>> range(row + 1, vector<int32_t>(col + 1));
        for (size_t i{0}; i < row; i++) {
            for (size_t j{0}; j < col; j++) {
                range[i + 1][j + 1] = range[i][j + 1] + range[i + 1][j] - range[i][j] + (matrix[i][j] - base);
            }
        }
        size_t maxV{0}; // O(mn*min(m,n))
        for (size_t i{1}; i <= row; i++) {
            for (size_t j{1}; j <= col; j++) {
                const auto leftUp{range[i - 1][j - 1]};
                size_t x{i + 1}, y{j + 1};
                if (matrix[i - 1][j - 1] != base) {
                    maxV = std::max(maxV, static_cast<size_t>(1));
                    while (x <= row && y <= col) {
                        const size_t diff = range[x][y] - range[i - 1][y] - range[x][j - 1] + leftUp;
                        if (diff != (x - i + 1) * (x - i + 1)) {
                            break;
                        } else {
                            maxV = std::max(maxV, diff);
                            x++, y++;
                        }
                    }
                }
            }
        }
        return static_cast<size_t>(maxV);
    }

    int32_t maximalSquare2(const vector<vector<char>> &matrix) {
        if (matrix.empty() || matrix.front().empty()) {
            return {};
        }
        const auto row{matrix.size()}, col{matrix.front().size()};
        vector<vector<int32_t>> dp(row + 1, vector<int32_t>(col + 1));
        int32_t maxV{0};
        for (size_t i{0}; i < row; i++) {
            for (size_t j{0}; j < col; j++) {
                dp[i + 1][j + 1] = (
                        matrix[i][j] == base ?
                        0
                                             :
                        std::min({dp[i][j], dp[i + 1][j], dp[i][j + 1]}) + 1
                );
                maxV = std::max(maxV, dp[i + 1][j + 1]);
            }
        }
        return maxV * maxV;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
