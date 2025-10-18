//
// Created by nanos on 2021/12/8.
//

#ifndef ALGORITHM_TEMPLATE_INCLUDE_TREE_TRIE_TRIE_HPP
#define ALGORITHM_TEMPLATE_INCLUDE_TREE_TRIE_TRIE_HPP

#include <tree/trie_base.hpp>
#include <array>
#include <cstring>
#include <string>
#include <unordered_set>

using std::string;

namespace trie {
using std::unordered_set;
using trieBase::TrieTemplate;

struct trie : public TrieTemplate {
private:
    unordered_set<string> uset{};
public:
    trie() = default;

    void insert(const string &word) override {
        uset.insert(word);
    }

    bool search(const string &word) const override {
        return uset.find(word) != std::end(uset);
    }

    bool startsWith(const string &prefix) const override {
        return
                std::any_of(std::cbegin(uset), std::cend(uset), [& prefix](const auto &item) {
                    return prefix.size() <= item.size() && memcmp(item.c_str(), prefix.c_str(), prefix.size()) == 0;
                });
    }
};
}
namespace trieIter {

using std::array;
using trieIterBase::TrieTemplate;

struct trie : public TrieTemplate {
    static constexpr const size_t array_size{26};

    class Node final {
    public:
        uint8_t self, isfinish;
        std::array<Node *, array_size> sons{nullptr};

        explicit Node(uint8_t self_, uint8_t finish) : self(self_), isfinish(finish) {}

        ~Node() {
            for (size_t i{0}; i < array_size; i++) {
                delete sons[i];
                sons[i] = nullptr;
            }
        }
    };

    std::array<Node *, array_size> sons{nullptr};
public:
    trie() = default;

    ~trie() {
        for (size_t i{0}; i < array_size; i++) {
            delete sons[i];
        }
    }

    void insert(string::const_iterator cb, string::const_iterator ce) override {
        std::array<Node *, 26> *array = &sons;
        for (; cb != ce - 1; cb++) {
            const auto ch = *cb - 'a';
            if ((*array)[ch] == nullptr) {
                (*array)[ch] = new Node(ch, false);
            }
            array = &(*array)[ch]->sons;
        }
        {
            const auto ch = *cb - 'a';
            if ((*array)[ch] == nullptr) {
                (*array)[ch] = new Node(ch, false);
            }
            (*array)[ch]->isfinish = true;
        }
    }

    bool search(string::const_iterator cb, string::const_iterator ce) const override {
        const std::array<Node *, 26> *array = &sons;
        uint8_t isfinish{false};
        for (; cb != ce; cb++) {
            const auto ch = *cb - 'a';
            if ((*array)[ch] == nullptr) {
                return false;
            }
            isfinish = (*array)[ch]->isfinish;
            array = &(*array)[ch]->sons;
        }
        return isfinish;
    }

    bool startsWith(string::const_iterator cb, string::const_iterator ce) const override {
        const std::array<Node *, 26> *array = &sons;
        for (; cb != ce; cb++) {
            const auto ch = *cb - 'a';
            if ((*array)[ch] == nullptr) {
                return false;
            }
            array = &(*array)[ch]->sons;
        }
        return true;
    }
};
}
namespace trieR {

using std::array;
using trieBase::TrieTemplate;

struct trie : public TrieTemplate {
private:
    trieIter::trie Trie{};
public:
    trie() = default;

    ~trie() = default;

    void insert(const string &word) override {
        return Trie.insert(word.cbegin(), word.cend());
    }

    bool search(const string &word) const override {
        return Trie.search(word.cbegin(), word.cend());
    }

    bool startsWith(const string &prefix) const override {
        return Trie.startsWith(prefix.cbegin(), prefix.cend());
    }
};
}

#endif //ALGORITHM_TEMPLATE_INCLUDE_TREE_TRIE_TRIE_HPP
