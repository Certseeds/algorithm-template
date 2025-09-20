

#ifdef CS203_DSAA_TEST_MACRO
#include <cstdint>

#include <tree/treenode.hpp>
namespace leetcode_226 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
#endif

class Solution {
public:
    TreeNode *invertTree(TreeNode *const root) {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode *const temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);
        return root;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
