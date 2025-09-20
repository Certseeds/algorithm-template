// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_GRAPH_FLOW_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_GRAPH_FLOW_HPP

#include "build_graph.hpp"
#include <cassert>
#include <cstring>
#include <queue>
#include <utility>

namespace graph::flow {
using std::queue;

struct flink : public link {
    int32_t flow{-1};

    flink(int32_t end_, int32_t cost_, int32_t flow_) : link(end_, cost_), flow(flow_) {}
};

using f_adjlist = vector<vector<flink>>;

f_adjlist build_f_adjlist(const adjlist &table) {
    const auto table_size{table.size()};
    f_adjlist will_return(table_size, vector<flink>{});
    for (size_t i{0}; i < table_size; ++i) {
        for (const auto &item: table[i]) {
            will_return[i].emplace_back(item.end, item.cost, 0);
            will_return[item.end].emplace_back(i, 0, 0);
        }
    }
    return will_return;
}

class flow final {
public:
    f_adjlist table; // graph本身
    const int32_t Sn{-1};// 源点
    const int32_t Tn{-1};// 汇点
    int32_t result{0}; // 结果
    /**
    * 这里注意,默认input格式是从1开始对节点计数,所以对Sn,Tn各减一
    **/
    flow(const adjlist &table_, int32_t Sn_, int32_t Tn_) : table(build_f_adjlist(table_)), Sn(Sn_ - 1),
                                                            Tn(Tn_ - 1) {}

    //求取最大流结果
    void maxflow_ek() {
        if (this->Sn == this->Tn) {
            this->result = 0;
            return;
        }
        vector<int32_t> lastpoint(this->table.size(), 0); // lastpoint[i],到i点的上一条边
        vector<int32_t> flows(this->table.size(), 0); // flows[i],到i点的流量
        while (true) {
            std::memset(&flows[0], 0, sizeof(int32_t) * flows.size());
            queue<int32_t> que({this->Sn});
            flows[Sn] = 0x3f3f3f3f;
            while (!que.empty()) {
                const int32_t order = que.front();
                que.pop();
                for (const auto &item: this->table[order]) {
                    if (flows[item.end] != 0) {
                        continue;
                    }
                    if (item.cost > item.flow) {
                        lastpoint[item.end] = order;
                        flows[item.end] = std::min(flows[order], item.cost - item.flow);
                        que.push(item.end);
                    }
                }
                if (flows[this->Tn] != 0) {
                    break;
                }
            }
            if (flows[this->Tn] == 0) {
                break;
            }
            const auto search = [this](int32_t begin, int32_t end) {
                for (int32_t i{0}; static_cast<size_t>(i) < this->table[begin].size(); ++i) {
                    if (this->table[begin][i].end == end) {
                        return i;
                    }
                }
                return -1;
            };
            for (auto end = this->Tn; end != this->Sn; end = lastpoint[end]) {
                const auto begin = lastpoint[end];
                table[begin][search(begin, end)].flow += flows[this->Tn];
                table[end][search(end, begin)].flow -= flows[this->Tn];
            }
            this->result += flows[this->Tn];
        }
    }
};
}

#endif //ALGORITHM_TEMPLATE_ALGORITHM_GRAPH_FLOW_HPP
