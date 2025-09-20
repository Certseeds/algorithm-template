// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <vector>

namespace leetcode_905 {
using std::vector;
#endif

class Solution {
public:
    vector<int32_t> sortArrayByParity(vector<int32_t> &nums) {
        const auto nums_size{nums.size()};
        for (size_t begin{0}, end{nums_size - 1}; begin < end; std::swap(nums[begin], nums[end])) {
            for (; ((nums[begin] & 1) == 0) && (begin < end); ++begin) {}
            for (; ((nums[end] & 1) == 1) && (begin < end); --end) {}
        }
        return nums;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
