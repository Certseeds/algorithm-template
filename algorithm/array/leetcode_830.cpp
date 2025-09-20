
// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO

#include <vector>
#include <string>
#include <cstdint>

namespace leetcode_830 {
using std::vector;
using std::string;
#endif

class Solution {
public:
    vector<vector<int32_t>> largeGroupPositions(const string &S) {
        int32_t end{1}, length{1};
        vector<vector<int32_t>> willreturn{};
        const auto s_size{static_cast<int32_t>(S.size())};
        for (int32_t i{1}; i < s_size; ++i) {
            end = i;
            if (S[i] == S[i - 1]) {
                length++;
            } else {
                if (length >= 3) {
                    willreturn.push_back({end - length, end - 1});
                }
                length = 1;
            }
        }
        if (length >= 3) {
            willreturn.push_back({end - length + 1, end});
        }
        return willreturn;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
