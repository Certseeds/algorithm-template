// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <vector>

namespace leetcode_88 {
using std::vector;
#endif

class Solution {
public:
    void merge(vector<int32_t> &nums1, int32_t m, const vector<int32_t> &nums2, int32_t n) {
        for (int32_t begin_x{m - 1}, begin_y{n - 1}, count{m + n - 1}; count >= 0; count--) {
            if (begin_x < 0) {
                // repeat with meaning
                nums1[count] = nums2[begin_y];
                begin_y--;
            } else if (begin_y < 0 || nums1[begin_x] > nums2[begin_y]) {
                nums1[count] = nums1[begin_x];
                begin_x--;
            } else {
                nums1[count] = nums2[begin_y];
                begin_y--;
            }
        }
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
