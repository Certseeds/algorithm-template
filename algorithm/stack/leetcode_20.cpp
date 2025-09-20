// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO

#include <array>
#include <stack>
#include <string>
#include <cstdint>

namespace leetcode_20 {
using std::array;
using std::stack;
using std::string;
#endif

class Solution {
public:
    bool isValid(const string &s) {
        std::stack<uint8_t> stk{{'?'}};
        std::array<uint8_t, 256> umap{};
        umap['('] = ')';
        umap['['] = ']';
        umap['{'] = '}';
        for (const auto i: s) {
            if (umap[stk.top()] == i) {
                stk.pop();
            } else {
                stk.push(i);
            }
        }
        stk.pop();
        return stk.empty();
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
