

#ifdef ALGORITHM_TEST_MACRO
#include <vector>
#include <cstdint>
#include <functional>
#include <stack>
#include <algorithm>

#include <tree/treenode.hpp>
#include "traverse.cpp"
namespace leetcode_145 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
using namespace Tree_Traverse;
#endif

class Solution {
public:
    vector<int32_t> postorderTraversalIter(TreeNode *root) {
        vector<int32_t> will_return{};
        const auto function = [&will_return](const TreeNode *tn) -> void { will_return.push_back(tn->val); };
        iter::post(root, function);
        return will_return;
    }

    vector<int32_t> postorderTraversal(TreeNode *root) {
        vector<int32_t> will_return{};
        const auto function = [&will_return](const TreeNode *tn) -> void { will_return.push_back(tn->val); };
        rec::post(root, function);
        return will_return;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
