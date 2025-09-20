// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO

#include <vector>
#include <unordered_map>

namespace leetcode_560 {
using std::vector;
using std::unordered_map;
#endif

class Solution {
public:
    int32_t subarraySum(const vector<int32_t> &nums, int32_t k) {
        const auto nums_size{nums.size()};
        int32_t will_return{0};
        if (nums_size == 0) {
            return will_return;
        }
        // map里存的不是[x,y]的值,而是前缀和的值
        unordered_map<int, int> umap{};
        int32_t pre{0};
        for (const auto num: nums) {
            pre = pre + num;
            will_return += umap[pre - k]; // [0,i] - k == [0,?]
            will_return += (pre == k); // 不需要计算前缀和,自身就是
            umap[pre] += 1;
        }
        return will_return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
