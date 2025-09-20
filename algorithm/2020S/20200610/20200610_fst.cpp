// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

#ifdef ALGORITHM_TEST_MACRO
namespace fst_20200610 {
#endif

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::unordered_set;
static constexpr const char end{'\n'};

using num_t = int32_t;

int main() {
    int32_t m, n;
    cin >> m >> n;
    if (m < 0 || n < 0 || m > n || (m == 0 && n == 0)) {
        return 0;
    }
    if (m == 1 & n == 1 || (m == 0 && n == 1)) {
        return 9;
    }
    vector<unordered_set<int32_t>> umap_next = {{0},
                                                {2, 4, 5, 6, 8},
                                                {1, 3, 4, 5, 6, 7, 9},
                                                {2, 4, 5, 6, 8},
                                                {1, 2, 3, 5, 7, 8, 9},
                                                {1, 2, 3, 4, 6, 7, 8, 9},
                                                {1, 2, 3, 5, 7, 8, 9},
                                                {2, 4, 5, 6, 8},
                                                {1, 3, 4, 5, 6, 7, 9},
                                                {2, 4, 5, 6, 8}
    };
    vector<unordered_set<int32_t>> umap_next_2 = {
            {0},
            {2, 4, 5},
            {5},
            {2, 5, 6},
            {5},
            {},
            {5},
            {4, 5, 8},
            {5},
            {5, 6, 8}
    };
    vector<vector<int32_t>> sequence;
    for (int i = 1; i <= 9; ++i) {
        sequence.push_back({i});
    }
    int result = 0;
    for (int j = 1; j < n; ++j) {
        if (j >= m) {
            result += sequence.size();
        }
        vector<vector<int32_t>> temp;
        for (const auto &i: sequence) {
            int32_t last_one = i.back();
            unordered_set<int32_t> can_add(umap_next[last_one]);
            for (size_t k = 0; k < i.size() - 1; ++k) {
                if (umap_next[last_one].count(i[k])) {
                    can_add.erase(i[k]);
                }
            }
            if (i.size() == 2 && i[0] == 4 && i[1] == 7) {
                const int useless = 2;
            }
            for (size_t k = 0; last_one != 5 && k < i.size() - 1; ++k) {
                const int middle_value = 2 * i[k] - last_one;
                if (umap_next_2[last_one].find(i[k]) != umap_next_2[last_one].end()
                    && std::find(i.begin(), i.end(), middle_value) == i.end()
                    && middle_value >= 1 && middle_value <= 9) {
                    can_add.insert(middle_value);
                }
            }
            for (const auto &k: can_add) {
                vector<int32_t> middle(i);
                middle.push_back(k);
                temp.push_back(middle);
            }
        }
        sequence = temp;
    }
    result += sequence.size();
    std::cout << result << end;
    return 0;
}

static const auto faster_streams = [] {
    srand(time(nullptr));
    // use time to init the random seed
    std::ios::sync_with_stdio(false);
    std::istream::sync_with_stdio(false);
    std::ostream::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // 关闭c++风格输入输出 , 与C风格输入输出的同步,提高性能.
    return 0;
}();
#ifdef ALGORITHM_TEST_MACRO
}
#endif
