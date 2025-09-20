// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-04-20 08:50:41
 * @LastEditors  : nanoseeds
 */
#include "Assignment_4_05.hpp"

int32_t question5() {
    while (true) {
        std::cout << "<";
        // switch
        int32_t temp = recieve_input();
        // std::cout << temp << std::endl;
        switch (temp) {
            case exit_n: {
                std::cout << "exit" << std::endl;
                return 0;
            }
            case illegal: {
                std::cout << "Invalid command" << std::endl;
                break;
            }
            default: {
                std::cout << "command " << command[temp] << " recognized" << std::endl;
                break;
            }
        }
    }
    return 0;
}

int32_t recieve_input() {
    // recieve input and return order.
    std::string input;
    std::cin >> input;
    input = trim(input);
    input = str_lower(input);
    return std::distance(std::cbegin(command), std::find(std::cbegin(command), std::cend(command), input));
}

// 给分的时候,虽然没写要处理大小写,但是还是扣分了.
// PS: argue回来了
std::string str_lower(std::string str) {
    for (auto &item: str) {
        if (item >= 'A' && item <= 'Z') {
            item = item - ('A' - 'a');
        }
    }
    return str;
}

std::string trim(std::string str) {
    // delete spaces
    if (str.empty()) {
        return str;
    }
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1);
    return str;
}
