// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <cstdint>
#include <vector>
#include <array>
#include <iostream>
#include <algorithm>

#ifndef ALGORITHM_TEST_MACRO
#pragma GCC optimize(3, "Ofast", "inline", "no-stack-protector", "unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#else
namespace lab_04_G {
#endif

using int32 = std::int32_t;
using int64 = std::int64_t;
static constexpr int64 MOD = 1000000007LL;

struct TestCase {
    int32 n, k;
    std::vector<int32> a;
};

std::vector<TestCase> read_input();

std::vector<int64> solve(const std::vector<TestCase> &cases);

void write_output(const std::vector<int64> &answers);

inline int64 mod_mul64(int64 a, int64 b) { return (a * b) % MOD; }

int32 main() {
    const auto input_data = read_input();
    const auto results = solve(input_data);
    write_output(results);
    return 0;
}

std::vector<TestCase> read_input() {
    std::vector<TestCase> data;

    int32 T;
    if (!(std::cin >> T)) return data;
    data.reserve(T);
    for (int32 _ = 0; _ < T; ++_) {
        TestCase tc;
        std::cin >> tc.n >> tc.k;
        tc.a.resize(tc.n);
        for (int32 i = 0; i < tc.n; ++i) std::cin >> tc.a[i];
        data.push_back(std::move(tc));
    }
    return data;
}

std::vector<int64> solve(const std::vector<TestCase> &cases) {
    std::vector<int64> outputs;
    outputs.reserve(cases.size());

    for (const auto &tc: cases) {
        const int32 n = tc.n, k = tc.k;
        const auto &a = tc.a;

        // k == 1: sum of max^2 over all subarrays via nearest greater by value
        if (k == 1) {
            std::vector<int32> NL(n + 1, 0), NR(n + 1, n + 1);
            std::vector<int32> st;
            st.reserve(n);
            for (int32 i = 1; i <= n; ++i) {
                int32 ai = a[i - 1];
                while (!st.empty() && a[st.back() - 1] < ai) st.pop_back();
                NL[i] = st.empty() ? 0 : st.back();
                st.push_back(i);
            }
            st.clear();
            for (int32 i = 1; i <= n; ++i) {
                while (!st.empty() && a[i - 1] > a[st.back() - 1]) {
                    NR[st.back()] = i;
                    st.pop_back();
                }
                st.push_back(i);
            }
            uint64_t acc = 0ULL;
            for (int32 i = 1; i <= n; ++i) {
                int64 cnt = (int64) (i - NL[i]) * (NR[i] - i) % MOD;
                int64 v = a[i - 1] % MOD;
                acc += (uint64_t) mod_mul64(cnt, mod_mul64(v, v));
            }
            outputs.push_back((int64) (acc % MOD));
            continue;
        }

        // value -> position (permutation)
        std::vector<int32> pos(n + 1);
        for (int32 i = 1; i <= n; ++i) pos[a[i - 1]] = i;

        // bitset of active positions (value greater than current v)
        const int W = 64;
        const int words = (n + W - 1) / W;
        std::vector<uint64_t> bits(words, 0ULL);

        const int K1 = k - 1;
        std::array<int32, 85> Lpos{}, Rpos{}, maxLeft{}, maxRight{}, dL{}, dR{};

        uint64_t acc = 0ULL;

        for (int32 v = n; v >= 1; --v) {
            int32 p = pos[v];
            int32 aj = a[p - 1];
            int64 aj_mod = aj % MOD;

            // left neighbors: fill Lpos[1..k], Lpos[0]=p, rest 0
            Lpos[0] = p; {
                int need = k, u = 1;
                int idx = (p - 1) >> 6;
                int off = (p - 1) & 63;
                uint64_t mask = (off == 0) ? 0ULL : (bits[idx] & ((~0ULL) >> (64 - off)));
                while (need > 0) {
                    while (need > 0 && mask) {
                        int msb = 63 - __builtin_clzll(mask);
                        int32 q = (idx << 6) + msb + 1; // back to 1-based
                        Lpos[u++] = q;
                        --need;
                        mask ^= (1ULL << msb);
                    }
                    if (need == 0) break;
                    if (--idx < 0) break;
                    mask = bits[idx];
                }
                for (; u <= k; ++u) Lpos[u] = 0;
            }

            // right neighbors: fill Rpos[1..k], Rpos[0]=p, rest n+1
            Rpos[0] = p; {
                int need = k, t = 1;
                int idx = (p - 1) >> 6;
                int off = (p - 1) & 63;
                uint64_t mask;
                if (off == 63) mask = 0ULL;
                else {
                    uint64_t lowMask = (1ULL << (off + 1)) - 1ULL;
                    mask = bits[idx] & (~lowMask);
                }
                while (need > 0) {
                    while (need > 0 && mask) {
                        int lsb = __builtin_ctzll(mask);
                        int32 q = (idx << 6) + lsb + 1;
                        Rpos[t++] = q;
                        --need;
                        mask &= (mask - 1);
                    }
                    if (need == 0) break;
                    if (++idx >= words) break;
                    mask = bits[idx];
                }
                for (; t <= k; ++t) Rpos[t] = n + 1;
            }

            // prefix maxima of neighbor values (only need up to K1)
            maxLeft[0] = 0;
            for (int u = 1; u <= K1; ++u) {
                int32 q = Lpos[u];
                int32 val = (q == 0 ? 0 : a[q - 1]);
                maxLeft[u] = std::max(maxLeft[u - 1], val);
            }
            maxRight[0] = 0;
            for (int t = 1; t <= K1; ++t) {
                int32 q = Rpos[t];
                int32 val = (q == n + 1 ? 0 : a[q - 1]);
                maxRight[t] = std::max(maxRight[t - 1], val);
            }

            // deltas for endpoints
            for (int u = 0; u <= K1; ++u) dL[u] = Lpos[u] - Lpos[u + 1];
            for (int t = 0; t <= K1; ++t) dR[t] = Rpos[t + 1] - Rpos[t];

            // accumulate contributions
            for (int u = 0; u <= K1; ++u) {
                int t = K1 - u;
                int32 dl = dL[u], dr = dR[t];
                if (dl <= 0 || dr <= 0) continue;

                int32 mval = std::max(maxLeft[u], maxRight[t]);
                if (mval == 0) continue;

                int64 ways = ((int64) dl * (int64) dr) % MOD;
                int64 prod = mod_mul64(aj_mod, (int64) mval % MOD);
                int64 term = mod_mul64(ways, prod);
                acc += (uint64_t) term;
            }

            // activate position p
            int w = (p - 1) >> 6;
            int b = (p - 1) & 63;
            bits[w] |= (1ULL << b);
        }

        outputs.push_back((int64) (acc % MOD));
    }
    return outputs;
}

void write_output(const std::vector<int64> &answers) {
    for (auto v: answers) std::cout << v << '\n';
}

static const auto faster_streams = [] {
    std::ios::sync_with_stdio(false);
    std::istream::sync_with_stdio(false);
    std::ostream::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

#ifdef ALGORITHM_TEST_MACRO
} // namespace lab_04_G
#endif
