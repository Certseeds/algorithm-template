// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-04-11 10:39:25
 * @LastEditors  : nanoseeds
 */
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int32_t sub_main_assignment_3_01();

void fill_grid(vector<vector<int8_t>> &grid, vector<int32_t> &bullet);

static const vector<vector<int32_t>> possibility{
        {1,  1},
        {1,  0},
        {1,  -1},
        {0,  1},
        {0,  -1},
        {-1, 1},
        {-1, 0},
        {-1, -1}
};

#ifndef UNIT_TESTING_ASSIGNMENT_3
#define UNIT_TESTING_ASSIGNMENT_3

int main() {
    return sub_main_assignment_3_01();
    //for unit test, use macro
}

#endif // !UNIT_TESTING_ASSIGNMENT_3

int32_t sub_main_assignment_3_01() {
    int32_t basic[3];
    for (int &i: basic) {
        cin >> i;
        if (cin.fail() || i <= 0) {
            cout << "Error input,Please try once again." << endl;
            return -1;
        }
    }//read data
    vector<vector<int8_t>> grid(basic[0], vector<int8_t>(basic[1], 0));
    vector<vector<int32_t>> input(basic[2], vector<int32_t>(4, 0));
    for (int32_t i = 0; i < basic[2]; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> input[i][j];
            if (cin.fail()) {
                cout << "Error input, Please run once again." << endl;
                return -1;
            }
        }//read data
        if ((input[i][0] < 0 || input[i][0] >= basic[0]) ||
            (input[i][1] < 0 || input[i][1] >= basic[1])) {
            cout << "Error, input begin point out of range,Please run again." << endl;
            return -1;
        }// if size is output of range,it's error
        bool appear = false;
        for (const auto &k: possibility) {
            if (k[0] == input[i][2] && k[1] == input[i][3]) {
                appear = true;
            }
        }
        if (!appear) {
            cout << "Error, input direction is not allowed." << endl;
            //output should only be one of eight kind.
            return -1;
        }
        fill_grid(grid, input[i]);
        // fill a line.
    }
    int32_t count = 0;
    for (const auto &row: grid) {
        for (const auto &item: row) {
            count += (item == 0);
            //count numbers.
        }
    }
    cout << count << endl;
    return 0;
}

void fill_grid(vector<vector<int8_t>> &grid, vector<int32_t> &bullet) {
    //file the grid.
    int32_t begin_x = bullet[0];
    int32_t begin_y = bullet[1];
    while (true) {
        if (begin_x < 0 || begin_x >= static_cast<int32_t>(grid.size()) ||
            begin_y < 0 || begin_y >= static_cast<int32_t>(grid[0].size())) {
            return;
        }
        grid[begin_x][begin_y] = true;
        begin_x += bullet[2];
        begin_y += bullet[3];
    }
}
