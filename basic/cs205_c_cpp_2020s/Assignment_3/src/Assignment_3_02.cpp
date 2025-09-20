// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-04-11 12:12:24
 * @LastEditors  : nanoseeds
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int32_t sub_main_assignment_3_02();

void spiral(vector<vector<int32_t>> &matrix, int32_t begin);

#ifndef UNIT_TESTING_ASSIGNMENT_3
#define UNIT_TESTING_ASSIGNMENT_3

int main() {
    return sub_main_assignment_3_02();
    //for unit test, use macro
}

#endif // !UNIT_TESTING_ASSIGNMENT_3

int32_t sub_main_assignment_3_02() {
    int32_t sizes[2] = {0, 0};
    for (int &size: sizes) {
        cin >> size;
        if (cin.fail() || size <= 0) {
            cout << "Please ensure the input is integer that bigger than 0" << endl;
            return -1;
        }
    }//read row and column size
    int32_t size = sizes[0] * sizes[1];
    int32_t length = 0;
    while (size > 0) {
        size /= 10;
        length++;
    }//get the format of output time
    vector<vector<int32_t>> matrix(sizes[0], vector<int32_t>(sizes[1], 0));
    spiral(matrix, 1);

    for (const auto &i: matrix) {
        for (const auto &j: i) {
            cout << std::setw(length + 1) << std::left << j;
        }
        cout << endl;
    }//output
    return 0;
}

void spiral(vector<vector<int32_t>> &matrix, int32_t begin) {
    if (matrix.empty() || matrix[0].empty()) {
        return;
        // illegal input or final of rec, should return
    } else if (1 == matrix.size() && matrix[0].size() > 1) {
        for (int32_t i = matrix[0].size() - 1; i >= 0; i--) {
            matrix[0][i] = begin;
            begin++;
        }
        return;
        //for one line matrix
    } else if (matrix.size() > 1 && 1 == matrix[0].size()) {
        for (auto &i: matrix) {
            i[0] = begin;
            begin++;
        }
        return;
        //for one column matrix
    } else if (1 == matrix.size() && 1 == matrix[0].size()) {
        matrix[0][0] = begin;
        return;
        // for matrix that just have one moment;
    }
    int32_t row = matrix.size();
    int32_t column = matrix[0].size();
    int32_t count = begin;
    for (int i = column - 1; i >= 0; i--, count++) {
        matrix[0][i] = count;
    }
    for (int i = 1; i < row; ++i, count++) {
        matrix[i][0] = count;
    }
    // fill the first row and first column in order
    vector<vector<int32_t>> submatrix(row - 1, vector<int32_t>(column - 1, 0));
    spiral(submatrix, count);
    std::reverse(submatrix.begin(), submatrix.end());
    for (auto &i: submatrix) {
        std::reverse(i.begin(), i.end());
    }
    //create submatrix, recurrence and reverse in row and column
    for (int32_t i = 0; i < static_cast<int32_t>(submatrix.size()); ++i) {
        for (int32_t j = 0; j < static_cast<int32_t>(submatrix[0].size()); ++j) {
            matrix[i + 1][j + 1] = submatrix[i][j];
        }
    }
    // fill other part from submatrix;
}
