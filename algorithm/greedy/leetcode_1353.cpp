// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#include <queue>
#include <vector>
#include <cstdint>
#include <algorithm>

#ifdef CS203_DSAA_TEST_MACRO

namespace leetcode_1353 {
using std::priority_queue;
using std::vector;
#endif

class Solution {
public:
    int32_t maxEvents(const vector<vector<int32_t>> &events) {
        int32_t begin{0x3f3f3f3f}, end{0};
        for (const auto &event: events) {
            begin = std::min(begin, event[0]);
            end = std::max(end, event[1]);
        }
        vector<vector<int32_t>> dayToEvents{static_cast<size_t>(end + 1)};
        for (const auto &event: events) {
            dayToEvents[event[0]].push_back(event[1]);
        }
        priority_queue<int32_t, vector<int32_t>, std::greater<>> priorityQueue{};
        int32_t joined{0};
        for (int32_t order{begin}; order <= end; order++) {
            for (const auto lastDay: dayToEvents[order]) {
                priorityQueue.push(lastDay);
            }
            for (; !priorityQueue.empty();) {
                const auto head = priorityQueue.top();
                if (head >= order) {
                    priorityQueue.pop();
                    joined += 1;
                    break;
                }
                priorityQueue.pop();
            }
        }
        return joined;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
