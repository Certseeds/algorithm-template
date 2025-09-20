// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <vector>
#include <string>

namespace leetcode_942 {
using std::vector;
using std::string;
#endif

class Solution {
public:
    vector<int32_t> diStringMatch(const string &str) {
        const auto str_size{str.size()};
        int32_t min{0}, max{static_cast<int>(str_size)};
        vector<int32_t> willreturn(max + 1);
        for (size_t i{0}; i < str_size; i++) {
            if (str[i] == 'I') {
                willreturn[i] = min;
                min++;
            } else {
                willreturn[i] = max;
                max--;
            }
        }
        willreturn.back() = min;
        return willreturn;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
