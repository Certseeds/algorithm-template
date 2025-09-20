// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2021 nanoseeds

*/
#ifndef ALGORITHM_TEMPLATE_INCLUDE_TREE_TREENODE_TEMPLATE_HPP
#define ALGORITHM_TEMPLATE_INCLUDE_TREE_TREENODE_TEMPLATE_HPP
#include <class_helper/nonable.hpp>
namespace TREE_NODE_TEMP {
template<typename T, template<typename> typename CLASS>
struct TreeNodeTemp : private nonCopyMoveAble {
public:
    T val;
    CLASS<T> *left, *right;

    virtual ~TreeNodeTemp() {
        this->val = static_cast<T>(0);
        this->left = nullptr;
        this->right = nullptr;
    }


private:
    explicit TreeNodeTemp(T x = static_cast<T>(0)) : TreeNodeTemp<T, CLASS>(x, nullptr, nullptr) {};

    TreeNodeTemp(T x, CLASS<T> *le, CLASS<T> *rig) : val(x), left(le), right(rig) {};

    friend CLASS<T>;
};
}
#endif //ALGORITHM_TEMPLATE_INCLUDE_TREE_TREENODE_TEMPLATE_HPP
