// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO
#include <cstddef>
#include <cstdint>
#include <tree/treenode.hpp>
#include <vector>
#include "traverse.cpp"
namespace leetcode_unknown {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
using namespace Tree_Traverse;
#endif

class Solution {
   public:
    bool findTarget(TreeNode *root, int k) {
        vector<int32_t> targets{};
        const auto func = [&targets](const TreeNode *tn) -> void { targets.push_back(tn->val); };
        iter::in(root, func);
        for (size_t ll{0}, rr{targets.size() - 1}; ll < rr;) {
            const auto sum = targets[ll] + targets[rr];
            if (sum == k) {
                return true;
            } else if (sum > k) {
                --rr;
            } else if (sum < k) {
                ++ll;
            }
        }
        return false;
    }
};
#ifdef ALGORITHM_TEST_MACRO
}
#endif
