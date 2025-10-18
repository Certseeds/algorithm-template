// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
// Problem F: find M-th smallest element in A where
// A[i][j] = i^2 + 12345*i + j^2 -12345*j + i*j
// Approach: binary search on value X, count number of pairs (i,j) with A[i][j] <= X

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>
#include <limits>

#ifdef ALGORITHM_TEST_MACRO
namespace lab_02_F {
#endif

using std::cin;
using std::cout;
using std::vector;
using std::int64_t;
using std::int32_t;
static constexpr const char end{'\n'};

// count number of pairs (i,j) with 1<=i,j<=N and A[i][j] <= X
static inline int64_t count_leq(int N, int64_t X) {
    int64_t cnt = 0;
    for (int i = 1; i <= N; ++i) {
        int64_t B = int64_t(i) - int64_t(12345);
        int64_t C = int64_t(i) * int64_t(i) + int64_t(12345) * int64_t(i) - X;
        long double D = (long double) B * (long double) B - 4.0L * (long double) C;
        if (D < 0) continue;
        long double sd = std::sqrt(D);
        long double r1 = (-(long double) B - sd) / 2.0L;
        long double r2 = (-(long double) B + sd) / 2.0L;
        auto L = (int64_t) std::ceil(r1 - 1e-12L);
        auto R = (int64_t) std::floor(r2 + 1e-12L);
        if (R < 1 || L > N) continue;
        if (L < 1) L = 1;
        if (R > N) R = N;
        if (R >= L) cnt += (R - L + 1);
        if (cnt > (int64_t(1) << 62)) return cnt;
    }
    return cnt;
}

// ---- Input / Process / Output style ----
using input_type = vector<std::pair<int, int64_t> >; // (N, M)
using output_type = vector<int64_t>;

static input_type read_input() {
    int T;
    if (!(cin >> T)) return {};
    input_type in;
    in.reserve(T);
    for (int i = 0; i < T; ++i) {
        int N;
        int64_t M;
        cin >> N >> M;
        in.emplace_back(N, M);
    }
    return in;
}

static output_type process(const input_type &in) {
    output_type ans;
    ans.reserve(in.size());
    for (auto &pr: in) {
        int N = pr.first;
        int64_t M = pr.second;
        int64_t lo = std::numeric_limits<int64_t>::min() / 4;
        int64_t hi = std::numeric_limits<int64_t>::max() / 4;
        while (lo < hi) {
            int64_t mid = lo + ((hi - lo) >> 1);
            int64_t cnt = count_leq(N, mid);
            if (cnt >= M) hi = mid;
            else lo = mid + 1;
        }
        ans.push_back(lo);
    }
    return ans;
}

static void write_output(const output_type &out) {
    for (auto v: out) { cout << v << end; }
}

int main() {
    auto input = read_input();
    auto output = process(input);
    write_output(output);
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
