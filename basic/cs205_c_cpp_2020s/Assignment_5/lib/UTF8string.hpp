// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-04-26 17:58:29
 * @LastEditors  : nanoseeds
 */
#ifndef CS205_C_CPP_ASSIGNMENT_5_SRC_UTF8STRING_HPP
#define CS205_C_CPP_ASSIGNMENT_5_SRC_UTF8STRING_HPP


#include <iostream>
#include <string>
#include <vector>

#include "utf8.hpp"

using std::string;

class UTF8string {
private:
    string str;
public:
    [[nodiscard]] const string &get_str() const;

    // Constructor
    // if add explicit ,need use .replace(UTF8string("1"),UTF8string("2"))
    UTF8string(const char *ch);

    // 拷贝构造函数 Copy Constructor
    UTF8string(const UTF8string &s);

    // 移动构造函数
    UTF8string(UTF8string &&s) noexcept;

    //Copy Assignment operator
    UTF8string &operator=(const UTF8string &) = delete;

    //Move Assignment operator
    UTF8string &operator=(UTF8string &&data) = delete;


    int32_t length();

    int32_t bytes();

    int32_t find(const string &substr);

    int32_t replace(const UTF8string &to_remove, const UTF8string &replacement);

    UTF8string operator+(const UTF8string &str1) const;

    UTF8string operator*(int32_t times);

    friend UTF8string operator*(int32_t times, UTF8string &str);

    UTF8string &operator+=(const UTF8string &str1);

    friend std::ostream &operator<<(std::ostream &output, const UTF8string &str);

    UTF8string operator!();

};


#endif //CS205_C_CPP_ASSIGNMENT_5_SRC_UTF8STRING_HPP
