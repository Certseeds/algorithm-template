// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds

#ifdef ALGORITHM_TEST_MACRO
#include <cstddef>
#include <cstdint>
#include <tree/treenode.hpp>
#include <vector>
#include "traverse.cpp"
namespace leetcode_so_54 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
using namespace Tree_Traverse;
#endif

class Solution {
   public:
    int kthLargest(TreeNode *root, int k) {
        vector<int32_t> countVec;
        const auto functionPre = [&countVec](const TreeNode *tn) -> void {
            countVec.push_back(tn->val);
        };
        iter::in(root, functionPre);
        const auto netElements = countVec.size();
        vector<int32_t> element;
        static size_t count{0};
        const auto function = [&element, k, netElements](const TreeNode *tn) -> void {
            ++count;
            if (count + k == netElements + 1) {
                element.push_back(tn->val);
            }
        };
        iter::in(root, function);
        count = 0;
        return element.front();
    }
};
#ifdef ALGORITHM_TEST_MACRO
}
#endif
