// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO

#include <catch_main.hpp>
#include "cache_base.hpp"
#include <array>
#include <memory>

namespace cache::no {
using std::array;

class no_cache final : public cache_base {
public:
    explicit no_cache(size_t) : cache_base(0) {}

    bool exists(size_t) const override { return false; }

    bool read(size_t) override { return false; }
};

static constexpr const std::array<const char *const, 8> pairs{
        "sample.data.in",
        "1.data.in",
        "2.data.in",
        "3.data.in",
        "4.data.in",
        "5.data.in",
        "6.data.in",
        "7.data.in",
};

TEST_CASE("no test sample") {
    for (const auto &file_name: pairs) {
        const CS203_redirect cr{file_name};
        const auto input = inputs::read_input();
        const std::unique_ptr<cache_base> cache = std::make_unique<no_cache>(input.cacheSize);
        size_t hits{0};
        for (const auto iter: input.querys) {
            const auto exist = cache->read(iter);
            hits += exist;
        }
        CHECK(0 == hits);
    }
}

}
#endif
