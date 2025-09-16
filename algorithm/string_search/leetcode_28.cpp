// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#include <string>
#include <cstdint>

#ifdef CS203_DSAA_TEST_MACRO

#include "kmp.hpp"

namespace leetcode_28 {
using std::string;
#endif

class Solution {
public:
    int32_t strStr(const string &haystack, const string &needle) {
        return string_search::strStr(haystack, needle);
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
