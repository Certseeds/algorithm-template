// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <deque>
#include <iostream>
#include <tuple>
#include <vector>

#ifndef ALGORITHM_TEST_MACRO
#pragma GCC optimize(3, "Ofast", "inline", "no-stack-protector", "unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC target("mmx")
#else
namespace lab_05_E {
#endif
using std::cin;
using std::cout;
using std::deque;
using std::tie;
using std::tuple;
using std::vector;
using num_t = int32_t;

// Operation and test case definitions for structured input
struct Operation {
    int op, u, w, v, val;
};

struct TestCase {
    int n, q;
    vector<Operation> ops;
};

using input_type = vector<TestCase>;
using output_type = vector<num_t>;

static constexpr const char end{'\n'};

inline input_type read();

// Process test cases and collect outputs
output_type cal(const input_type &tests);

void output(const output_type &data);

int main() {
    const auto input_data = read();
    const auto output_data = cal(input_data);
    output(output_data);
    return 0;
}

// Read all test cases and operations
inline input_type read() {
    input_type tests;
    int n, q;
    while (cin >> n >> q) {
        TestCase tc{n, q, {}};
        tc.ops.reserve(q);
        for (int i = 0; i < q; ++i) {
            Operation o{};
            cin >> o.op;
            if (o.op == 1) {
                cin >> o.u >> o.w >> o.val;
            } else if (o.op == 2) {
                cin >> o.u >> o.w;
            } else if (o.op == 3) {
                cin >> o.u >> o.v >> o.w;
            }
            tc.ops.push_back(o);
        }
        tests.push_back(std::move(tc));
    }
    return tests;
}

// Output all collected results
void output(const output_type &data) {
    for (num_t v: data) cout << v << end;
}

// Process test cases and collect outputs
output_type cal(const input_type &tests) {
    output_type results;
    for (const auto &tc: tests) {
        int n = tc.n;
        vector<deque<int> > buckets(n + 1);
        vector<int> bid(n + 1);
        vector<char> rev(n + 1, 0);
        for (int i = 1; i <= n; ++i) bid[i] = i;
        for (const auto &o: tc.ops) {
            if (o.op == 1) {
                int u = o.u, w = o.w, val = o.val;
                int b = bid[u];
                if (w == 0) {
                    if (!rev[u]) buckets[b].push_front(val);
                    else buckets[b].push_back(val);
                } else {
                    if (!rev[u]) buckets[b].push_back(val);
                    else buckets[b].push_front(val);
                }
            } else if (o.op == 2) {
                int u = o.u, w = o.w;
                int b = bid[u];
                if (buckets[b].empty()) {
                    results.push_back(-1);
                } else {
                    int ans;
                    if (w == 0) {
                        if (!rev[u]) {
                            ans = buckets[b].front();
                            buckets[b].pop_front();
                        } else {
                            ans = buckets[b].back();
                            buckets[b].pop_back();
                        }
                    } else {
                        if (!rev[u]) {
                            ans = buckets[b].back();
                            buckets[b].pop_back();
                        } else {
                            ans = buckets[b].front();
                            buckets[b].pop_front();
                        }
                    }
                    results.push_back(ans);
                }
            } else if (o.op == 3) {
                int u = o.u, v = o.v, w = o.w;
                if (u == v) continue;
                int bu = bid[u], bv = bid[v];
                if (buckets[bv].empty()) continue;

                // Choose target bucket to minimize moves
                if ((int) buckets[bu].size() >= (int) buckets[bv].size()) {
                    // Append into u's bucket
                    const bool push_to_back = (rev[u] == 0);
                    const bool take_back_to_front = ((rev[v] ^ w) == 1); // true => take back->front
                    if (!take_back_to_front) {
                        while (!buckets[bv].empty()) {
                            int x = buckets[bv].front();
                            buckets[bv].pop_front();
                            if (push_to_back)
                                buckets[bu].push_back(x);
                            else
                                buckets[bu].push_front(x);
                        }
                    } else {
                        while (!buckets[bv].empty()) {
                            int x = buckets[bv].back();
                            buckets[bv].pop_back();
                            if (push_to_back)
                                buckets[bu].push_back(x);
                            else
                                buckets[bu].push_front(x);
                        }
                    }
                    // v becomes empty automatically
                } else {
                    // Build into v's bucket, then reassign it to u
                    int new_rev_u = rev[v] ^ w;
                    if (new_rev_u == 0) {
                        // Physical P = U + current V; push U to front preserving U logical order
                        if (rev[u] == 0) {
                            while (!buckets[bu].empty()) {
                                int x = buckets[bu].back();
                                buckets[bu].pop_back();
                                buckets[bv].push_front(x);
                            }
                        } else {
                            while (!buckets[bu].empty()) {
                                int x = buckets[bu].front();
                                buckets[bu].pop_front();
                                buckets[bv].push_front(x);
                            }
                        }
                    } else {
                        // new_rev_u == 1: Physical P = current V + reverse(U); push reverse(U) to back
                        if (rev[u] == 0) {
                            while (!buckets[bu].empty()) {
                                int x = buckets[bu].back();
                                buckets[bu].pop_back();
                                buckets[bv].push_back(x);
                            }
                        } else {
                            while (!buckets[bu].empty()) {
                                int x = buckets[bu].front();
                                buckets[bu].pop_front();
                                buckets[bv].push_back(x);
                            }
                        }
                    }
                    // Reassign buckets
                    bid[u] = bv;
                    bid[v] = bu; // now empty
                    rev[u] = new_rev_u;
                }
            }
        }
    }
    return results;
}


static const auto faster_streams = [] {
    srand(time(nullptr));
    std::ios::sync_with_stdio(false);
    std::istream::sync_with_stdio(false);
    std::ostream::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

#ifdef ALGORITHM_TEST_MACRO
}
#endif
