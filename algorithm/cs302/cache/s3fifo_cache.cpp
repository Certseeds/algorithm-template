// SPDX-License-Identifier: AGPL-3.0-or-later
/*  algorithm_template
    Copyright (C) 2024  nanoseeds
*/
#ifdef CS203_DSAA_TEST_MACRO

#include <catch_main.hpp>
#include <memory>
#include <queue>
#include "cache_base.hpp"

namespace cache::s3fifo {
using std::array;
static constexpr const std::array<const std::pair<size_t, const char *const>, 8> pairs{
        {
                {1, "sample.data.in"},
                {4, "4.data.in"},
                {1, "5.data.in"},
                {4, "6.data.in"},
                {0, "7.data.in"},
                {1110, "1.data.in"},
                {11873, "2.data.in"},
                {82132, "3.data.in"},
                // 这种大规模数据集对比lru只差一点点, 性能很好.
                // 更贴合实际的数据集应该能更好.
        }
};

namespace Origin {
// algorithm come from
// https://blog.jasony.me/system/cache/2023/08/01/s3fifo
class fifo_cache final {
public:
    std::deque<std::pair<size_t, uint8_t>> fifo{};
    size_t max_size{0};

    explicit fifo_cache(size_t size) {
        max_size = std::max(size_t(1), size);
    }

    bool exists_const(size_t page) const {
        const auto pointer = std::find_if(std::begin(fifo), std::end(fifo),
                                          [page](const std::pair<size_t, uint8_t> &pair) {
                                              return pair.first == page;
                                          });
        return pointer != std::end(fifo);
    }

    bool exists(size_t page) {
        const auto pointer = std::find_if(std::begin(fifo), std::end(fifo),
                                          [page](const std::pair<size_t, uint8_t> &pair) {
                                              return pair.first == page;
                                          });
        if (pointer == std::end(fifo)) {
            return false;
        }
        pointer->second = std::min(3, pointer->second + 1);
        return true;
    }

    bool isFull() const {
        return fifo.size() == max_size;
    }

    bool isEmpty() const {
        return fifo.empty();
    }

    std::pair<size_t, uint8_t> pop() {
        assert(!fifo.empty());
        const auto result = fifo.front();
        fifo.pop_front();
        return result;
    }

    void insert(size_t page, size_t times) {
        if (!isFull()) {
            fifo.emplace_back(page, times);
        }
    }
};

class s3fifo_cache final : public cache_base {
private:
    fifo_cache small;
    fifo_cache main;
    fifo_cache ghost;

    void insertToSmall(size_t page) {
        if (small.isFull()) {
            evictSmall();
        }
        small.insert(page, 0);
    }

    void insertToMain(size_t page, uint8_t times) {
        if (main.isFull()) {
            evictMain();
        }
        main.insert(page, times);
    }

    void insertToGhost(size_t page) {
        if (!ghost.exists_const(page)) {
            // 直接驱逐最后一个
            if (ghost.isFull()) {
                ghost.pop();
            }
            ghost.insert(page, 0);
        }
    }

    void evictSmall() {
        bool evicted = false;
        while (!evicted && !small.isEmpty()) {
            const auto result = small.pop();
            if (result.second > 1) {
                if (main.isFull()) {
                    evictMain();
                    insertToMain(result.first, 0);
                }
            } else {
                insertToGhost(result.first);
                evicted = true;
            }
        }
    }

    void evictMain() {
        bool evicted = false;
        while (!evicted && !main.isEmpty()) {
            const auto result = main.pop();
            if (result.second > 0) {
                insertToMain(result.first, result.second - 1);
            } else {
                evicted = true;
            }
        }
    }

public:
    explicit s3fifo_cache(size_t page) : cache_base(page), small(page / 10), main(page * 9 / 10),
                                         ghost(page * 9 / 10) {}

    virtual bool exists(size_t value) const override {
        if (small.exists_const(value) || main.exists_const(value)) {
            return true;
        }
        return false;
    }

    // read true if match
    virtual bool read(size_t page) override {
        if (small.exists(page) || main.exists(page)) {
            return true;
        } // cache miss
        if (ghost.exists_const(page)) {
            insertToMain(page, 0);
        } else {
            insertToSmall(page);
        }
        return false;
    }


};

TEST_CASE("fifo test n") {
    for (const auto &[result, file_name]: pairs) {
        const CS203_redirect cr{file_name};
        const auto input = inputs::read_input();
        const auto cache = std::make_unique<s3fifo_cache>(input.cacheSize);
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
