// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO

#include <vector>
#include <cstdint>

namespace leetcode_941 {
using std::vector;
#endif

class Solution {
public:
    bool validMountainArray(const vector<int32_t> &arr) {
        const auto arr_size{arr.size()};
        if (arr_size < 3) {
            return false;
        } else if (arr_size == 3) {
            return arr[0] < arr[1] && arr[1] > arr[2];
        }
        size_t count{0};
        for (size_t i{1}; i + 1 < arr_size; ++i) {
            if (arr[i - 1] == arr[i] || arr[i] == arr[i + 1]) {
                return false;
            }
            count += (arr[i - 1] < arr[i]) == (arr[i] < arr[i + 1]);
        }
        if (count + 3 == arr_size) {
            return true;
        }
        return false;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
