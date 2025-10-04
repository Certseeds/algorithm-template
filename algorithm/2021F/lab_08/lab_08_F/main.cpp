// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <tuple>
#include <vector>
#include <iostream>
#include <cstdint>
#include <utility>


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

class Treap {
private:
    struct Node {
        i64 key;
        uint32_t priority;
        int left;
        int right;
    };

    std::vector<Node> nodes;
    int root = -1;
    uint32_t seed = 712367521u;

    inline uint32_t next_random() {
        seed ^= seed << 13;
        seed ^= seed >> 17;
        seed ^= seed << 5;
        return seed;
    }

    int new_node(const i64 key) {
        nodes.push_back(Node{key, next_random(), -1, -1});
        return static_cast<int>(nodes.size()) - 1;
    }

    void split(const int current, const i64 key, int &left, int &right) {
        if (current == -1) {
            left = right = -1;
            return;
        }
        if (nodes[current].key <= key) {
            left = current;
            split(nodes[current].right, key, nodes[current].right, right);
        } else {
            right = current;
            split(nodes[current].left, key, left, nodes[current].left);
        }
    }

    int merge(const int left, const int right) {
        if (left == -1) return right;
        if (right == -1) return left;
        if (nodes[left].priority < nodes[right].priority) {
            nodes[left].right = merge(nodes[left].right, right);
            return left;
        }
        nodes[right].left = merge(left, nodes[right].left);
        return right;
    }

    int erase_node(const int current, const i64 key) {
        if (current == -1) return -1;
        if (nodes[current].key == key) {
            return merge(nodes[current].left, nodes[current].right);
        }
        if (key < nodes[current].key) {
            nodes[current].left = erase_node(nodes[current].left, key);
        } else {
            nodes[current].right = erase_node(nodes[current].right, key);
        }
        return current;
    }

public:
    void insert(const i64 key) {
        int left = -1;
        int right = -1;
        split(root, key, left, right);
        const int node = new_node(key);
        root = merge(merge(left, node), right);
    }

    void erase(const i64 key) {
        root = erase_node(root, key);
    }

    bool empty() const {
        return root == -1;
    }

    bool find_floor(const i64 key, i64 &result) const {
        int current = root;
        bool found = false;
        while (current != -1) {
            const i64 cur_key = nodes[static_cast<size_t>(current)].key;
            if (cur_key == key) {
                result = cur_key;
                return true;
            }
            if (cur_key < key) {
                result = cur_key;
                found = true;
                current = nodes[static_cast<size_t>(current)].right;
            } else {
                current = nodes[static_cast<size_t>(current)].left;
            }
        }
        return found;
    }

    bool find_ceiling(const i64 key, i64 &result) const {
        int current = root;
        bool found = false;
        while (current != -1) {
            const i64 cur_key = nodes[static_cast<size_t>(current)].key;
            if (cur_key == key) {
                result = cur_key;
                return true;
            }
            if (cur_key > key) {
                result = cur_key;
                found = true;
                current = nodes[static_cast<size_t>(current)].left;
            } else {
                current = nodes[static_cast<size_t>(current)].right;
            }
        }
        return found;
    }
};

struct MatchResult {
    bool matched;
    i64 partner_value;
    i64 gain;
};

MatchResult try_match(Treap &waiting, const i64 value) {
    if (waiting.empty()) return MatchResult{false, 0, 0};

    i64 floor_value = 0;
    i64 ceil_value = 0;
    const bool has_floor = waiting.find_floor(value, floor_value);
    const bool has_ceil = waiting.find_ceiling(value, ceil_value);

    if (!has_floor && !has_ceil) return MatchResult{false, 0, 0};

    i64 chosen = 0;
    if (has_floor && has_ceil) {
        const i64 diff_floor = std::abs(value - floor_value);
        const i64 diff_ceil = std::abs(value - ceil_value);
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

    waiting.erase(chosen);
    const i64 gain = std::llabs(value - chosen);
    return MatchResult{true, chosen, gain};
}

ProblemOutput solve(const ProblemInput &in) {
    Treap waiting_girls;
    Treap waiting_bunnies;
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
