// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds

#include "package.hpp"

namespace dp_package {

namespace zero_one {
template<allow_unfull T>
int64_t Package::solve() const {
    const auto thing_size = things.size();
    vector<vector<int64_t>> dp;
    // dp[i][j] 前i件商品, j总容积量下的最大money
    if constexpr (T == allow_unfull::UN_ALLOW) {
        dp = vector<vector<int64_t >>(thing_size + 1, vector<int64_t>(full + 1, 0));
    } else {
        dp = vector<vector<int64_t >>(thing_size + 1, vector<int64_t>(full + 1, -0x3f3f3f3f));
    }
    for (int64_t i{1}; i <= full; i++) {
        dp[0][i] = -0x3f3f3f3f; // 无论怎样, 前0种无法装满任何有量的背包
    }
    for (size_t i{0}; i <= thing_size; i++) {
        dp[i][0] = 0; // 无论怎样,0量的背包可以被0个物体组合装满
    }
    for (size_t i{1}; i <= thing_size; i++) {
        for (int64_t j{1}; j <= full; j++) {
            dp[i][j] = std::max(dp[i - 1][j], dp[i][j]);
            const auto cost{things[i - 1].cost}, money{things[i - 1].money};
            if (j >= cost) {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j - cost] + money);
            }
        }
    }
    if constexpr (T == allow_unfull::UN_ALLOW) {
        return dp.back().back();
    } else {
        return *std::max_element(std::cbegin(dp.back()), std::cend(dp.back()));
    }
}

template<allow_unfull T>
int64_t Package::solveSaveSpace() const {
    const auto thing_size = things.size();
    vector<int64_t> lastLine, nowLine;
    // dp[i][j] 前i件商品, j总容积量下的最大money
    if constexpr (T == allow_unfull::UN_ALLOW) {
        lastLine = vector<int64_t>(full + 1, 0);
        nowLine = vector<int64_t>(full + 1, 0);
    } else {
        lastLine = vector<int64_t>(full + 1, -0x3f3f3f3f);
        nowLine = vector<int64_t>(full + 1, -0x3f3f3f3f);
    }
    for (int64_t i{1}; i <= full; i++) {
        lastLine[i] = -0x3f3f3f3f; // 无论怎样, 前0种无法装满任何有量的背包
    }
    for (size_t i{0}; i <= thing_size; i++) {
        lastLine[0] = 0;
        nowLine[0] = 0;// 无论怎样,0量的背包可以被0个物体组合装满
    }
    for (size_t i{1}; i <= thing_size; i++) {
        for (int64_t j{1}; j <= full; j++) {
            nowLine[j] = std::max(lastLine[j], nowLine[j]);
            const auto cost{things[i - 1].cost}, money{things[i - 1].money};
            if (j >= cost) {
                nowLine[j] = std::max(nowLine[j], lastLine[j - cost] + money);
            }
        }
        std::swap(lastLine, nowLine);
    }
    if constexpr (T == allow_unfull::UN_ALLOW) {
        return std::max(lastLine.back(), static_cast<int64_t>(0));
    } else {
        return *std::max_element(std::cbegin(lastLine), std::cend(lastLine));
    }
}

void pack(vector<int64_t> &line, int64_t ful, const something &thing) {
    const auto cost{thing.cost}, money{thing.money};
    for (int64_t j{ful}; j >= cost; j--) {
        if (j >= cost) {
            line[j] = std::max(line[j], line[j - cost] + money);
        }
    }
}

template<allow_unfull T>
int64_t Package::solveOneLine() const {
    const auto thing_size = things.size();
    const auto ful = this->full;
    vector<int64_t> line;
    // dp[i][j] 前i件商品, j总容积量下的最大money
    line = vector<int64_t>(ful + 1, -0x3f3f3f3f);
    line[0] = 0;
    for (size_t i{1}; i <= thing_size; i++) {
        zero_one::pack(line, ful, things[i - 1]);
    }
    if constexpr (T == allow_unfull::UN_ALLOW) {
        return std::max(line.back(), static_cast<int64_t>(0));
    } else {
        return *std::max_element(std::cbegin(line), std::cend(line));
    }
}
}

namespace complete {
template<allow_unfull T>
int64_t Package::solve() const {
    const auto things_size{things.size()};
    vector<size_t> parts(things_size, 0);
    vector<something> thingsList{};
    for (size_t i{0}; i < things_size; i++) {
        const auto cost{things[i].cost}, money{things[i].money};
        parts[i] = full / cost + ((full % cost) != 0);
        for (size_t j{1}; j <= parts[i]; j++) {
            thingsList.emplace_back(j * cost, j * money);
        }
    }
    const zero_one::Package package{thingsList, full};
    return package.solveOneLine<T>();
}

template<allow_unfull T>
int64_t Package::solve2() const {
    const auto things_size{things.size()};
    vector<size_t> parts(things_size, 0);
    vector<something> thingsList{};
    for (size_t i{0}; i < things_size; i++) {
        const auto cost{things[i].cost};
        parts[i] = full / cost + ((full % cost) != 0);
    }
    for (size_t i{0}; i < things_size; i++) {
        const auto iCost{things[i].cost}, iMoney{things[i].money};
        for (size_t j{0}; j < i; j++) {
            const auto jCost{things[j].cost}, jMoney{things[j].money};
            if (iCost <= jCost && iMoney >= jMoney) {
                parts[j] = 0;
            }
        }
    }
    for (size_t i{0}; i < things_size; i++) {
        const auto cost{things[i].cost}, money{things[i].money};
        for (size_t j{1}; j <= parts[i]; j++) {
            thingsList.emplace_back(j * cost, j * money);
        }
    }
    const zero_one::Package package{thingsList, full};
    return package.solveOneLine<T>();
}

template<allow_unfull T>
int64_t Package::solveBinary() const {
    const auto things_size{things.size()};
    vector<size_t> parts(things_size, 0);
    for (size_t i{0}; i < things_size; i++) {
        const auto cost{things[i].cost};
        parts[i] = full / cost;
    }
    static constexpr const auto divideNumToVec = [](int32_t n) {
        vector<int32_t> numbers;
        numbers.reserve(31);
        for (size_t i{0}; i <= 30; i++) {
            if (n > 0) {
                n /= 2;
                numbers.push_back(1 << i);
            }
        }
        return numbers;
    };
    vector<something> thingsList{};
    for (size_t i{0}; i < things_size; i++) {
        const auto iCost{things[i].cost}, iMoney{things[i].money};
        const vector<int32_t> binaries{divideNumToVec(parts[i])};
        for (const auto binary: binaries) {
            thingsList.emplace_back(binary * iCost, binary * iMoney);
        }
    }
    const zero_one::Package package{thingsList, full};
    return package.solveOneLine<T>();
}

void pack(vector<int64_t> &line, int64_t ful, const something &thing) {
    const auto cost{thing.cost}, money{thing.money};
    for (int64_t v{cost}; v <= ful; v++) {
        line[v] = std::max(line[v], line[v - cost] + money);
    }
}

template<allow_unfull T>
int64_t Package::solveComplete() const {
    const auto things_size{things.size()};
    vector<int64_t> line(this->full + 1, -0x3f3f3f3f);
    line[0] = 0;
    for (size_t i{0}; i < things_size; i++) {
        complete::pack(line, this->full, things[i]);
    }
    if constexpr (T == allow_unfull::UN_ALLOW) {
        return std::max(line.back(), static_cast<int64_t>(0));
    } else {
        return *std::max_element(std::cbegin(line), std::cend(line));
    }
}
}

}
