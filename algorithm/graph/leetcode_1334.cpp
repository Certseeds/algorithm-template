// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#include "leetcode_1334_test.hpp"
#include <queue>
#include <climits>
#include <algorithm>

namespace leetcode_1334 {
using std::priority_queue;

//TODO floyd求多元最短路径

//本质上是一个单源最短路径
vector<int> minimum_path(const vector<vector<std::pair<int32_t, int32_t>>> &map, const int n) {
    constexpr const auto cmp = [](
            const std::pair<int32_t, int32_t> &p1, const std::pair<int32_t, int32_t> &p2) -> bool {
        return p1.second < p2.second;
    };
    priority_queue<std::pair<int32_t, int32_t>, vector<std::pair<int32_t, int32_t>>, decltype(cmp)> nodes(cmp);
    vector<int32_t> d(map.size(), std::numeric_limits<int32_t>::max());
    d[n] = 0;
    nodes.emplace(n, 0);
    while (!nodes.empty()) {
        const auto root = nodes.top();
        nodes.pop();
        const int root_v = root.first;
        for (size_t i{0}, map_root_v_size{map[root_v].size()}; i < map_root_v_size; ++i) {
            const auto [fst, snd] = map[root_v][i];
            if (d[fst] > d[root_v] + snd) {
                d[fst] = d[root_v] + snd;
                nodes.emplace(fst, d[fst]);
            }
        }
    }
    return d;
}

// 使用多次单源最短路径, 所以会比较慢
int32_t leetcode_1334::findTheCity(int32_t n, const vector<vector<int32_t>> &edges, int32_t distanceThreshold) {
    vector<vector<std::pair<int, int>>> maps(n);
    const auto cmp = [distanceThreshold](int32_t i) { return i <= distanceThreshold; };
    for (size_t i{0}, edges_size{edges.size()}; i < edges_size; ++i) {
        if (edges[i][2] <= distanceThreshold) {
            maps[edges[i][0]].emplace_back(edges[i][1], edges[i][2]);
            maps[edges[i][1]].emplace_back(edges[i][0], edges[i][2]);
        }
    }
    int32_t count = INT16_MAX;
    int32_t willreturn = -1;
    for (int32_t i{0}; i < n; ++i) {
        const vector<int32_t> dis = minimum_path(maps, i);
        const int32_t temp = std::count_if(dis.begin(), dis.end(), cmp) - 1;
        if (count >= temp) {
            count = temp;
            willreturn = i;
        }
    }
    return willreturn;
}
}
