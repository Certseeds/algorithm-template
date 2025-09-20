// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#include <string>
#include <vector>
#include <cstdint>

#ifdef CS203_DSAA_TEST_MACRO
namespace leetcode_6 {
using std::string;
using std::vector;
#endif

class Solution {
public:
    string convert(const string &s, int numRows) {
        const auto s_size{s.size()}, numRows_size{static_cast<size_t>(numRows)};
        if (s_size <= numRows_size || numRows_size == 1) {
            return s;
        }
        string will_return;
        will_return.reserve(s_size);
        const size_t batch{numRows_size * 2 - 2};
        for (size_t i = 0; i < numRows_size; ++i) {
            for (size_t j = 0; j + i < s_size; j += batch) {
                will_return += s[j + i];
                if (i > 0 && i < numRows_size - 1 && j + batch - i < s_size) {
                    will_return += s[j + batch - i];
                }
            }
        }
        return will_return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
