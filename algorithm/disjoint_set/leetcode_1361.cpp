// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO

#include "disjoint_set.hpp"
#include "disjoint_set.cpp"
#include <queue>
#include <cstdint>
#include <vector>

namespace leetcode_1361 {
using ::disjoint_set::disjoint_set;
using ::disjoint_set::getDisjointSet;
using std::vector;
#endif

// 二叉树上x个节点应该有x-1条边
bool simpleCheck(int32_t n, const vector<int32_t> &leftChild, const vector<int32_t> &rightChild) {
    int32_t count{0};
    for (int32_t i{0}; i < n; i++) {
        count += (leftChild[i] != -1) + (rightChild[i] != -1);
    }
    return (n == count + 1);
}

class Solution {
public:
    bool
    validateBinaryTreeNodes(int32_t n, const vector<int32_t> &leftChild, const vector<int32_t> &rightChild) {
        if (!simpleCheck(n, leftChild, rightChild)) {
            return false;
        }
        vector<int32_t> in_position(n, -1);
        for (int32_t i{0}; i < n; i++) {
            if (leftChild[i] != -1) {
                if (in_position[leftChild[i]] == -1) {
                    in_position[leftChild[i]] = i;
                } else {
                    return false;
                }
            }
            if (rightChild[i] != -1) {
                if (in_position[rightChild[i]] != -1) {
                    return false;
                }
                in_position[rightChild[i]] = i;
            }
        } // 父节点不能有多个
        // O(n)
        int32_t count{-1};
        for (int32_t i{0}; i < n; i++) {
            if (in_position[i] == -1) {
                if (count != -1) {// 循环节点不会被扫描到, 因为它们有子节点也有父节点
                    return false;
                }
                count = i;
            }
        }// 只能有一个根节点
        // count must be root
        // O(n)
        int32_t visit_nums{0};
        for (std::queue<int32_t> que{{count}}; !que.empty();) {
            const auto head = que.front();
            que.pop();
            visit_nums += 1;
            if (leftChild[head] != -1) {
                que.push(leftChild[head]);
            }
            if (rightChild[head] != -1) {
                que.push(rightChild[head]);
            }
        }
        // O(n)
        //根节点遍历必须得能遍历到所有节点
        if (visit_nums != n) {
            return false;
        }
        return true;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
