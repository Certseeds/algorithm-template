// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO

#include <vector>
#include <algorithm>
#include <cstdint>

namespace leetcode_31 {
using std::vector;
#endif

class Solution {
public:
    void nextPermutation(vector<int32_t> &nums) {
        if (nums.size() <= 1) {
            return;
        }
        size_t j{nums.size() - 1};
        for (; j > 0; j--) {
            if (nums[j - 1] < nums[j]) {
                break;
            }
        }
        if (j == 0) {
            std::reverse(nums.begin(), nums.end());
            return;
        }
        for (size_t k = nums.size() - 1; k >= j; k--) {
            if (nums[k] > nums[j - 1]) {
                std::swap(nums[k], nums[j - 1]);
                break;
            }
        }
        std::reverse(nums.begin() + j, nums.end());
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
