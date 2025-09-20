// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <cstdint>
#include <cstddef>
#include <vector>
#include <cassert>

namespace leetcode_1252 {
using std::vector;
#endif

class Solution {
public:
    int oddCells(int32_t m, int32_t n, const vector<vector<int32_t>> &indices) {
        vector<int8_t> ms(m, 0), ns(n, 0);
        int32_t mOnes{0}, nOnes{0};
        for (const auto &indice: indices) {
            assert(indice.size() == 2);
            const auto mElement = indice[0];
            const auto nElement = indice[1];
            ms[mElement] = static_cast<int8_t>((ms[mElement] + 1) & 1);
            ns[nElement] = static_cast<int8_t>((ns[nElement] + 1) & 1);
            if (ms[mElement]) {
                ++mOnes;
            } else {
                --mOnes;
            }
            if (ns[nElement]) {
                ++nOnes;
            } else {
                --nOnes;
            }
        }
        // 在matrix中, row exchange or column exchange do not effect the 0,1 ,
        // so, we can move them to the same side:
        // move the 0 (ms and ns) element to the leftest and uppest corner
        // that will make left-upper and right-down corner is both 0 (one from 0+0,another from (1+1)%2 == 0)
        // finally, the odds is the left-down and right-upper corner
        // the row-one-element-size * column-zero-element-size + row-zero-element-size * column-one-element-size
        return mOnes * (n - nOnes) + nOnes * (m - mOnes);
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
