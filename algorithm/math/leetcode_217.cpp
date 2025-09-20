// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO

#include <cstdint>
#include <cstddef>
#include <vector>
#include <unordered_set>

namespace leetcode_217 {
using std::vector;
using std::unordered_set;
#endif

class Solution {
public:
    bool containsDuplicate(const vector<int32_t> &nums) {
        unordered_set<int32_t> judges;
        for (size_t i{0}, nums_size{nums.size()}; i < nums_size; i++) {
            if (judges.count(nums[i]) != 0) {
                return true;
            } else {
                judges.insert(nums[i]);
            }
        }
        return false;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
