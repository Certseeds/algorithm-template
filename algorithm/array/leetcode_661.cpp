// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds

#ifdef CS203_DSAA_TEST_MACRO

#include <cstdint>
#include <vector>

namespace leetcode_661 {
using std::vector;
#endif

class Solution {
public:
    vector<vector<int32_t>> imageSmoother(const vector<vector<int32_t>> &M) {
        const auto sizes{M.size()}, sizes_in{M[0].size()};
        vector<vector<int32_t>> willreturn(sizes, vector<int32_t>(sizes_in, 0));
        if (sizes == 1) {
            if (sizes_in == 1) {
                return M;
            } else if (sizes_in == 2) {
                return {{(M[0][0] + M[0][1]) / 2, (M[0][0] + M[0][1]) / 2}};
            } else {
                willreturn[0][0] = (M[0][0] + M[0][1]) / 2;
                willreturn[0][sizes_in - 1] = (M[0][sizes_in - 2] + M[0][sizes_in - 1]) / 2;
                for (size_t i{1}; i < sizes_in - 1; i++) {
                    willreturn[0][i] = (M[0][i - 1] + M[0][i] + M[0][i + 1]) / 3;
                }
                return willreturn;
            }
        } else if (sizes_in == 1) {
            if (sizes == 2) {
                return {{(M[0][0] + M[1][0]) / 2},
                        {(M[0][0] + M[1][0]) / 2}};
            } else {
                willreturn[0][0] = (M[0][0] + M[1][0]) / 2;
                willreturn[sizes - 1][0] = (M[sizes - 1][0] + M[sizes - 2][0]) / 2;
                for (size_t i{1}; i < sizes - 1; i++) {
                    willreturn[i][0] = (M[i - 1][0] + M[i][0] + M[i + 1][0]) / 3;
                }
                return willreturn;
            }
        }
        willreturn[0][0] =
                (M[0][0] + M[0][1] +
                 M[1][0] + M[1][1]) /
                4;
        willreturn[sizes - 1][0] =
                (M[sizes - 1][0] + M[sizes - 2][0] +
                 M[sizes - 2][1] + M[sizes - 1][1]) /
                4;
        willreturn[0][sizes_in - 1] = (M[0][sizes_in - 1] + M[1][sizes_in - 1] +
                                       M[1][sizes_in - 2] + M[0][sizes_in - 2]) /
                                      4;
        willreturn[sizes - 1][sizes_in - 1] = (M[sizes - 1][sizes_in - 1] + M[sizes - 1][sizes_in - 2] +
                                               M[sizes - 2][sizes_in - 1] + M[sizes - 2][sizes_in - 2]) /
                                              4;
        for (size_t i{1}; i < sizes_in - 1; i++) {
            willreturn[0][i] = (M[0][i - 1] + M[0][i] + M[0][i + 1] +
                                M[1][i - 1] + M[1][i] + M[1][i + 1]) /
                               6;
            willreturn[sizes - 1][i] = (M[sizes - 2][i - 1] + M[sizes - 2][i] + M[sizes - 2][i + 1] +
                                        M[sizes - 1][i - 1] + M[sizes - 1][i] + M[sizes - 1][i + 1]) /
                                       6;
        }
        for (size_t i{1}; i < sizes - 1; i++) {
            willreturn[i][0] = (M[i - 1][0] + M[i][0] + M[i + 1][0] +
                                M[i - 1][1] + M[i][1] + M[i + 1][1]) /
                               6;
            willreturn[i][sizes_in - 1] = (M[i - 1][sizes_in - 1] + M[i][sizes_in - 1] + M[i + 1][sizes_in - 1] +
                                           M[i - 1][sizes_in - 2] + M[i][sizes_in - 2] + M[i + 1][sizes_in - 2]) /
                                          6;
            for (size_t j{1}; j < sizes_in - 1; j++) {
                willreturn[i][j] = (M[i - 1][j - 1] + M[i][j - 1] + M[i + 1][j - 1] +
                                    M[i - 1][j] + M[i][j] + M[i + 1][j] +
                                    M[i - 1][j + 1] + M[i][j + 1] + M[i + 1][j + 1]) /
                                   9;
            }
        }
        return willreturn;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
