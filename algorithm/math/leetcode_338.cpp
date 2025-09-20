// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO

#include <cstdint>
#include <vector>

namespace leetcode_338 {
using std::vector;
#endif

class Solution {
public:
    vector<int32_t> countBits(int32_t num) {
        if (num == 0) {
            return {0};
        }
        vector<int32_t> will_return(num + 1, 0);
        will_return[0] = 0;
        will_return[1] = 1;
        for (int32_t i{2}; i < num + 1; ++i) {
            will_return[i] = will_return[i / 2] + i % 2;
        }
        return will_return;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
