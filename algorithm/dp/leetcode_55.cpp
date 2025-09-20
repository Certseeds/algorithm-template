// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds

#include <vector>
#include <algorithm>
#include <cstdint>

#ifdef ALGORITHM_TEST_MACRO
namespace leetcode_55 {
using std::vector;
#endif

class Solution {
public:
    bool canJump(const vector<int32_t> &nums) {
        const auto nums_size{nums.size()};
        if (nums_size <= 1) {
            return true;
        }
        size_t fst{0}, end = nums[0];
        while (fst < end) {
            const size_t next = end;
            for (size_t now{fst}; now <= next; now++) {
                end = std::max(now + nums[now], end);
                if (end + 1 >= nums_size) {
                    return true;
                }
            }
            fst = next;
        }
        return end + 1 >= nums_size;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
