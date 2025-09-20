// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <string>
#include <vector>
#include <cctype>

#ifdef CS203_DSAA_TEST_MACRO
namespace leetcode_784 {
using std::string;
using std::vector;
#endif

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> result;
        dfs(S, 0, result);
        return result;
    }

private:
    void dfs(string &s, int index, vector<string> &result) {
        if (index == s.length()) {
            result.push_back(s);
            return;
        }
        dfs(s, index + 1, result);
        if (isalpha(s[index])) {
            s[index] ^= 32;
            dfs(s, index + 1, result);
        }
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
