// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022 nanoseeds

*/


#ifdef CS203_DSAA_TEST_MACRO
#include <stack>
#include <vector>
#include <tuple>
#include <cstdint>
#include <cstddef>

#include <tree/treenode.hpp>
namespace leetcode_1302 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
#endif

class Solution {
private:
    void visit(const TreeNode *const root, vector<int32_t> &nums, int32_t depth) {
        if (root == nullptr) {
            return;
        }
        const auto length{nums.size()};
        if (length <= depth) {
            nums.push_back(0);
        }
        nums[depth] += root->val;
        visit(root->left, nums, depth + 1);
        visit(root->right, nums, depth + 1);
    }

public:
    int32_t deepestLeavesSumRec(TreeNode *root) {
        vector<int32_t> nums{};
        visit(root, nums, 0);
        return nums.back();
    }

    int32_t deepestLeavesSumIter(TreeNode *root) {
        int32_t willReturn{0}, height{0};
        for (std::stack<std::tuple<const TreeNode *const, int32_t>> que{{std::make_tuple(root, 0)}};!que.empty();) {
            const auto [node, depth] = que.top();
            que.pop();
            if (node == nullptr) {
                continue;
            }
            if (height == depth) {
                willReturn += node->val;
            } else if (height < depth) {
                willReturn = node->val;
                height = depth;
            }
            que.push(std::make_tuple(node->left, depth + 1));
            que.push(std::make_tuple(node->right, depth + 1));
        }
        return willReturn;
    }
};
#ifdef CS203_DSAA_TEST_MACRO
}
#endif
