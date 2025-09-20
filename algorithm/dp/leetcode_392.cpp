// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanos

*/

#include <string>

#ifdef CS203_DSAA_TEST_MACRO
namespace leetcode_392 {
using std::string;
#endif

class Solution {
public:
    bool isSubsequence(const string &s, const string &t) {
        const auto tSize{t.size()}, sSize{s.size()};
        if (tSize < sSize) {
            return false;
        }
        size_t sNum{0};
        for (size_t i{0}; i < tSize && sNum != sSize; i++) {
            if (t[i] == s[sNum]) {
                sNum++;
            }
        }
        return sNum == sSize;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
