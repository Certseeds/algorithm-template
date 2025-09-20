// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag stack
//@Tag 栈
//@Tag 单调栈

#ifdef CS203_DSAA_TEST_MACRO

#include <stack>
#include <cstdint>

namespace leetcode_232 {
using std::stack;
#endif

class MyQueue {
public:
    MyQueue() = default;

    virtual void push(int x) = 0;

    virtual int pop() = 0;

    virtual int peek() = 0;

    virtual bool empty() const = 0;

    virtual ~MyQueue() = default;
};

class Solution {
private:
    class Queue : public MyQueue {
    private:
        stack<int32_t> sta1{}, sta2{};
    public:
        Queue() = default;

        void push(int x) override {
            sta1.push(x);
        }

        int pop() override {
            const auto head = this->peek();
            sta2.pop();
            return head;
        }

        int peek() override {
            if (sta2.empty()) {
                while (!sta1.empty()) {
                    sta2.push(sta1.top());
                    sta1.pop();
                }
            }
            return sta2.top();
        }

        bool empty() const override { return sta1.empty() && sta2.empty(); }
    };

public:
    MyQueue *pure() {
        return new Queue();
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
