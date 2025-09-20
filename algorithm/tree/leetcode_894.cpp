// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds



#ifdef ALGORITHM_TEST_MACRO
#include <cstdint>
#include <cstddef>
#include <vector>
#include <unordered_map>
namespace leetcode_894 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
#endif


using std::unordered_map;
using std::vector;

class Solution {
private:
    vector<TreeNode *> rec(int32_t n, const unordered_map<int32_t, vector<TreeNode *>> &nodes) {
        vector<TreeNode *> will_return{};
        for (int32_t i{1}; i <= n - 2; i += 2) {
            vector<TreeNode *> left = nodes.at(i);
            vector<TreeNode *> right = nodes.at(n - i - 1);
            for (auto j: left) {
                for (auto k: right) {
                    auto *const root = new TreeNode{0};
                    root->left = j;
                    root->right = k;
                    will_return.push_back(root);
                }
            }
        }
        return will_return;
    }

public:
    vector<TreeNode *> allPossibleFBT(int32_t n) {
        if (n % 2 == 0) {
            return {};
        }
        unordered_map<int32_t, vector<TreeNode *>> nodes{{1, {new TreeNode{0}}}};
        vector<TreeNode *> will_return{};
        for (int32_t i{3}; i <= n; i += 2) {
            nodes[i] = rec(i, nodes);
        }
        return nodes.at(n);
    }
};
#ifdef ALGORITHM_TEST_MACRO
}
#endif
