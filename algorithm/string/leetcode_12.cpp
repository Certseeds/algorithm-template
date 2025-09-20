// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO
#include <string>
#include <array>
#include <vector>
#include <cstdint>
#include <cstddef>
namespace leetcode_12 {
using std::string;
using std::array;
using std::vector;
#endif

class Solution {
public:
    string intToRoman_2(int num) {
        if (num > 1000) {
            return "M" + intToRoman(num - 1000);
        } else if (num > 100) {
            static const array<string, 11> hundres = {
                    "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM", "M"};
            return hundres[num / 100] + intToRoman(num % 100);
        } else if (num > 10) {
            static const array<string, 11> tens = {
                    "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC", "C"};
            return tens[num / 10] + intToRoman(num % 10);
        } else if (num <= 10) {
            static const array<string, 11> ones = {
                    "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X"};
            return ones[num];
        }
        return "should reach there";
    }

    string intToRoman(int num) {
        static const array<string, 11> hundres =
                {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM", "M"};
        static const array<string, 11> tens =
                {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC", "C"};
        static const array<string, 11> ones =
                {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X"};
        string will_return = string((num / 1000), 'M');
        will_return.reserve(sizeof(char) * 16);
        num = num % 1000;
        will_return += hundres[num / 100];
        num = num % 100;
        will_return += tens[num / 10];
        num = num % 10;
        will_return += ones[num];
        return will_return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
