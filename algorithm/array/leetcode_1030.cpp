// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <vector>
#include <algorithm>
#include <cstdlib>

namespace leetcode_1030 {
using std::vector;
#endif

class Solution {
public:
    vector<vector<int32_t>> allCellsDistOrder(int32_t rows, int32_t cols, int32_t rCenter, int32_t cCenter) {
        const auto distance = [rCenter, cCenter](int32_t x, int32_t y) {
            return std::abs(rCenter - x) + std::abs(cCenter - y);
        };
        const auto max_distance = std::max(
                {distance(0, 0), distance(0, cols - 1), distance(rows - 1, 0), distance(rows - 1, cols - 1)}
        );
        vector<vector<int32_t>> will_return{{rCenter, cCenter}};
        const auto in = [rows, cols, &will_return](int32_t x, int32_t y) {
            const auto judge = (0 <= x && x < rows) && (0 <= y && y < cols);
            if (judge) {
                will_return.push_back({x, y});
            }
        };
        for (int32_t i{1}; i <= max_distance; ++i) {
            in(rCenter, cCenter + i);
            in(rCenter, cCenter - i);
            for (int32_t j{1}; j < i; ++j) {
                const auto row{j}, col{i - j};
                in(rCenter + row, cCenter + col);
                in(rCenter + row, cCenter - col);
                in(rCenter - row, cCenter + col);
                in(rCenter - row, cCenter - col);
            }
            in(rCenter + i, cCenter);
            in(rCenter - i, cCenter);
        }
        return will_return;
    }

    vector<vector<int32_t>> allCellsDistOrderNLogN(int32_t rows, int32_t cols, int32_t rCenter, int32_t cCenter) {
        struct point final {
            int32_t x{0}, y{0};

            point(int32_t x, int32_t y) : x(x), y(y) {};

            bool operator<(const point &p) const {
                return abs(x) + abs(y) < abs(p.x) + abs(p.y);
            }
        };
        vector<point> pois;
        vector<vector<int32_t>> willreturn;
        for (int32_t i{0}; i < rows; i++) {
            for (int32_t j{0}; j < cols; j++) {
                pois.emplace_back(i - rCenter, j - cCenter);
            }
        }
        sort(pois.begin(), pois.end(), std::less<point>());
        for (size_t i{0}; i < pois.size(); i++) {
            willreturn.emplace_back(vector<int32_t>{pois[i].x + rCenter, pois[i].y + cCenter});
        }
        return willreturn;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
