// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds

#ifdef ALGORITHM_TEST_MACRO
namespace leetcode_435 {
using std::vector;
#endif

class Solution {
public:
    // 逆向思维来看, 这个问题就相当于排课问题中应该排出多少门课程的结果之反: 应该排除多少门课程
    // 因此, 采用经典贪心解法,一直选取最早结束的课程,即可获取答案.
    int32_t eraseOverlapIntervals(const vector<vector<int32_t>> &intervals) {
        vector<vector<int32_t>> times{intervals};
        auto will_return = static_cast<int32_t>(times.size());
        std::sort(std::begin(times), std::end(times), [](const auto &p1, const auto &p2) { return p1[1] < p2[1]; });
        int32_t end{std::numeric_limits<int32_t>::min()};
        for (const auto &p: times) {
            if (p[0] >= end) {
                end = p[1];
                --will_return;
            }
        }
        return will_return;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
