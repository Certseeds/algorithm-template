

#ifdef ALGORITHM_TEST_MACRO
#include <cstdint>
#include <unordered_map>

#include <tree/treenode.hpp>
namespace leetcode_235 {
using std::vector;
using std::unordered_map;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
#endif

class Solution {
public:
    const TreeNode *lowestCommonAncestorV2(TreeNode *root,
                                                         TreeNode *p, TreeNode *q) {
        // first, visit the p node, find it's parent-link
        // then, visit the q node and match it's parents one by one.
        if (root->val == p->val || root->val == q->val){
            return root;
        }
        unordered_map<TreeNode*, int32_t> node_to_depth{};
        int32_t depth{1};
        for(TreeNode* base{root};base != nullptr && base->val != p->val;depth++ ) {
            node_to_depth[base] = depth;
            if (base->val > p->val) {
                base = base->left;
            } else if (base->val < p->val) {
                base = base->right;
            }
        }
        node_to_depth[p] = depth;
        TreeNode* will_return{nullptr};
        depth = 0;
        for(TreeNode* base{root};base != nullptr && base->val != q->val;) {
            if (node_to_depth.count(base) != 0 && node_to_depth[base] > depth) {
                will_return = base;
                depth = node_to_depth[base];
            }
            if (base->val > q->val) {
                base = base->left;
            } else if (base->val <q->val) {
                base = base->right;
            }
        }
        if (node_to_depth.count(q) != 0 && node_to_depth[q] > depth) {
            will_return = q;
        }
        return will_return;
    }
private:
    bool nodeHadValue(unordered_map<TreeNode *, uint8_t> &umap, TreeNode *base, int32_t value) {
        if (base == nullptr) {
            return false;
        }
        if (umap.count(base) != 0) {
            return umap.at(base);
        }
        if (base->val == value) {
            umap[base] = true;
            return true;
        }
        const auto will_return = nodeHadValue(umap, base->left, value) || nodeHadValue(umap, base->right, value);
        umap[base] = will_return;
        return will_return;
    }
public:
    const TreeNode *lowestCommonAncestor(const TreeNode *root, const TreeNode *const p, const TreeNode *const q) {
        if (root == nullptr) {
            return nullptr;
        }
        for (unordered_map<TreeNode *, uint8_t> pmap, qmap; root != nullptr;) {
            if (root->val == p->val) {
                return p;
            } else if (root->val == q->val) {
                return q;
            }
            const auto pleft = nodeHadValue(pmap, root->left, p->val);
            const auto pright = nodeHadValue(pmap, root->right, p->val);

            const auto qleft = nodeHadValue(qmap, root->left, q->val);
            const auto qright = nodeHadValue(qmap, root->right, q->val);
            if (pleft && qright) {
                return root;
            } else if (pright && qleft) {
                return root;
            } else if (pleft && qleft) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return nullptr;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
