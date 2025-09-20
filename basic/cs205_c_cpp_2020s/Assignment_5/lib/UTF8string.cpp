// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-04-26 17:58:29
 * @LastEditors  : nanoseeds
 */
#include "UTF8string.hpp"

// Constructor
UTF8string::UTF8string(const char *ch) {
    this->str = string(ch);
}

// 拷贝构造函数 Copy Constructor
UTF8string::UTF8string(const UTF8string &s) {
    this->str = string(s.str);
}

UTF8string::UTF8string(UTF8string &&s) noexcept {
    if (this != &s) {
        this->str = std::move(s.str);
    }
}


// return bytes
int32_t UTF8string::bytes() {
    return str.size();
}

// use
int32_t UTF8string::length() {
    int32_t will_return = 0;
    int32_t bytes_in_char = 0;
    for (uint32_t i = 0; i < str.size(); i += bytes_in_char) {
        utf8_to_codepoint(reinterpret_cast<const unsigned char *>(&str[i]), &bytes_in_char);
        will_return++;
        //  强制类型转换,search and count
    }
    return will_return;
}

int32_t UTF8string::find(const string &sub_str) {
    int32_t will_return = 0;
    int32_t bytes_in_char = 0;
    for (uint32_t i = 0; i <= str.size() - sub_str.size(); i += bytes_in_char) {
        utf8_to_codepoint(reinterpret_cast<const unsigned char *>(&str[i]), &bytes_in_char);
        if (str.substr(i, sub_str.size()) == sub_str) {
            return will_return;
        }
        will_return++;
        //  强制类型转换,search and count
    }
    return -1;
}

int32_t UTF8string::replace(const UTF8string &to_remove, const UTF8string &replacement) {
    int32_t bytes_in_char = 0;
    std::vector<int32_t> positions;
    for (uint32_t i = 0; i <= str.size() - to_remove.str.size(); i += bytes_in_char) {
        utf8_to_codepoint(reinterpret_cast<const unsigned char *>(&str[i]), &bytes_in_char);
        if (str.substr(i, to_remove.str.size()) == to_remove.str) {
            positions.push_back(i);
        }
        //  强制类型转换,search and count
    }
    for (auto it = positions.rbegin(); it != positions.rend(); ++it) {
        this->str.replace(*it, to_remove.str.size(), replacement.str);
    }//逆序遍历
    // return 0 replace成功,return 1,不成功.
    return !positions.empty();
}

std::ostream &operator<<(std::ostream &output, const UTF8string &str) {
    output << str.str;
    return output;
}

UTF8string UTF8string::operator+(const UTF8string &str1) const {
    UTF8string will_return(this->str.c_str());
    will_return.str.append(str1.str);
    return will_return;
}


UTF8string &UTF8string::operator+=(const UTF8string &str1) {
    this->str.append(str1.str);
    return (*this);
}

UTF8string UTF8string::operator*(int32_t times) {
    UTF8string will_return("");
    string temp = this->str;
    for (int32_t i = 0; i < times; ++i) {
        will_return.str.append(temp);
    }
    return will_return;
}

UTF8string operator*(int32_t times, UTF8string &str) {
    return str * times;
}

UTF8string UTF8string::operator!() {
    UTF8string will_return("");
    std::vector<std::pair<int32_t, int32_t>> positions;
    int32_t bytes_in_char = 0;
    for (uint32_t i = 0; i < str.size(); i += bytes_in_char) {
        utf8_to_codepoint(reinterpret_cast<const unsigned char *>(&str[i]), &bytes_in_char);
        positions.emplace_back(i, bytes_in_char);
        //  强制类型转换,search and count
    }
    for (auto it = positions.rbegin(); it != positions.rend(); ++it) {
        will_return.str.append(this->str.substr(it->first, it->second));
    }
    return will_return;
}

const string &UTF8string::get_str() const {
    return this->str;
}
