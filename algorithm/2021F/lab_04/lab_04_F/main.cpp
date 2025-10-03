// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds

#include <tuple>
#include <string>
#include <vector>
#include <cstdint>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <ctime>
#include <cstdlib>
#include <utility>

#ifdef ALGORITHM_TEST_MACRO
namespace lab_04_F {
#endif

using std::cin;
using std::tie;
using std::cout;
using std::tuple;
using std::string;
using std::vector;

static constexpr const char end{'\n'};

using num_t = int32_t;

struct Operation {
    int type; // 1: Insert, 2: Find, 3: Transform
    char ch; // used for Insert
    num_t p; // used for Insert/Find
    num_t l, r; // used for Transform
};

using input_type = std::tuple<string, vector<Operation> >;
using output_type = string;

inline input_type read();

output_type cal(const input_type &data);

void output(const output_type &data);

// Implicit Treap with lazy "invert" ('a' + 'z' - c) on range
struct Node {
    char ch;
    uint32_t prio;
    int sz;
    bool flip; // lazy invert flag
    Node *l, *r;
};

static vector<Node> node_pool;
static int pool_ptr = 0;

inline uint32_t rng() {
    static uint32_t x = uint32_t(time(nullptr)) ^ 0x9e3779b9U;
    // xorshift32
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return x;
}

inline Node *newNode(char c) {
    Node &n = node_pool[pool_ptr++];
    n.ch = c;
    n.prio = rng();
    n.sz = 1;
    n.flip = false;
    n.l = n.r = nullptr;
    return &n;
}

inline int size(Node *t) { return t ? t->sz : 0; }

inline char invert_char(char c) {
    // Defined: 'a' + 'z' - c
    return char('a' + 'z' - c);
}

inline void apply_inv(Node *t) {
    if (!t) return;
    t->flip ^= true;
    t->ch = invert_char(t->ch);
}

inline void push(Node *t) {
    if (!t || !t->flip) return;
    t->flip = false;
    if (t->l) apply_inv(t->l);
    if (t->r) apply_inv(t->r);
}

inline void upd(Node *t) {
    if (!t) return;
    t->sz = 1 + size(t->l) + size(t->r);
}

Node *merge(Node *a, Node *b) {
    if (!a) return b;
    if (!b) return a;
    if (a->prio < b->prio) {
        push(a);
        a->r = merge(a->r, b);
        upd(a);
        return a;
    } else {
        push(b);
        b->l = merge(a, b->l);
        upd(b);
        return b;
    }
}

// split t into [a (size=k), b]
void split(Node *t, int k, Node *&a, Node *&b) {
    if (!t) {
        a = b = nullptr;
        return;
    }
    push(t);
    int ls = size(t->l);
    if (k <= ls) {
        split(t->l, k, a, t->l);
        upd(t);
        b = t;
    } else {
        split(t->r, k - ls - 1, t->r, b);
        upd(t);
        a = t;
    }
}

char kth(Node *t, int k) {
    Node *cur = t;
    while (cur) {
        push(cur);
        int ls = size(cur->l);
        if (k == ls + 1) return cur->ch;
        if (k <= ls) cur = cur->l;
        else {
            k -= ls + 1;
            cur = cur->r;
        }
    }
    return '\0';
}

// Build treap from string in O(n) using Cartesian tree with priorities
Node *build_from_string(const string &s) {
    if (s.empty()) return nullptr;

    vector<Node *> st;
    st.reserve(64); // small initial reserve

    for (size_t i = 0; i < s.size(); ++i) {
        Node *cur = newNode(s[i]);
        Node *last = nullptr;
        while (!st.empty() && st.back()->prio > cur->prio) {
            last = st.back();
            st.pop_back();
        }
        cur->l = last;
        if (!st.empty()) st.back()->r = cur;
        st.push_back(cur);
    }
    Node *root = st.front();

    // Compute sizes recursively (expected stack depth O(log n))
    // Avoids large auxiliary vectors
    struct Helper {
        static int dfs(Node *t) {
            if (!t) return 0;
            int ls = dfs(t->l);
            int rs = dfs(t->r);
            t->sz = 1 + ls + rs;
            return t->sz;
        }
    };
    Helper::dfs(root);
    return root;
}

int main() {
    auto input_data = read();
    const auto output_data = cal(input_data);
    output(output_data);
    return 0;
}

inline input_type read() {
    string S;
    cin >> S;
    int n;
    cin >> n;
    vector<Operation> ops;
    ops.reserve(n);
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        Operation op{};
        op.type = t;
        if (t == 1) {
            char ch;
            num_t p;
            cin >> ch >> p;
            op.ch = ch;
            op.p = p;
        } else if (t == 2) {
            num_t p;
            cin >> p;
            op.p = p;
        } else {
            // t == 3
            num_t l, r;
            cin >> l >> r;
            op.l = l;
            op.r = r;
        }
        ops.push_back(op);
    }
    return std::make_tuple(S, ops);
}

output_type cal(const input_type &data) {
    string S;
    vector<Operation> ops;
    tie(S, ops) = data;

    // Pre-allocate pool: initial size + number of inserts
    size_t insert_cnt = 0;
    for (size_t i = 0; i < ops.size(); ++i) if (ops[i].type == 1) ++insert_cnt;
    node_pool.clear();
    node_pool.resize(S.size() + insert_cnt + 8); // small safety margin
    pool_ptr = 0;

    Node *root = build_from_string(S);

    string out;
    out.reserve(ops.size() * 2);

    for (const auto & op : ops) {
        if (op.type == 1) {
            // Insert(ch, p): insert before position p (1-based). p can be size+1 to append
            int p = op.p;
            if (p < 1) p = 1;
            int cur_sz = size(root);
            if (p > cur_sz + 1) p = cur_sz + 1;
            Node *L, *R;
            split(root, p - 1, L, R);
            Node *M = newNode(op.ch);
            root = merge(merge(L, M), R);
        } else if (op.type == 2) {
            // Find(p): 1-based
            int p = op.p;
            char c = kth(root, p);
            out.push_back(c);
            out.push_back(end);
        } else {
            // Transform(l, r): invert chars in range [l, r]
            int l = op.l, r = op.r;
            if (l > r) continue;
            l = std::max(l, 1);
            r = std::min(r, size(root));
            if (l > r) continue;
            Node *A, *B, *C;
            split(root, l - 1, A, B);
            split(B, r - l + 1, B, C);
            apply_inv(B);
            root = merge(A, merge(B, C));
        }
    }

    return out;
}

void output(const output_type &data) {
    cout << data;
}

static const auto faster_streams = [] {
    srand(time(nullptr));
    // use time to init the random seed
    std::ios::sync_with_stdio(false);
    std::istream::sync_with_stdio(false);
    std::ostream::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // 关闭c++风格输入输出 , 与C风格输入输出的同步,提高性能.
    return 0;
}();

#ifdef ALGORITHM_TEST_MACRO
}
#endif
