// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifndef ALGORITHM_TEMPLATE_INCLUDE_TREE_TREENODE_LINK_HPP
#define ALGORITHM_TEMPLATE_INCLUDE_TREE_TREENODE_LINK_HPP

#include "tree/treenode.hpp"
#include <stack>
#include <class_helper/nonable.hpp>

namespace TREE_NODE {
using std::stack;

template<typename T>
class TreeNodeLink final : private nonCopyMoveAble {
    using TreeNodeT = TreeNode<T>;
private:
    TreeNodeT *root{nullptr};
    vector<TreeNodeT *> list{};
public:

    TreeNodeLink(std::initializer_list<int32_t> list_) : list(TREE_NODE::numToTree<T>(list_)) {}

    explicit TreeNodeLink(const vector<TreeNodeT *> &list_) : list(list_) {}

    explicit TreeNodeLink(TreeNodeT *li) : root(li) {}

    TreeNodeT *operator[](size_t i) const {
        if (i > list.size()) {
            return nullptr;
        }
        return list.at(i);
    }

    TreeNodeT *operator[](size_t i) {
        return const_cast<TreeNodeT *>(
                static_cast<const TreeNodeLink<T> &>(*this)[i]
        );
    }

    virtual ~TreeNodeLink() {
        for (stack<const TreeNodeT *> sta{{root}}; !sta.empty();) {
            const TreeNodeT *const head = sta.top();
            sta.pop();
            if (head == nullptr) { continue; }
            if (head->right != nullptr) {
                sta.push(head->right);
            }
            if (head->left != nullptr) {
                sta.push(head->left);
            }
            delete head;
        }
        for (const auto &ele: list) {
            delete ele;
        }
    }
};

}
#endif //ALGORITHM_TEMPLATE_INCLUDE_TREE_TREENODE_LINK_HPP
