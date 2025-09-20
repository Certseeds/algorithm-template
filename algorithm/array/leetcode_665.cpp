// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds

#ifdef ALGORITHM_TEST_MACRO

#include <cstdint>
#include <vector>

namespace leetcode_665 {
using std::vector;
#endif

class Solution {
public:
    bool checkPossibility(const vector<int32_t> &nums) {
        int32_t count{0};
        size_t position{0};
        for (size_t i{0}; i < nums.size() - 1; i++) {
            if (nums[i] - nums[i + 1] > 0) {
                count++;
                position = i;
            }
        }
        if (count > 1) {
            return false;
        }
        if (position == 0 || position == nums.size() - 1) {
            return true;
        }
        bool first{true}, second{true};
        if (nums[position - 1] > nums[position + 1]) {
            first = false;
        }
        for (size_t i = position + 1; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                first = false;
            }
        }
        if (position < nums.size() - 2) {
            if (nums[position] > nums[position + 2]) {
                return first;
            }
            for (size_t i = position + 1; i < nums.size() - 1; i++) {
                if (nums[i] > nums[i + 1]) {
                    return first;
                }
            }
        }
        return first || second;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
