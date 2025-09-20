// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO

#include <numeric>
#include <unordered_map>
#include <cstddef>
#include <vector>
#include <string>
#include <cmath>

namespace leetcode_399 {
using std::unordered_map;
using std::string;
using std::vector;
#endif

namespace disjoint_set_weight {
// 节点之间是一张 有向无环图
class disjoint_set final {
private:
    std::vector<size_t> fa; // 记录father
    std::vector<double_t> weights; // 记录子节点
public:
    explicit disjoint_set(size_t size) : fa(vector<size_t>(size + 1, -1)),
                                         weights(vector<double_t>(size + 1, static_cast<double_t>(1.0f))) {
        // 0号元素弃用
        // from 1 to ${size}
        // value is 1 to ${size}
        std::iota(fa.begin(), fa.end(), 0);
    }

    size_t find(size_t x) {
        if (this->fa[x] != x) {
            const auto faorigin{fa[x]};
            this->fa[x] = find(faorigin);
            weights[x] *= weights[faorigin];
        }
        return this->fa[x];
    }

    void merge(size_t x, size_t y, double value) {
        const auto xfa = find(x),
                yfa = find(y);
        if (xfa == yfa) {
            return;
        }
        fa[xfa] = yfa;
        weights[xfa] = weights[y] * value / weights[x];
        // 此处 weights[y] => y到yfa的weight
        // value => x到y的weight
        // weights[x] => x到x fa的weight
        // 由于不能出现矛盾, `x => xfa => yfa` === `x => y => yfa`
        // 因此可求得 x的father的weights
    }

    double findWeight(size_t x) {
        this->find(x);
        return weights[x];
    }
};
}

class Solution {
public:
    vector<double> calcEquation(const vector<vector<string>> &equations, const vector<double> &values,
                                const vector<vector<string>> &queries) {
        unordered_map<string, size_t> str_to_num{};
        for (const auto &pair: equations) {
            for (const auto &str: pair) {
                if (str_to_num.count(str) == 0) {
                    str_to_num.emplace(str, str_to_num.size() + 1);
                }
            }
        }
        disjoint_set_weight::disjoint_set dset(str_to_num.size());
        for (size_t i{0}; i < equations.size(); i++) {
            const auto &pair = equations[i];
            const auto first{str_to_num[pair[0]]},
                    second{str_to_num[pair[1]]};
            dset.merge(first, second, values[i]);
        }
        vector<double_t> results(queries.size(), -1);
        for (size_t i{0}; i < queries.size(); i++) {
            const auto &query{queries[i]};
            const auto &first{query[0]}, second{query[1]};
            if (str_to_num.count(first) == 0 || str_to_num.count(second) == 0) {
                continue;
            }
            const auto firstNum{str_to_num[first]},
                    secondNum{str_to_num[second]};
            if (dset.find(firstNum) != dset.find(secondNum)) {
                continue;
            }
            if (firstNum == secondNum) {
                results[i] = 1.0f;
                continue;
            }
            auto multiOne{dset.findWeight(firstNum)},
                    multiTwo{dset.findWeight(secondNum)};
            results[i] = multiOne / multiTwo;
        }

        return results;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
