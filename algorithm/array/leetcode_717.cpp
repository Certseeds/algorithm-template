// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds

#ifdef CS203_DSAA_TEST_MACRO

#include <cstdint>
#include <vector>

namespace leetcode_717 {
using std::vector;
#endif

class Solution {
public:
    bool isOneBitCharacter(vector<int32_t> &bits) {
        const size_t size{bits.size()};
        if (size < 2 || bits[size - 2] == 0) {
            return true;
        }
        // sizes == 2 is the same with sizes >2
        // it means, test the string before the last one is over or not
        size_t i{0};
        for (; i + 1 < size; ++i) {
            i += bits[i];
        }
        return i + 1 == size;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
