// SPDX-License-Identifier: AGPL-3.0-or-later
/*  algorithm_template
    Copyright (C) 2020-2023  nanoseeds
*/

#include <vector>
#include <limits>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool check_value(unordered_map<int32_t, int32_t> umap, vector<int32_t> vec1, double value);

int main() {
    int32_t n;
    cin >> n;
    unordered_map<int32_t, int32_t> value_max;
    int32_t max_v = std::numeric_limits<int32_t>::min() / 2;
    for (int32_t i = 0; i < n; ++i) {
        int32_t a;
        int32_t b;
        cin >> a >> b;
        max_v = std::max(max_v, std::max(a, b));
        value_max[a] = std::max(value_max[a], b);
    }
    vector<int32_t> value1;
    value1.reserve(value_max.size());
    for (const auto &i: value_max) {
        value1.push_back(i.first);
    }
    std::sort(value1.begin(), value1.end(), std::less<int32_t>());
    int32_t begin = 0;
    int32_t end = max_v * 2;
    int32_t middle = 0;
    while (begin < end) {
        middle = (end - begin) / 2 + begin;
        bool temp = check_value(value_max, value1, middle);
        cout << middle << " " << temp << endl;
        if (temp) {
            begin = middle + 1;
        } else {
            end = middle;
        }
    }
    cout << middle / 2;
    return 0;
}

bool check_value(unordered_map<int32_t, int32_t> umap, vector<int32_t> vec1, double value) {
    for (int32_t i = vec1.size() - 1; i >= 0; i--) {
        auto order = std::lower_bound(vec1.begin(), vec1.end(), value - vec1[i]);
        if (order == vec1.end()) {
            continue;
        }
        if (i != order - vec1.begin() && umap[vec1[i]] + umap[vec1[order - vec1.begin()]] >= value) {
            return true;
        }
    }
    return false;
}