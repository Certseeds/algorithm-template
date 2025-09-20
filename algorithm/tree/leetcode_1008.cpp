// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022 nanoseeds

*/



#ifdef CS203_DSAA_TEST_MACRO
#include <cstdint>
#include <cstddef>
#include <vector>

#include <tree/treenode.hpp>
namespace leetcode_1008 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
#endif

using std::vector;

class Solution {
private:
    // find fst > value in vec[left,right]
    int32_t binary_search(const vector<int32_t> &vec, size_t left, size_t right, int32_t value) {
        if (left > right) {
            return 0;
        } else if (left == right) {
            return right;
        } else if (left + 1 == right) {
            return right;
        }// 一定存在,所以上面这俩能直接判定
        while (left <= right) {
            if (const size_t middle = (right - left) / 2 + left;
                    vec[middle] > value && vec[middle - 1] < value) {
                return middle;
            } else if (vec[middle] > value) {
                right = middle;
            } else {
                left = middle + 1;
            }
        }
        return 0;
    }

    TreeNode *rec(const vector<int32_t> &preorder, int32_t left, int32_t right) {
        if (left > right) {
            return nullptr;
        } else if (left == right) {
            return new TreeNode{preorder[right]};
        }
        TreeNode *const root = new TreeNode{preorder[left]};
        const int32_t leftPlus = ++left;
        if (preorder[leftPlus] > root->val) {
            root->right = rec(preorder, leftPlus, right);
            return root;
        } else if (preorder[right] < root->val) {
            root->left = rec(preorder, leftPlus, right);
            return root;
        }
        // there vec[leftPlus] < root->val < vec[right]
        const auto bigger = binary_search(preorder, leftPlus, right, root->val);
        if (bigger == 0) {
            return root;
        }
        root->left = rec(preorder, leftPlus, bigger - 1);
        root->right = rec(preorder, bigger, right);
        return root;
    }

public:
    TreeNode *bstFromPreorder(const vector<int32_t> &preorder) {
        const auto sizes{preorder.size() - 1};
        return rec(preorder, 0, sizes);
    }
};
#ifdef CS203_DSAA_TEST_MACRO
}
#endif