/**
 * @Author: nanoseeds
 * @Date: 2020/9/19 21:42:36
 * @LastEditors: nanoseeds
 */
// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifndef ALGORITHM_TEMPLATE_INCLUDE_INCLUDE_CS203_SEQUENCE_HPP
#define ALGORITHM_TEMPLATE_INCLUDE_INCLUDE_CS203_SEQUENCE_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <class_helper/nonable.hpp>

using std::cin;
using std::cout;
using std::string;
using std::vector;

class CS203_sequence final : private nonCopyMoveAble {
private:
    std::string prefix_of_file_name{""};
    std::string postfix_of_testout{"test.out"};
    std::string postfix_of_datain{"data.in"};
    std::string postfix_of_dataout{"data.out"};
    int32_t begin{0};
    int32_t end{0};
    int32_t max_length{-1};
public:

    // default path1 is input and path2 is output
    explicit CS203_sequence(int32_t begin, int32_t end, int32_t max_length = -1) : begin(begin), end(end),
                                                                                   max_length(max_length) {}

    void set_prefix_of_filename(const string &prefixOfFileName) {
        prefix_of_file_name = prefixOfFileName;
    }

    void set_postfix_of_testout(const string &postfixOfTestout) {
        postfix_of_testout = postfixOfTestout;
    }

    void set_postfix_of_datain(string postfixOfDatain) {
        postfix_of_datain = std::move(postfixOfDatain);
    }

    void set_postfix_of_dataout(const string &postfixOfDataout) {
        postfix_of_dataout = postfixOfDataout;
    }

    /*
     *     [begin,end]
    */
    vector<string> get_sequence() const {
        vector<string> will_return{};
        for (int32_t i{begin}; i <= end; ++i) {
            will_return.push_back(std::to_string(i));
        }
        return will_return;
    }

    // [begin,end]
    // 默认max_length = -1,即使用end的长度
    // 若max_length != -1,即传入参数,则使用std::max(end长度,max_length)
    vector<string> get_same_length_sequence() const {
        const int32_t max_lengths = std::max(max_length, get_length(end));
        vector<string> will_return = get_sequence();
        for (auto &item: will_return) {
            if (static_cast<int32_t>(item.length()) < max_lengths) {
                item.insert(std::begin(item), max_lengths - item.length(), '0');
            }
        }
        return will_return;
    }

    inline static int32_t get_length(int32_t value) {
        int32_t length = 0;
        while (value > 0) {
            length++;
            value /= 10;
        }
        return length;
    }

    using files_type = vector<std::tuple<std::string, std::string, std::string>>;

    files_type get_files(bool same_length) const {
        const vector<string> sequence = same_length ? get_same_length_sequence() : get_sequence();
        files_type will_return;
        for (const auto &item: sequence) {
            const string datain = prefix_of_file_name + item + "." + postfix_of_datain;
            const string dataout = prefix_of_file_name + item + "." + postfix_of_dataout;
            const string testout = prefix_of_file_name + item + "." + postfix_of_testout;
            will_return.push_back(std::make_tuple(datain, dataout, testout));
        }
        return will_return;
    }
};

#endif //ALGORITHM_TEMPLATE_INCLUDE_INCLUDE_CS203_SEQUENCE_HPP
