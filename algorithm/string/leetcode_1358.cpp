// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#include <string>
#include <cstdint>
#include <cstddef>

#ifdef CS203_DSAA_TEST_MACRO
namespace leetcode_1358 {
using std::string;
#endif

class Solution {
public:
    int32_t numberOfSubstrings(const string &s) {
        int32_t count{0};
        const auto s_size{s.size()};
        for (size_t left{0}, right{0}, a{0}, b{0}, c{0}; right < s_size;) {
            const auto ch1 = s[right];
            if (ch1 == 'a') { a += 1; }
            if (ch1 == 'b') { b += 1; }
            if (ch1 == 'c') { c += 1; }
            right += 1;
            while (a >= 1 && b >= 1 && c >= 1) {
                count += s_size - right + 1;
                const auto ch2 = s[left];
                if (ch2 == 'a') { a -= 1; }
                if (ch2 == 'b') { b -= 1; }
                if (ch2 == 'c') { c -= 1; }
                left += 1;
            }
        }
        return count;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
