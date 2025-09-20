// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <unordered_map>

namespace tree::huffman {

using std::stack;
using std::list;
using std::priority_queue;

struct huffman final : private nonCopyMoveAble {
private:
    struct TreeNode final {
        const size_t val;
        const size_t ch;
        TreeNode *left{nullptr}, *right{nullptr};

        explicit TreeNode(size_t v, size_t ch) : val(v), ch(ch) {}
    };

private:
    std::vector<char> inside;
    std::unordered_map<char, string> umap;
    TreeNode *base;
    vector<TreeNode *> del;
public:
    explicit huffman(const std::string &str);

    void push_back(const char ch) {
        inside.push_back(ch);
    }

    string cal(const string &str) const;

    string decal(const string &serilize) const;

    ~huffman();
};

huffman::huffman(const string &str) {
    static constexpr const auto cmp{
            [](const auto &v1, const auto &v2) {
                return v1->val > v2->val;
            }
    };
    priority_queue<TreeNode *, vector<TreeNode *>, decltype(cmp)> priorityQueue{cmp};
    {
        std::map<char, size_t> chmap;
        for (const auto item: str) {
            ++chmap[item];
        }
        for (const auto item: chmap) {
            auto *const node = new TreeNode(item.second, item.first);
            priorityQueue.push(node);
            del.push_back(node);
        }
    }
    size_t order{std::numeric_limits<char>::max() + 1};
    while (priorityQueue.size() > 1) {
        const auto minV{priorityQueue.top()};
        priorityQueue.pop();
        const auto minV2{priorityQueue.top()};
        priorityQueue.pop();
        auto *const insertd = new TreeNode(minV->val + minV2->val, ++order);
        insertd->left = (minV->val > minV2->val) ? minV : minV2;
        insertd->right = (minV == insertd->left) ? minV2 : minV;
        priorityQueue.push(insertd);
        del.push_back(insertd);
    }
    TreeNode *root = priorityQueue.top();
    const TreeNode *const Croot = root;
    priorityQueue.pop();
    std::queue<std::pair<string, const TreeNode *const>> que{{{"", Croot}}};
    while (!que.empty()) {
        const auto[prefix, node] = que.front();
        que.pop();
        if (node->left == nullptr && node->right == nullptr) {
            umap[static_cast<char>(node->ch)] = prefix;
            continue;
        }
        if (node->left != nullptr) {
            que.push(std::make_pair(prefix + "0", node->left));
        }
        if (node->right != nullptr) {
            que.push(std::make_pair(prefix + "1", node->right));
        }
    }
    base = root;
}

string huffman::cal(const string &str) const {
    string will_return{};
    for (const auto ch: str) {
        if (umap.count(ch) == 0) {
            throw std::runtime_error(ch + " character do not be inited");
        }
        will_return += umap.at(ch);
    }
    return will_return;
}

string huffman::decal(const string &serilize) const {
    string will_return{};
    const TreeNode *root = base;
    for (const auto ch: serilize) {
        if (ch == '0') {
            root = root->left;
        } else if (ch == '1') {
            root = root->right;
        }
        if (root->left == nullptr && root->right == nullptr) {
            will_return += static_cast<char>(root->ch);
            root = base;
        }
    }
    return will_return;
}

huffman::~huffman() {
    for (auto &node: del) {
        delete node;
    }
}


}
