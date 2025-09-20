// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO

#include <catch_main.hpp>
#include "cache_base.hpp"
#include <set>
#include <queue>
#include <memory>
#include <vector>
#include <unordered_set>

namespace cache::min {
using std::array;
static constexpr const std::array<const std::pair<size_t, const char *const>, 8> pairs{
        {
                {2, "sample.data.in"},
                {7, "4.data.in"},
                {5, "5.data.in"},
                {9, "6.data.in"},
                {3, "7.data.in"},
                {4240, "1.data.in"},
                {43265, "2.data.in"},
                {88583, "3.data.in"},
        }};

/**
 * 这是个需要"预知未来"的算法
 * 平均O(logN)算不错的了
 * */
namespace OlogN {
using std::priority_queue, std::unordered_set, std::vector;

class min_cache final : public cache_base {
private:
    struct pn final {
        size_t page, next;

        //按next由大到小排列
        bool operator<(const pn &a) const { return this->next > a.next; }
    };

private:
    const vector<size_t> predict;
    size_t position{0};
    std::multiset<pn> pset{}; // 没想到set充当优先队列这么优秀
    std::unordered_set<size_t> uset{};
private:
    /**
     * Example
     * [1,2,3,4,5,2] && position 1, 所以从2开始搜索,找到下一个2,即第六个位置-5
     */
    size_t getNext(size_t page) {
        position += 1;
        for (size_t i{position}, size{predict.size()}; i < size; i++) {
            if (predict[i] == page) {
                return i;
            }
        }
        return std::numeric_limits<size_t>::max();
    }

public:
    explicit min_cache(size_t size, vector<size_t> pri) : cache_base(size), predict(std::move(pri)) {}

    [[nodiscard]] bool exists(size_t page) const override {
        return std::end(uset) != uset.find(page);
    }

    bool read(size_t page) override {
        if (this->exists(page)) {
            const auto iter = std::find_if(pset.begin(), pset.end(),
                                           [page](const auto &search) { return search.page == page; });
            pset.erase(iter);
            const auto next{this->getNext(page)};
            pset.insert({page, next});
            return true;
        } else {
            if (uset.size() == cache_size) {
                const auto top_iter = pset.cbegin();
                const auto top_v = top_iter->page;
                pset.erase(top_iter);
                uset.erase(top_v);
            }
            const auto next{this->getNext(page)};
            pset.insert({page, next});
            uset.insert(page);
            return false;
        }
    }
};

TEST_CASE("min test 1") {
    for (const auto &[result, file_name]: pairs) {
        const CS203_redirect cr{file_name};
        const auto input = inputs::read_input();
        const auto inputAll = [&input] {
            vector<size_t> vec{};
            vec.reserve(input.querys.size());
            for (const auto ori: input.querys) {
                vec.push_back(ori);
            }
            return vec;
        }();
        const std::unique_ptr<cache_base> cache = std::make_unique<min_cache>(input.cacheSize, inputAll);
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
