// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <queue>
#include <set>
#include <utility>
#include <vector>
#include <algorithm>

#ifndef ALGORITHM_TEST_MACRO
#pragma GCC optimize(3, "Ofast", "inline", "no-stack-protector", "unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC target("mmx")
#else
namespace lab_04_E {
#endif
using std::cin;
using std::cout;
using std::vector;
using std::set;
static constexpr const char end{'\n'};

using num_t = int32_t;

struct test_case final {
    num_t length{0};
    vector<num_t> values{};

    test_case() = default;

    test_case(num_t l, vector<num_t> &&v) : length(l), values(std::move(v)) {
    }
};

using input_type = vector<test_case>;
using output_type = vector<vector<num_t> >;

inline input_type read();

output_type cal(const input_type &data);

void output(const output_type &data);

vector<num_t> solve_case(const vector<num_t> &numbers);

int main() {
    const auto input_data = read();
    const auto output_data = cal(input_data);
    output(output_data);
    return 0;
}

inline input_type read() {
    num_t total_cases{0};
    cin >> total_cases;
    input_type all_cases{};
    all_cases.reserve(total_cases);
    for (num_t case_idx{0}; case_idx < total_cases; ++case_idx) {
        num_t length{0};
        cin >> length;
        vector<num_t> values(static_cast<vector<num_t>::size_type>(length));
        for (num_t i{0}; i < length; ++i) {
            cin >> values[static_cast<vector<num_t>::size_type>(i)];
        }
        all_cases.push_back(test_case{length, std::move(values)});
    }
    return all_cases;
}

output_type cal(const input_type &data) {
    output_type answers{};
    answers.reserve(data.size());
    for (const auto &item: data) {
        answers.emplace_back(solve_case(item.values));
    }
    return answers;
}

void output(const output_type &data) {
    for (const auto &sequence: data) {
        bool first{true};
        for (const auto value: sequence) {
            if (!first) {
                cout << ' ';
            }
            first = false;
            cout << value;
        }
        cout << end;
    }
}

vector<num_t> solve_case(const vector<num_t> &numbers) {
    const int32_t n = static_cast<int32_t>(numbers.size());
    if (n <= 1) return numbers;

    vector<int32_t> prev(n), next(n);
    for (int32_t i = 0; i < n; ++i) {
        prev[i] = i - 1;
        next[i] = i + 1; // next[n-1] == n 作为右侧哨兵
    }

    vector<uint8_t> removed(n, 0);

    // 初始候选：所有下降数
    vector<int32_t> cur;
    cur.reserve(n);
    for (int32_t i = 0; i < n; ++i) {
        bool has_left = (i - 1) >= 0 && numbers[(size_t) (i - 1)] > numbers[(size_t) i];
        bool has_right = (i + 1) < n && numbers[(size_t) i] > numbers[(size_t) (i + 1)];
        if (has_left || has_right) cur.push_back(i);
    }

    vector<int32_t> nxt;
    nxt.reserve(n);
    vector<uint8_t> in_next(n, 0); // 下一轮去重

    while (!cur.empty()) {
        std::sort(cur.begin(), cur.end());
        cur.erase(std::unique(cur.begin(), cur.end()), cur.end());

        // 标记本轮删除
        for (int32_t idx: cur) removed[idx] = 1;

        nxt.clear();

        // 按连续段 [L..R] 同时桥接
        int32_t k = 0;
        while (k < (int32_t) cur.size()) {
            int32_t L = cur[k];
            int32_t R = L;
            while (k + 1 < (int32_t) cur.size() && cur[k + 1] == R + 1) {
                ++k;
                R = cur[k];
            }
            ++k;

            // 找到段左、右侧仍存活的邻居
            int32_t left = prev[L];
            while (left >= 0 && removed[left]) left = prev[left];

            int32_t right = (R + 1 < n) ? (R + 1) : n;
            // 使用 next[R] 更稳妥，但 R+1 == next[R] 初始等价
            // 若 right 是活的就用 right，否则跳过至右侧活的
            if (right < n) {
                if (removed[right]) {
                    // 跳过右侧本轮被删的连续段
                    while (right < n && removed[right]) right = next[right];
                }
            }

            // 桥接
            if (left >= 0) next[left] = right;
            if (right < n) prev[right] = left;

            // 段左邻居可能因桥接变成下降数
            if (left >= 0 && !removed[left] && !in_next[left]) {
                int32_t ll = prev[left];
                while (ll >= 0 && removed[ll]) ll = prev[ll];
                int32_t rr = next[left];
                while (rr < n && removed[rr]) rr = next[rr];
                if ((ll >= 0 && numbers[(size_t) ll] > numbers[(size_t) left]) ||
                    (rr < n && numbers[(size_t) left] > numbers[(size_t) rr])) {
                    in_next[left] = 1;
                    nxt.push_back(left);
                }
            }

            // 段右邻居可能因桥接变成下降数
            if (right < n && !removed[right] && !in_next[right]) {
                int32_t ll = prev[right];
                while (ll >= 0 && removed[ll]) ll = prev[ll];
                int32_t rr = next[right];
                while (rr < n && removed[rr]) rr = next[rr];
                if ((ll >= 0 && numbers[(size_t) ll] > numbers[(size_t) right]) ||
                    (rr < n && numbers[(size_t) right] > numbers[(size_t) rr])) {
                    in_next[right] = 1;
                    nxt.push_back(right);
                }
            }
        }

        // 清理下一轮去重标记（仅对已加入的元素）
        for (int32_t j: nxt) in_next[j] = 0;

        cur.swap(nxt);
    }

    // 输出存活元素（按原顺序）
    vector<num_t> result;
    result.reserve(n);
    for (int32_t i = 0; i < n; ++i) {
        if (!removed[i]) result.push_back(numbers[(size_t) i]);
    }
    return result;
}

static const auto faster_streams = [] {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
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
