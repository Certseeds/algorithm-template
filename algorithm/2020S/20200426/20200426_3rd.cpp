// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <cstdint>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <limits>

int32_t main() {
    int32_t n{0};
    std::cin >> n;
    std::vector<std::pair<int32_t, int32_t>> a;
    std::vector<std::pair<int32_t, int32_t>> b;
    for (int i{0}; i < n; ++i) {
        int x1{0}, x2{0};
        std::cin >> x1 >> x2;
        a.emplace_back(x1, x2);
    }
    for (int i{0}; i < n; ++i) {
        int x1{0}, x2{0};
        std::cin >> x1 >> x2;
        b.emplace_back(x1, x2);
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    double min_value = std::numeric_limits<int32_t>::max() / 2;
    struct compare {
        bool operator()(const std::pair<int, int> &value,
                        const int &key) {
            return (value.first < key);
        }

        bool operator()(const int &key,
                        const std::pair<int, int> &value) {
            return (key < value.first);
        }
    };
    for (const auto &i: a) {
        const auto it = std::upper_bound(b.begin(), b.end(),
                                         i.first, compare()) - b.begin();
        // int order = std::find(b.begin(), b.end(), a.at(j).first) - b.begin();
        for (int l = 0; l < 16; ++l) {
            min_value = std::min(
                    min_value,
                    std::pow((i.first - b.at(std::min(it + l, static_cast<long>(b.size() - 1))).first), 2) +
                    std::pow((i.second - b.at(std::min(it + l, static_cast<long>(b.size() - 1))).second), 2));
            min_value = std::min(
                    min_value,
                    std::pow((i.first - b.at(std::max(it - l, static_cast<long>(0))).first), 2) +
                    std::pow((i.second - b.at(std::max(it - l, static_cast<long>(0))).second), 2));
        }
    }
    printf("%.3f", std::sqrt(min_value));
    return 0;
}
