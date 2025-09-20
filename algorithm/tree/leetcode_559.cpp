

#ifdef CS203_DSAA_TEST_MACRO
#include <vector>
#include <algorithm>
#include <tree/treenode_multi.hpp>
#include <stack>

namespace leetcode_559 {
using Node = TREE_NODE::TreeNodeMulti;
using std::stack;
#endif


class Solution {
public:
    int maxDepth(Node *root) {
        if (root == nullptr) {
            return 0;
        }
        int maxvalue{0};
        for (const auto pointer: root->children) {
            maxvalue = std::max(maxvalue, maxDepth(pointer));
        }
        return maxvalue + 1;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
