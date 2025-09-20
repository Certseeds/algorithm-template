// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds

#include <vector>
#include <cstdint>
#include <cstddef>

#ifdef CS203_DSAA_TEST_MACRO
namespace leetcode_1025 {
using std::vector;
#endif

class Solution {
public:
    bool divisorGame(int32_t n) {
        vector<uint8_t> status(n + 3, false);
        status[1] = false;
        status[2] = true;
        for (size_t i{3}; i < n + 3; ++i) {
            for (size_t j{1}; j < i; ++j) {
                if (i % j == 0 && status[i - j] == false) {
                    status[i] = true;
                    break;
                }
            }
        }
        return status[n];
    }

    bool divisorGame2(int32_t n) {
        return !(n & 1);
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
