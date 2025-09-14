// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/

#ifdef CS203_DSAA_TEST_MACRO

#include <cstdint>
#include <vector>

namespace leetcode_605 {
using std::vector;
#endif

class Solution {
public:
    // 虽然是种花问题,但是也可以映射到其他问题上,比如一个很常见的问题......
    bool canPlaceFlowers(const vector<int32_t> &urinal_immutable, int32_t n) {
        vector<int32_t> urinal{urinal_immutable};
        const auto urinal_size{urinal.size()};
        if (n == 0) {
            return true;
        } else if ((urinal_size + 1) / 2 < static_cast<size_t>(n)) {
            return false;
        } else if (urinal_size == 1) {
            return urinal[0] != 1;
        } else if (urinal_size == 2) {
            return urinal[0] != 1 && urinal[1] != 1;
        }
        if (urinal[0] == 0 && urinal[1] == 0) {
            urinal[0] = 1;
            n--;
        }
        if (urinal[urinal_size - 1] == 0 && urinal[urinal_size - 2] == 0) {
            urinal[urinal_size - 1] = 1;
            n--;
        }
        for (size_t i{1}, temp{1}; n > 0; temp = i) {
            for (; i < urinal_size; i++) {
                if (urinal[i - 1] == 0 && urinal[i] == 0 && urinal[i + 1] == 0) {
                    urinal[i] = 1;
                    i += 2;
                    n--;
                    break;
                }
            }
            if (temp == i) {
                return false;
            }
        }
        return true;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
