// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds

#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

#ifdef ALGORITHM_TEST_MACRO
namespace fourth_20200511{
#endif

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::unordered_set;
static constexpr const char end{'\n'};

using num_t = int32_t;

int main() {
    string init;
    int32_t number;
    cin >> init;
    cin >> number;
    int32_t command{0};
    unordered_set<char> uset;
    int32_t first{0};
    for (int32_t i{0}; i < number; ++i) {
        cin >> command;
        cin >> first;
        switch (command) {
            case 1: {
                char second;
                cin >> second;
                init[first - 1] = second;
                break;
            }
            case 2: {
                int32_t second;
                cin >> second;
                for (int j = first - 1; j < second; ++j) {
                    uset.insert(init[j]);
                }
                cout << uset.size() << "\n";
                uset.clear();
                break;
            }
            default: {
                return -1;
            }
        }
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
#ifdef ALGORITHM_TEST_MACRO
}
#endif
