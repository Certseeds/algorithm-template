// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO

#include <vector>
#include <algorithm>
#include <cstdint>

namespace leetcode_11 {
using std::vector;
#endif

class Solution {
public:
    int32_t maxArea(const vector<int32_t> &height) {
        int32_t left{0},
                right = static_cast<int32_t>(height.size() - 1);
        const auto water = [&height](const auto lhs, const auto rhs) {
            return (rhs - lhs) * std::min(height[lhs], height[rhs]);
        };
        int32_t will_return = water(left, right);
        while (left < right) {
            if (height[left] >= height[right]) {
                right--;
            } else {
                left++;
            }
            will_return = std::max(will_return, water(left, right));
        }
        return will_return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
