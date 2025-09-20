

#ifdef CS203_DSAA_TEST_MACRO
#include <cstdint>
#include <vector>
#include <functional>

#include <tree/treenode.hpp>
namespace leetcode_617 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
#endif

class Solution {
private:
    int32_t returnValueOfNode(TreeNode *t1, TreeNode *t2) {
        int willreturn{0};
        for (const auto i: {t1, t2}) {
            if (i != nullptr) {
                willreturn += i->val;
            }
        }
        return willreturn;
    }

    TreeNode *mergeTreesRec(TreeNode *t1, TreeNode *t2, const std::function<void(TreeNode *)> &func) {
        if (t1 == nullptr) {
            return t2;
        } else if (t2 == nullptr) {
            return t1;
        }
        auto *const willreturn = new TreeNode{returnValueOfNode(t1, t2)};
        func(willreturn);
        willreturn->left = mergeTreesRec(t1->left, t2->left, func);
        willreturn->right = mergeTreesRec(t1->right, t2->right, func);
        return willreturn;
    }
public:
    std::pair<TreeNode *, vector<TreeNode *>> mergeTrees(TreeNode *t1, TreeNode *t2) {
        vector<TreeNode *> will_return{};
        const auto func = [&will_return](TreeNode *node) { will_return.push_back(node); };
        const auto result = mergeTreesRec(t1, t2, func);
        return {result, will_return};
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
