// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <algorithm>
#include <iostream>
#include <stack>
#include <tuple>
#include <vector>
#include <cstdio>
#include <cstdint>
#include <cstring>

#ifndef ALGORITHM_TEST_MACRO
#pragma GCC optimize(3, "Ofast", "inline", "no-stack-protector", "unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC target("tune=native")
#else
namespace lab_05_G{
#endif

using std::cin;
using std::cout;
using std::vector;
using std::pair;
using std::int64_t;
static constexpr const char end{'\n'};

struct Fenwick {
    int n;
    vector<int64_t> bit;
    Fenwick(int n_=0) { init(n_); }
    void init(int n_) {
        n = n_;
        bit.assign(n + 1, 0);
    }
    inline void add(int idx, int64_t delta) {
        for (; idx <= n; idx += idx & -idx) bit[idx] += delta;
    }
    inline int64_t sum(int idx) const {
        int64_t res = 0;
        for (; idx > 0; idx -= idx & -idx) res += bit[idx];
        return res;
    }
    inline int64_t range_sum(int l, int r) const {
        if (l > r) return 0;
        return sum(r) - sum(l - 1);
    }
};

struct Event {
    int x;     // threshold on v
    int l, r;  // u range
    int id;    // query id
    int w;     // +1 or -1
    bool operator<(const Event& other) const {
        return x < other.x;
    }
};

struct Group {
    int h;
    vector<int> idxs; // positions with equal height (stack-top group)
};

struct Input {
    int n, q;
    vector<int> h;
    vector<pair<int, int>> queries;
};

Input read_input() {
    Input in;
    if (!(cin >> in.n >> in.q)) return in;
    in.h.resize(in.n + 1);
    for (int i = 1; i <= in.n; ++i) cin >> in.h[i];
    in.queries.resize(in.q);
    for (int i = 0; i < in.q; ++i) {
        cin >> in.queries[i].first >> in.queries[i].second;
    }
    return in;
}

vector<int64_t> solve(const Input& in) {
    // Build all visible pairs (u, v), u < v
    vector<pair<int,int>> edges;
    edges.reserve(2 * in.n);
    vector<Group> st;
    st.reserve(in.n);

    for (int i = 1; i <= in.n; ++i) {
        while (!st.empty() && st.back().h < in.h[i]) {
            const int u = st.back().idxs.back();
            edges.emplace_back(u, i);
            st.pop_back();
        }
        if (st.empty()) {
            st.push_back(Group{in.h[i], vector<int>{i}});
        } else if (st.back().h == in.h[i]) {
            int u = st.back().idxs.back();
            edges.emplace_back(u, i);
            st.back().idxs.push_back(i);
        } else { // st.back().h > h[i]
            int u = st.back().idxs.back();
            edges.emplace_back(u, i);
            st.push_back(Group{in.h[i], vector<int>{i}});
        }
    }

    // Offline answer queries
    std::sort(edges.begin(), edges.end(),
              [](const pair<int,int>& a, const pair<int,int>& b){ return a.second < b.second; });

    vector<Event> events;
    events.reserve(2 * in.q);
    vector<int64_t> ans(in.q, 0);
    for (int id = 0; id < in.q; ++id) {
        int l = in.queries[id].first;
        int r = in.queries[id].second;
        events.push_back(Event{r, l, r, id, +1});
        events.push_back(Event{l - 1, l, r, id, -1});
    }
    std::sort(events.begin(), events.end());

    Fenwick bit(in.n);
    size_t epos = 0;
    for (const auto& ev : events) {
        while (epos < edges.size() && edges[epos].second <= ev.x) {
            bit.add(edges[epos].first, 1);
            ++epos;
        }
        ans[ev.id] += (int64_t)ev.w * bit.range_sum(ev.l, ev.r);
    }
    return ans;
}

void print_output(const vector<int64_t>& ans) {
    for (const auto& val : ans) {
        cout << val << end;
    }
}

int main() {
    auto input = read_input();
    if (input.n == 0) return 0;
    auto ans = solve(input);
    print_output(ans);
    return 0;
}

#ifdef ALGORITHM_TEST_MACRO
}
#endif
