// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO
#include <vector>
#include <queue>
#include <cstdint>
#include <array>

namespace leetcode_so_13 {
using std::vector;
using std::queue;
#endif

class Solution {
public:
    int32_t movingCount(int32_t m, int32_t n, int32_t k) {
        vector<vector<uint8_t>> visit(m + 2, vector<uint8_t>(n + 2, false));
        for (int32_t i{0}; i < n + 2; i++) {
            visit[0][i] = true;
            visit[m + 1][i] = true;
        }
        for (int32_t i{0}; i < m + 2; i++) {
            visit[i][0] = true;
            visit[i][n + 1] = true;
        }
        visit[1][1] = true;
        static constexpr const auto sums = [](auto num) {
            int32_t sum{0};
            for (; num != 0; num /= 10) { sum += num % 10; }
            return sum;
        };
        static constexpr const std::array<const std::array<int32_t, 2>, 4> path{{{1, 0},
                                                                           {-1, 0},
                                                                           {0, 1},
                                                                           {0, -1}}};
        int32_t nums{0};
        for (queue<std::pair<int32_t, int32_t>> que{{{1, 1}}}; !que.empty(); ++nums) {
            const auto head = que.front();
            que.pop();
            for (const auto&[row, col]: path) {
                const auto x{head.first + row}, y{head.second + col};
                if (!visit[x][y] &&
                    sums(x - 1) + sums(y - 1) <= k) {
                    que.push({x, y});
                    visit[x][y] = true;
                }
            }
        }
        return nums;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
