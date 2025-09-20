// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-05-23 11:01:42
 * @LastEditors  : nanoseeds
 */
#include <iostream>
#include <string>

using namespace std;

//Make a template out of the prototype
template<typename T>
T Max(T one, T two);

int main() {
    int i_one = 3, i_two = 5;
    cout << "The max of " << i_one << " and " << i_two << " is "
         << Max<int>(i_one, i_two) << endl;
//Test your template on float and string types
    double double_one = 5.6f, double_two = 7.3f;
    cout << "The max of " << double_one << " and " << double_two << " is "
         << Max<double>(double_one, double_two) << endl;
    string str_one = "donkey", str_two = "apple";
    cout << "The max of " << str_one << " and " << str_two << " is "
         << Max<string>(str_one, str_two) << endl;
    return 0;
}

template<typename T>
T Max(T one, T two) {
    T biggest;
    if (one < two) {
        biggest = two;
    } else {
        biggest = one;
    }
    return biggest;
}
