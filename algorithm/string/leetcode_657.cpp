// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <string>
#include <cstdint>

#ifdef ALGORITHM_TEST_MACRO
namespace leetcode_657 {
using std::string;
#endif

class Solution {
public:
    bool judgeCircle(const string &moves) {
        int32_t x{0}, y{0};
        for (const auto move : moves) {
            switch (move) {
                case 'L':
                    x++;
                    break;
                case 'R':
                    x--;
                    break;
                case 'U':
                    y++;
                    break;
                case 'D':
                    y--;
                    break;
            }
        }
        return (x == 0 && y == 0);
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
