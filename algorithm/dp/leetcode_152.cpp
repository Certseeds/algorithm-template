// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO

#include <cstdint>
#include <cstddef>
#include <vector>
#include <algorithm>

namespace leetcode_152 {
using std::vector;
#endif

class Solution {
public:
    int32_t maxProduct(const vector<int32_t> &nums) {
        const auto nums_size{nums.size()};
        if (nums_size == 0) {
            return 0;
        } else if (nums_size == 1) {
            return nums[0];
        }
        vector<int32_t> dpMax(nums_size + 1, 0), dpMin(nums_size + 1, 0);
        dpMax[0] = 0; // 以第0个结尾的一定是0
        dpMin[0] = 0; // 以第0个结尾的一定是0
        dpMax[1] = nums[0]; // 以第一个结尾的一定是nums[0]
        dpMin[1] = nums[0]; // 以第一个结尾的一定是nums[0]
        int32_t maxV{nums[0]};
        for (size_t i{2}; i <= nums_size; i++) {
            if (nums[i - 1] > 0) {
                dpMax[i] = std::max(dpMax[i - 1] * nums[i - 1], nums[i - 1]);
                dpMin[i] = std::min(dpMin[i - 1] * nums[i - 1], nums[i - 1]);
            } else if (nums[i - 1] == 0) {
                dpMax[i] = 0;
                dpMin[i] = 0;
            } else {
                dpMax[i] = std::max(dpMin[i - 1] * nums[i - 1], nums[i - 1]);
                dpMin[i] = std::min(dpMax[i - 1] * nums[i - 1], nums[i - 1]);
                // 这里其实考虑到了对称性, 先确认了dpMax,再确认的dpMin
            }
            maxV = std::max(maxV, dpMax[i]);
        }
        return maxV;
    }

    int32_t maxProduct2(const vector<int32_t> &nums) {
        const auto nums_size{nums.size()};
        if (nums_size == 0) {
            return 0;
        } else if (nums_size == 1) {
            return nums[0];
        }
        int32_t aMax{nums[0]}, bMax, maxV{nums[0]};
        int32_t aMin{nums[0]}, bMin;
        // 滚 动 数 组
        for (size_t i{2}; i <= nums_size; maxV = std::max(maxV, bMax), i++, aMax = bMax, aMin = bMin) {
            if (nums[i - 1] > 0) {
                bMax = std::max(aMax * nums[i - 1], nums[i - 1]);
                bMin = std::min(aMin * nums[i - 1], nums[i - 1]);
            } else if (nums[i - 1] == 0) {
                bMax = 0;
                bMin = 0;
            } else {
                bMax = std::max(aMin * nums[i - 1], nums[i - 1]);
                bMin = std::min(aMax * nums[i - 1], nums[i - 1]);
            }
        }
        return maxV;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
