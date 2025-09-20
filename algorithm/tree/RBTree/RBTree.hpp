/**
 * @Author: nanoseeds
 * @Date: 2020-08-06 22:41:41
 * @LastEditors: nanoseeds
 */
// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_TREE_RBTREE_RBTREE_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_TREE_RBTREE_RBTREE_HPP

#include "RBTNode.hpp"
#include <iostream>
#include <stack>
#include <map>

namespace RED_BLACK_TREE {
using std::cout, std::endl;
using std::stack;
using std::initializer_list;
using RED_BLACK_TREE_NODE::RBTNode, RED_BLACK_TREE_NODE::RBTColor;

template<typename T>
class RBTree {
public:
    using Node_t = RBTNode<T>;
private:
    inline bool check_law2() const {
        return nullptr == this->root || this->root->isBlack();
    }

    inline bool check_law4() const {
        if (this->root == nullptr) {
            return true;
        }
        stack<Node_t *> sta{{this->root}};
        while (!sta.empty()) {
            const auto node = sta.top();
            sta.pop();
            if (node->isRed()) {
                static const auto judge_func = [](Node_t *const n) {
                    return n != nullptr && n->isRed();
                };
                if (judge_func(node->left) || judge_func(node->right)) {
                    return false;
                }
            }
            if (node->right != nullptr) {
                sta.push(node->right);
            }
            if (node->left != nullptr) {
                sta.push(node->left);
            }
        }
        return true;
    }

    inline bool check_law5() {
        if (this->root == nullptr) {
            return true;
        }
        stack<std::pair<int, Node_t *>> sta{{{0, this->root}}};
        int32_t count = -1;
        while (!sta.empty()) {
            const auto head = sta.top();
            sta.pop();
            auto[num, node] = head;
            num += node->isBlack();
            if (node->right != nullptr) {
                sta.push(std::make_pair(num, node->right));
            }
            if (node->left != nullptr) {
                sta.push(std::make_pair(num, node->left));
            }
            if (node->left == nullptr && node->right == nullptr) {
                if (count == -1) {
                    count = num;
                } else if (num != count) {
                    return false;
                }
            }
        }
        return true;
    }

    inline bool check_number() {
        if (this->root == nullptr) {
            return true;
        }
        stack<Node_t *> sta{{this->root}};
        size_t count{0};
        while (!sta.empty()) {
            const auto node = sta.top();
            sta.pop();
            if (node->right != nullptr) {
                sta.push(node->right);
            }
            if (node->left != nullptr) {
                sta.push(node->left);
            }
            ++count;
        }
        CHECK(this->size == count);
        return true;
    }

    void insert_case1(Node_t *node);

    void insert_case2(Node_t *node);

    void insert_case3(Node_t *node);

    void insert_case4(Node_t *node);

    void insert_case5(Node_t *node);

    void removeNode(Node_t *node);

    void remove_case1(Node_t *node, Node_t *brother, Node_t *parent, bool isLeft);

    void remove_case2(Node_t *node, Node_t *brother, Node_t *parent, bool isLeft);

    void remove_case3(Node_t *node, Node_t *brother, Node_t *parent, bool isLeft);

    void remove_case4(Node_t *node, Node_t *brother, Node_t *parent, bool isLeft);

    void remove_case5(Node_t *node, Node_t *brother, Node_t *parent, bool isLeft);

    void remove_case6(Node_t *node, Node_t *brother, Node_t *parent, bool isLeft);

    void rorate_left(Node_t *node);

    void rorate_right(Node_t *node);

    const std::function<int(const T &t1, const T &t2)> comp = std::less<T>();
public:
    Node_t *root{nullptr};
    size_t size{0};

    RBTree() = default;

    explicit RBTree(std::function<int(const T &t1, const T &t2)> comp_) : comp(std::move(comp_)) {}

    RBTree(initializer_list<T> list) {
        this->insert(list);
    }

    template<typename it>
    RBTree(it begin, it end) {
        for (; begin != end; ++begin) {
            this->insert(*begin);
        }
    }

