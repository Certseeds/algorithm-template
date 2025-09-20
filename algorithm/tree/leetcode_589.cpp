

#ifdef CS203_DSAA_TEST_MACRO
#include <vector>
#include <stack>

#include <tree/treenode_multi.hpp>
namespace leetcode_589 {
using std::vector;
using Node = TREE_NODE::TreeNodeMulti;
#endif

#include <vector>
#include <stack>

using std::vector;
using std::stack;

class Solution {
private:
    void real_action(const Node *const root, vector<int32_t> &vec) {
        if (root == nullptr) {
            return;
        }
        vec.push_back(root->val);
        for (const auto child: root->children) {
            real_action(child, vec);
        }
    }

public:
    vector<int32_t> preorder(const Node *const root) {
        vector<int32_t> vec;
        real_action(root, vec);
        return vec;
    }

    vector<int32_t> preorderIter(const Node *const root) {
        if (root == nullptr) {
            return {};
        }
        vector<int32_t> vec{};
        const auto func = [&vec](const Node *const node) {
            vec.push_back(node->val);
        };
        for (stack<const Node *> sta{{root}}; !sta.empty();) {
            const auto *const head = sta.top();
            sta.pop();
            func(head);
            for (auto iter{head->children.rbegin()}; iter != head->children.rend(); iter++) {
                sta.push(*iter);
            }
        }
        return vec;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
