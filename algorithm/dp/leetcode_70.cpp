// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO

#include <vector>
#include <algorithm>
#include <array>
#include <cstdint>

namespace leetcode_70 {
using std::vector;
#endif

class Solution {
public:
    int32_t climbStairs(int32_t n) {
        int32_t b{1};
        for (int32_t a{0}, i{0}, temp{-1}; i < n; i++) {
            temp = a;
            a = b;
            b = temp + a;
        }
        return b;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif