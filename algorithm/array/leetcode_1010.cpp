// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <vector>
#include <array>
#include <cstdint>

namespace leetcode_1010 {
using std::vector;
using std::array;
#endif

class Solution {
public:
    int32_t numPairsDivisibleBy60(const vector<int32_t> &time) {
        array<int32_t, 60> uses{0};
        int32_t willreturn{0};
        for (const int32_t i: time) {
            uses[i % 60]++;
            willreturn += uses[(60 - i % 60) % 60];
        }
        return willreturn - uses[30] - uses[0];
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
