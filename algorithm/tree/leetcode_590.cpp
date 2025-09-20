

#ifdef CS203_DSAA_TEST_MACRO
#include <vector>
#include <list>
#include <stack>
#include <tree/treenode_multi.hpp>
namespace leetcode_590 {
using std::vector;
using std::stack;
using std::list;
using Node = TREE_NODE::TreeNodeMulti;
#endif

class Solution {
private:
    void real_action(const Node *const root, vector<int32_t> &vec) {
        if (root == nullptr) {
            return;
        }
        for (const auto child: root->children) {
            real_action(child, vec);
        }
        vec.push_back(root->val);
    }

public:
    vector<int32_t> postorder(const Node *const root) {
        vector<int32_t> vec;
        real_action(root, vec);
        return vec;
    }

    vector<int32_t> postorderIter(const Node *const root) {
        if (root == nullptr) {
            return {};
        }
        list<int32_t> nodes;
        for (stack<const Node *> sta{{root}}; !sta.empty();) {
            const auto *const head = sta.top();
            sta.pop();
            nodes.push_front(head->val);
            for (const auto iter: head->children) {
                sta.push(iter);
            }
        }
        return {nodes.cbegin(), nodes.cend()};
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
