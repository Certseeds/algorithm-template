// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds

#include <string>
#include <vector>
#include <iostream>
#include <deque>

#ifdef ALGORITHM_TEST_MACRO
namespace fst_20200511{
#endif

using std::cin;
using std::cout;
using std::string;
using std::vector;
static constexpr const char end{'\n'};

using num_t = int32_t;

int main() {
    int32_t c_n{0}, command{0};
    string init, str;
    int32_t size_1;
    cin >> c_n;
    std::deque<string> deq_s;
    for (int32_t i{0}; i < c_n; ++i) {
        cin >> command;
        switch (command) {
            case 1: {
                cin >> str;
                deq_s.push_back(init);
                init += str;
                break;
            }
            case 2: {
                cin >> size_1;
                deq_s.push_back(init);
                init = init.substr(0, init.size() - size_1);
                break;
            }
            case 3: {
                cin >> size_1;
                cout << init[size_1 - 1] << end;
                break;
            }
            case 4: {
                init = deq_s.back();
                deq_s.pop_back();
                break;
            }
            default: {
                return -1;
            }
        }
    }
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
#ifdef ALGORITHM_TEST_MACRO
}
#endif
