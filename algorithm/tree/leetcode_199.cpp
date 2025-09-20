

#ifdef CS203_DSAA_TEST_MACRO
#include <vector>
#include <cstdint>
#include <queue>

#include <tree/treenode.hpp>
namespace leetcode_199 {
using std::vector;
using std::queue;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
#endif

class Solution {
public:
    vector<int32_t> rightSideView(const TreeNode *root) {
        if (root == nullptr) {
            return {};
        }
        vector<int32_t> will_return{};
        for (queue<const TreeNode *> now{{root}}, next{}; !now.empty(); std::swap(now, next)) {
            vector<int32_t> line{};
            while (!now.empty()) {
                const auto *const head = now.front();
                now.pop();
                line.push_back(head->val);
                if (head->left != nullptr) {
                    next.push(head->left);
                }
                if (head->right != nullptr) {
                    next.push(head->right);
                }
            }
            will_return.push_back(line.back());
        }
        return will_return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
