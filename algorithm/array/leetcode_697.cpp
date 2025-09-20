// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds

#ifdef CS203_DSAA_TEST_MACRO

#include <cstdint>
#include <vector>

namespace leetcode_697 {
using std::vector;
#endif

class Solution {
public:
    int32_t findShortestSubArray(std::vector<int32_t> &nums) {
        if (nums.empty()) {
            return 0;
        }
        std::unordered_map<int, int> times, begin;
        int32_t max{0}, will_return{0};
        const auto nums_size{static_cast<int>(nums.size())};
        for (int32_t i{0}; i < nums_size; i++) {
            const auto num{nums[i]};
            ++times[num];
            if (times[num] == 1) {
                begin[num] = i;
            } else {
                if (times[num] > max) {
                    max = times[num];
                    will_return = i - begin[num];
                } else if (times[num] == max) {
                    will_return = std::min(will_return, i - begin[num]);
                }
            }
        }
        return will_return + 1;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif