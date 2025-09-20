// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <string>
#include <array>
#include <limits>

#ifdef ALGORITHM_TEST_MACRO
namespace leetcode_709 {
using std::string;
using std::array;
#endif

class Solution {
public:
    string toLowerCase(string s) {
        for (char &c : s) {
            if (c >= 'A' && c <= 'Z') {
                c = c - 'A' + 'a';
            }
        }
        return s;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
