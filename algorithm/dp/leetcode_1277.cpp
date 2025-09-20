// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds

#include <vector>
#include <algorithm>
#include <cstdint>

#ifdef ALGORITHM_TEST_MACRO
namespace leetcode_1277 {
using std::vector;
#endif

class Solution {
public:
    int32_t countSquares(const vector<vector<int32_t>> &matrix) {
        const auto row{matrix.size()};
        if (0 == row) {
            return 0;
        }
        const auto column{matrix.front().size()};
        if (0 == column) {
            return 0;
        }
        vector<vector<int32_t>> dp(row, vector<int32_t>(column, 0));
        // dp[i][j] 代表以dp[i][j]这个点为右下角的最大正方形的面积
        // dp[0][j],dp[i][0] 最大值都是1
        int32_t will_return{0};
        for (size_t i{0}; i < column; ++i) {
            dp[0][i] = (matrix[0][i] == 1 ? 1 : 0);
            will_return += dp[0][i];
        }
        for (size_t j{1}; j < row; ++j) {
            dp[j][0] = (matrix[j][0] == 1 ? 1 : 0);
            will_return += dp[j][0];
        }
        for (size_t i{1}; i < row; ++i) {
            for (size_t j{1}; j < column; ++j) {
                if (matrix[i][j] == 0) {
                    dp[i][j] = 0;
                } else {
                    // 这里是重点,决定递推关系
                    // 首先,判断递推顺序,换句话讲, 查看已有信息
                    // 很常见的推论: dp[i][j] 依赖dp[i-1][j-1],dp[i][j-1],dp[i-1][j]
                    // 接着要拿到递推关系式, 先分别将三个依赖取到0,其他任意,会发现此时dp[i][j]只能取1
                    // 再将三个依赖分别取到极大值, 其他的任意,会发现dp[i][j]依赖于其中的最小值
                    // 得出:１.　三个值和位置无关，可以替换; 2. 和最小值有关
                    // 得出结论
                    dp[i][j] = std::min({dp[i][j - 1], dp[i - 1][j - 1], dp[i - 1][j]}) + 1;
                    will_return += dp[i][j];
                }
            }
        }
        return will_return;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
