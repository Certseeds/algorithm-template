// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag stack
//@Tag 栈
//@Tag 贪心
#ifdef CS203_DSAA_TEST_MACRO

#include <stack>
#include <string>
#include <cstdint>
#include <algorithm>

namespace leetcode_678 {
using std::stack;
using std::string;
#endif

class Solution {
public:
    bool checkValidString(const string &s) {
        int32_t order{0};
        stack<int32_t> s1{}, s2{};
        for (auto &&ch: s) {
            if (ch == '(') {
                s1.push(order);
            } else if (ch == '*') {
                s2.push(order);
            } else {
                if (!s1.empty()) {
                    s1.pop();
                } else if (!s2.empty()) {
                    s2.pop();
                } else {
                    return false;
                }
            }
            order++;
        }
        if (s1.size() > s2.size()) {
            return false;
        }
        while (!s1.empty() && !s2.empty()) {
            if (s1.top() > s2.top()) {
                return false;
            }
            s1.pop();
            s2.pop();
        }
        return true;
    }

    bool checkValidString2(const string &s) {
        int32_t low{0}, high{0};
        for (auto &&ch: s) {
            if (ch == '(') {
                low++;
                high++;
            } else if (ch == '*') {
                low = std::max(0, low - 1); // mayBe match a )
                high++;
            } else {
                high--;
                low = std::max(0, low - 1);
                if (high < 0) {
                    return false;
                }
            }
        }
        if (low == 0) {
            return true;
        }
        return false;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
