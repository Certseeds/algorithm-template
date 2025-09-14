// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_48 {
using std::vector;
#endif

class Solution {
public:
    void rotate(vector<vector<int32_t>> &matrix) {
        const auto lines = matrix.size();
        const size_t actions = lines / 2;
        for (size_t i{0}; i < actions; ++i) {
            const auto right_end{lines - 1 - i};
            for (size_t j{i}; j < right_end; ++j) {
                const auto fst = matrix[i][j]; // 观察法罢了
                const auto snd = matrix[lines - j - 1][i];
                const auto trd = matrix[lines - 1 - i][lines - 1 - j];
                const auto fth = matrix[j][lines - i - 1];
                matrix[i][j] = snd;
                matrix[lines - j - 1][i] = trd;
                matrix[lines - 1 - i][lines - 1 - j] = fth;
                matrix[j][lines - i - 1] = fst;
            }
        }
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
