// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <algorithm>
#include <vector>
#include <cstdint>

namespace leetcode_15 {
using std::vector;
#endif

class Solution {
public:
    vector<vector<int32_t>> threeSum(vector<int32_t> &nums) {
        vector<vector<int32_t>> will_return{};
        std::sort(std::begin(nums), std::end(nums));
        const auto nums_size = nums.size();
        if (nums_size < 3) {
            return will_return;
        }
        const auto fst_right_range = nums_size - 2;
        // 优化: next数组,提前计算好从左到右,右到左的跳跃步骤
        // 至少外层循坏可以节约时间
        for (size_t i{0}; i < fst_right_range;) {
            const auto base = nums[i];
            // snd,一串序列的最左侧
            // trd,一串序列的最右侧
            for (auto snd = i + 1, trd = nums_size - 1; snd < trd;) {
                const auto sums = base + nums[snd] + nums[trd];
                if (sums < 0) {
                    // 这样的话, snd<trd时可以保证, 如果有复数个数字则可以重复, 没有则不能
                    for (++snd; snd < trd && nums[snd] == nums[snd - 1]; ++snd) {}
                } else if (sums > 0) {
                    for (--trd; trd > snd && nums[trd] == nums[trd + 1]; --trd) {}
                } else {
                    will_return.push_back(vector<int32_t>{base, nums[snd], nums[trd]});
                    for (++snd; snd < trd && nums[snd] == nums[snd - 1]; ++snd) {}
                    for (--trd; trd > snd && nums[trd] == nums[trd + 1]; --trd) {}
                }
            }
            for (++i; i < fst_right_range && nums[i] == nums[i - 1]; ++i) {}
        }
        return will_return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
