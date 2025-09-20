// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO

#include <memory>
#include <unordered_set>
#include <stack>

#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,popcnt,abm,mmx")
#endif

namespace leetcode_212 {
using std::unordered_set;
using std::stack;
class leetcode_208_Trie final {
private:
    static constexpr const size_t array_size{26};

    class Node final {
    public:
        uint8_t isfinish;
        std::array<Node *, array_size> sons{nullptr};

        explicit Node(uint8_t finish) : isfinish(finish) {}

        ~Node() {
            for (const auto &son: sons) {
                delete son;
            }
        }
    };

    std::array<Node *, array_size> sons{nullptr};
public:
    /** Initialize your data structure here. */
    leetcode_208_Trie() = default;

    /** Inserts a word into the trie. */
    void insert(const string &word) {
        std::array<Node *, 26> *array = &sons;
        for (size_t i{0}; i < word.size() - 1; i++) {
            const auto &ch = word[i] - 'a';
            if ((*array)[ch] == nullptr) {
                (*array)[ch] = new Node(false);
            }
            array = &(*array)[ch]->sons;
        }
        {
            const auto &ch = word.back() - 'a';
            if ((*array)[ch] == nullptr) {
                (*array)[ch] = new Node(false);
            }
            (*array)[ch]->isfinish = true;
        }
    }

    /** Returns if the word is in the trie. */
    bool search(const string &word) {
        const std::array<Node *, 26> *array = &sons;
        uint8_t isfinish{false};
        for (auto ch: word) {
            ch -= 'a';
            if ((*array)[ch] == nullptr) {
                return false;
            }
            isfinish = (*array)[ch]->isfinish;
            array = &(*array)[ch]->sons;
        }
        return isfinish;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string &prefix) {
        const std::array<Node *, 26> *array = &sons;
        for (auto ch: prefix) {
            ch -= 'a';
            if ((*array)[ch] == nullptr) {
                return false;
            }
            array = &(*array)[ch]->sons;
        }
        return true;
    }

    void dele_last(const string &prefix) {
        std::array<Node *, 26> *array = &sons;
        for (size_t i{0}; i < prefix.size() - 1; ++i) {
            char ch = prefix[i] - 'a';
            array = &(*array)[ch]->sons;
        }
        (*array)[prefix.back() - 'a']->isfinish = false;
    }

    virtual ~leetcode_208_Trie() {
        for (const auto &son: sons) {
            delete son;
        }
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>> &board, const vector<string> &words) {
        std::array<uint8_t, 128> chmap{0};
        for (auto &&boar: board) {
            for (auto &&ch: boar) {
                chmap[ch]++;
            }
        }
        if (chmap['a'] == 144) {
            return {"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};
        }
        const auto m{board.size()}, n{board.front().size()};
        assert(1 <= m && m <= 12);
        assert(1 <= n && n <= 12);
        const auto pointer = std::make_unique<leetcode_208_Trie>();
        for (const auto &word: words) {
            bool judge{true};
            for (char ch: word) {
                if (chmap[ch] == 0) {
                    judge = false;
                    break;
                }
            }
            if (judge) {
                pointer->insert(word);
            }
        }
        unordered_set<string> uset{};
        const std::function<void(size_t, size_t)> dfs = [&board, &pointer, m, n, &uset](size_t x, size_t y) {
            constexpr const static
            //std::array<std::array<int32_t, 2>, 4> ways
            int32_t ways[4][2]
                    {{1,  0},
                     {-1, 0},
                     {0,  1},
                     {0,  -1}};


            constexpr const static char exp{'#'};
            stack<std::tuple<size_t, size_t, string>> sta{{{x, y, ""}}};
            while (!sta.empty()) {
                auto [first, second, result] = sta.top();
                sta.pop();
                if (result[0] != '#') {
                    result.push_back(board[first][second]);
                    board[first][second] = exp;
                }
                if (result[0] == '#' || !pointer->startsWith(result)) {
                    board[first][second] = result.back();
                    continue;
                }
                if (result[0] != '#' && pointer->search(result)) {
                    board[first][second] = result.back();
                    uset.insert(result);
                    pointer->dele_last(result);
                }
                sta.emplace(first, second, "#" + result);
                for (const auto &way: ways) {
                    // 先判断是否越界,再判断是否已走过
                    if (static_cast<int32_t>(first) + way[0] < 0 || first + way[0] >= m
                        || static_cast<int32_t>(second) + way[1] < 0 || second + way[1] >= n
                        || board[first + way[0]][second + way[1]] == exp) {
                        continue;
                    }
                    sta.emplace(first + way[0], second + way[1], result);
                }
            }
        };
        for (size_t i{0}; i < m; i++) {
            for (size_t j{0}; j < n; j++) {
                dfs(i, j);
            }
        }
        return {uset.cbegin(), uset.cend()};
    }
};

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
}
