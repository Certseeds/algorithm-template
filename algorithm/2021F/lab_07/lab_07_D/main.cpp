// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <tuple>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

#ifndef ALGORITHM_TEST_MACRO
#pragma GCC optimize(3, "Ofast", "inline", "no-stack-protector", "unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC target("native")
#else
namespace lab_07_D {
#endif
using std::tie;
using std::cin;
using std::cout;
using std::tuple;
using std::vector;
static constexpr const char end{'\n'};

struct Input {
    int T{0};
    std::vector<std::pair<std::string, std::string>> cases;
};

using output_type = std::vector<long long>;

static Input read_input() {
    Input in{};
    if (!(cin >> in.T)) return in;
    in.cases.reserve(std::max(0, in.T));
    for (int i = 0; i < in.T; ++i) {
        std::string pre, post;
        cin >> pre >> post;
        in.cases.emplace_back(pre, post);
    }
    return in;
}

// recursive solver: returns number of binary trees for given pre[pl..pr] and post[ol..or]
static long long solve_one(const std::string &pre, int pl, int pr,
                           const std::string &post, int ol, int orr,
                           const std::unordered_map<char, int> &pos) {
    if (pl > pr) return 1;
    if (pl == pr) return 1; // single node
    long long ways = 1;
    int children = 0;
    int i = pl + 1; // next position in pre for children
    int o = ol;
    while (i <= pr) {
        char rootChild = pre[i];
        auto it = pos.find(rootChild);
        if (it == pos.end()) return 0; // invalid
        const int idx = it->second;
        const int sz = idx - o + 1; // size of this child's subtree
        ways *= solve_one(pre, i, i + sz - 1, post, o, idx, pos);
        ++children;
        i += sz;
        o = idx + 1;
    }
    if (children == 1) ways *= 2; // single child: left/right ambiguity
    return ways;
}

static output_type solve(const Input &in) {
    output_type out;
    out.reserve(in.cases.size());
    for (const auto &c: in.cases) {
        const auto &pre = c.first;
        const auto &post = c.second;
        std::unordered_map<char, int> pos;
        for (int i = 0; i < static_cast<int>(post.size()); ++i) pos[post[i]] = i;
        long long res = solve_one(pre, 0, static_cast<int>(pre.size()) - 1, post, 0, static_cast<int>(post.size()) - 1,
                                  pos);
        out.push_back(res);
    }
    return out;
}

static void write_output(const output_type &outv) {
    for (const auto &v: outv) {
        cout << v << end;
    }
}

int main() {
    const auto in = read_input();
    if (in.T <= 0) return 0;
    const auto outv = solve(in);
    write_output(outv);
    return 0;
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
