// SPDX-License-Identifier: AGPL-3.0-or-later
/*  algorithm_template
    Copyright (C) 2020-2023  nanoseeds
*/

#include <string>
#include <vector>
#include <iostream>

#ifdef CS203_DSAA_TEST_MACRO
namespace trd_20200511{
#endif

using std::cin;
using std::cout;
using std::string;
using std::vector;
static constexpr const char end{'\n'};

using num_t = int32_t;

int main() {
    // it just read input
    int32_t n{0}, m{0};
    cin >> n >> m;
    vector<int32_t> c(n), a(m), b(m);
    for (auto &i: c) {
        cin >> i;
    }
    for (int32_t j{0}; j < m; ++j) {
        cin >> a[j] >> b[j];
    }
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
