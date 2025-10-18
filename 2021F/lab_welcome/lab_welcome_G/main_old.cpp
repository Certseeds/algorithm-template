// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#pragma GCC optimize(3, "Ofast", "inline", "no-stack-protector", "unroll-loops")
#include <list>
#include <array>
#include <deque>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <vector>
#include <cstdint>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <ctime>

#ifdef ALGORITHM_TEST_MACRO
namespace lab_welcome_G{
#endif

using std::cin;
using std::tie;
using std::cout;
using std::list;
using std::sort;
using std::array;
using std::deque;
using std::queue;
using std::stack;
using std::tuple;
using std::string;
using std::vector;
using std::unordered_map;
using std::unordered_set;
using std::priority_queue;
static constexpr const char end{'\n'};

using num_t = int32_t;
using input_type = tuple<num_t, num_t>;
using output_type = num_t;

inline input_type read();

output_type cal(input_type data);

void output(const output_type &data);

// gcd for older compilers
static inline int64_t igcd(int64_t a, int64_t b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b) {
        int64_t t = a % b;
        a = b;
        b = t;
    }
    return a;
}

static inline uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15ULL;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    return x ^ (x >> 31);
}

struct Frac {
    int64_t p, q; // q > 0, reduced; 0 -> 0/1
    Frac() : p(0), q(1) {}
    Frac(int64_t _p, int64_t _q) : p(_p), q(_q) { norm(); }
    inline void norm() {
        if (q < 0) { q = -q; p = -p; }
        if (p == 0) { q = 1; return; }
        int64_t a = p >= 0 ? p : -p;
        int64_t b = q >= 0 ? q : -q;
        int64_t g = igcd(a, b);
        if (g > 1) { p /= g; q /= g; }
    }
};

static inline Frac add(const Frac& a, const Frac& b) {
    return Frac(a.p * b.q + b.p * a.q, a.q * b.q);
}
static inline Frac sub(const Frac& a, const Frac& b) {
    return Frac(a.p * b.q - b.p * a.q, a.q * b.q);
}
static inline Frac mul(const Frac& a, const Frac& b) {
    return Frac(a.p * b.p, a.q * b.q);
}
static inline bool is_zero(const Frac& a) { return a.p == 0; }
static inline Frac divide(const Frac& a, const Frac& b) {
    return Frac(a.p * b.q, a.q * b.p);
}

static inline uint64_t hash_int_vec(const vector<int64_t>& v) {
    uint64_t h = 1469598103934665603ULL;
    h ^= splitmix64((uint64_t)v.size() + 0x9e3779b97f4a7c15ULL);
    for (auto x : v) {
        uint64_t y = (uint64_t)x ^ (uint64_t)(x << 23) ^ (uint64_t)(x >> 17);
        h ^= splitmix64(y + 0x9e3779b97f4a7c15ULL + (h << 6) + (h >> 2));
    }
    return h;
}
static inline uint64_t hash_frac_vec(vector<Frac> v) {
    sort(v.begin(), v.end(), [](const Frac& a, const Frac& b){
        if (a.p != b.p) return a.p < b.p;
        return a.q < b.q;
    });
    uint64_t h = 1099511628211ULL;
    h ^= splitmix64((uint64_t)v.size() + 0x517cc1b727220a95ULL);
    for (auto &f : v) {
        uint64_t a = splitmix64((uint64_t)f.p ^ 0x9e3779b97f4a7c15ULL);
        uint64_t b = splitmix64((uint64_t)f.q ^ 0x94d049bb133111ebULL);
        h ^= splitmix64(a + 0x9e3779b97f4a7c15ULL + (h << 6) + (h >> 2));
        h ^= splitmix64(b + 0xbf58476d1ce4e5b9ULL + (h << 7) + (h >> 1));
    }
    return h;
}

static inline void canonical_sort(vector<int64_t>& v) {
    sort(v.begin(), v.end());
}
static inline void canonical_sort(vector<Frac>& v) {
    sort(v.begin(), v.end(), [](const Frac& a, const Frac& b){
        if (a.p != b.p) return a.p < b.p;
        return a.q < b.q;
    });
}

static bool canReachIntTarget(const vector<int64_t>& nums_in, int64_t target,
                              unordered_set<uint64_t>& memo) {
    vector<int64_t> nums = nums_in;
    canonical_sort(nums);
    const size_t n = nums.size();
    uint64_t key = hash_int_vec(nums);
    if (memo.find(key) != memo.end()) return false;
    if (n == 1) {
        return nums[0] == target;
    }
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i + 1; j < n; ++j) {
            int64_t a = nums[i], b = nums[j];
            vector<int64_t> rest;
            rest.reserve(n - 1);
            for (size_t k = 0; k < n; ++k) {
                if (k != i && k != j) rest.push_back(nums[k]);
            }
            // a + b
            {
                vector<int64_t> nxt = rest;
                nxt.push_back(a + b);
                if (canReachIntTarget(nxt, target, memo)) return true;
            }
            // a - b
            {
                vector<int64_t> nxt = rest;
                nxt.push_back(a - b);
                if (canReachIntTarget(nxt, target, memo)) return true;
            }
            // b - a
            {
                vector<int64_t> nxt = rest;
                nxt.push_back(b - a);
                if (canReachIntTarget(nxt, target, memo)) return true;
            }
            // a * b
            {
                vector<int64_t> nxt = rest;
                nxt.push_back(a * b);
                if (canReachIntTarget(nxt, target, memo)) return true;
            }
            // divisions (exact only)
            if (b != 0 && (a % b == 0)) {
                vector<int64_t> nxt = rest;
                nxt.push_back(a / b);
                if (canReachIntTarget(nxt, target, memo)) return true;
            }
            if (a != 0 && (b % a == 0)) {
                vector<int64_t> nxt = rest;
                nxt.push_back(b / a);
                if (canReachIntTarget(nxt, target, memo)) return true;
            }
        }
    }
    memo.insert(key);
    return false;
}

