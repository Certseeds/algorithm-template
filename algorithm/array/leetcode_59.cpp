// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO

#include <vector>
#include <functional>
#include <cstdint>

namespace leetcode_59 {
using std::vector;
#endif

class Solution {
public:
    vector<vector<int32_t>> generateMatrix(int32_t n) {
        vector<vector<int32_t>> will_return(n, vector<int32_t>(n, 0));
        int32_t counter{1};
        using func_type = std::function<std::pair<int32_t, int32_t>(size_t, size_t, int32_t)>;
        const func_type rightDown = [&will_return, &counter]
                (size_t x, size_t y, int32_t steps) -> std::pair<int32_t, int32_t> {
            will_return[x][y] = counter;
            for (int32_t step{0}; step < steps; ++counter, ++y, will_return[x][y] = counter, ++step) {}
            for (int32_t step{0}; step < steps; ++counter, ++x, will_return[x][y] = counter, ++step) {}
            counter++;
            return {x, y - 1}; // 到达右下角,左移一位
        };
        const func_type leftup = [&will_return, &counter]
                (size_t x, size_t y, int32_t steps) -> std::pair<int32_t, int32_t> {
            will_return[x][y] = counter;
            for (int32_t step{0}; step < steps; ++counter, --y, will_return[x][y] = counter, ++step) {}
            for (int32_t step{0}; step < steps; ++counter, --x, will_return[x][y] = counter, ++step) {}
            counter++;
            return {x, y + 1}; // 到达左上角,右移一位
        };
        for (int32_t i{0}, x{0}, y{0}; i < n; ++i) {
            const auto func = (i % 2 == 0) ? rightDown : leftup;
            const auto next = func(x, y, n - i - 1);
            x = next.first, y = next.second;
        }
        return will_return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
