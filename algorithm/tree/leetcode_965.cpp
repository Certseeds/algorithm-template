// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds


#ifdef ALGORITHM_TEST_MACRO
#include <cstdint>
#include <cstddef>
#include <stack>
#include <functional>

#include <tree/treenode.hpp>
namespace leetcode_965 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
using std::stack;

#endif


class Solution {
public:
    bool isUnivalTreeRec(TreeNode *root) {
        for (stack<TreeNode const *> sta{{root}}; !sta.empty();) {
            const TreeNode *now = sta.top();
            sta.pop();
            const auto lambda = [now, &sta](TreeNode const *son) {
                if (son != nullptr) {
                    if (now->val != son->val) {
                        return false;
                    }
                    sta.push(son);
                }
                return true;
            };
            if (!lambda(now->left) || !lambda(now->right)) {
                return false;
            }
        }
        return true;
    }

    bool isUnivalTreeIter(TreeNode *root) {
        const std::function<bool(TreeNode *const, int32_t)> judgement =
                [&judgement](TreeNode *const root, int32_t value) {
                    if (root == nullptr) {
                        return true;
                    }
                    return (
                            (root->val == value) &&
                            judgement(root->left, root->val) &&
                            judgement(root->right, root->val));
                };
        return judgement(root, root->val);
    }
};
#ifdef ALGORITHM_TEST_MACRO
}
#endif
