// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO

#include <vector>
#include <cstdint>

namespace leetcode_867 {
using std::vector;
#endif

class Solution {
public:
    vector<vector<int32_t>> transpose(const vector<vector<int32_t>> &A) {
        const auto m{A.size()};
        if (m == 0) {
            return {};
        }
        const auto n{A[0].size()};
        vector<vector<int32_t>> will_return(n, vector<int32_t>(m));
        for (size_t i{0}; i < n; ++i) {
            for (size_t j{0}; j < m; ++j) {
                will_return[i][j] = A[j][i];
            }
        }
        return will_return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
