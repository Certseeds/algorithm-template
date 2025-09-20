// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO

#include <vector>
#include <algorithm>

namespace leetcode_908 {
using std::vector;
#endif

class Solution {
public:
    int32_t smallestRangeI(const vector<int32_t> &nums, int32_t k) {
        int min{0x3f3f3f3f}, max{0};
        for (const auto num: nums) {
            min = std::min(min, num);
            max = std::max(max, num);
        }
        return (max - min >= 2 * k ? max - min - 2 * k : 0);
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
