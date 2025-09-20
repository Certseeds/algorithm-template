// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <vector>
#include <cstdint>

namespace leetcode_832 {
using std::vector;
#endif

class Solution {
public:
    vector<vector<int32_t>> flipAndInvertImage(vector<vector<int32_t>> &image) {
        const auto m{image.size()};
        if (m == 0) {
            return image;
        }
        const auto n{image.front().size()};
        if (n == 0) {
            return image;
        }
        vector<vector<int32_t>> result(image);
        vector<uint8_t> traverse(n);
        for (size_t i{0}; i < m; ++i) {
            for (size_t left{0}, right{n - 1}; left < right && right < n; ++left, --right) {
                if (image[i][left] == image[i][right]) {
                    result[i][left] = !image[i][left];
                    result[i][right] = !image[i][right];
                }
            }
            if (n % 2 == 1) {
                result[i][n / 2] = !image[i][n / 2];
            }
        }
        return result;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
