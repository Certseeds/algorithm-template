// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-04-20 08:50:41
 * @LastEditors  : nanoseeds
 */
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

int32_t recieve_input();

int32_t question5();

std::string str_lower(std::string str);

std::string trim(std::string str);

// commands
static constexpr const char *const command[]{"start", "stop", "restart", "reload", "status", "exit"};
static constexpr const int32_t exit_n = 5;
static constexpr const int32_t illegal = 6;
