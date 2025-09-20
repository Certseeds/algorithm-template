

#ifdef CS203_DSAA_TEST_MACRO
#include <vector>
#include <cstdint>
#include <vector>
#include <limits>
#include <tree/treenode.hpp>
namespace leetcode_654 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
#endif

class Solution {
private:
    inline int get_max(const vector<int> &nums, size_t begin, size_t end) {
        int maxv{std::numeric_limits<int16_t>::min()}, posi{0};
        for (size_t i{begin}; i < end; i++) {
            if (maxv < nums[i]) {
                maxv = nums[i];
                posi = i;
            }
        }
        return posi;
    }

    TreeNode *rec(const vector<int> &nums, size_t begin, size_t end) {
        if (begin == end) {
            return nullptr;
        }
        const int posi = get_max(nums, begin, end);
        auto *const willreturn = new TreeNode(nums[posi]);
        willreturn->left = rec(nums, begin, posi);
        willreturn->right = rec(nums, posi + 1, end);
        return willreturn;
    }
public:
    TreeNode *constructMaximumBinaryTree(const vector<int32_t> &nums) {
        return rec(nums, 0, nums.size());
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
