

#ifdef ALGORITHM_TEST_MACRO
#include <vector>
#include <cstdint>
#include <functional>
#include <stack>

#include <tree/treenode.hpp>
#include "traverse.cpp"
namespace leetcode_144 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
using namespace Tree_Traverse;
#endif

class Solution {
public:
    vector<int32_t> preorderTraversalIter(TreeNode *root) {
        vector<int32_t> will_return{};
        const auto function = [&will_return](const TreeNode *tn) -> void { will_return.push_back(tn->val); };
        iter::pre1(root, function);
        return will_return;
    }

    vector<int32_t> preorderTraversal(TreeNode *root) {
        vector<int32_t> will_return{};
        const auto function = [&will_return](const TreeNode *tn) -> void { will_return.push_back(tn->val); };
        rec::pre(root, function);
        return will_return;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
