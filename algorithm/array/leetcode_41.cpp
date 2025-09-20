// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO

#include <vector>
#include <cstdint>
#include <cmath>

namespace leetcode_41 {
using std::vector;
#endif

class Solution {
public:
    int32_t firstMissingPositive(vector<int32_t> &nums) {
        const auto nums_size{static_cast<int32_t>(nums.size())};
        for (auto &value: nums) {
            if (value <= 0) {
                value = nums_size + 1;
            }
        }
        for (const auto &value: nums) {
            const auto absV{std::abs(value) - 1};
            if (0 <= absV && absV < nums_size) {
                nums[absV] = -1 * std::abs(nums[absV]);
            }
        }
        nums.push_back(nums_size + 1);
        for (int32_t i{0}; i < nums_size + 1; i++) {
            if (0 < nums[i]) {
                return (i + 1);
            }
        }
        return -1;
    }

    int32_t firstMissingPositive2(vector<int32_t> &nums) {
        const size_t maxv{nums.size()};
        vector<int32_t> num(nums.size() + 1, 0);
        for (size_t i{0}; i < nums.size(); i++) {
            if (0 < nums[i] && nums[i] <= static_cast<int32_t>(maxv)) {
                num[nums[i] - 1] = nums[i];
            }
        }
        for (size_t i{0}; i < num.size(); i++) {
            if (num[i] == 0) {
                return static_cast<int32_t>(i + 1);
            }
        }
        return -1;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
