// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO

#include <cstddef>
#include <vector>

namespace leetcode_238 {
using std::vector;
using std::size_t;
#endif

class Solution {
public:
    vector<int32_t> productExceptSelf(const vector<int32_t> &nums) {
        const auto nums_size{nums.size()};
        vector<int32_t> pre(nums_size, 1), post(nums_size, 1), mid(nums_size, 1);
        for (size_t i{1}; i < nums_size; ++i) {
            pre[i] = pre[i - 1] * nums[i - 1];
            post[nums_size - 1 - i] = post[nums_size - i] * nums[nums_size - i];
        }
        for (size_t i{0}; i < nums_size; ++i) {
            mid[i] = pre[i] * post[i];
        }
        return mid;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
