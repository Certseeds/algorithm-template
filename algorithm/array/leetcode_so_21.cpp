// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO

#include <cstddef>
#include <cstdint>
#include <vector>

using std::vector;

namespace leetcode_so_21 {
#endif

class Solution {
public:
    vector<int32_t> exchange(const vector<int32_t> &nums_const) {
        if (nums_const.empty()) {
            return {};
        }
        vector<int32_t> nums{nums_const};
        static constexpr const auto judge = [](const auto num) -> bool { return num % 2 == 0; };
        // 实际上完全可以是左边模三余1,右边余0,2
        const auto nums_size{nums.size()};
        for (size_t left{0}, right{nums_size - 1}; left < right;) {
            for (; left < right && !judge(nums[left]); ++left) {
            }
            for (; left < right && judge(nums[right]); --right) {
            }
            if (left >= right) {
                return nums;
            }
            std::swap(nums[left], nums[right]);
        }
        return nums;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
