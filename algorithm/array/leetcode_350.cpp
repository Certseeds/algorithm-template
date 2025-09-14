// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <vector>
#include <unordered_map>
#include <algorithm>

namespace leetcode_350 {
using std::vector;
using std::unordered_map;
#endif

class Solution {
public:
    vector<int32_t> intersect(const vector<int32_t> &nums1, const vector<int32_t> &nums2) {
        const auto *nums1Ref = &nums1;
        const auto *nums2Ref = &nums2;
        const auto nums1_size{nums1.size()}, nums2_size{nums2.size()};
        if (nums1_size >= nums2_size) {
            std::swap(nums1Ref, nums2Ref);
        }
        // nums1.size() < nums2.size()
        unordered_map<int, int> umap1;
        for (const auto i: *nums1Ref) {
            umap1[i]++;
        }
        vector<int32_t> will_return;
        will_return.reserve(nums2_size);
        for (const auto i: *nums2Ref) {
            if (umap1[i] > 0) {
                umap1[i]--;
                will_return.push_back(i);
            }
        }
        return will_return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
