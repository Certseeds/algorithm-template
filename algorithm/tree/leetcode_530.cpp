

#ifdef CS203_DSAA_TEST_MACRO
#include <cstdint>
#include <stack>
#include <algorithm>
#include <limits>
#include <tree/treenode.hpp>
namespace leetcode_530 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;

#endif

class Solution {
public:
    int32_t getMinimumDifference(TreeNode *root) {
        if (root == nullptr) {
            return std::numeric_limits<int32_t>::max();
        }
        const auto *left = root->left;
        const auto *right = root->right;
        while (left != nullptr && left->right != nullptr) {
            left = left->right;
        }
        while (right != nullptr && right->left != nullptr) {
            right = right->left;
        }
        int32_t left_son_diff{std::numeric_limits<int32_t>::max()}, right_son_diff{std::numeric_limits<int32_t>::max()};
        if (left != nullptr) {
            left_son_diff = root->val - left->val;
        }
        if (right != nullptr) {
            right_son_diff = right->val - root->val;
        }
        const int32_t left_will_return = getMinimumDifference(root->left);
        const int32_t right_will_return = getMinimumDifference(root->right);
        return std::min({left_son_diff, right_son_diff, left_will_return, right_will_return});
    }

    int32_t getMinimumDifference2(TreeNode *root) {
        if (root == nullptr) {
            return std::numeric_limits<int32_t>::max();
        }
        std::stack<TreeNode *> sta{};
        int32_t lastValue{-0x3f3f3f3f}, will_return{std::numeric_limits<int32_t>::max()};
        for (TreeNode *head{root}; head != nullptr || !sta.empty(); head = head->right) {
            while (head != nullptr) {
                sta.push(head);
                head = head->left;
            }
            head = sta.top();
            sta.pop();
            will_return = std::min(will_return, head->val - lastValue);
            lastValue = head->val;
        }
        return will_return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
