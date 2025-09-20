// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
#include <vector>
#include <algorithm>
#include <cstddef>

#ifdef CS203_DSAA_TEST_MACRO
namespace leetcode_344 {
using std::vector;
#endif

class Solution {
public:
    void reverseString(vector<char> &s) {
        for (size_t left{0}, right{s.size() - 1}; left < right; left++, right--) {
            std::swap(s[left], s[right]);
        }
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
