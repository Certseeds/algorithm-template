// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_GRAPH_TOPOSORT_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_GRAPH_TOPOSORT_HPP

#include <cassert>
#include <queue>
#include <unordered_set>
#include "build_graph.hpp"

namespace graph {
namespace toposort {

class graphlist final {
    vector<vector<link>> graph;
public:
    graphlist(const vector<vector<int32_t>> &input, int32_t node_num) : graph(node_num, vector<link>{}) {
        check_graph_cost_all_positive(input);
        for (const auto &item: input) {
            graph[item[0] - 1].emplace_back(item[1] - 1, item[2]);
        }
    }

    inline size_t size() const { return graph.size(); }

    inline auto at(size_t size) const { return graph.at(size); }

    // 拿到一个拓扑排序顺序, 不唯一, 特征依托于优先队列的设置
    vector<size_t> toposort() const {
        const auto this_size{this->size()};
        vector<size_t> result;
        result.reserve(this_size);
        vector<size_t> in(this_size, 0);
        for (const auto &links: this->graph) {
            for (const auto &link: links) {
                ++in[link.end];
            }
        }
        std::priority_queue<size_t> pri_que;
        for (size_t i{0}; i < this_size; ++i) {
            if (in[i] == 0) { pri_que.push(i); }
        }
        while (!pri_que.empty()) {
            const auto head = pri_que.top();
            pri_que.pop();
            for (const auto &link: this->at(head)) {
                --in[link.end];
                if (in[link.end] == 0) {
                    pri_que.push(link.end);
                }
            }
            result.push_back(head);
        }
        return result;
    }

    static size_t hash(const vector<size_t> &vec) {
        size_t seed{vec.size()};
        for (const auto &i: vec) {
            seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }

    // 拿到所有拓扑排序
    vector<vector<size_t>> toposorts() const {
        const auto this_size{this->size()};
        vector<size_t> in(this_size, 0);
        for (const auto &links: this->graph) {
            for (const auto &link: links) {
                ++in[link.end];
            }
        }
        std::unordered_set<size_t> next, uset;
        vector<vector<size_t>> will_return;

        for (size_t i{0}; i < this_size; ++i) {
            if (in[i] == 0) {
                next.insert(i);
            }
        }
        for (const auto &i: next) {
            std::unordered_set<size_t> next_erase{next};
            next_erase.erase(i);
            const auto result = toposorts({{}}, i, in, next_erase);
            for (const auto &path: result) {
                const auto[fst, snd] = uset.insert(hash(path));
                if (snd) {
                    will_return.push_back(path);
                }
            }
        }
        return will_return;
    }

    vector<vector<size_t>>
    toposorts(const vector<vector<size_t>> &pres, size_t head, vector<size_t> in,
              std::unordered_set<size_t> nexts) const {
        for (const auto &link: this->at(head)) {
            --in[link.end];
            if (in[link.end] == 0) {
                nexts.insert(link.end);
            }
        }
        vector<vector<size_t>> one_step;
        for (const auto &path: pres) {
            one_step.push_back(path);
            one_step.back().push_back(head);
        }
        if (nexts.empty()) {
            return one_step;
        }
        vector<vector<size_t>> will_return{};
        std::unordered_set<size_t> uset;
        for (const auto &ele: nexts) {
            std::unordered_set<size_t> next_erase{nexts};
            next_erase.erase(ele);
            const auto result = toposorts(one_step, ele, in, next_erase);
            for (const auto &path: result) {
                const auto[fst, snd] = uset.insert(hash(path));
                if (snd) {
                    will_return.push_back(path);
                }
            }
        }
        return will_return;
    }
};

}
}
#endif // ALGORITHM_TEMPLATE_ALGORITHM_GRAPH_TOPOSORT_HPP
