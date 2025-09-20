// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO

#include "disjoint_set.hpp"
#include "disjoint_set.cpp"
#include <unordered_set>
#include <string>
#include <cstddef>
#include <vector>

namespace leetcode_200 {
using std::string;
using ::disjoint_set::disjoint_set;
using ::disjoint_set::getDisjointSet;
using std::unordered_set;
using std::vector;
#endif

enum GRID : char {
    WATER = '0',
    LAND = '1'
};

class Solution {
public:
    int numIslands(const vector<vector<char>> &grid) {
        if (grid.empty() || grid.back().empty()) {
            return 0;
        }
        const auto x_size{grid.size()}, y_size{grid.back().size()};
        vector<vector<char>> grids(x_size + 1, vector<char>(y_size + 1, 0));
        for (size_t i{0}; i < x_size; i++) {
            for (size_t j{0}; j < y_size; j++) {
                grids[i][j] = grid[i][j];
            }
        }
        const auto x_size2{x_size + 1}, y_size2{y_size + 1}, grid_size2{x_size2 * y_size2};
        const auto loca = [y_size2](auto x, auto y) {
            return x * y_size2 + y + 1;
        };
        const auto jset = getDisjointSet(grid_size2);
        for (size_t i{0}; i < x_size; ++i) {
            for (size_t j{0}; j < y_size; ++j) {
                if (grids[i][j] == GRID::LAND) {
                    if (grids[i + 1][j] == GRID::LAND) {
                        jset->merge(loca(i + 1, j), loca(i, j));
                    }
                    if (grids[i][j + 1] == GRID::LAND) {
                        jset->merge(loca(i, j + 1), loca(i, j));
                    }
                }
            }
        }
        std::unordered_set<size_t> uset;
        for (size_t i{0}; i < x_size; ++i) {
            for (size_t j{0}; j < y_size; ++j) {
                if (grids[i][j] == GRID::LAND) {
                    uset.insert(jset->find(loca(i, j)));
                }
            }
        }
        return uset.size();
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
