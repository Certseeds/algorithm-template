/*
 * @Author: nanoseeds
 * @Date: 2020-07-30 10:30:53
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-07-30 18:18:53
 */
// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/

#include <catch_main.hpp>
#include <functional>
#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <vector>

#include <tree/treenode.hpp>

namespace Tree_Traverse {
using TreeNode = TREE_NODE::TreeNode<int32_t>;
using Catch::Matchers::Equals;
using std::cout;
using std::list;
using std::stack;
using std::queue;
using std::vector;
using action = const std::function<void(const TreeNode *)> &;
static constexpr char end{'\n'}, space{' '};

namespace rec {
void pre(const TreeNode *root, action func) {
    if (root == nullptr) {
        return;
    }
    func(root);
    pre(root->left, func);
    pre(root->right, func);
}

void in(const TreeNode *root, action func) {
    if (root == nullptr) {
        return;
    }
    in(root->left, func);
    func(root);
    in(root->right, func);
}

void post(const TreeNode *root, action func) {
    if (root == nullptr) {
        return;
    }
    post(root->left, func);
    post(root->right, func);
    func(root);
}
}

namespace iter {

void pre1(const TreeNode *root, action func) {
    if (root == nullptr) {
        return;
    }
    for (stack<const TreeNode *> sta{{root}}; !sta.empty();) {
        const TreeNode *head = sta.top();
        sta.pop();
        func(head);
        if (head->right != nullptr) {
            sta.push(head->right);
        }
        if (head->left != nullptr) {
            sta.push(head->left);
        }
    }
}

void pre2(const TreeNode *root, action func) {
    if (root == nullptr) {
        return;
    }
    stack<const TreeNode *> sta;
    const TreeNode *head = root;
    while (head != nullptr || !sta.empty()) {
        while (head != nullptr) {
            func(head);
            sta.push(head->right);
            head = head->left;
        }
        head = sta.top();
        sta.pop();
    }
}

void pre3(const TreeNode *root, action func) {
    //作者：sonp
    //链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal/solution/mo-fang-di-gui-zhi-bian-yi-xing-by-sonp/
    if (root == nullptr) {
        return;
    }
    for (stack<const TreeNode *> sta{{root}}; !sta.empty();) {
        const TreeNode *head = sta.top();
        sta.pop();
        if (head != nullptr) {
            if (head->right != nullptr) {
                sta.push(head->right);
            }
            if (head->left != nullptr) {
                sta.push(head->left);
            }
            sta.push(head);
            sta.push(nullptr);
        } else {
            func(sta.top());
            sta.pop();
        }
    }
}


void in(const TreeNode *root, action func) {
    if (root == nullptr) {
        return;
    }
    const TreeNode *head = root;
    for (stack<const TreeNode *> sta; head != nullptr || !sta.empty(); head = head->right) {
        for (; head != nullptr; head = head->left) {
            sta.push(head);
        }
        head = sta.top();
        sta.pop();
        func(head);
    }
}

void in2(const TreeNode *root, action func) {
    //作者：sonp
    //链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal/solution/mo-fang-di-gui-zhi-bian-yi-xing-by-sonp/
    if (root == nullptr) {
        return;
    }
    for (stack<const TreeNode *> sta{{root}}; !sta.empty();) {
        const TreeNode *head = sta.top();
        sta.pop();
        if (head != nullptr) {
            if (head->right != nullptr) {
                sta.push(head->right);
            }
            sta.push(head);
            sta.push(nullptr);
            if (head->left != nullptr) {
                sta.push(head->left);
            }
        } else {
            func(sta.top());
            sta.pop();
        }
    }
}

void post(const TreeNode *root, action func) {
    //作者：sonp
    //链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal/solution/mo-fang-di-gui-zhi-bian-yi-xing-by-sonp/
    if (root == nullptr) {
        return;
    }
    for (stack<const TreeNode *> sta{{root}}; !sta.empty();) {
        const TreeNode *head = sta.top();
        sta.pop();
        if (head != nullptr) {
            sta.push(head);
            sta.push(nullptr);
            if (head->right != nullptr) {
                sta.push(head->right);
            }
            if (head->left != nullptr) {
                sta.push(head->left);
            }
        } else {
            func(sta.top());
            sta.pop();
        }
    }
}

void post2(const TreeNode *root, action func) {
    if (root == nullptr) {
        return;
    }
    list<const TreeNode *> nodes;
    for (stack<const TreeNode *> sta{{root}}; !sta.empty();) {
        const auto *const head = sta.top();
        sta.pop();
        nodes.push_front(head);
        if (head->left != nullptr) {
            sta.push(head->left);
        }
        if (head->right != nullptr) {
            sta.push(head->right);
        }
    }
    for (const auto *const node: nodes) {
        func(node);
    }
}

void level(const TreeNode *root, action func) {
    if (root == nullptr) {
        return;
    }
    for (queue<const TreeNode *> now{{root}}, next{}; !now.empty(); std::swap(now, next)) {
        while (!now.empty()) {
            const auto *const head = now.front();
            now.pop();
            func(head);
            if (head->left != nullptr) {
                next.push(head->left);
            }
            if (head->right != nullptr) {
                next.push(head->right);
            }
        }
    }
}
}
}
