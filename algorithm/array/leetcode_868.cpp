// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO

#include <algorithm>
#include <cstdint>
#include <vector>

namespace leetcode_868 {
using std::vector;
#endif

class Solution {
public:
    int32_t binaryGap(int32_t N) {
        vector<int32_t> ones;
        ones.reserve(32);
        while (N > 0) {
            ones.push_back(N % 2);
            N /= 2;
        }
        vector<size_t> pos;
        const auto ones_size{ones.size()};
        for (size_t i{0}; i < ones_size; ++i) {
            if (1 == ones[i]) {
                pos.push_back(i);
            }
        }
        const auto pos_size{pos.size()};
        size_t diff{0};
        for (size_t i{0}; i < pos_size - 1; i++) {
            diff = std::max(diff, pos[i + 1] - pos[i]);
        }
        return static_cast<int32_t>(diff);
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
