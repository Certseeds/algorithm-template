// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2021-2025 nanoseeds

#ifdef CS203_DSAA_TEST_MACRO
namespace leetcode_1567 {
using std::vector;
#endif

class Solution {
public:
    int32_t getMaxLen(const vector<int32_t> &nums) {
        const auto nums_size{nums.size()};
        if (nums_size == 0) {
            return 0;
        } else if (nums_size == 1) {
            return nums[0] > 0 ? 1 : 0;
        }
        vector<int32_t> dpPos(nums_size + 1, 0), dpNeg(nums_size + 1, 0);
        dpPos[0] = 0, dpNeg[0] = 0;// 以第0个结尾一定是0
        dpPos[1] = nums[0] > 0 ? 1 : 0; // 第一个结尾的话,正则1,否则0
        dpNeg[1] = nums[0] < 0 ? 1 : 0; // 第一个结尾的话,正则1,否则0
        for (size_t i{2}; i <= nums_size; i++) {
            if (nums[i - 1] == 0) {
                dpPos[i] = 0;
                dpNeg[i] = 0;
            } else if (nums[i - 1] > 0) {
                // 这个是正数,则取决于上一个结尾的最大正乘积长度
                dpPos[i] = dpPos[i - 1] + 1;
                // 这种情况下,上一个结尾的最大负乘积长度得先存在才能+1
                if (dpNeg[i - 1] > 0) {
                    dpNeg[i] = dpNeg[i - 1] + 1;
                }
            } else if (nums[i - 1] < 0) {
                if (dpNeg[i - 1] > 0) {
                    dpPos[i] = dpNeg[i - 1] + 1;
                }
                dpNeg[i] = dpPos[i - 1] + 1;
            }
        }
        return *std::max_element(dpPos.cbegin(), dpPos.cend());
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
