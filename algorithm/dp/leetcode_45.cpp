// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds

#ifdef CS203_DSAA_TEST_MACRO
#include <vector>
#include <algorithm>
#include <cstdint>
namespace leetcode_45 {
using std::vector;
using std::max;
using std::min;
#endif

class Solution {
public:
    int32_t jump(const vector<int32_t> &nums) {
        const auto nums_size{nums.size()};
        if (nums_size == 1) {
            return 0;
        }
        int32_t times{0};
        // 每次移动一个"范围"
        // 范围内从左到右依次更新右边界
        // 一旦右边界移动出界,则返回
        for (size_t start{0}, end{1}; end < nums_size; times++) {
            size_t max{end + 1};
            for (size_t begin{start}; begin < end; begin++) {
                max = std::max(max, begin + nums[begin] + 1);
            }
            start = end;
            end = max;
        }
        return times;
    }

    int32_t jump2(const vector<int32_t> &nums) {
        const auto nums_size{nums.size()};
        if (nums_size == 1) {
            return 0;
        }
        vector<int32_t> steps(nums_size, 0x3f3f3f3f);
        steps[0] = 0;
        for (size_t i{0}; i < nums_size; i++) {
            for (int32_t step{1}; step <= nums[i] && (i + step) < nums_size; step++) {
                steps[i + step] = std::min(steps[i + step], steps[i] + 1);
                if (i + step + 1 == nums_size) {
                    return steps.back();
                }
            }
        }
        return steps.back();
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
