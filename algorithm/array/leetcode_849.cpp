// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO

#include <vector>
#include <cstdint>
#include <limits>
#include <algorithm>

namespace leetcode_849 {
using std::vector;
#endif

class Solution {
public:
    int32_t maxDistToClosest(const vector<int32_t> &seats) {
        vector<int> left(seats), right(seats);
        const auto size{seats.size()};
        left[0] = (seats[0] == 1) ? 0 : std::numeric_limits<int32_t>::max();
        right[size - 1] = (seats[size - 1] == 1) ? 0 : std::numeric_limits<int32_t>::max();
        for (size_t i{1}; i < size; ++i) {
            left[i] = (seats[i] == 1) ? 0 : left[i - 1] + 1;
        }
        for (size_t i = size; i >= 2; --i) {
            right[i - 2] = (seats[i - 2] == 1) ? 0 : right[i - 1] + 1;
        }
        int will_return{std::numeric_limits<int32_t>::min()};
        for (size_t i{0}; i < size; ++i) {
            will_return = std::max(will_return, std::min(left[i], right[i]));
        }
        return will_return;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
