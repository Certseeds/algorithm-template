// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2023 nanoseeds

*/
#include <string>
#include <array>
#include <cstdint>
#include <cstddef>

#ifdef CS203_DSAA_TEST_MACRO
namespace leetcode_1370 {
using std::string;
#endif

class Solution {
public:
    string sortString(const string &s) {
        constexpr const auto chnum{'Z' - 'A' + 1};
        std::array<int32_t, chnum> count{0,};
        const auto length{s.size()};
        for (const auto ch: s) {
            count[ch - 'a'] += 1;
        }
        string will_return{};
        will_return.reserve(length);
        for (size_t remains{length}; remains > 0;) {
            for (size_t i{0}; i < chnum; ++i) {
                if (count[i] != 0) {
                    will_return.push_back(static_cast<char>(i + 'a'));
                    count[i] -= 1;
                    remains -= 1;
                }
            }
            for (size_t i{0}; i < chnum; ++i) {
                const auto i2 = chnum - 1 - i;
                if (count[i2] != 0) {
                    will_return.push_back(static_cast<char>(i2 + 'a'));
                    count[i2] -= 1;
                    remains -= 1;
                }
            }
        }
        return will_return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
