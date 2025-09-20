// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO

#include <vector>
#include <algorithm>

namespace leetcode_977 {
using std::vector;
#endif

class Solution {
public:
    vector<int32_t> sortedSquares(const vector<int32_t> &nums) {
        const auto nums_size{nums.size()};
        static constexpr const auto cmp = [](int32_t x, int32_t y) {
            return x * x <= y * y;
        };
        vector<int32_t> will_return{};
        const size_t posi = std::min_element(nums.cbegin(), nums.cend(), cmp) - nums.cbegin();
        size_t left{posi + 1}, right{posi + 1};
        while (0 < left && right < nums_size) {
            const auto cmpValue = cmp(nums[left - 1], nums[right]);
            if (cmpValue) {
                will_return.push_back(nums[left - 1] * nums[left - 1]);
                --left;
            } else {
                will_return.push_back(nums[right] * nums[right]);
                ++right;
            }
        }
        for (; 0 < left; --left) { will_return.push_back(nums[left - 1] * nums[left - 1]); }
        for (; right < nums_size; ++right) { will_return.push_back(nums[right] * nums[right]); }
        return will_return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
