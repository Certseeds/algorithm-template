// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
/*
 *@题目描述
 * 给出两个各有ν(希腊字母Nu),μ(希腊字母Mu)长的多项式Ν(大写希腊字母Nu),Μ(大写希腊字母Mu),请计算两者之和
 *@输入
 * 第一行输入两个int32_t,(0,10^6)
 * 之后ν行输入,分别是Ν的 ${系数},${指数}
 * 之后μ行输入,分别是Μ的 ${系数},${指数}
 * 所有系数指数都在(-10^9,10^9)
 * PS: 输入全为int32_t
 *@输出
 * 第一行int32_t, 输出项数
 * 之后分行输出 ${系数},${指数}
 * */
// DONE

#ifndef CS203_DSAA_TEST_MACRO
#pragma GCC optimize(3, "Ofast", "inline", "no-stack-protector", "unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC target("sse,sse2,mmx")
#endif

#include <map>
#include <vector>
#include <cstdint>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#ifdef CS203_DSAA_TEST_MACRO
namespace lab_04_2A{
#endif

using std::cin;
using std::tie;
using std::map;
using std::cout;
using std::pair;
using std::vector;

static constexpr const char end{'\n'}, space{' '};
using num_t = int32_t;

int main() {
    num_t nu{0}, mu{0};
    num_t coeff{0}, expon{0};
    std::cin >> nu >> mu;
    vector<std::pair<num_t, num_t>> NU{}, MU{};
    NU.reserve(nu), MU.reserve(mu);
    for (num_t i{0}; i < nu; ++i) {
        std::cin >> coeff >> expon;
        NU.emplace_back(expon, coeff);
    }
    for (num_t i{0}; i < mu; ++i) {
        std::cin >> coeff >> expon;
        MU.emplace_back(expon, coeff);
    }
    // 读取结束
    const static auto cmp = [](const std::pair<num_t, num_t> &lhs, const std::pair<num_t, num_t> &rhs) {
        return lhs.first > rhs.first;
    };
    std::sort(NU.begin(), NU.end(), cmp);
    std::sort(MU.begin(), MU.end(), cmp);
    // 排序完成,可归并
    vector<std::pair<num_t, num_t>> result{};
    result.reserve(nu + mu);
    num_t nul{0}, mul{0};
    while (nul < nu && mul < mu) {
        const auto &NUele = NU[nul];
        const auto &MUele = MU[mul];
        if (NUele.first > MUele.first) {
            result.emplace_back(NUele);
            nul++;
        } else if (NUele.first < MUele.first) {
            result.emplace_back(MUele);
            mul++;
        } else {
            result.emplace_back(NUele.first, NUele.second + MUele.second);
            nul++, mul++;
        }
    }
    for (; nul < nu; nul++) {
        result.emplace_back(NU[nul]);
    }
    for (; mul < mu; mul++) {
        result.emplace_back(MU[mul]);
    }
    std::cout << result.size() << end;
    for (const auto &iter: result) {
        if (iter.first != 0) {
            std::cout << iter.second << space << iter.first << end;
        }
    }
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
#ifdef CS203_DSAA_TEST_MACRO
}
#endif
