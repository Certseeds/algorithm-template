// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include "traverse.cpp"

namespace leetcode_94 {
using namespace Tree_Traverse;

vector<int32_t> inorderTraversalIter(TreeNode *root) {
    vector<int32_t> will_return{};
    const auto function = [&will_return](const TreeNode *tn) -> void { will_return.push_back(tn->val); };
    iter::in(root, function);
    return will_return;
}

vector<int32_t> inorderTraversal(TreeNode *root) {
    vector<int32_t> will_return{};
    const auto function = [&will_return](const TreeNode *tn) -> void { will_return.push_back(tn->val); };
    rec::in(root, function);
    return will_return;
}
}
