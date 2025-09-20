// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
/*
 * @题目描述
 * 惧亡者排成一个队列,每个惧亡者都有一个生体转化偏好
 * 星神在一个栈中提供各种生体转化可能性
 * 如果栈顶的生体转化匹配上了惧亡者的生体转化偏好,该惧亡者将被生体转化为 太空死灵, 并从队列中移除
 * 否则,该惧亡者将重新进入队列尾部
 *
 * 每个时隙内,会有不同事件发生
 * 第一种: `NewFold ${NAME_OF_NEW_FOOD}` 生体转化堆中推入新可能性
 * 第二种: `NewComer ${NAME_OF_FAVORITE_FOOD}` 新的惧亡者进入队列
 * 第三种: `TakeFood`  队列首部惧亡者进行选择,若生体转化堆为空,则等待
 * 所有时隙后,星神不再提供新的生体转化可能性
 *
 * 剩余的惧亡者将进行生体转化 直到 生体转化堆 为空 或者没有惧亡者能够进行生体转化
 * 此时星神将会结束生体转化.
 *
 * 输出生体转化结束时多少惧亡者 还没有进行生体转化
 *@输入
 * 第一行数字 α,代表时隙数量 [0,1000]
 * 之后是 α行操作
 *@输出
 * 若全部都进行了,则输出 R"(Qi Fei!)"
 * 否则,输出数字
 *@样例
 *   @输入
 *    6
 *    NewComer SpicyHotPot
 *    NewComer BarbecuedPorkCombo
 *    NewFood BarbecuedPorkCombo
 *    TakeFood
 *    NewFood SpicyHotPot
 *    NewFood BarbecuedPorkCombo
 *   @输出
 *   Qi Fei!
 * */
//@Tag DONE

#ifndef CS203_DSAA_TEST_MACRO
#pragma GCC optimize(3, "Ofast", "inline", "no-stack-protector", "unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC target("mmx")
#endif

#include <stack>
#include <queue>
#include <vector>
#include <cstdint>
#include <iostream>
#include <algorithm>

#ifdef CS203_DSAA_TEST_MACRO
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
#ifdef CS203_DSAA_TEST_MACRO
}
#endif
