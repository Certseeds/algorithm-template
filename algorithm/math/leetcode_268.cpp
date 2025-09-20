// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <numeric>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_268 {
using std::vector;
#endif

class Solution {
public:
    int32_t missingNumber(const vector<int32_t> &nums) {
        const auto nums_size = static_cast<int32_t>(nums.size());
        return nums_size * (nums_size + 1) / 2 - std::accumulate(nums.begin(), nums.end(), 0);
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
