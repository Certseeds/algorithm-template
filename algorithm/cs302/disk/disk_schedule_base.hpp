// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_DISK_SCHEDULE_BASE_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_DISK_SCHEDULE_BASE_HPP

#include <cstdint>
#include <cstddef>
#include <utility>
#include <vector>
#include <class_helper/nonable.hpp>

namespace disk_schedule {
using std::vector;

class disk_base : protected nonCopyMoveAble {
protected:
    const size_t S, M, N;
    const vector<size_t> requests;
protected:
    vector<size_t> steps{};
    size_t distance{0};
public:
    explicit disk_base(size_t S, size_t M, size_t N, vector<size_t> requests) :
            S(S), M(M), N(N), requests(std::move(requests)) {};

    virtual const char *name() const = 0;

    void output() const {
        //std::cout << this->name() << '\n';
        for (auto iter = steps.cbegin(); iter != steps.cend() - 1; ++iter) {
            cout << *iter << ' ';
        }
        std::cout << steps.back() << '\n';
        std::cout << distance << '\n';
    }

    virtual ~ disk_base() = default;
};
}
struct inputs {
    const size_t S, M, N{};
    const vector<size_t> requests;

    inputs(size_t S, size_t M, size_t N, vector<size_t> requests) : S(S), M(M), N(N), requests(std::move(requests)) {}

    static inputs read_input() {
        size_t S, M, N{0};
        std::cin >> S >> M >> N;
        vector<size_t> requests(N);
        for (size_t i{0}; i < N; ++i) {
            std::cin >> requests[i];
        }
        return inputs{S, M, N, requests};
    }
};

std::string getFilePath() noexcept {
    return "./../../../../algorithm/cs302/disk/data/";
}

const std::string CS203_redirect::file_paths = getFilePath();
#endif //ALGORITHM_TEMPLATE_ALGORITHM_DISK_SCHEDULE_BASE_HPP
