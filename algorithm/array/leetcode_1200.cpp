// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO

#include <vector>
#include <algorithm>
#include <limits>

namespace leetcode_1200 {
using std::vector;
#endif

class Solution {
public:
    vector<vector<int32_t>> minimumAbsDifference(const vector<int32_t> &arr_) {
        vector<int32_t> arr{arr_};
        std::sort(arr.begin(), arr.end());
        int32_t minDiff = std::numeric_limits<int>::max() - 1;
        vector<vector<int32_t>> will_return{};
        for (auto fst = arr.cbegin(), snd = fst + 1; snd != arr.cend(); ++fst, ++snd) {
            const auto diff = (*snd - *fst);
            if (minDiff > diff) {
                minDiff = diff;
                will_return.clear();
                will_return.push_back({*fst, *snd});
            } else if (minDiff == diff) {
                will_return.push_back({*fst, *snd});
            }
        }
        return will_return;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
