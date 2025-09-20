// SPDX-License-Identifier: AGPL-3.0-or-later
/*  algorithm_template
    Copyright (C) 2020-2023  nanoseeds
*/
#include <vector>
#include <iostream>
#include <algorithm>

#ifdef CS203_DSAA_TEST_MACRO
namespace trd_20200610 {
#endif

using std::cin;
using std::cout;
using std::vector;
static constexpr const char end{'\n'};

using num_t = int32_t;

int main() {
    int32_t temp{0}, result{0}, n{0};
    std::cin >> n;
    for (int i = 1; i < n; ++i) {
        if (i * (i + 1) >= 2 * n) {
            temp = i - 1;
            break;
        }
    }
    for (int j = 1; j <= temp; ++j) {
        result += j * j;
    }
    result += (n - temp * (temp + 1) / 2) * (temp + 1);
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
#ifdef CS203_DSAA_TEST_MACRO
}
#endif
