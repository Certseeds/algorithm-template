// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022 nanoseeds

*/


#ifdef CS203_DSAA_TEST_MACRO
#include <stack>
#include <cstdint>

#include <tree/treenode.hpp>
namespace leetcode_1261 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
#endif

class FindElements {
private:
    TreeNode *const root;
public:
    explicit FindElements(TreeNode *root_) : root(root_) {
        TreeNode *node = root;
        if (node == nullptr) return;
        node->val = 0;
        for (std::stack<TreeNode *> sta{{node}}; !sta.empty();) {
            TreeNode *const top = sta.top();
            sta.pop();
            if (top != nullptr) {
                if (top->left != nullptr) {
                    top->left->val = (top->val * 2) + 1;
                    sta.push(top->left);
                }
                if (top->right != nullptr) {
                    top->right->val = (top->val * 2) + 2;
                    sta.push(top->right);
                }
            }
        }
    }

    [[nodiscard]] bool find(int32_t target) {
        std::stack<uint8_t> sta;
        if (target == 0) {
             return root != nullptr;
        }
        for (int32_t temp{target}; temp != 0;) {
            if (temp % 2 == 0) {
                sta.push(1); // means right
                temp = (temp - 2) / 2;
            } else {
                sta.push(0);
                temp = (temp - 1) / 2;
            }
        }
        // 15: (1,7),(1,3),(1,1),(1,0)
        // 30: (0,14),(0,6),(0,2),(0,0)
        TreeNode *base{root};
        while (!sta.empty()) {
            const auto v = sta.top();
            sta.pop();
            if (base == nullptr) {
                return false;
            }
            if (v == 1) {
                base = base->right;
            } else {
                base = base->left;
            }
        }
        return (base != nullptr);
    }
};
#ifdef CS203_DSAA_TEST_MACRO
}
#endif
