// SPDX-License-Identifier: AGPL-3.0-or-later
/*  algorithm_template
    Copyright (C) 2020-2023  nanoseeds
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#ifdef CS203_DSAA_TEST_MACRO
namespace snd_20200511 {
#endif

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::unordered_map;
static constexpr const char end{'\n'};
static constexpr const int32_t yushu{835672545};
using num_t = int32_t;

int main() {
    string ari;
    int32_t dir_size{0};
    cin >> ari;
    cin >> dir_size;
    vector<string> dir(dir_size);
    for (auto &i: dir) {
        cin >> i;
    }

    const int32_t ari_size = ari.size();
    std::sort(std::begin(dir), std::end(dir),
              [](const string &str1, const string &str2) { return str1.size() < str2.size(); });
    int32_t will_return{0};
    unordered_map<int32_t, int32_t> now;
    unordered_map<int32_t, int32_t> next;
    now.insert(std::make_pair(0, 1));
    while (!now.empty()) {
        for (const auto &i: now) {
            if (i.first == ari_size) {
                will_return += i.second;
                will_return %= yushu;
            }
            const string &temp_str(ari.substr(i.first));
            for (const auto &j: dir) {
                if (temp_str.size() < j.size()) {
                    break;
                }
                if (temp_str.substr(0, j.size()) == j) {
                    next[i.first + j.size()] += now[i.first];
                }
            }
        }
        now = std::move(next);
        next = unordered_map<int32_t, int32_t>();
        will_return %= yushu;
    }
    cout << will_return << end;
    cout.flush();
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
#ifdef CS203_DSAA_TEST_MACRO
}
#endif