    ~RBTree() {
        if (this->root != nullptr) {
            stack<Node_t *> sta{{this->root}};
            while (!sta.empty()) {
                const auto node = sta.top();
                sta.pop();
                if (node->right != nullptr) {
                    sta.push(node->right);
                }
                if (node->left != nullptr) {
                    sta.push(node->left);
                }
                delete node;
            }
        }
    }

    void check() {
        CHECK(this->check_number());
        CHECK(this->check_law2());
        CHECK(this->check_law4());
        CHECK(this->check_law5());
        if (!this->check_law2()) {
            throw std::logic_error("law 2 error");
        }
        if (!this->check_law4()) {
            throw std::logic_error("law 4 error");
        }
        if (!this->check_law5()) {
            throw std::logic_error("law 5 error");
        }
        if (!this->check_number()) {
            throw std::logic_error("number do not match error");
        }
    }

    void pre_order() const;

    void insert(T key);

    void insert(std::initializer_list<T> key) {
        for (const auto &item: key) {
            RBTree<T>::insert(item);
        }
    }

    bool find(T key) const;

    bool contains(T key) const { return this->find(std::move(key)); }

    void remove(T key);

};

template<typename T>
void RBTree<T>::insert(T key) {
    auto *const node = new Node_t(key, nullptr, nullptr, nullptr);
    Node_t *temp = root;
    while (temp != nullptr) {
        int32_t comp_val_one = this->comp(temp->val, key);
        int32_t comp_val_two = this->comp(key, temp->val);
        if (comp_val_two) {
            if (temp->left == nullptr) {
                temp->set_left(node);
                node->set_partent(temp);
                ++size;
                break;
            }
            temp = temp->left;
        } else if (comp_val_one) {
            if (temp->right == nullptr) {
                temp->set_right(node);
                node->set_partent(temp);
                ++size;
                break;
            }
            temp = temp->right;
        }
    }
    insert_case1(node);
}

template<typename T>
void RBTree<T>::insert_case1(Node_t *node) {
    if (node->parent == nullptr) {
        this->root = node;
        node->set_black();
        ++size;
        return;
    }
    insert_case2(node);
}

template<typename T>
void RBTree<T>::insert_case2(Node_t *node) {
    assert(node->parent != nullptr);
    if (node->parent->isBlack()) {
        return;
    }
    insert_case3(node);
}

template<typename T>
void RBTree<T>::insert_case3(Node_t *node) {
    auto *const parent = node->parent;
    auto *const uncle = node->get_uncle();
    if (parent->isRed() && uncle != nullptr && uncle->isRed()) {
        auto *const p_parent = node->get_grandparent();
        // because parent is Red, so, parent can not be root( which must be Black)
        // so, it have p_parent node and no not need check
        parent->set_black();
        uncle->set_black();
        p_parent->set_red();
        if (p_parent->parent == nullptr) {
            --size;
        }
        insert_case1(p_parent);
        return;
    }
    insert_case4(node);
}

template<typename T>
void RBTree<T>::insert_case4(Node_t *node) {
    auto *const parent = node->parent;
    auto *const uncle = node->get_uncle();
    //cout << "insert 4" << endl;
    if (parent->isRed() && (nullptr == uncle || uncle->isBlack())) {
        auto *const p_parent = node->get_grandparent();
        if (node == parent->right && parent == p_parent->left) {
            rorate_left(node);
            node = node->left;
        } else if (node == parent->left && parent == p_parent->right) {
            rorate_right(node);
            node = node->right;
        }
    }
    insert_case5(node);
}

template<typename T>
void RBTree<T>::insert_case5(Node_t *node) {
    //cout << "insert 5" << endl;
    auto *const parent = node->parent;
    auto *const p_parent = node->get_grandparent();
    parent->set_black();
    p_parent->set_red();
    if (node == parent->left && p_parent->left == parent) {
        rorate_right(node->parent);
    } else if (node == parent->right && parent == p_parent->right) {
        rorate_left(node->parent);
    }
}

template<typename T>
void RBTree<T>::rorate_left(Node_t *node) {
    Node_t *const p_parent = node->get_grandparent();
    Node_t *const parent = node->parent;
    if (p_parent != nullptr) {
        if (p_parent->left == parent) {
            p_parent->set_left(node);
        } else {
            p_parent->set_right(node);
        }
    }
    if (node->left != nullptr) {
        node->left->set_partent(parent);
    }
    if (parent != nullptr) {
        parent->set_right(node->left);
        parent->set_partent(node);
    }
    node->set_partent(p_parent);
    node->set_left(parent);
    if (node->parent == nullptr) {
        this->root = node;
    }
}

template<typename T>
void RBTree<T>::rorate_right(Node_t *node) {
    auto *const p_parent = node->get_grandparent();
    auto *const parent = node->parent;
    if (p_parent != nullptr) {
        if (p_parent->left == parent) {
            p_parent->set_left(node);
        } else {
            p_parent->set_right(node);
        }
    }
    if (node->right != nullptr) {
        node->right->set_partent(parent);
    }
    if (parent != nullptr) {
        parent->set_left(node->right);
        parent->set_partent(node);
    }
    node->set_partent(p_parent);
    node->set_right(parent);
    if (node->parent == nullptr) {
        this->root = node;
    }
}

template<typename T>
void RBTree<T>::remove(T key) {
    Node_t *temp = root;
    while (temp != nullptr) {
        int32_t comp_val_one = this->comp(temp->val, key);
        int32_t comp_val_two = this->comp(key, temp->val);
        if (comp_val_two) {
            if (temp->left == nullptr) {
                goto unfind;
            }
            temp = temp->left;
        } else if (comp_val_one) {
            if (temp->right == nullptr) {
                goto unfind;
            }
            temp = temp->right;
        } else {
            if (temp->right == nullptr) {
                removeNode(temp);
                goto find;
            }
            Node_t *right_min = temp->right;
            while (right_min->left != nullptr) {
                right_min = right_min->left;
            }
            std::swap(temp->val, right_min->val);
            removeNode(right_min);
            goto find;
        }
    }
    find:
    size -= 1;
    unfind:
    return;
}

template<typename T>
void RBTree<T>::removeNode(RBTree::Node_t *node) {
    auto *const child = node->right == nullptr ? node->left : node->right;
    auto *const p_node = node->parent;
    if (p_node == nullptr) {
        if (node->left != nullptr || node->right != nullptr) {
            child->parent = nullptr;
            child->set_black();
        }
        this->root = child;
        delete node;
        node = nullptr;
        return;
    }
    assert(p_node != nullptr);
    Node_t *bro_node;
    bool isLeft;
    if (node == p_node->left) {
        p_node->left = child;
        bro_node = p_node->right;
        isLeft = true;
    } else {
        p_node->right = child;
        bro_node = p_node->left;
        isLeft = false;
    }
    if (child != nullptr) {
        child->parent = p_node;
    }
    if (node->isBlack()) {
        if (child != nullptr && child->isRed()) {
            child->set_black();
        } else {
            remove_case1(child, bro_node, p_node, isLeft);
        }
    }
    delete node;
}

template<typename T>
void RBTree<T>::remove_case1(Node_t *node, Node_t *brother, Node_t *parent, bool isLeft) {
    if (parent != nullptr) {
        if (parent->left == nullptr && parent->right == nullptr && parent->parent == nullptr && node == nullptr &&
            brother == nullptr) {
            return;
        }
        remove_case2(node, brother, parent, isLeft);
    }
}

template<typename T>
void RBTree<T>::remove_case2(Node_t *node, Node_t *brother, Node_t *parent, bool isLeft) {
    if (nullptr != brother && brother->isRed()) {
        parent->set_red();
        brother->set_black();
        if (isLeft) {
            rorate_left(parent);
        } else {
            rorate_right(parent);
        }
    }
    remove_case3(node, brother, parent, isLeft);
}

template<typename T>
void RBTree<T>::remove_case3(Node_t *node, Node_t *brother, Node_t *parent, bool isLeft) {
    if (parent->isBlack()) {
        bool new_isLeft = true;
        if (parent->parent == nullptr) {
            new_isLeft = false;
        }
        if (brother == nullptr) {
        } else if (brother->isBlack() &&
                   (brother->left == nullptr || brother->left->isBlack()) &&
                   (brother->right == nullptr || brother->right->isBlack())) {
            brother->set_red();
        }
        remove_case1(parent, parent->get_brother(), parent->parent, new_isLeft);
    }
    remove_case4(node, brother, parent, isLeft);
}

template<typename T>
void RBTree<T>::remove_case4(Node_t *node, Node_t *brother, Node_t *parent, bool isLeft) {
    if (parent->isRed() &&
        (brother == nullptr ||
         (brother->isBlack() && (brother->left == nullptr || brother->left->isBlack()) &&
          (brother->right == nullptr || brother->right->isBlack())))
            ) {
        if (brother != nullptr) {
            brother->set_red();
        }
        parent->set_black();
    } else {
        remove_case5(node, brother, parent, isLeft);
    }
}

template<typename T>
void RBTree<T>::remove_case5(Node_t *node, Node_t *brother, Node_t *parent, bool isLeft) {
    if (brother == nullptr || brother->isBlack()) {
        if (isLeft) {
            if (brother != nullptr && (brother->right == nullptr || brother->right->isBlack()) &&
                (brother->left != nullptr && brother->left->isRed())) {
                brother->set_red();
                brother->left->set_black();
                rorate_right(brother->left);
            }
        } else {
            if (brother != nullptr && (brother->left == nullptr || brother->left->isBlack()) &&
                (brother->right != nullptr && brother->right->isRed())) {
                brother->set_red();
                brother->right->set_black();
                rorate_left(brother->right);
            }
        }
    }
    remove_case6(node, brother, parent, isLeft);
}

template<typename T>
void RBTree<T>::remove_case6(Node_t *node, Node_t *brother, Node_t *parent, bool isLeft) {
    if (brother == nullptr || brother->isBlack()) {
        if (parent == nullptr || parent->isBlack()) {
            brother->set_black();
        } else {
            brother->set_red();
        }
        if (parent != nullptr) {
            parent->set_black();
        }
        if (isLeft) {
            if (brother->right != nullptr && brother->right->isRed()) {
                brother->right->set_black();
                rorate_left(brother);
            }
        } else {
            if (brother->left != nullptr && brother->left->isRed()) {
                brother->left->set_black();
                rorate_right(brother);
            }
        }
    }
}

static const auto print = [](auto p) {
    int distance = p.first;
    const auto *node = p.second;
    std::cout << std::string(distance, ' ');
    std::cout << (node->isRed() ? 'R' : 'B') << ':';
    std::cout << node->val << '\n';
};

static constexpr const int32_t plusNumber = 2;

template<typename T>
void RBTree<T>::pre_order() const {
    if (this->root == nullptr) {
        return;
    }
    stack<std::pair<int, Node_t *>> sta{{{0, this->root}}};
    int count = 0;
    while (!sta.empty()) {
        const auto head = sta.top();
        const auto&[distance, node] = head;
        sta.pop();
        print(head);
        if (node->right != nullptr) {
            sta.push(std::make_pair(distance + plusNumber, node->right));
        }
        if (node->left != nullptr) {
            sta.push(std::make_pair(distance + plusNumber, node->left));
        }
        count++;
        if (count > 1000) {
            count += 2;
        }
    }
}

template<typename T>
bool RBTree<T>::find(T key) const {
    Node_t *temp = root;
    while (temp != nullptr) {
        if (temp->val > key) {
            if (temp->left == nullptr) {
                return false;
            }
            temp = temp->left;
        } else if (temp->val < key) {
            if (temp->right == nullptr) {
                return false;
            }
            temp = temp->right;
        } else {
            return true;
        }
    }
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_TREE_RBTREE_RBTREE_HPP
