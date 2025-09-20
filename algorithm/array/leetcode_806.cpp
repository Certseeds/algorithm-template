// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanoseeds

*/

#ifdef CS203_DSAA_TEST_MACRO

#include <vector>
#include <string>

namespace leetcode_806 {
using std::vector;
using std::string;
#endif

class Solution {
public:
    vector<int32_t> numberOfLines(const vector<int32_t> &widths, const string &S) {
        const auto number_of_a{97};
        int32_t line{1}, number{0};
        for (const auto ch: S) {
            if (number + widths[ch - number_of_a] <= 100) {
                number += widths[ch - number_of_a];
            } else {
                number = widths[ch - number_of_a];
                line += 1;
            }
        }
        return {line, number};
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
