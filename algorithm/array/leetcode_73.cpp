// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO

#include <vector>
#include <unordered_set>
#include <algorithm>

namespace leetcode_73 {
using std::vector;
using std::unordered_set;

class Solution {
public:
    void setZeroes(vector<vector<int32_t>> &matrix) {
        if (matrix.empty() || matrix.front().empty()) {
            return;
        }
        const auto row_size{matrix.size()}, col_size{matrix.front().size()};
        const auto row = [&matrix] {
            return std::find(matrix[0].cbegin(), matrix[0].cend(), 0) != matrix[0].cend();
        }(), col = [&matrix, row_size] {
            for (size_t i{0}; i < row_size; ++i) {
                if (matrix[i][0] == 0) {
                    return true;
                }
            }
            return false;
        }();
        for (size_t i{1}; i < row_size; ++i) {
            for (size_t j{1}; j < col_size; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (size_t i{1}; i < row_size; ++i) {
            if (matrix[i][0] == 0) {
                std::fill(matrix[i].begin() + 1, matrix[i].end(), 0);
            }
        }
        for (size_t j{1}; j < col_size; ++j) {
            if (matrix[0][j] == 0) {
                for (size_t i{1}; i < row_size; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (row) {
            std::fill(matrix[0].begin(), matrix[0].end(), 0);
        }
        if (col) {
            for (size_t i{0}; i < row_size; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};

}
#endif
