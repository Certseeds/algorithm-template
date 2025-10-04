// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <tuple>
#include <vector>
#include <iostream>
#include <cstdint>
#include <utility>
#include <queue>
#include <set>

#ifndef ALGORITHM_TEST_MACRO
#pragma GCC optimize(3, "Ofast", "inline", "no-stack-protector", "unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC target("tune=native")
#else
namespace lab_08_F {
#endif
using std::cin;
using std::cout;
using std::tuple;
using std::vector;
static constexpr const char end{'\n'};

using i32 = int32_t;
using i64 = int64_t;

struct Event {
    i32 type;
    i64 value;
};

struct ProblemInput {
    i32 m;
    std::vector<Event> events;
};

using ProblemOutput = i64;

ProblemInput read_input();

ProblemOutput solve(const ProblemInput &in);

void write_output(const ProblemOutput &out);

int main() {
    const auto in = read_input();
    const auto out = solve(in);
    write_output(out);
    return 0;
}

ProblemInput read_input() {
    ProblemInput in;
    std::cin >> in.m;
    in.events.resize(static_cast<size_t>(in.m));
    for (i32 i = 0; i < in.m; ++i) {
        auto &ev = in.events[static_cast<size_t>(i)];
        std::cin >> ev.type >> ev.value;
    }
    return in;
}

// Replace Treap with std::multiset for ordered waiting sets
// multiset supports insert, erase(one element), lower_bound for ceiling
// and predecessor can be found by stepping iterator backward when needed.
using WaitingSet = std::multiset<i64>;

struct MatchResult {
    bool matched;
    i64 partner_value;
    i64 gain;
};

MatchResult try_match(WaitingSet &waiting, const i64 value) {
    if (waiting.empty()) return MatchResult{false, 0, 0};

    // ceiling: first element >= value
    auto it = waiting.lower_bound(value);
    bool has_ceil = it != waiting.end();
    bool has_floor = false;
    i64 ceil_value = 0;
    i64 floor_value = 0;
    if (has_ceil) {
        ceil_value = *it;
    }
    if (it != waiting.begin()) {
        auto itf = it;
        if (itf == waiting.end() || *itf >= value) --itf;
        floor_value = *itf;
        has_floor = true;
    }

    if (!has_floor && !has_ceil) return MatchResult{false, 0, 0};

    i64 chosen = 0;
    if (has_floor && has_ceil) {
        const i64 diff_floor = std::llabs(value - floor_value);
        const i64 diff_ceil = std::llabs(value - ceil_value);
        if (diff_floor < diff_ceil) {
            chosen = floor_value;
        } else if (diff_floor > diff_ceil) {
            chosen = ceil_value;
        } else {
            chosen = std::min(floor_value, ceil_value);
        }
    } else if (has_floor) {
        chosen = floor_value;
    } else {
        chosen = ceil_value;
    }

    // erase one instance of chosen
    auto eit = waiting.find(chosen);
    if (eit != waiting.end()) waiting.erase(eit);
    const i64 gain = std::llabs(value - chosen);
    return MatchResult{true, chosen, gain};
}

ProblemOutput solve(const ProblemInput &in) {
    WaitingSet waiting_girls;
    WaitingSet waiting_bunnies;
    i64 total_gain = 0;

    for (const auto &ev: in.events) {
        if (ev.type == 1) {
            const auto result = try_match(waiting_bunnies, ev.value);
            if (result.matched) {
                total_gain += result.gain;
            } else {
                waiting_girls.insert(ev.value);
            }
        } else {
            const auto result = try_match(waiting_girls, ev.value);
            if (result.matched) {
                total_gain += result.gain;
            } else {
                waiting_bunnies.insert(ev.value);
            }
        }
    }

    return total_gain;
}

void write_output(const ProblemOutput &out) {
    std::cout << out << end;
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
