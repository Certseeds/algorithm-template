// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
/*
 *@题目描述
 * 假设有一些自行车链条的链粒,每一个链粒都有一个权重
 * 可以通过一系列操作,将两个链粒链接起来
 * 最后,输出每个链条上权重值排第K位的权重
 *@输入
 * 第一行三个int32_t,nu(1,10^6),rho(1,10^6),phi[1,9]
 * 下一行, nu个int32_t 代表 1-nu个 链粒的 权重
 * 接下来的 rho 行, 每行第一个数字代表头链粒,第二个数字代表尾链粒,
 * 象征操作: 将 头链粒的尾节点 指向 尾链粒的头节点
 *@输出
 * 对于每个1-nu的链粒,
 * 1. 如果链粒是头节点
 * 2. 链粒所在链条长于phi
 * 则 输出 第 phi个 节点
 * 输出由空格间隔(疑似最后一个之后没有空格)
 *@样例
 *  @Input:
 *    5 3 2
 *    1 2 3 4 5
 *    1 3
 *    1 4
 *    2 5
 *  @Output:
 *    3 5
 *  分析:
 *  第一行,一共五个链粒,三次链接操作,输出第二个权重
 *  第二行,分别为1,2,3,4,5
 *  第三行,将1,3链接起来,此时`1->3,2,4,5`
 *  第四行,将1,4链接起来,此时`1->3->4,2,5`
 *  第五行,将2,5链接起来,此时`1->3->4,2->5`
 *  结束
 *  此时按第一个条件,过滤掉`3,4,5`
 *  按第二个条件,不过滤元素`
 *  输出`3 5`
 * */
//@Tag DONE
#ifdef CS203_DSAA_TEST_MACRO

#include <list/listnode.hpp>

#else

#include <cstdint>
#include <cstddef>

namespace LISTNODE {
struct ListNode {
    int32_t val;
    ListNode *next;

    ListNode(int32_t v, ListNode *n) : val(v), next(n) {}

    explicit ListNode(int32_t x) : ListNode(x, nullptr) {}
};
}
#pragma GCC optimize(3, "Ofast", "inline", "no-stack-protector", "unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC target("mmx")
#endif //CS203_DSAA_TEST_MACRO

#include <tuple>
#include <vector>
#include <cstdint>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#ifdef CS203_DSAA_TEST_MACRO
namespace lab_04_C{
#endif

using std::cin;
using std::cout;
using std::tuple;
using std::string;
using std::vector;
using std::unordered_map;
using LISTNODE::ListNode;

static constexpr const char end{'\n'}, space{' '};

using num_t = int32_t;
using input_type = std::tuple<vector<ListNode *>, vector<std::pair<num_t, num_t>>>;
using output_type = vector<num_t>;

inline input_type read();

output_type cal(const input_type &data);

static num_t phi{0};

void output(const output_type &data);

void destoryResource(const input_type &data);

int32_t main() {
    const auto input_data = read();
    const auto output_data = cal(input_data);
    output(output_data);
    destoryResource(input_data);
    return 0;
}

inline input_type read() {
    num_t nu{0}, rho{0};
    std::cin >> nu >> rho >> phi;
    vector<ListNode *> nodes(nu, nullptr);
    for (num_t i{0}; i < nu; i++) {
        nodes[i] = new ListNode(0);
    }
    for (auto &node: nodes) {
        std::cin >> node->val;
    }
    vector<std::pair<num_t, num_t>> operas(rho);
    for (auto &opera: operas) {
        std::cin >> opera.first >> opera.second;
    }
    return std::make_tuple(nodes, operas);
}

output_type cal_v1(const input_type &data) {
    vector<ListNode *> nodes{};
    vector<std::pair<num_t, num_t>> operas{};
    vector<num_t> will_return{};
    std::tie(nodes, operas) = data;
    will_return.reserve(nodes.size());
    vector<ListNode *> to_tail(nodes);
    for (auto &&opera: operas) {
        const auto fir{opera.first - 1}, rih{opera.second - 1};
        ListNode *const rih_head = nodes[rih];
        ListNode *const rih_tail = to_tail[rih];
        ListNode *const fir_tail = to_tail[fir];
        fir_tail->next = rih_head;
        to_tail[rih] = nullptr;
        to_tail[fir] = rih_tail;
    }
    for (size_t i{0}; i < nodes.size(); i++) {
        if (to_tail[i] != nullptr) {
            const ListNode *head = nodes[i];
            for (num_t count{1}; head != nullptr && count < phi; ++count) {
                head = head->next;
            }
            if (head != nullptr) {
                will_return.emplace_back(head->val);
            }
        }
    }
    return will_return;
}

output_type cal(const input_type &data) {
    return cal_v1(data);
}

void output(const output_type &data) {
    if (data.empty()) {
        return;
    }
    for (auto iter = data.cbegin(); iter != data.cend() - 1; ++iter) {
        std::cout << (*iter) << space;
    }
    std::cout << *(data.cend() - 1);
}

void destoryResource(const input_type &data) {
    vector<ListNode *> nodes{};
    vector<std::pair<num_t, num_t>> operas{};
    vector<num_t> will_return{};
    std::tie(nodes, operas) = data;
    for (const auto &node: nodes) {
        delete node;
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
