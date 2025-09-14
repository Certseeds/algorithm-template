// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <vector>
#include <string>

namespace leetcode_944 {
using std::vector;
using std::string;
#endif

class Solution {
public:
    int32_t minDeletionSize(const vector<string> &strs) {
        int count{0};
        const auto lines{strs.size()};
        const auto str_size{strs[0].size()};
        for (size_t i{0}, notdeletex{true}; i < str_size; ++i, notdeletex = true) {
            for (size_t j{1}; j < lines; ++j) {
                notdeletex = notdeletex & (strs[j][i] >= strs[j - 1][i]);
            }
            count += !notdeletex;
        }
        return count;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
