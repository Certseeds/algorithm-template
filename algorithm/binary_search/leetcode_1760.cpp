// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <cstdlib>
#include <vector>
#include <algorithm>

namespace leetcode_1760 {
#endif

using std::vector;

class Solution {
private:
    //  开销是数组内的最大值,因此要最小化数组的最大值
    //  因此将1作为最小值,数组内最大值作为最大值, 进行二分
    //  每次二分进行一次判别,返回操作次数
    int32_t judgement(const vector<int32_t> &nums, int32_t value) {
        int32_t operations{0};
        for (const auto num: nums) {
            const auto [q, r] = std::div(num, value);
            if (r != 0) { //剩下就得多分割一次
                operations++;
            }
            operations += (q - 1); // 本来自己是有的,需要划去
        }
        return operations;
    }

public:
    int32_t minimumSize(const vector<int32_t> &nums, int32_t maxOperations) {
        int32_t minValue{1};
        for (int32_t maxValue{*std::max_element(nums.cbegin(), nums.cend())}; minValue < maxValue;) {
            const auto mid = (maxValue - minValue) / 2 + minValue;
            const auto result = judgement(nums, mid);
            if (result > maxOperations) {
                minValue = mid + 1;
            } else if (result <= maxOperations) {
                maxValue = mid;
            }
        }
        return minValue; // should not reach
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
