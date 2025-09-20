// SPDX-License-Identifier: AGPL-3.0-or-later
/*  algorithm_template
    Copyright (C) 2020-2023  nanoseeds
*/
#include <cstdint>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>

inline void s1_to_s2(std::stack<int32_t> &s1, std::stack<int32_t> &s2) {
    while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
    }
}

int32_t main() {
    int32_t n{0};
    std::cin >> n;
    std::stack<int32_t> stack1, stack2;
    for (int i = 0; i < n; ++i) {
        std::string str;
        std::cin >> str;
        if ("add" == str) {
            int number;
            std::cin >> number;
            stack1.push(number);
            s1_to_s2(stack2, stack1);
            s1_to_s2(stack1, stack2);
        } else if ("poll" == str) {
            s1_to_s2(stack2, stack1);
            stack1.pop();
            s1_to_s2(stack1, stack2);
        } else if ("peek" == str) {
            s1_to_s2(stack2, stack1);
            std::cout << stack1.top() << std::endl;
            s1_to_s2(stack1, stack2);
        }
    }
    return 0;
}
