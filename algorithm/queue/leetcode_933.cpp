// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#include <queue>

#ifdef CS203_DSAA_TEST_MACRO

namespace leetcode_933 {
using std::queue;
#endif

class RecentCounter {
protected:
    RecentCounter() = default;

public:
    virtual int ping(int t) = 0;

    virtual ~RecentCounter() = default;
};

class RecentCounterNormal : public RecentCounter {
private:
    std::queue<int> que;
public:
    RecentCounterNormal() = default;

    int ping(int t) override {
        que.push(t);
        while (que.front() < t - 3000) {
            que.pop();
        }
        return que.size();
    }
};

class Solution {
public:
    RecentCounter *pure() {
        return new RecentCounterNormal();
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
