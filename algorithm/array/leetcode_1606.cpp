// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <queue>
#include <map>
#include <cstdint>
#include <cstddef>
#include <vector>

using std::map;
using std::vector;
using std::priority_queue;

namespace leetcode_1606 {
#endif

struct server {
    int32_t order;
    int32_t finishTime;
    int32_t times;

    bool operator<(const server &serv) const {
        return this->finishTime > serv.finishTime;
    }
};

class Solution {
public:
// 最简单的思路是模拟数组, 但是这样是O(N^2),需要优化
// 根源在于如果维护一个数组, 必须按顺序遍历数组内的元素,才能得到具体哪一个可用
// 这个过程中浪费了很多资源来过滤那些不可用的
// 所以需要将running的服务置于另一个容器中, 每次将本次可用的搬回来, 减少遍历复杂度
// 这样每次最坏O(N)就变成了每次最坏O1遍历
// 一个服务激活一次也只能重入一次
    vector<int32_t> busiestServers(int32_t k, const vector<int32_t> &arrival, const vector<int32_t> &load) {
        const auto arr_size = arrival.size();
        map<int32_t, server> canUse{};
        for (int32_t i{0}; i < k; ++i) {
            canUse.insert(std::pair{i, server{i, 0, 0}});
        }
        priority_queue<server> works{};
        int32_t max{-1};
        for (size_t i{0}; i < arr_size; ++i) {
            while (!works.empty()) {
                const auto head = works.top();
                if (head.finishTime <= arrival[i]) {
                    works.pop();
                    canUse.insert(std::pair{head.order, head});
                } else {
                    break;
                }
            }
            if (canUse.empty()) {
                continue;
            }
            const auto iter = canUse.lower_bound(i % k);
            if (iter != std::end(canUse)) {
                works.push(server{iter->first, arrival[i] + load[i], iter->second.times + 1});
                max = std::max(max, iter->second.times + 1);
                canUse.erase(iter);
            } else {
                const auto iter2 = std::begin(canUse);
                const auto times = iter2->second.times + 1;
                works.push(server{iter2->first, arrival[i] + load[i], times});
                max = std::max(max, times);
                canUse.erase(iter2);
            }
        }
        for (; !works.empty(); works.pop()) {
            const auto top = works.top();
            canUse.insert(std::pair{top.order, top});
        }
        vector<int32_t> will_return{};
        for (const auto [key, v]: canUse) {
            if (v.times == max) {
                will_return.push_back(key);
            }
        }
        return will_return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
