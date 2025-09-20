// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO

#include <cstdint>
#include <vector>

namespace leetcode_136 {
using std::vector;
#endif

class Solution {
public:
    int singleNumber(const vector<int32_t> &nums) {
        int will_return{0};
        for (const auto num: nums) {
            will_return ^= num;
        }
        return will_return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
