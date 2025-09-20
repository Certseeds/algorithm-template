// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO

#include "basic.hpp"
#include <algorithm>
#include <vector>
#include <functional>

namespace leetcode_1237 {
using CustomFunction = std::function<int32_t(int32_t x, int32_t y)>;
using std::vector;
#endif


class Solution {
private:
    int32_t getXMin(const CustomFunction &customfunction, int32_t z) {
        // fst step, find the minimum x
        // 如果f(1,1)就已经大于z了,就不需要进行了,直接退出
        // 如果(50,1000)等于z, 说明(49,1000)小于z, 需要从50开始
        // 如果(50,1000)大于z, 说明(49,1000)小于z, 需要从50开始
        // 如果(50,1000)大于z, 说明(49,1000)等于z, 需要从49开始
        const auto y{1000};
        for (int32_t x_left{1}, x_right{1000}; x_left < x_right;) {
            const auto mid = (x_right - x_left) / 2 + x_left;
            const auto value{customfunction(mid, y)};
            if (value == z) {
                return mid;
            } else if (value > z) {
                const auto midM1{mid - 1};
                const auto valueM1{customfunction(midM1, y)};
                if (valueM1 < z) {
                    return mid;
                }
                x_right = mid;
            } else {
                x_left = mid + 1;
            }
        }
        return 1;
    }

    int32_t getXMax(const CustomFunction &customfunction, int32_t z) {
        // fst step, find the minimum x
        // 如果f(1,1)就已经大于z了,就不需要进行了,直接退出
        // 如果(50,1)等于z, 说明(51,1)大于z, 截止到50
        // 如果(50,1)小于z, 说明(51,1)大于z, 截止到50
        const auto y{1};
        for (int32_t x_left{1}, x_right{1000}; x_left < x_right;) {
            const auto mid = (x_right - x_left) / 2 + x_left;
            const auto value{customfunction(mid, y)};
            if (value == z) {
                return mid;
            } else if (value < z) {
                const auto midP1 = mid + 1;
                const auto valueP1{customfunction(midP1, y)};
                if (valueP1 > z) {
                    return mid;
                }
                x_left = mid + 1;
            } else {
                x_right = mid;
            }
        }
        return 1000;
    }

public:
    vector<vector<int32_t>> findSolution(const CustomFunction &customfunction, int32_t z) {
        vector<vector<int32_t>> will_return{};
        if (customfunction(1, 1) > z) {
            return will_return;
        } // O(1)守门
        const auto xmin{getXMin(customfunction, z)}; // log(n)
        const auto xmax{getXMax(customfunction, z)}; // log(n)
        for (int32_t i{xmin}, y_righest{1000}; i <= xmax; ++i) { // log(n) for each step
            // f(x1,y1) == z
            // then, for f(x1+1,y2) == z, y2<y1
            for (int32_t y_left{1}, y_right{y_righest}; y_left < y_right;) {
                const auto mid = (y_right - y_left) / 2 + y_left;
                const auto value = customfunction(i, mid);
                if (value > z) {
                    y_right = mid;
                } else if (value == z) {
                    will_return.emplace_back(vector<int32_t>{i, mid});
                    y_righest = y_right;
                    break;
                } else {
                    y_left = mid + 1;
                }
            }
        }
        return will_return;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
