

#ifdef ALGORITHM_TEST_MACRO
#include <tree/treenode.hpp>
namespace leetcode_700 {
using TreeNode = TREE_NODE::TreeNode<int32_t>;
#endif

class Solution {
public:
    TreeNode *searchBST(TreeNode *root, int32_t val) {
        if (root == nullptr) {
            return nullptr;
        } else if (root->val == val) {
            return root;
        } else if (root->val > val) {
            return (searchBST(root->left, val));
        }
        return (searchBST(root->right, val));
    }

    TreeNode *searchBSTiter(TreeNode *root, int32_t val) {
        TreeNode *base{root};
        while (base != nullptr) {
            if (base->val == val) {
                return base;
            } else if (base->val > val) {
                base = base->left;
            } else {
                base = base->right;
            }
        }
        return nullptr;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
