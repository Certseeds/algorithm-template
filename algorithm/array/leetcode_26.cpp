// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <vector>
#include <cstdint>

namespace leetcode_26 {
using std::vector;
#endif

class Solution {
public:
    int32_t removeDuplicates(vector<int32_t> &nums) {
        if (nums.empty()) {
            return 0;
        }
        int32_t last{nums.front() - 1}, count{0};
        for (auto &num: nums) {
            if (num != last) {
                last = num;
                nums[count] = num;
                count++;
            }
        }
        nums.resize(count);
        return count;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
