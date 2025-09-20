// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <cstdint>
#include <vector>
#include <algorithm>

namespace leetcode_343 {
using std::vector;
#endif

class Solution {
public:
    template<typename T>
    T integerBreak(T n) {
        if (n <= 3) {
            return n - 1;
        }
        vector<T> dp{0, 1, 2, 3};
        dp.resize(n + 4);
        for (T i{4}; i <= n; i++) {
            dp[i] = std::max(2 * dp[i - 2], 3 * dp[i - 3]);
            // 根源在于要用接近e(2.71828)的那一个
            // 理论上拆分成e的和之后乘积最大化
        }
        return dp[n];
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
