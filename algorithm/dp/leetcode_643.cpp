// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanos

*/

#include <vector>
#include <numeric>
#include <algorithm>
#include <cstdint>

#ifdef CS203_DSAA_TEST_MACRO
namespace leetcode_643 {
using std::vector;
#endif

class Solution {
public:
    double findMaxAverage(const vector<int32_t> &nums, int32_t k) {
        const auto nums_size{nums.size()};
        if (nums_size <= static_cast<size_t>(k)) {
            return double(std::accumulate(nums.begin(), nums.end(), 0)) /
                   static_cast<double>(nums_size);
        }
        vector<int32_t> DP(nums_size - k + 1);
        DP[0] = std::accumulate(nums.begin(), nums.begin() + k, 0);
        int willreturn = DP[0];
        for (size_t i{1}; i + k <= nums_size; i++) {
            DP[i] = DP[i - 1] - nums[i - 1] + nums[k + i - 1];
            willreturn = std::max(willreturn, DP[i]);
        }
        return willreturn / double(k);
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
