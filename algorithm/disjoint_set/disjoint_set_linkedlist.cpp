//
// Created by nanos on 2021/11/9.
//

#include "disjoint_set_linkedlist.hpp"
#include <catch_main.hpp>
#include <iostream>
#include <cstddef>

namespace disjoint_set {
namespace linkedlist {
using std::string;
using std::cout, std::endl;

class djset_linkedlist;

class djset_linkedlist : public base<djset_linkedlist> {
    struct node : public node_base {
        node *next{};
        djset_linkedlist *tohead;

        node(size_t v, node *next, djset_linkedlist *tohead) : node_base(v), next(next), tohead(tohead) {}

        node(size_t v, djset_linkedlist *tohead) : node(v, nullptr, tohead) {}
    };

    size_t length{1};
public:
    node *head, *tail;

    djset_linkedlist() : head(nullptr), tail(nullptr) {}

public:
    static djset_linkedlist *make_set(size_t x) {
        auto *const will_return = new djset_linkedlist();
        node *const one = new node{x, nullptr, will_return};
        will_return->head = one;
        will_return->tail = one;
        return will_return;
    }

    static djset_linkedlist *unio(djset_linkedlist *fst, djset_linkedlist *snd) {
        const auto fst_size{fst->length}, snd_size{snd->length};
        if (fst_size > snd_size) {
            return unio(snd, fst);
        }
        for (node *sndhead = snd->head; sndhead != nullptr;) {
            sndhead->tohead = fst;
            sndhead = sndhead->next;
        }
        node *fst_tail = fst->tail;
        fst->tail->next = snd->head;
        fst->tail = snd->tail;
        fst->length += snd->length;
        snd->length = 0;
        snd->head = nullptr;
        snd->tail = nullptr;
        return fst;
    }

    /**
     * 要先获取到node,才能拿到其首部node,可见完全没用
     * */
    static node *find_set(const node &x) {
        djset_linkedlist *djset = x.tohead;
        return djset->head;
    }

    ~djset_linkedlist() {
        for (node *hea = this->head; hea != nullptr;) {
            const auto will_delete{hea};
            hea = hea->next;
            will_delete->next = nullptr;
            delete will_delete;
        }
        this->head = nullptr;
        this->tail = nullptr;
    }
};

TEST_CASE("djset_linkedlist test base") {
    auto fst = base<djset_linkedlist>::make_set(1);
    auto snd = base<djset_linkedlist>::make_set(2);
    auto union1 = base<djset_linkedlist>::unio(fst, snd);
    for (auto *head = union1->head; head != nullptr; head = head->next) {
        CHECK(head->tohead == union1);
    }
    delete fst;
    delete snd;
}

TEST_CASE("djset_linkedlist test 1") {
    auto fst = djset_linkedlist::make_set(1);
    auto snd = djset_linkedlist::make_set(2);
    auto third = djset_linkedlist::make_set(3);
    auto fourth = djset_linkedlist::make_set(4);
    auto fifth = djset_linkedlist::make_set(5);
    auto union1 = djset_linkedlist::unio(fst, snd);
    auto union2 = djset_linkedlist::unio(third, fourth);
    auto union3 = djset_linkedlist::unio(union2, fifth);
    auto union4 = djset_linkedlist::unio(union1, union3);
    for (auto *head = union4->head; head != nullptr; head = head->next) {
        CHECK(head->tohead == union4);
    }
    delete fst;
    delete snd;
    delete third;
    delete fourth;
    delete fifth;
    const auto x = 1;
}
}
}