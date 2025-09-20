/**
 * @Author: nanoseeds
 * @Date: 2020-07-24 01:56:19
 * @LastEditors: nanoseeds
 */
// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifndef ALGORITHM_TEMPLATE_INCLUDE_INCLUDE_CS203_REDIRECT_HPP
#define ALGORITHM_TEMPLATE_INCLUDE_INCLUDE_CS203_REDIRECT_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <class_helper/nonable.hpp>

using std::cin;
using std::cout;
using std::string;

class CS203_redirect final : private nonCopyMoveAble {
private:
    std::streambuf *strmin_buf;
    std::streambuf *strmout_buf;
    std::ifstream file_in = std::ifstream();
    std::ofstream file_out = std::ofstream();
public:
    const static string file_paths;

    // default datain is input and testout is output
    explicit CS203_redirect(string datain, string testout = "") {
        string old_path2 = testout;
        datain = file_paths + datain;
        testout = file_paths + testout;
        this->strmin_buf = std::cin.rdbuf();
        this->strmout_buf = std::cout.rdbuf();
        this->file_in.open(datain, std::ios_base::in);
        std::cin.rdbuf(file_in.rdbuf());
        if (!old_path2.empty()) {
            this->file_out.open(testout, std::ios_base::binary | std::ios_base::out);
            std::cout.rdbuf(file_out.rdbuf());
        }
    }

    ~CS203_redirect() {
        std::cout.rdbuf(strmout_buf);
        std::cin.rdbuf(strmin_buf);
        std::cout.flush();
    }
};

#ifndef CS203_DSAA_TEST_MACRO

/* if in this macro, it means it do not belong to ./test/lab_${number}/${x}_test.cpp
   so, it need define file_paths although it maybe do not need that
   to avoid file_paths do not be define before use.
*/
std::string getFilePath() noexcept {
    return "";
}

const std::string CS203_redirect::file_paths = getFilePath();
#endif //CS203_DSAA_TEST_MACRO

#endif //ALGORITHM_TEMPLATE_INCLUDE_INCLUDE_CS203_REDIRECT_HPP
