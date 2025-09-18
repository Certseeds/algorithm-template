// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/

#include <vector>
#include <algorithm>
#include <cstdint>

#ifdef CS203_DSAA_TEST_MACRO
namespace leetcode_740 {
using std::vector;
#endif

class Solution {
public:
    int deleteAndEarn(const vector<int> &nums) {
        vector<int32_t> values(nums);
        std::sort(std::begin(values), std::end(values));
        const auto maxV{values.back()};
        vector<int32_t> arr(maxV + 1, 0);
        vector<int32_t> dp(maxV + 2, 0);
        for (const auto value: values) {
            arr[value]++;
        }
        dp[0] = 0; // 只选前0个肯定只能得到0的点数
        dp[1] = arr[0]; // 只选第一个 只能得到1的点数
        for (int32_t i{2}; i <= maxV + 1; i++) {
            dp[i] = std::max(dp[i - 2] + arr[i - 1] * (i - 1), dp[i - 1]);
            // 因为排了序,所以考虑的时候后面那个根本还没有, 所以不需要考虑
            // 只需要考虑是 要 i-2并且去掉i-1 还是要i-1
        }
        return dp.back();
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
