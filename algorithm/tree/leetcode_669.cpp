

#ifdef CS203_DSAA_TEST_MACRO
#include <cstdint>

#include <tree/treenode.hpp>
namespace leetcode_669 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
#endif

class Solution {
public:
    TreeNode *trimBST(TreeNode *root, int L, int R) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val < L) {
            root->left = nullptr;
            return trimBST(root->right, L, R);
        } else if (root->val > R) {
            root->right = nullptr;
            return trimBST(root->left, L, R);
        }
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        return root;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
