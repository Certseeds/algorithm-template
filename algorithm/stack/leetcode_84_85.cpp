// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO

#include <stack>
#include <vector>
#include <cstdint>
#include <cstddef>
#include <algorithm>

namespace leetcode_84 {
using std::stack;
using std::vector;
#endif

class Solution {
public:
    int32_t largestRectangleArea(const vector<int32_t> &heights) {
        const auto height_size{static_cast<int32_t>(heights.size())};
        // 我们要找到 左侧最近的 小于当前高度的 坐标
        // 极限模型: 一个从左到右单调增的序列,全部都是 i-1
        // 因此使用递增栈
        stack<int32_t> staL;
        vector<int32_t> left(height_size);
        for (int32_t i{0}; i < height_size; i++) {
            while (!staL.empty() && heights[i] <= heights[staL.top()]) {
                staL.pop();
            }
            left[i] = staL.empty() ? -1 : staL.top();
            staL.push(i);
        }
        stack<int32_t> staR;
        vector<int32_t> right(height_size);
        for (int32_t i{height_size - 1}; i >= 0; i--) {
            while (!staR.empty() && heights[i] <= heights[staR.top()]) {
                staR.pop();
            }
            right[i] = staR.empty() ? height_size : staR.top();
            staR.push(i);
        }
        int32_t will_return{-1};
        for (int32_t i{0}; i < height_size; i++) {
            will_return = std::max(will_return, (right[i] - left[i] - 1) * heights[i]);
        }
        return will_return;
    }

    int32_t maximalRectangle(const vector<vector<char>> &matrix) {
        if (matrix.empty() || matrix.front().empty()) {
            return 0;
        }
        const auto col_size{matrix.size()}, row_size{matrix.front().size()};
        vector<vector<int32_t>> heights(col_size, vector<int32_t>(row_size, 0));
        for (size_t j{0}; j < row_size; ++j) {
            heights[0][j] = matrix[0][j] - '0';
        }
        int32_t will_return{largestRectangleArea({heights[0].cbegin(), heights[0].cend()})};
        for (size_t i{1}; i < col_size; ++i) {
            for (size_t j{0}; j < row_size; ++j) {
                const auto now{(matrix[i][j] - '0')};
                heights[i][j] = now ? (now + heights[i - 1][j]) : 0;
            }
            will_return = std::max(will_return, largestRectangleArea(
                    {heights[i].cbegin(), heights[i].cend()}));
        }
        return will_return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
