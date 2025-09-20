// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
#include <string>
#include <array>
#include <algorithm>
#include <limits>

#ifdef CS203_DSAA_TEST_MACRO
namespace leetcode_242 {
using std::string;
using std::array;
#endif

class Solution {
public:
    bool isAnagram(const string &s, const string &t) {
        std::array<size_t, std::numeric_limits<char>::max() + 1> arr{0};
        for (const auto ch: s) { ++arr[ch]; }
        for (const auto ch: t) { --arr[ch]; }
        return std::all_of(arr.cbegin(), arr.cend(), [](const auto ele) { return ele == 0; });
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
