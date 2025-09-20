// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO

#include <cstdint>
#include <cstddef>
#include <vector>
#include <unordered_map>
#include <limits>

namespace leetcode_so_35 {
using std::vector;
using std::unordered_map;

struct Node {
public:
    int val;
    Node *next;
    Node *random;

    explicit Node(int32_t _val) : val(_val), next(nullptr), random(nullptr) {}
};

#endif

class Solution {
public:
    Node *copyRandomList(Node *head) {
        std::unordered_map<std::intptr_t, size_t> umap;
        Node *head2 = head;
        for (size_t i{0}; head2 != nullptr; head2 = head2->next, ++i) {
            umap[reinterpret_cast<std::intptr_t>(head2)] = i;
        }
        const auto length = umap.size();
        vector<size_t> random_map(length);
        Node *head3 = head;
        for (size_t i{0}; head3 != nullptr; head3 = head3->next, ++i) {
            if (head3->random == nullptr) {
                random_map[i] = std::numeric_limits<size_t>::max();
            } else {
                random_map[i] = umap[reinterpret_cast<std::intptr_t>(head3->random)];
            }
        }
        std::vector<Node *> nodes(length);
        Node *head4 = head;
        for (size_t i{0}; head4 != nullptr; head4 = head4->next, ++i) {
            nodes[i] = new Node(head4->val);
        }
        for (size_t i{0}; i + 1 < length; ++i) {
            nodes[i]->next = nodes[i + 1];
        }
        for (size_t i{0}; i < length; ++i) {
            if (random_map[i] != std::numeric_limits<size_t>::max()) {
                nodes[i]->random = nodes[random_map[i]];
            }
        }
        return nodes[0];
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
