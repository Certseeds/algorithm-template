// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_DP_PACKAGE_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_DP_PACKAGE_HPP

#include <cstddef>
#include <cstdint>
#include <utility>
#include <vector>
#include <class_helper/nonable.hpp>

namespace dp_package {

struct something final {
    something(int64_t cost, int64_t money) : cost(cost), money(money) {};
    const int64_t cost, money;
};

enum class allow_unfull : bool {
    ALLOW = true, // 必须放满
    UN_ALLOW = false // 不必须放满
};
namespace zero_one {

using std::vector;

struct Package final : private nonCopyMoveAble {
private:
    const vector<something> things; // 物品
    const int64_t full; // 容积
public:
    Package(const vector<something> &things, int64_t maxV) : things(things), full(maxV) {}

    template<allow_unfull T>
    [[nodiscard]] int64_t solve() const; // 最普通解法

    template<allow_unfull T>
    [[nodiscard]] int64_t solveSaveSpace() const; // O(n)空间优化

    template<allow_unfull T>
    [[nodiscard]] int64_t solveOneLine() const; // 更彻底的空间优化
};
}

namespace complete {
using std::vector;

struct Package final : private nonCopyMoveAble {
private:
    const vector<something> things;
    const int64_t full;
public:
    Package(const vector<something> &things, int64_t maxV) : things(things), full(maxV) {}

    template<allow_unfull T>
    [[nodiscard]] int64_t solve() const; // 最普通解法
    template<allow_unfull T>
    [[nodiscard]] int64_t solve2() const; // O(N^2) 去掉不经济的物品

    template<allow_unfull T>
    [[nodiscard]] int64_t solveBinary() const; // O(N^2) 拆分常数化,最多31种

    template<allow_unfull T>
    [[nodiscard]] int64_t solveComplete() const;
};

}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_DP_PACKAGE_HPP
