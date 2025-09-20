// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <vector>
#include <string>

namespace leetcode_17 {
using std::vector;
using std::string;
#endif

class Solution {
public:
    vector<string> letterCombinations(const string &digits) {
        if (digits.empty()) {
            return {};
        }
        const vector<vector<char>> chars{
                {},
                {'a', 'b', 'c'},
                {'d', 'e', 'f'},
                {'g', 'h', 'i'},
                {'j', 'k', 'l'},
                {'m', 'n', 'o'},
                {'p', 'q', 'r', 's'},
                {'t', 'u', 'v'},
                {'w', 'x', 'y', 'z'}
        };
        vector<string> will_return = {""};
        for (const char &digit: digits) {
            vector<string> temp;
            for (const string &temp_str: will_return) {
                for (const char &k: chars[digit - '1']) {
                    temp.emplace_back(temp_str + k);
                }
            }
            will_return = temp;
        }
        return will_return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
