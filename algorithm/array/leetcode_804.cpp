// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds

#ifdef ALGORITHM_TEST_MACRO

#include <vector>
#include <string>
#include <array>
#include <unordered_set>

namespace leetcode_804 {
using std::vector;
using std::string;
using std::array;
using std::unordered_set;
#endif

class Solution {
public:
    int32_t uniqueMorseRepresentations(vector<string> &words) {
        static constexpr const array<const char *const, 26> asks = {".-", "-...", "-.-.", "-..",
                                                                    ".", "..-.", "--.", "....",
                                                                    "..", ".---", "-.-",
                                                                    ".-..", "--", "-.", "---",
                                                                    ".--.", "--.-", ".-.", "...",
                                                                    "-", "..-", "...-", ".--",
                                                                    "-..-", "-.--", "--.."};
        unordered_set<string> uset;
        for (const auto &word: words) {
            string temp;
            temp.reserve(4 * word.size());
            for (const auto wchar: word) {
                temp += asks[wchar - 97];
            }
            if (uset.count(temp) == 0) {
                uset.insert(temp);
            }
        }
        return uset.size();
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
