// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <cstdint>
#include <iostream>
#include <queue>
#include <algorithm>
#include <array>

static constexpr const std::array<const char *const, 5> command2{"PUSH", "TOP", "POP", "SIZE", "CLEAR"};

int32_t main() {
    size_t t{0};
    std::cin >> t;
    for (size_t i{0}; i < t; ++i) {
        std::queue<int32_t> que;
        size_t q{0};
        std::cin >> q;
        for (size_t j{0}; j < q; ++j) {
            std::string com;
            int number;
            std::cin >> com;
            switch (std::distance(command2.begin(),
                                  std::find(command2.begin(), command2.end(), com)
            )) {
                case 1: {
                    std::cin >> number;
                    que.push(number);
                    break;
                }
                case 2: {
                    if (que.empty()) {
                        std::cout << -1 << std::endl;
                    } else {
                        std::cout << que.front() << std::endl;
                    }
                    break;
                }
                case 3: {
                    if (que.empty()) {
                        std::cout << -1 << std::endl;
                    } else {
                        que.pop();
                    }
                    break;
                }
                case 4: {
                    std::cout << que.size() << std::endl;
                    break;
                }
                case 5: {
                    que = std::queue<int32_t>();
                    break;
                }
            }
        }
    }
    return 0;
}
