

#ifdef ALGORITHM_TEST_MACRO
#include <cstdint>
#include <algorithm>

#include <tree/treenode.hpp>
namespace leetcode_653 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
#endif

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, const TreeNode *const p, const TreeNode *const q) {
        if (root->val > std::max(p->val, q->val)) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (root->val < std::min(p->val, q->val)) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
