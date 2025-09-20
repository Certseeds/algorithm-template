// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag stack
//@Tag 栈
//@Tag 输入保证合法
#ifdef CS203_DSAA_TEST_MACRO

#include <array>
#include <stack>
#include <limits>
#include <string>
#include <cstdint>
#include <algorithm>

namespace leetcode_1614 {
using std::array;
using std::stack;
using std::string;
#endif

class Solution {
public:
    int maxDepth(const string &s) {
        static const auto arr = [] {
            static auto arr = std::array<uint8_t, std::numeric_limits<uint8_t>::max() + 1>{0};
            arr['('] = '(';
            arr[')'] = '(';
            return arr;
        }();
        stack<uint8_t> sta{};
        int32_t will_return{0}, temp{0};
        for (auto &&ch: s) {
            if (arr[ch] == ch) {
                sta.push(ch);
            } else if (!sta.empty() && arr[ch] == sta.top()) {
                will_return = std::max(will_return, static_cast<int32_t>(sta.size()));
                sta.pop();
            } else {
                will_return = std::max(will_return, static_cast<int32_t>(sta.size()));
            }
            temp++;
        }
        return will_return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
