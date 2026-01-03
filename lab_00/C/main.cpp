// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <vector>
/*
给定一个无向图 graph,当这个图为二分图时返回 true.

如果我们能将一个图的节点集合分割成两个独立的子集 A 和 B,
并使图中的每一条边的两个节点一个来自 A 集合,一个来自 B 集合,我们就将这个图称为二分图.

每个节点都是一个在 0 到 graph.length-1 之间的整数.
图中没有自环和平行边： graph[i] 中不存在 i,并且 graph[i] 中没有重复的值.

输入格式:
The 1st line contains a single integer N([1,10^6]) —— the number of the nodes in graph

Then there will have N lines of number:

each line the first is a single integer X-- the number of connect nodes of node xi
then there will be X unrepeated numbers ∈ [0,N-1]

 输出格式:
如果是二分图,输出 "PÖSSiBLE"
如果不是二分图,输出 "lMP0SSlBLE"

来源：Leetcode-cn
链接：https://leetcode-cn.com/problems/is-graph-bipartite
著作权归领扣网络所有
*/
/* leetcode
// id: 785
// Graph
// 判断二分图*/
#ifdef ALGORITHM_TEST_MACRO
namespace lab_00_C{
#endif
using std::cin;
using std::cout;
using std::queue;
using std::string;
using std::vector;
static constexpr const char end{'\n'};

enum class Color : int32_t {
    uncolor = -1,
    red = 0,
    black = 1
};
using num_t = int32_t;
using input_type = vector<vector<num_t>>;
using output_type = bool;

inline input_type read();

output_type isBipartite(const input_type &graph);

void output(const output_type &data);

int main() {
    auto input_data = read();
    const auto output_data = isBipartite(input_data);
    output(output_data);
    return 0;
}

inline input_type read() {
    num_t N{0};
    std::cin >> N;
    vector<vector<num_t>> will_return(N);
    for (auto i = 0; i < N; ++i) {
        num_t X{0};
        std::cin >> X;
        will_return[i].resize(X);
        for (auto &j: will_return[i]) {
            std::cin >> j;
        }
    }
    return will_return;
}

output_type isBipartite(const input_type &graph) {
    const auto node_number = graph.size();
    vector<Color> color_vec(node_number, Color::uncolor);
    for (size_t i{0}; i < node_number; ++i) {
        if (!graph[i].empty() && color_vec[i] == Color::uncolor) {
            color_vec[i] = Color::red;
            for (queue<num_t> que{{static_cast<int32_t>(i)}};!que.empty();) {
                const num_t head = que.front();
                que.pop();
                const Color next_color = (color_vec[head] == Color::red) ? Color::black : Color::red;
                for (const auto &j: graph[head]) {
                    if (color_vec[j] == Color::uncolor) {
                        color_vec[j] = next_color;
                        que.push(j);
                    } else if (color_vec[j] == color_vec[head]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

void output(const output_type &data) {
    if (data) {
        std::cout << R"("PÖSSiBLE")" << end;
        // feature in c++11 which named `raw string literals`
    } else {
        std::cout << R"("lMP0SSlBLE")" << end;
    }
}

static const auto faster_streams = [] {
    srand(time(nullptr));
    // use time to init the random seed
    std::ios::sync_with_stdio(false);
    std::istream::sync_with_stdio(false);
    std::ostream::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // 关闭c++风格输入输出 , 与C风格输入输出的同步,提高性能.
    return 0;
}();
#ifdef ALGORITHM_TEST_MACRO
}
#endif
