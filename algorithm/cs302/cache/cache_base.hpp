// SPDX-License-Identifier: AGPL-3.0-or-later
/*  algorithm_template
    Copyright (C) 2022-2024  nanoseeds
*/
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_CACHE_CACHE_BASE_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_CACHE_CACHE_BASE_HPP

#include <cstdint>
#include <cstddef>
#include <string>
#include <utility>
#include <vector>
#include <class_helper/nonable.hpp>

namespace cache {
class cache_base : protected nonCopyMoveAble {
protected:
    const size_t cache_size;
public:
    explicit cache_base(size_t x = 0) : cache_size(x) {};

    virtual bool exists(size_t value) const = 0;

    virtual bool read(size_t value) = 0;

    virtual ~cache_base() = default;
};
}
struct inputs {
    const size_t cacheSize{};
    const vector<int32_t> querys;

    inputs(size_t cacheSize, vector<int32_t> querys) :
            cacheSize(cacheSize), querys(std::move(querys)) {}

    static inputs read_input() {
        size_t cache_size{0};
        size_t query_numbers{0};
        vector<int32_t> query_pages{};
        cin >> cache_size >> query_numbers;
        query_pages.reserve(query_numbers);
        int32_t temp_number;
        for (size_t i{0}; i < query_numbers; ++i) {
            cin >> temp_number;
            query_pages.push_back(temp_number);
        }
        return inputs{cache_size, query_pages};
    }
};

std::string getFilePath() noexcept {
    return "./../../../../algorithm/cs302/cache/data/";
}

const std::string CS203_redirect::file_paths = getFilePath();
#endif //ALGORITHM_TEMPLATE_ALGORITHM_CACHE_CACHE_BASE_HPP
