// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

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

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
