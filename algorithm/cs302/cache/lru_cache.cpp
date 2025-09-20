// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO

#include <catch_main.hpp>
#include "cache_base.hpp"
#include <array>
#include <limits>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <memory>

/**case 4
4
13
4 3 2 1 4 3 5 4 3 2 1 5 4
4,3,2,1四个都缓存不命中,队列现在为1,2,3,4
4,命中,4,1,2,3
3,命中,3,4,1,2
5,不命中,5,3,4,1
4,命中,4,5,3,1
3,命中,3,4,5,1
2,不命中,2,3,4,5
1,不命中,1,2,3,4
5,不命中,5,1,2,3
5,不命中,4,5,1,2
 * */
namespace cache::lru {
using std::array;
static constexpr const std::array<const std::pair<size_t, const char *const>, 8> pairs{
        {
                {1, "sample.data.in"},
                {4, "4.data.in"},
                {3, "5.data.in"},
                {5, "6.data.in"},
                {1, "7.data.in"},
                {1176, "1.data.in"},
                {11847, "2.data.in"},
                {82394, "3.data.in"},
        }};
namespace On {

class lru_cache final : public cache_base {
private:
    std::list<size_t> lru;
    std::unordered_set<size_t> uset;
public:
    explicit lru_cache(size_t size = 0) : cache_base(size) {}

    bool exists(size_t page) const override {
        return uset.find(page) != uset.end();
    }

    bool read(size_t page) override {
        const auto result = std::find(std::begin(lru), std::end(lru), page);
        const auto judge = (result != std::end(lru));
        if (judge) {
            lru.erase(result);
            lru.push_front(page);
        } else {
            if (lru.size() == cache_size) {
                lru.pop_back();
                uset.erase(lru.back());
            }
            lru.push_front(page);
            uset.insert(page);
        }
        return judge;
    }
};

TEST_CASE("lru test sample") {
    for (const auto&[result, file_name]: pairs) {
        const CS203_redirect cr{file_name};
        const auto input = inputs::read_input();
        const auto cache = std::make_unique<lru_cache>(input.cacheSize);
        size_t hits{0};
        for (const auto iter: input.querys) {
            const auto exist = cache->read(iter);
            hits += exist;
        }
        CHECK(result == hits);
    }
}
}
namespace O1 {

class lru_cache final : public cache_base {
private:
    struct Node final : private nonCopyMoveAble {
        const size_t v;
        Node *before{nullptr};
        Node *next{nullptr};

        Node(size_t v, Node *before, Node *next) : v(v), before(before), next(next) {}
    };

    Node head{std::numeric_limits<size_t>::max(), nullptr, nullptr};
    std::unordered_map<size_t, Node *> umap;
public:
    explicit lru_cache(size_t size = 1) : cache_base(size) {
        CHECK(size != 0);
        this->head.next = &(this->head);
        this->head.before = &(this->head);
    }

    bool exists(size_t page) const override {
        return umap.count(page) != 0; // equal,
    }

    bool read(size_t page) override {
        if (this->exists(page)) {
            Node *const ptr = umap[page];
            // step1,摘出
            {
                Node *const pnext = ptr->next;
                Node *const pbefore = ptr->before;
                pbefore->next = pnext;
                pnext->before = pbefore;
            }
            // step2,接续
            {
                Node *const snd = head.next;
                head.next = ptr;
                snd->before = ptr;
                ptr->next = snd;
                ptr->before = &head;
            }
            return true;
        } else {
            if (umap.size() == this->cache_size) {
                Node *const last = head.before;
                Node *const last_snd = last->before;
                last_snd->next = &head;
                head.before = last_snd;
                umap.erase(last->v);
                delete last;
            }
            Node *const fst = new Node(page, &head, head.next);
            head.next->before = fst;
            head.next = fst;
            umap[page] = fst;
            return false;
        }
    }

    ~lru_cache() override {
        for (const auto&[k, v]: umap) {
            delete v;
        }
    }
};

TEST_CASE("lru-2 test sample") {
    for (const auto&[result, file_name]: pairs) {
        const CS203_redirect cr{file_name};
        const auto input = inputs::read_input();
        const std::unique_ptr<cache_base> cache = std::make_unique<lru_cache>(input.cacheSize);
        size_t hits{0};
        for (const auto iter: input.querys) {
            const auto exist = cache->read(iter);
            hits += exist;
        }
        CHECK(result == hits);
    }
}
}
}
#endif
