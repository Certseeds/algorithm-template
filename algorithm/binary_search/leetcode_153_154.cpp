
// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO
#include <cstdint>
#include <cstddef>
#include <vector>
namespace leetcode_154 {
using std::vector;

#endif


class Solution {
public:
    int32_t findMin(const vector<int32_t> &nums) {
        size_t begin{0}, middle{0};
        size_t end{nums.size() - 1};
        while (begin < end) {
            middle = (end - begin) / 2 + begin;
            if (nums[middle] > nums[end]) {
                begin = middle + 1;
            } else if (nums[middle] < nums[end]) {
                end = middle;
            } else {
                end--;
            }
        }
        return nums[begin];
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
