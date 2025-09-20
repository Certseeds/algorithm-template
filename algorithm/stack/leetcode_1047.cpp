// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag stack
//@Tag 栈
//@Tag 输入保证合法
#ifdef ALGORITHM_TEST_MACRO

#include <stack>
#include <string>
#include <vector>

namespace leetcode_1047 {
using std::stack;
using std::string;
#endif

class Solution {
public:
    string removeDuplicates(const string &s) {
        stack<char> sta;
        for (const auto ch: s) {
            if (sta.empty()) {
                sta.push(ch);
            } else {
                const auto top{sta.top()};
                if (top == ch) {
                    sta.pop();
                } else {
                    sta.push(ch);
                }
            }
        }
        std::vector<char> cache(sta.size());
        for (auto iter = cache.begin(); iter != cache.end(); ++iter, sta.pop()) {
            (*iter) = sta.top();
        }
        return {cache.crbegin(), cache.crend()};
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
