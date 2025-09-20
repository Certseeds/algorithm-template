// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <cstdint>
#include <cstddef>
#include <vector>
#include <array>

namespace leetcode_75 {
using std::vector;
#endif

class Solution {
public:
    void sortColors(vector<int32_t> &nums) {
        std::array<int32_t, 3> counts{0, 0, 0};
        for (const auto num: nums) {
            counts[num]++;
        }
        for (int32_t i{0}, count{0}; i < 3; ++i) {
            for (int32_t j{0}; j < counts[i]; ++j, ++count) {
                nums[count] = i;
            }
        }
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
