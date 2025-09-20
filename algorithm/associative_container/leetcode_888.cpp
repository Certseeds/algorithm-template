// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO

#include <cassert>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <unordered_set>
#include <numeric>

namespace leetcode_888 {
using std::unordered_set;
using std::accumulate;
using std::vector;
#endif

class Solution {
public:
    vector<int32_t> fairCandySwap(const vector<int32_t> &alice, const vector<int32_t> &tifa) {
        const int sum1 = accumulate(alice.begin(), alice.end(), 0);
        const int sum2 = accumulate(tifa.begin(), tifa.end(), 0);
        assert((sum1 - sum2) % 2 != 1);
        const int diff = (sum1 - sum2) / 2;
        unordered_set<int32_t> s2;
        for (const auto i: tifa) {
            s2.insert(i);
        }
        const auto aliceSize{alice.size()};
        for (size_t i{0}; i < aliceSize; ++i) {
            if (s2.count(alice[i] - diff) == 1) {
                return {alice[i], alice[i] - diff};
            }
        }
        return {};
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
