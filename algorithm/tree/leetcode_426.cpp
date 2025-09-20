

#ifdef CS203_DSAA_TEST_MACRO
#include <cstdint>
#include <stack>

#include <tree/treenode.hpp>
namespace leetcode_426 {
using std::vector;
using Node = TREE_NODE::TreeNode<int32_t>;
using std::stack;

#endif

class Solution {
public:
    Node *treeToDoublyList(Node *root) {
        if (root == nullptr) {
            return nullptr;
        }
        Node *base{nullptr};
        Node *head = root;
        bool temp{false};
        for (stack<Node *> sta; head != nullptr || !sta.empty(); head = head->right) {
            for (; head != nullptr; head = head->left) {
                sta.push(head);
            }
            head = sta.top();
            sta.pop();
            if (base != nullptr) {
                base->right = head;
            }
            head->left = base;
            if (!temp) {
                root = head;
                temp = true;
            }
            base = head;
        }
        root->left = base;
        base->right = root;
        return root;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
