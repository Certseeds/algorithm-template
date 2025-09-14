// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <cstdint>
#include <cstddef>
#include <vector>
#include <tuple>
#include <algorithm>

using std::vector;

namespace leetcode_1329 {
#endif

namespace unstable {

size_t matrixToLines(const vector<vector<int32_t>> &mat) {
    if (mat.empty()) {
        return 0;
    }
    return mat.size() + mat.front().size() - 1;
}

std::tuple<int32_t, int32_t> matrixBeginNode(const vector<vector<int32_t>> &mat, size_t order) {
    const auto columns{mat.front().size()};
    if (order < columns) {
        return std::make_tuple(0, columns - order - 1);
    }
    return std::make_tuple(order - columns + 1, 0);
}

size_t matrixNodeLength(const vector<vector<int32_t>> &mat, size_t order) {
    const auto rows{mat.size()};
    const auto columns{mat.front().size()};
    const auto minValue{std::min(rows, columns)};
    if (order < minValue) {
        return order;
    } else if (order + 1 > columns && rows + columns < 2 + order + minValue) {
        return rows + columns - 2 - order;
    }
    return minValue - 1;
}

vector<int32_t> readAndSort(const vector<vector<int32_t>> &mat, size_t order) {
    auto [row, column] = matrixBeginNode(mat, order);
    const auto iters{matrixNodeLength(mat, order)};
    vector<int32_t> will_return{};
    for (size_t iter{0}; iter <= iters; ++iter) {
        will_return.push_back(mat[row][column]);
        row += 1;
        column += 1;
    }
    std::sort(will_return.begin(), will_return.end());
    return will_return;
}

void writeOrder(vector<vector<int32_t>> *mat, size_t order, const vector<int32_t> &line) {
    auto [row, column] = matrixBeginNode((*mat), order);
    const auto iters{matrixNodeLength((*mat), order)};
    for (size_t iter{0}; iter <= iters; ++iter) {
        (*mat)[row][column] = line[iter];
        row += 1;
        column += 1;
    }
}

vector<vector<int32_t>> diagonalSort(vector<vector<int32_t>> &mat) {
    const auto nodes{matrixToLines(mat)};
    for (size_t iter{1}; iter + 1 < nodes; ++iter) {
        const auto sortedLines = readAndSort(mat, iter);
        writeOrder(&mat, iter, sortedLines);
    }
    return mat;
}
}

class Solution {
public:
    vector<vector<int32_t>> diagonalSort(const vector<vector<int32_t>> &mat) {
        vector<vector<int32_t>> will_return{mat};
        unstable::diagonalSort(will_return);
        return will_return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
