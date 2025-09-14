// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <vector>
#include <algorithm>
#include <cstdint>

namespace leetcode_485 {
using std::vector;
#endif

class Solution {
public:
    int32_t findMaxConsecutiveOnes(const vector<int32_t> &nums) {
        int32_t val{0}, willreturn{-1};
        for (const auto i: nums) {
            if (i != 0) {
                val++;
            } else {
                willreturn = std::max(val, willreturn);
                val = 0;
            }
        }
        return std::max(val, willreturn);;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