static bool canReachRationalTarget(const vector<Frac>& nums_in, int64_t target,
                                   unordered_set<uint64_t>& memo) {
    vector<Frac> nums = nums_in;
    canonical_sort(nums);
    const size_t n = nums.size();
    uint64_t key = hash_frac_vec(nums);
    if (memo.find(key) != memo.end()) return false;
    if (n == 1) {
        return nums[0].p == target * nums[0].q;
    }
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i + 1; j < n; ++j) {
            Frac a = nums[i], b = nums[j];
            vector<Frac> rest;
            rest.reserve(n - 1);
            for (size_t k = 0; k < n; ++k) {
                if (k != i && k != j) rest.push_back(nums[k]);
            }
            // a + b
            {
                vector<Frac> nxt = rest;
                nxt.push_back(add(a, b));
                if (canReachRationalTarget(nxt, target, memo)) return true;
            }
            // a - b
            {
                vector<Frac> nxt = rest;
                nxt.push_back(sub(a, b));
                if (canReachRationalTarget(nxt, target, memo)) return true;
            }
            // b - a
            {
                vector<Frac> nxt = rest;
                nxt.push_back(sub(b, a));
                if (canReachRationalTarget(nxt, target, memo)) return true;
            }
            // a * b
            {
                vector<Frac> nxt = rest;
                nxt.push_back(mul(a, b));
                if (canReachRationalTarget(nxt, target, memo)) return true;
            }
            // a / b
            if (!is_zero(b)) {
                vector<Frac> nxt = rest;
                nxt.push_back(divide(a, b));
                if (canReachRationalTarget(nxt, target, memo)) return true;
            }
            // b / a
            if (!is_zero(a)) {
                vector<Frac> nxt = rest;
                nxt.push_back(divide(b, a));
                if (canReachRationalTarget(nxt, target, memo)) return true;
            }
        }
    }
    memo.insert(key);
    return false;
}

static void dfs_gen(int n, int idx, int last, vector<int>& cur, int64_t m, int32_t& answer) {
    if (idx == n) {
        vector<int64_t> ints;
        ints.reserve(n);
        for (int i = 0; i < n; ++i) ints.push_back(cur[i]);

        unordered_set<uint64_t> memoInt;
        memoInt.reserve(1024);
        if (canReachIntTarget(ints, m, memoInt)) {
            return; // invalid: has an all-integer path to m
        }

        vector<Frac> frs;
        frs.reserve(n);
        for (int i = 0; i < n; ++i) frs.emplace_back((int64_t)cur[i], 1);
        unordered_set<uint64_t> memoRat;
        memoRat.reserve(2048);
        if (canReachRationalTarget(frs, m, memoRat)) {
            ++answer; // valid: can reach m, but integer-only cannot
        }
        return;
    }
    for (int v = last; v <= 13; ++v) {
        cur[idx] = v;
        dfs_gen(n, idx + 1, v, cur, m, answer);
    }
}

output_type cal(input_type data) {
    num_t n{0};
    int64_t m{0};
    tie(n, m) = data;

    // Quick short-circuit filters to avoid expensive enumeration:
    // 1) If n < 3, the condition "every expression has at least one non-integer intermediate"
    //    cannot be satisfied (too few operations), so answer is 0.
    if (n < 3) return 0;
    // 2) If |m| > 13^n, impossible to reach m with numbers in [1,13]. Compute 13^n safely.
    int64_t maxv = 1;
    for (int i = 0; i < n; ++i) maxv *= 13;
    if (m < 0 ? -m : m > maxv) return 0;

    int32_t answer = 0;
    if (n >= 1 && n <= 4) {
        vector<int> cur(n, 1);
        dfs_gen(n, 0, 1, cur, m, answer);
    }

    return answer;
}

void output(const output_type &data) {
    cout << data << end;
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

int main() {
    auto input_data = read();
    auto output_data = cal(input_data);
    output(output_data);
    return 0;
}

inline input_type read() {
    num_t a{0}, b{0};
    std::cin >> a >> b;
    return std::make_tuple(a, b);
}

#ifdef ALGORITHM_TEST_MACRO
}
#endif
