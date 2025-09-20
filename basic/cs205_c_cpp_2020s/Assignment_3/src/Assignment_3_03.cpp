// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-04-11 18:54:01
 * @LastEditors  : nanoseeds
 */
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <limits>
#include "utf8.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct unicode_block {
    uint32_t begin;
    uint32_t end;
    char part[100];
};//struct

int32_t sub_main_assignment_3_03();

void string_to_block(string s, unicode_block *bl);

string trim(string str);

int32_t hex_string_to_int32_t(const string &s);

int32_t find_alphabeta(unicode_block *bl, int32_t length_of_blocks, int32_t ch);

static constexpr const int32_t unicode_part_number = 300;
#ifndef UNIT_TESTING_ASSIGNMENT_3
#define UNIT_TESTING_ASSIGNMENT_3

int main() {
    return sub_main_assignment_3_03();
}

#endif // !UNIT_TESTING_ASSIGNMENT_3

int32_t sub_main_assignment_3_03() {
    std::ifstream read_file("./Blocks.txt", std::ios::in);
    string line;
    if (!read_file.is_open()) {
        cout << "Can not find Blocks.txt " << endl;
        read_file.close();
        return -1;
    }//read blocks
    unicode_block blocks[unicode_part_number];
    int32_t chars_count[unicode_part_number];
    //声明变量
    memset(chars_count, 0, unicode_part_number * sizeof(int32_t));
    int32_t block_count = 0;
    while (getline(read_file, line)) {
        if (line.size() <= 1 || '#' == line[0]) {
            continue;
        }
        string_to_block(line, &blocks[block_count]);
        block_count++;
        //读取,跳过或者由string -> struct
    }
    read_file.close();
    string file_content;
    string temp;
    while (!cin.eof()) {
        getline(cin, temp);
        file_content.append(temp);
    }
    // read form stdin
    for (int32_t i{0}, bytes_in_char{0}; i < static_cast<int32_t>(file_content.size()); i += bytes_in_char) {
        int32_t code_point =
                utf8_to_codepoint(reinterpret_cast<const unsigned char *>(&file_content[i]), &bytes_in_char);
        chars_count[find_alphabeta(blocks, block_count, code_point)]++;
        //  强制类型转换,search and count
    }
    int32_t max_v = std::numeric_limits<int32_t>::min() / 2;
    int32_t max_posi = 0;
    for (int i = 0; i < unicode_part_number; ++i) {
        if (chars_count[i] > max_v) {
            max_v = chars_count[i];
            max_posi = i;
        }
    }
    // find max
    cout << blocks[max_posi].part << endl;
    return 0;
}

void string_to_block(string s, unicode_block *bl) {
    string begin = trim(s.substr(0, s.find_first_of('.')));
    string end = trim(s.substr(s.find_last_of('.') + 1, s.find(';') - s.find_last_of('.') - 1));
    string name = trim(s.substr(s.find(';') + 1));
    bl->begin = hex_string_to_int32_t(begin);
    bl->end = hex_string_to_int32_t(end);
    std::memcpy(bl->part, &name[0], name.size());
    // string -> struct values
}

string trim(string str) {
    if (str.empty()) {
        return str;
    }
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1);
    return str;
    // trim
}

int32_t hex_string_to_int32_t(const string &s) {
    int32_t number = 0;
    std::stringstream ss;
    ss << std::hex << s;
    ss >> number;
    return number;
    // use stringstream to hex -> int32_t
}

int32_t find_alphabeta(unicode_block *bl, int32_t length_of_blocks, int32_t ch) {
    for (int32_t i = 0; i < length_of_blocks; ++i) {
        if (bl[i].begin <= static_cast<uint32_t>(ch) && static_cast<uint32_t>(ch) <= bl[i].end) {
            return i;
        }
    }
    // search one by one.
    return -1; // should not reach there.
}
