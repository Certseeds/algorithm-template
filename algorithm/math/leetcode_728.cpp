// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <cstdint>
#include <vector>

namespace leetcode_728 {
using std::vector;
#endif

class Solution {
public:
    vector<int32_t> selfDividingNumbers(int32_t left, int32_t right) {
        vector<int32_t> will_return{};
        for (; left <= right; ++left) {
            int32_t now{left};
            while (now > 0) {
                const auto ten = now % 10;
                now /= 10;
                if (ten == 0 || left % ten != 0) {
                    now = -1;
                    break;
                }
            }
            if (now == 0) {
                will_return.push_back(left);
            }
        }
        return will_return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
