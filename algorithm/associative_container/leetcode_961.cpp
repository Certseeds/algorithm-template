// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO

#include <cstdint>
#include <cstddef>
#include <vector>
#include <unordered_set>

namespace leetcode_961 {
using std::unordered_set;
using std::vector;
#endif

class Solution {
public:
    int repeatedNTimes(const vector<int32_t> &nums) {
        unordered_set<int32_t> uset{};
        for (const auto num: nums) {
            if (uset.count(num) != 0) {
                return num;
            } else {
                uset.insert(num);
            }
        }
        return -1;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
