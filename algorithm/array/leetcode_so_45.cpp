// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO

#include <array>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <string>

namespace leetcode_so_45 {
using std::array;
using std::vector;
using std::string;
#endif

class Solution {
public:
    string minNumber(const vector<int32_t> &numsImmutable) {
        auto nums{numsImmutable};
        const auto comp = [](auto nums1, auto nums2) {
            const auto tovec = [](auto nums_fst, auto nums_snd) {
                vector<uint8_t> vec{};
                if (nums_fst == 0) { vec.push_back(0); }
                for (; nums_fst != 0; nums_fst /= 10) { vec.push_back(nums_fst % 10); }
                if (nums_snd == 0) { vec.push_back(0); }
                for (; nums_snd != 0; nums_snd /= 10) { vec.push_back(nums_snd % 10); }
                return vector<uint8_t>{vec.crbegin(), vec.crend()};
                // TODO,此处可优化
            };
            const vector<uint8_t> fst = tovec(nums1, nums2), snd = tovec(nums2, nums1);
            const auto length = fst.size();
            for (size_t i{0}; i < length; ++i) {
                if (fst[i] > snd[i]) {
                    return true;
                } else if (fst[i] < snd[i]) {
                    return false;
                }
            }
            return false;
        };
        std::sort(nums.begin(), nums.end(), comp);
        string will_return{};
        for (const auto num: nums) {
            will_return += std::to_string(num);
        }
        return will_return;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif