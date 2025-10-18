// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <list>
#include <array>
#include <deque>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <vector>
#include <cstdint>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

#ifdef ALGORITHM_TEST_MACRO
namespace lab_03_G{
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
using i64 = int64_t;

struct Input {
    int32_t n;
    i64 x1;
    i64 x2;
    vector<std::pair<i64, i64> > lines; // (k, b)
};

using input_type = Input;
using output_type = string;

inline input_type read();

output_type cal(input_type data);

void output(const output_type &data);

int main() {
    auto input_data = read();
    auto output_data = cal(input_data);
    output(output_data);
    return 0;
}

inline input_type read() {
    Input in;
    int32_t n;
    i64 x1, x2;
    cin >> n >> x1 >> x2;
    in.n = n;
    in.x1 = x1;
    in.x2 = x2;
    in.lines.reserve(static_cast<size_t>(n));
    for (int i = 0; i < n; ++i) {
        i64 k, b;
        cin >> k >> b;
        in.lines.emplace_back(k, b);
    }
    return in;
}

output_type cal(input_type data) {
    const int n = data.n;
    const i64 x1 = data.x1;
    const i64 x2 = data.x2;
    // compute values at x1 and x2
    vector<std::pair<i64, i64> > ys;
    ys.reserve(static_cast<size_t>(n));
    for (int i = 0; i < n; ++i) {
        const i64 k = data.lines[i].first;
        const i64 b = data.lines[i].second;
        const i64 y1 = k * x1 + b;
        const i64 y2 = k * x2 + b;
        ys.emplace_back(y1, y2);
    }

    // order indices by (y1, y2) to ensure ties at x1 are resolved by x2
    vector<int> ord(n);
    for (int i = 0; i < n; ++i) ord[i] = i;
    sort(ord.begin(), ord.end(), [&](int a, int b) {
        if (ys[a].first != ys[b].first) return ys[a].first < ys[b].first;
        return ys[a].second < ys[b].second;
    });

    // check for inversion in y2 sequence
    for (int i = 0; i + 1 < n; ++i) {
        const i64 y2_cur = ys[ord[i]].second;
        const i64 y2_nxt = ys[ord[i + 1]].second;
        if (y2_cur > y2_nxt) return string("YES");
    }
    return string("NO");
}

void output(const output_type &data) {
    cout << data << end;
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
