// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
#include <string>
#include <array>
#include <limits>

#ifdef CS203_DSAA_TEST_MACRO
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

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
