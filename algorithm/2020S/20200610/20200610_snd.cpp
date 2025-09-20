// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds

#include <vector>
#include <iostream>
#include <algorithm>

#ifdef CS203_DSAA_TEST_MACRO
namespace snd_20200610 {
#endif

using std::cin;
using std::cout;
using std::vector;
static constexpr const char end{'\n'};

using num_t = int32_t;

int main() {
    int32_t n{0}, will_return{0};
    cin >> n;
    vector<int32_t> results;
    bool can{true};
    while (n > 1 && can) {
        can = false;
        for (int i = 9; i >= 2; --i) {
            if (n % i == 0) {
                results.push_back(i);
                n = n / i;
                can = true;
                break;
            }
        }
    }
    if (n > 9) {
        cout << -1 << end;
        return 0;
    }
    std::sort(results.begin(), results.end());
    for (const auto &x: results) {
        will_return *= 10;
        will_return += x;
    }
    cout << will_return << end;
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
