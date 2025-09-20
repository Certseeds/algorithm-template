

#ifdef ALGORITHM_TEST_MACRO
#include <cstdint>

#include <tree/treenode.hpp>
namespace leetcode_98 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;

#endif

class Solution {
private:
    bool smaller(TreeNode *root, int32_t value) {
        if (root == nullptr) {
            return true;
        }
        return root->val < value &&
               smaller(root->right, value) && smaller(root->left, root->val) &&
               bigger(root->right, root->val);
    }

    bool bigger(TreeNode *root, int32_t value) {
        if (root == nullptr) {
            return true;
        }
        return root->val > value &&
               smaller(root->left, root->val) &&
               bigger(root->left, value) && bigger(root->right, root->val);
    }

public:
    bool isValidBST(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        return smaller(root->left, root->val) && bigger(root->right, root->val);
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
