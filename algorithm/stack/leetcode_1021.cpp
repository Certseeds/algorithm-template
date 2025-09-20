// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag stack
//@Tag 栈
//@Tag 输入保证合法
#ifdef ALGORITHM_TEST_MACRO

#include <string>
#include <cstddef>

namespace leetcode_1021 {
using std::string;
#endif

class Solution {
public:
    string removeOuterParentheses(const string &str) {
        std::string will_return{};
        const auto str_size{str.size()};
        for (size_t i{0}; i < str_size; ++i) {
            for (size_t depth{1}; depth != 0;) {
                ++i;
                if (str[i] == '(') {
                    ++depth;
                } else {
                    --depth;
                }
                if (depth != 0) [[likely]] {
                    will_return += str[i];
                }
            }
        }
        return will_return;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
