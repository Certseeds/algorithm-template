// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <tuple>
#include <vector>
#include <iostream>
#include <deque>
#include <cstdint>

#ifndef ALGORITHM_TEST_MACRO
#pragma GCC optimize(3, "Ofast", "inline", "no-stack-protector", "unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC target("mmx")
#else
namespace lab_05_F{
#endif
using std::tie;
using std::cin;
using std::cout;
using std::tuple;
using std::vector;
static constexpr const char end{'\n'};

using num_t = int32_t; // 数值和长度均在int32范围内
using input_type = tuple<num_t, num_t, std::vector<num_t>>; // k, n, sequence
using output_type = num_t; // 最长长度

inline input_type read();
output_type cal(const input_type &data);
void output(const output_type &data);

int main() {
    const auto input_data = read();
    const auto output_data = cal(input_data);
    output(output_data);
    return 0;
}

inline input_type read() {
    // 输入: k n 然后 n 个数
    num_t k{0}, n{0};
    cin >> k >> n;
    std::vector<num_t> arr;
    arr.resize(static_cast<size_t>(n));
    for (num_t i = 0; i < n; ++i) {
        cin >> arr[static_cast<size_t>(i)];
    }
    return std::make_tuple(k, n, std::move(arr));
}

output_type cal(const input_type &data) {
    // 计算满足 max - min <= k 的最长连续子数组长度
    const num_t k = std::get<0>(data);
    const num_t n = std::get<1>(data);
    const auto &a = std::get<2>(data);
    if (n == 0) { return 0; }

    std::deque<num_t> q_max; // 存储下标, 保持对应值严格递减
    std::deque<num_t> q_min; // 存储下标, 保持对应值严格递增

    num_t best = 1; // 至少为1
    num_t left = 0; // 当前窗口左端
    for (num_t right = 0; right < n; ++right) {
        const auto val = a[static_cast<size_t>(right)];
        // 维护最大值队列: 去掉 <= 当前值的尾部元素
        while (!q_max.empty() && a[static_cast<size_t>(q_max.back())] <= val) {
            q_max.pop_back();
        }
        q_max.push_back(right);
        // 维护最小值队列: 去掉 >= 当前值的尾部元素
        while (!q_min.empty() && a[static_cast<size_t>(q_min.back())] >= val) {
            q_min.pop_back();
        }
        q_min.push_back(right);

        // 若当前窗口不满足条件, 缩小左端
        while (!q_max.empty() && !q_min.empty() && (static_cast<int64_t>(a[static_cast<size_t>(q_max.front())]) - static_cast<int64_t>(a[static_cast<size_t>(q_min.front())]) > k)) {
            // 向右移动左端
            ++left;
            // 弹出已经不在窗口内的下标
            if (!q_max.empty() && q_max.front() < left) { q_max.pop_front(); }
            if (!q_min.empty() && q_min.front() < left) { q_min.pop_front(); }
        }
        // 更新答案 (窗口为 [left, right])
        const num_t cur_len = right - left + 1;
        if (cur_len > best) { best = cur_len; }
    }
    return best;
}

void output(const output_type &data) { cout << data << end; }

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
