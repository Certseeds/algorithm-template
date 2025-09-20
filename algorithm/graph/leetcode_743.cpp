// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO
#include <queue>
#include <unordered_set>
#include <vector>
#include <cstdint>
#include <algorithm>

namespace leetcode_743 {
using std::priority_queue;
using std::unordered_set;
using std::vector;
#endif

class Solution {
public:
    int32_t networkDelayTime(const vector<vector<int32_t>> &times, int32_t n, int32_t k) {
        struct time_ {
            int32_t end, cost;

            time_(int32_t end, int32_t cost) : end(end), cost(cost) {}

            bool operator<(const time_ &v2) const { return this->cost > v2.cost; }
        };
        k -= 1;
        vector<vector<time_>> dis(n, vector<time_>{});
        vector<int32_t> results(n, 0x3f3f3f3f);
        for (const auto &time: times) {
            const auto &first = time[0];
            const auto &second = time[1];
            const auto &third = time[2];
            dis[first - 1].emplace_back(second - 1, third);
        }
        priority_queue<time_> priorityQueue{};
        unordered_set<int32_t> uMap{};
        results[k] = 0;
        priorityQueue.emplace(k, -1);
        while (!priorityQueue.empty()) {
            const auto head = priorityQueue.top();
            priorityQueue.pop();
            for (auto &i: dis[head.end]) {
                const auto val = results[head.end] + i.cost;
                if (val < results[i.end]) {
                    results[i.end] = val;
                    priorityQueue.push(i);
                }
            }
        }
        const int32_t will_return = *std::max_element(std::cbegin(results), std::cend(results));
        return will_return == 0x3f3f3f3f ? -1 : will_return;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
