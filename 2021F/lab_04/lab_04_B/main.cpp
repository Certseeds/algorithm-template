// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds


//@Tag Done


#ifdef ALGORITHM_TEST_MACRO

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
#endif //ALGORITHM_TEST_MACRO

#include <vector>
#include <cstdint>
#include <numeric>
#include <iostream>
#include <algorithm>

#ifdef ALGORITHM_TEST_MACRO
namespace lab_04_B{
#endif

using std::cin;
using std::cout;
using std::tuple;
using std::string;
using std::vector;
static constexpr const char end{'\n'}, space{' '};

using num_t = int32_t;
using input_type = std::pair<num_t, num_t>;
using output_type = vector<num_t>;

inline input_type read();

output_type cal(const input_type &data);

void output(const output_type &data);

int32_t main() {
    const auto input_data = read();
    const auto output_data = cal(input_data);
    output(output_data);
    return 0;
}

inline input_type read() {
    std::pair<num_t, num_t> will_return;
    std::cin >> will_return.first >> will_return.second;
    return will_return;
}

output_type cal(const input_type &data) {
    const num_t nu{data.first}, mu{data.second};
    vector<num_t> will_return{};
    if (mu == 1) {
        will_return.resize(nu);
        std::iota(std::begin(will_return), std::end(will_return), 1);
        return will_return;
    }
    LISTNODE::ListNode stable{0};
    auto *stable_ptr = &stable;
    for (num_t i{1}; i <= nu; i++) {
        stable_ptr->next = new LISTNODE::ListNode(i);
        stable_ptr = stable_ptr->next;
    }
    while (stable.next != nullptr) {
        auto *pre = &stable;
        auto *now = pre->next;
        for (num_t count{mu}; pre->next != nullptr; count++) {
            if (count == mu) {
                will_return.push_back(now->val);
                pre->next = now->next;
                delete now;
                now = nullptr;
                count = 0;
            } else {
                pre = pre->next;
                now = pre->next;
            }
        }
    }
    return will_return;
}

void output(const output_type &data) {
    for (const auto &ele: data) {
        std::cout << ele << space;
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
