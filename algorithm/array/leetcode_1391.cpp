// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2023  nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <cstdint>
#include <cstddef>
#include <vector>

using std::vector;

namespace leetcode_1391 {
#endif

enum direction {
    left_to_right = 1,
    up_to_down = 2,
    left_to_down = 3,
    down_to_right = 4,
    left_to_up = 5,
    up_to_right = 6,
};

class Solution {
public:
    // 他得有一个额外的变量记录方向, 从而决定下一步的方向.
    bool hasValidPath(vector<vector<int32_t>> &grid) {
        const auto row = grid.size();
        if (row == 0) {
            return true;
        }
        const auto col = grid[0].size();
        if (col == 0) {
            return true;
        }
        if (grid[0][0] == direction::left_to_up) {
            return false;
        } else if (grid[0][0] == direction::down_to_right) {
            grid[0][0] = direction::left_to_right;
            const auto v1 = hasValidPath(grid);
            if (v1) {
                return true;
            }
            grid[0][0] = direction::up_to_down;
            return hasValidPath(grid);
        }
        size_t i{0}, j{0}, direction{0};//0 to right, 1 to down, 2 to left,3 to up
        switch (grid[0][0]) {
            case direction::left_to_right: {
                direction = 0;
                break;
            }
            case direction::up_to_down: {
                direction = 1;
                break;
            }
            case direction::left_to_down: {
                direction = 1;
                break;
            }
            case direction::up_to_right: {
                direction = 0;
                break;
            }
        }
        vector<vector<uint8_t>> vec(row, vector<uint8_t>(col, 0));
        while (i < row && j < col) {
            if (i == row - 1 && j == col - 1) {
                return true;
            }
            if (vec[i][j] == 1) {
                return false;
            }
            vec[i][j] = 1;
            switch (direction) {
                case 0: {
                    if (j + 1 < col) {
                        if (grid[i][j + 1] == direction::left_to_right) {
                            j += 1;
                            continue;
                        } else if (grid[i][j + 1] == direction::left_to_down) {
                            j += 1;
                            direction = 1;
                            continue;
                        } else if (grid[i][j + 1] == direction::left_to_up) {
                            j += 1;
                            direction = 3;
                            continue;
                        } else {
                            return false;
                        }
                    } else {
                        return false;
                    }
                }
                case 1: {
                    if (i + 1 < row) {
                        if (grid[i + 1][j] == direction::up_to_down) {
                            i += 1;
                            continue;
                        } else if (grid[i + 1][j] == direction::left_to_up) {
                            i += 1;
                            direction = 2;
                            continue;
                        } else if (grid[i + 1][j] == direction::up_to_right) {
                            i += 1;
                            direction = 0;
                            continue;
                        } else {
                            return false;
                        }
                    } else {
                        return false;
                    }
                }
                case 2: {
                    if (j > 0) {
                        if (grid[i][j - 1] == direction::left_to_right) {
                            j -= 1;
                            continue;
                        } else if (grid[i][j - 1] == direction::down_to_right) {
                            j -= 1;
                            direction = 1;
                            continue;
                        } else if (grid[i][j - 1] == direction::up_to_right) {
                            j -= 1;
                            direction = 3;
                            continue;
                        } else {
                            return false;
                        }
                    } else {
                        return false;
                    }
                }
                case 3: {
                    if (i > 0) {
                        if (grid[i - 1][j] == direction::up_to_down) {
                            i -= 1;
                            continue;
                        } else if (grid[i - 1][j] == direction::left_to_down) {
                            i -= 1;
                            direction = 2;
                            continue;
                        } else if (grid[i - 1][j] == direction::down_to_right) {
                            i -= 1;
                            direction = 0;
                            continue;
                        } else {
                            return false;
                        }
                    } else {
                        return false;
                    }
                }
            }
        }
        return false;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
