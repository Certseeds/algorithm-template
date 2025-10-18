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
namespace lab_03_D{
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

using num_t = int64_t;
using input_type = std::vector<num_t>;
using output_type = std::vector<num_t>;

inline input_type read();

output_type cal(const input_type &data);

void output(const output_type &data);

int main() {
    auto input_data = read();
    auto output_data = cal(input_data);
    output(output_data);
    return 0;
}

inline input_type read() {
    int32_t n;
    if (!(std::cin >> n)) return {};
    input_type a;
    a.reserve(n);
    for (int32_t i = 0; i < n; ++i) {
        num_t v;
        std::cin >> v;
        a.push_back(v);
    }
    return a;
}

output_type cal(const input_type &data) {
    const int n = static_cast<int>(data.size());
    if (n == 0) return {};
    // copy and sort
    auto s = data;
    std::sort(s.begin(), s.end());
    output_type b(n);
    const int half = n / 2;
    // Interleave: small, large, small2, large2, ...
    for (int i = 0; i < half; ++i) {
        b[2 * i] = s[i];
        b[2 * i + 1] = s[i + half];
    }
    return b;
}

void output(const output_type &data) {
    const int n = static_cast<int>(data.size());
    for (int i = 0; i < n; ++i) {
        if (i) std::cout << ' ';
        std::cout << data[i];
    }
    std::cout << end;
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
