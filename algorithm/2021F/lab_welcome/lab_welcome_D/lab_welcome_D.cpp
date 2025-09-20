// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
#include <list>
#include <array>
#include <deque>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <limits>
#include <vector>
#include <cstdint>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <memory>

#ifdef CS203_DSAA_TEST_MACRO
namespace lab_welcome_D{
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
/*
 * 题目描述
Given two arrays A and B with the same length n−1. We want to insert two integers into An and Bn (1≤An≤h,1≤Bn≤h)
such that (i) the sum of array A without its largest value and smallest value is larger than the sum of array B without its largest value and smallest value;
and (ii) An−Bn is minimized.

输入
The 1st line contains two integers: n,h (2≤n≤105,1≤h≤109)

The 2nd line contains n−1 integers: A1,A2,...,An−1,all element in A is between [1,h]

The 3rd line contains n−1 integers, B1,B2,...,Bn−1,all element in B is between [1,h]

输出
Print the minimum value of An−Bn if you can find a proper (An,Bn) pair, otherwise print “IMPOSSIBLE”.
 * */
//TODO
using num_t = int32_t;
using input_type = tuple<vector<num_t>, vector<num_t>, num_t>;

struct output_type {
    bool OK{true};
    num_t number{-1};

    explicit output_type(bool ok) : OK(ok) {}

    output_type(bool ok, num_t number) : OK(ok), number(number) {}
};

struct arrayInfo {
    int64_t sum{static_cast<int64_t>(0)};
    num_t maxV{std::numeric_limits<num_t>::min()};
    num_t minV{std::numeric_limits<num_t>::max()};
};

static inline input_type read();

static output_type cal(const input_type &data);

static void output(const output_type &data);

static arrayInfo analysis(const vector<num_t> &vec);

bool check(const arrayInfo &aInfo, const arrayInfo &bInfo, num_t distance, num_t maxValue);

int main() {
    auto input_data = read();
    auto output_data = cal(input_data);
    output(output_data);
    return 0;
}

inline input_type read() {
    num_t n{0}, h{0};
    std::cin >> n >> h;
    vector<num_t> A(n - 1, 0);
    vector<num_t> B(n - 1, 0);
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> A[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> B[i];
    }
    return std::make_tuple(A, B, h);
}

static output_type cal(const input_type &data) {
    vector<num_t> A{}, B{};
    num_t h{};
    tie(A, B, h) = data;
    const auto aInfo = analysis(A);
    const auto bInfo = analysis(B);
    if (aInfo.sum - aInfo.minV < bInfo.sum - bInfo.maxV) {
        //cout << "case 1" << end;
        // A中补充了一个最大值,B中补充了一个最小值还是不行
        return output_type{false};
    } else if (aInfo.sum - aInfo.maxV > bInfo.sum - bInfo.minV) {
        //cout << "case 2" << end;
        // A中补充一个最小值,B中补充一个最大值,仍然可以
        // 则An为0,Bn为h
        return output_type{true, -h};
    }
    // 此处A
    // 二分logn * On check
    num_t left{aInfo.minV - bInfo.maxV}, right{aInfo.maxV - bInfo.minV + 1}, middle{0};
    while (left < right) {
        middle = (right - left) / 2 + left;
        bool OK = check(aInfo, bInfo, middle, h);
        if (OK) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }
    return output_type{true, left};
}


arrayInfo analysis(const vector<num_t> &vec) {
    arrayInfo will_return{};
    for (const auto &num: vec) {
        will_return.sum += num;
        will_return.maxV = std::max(will_return.maxV, num);
        will_return.minV = std::min(will_return.minV, num);
    }
    return will_return;
}

void output(const output_type &data) {
    const static string impossible = R"(IMPOSSIBLE)";
    if (data.OK) {
        std::cout << data.number << std::endl;
    } else {
        std::cout << impossible << std::endl;
    }
}

bool check(const arrayInfo &aInfo, const arrayInfo &bInfo, num_t distance, num_t maxValue) {
    const int64_t constdiff = aInfo.sum - aInfo.minV - aInfo.maxV - bInfo.sum + bInfo.maxV + bInfo.minV;
    for (int i = std::max(0, distance); i < std::min(maxValue + distance, maxValue); ++i) {
        int64_t diff = constdiff;
        if (i < aInfo.minV) {
            diff += aInfo.minV;
        } else if (aInfo.minV <= i && i < aInfo.maxV) {
            diff += i;
        } else {
            diff += aInfo.maxV;
        }
        const auto bI = i - distance;
        if (bI < bInfo.minV) {
            diff -= bInfo.minV;
        } else if (bInfo.minV <= bI && bI < bInfo.maxV) {
            diff -= bI;
        } else {
            diff -= bInfo.maxV;
        }
        if (diff > 0) {
            return true;
        }
    }
    return false;
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
