/*
 * @Author: nanoseeds
 * @Date: 2020-07-15 21:44:06
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-01-03 21:46:26
 */
// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifndef ALGORITHM_TEMPLATE_INCLUDE_INCLUDE_PUBLIC_HPP
#define ALGORITHM_TEMPLATE_INCLUDE_INCLUDE_PUBLIC_HPP

#include <string>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include "CS203_helper.hpp"
#include "CS203_timer.hpp"
#include "CS203_redirect.hpp"
#include "CS203_sequence.hpp"

using std::ios;
using std::cin;
using std::cout;

inline bool compareFiles(std::string p1, std::string p2) {
    p1 = CS203_redirect::file_paths + p1;
    p2 = CS203_redirect::file_paths + p2;
    // get from https://stackoverflow.com/questions/6163611/compare-two-files
    std::ifstream f1(p1, std::ifstream::binary | std::ifstream::ate);
    std::ifstream f2(p2, std::ifstream::binary | std::ifstream::ate);
    if (f1.fail() || f2.fail()) {
        return false; //file problem
    }
    if (f1.tellg() != f2.tellg()) {
        std::cout << p1 << " not match " << p2 << '\n';
        std::cout << f1.tellg() << " " << f2.tellg() << '\n';
        return false; //size mismatch
    }
    //seek back to beginning and use std::equal to compare contents
    f1.seekg(0, std::ifstream::beg);
    f2.seekg(0, std::ifstream::beg);
    return std::equal(std::istreambuf_iterator<char>(f1.rdbuf()),
                      std::istreambuf_iterator<char>(),
                      std::istreambuf_iterator<char>(f2.rdbuf()));
}

#endif //ALGORITHM_TEMPLATE_INCLUDE_INCLUDE_PUBLIC_HPP
