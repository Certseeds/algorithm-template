// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#include <string>
#include <array>
#include <limits>
#include <cstdint>

#ifdef ALGORITHM_TEST_MACRO
namespace leetcode_383 {
using std::string;
using std::array;
#endif

class Solution {
public:
    bool canConstruct(const string &ransomNote, const string &magazine) {
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        std::array<int64_t, std::numeric_limits<char>::max() + 1> base{0};
        for (const auto ch: magazine) {
            ++base[ch];
        }
        for (const auto ch: ransomNote) {
            --base[ch];
            if (base[ch] < 0) {
                return false;
            }
        }
        return true;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
