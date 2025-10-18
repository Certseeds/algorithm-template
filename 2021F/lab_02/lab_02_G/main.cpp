// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
// Problem G: max median of any subarray with length >= k

#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

#ifdef ALGORITHM_TEST_MACRO
namespace lab_02_G {
#endif

using std::cin;
using std::cout;
using std::vector;
using std::int32_t;
using std::int64_t;
static constexpr const char end{'\n'};

struct Input {
    int32_t n;
    int32_t k;
    vector<int32_t> a;
};

static Input read_input() {
    Input in;
    cin >> in.n >> in.k;
    in.a.assign(in.n, 0);
    for (int32_t i = 0; i < in.n; ++i) cin >> in.a[i];
    return in;
}

// check if there exists subarray length >= k with median >= x
static bool check_median_at_least(const vector<int32_t> &a, int32_t k, int32_t x) {
    const int n = static_cast<int>(a.size());
    // prefix sums of transformed values: +1 if a[i]>=x, else -1
    vector<int32_t> pref(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i-1] + (a[i-1] >= x ? 1 : -1);
    }
    int32_t min_pref = 0; // minimal prefix up to index i-k
    for (int i = k; i <= n; ++i) {
        // update min_pref with prefix at i-k
        min_pref = std::min(min_pref, pref[i - k]);
        if (pref[i] - min_pref > 0) return true;
    }
    return false;
}

static int32_t solve(const Input &in) {
    int32_t lo = 0;
    int32_t hi = 1000000000; // per constraints
    while (lo < hi) {
        int32_t mid = lo + ((hi - lo + 1) >> 1);
        if (check_median_at_least(in.a, in.k, mid)) lo = mid;
        else hi = mid - 1;
    }
    return lo;
}

static void write_output(int32_t ans) {
    cout << ans << end;
}

int main() {
    auto in = read_input();
    auto ans = solve(in);
    write_output(ans);
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
