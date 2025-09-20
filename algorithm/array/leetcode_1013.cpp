// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO

#include <vector>
#include <numeric>
#include <cstdint>

namespace leetcode_1013 {
using std::vector;
#endif

class Solution {
public:
    bool canThreePartsEqualSum(std::vector<int32_t> &arr) {
        const int32_t sums = std::accumulate(arr.begin(), arr.end(), 0);
        if (sums % 3 != 0) {
            return false;
        }
        const int32_t divide = sums / 3;
        for (int32_t x{1}, y = arr.size() - 2, sum_x{arr.front()}, sum_y{arr.back()}; x < y;) {
            if (sum_x != divide) {
                sum_x += arr[x];
                x++;
            }
            if (sum_y != divide) {
                sum_y += arr[y];
                y--;
            }
            if (sum_x == divide && sum_y == divide && x <= y) {
                return true;
            }
        }
        return false;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
