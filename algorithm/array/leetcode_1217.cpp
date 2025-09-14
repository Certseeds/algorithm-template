// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <algorithm>
#include <limits>
#include <vector>

namespace leetcode_1217 {
using std::vector;
#endif

class Solution {
public:
    int minCostToMoveChips(const vector<int> &position) {
        if (position.empty() || position.size() == 1) {
            return 0;
        }
        int32_t odd{0}, even{0};
        for (const auto num: position) {
            if (num % 2 == 0) {
                odd++;
            } else {
                even++;
            }
        }
        return std::min(even, odd);
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
