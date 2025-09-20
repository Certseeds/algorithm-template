// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022 nanoseeds

*/


#ifdef CS203_DSAA_TEST_MACRO
#include <cstdint>
#include <cstddef>
#include <vector>
#include <stack>

#include <tree/treenode.hpp>
namespace leetcode_872 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
#endif

using std::vector;

class Solution {
private:
    vector<int32_t> getNode(TreeNode *root) {
        vector<int32_t> willreturn{};
        for (std::stack<TreeNode *> ques{{root}}; !ques.empty();) {
            const TreeNode *rootnode = ques.top();
            ques.pop();
            if (rootnode->left != nullptr) {
                ques.push(rootnode->left);
            }
            if (rootnode->right != nullptr) {
                ques.push(rootnode->right);
            }
            if (rootnode->left == nullptr && rootnode->right == nullptr) {
                willreturn.push_back(rootnode->val);
            }
        }
        return willreturn;
    }

public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return true;
        } else if (root1 == nullptr || root2 == nullptr) {
            return false;
        }
        vector<int32_t> val1 = getNode(root1);
        vector<int32_t> val2 = getNode(root2);
        if (val1.size() != val2.size()) {
            return false;
        }
        for (size_t i{0}, max{val1.size()}; i < max; ++i) {
            if (val1[i] != val2[i]) {
                return false;
            }
        }
        return true;
    }
};
#ifdef CS203_DSAA_TEST_MACRO
}
#endif