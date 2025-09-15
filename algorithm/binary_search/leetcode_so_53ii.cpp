// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO
#include <vector>
#include <cstdint>

namespace leetcode_so_53ii {
#endif

using std::vector;

class Solution {
public:
    int32_t missingNumber(const vector<int32_t> &nums) {
        if (nums.empty()) {
            return 0;
        }
        const int32_t size{static_cast<int32_t>(nums.size())};
        if (nums.back() + 1 == size) {
            return size;
        }
        for (int32_t fst{0}, last{size - 1}; fst < last;) {
            if (const int32_t mid{fst + (last - fst) / 2}; nums[mid] == mid) {
                fst = mid + 1;
                if (nums[mid + 1] - nums[mid] == 2) {
                    return mid + 1;
                }
            } else {
                last = mid;
            }
        }
        return 0;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
