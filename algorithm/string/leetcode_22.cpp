// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <vector>
#include <string>
#include <unordered_set>
#include <cstdint>

#ifdef ALGORITHM_TEST_MACRO
namespace leetcode_22 {
using std::vector;
using std::string;
using std::unordered_set;
#endif

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 1) {
            return vector<string>{"()"};
        }
        vector<string> will_return{generateParenthesis(n - 1)};
        unordered_set<string> uset{};
        for (const auto &i: will_return) {
            for (int32_t j{0}; j < n; j++) {
                uset.insert(string(i).insert(j, "()"));
            }
        }
        will_return.clear();
        will_return.reserve(uset.size());
        will_return.insert(will_return.end(), uset.begin(), uset.end());
        return will_return;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
