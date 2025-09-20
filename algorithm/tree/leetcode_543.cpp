

#ifdef ALGORITHM_TEST_MACRO
#include <cstdint>
#include <memory>
#include <algorithm>

#include <tree/treenode.hpp>
namespace leetcode_543 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
#endif

class Solution {
private:
    int rec(TreeNode *base, int32_t num, const std::shared_ptr<int32_t>& max) {
        if (base == nullptr) {
            return num;
        }
        const auto left = rec(base->left, num, max);
        const auto right = rec(base->right, num, max);
        *max = std::max(*max, left + right);
        return std::max(left, right) + 1;
    }
public:
    int32_t diameterOfBinaryTree(TreeNode *root) {
        auto maxV = std::make_shared<int32_t>(0);
        rec(root, 0, maxV);
        return *maxV;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
