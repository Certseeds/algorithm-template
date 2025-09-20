// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO

#include <vector>
#include <unordered_map>
#include <cstdint>

namespace leetcode_167 {
using std::vector;
using std::unordered_map;
#endif

class Solution {
public:
    vector<int32_t> twoSum(const vector<int32_t> &numbers, int32_t target) {
        unordered_map<int32_t, int32_t> umap;
        for (size_t i{0}, nums_size{numbers.size()}; i < nums_size; i++) {
            const auto iPlus = static_cast<int32_t>(i + 1);
            if (umap.count(target - numbers[i]) != 0) {
                return {umap[target - numbers[i]], iPlus};
            } else {
                umap[numbers[i]] = iPlus;
            }
        }
        return {-1, -1};
    }

    vector<int32_t> twoSum2(const vector<int32_t> &numbers, int32_t target) {
        int32_t begin{0};
        auto ends = static_cast<int32_t>(numbers.size() - 1);
        int32_t sum{numbers[begin] + numbers[ends]};
        while (begin < ends && sum != target) {
            if (sum > target) {
                ends--;
            } else if (sum < target) {
                begin++;
            }
            sum = numbers[begin] + numbers[ends];
        }
        return {begin + 1, ends + 1};
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
