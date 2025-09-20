// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag stack
//@Tag 栈
//@Tag 单调栈

#ifdef CS203_DSAA_TEST_MACRO

#include <stack>
#include <string>
#include <string_view>
#include <vector>
#include <array>
#include <cstdint>
#include <cstddef>

namespace leetcode_316 {
using std::stack;
using std::string;
using std::string_view;
using std::vector;
#endif

class Solution {
public:
    string removeDuplicateLetters(string_view str) {
        if (str.size() <= 1) {
            return string{str};
        }
        // 这个最重要的一点在于从"找到"
        // -> 每次删除一个char,删掉哪一个可以得到阶段性最小值?
        // 删掉从左向右数,第一个大于右边char的char
        // 再基于此得到一次性单调栈模型, 最后产出多次单调栈模型
        std::array<int32_t, (1 << 8)> uset{0}, stackSize{0};
        for (const auto ch: str) {
            uset[ch]++;
        }
        stack<size_t> sta;
        for (size_t i{0}; i < str.size(); i++) {
            const auto ch = str[i];
            if (stackSize[ch] == 0) {
                while (!sta.empty() && ch < str[sta.top()]) {
                    const auto topCH{str[sta.top()]};
                    if (uset[topCH] > 0) {
                        stackSize[topCH] = 0;
                        sta.pop();
                    } else {
                        break;
                    }
                }
                stackSize[ch] = 1;
                sta.push(i);
            }
            uset[ch]--;
        }
        vector<char> will_return{};
        while (!sta.empty()) {
            will_return.push_back(str[sta.top()]);
            sta.pop();
        }
        return {will_return.crbegin(), will_return.crend()};
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
