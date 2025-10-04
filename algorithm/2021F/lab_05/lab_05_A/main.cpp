// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds

#include <stack>
#include <queue>
#include <vector>
#include <cstdint>
#include <iostream>
#include <algorithm>

#ifndef ALGORITHM_TEST_MACRO
#pragma GCC optimize(3, "Ofast", "inline", "no-stack-protector", "unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC target("tune=native")
#else
namespace lab_05_A{
#endif

using std::cin;
using std::cout;
using std::stack;
using std::tuple;
using std::queue;
using std::string;
using std::vector;

static constexpr const char end{'\n'}, space{' '};
namespace HASH {
static constexpr const std::hash<string> STD_HASH_STRING{std::hash<string>()};
static const size_t NEW_FOOD{STD_HASH_STRING("NewFood")};
static const size_t NEW_COMER{STD_HASH_STRING("NewComer")};
static const size_t TAKE_FOOD{STD_HASH_STRING("TakeFood")};
}
using num_t = int32_t;
using output_type = std::pair<int32_t, int32_t>;

void output(const output_type &data);

int32_t main() {
    size_t alpha{0};
    std::cin >> alpha;
    std::pair<num_t, num_t> will_return{0, 0};
    stack<size_t> way;
    queue<size_t> comer;
    for (size_t i{0}, op_hashed{0}, de_hashed{0}; i < alpha; ++i) {
        string operation, detail;
        std::cin >> operation;
        op_hashed = HASH::STD_HASH_STRING(operation);
        if (op_hashed == HASH::TAKE_FOOD && !way.empty()) {
            const auto way_top{way.top()}, comer_top{comer.front()};
            comer.pop();
            if (way_top == comer_top) {
                way.pop();
                will_return.second++;
            } else {
                comer.push(comer_top);
            }
        } else {
            std::cin >> detail;
            de_hashed = HASH::STD_HASH_STRING(detail);
            if (op_hashed == HASH::NEW_COMER) {
                comer.push(de_hashed);
                will_return.first++;
            } else if (op_hashed == HASH::NEW_FOOD) {
                way.push(de_hashed);
            }
        }
    }
    size_t comer_size{comer.size()}, continue_time{0};
    while (!way.empty() && !comer.empty()) {
        const auto way_top{way.top()}, comer_top{comer.front()};
        comer.pop();
        if (way_top == comer_top) {
            way.pop();
            will_return.second++;
            comer_size--;
            continue_time = 0;
        } else {
            comer.push(comer_top);
            continue_time++;
        }
        if (continue_time == comer_size) {
            break;
        }
    }
    output(will_return);
    return 0;
}

void output(const output_type &data) {
    static constexpr const char *const SUCCESS = R"(Qi Fei!)";
    const auto diff{data.first - data.second};
    if (diff == 0) {
        std::cout << SUCCESS;
    } else {
        std::cout << diff;
    }
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
