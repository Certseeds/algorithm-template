// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO

#include <cstdint>

namespace leetcode_461 {
#endif

class Solution {
public:
    int32_t hammingDistance(int32_t x, int32_t y) {
        int32_t count{0};
        for (int32_t temp{x ^ y}; temp != 0; temp = temp >> 1) {
            count += (temp & 1);
        }
        return count;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
