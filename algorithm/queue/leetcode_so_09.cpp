// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#include <stack>
#include <cstdint>

#ifdef CS203_DSAA_TEST_MACRO

namespace leetcode_so_09 {
using std::stack;
#endif

struct CQueue {
    CQueue() = default;

    virtual void appendTail(int32_t value) = 0;

    virtual int deleteHead() = 0;

    virtual ~CQueue() = default;
};

struct StackQueue : CQueue {
private:
    stack<int32_t> sta1, sta2;
public:
    StackQueue() : CQueue() {};

    void appendTail(int32_t value) override {
        sta1.push(value);
    }

    int deleteHead() override {
        while (!sta1.empty()) {
            sta2.push(sta1.top());
            sta1.pop();
        }
        if (sta2.empty()) {
            return -1;
        }
        const auto top = sta2.top();
        sta2.pop();
        while (!sta2.empty()) {
            sta1.push(sta2.top());
            sta2.pop();
        }
        return top;
    }
};

struct StackQueue2 : CQueue {
private:
    stack<int32_t> sta1, sta2;
public:
    StackQueue2() : CQueue() {};

    void appendTail(int32_t value) override {
        sta1.push(value);
    }

    int deleteHead() override {
        if (sta2.empty()) {
            if (sta1.empty()) {
                return -1;
            } else {
                while (!sta1.empty()) {
                    sta2.push(sta1.top());
                    sta1.pop();
                }
            }
        }
        const auto top = sta2.top();
        sta2.pop();
        while (!sta2.empty()) {
            sta1.push(sta2.top());
            sta2.pop();
        }
        return top;
    }
};

class Solution {
public:
    CQueue *pure() {
        return new StackQueue();
    }

    CQueue *effective() {
        return new StackQueue2();
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
