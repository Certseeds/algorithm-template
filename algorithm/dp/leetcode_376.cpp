// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds

#include <vector>
#include <algorithm>
#include <cstdint>

#ifdef CS203_DSAA_TEST_MACRO
namespace leetcode_376 {
using std::vector;
#endif

class Solution {
public:
    int32_t wiggleMaxLength(const vector<int32_t> &nums) {
        const auto nums_size{nums.size()};
        if (nums_size <= 1) {
            return static_cast<int32_t>(nums_size);
        }
        vector<int32_t> dpInc(nums_size, 1), dpDec(nums_size, 1);
        for (size_t i{1}; i < nums_size; i++) {
            for (size_t j{0}; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dpInc[i] = std::max(dpInc[i], dpDec[j] + 1);
                } else if (nums[i] < nums[j]) {
                    dpDec[i] = std::max(dpDec[i], dpInc[j] + 1);
                }
            }
        }
        return std::max(
                *std::max_element(std::cbegin(dpInc), std::cend(dpInc)),
                *std::max_element(std::cbegin(dpDec), std::cend(dpDec))
        );
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
