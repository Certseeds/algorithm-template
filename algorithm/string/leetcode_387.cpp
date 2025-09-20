// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
#include <string>
#include <array>
#include <algorithm>
#include <cstdint>
#include <cstddef>

#ifdef CS203_DSAA_TEST_MACRO
namespace leetcode_387 {
using std::string;
using std::array;
#endif

class Solution {
public:
    int32_t firstUniqChar(const string &s) {
        std::array<int32_t, 128> chars{0};
        for (const auto ch: s) {
            chars[ch]++;
        }
        for (size_t i{0}, size{s.size()}; i < size; ++i) {
            if (chars[s[i]] == 1) {
                return static_cast<int32_t>(i);
            }
        }
        return -1;
    }

    int32_t firstUniqChar2(const string &s) {
        std::array<std::pair<int32_t, size_t>, 128> chars{};
        for (auto iter = s.crbegin(); iter != s.crend(); ++iter) {
            const auto ch = *iter;
            ++chars[ch].first;
            chars[ch].second = s.crend() - iter;
        }
        int32_t will_return{0x3f3f3f3f};
        for (const auto&[k, v]: chars) {
            if (k == 1) {
                will_return = std::min(will_return, static_cast<int32_t>(v - 1));
            }
        }
        return will_return == 0x3f3f3f3f ? -1 : will_return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
