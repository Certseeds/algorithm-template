

#ifdef CS203_DSAA_TEST_MACRO
#include <cstdint>
#include <stack>

#include <tree/treenode.hpp>
namespace leetcode_230 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
#endif

#include <stack>

using std::stack;

class Solution {
public:
    int32_t kthSmallest(TreeNode *root, int32_t k) {
        if (root == nullptr) {
            return -1;
        }
        for (stack<TreeNode *> sta; root != nullptr || !sta.empty(); root = root->right) {
            for (; root != nullptr; root = root->left) {
                sta.push(root);
            }
            root = sta.top();
            sta.pop();
            --k;
            if (k == 0) {
                break;
            }
        }
        return root->val;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif