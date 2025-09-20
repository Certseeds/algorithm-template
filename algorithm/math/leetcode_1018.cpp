// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO

#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_1018 {
using std::vector;
#endif

class Solution {
public:
    vector<bool> prefixesDivBy5(const vector<int32_t> &nums) {
        const auto nums_size{nums.size()};
        vector<bool> willreturn(nums_size);
        for (size_t i{0}, num{0}; i < nums_size; ++i) {
            num = (2 * num + nums[i]) % 5;
            willreturn[i] = (num == 0);
        }
        return willreturn;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
