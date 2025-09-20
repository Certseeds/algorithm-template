// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanos

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <vector>
#include <cstdint>
#include <cstddef>
#include <functional>

namespace leetcode_4 {
using std::vector;

#endif


class Solution {
public:
    double findMedianSortedArraysOn(const vector<int32_t> &nums1, const vector<int32_t> &nums2) {
        vector<int32_t> merged{};
        merged.reserve(nums1.size() + nums2.size());
        const size_t nums1_size{nums1.size()}, nums2_size{nums2.size()};
        size_t nums1_order{0}, nums2_order{0};
        while (nums1_order < nums1_size && nums2_order < nums2_size) {
            if (nums1[nums1_order] < nums2[nums2_order]) {
                merged.push_back(nums1[nums1_order]);
                nums1_order++;
            } else {
                merged.push_back(nums2[nums2_order]);
                nums2_order++;
            }
        }
        while (nums1_order < nums1_size) {
            merged.push_back(nums1[nums1_order]);
            nums1_order++;
        }
        while (nums2_order < nums2_size) {
            merged.push_back(nums2[nums2_order]);
            nums2_order++;
        }
        if (merged.size() % 2 == 0) {
            return static_cast<double>((merged[merged.size() / 2 - 1] + merged[merged.size() / 2])) / 2.0f;
        }
        const auto mid = merged.size() / 2;
        return static_cast<double>(merged[mid]);
    }

    double findMedianSortedArraysOlogN(const vector<int32_t> &nums1, const vector<int32_t> &nums2) {
        const std::function<int32_t(size_t, size_t, int)>
                get_nums = [&get_nums, &nums1, &nums2](size_t begin1, size_t begin2, int k) {
            if (begin1 >= nums1.size()) {
                return nums2[begin2 + k - 1];
            } else if (begin2 >= nums2.size()) {
                return nums1[begin1 + k - 1];
            } else if (k == 1) {
                return std::min(nums1[begin1], nums2[begin2]);
            }
            int half = k / 2;
            int newIndex1 = std::min(begin1 + half, nums1.size()) - 1;
            int newIndex2 = std::min(begin2 + half, nums2.size()) - 1;
            if (nums1[newIndex1] <= nums2[newIndex2]) {
                k -= (newIndex1 - begin1 + 1);
                begin1 = newIndex1 + 1;
            } else {
                k -= (newIndex2 - begin2 + 1);
                begin2 = newIndex2 + 1;
            }
            return get_nums(begin1, begin2, k);
        };
        auto left = (nums1.size() + nums2.size() + 1) / 2;
        auto right = (nums1.size() + nums2.size() + 2) / 2;
        return (get_nums(0, 0, left) * 1.0f +
                get_nums(0, 0, right) * 1.0f) / 2;
    }

    double findMedianSortedArraysOlogN2(const vector<int32_t> &nums1, const vector<int32_t> &nums2) {
        const size_t nums1_size{nums1.size()}, nums2_size{nums2.size()};
        const auto getKthElement = [nums1_size, nums2_size, & nums1, & nums2](size_t k) {
            k += 1;
            size_t nums1_order{0}, nums2_order{0};
            while (nums1_order < nums1_size && nums2_order < nums2_size && k != 1) {
                // 正常情况
                const auto half{k / 2};
                const size_t next_nums1_order{std::min(nums1_order + half, nums1_size) - 1},
                        next_nums2_order{std::min(nums2_order + half, nums2_size) - 1};
                const auto v1{nums1[next_nums1_order]}, v2{nums2[next_nums2_order]};
                if (v1 <= v2) {
                    k -= next_nums1_order - nums1_order + 1;
                    nums1_order = next_nums1_order + 1;
                } else {
                    k -= next_nums2_order - nums2_order + 1;
                    nums2_order = next_nums2_order + 1;
                }
            }
            // 边界情况
            if (nums1_order == nums1_size) {
                return nums2[nums2_order + k - 1];
            }
            if (nums2_order == nums2_size) {
                return nums1[nums1_order + k - 1];
            }
            return std::min(nums1[nums1_order], nums2[nums2_order]);
        };
        size_t totalLength{nums1_size + nums2_size};
        if (totalLength % 2 == 0) {
            return (getKthElement(totalLength / 2) + getKthElement(totalLength / 2 - 1)) / 2.0;
        }
        return getKthElement(totalLength / 2);
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
