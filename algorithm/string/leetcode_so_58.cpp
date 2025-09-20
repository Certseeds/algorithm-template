// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#include <string>
#include <vector>
#include <algorithm>

#ifdef CS203_DSAA_TEST_MACRO
namespace leetcode_so_58 {
using std::string;
using std::vector;
#endif

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        std::reverse(s.begin(), s.begin() + n);
        std::reverse(s.begin() + n, s.end());
        std::reverse(s.begin(), s.end());
        return s;
    }

    string reverseWords(string s) {
        std::reverse(s.begin(), s.end());
        int n = s.length();
        int idx = 0;
        for (int start = 0; start < n; ++start) {
            if (s[start] != ' ') {
                if (idx != 0) s[idx++] = ' ';
                int end = start;
                while (end < n && s[end] != ' ') s[idx++] = s[end++];
                std::reverse(s.begin() + idx - (end - start), s.begin() + idx);
                start = end;
            }
        }
        s.erase(s.begin() + idx, s.end());
        return s;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
