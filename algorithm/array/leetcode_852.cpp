// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO

#include <vector>
#include <cstdint>

namespace leetcode_852 {
using std::vector;
#endif

class Solution {
public:
    int32_t peakIndexInMountainArray(const vector<int32_t> &A) {
        int x1{0}, x4 = static_cast<int32_t>(A.size() - 1);
        for (int x2{x1 + (x4 - x1) / 3}, x3{x1 + (x4 - x1) * 2 / 3}; x1 < x4;) {
            int temp1 = A[x2], temp2 = A[x3];
            if (temp1 > temp2) {
                x4 = x3;
            } else {
                x1 = x2 + 1;
            }
            x2 = x1 + (x4 - x1) / 3;
            x3 = x1 + (x4 - x1) * 2 / 3;
        }
        return x1 - 1;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
