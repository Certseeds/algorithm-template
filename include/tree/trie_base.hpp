//
// Created by nanos on 2021/12/8.
//

#ifndef ALGORITHM_TEMPLATE_INCLUDE_TREE_TRIE_BASE_HPP
#define ALGORITHM_TEMPLATE_INCLUDE_TREE_TRIE_BASE_HPP

#include <string>
#include <unordered_set>
#include <class_helper/nonable.hpp>

namespace trieBase {
struct TrieTemplate : private nonCopyMoveAble {
protected:
    TrieTemplate() = default;

public:

    virtual void insert(const string &) = 0;

    virtual bool search(const string &) const = 0;

    virtual bool startsWith(const string &)const  = 0;
};
}

namespace trieIterBase {
struct TrieTemplate : private nonCopyMoveAble {
protected:
    TrieTemplate() = default;

public:
    virtual void insert(string::const_iterator cb, string::const_iterator ce) = 0;

    virtual bool search(string::const_iterator cb, string::const_iterator ce) const = 0;

    virtual bool startsWith(string::const_iterator cb, string::const_iterator ce) const = 0;
};
}
#endif //ALGORITHM_TEMPLATE_INCLUDE_TREE_TRIE_BASE_HPP
