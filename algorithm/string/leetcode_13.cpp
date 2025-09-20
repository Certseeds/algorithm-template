// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO
#include <string>
#include <array>
#include <cstring>
#include <iterator>
#include <vector>
#include <cstdint>
#include <cstddef>
namespace leetcode_13 {
using std::string;
using std::array;
using std::vector;
#endif

class Solution {
public:
    int32_t romanToInt(const string &s) {
        constexpr const static array<array<const char *const, 9>, 3> vas{
                {{"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                 {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                 {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}}
        };
        int32_t will_return{0};
        size_t begin{0};
        int32_t added{1000};
        while (s[begin] == 'M') {
            will_return += added;
            begin++;
        }
        for (const auto &i: vas) {
            added /= 10;
            for (auto j{i.crbegin()}; j != i.crend(); j++) {
                const auto jsize{strlen(*j)};
                if (!s.compare(begin, jsize, *j, 0, jsize)) {
                    will_return += std::distance(j, i.crend() - 1 + 1) * added;
                    begin += jsize;
                    break;
                }
            }
        }
        return will_return;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
