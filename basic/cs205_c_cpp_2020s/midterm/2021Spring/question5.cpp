/*
 * @Github: https://github.com/Certseeds
 * @Date: 2021-04-16 00:50:12
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-04-16 13:25:55
 */
// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
/*
腾讯后台笔试题(不晚于2018).
画家小Q又开始他的艺术创作。小Q拿出了一块有NxM像素格的画板, 画板初始状态是空白的,用'X'表示。

小Q有他独特的绘画技巧,每次小Q会选择一条斜线,
 如果斜线的方向形如'/',即斜率为1,小Q会选择这条斜线中的*一段*格子,都涂画为蓝色,用'B'表示;
 如果对角线的方向形如'\',即斜率为-1,小Q会选择这条斜线中的一段格子,都涂画为黄色,用'Y'表示。
如果一个格子既被蓝色涂画过又被黄色涂画过,那么这个格子就会变成绿色,用'G'表示。
 重点: 只是一段格子
小Q已经有想画出的作品的样子, 请你帮他计算一下他最少需要多少次操作完成这幅画。
 * */
namespace question5 {
using namespace std;
enum class Color : uint8_t {
    X,// init
    B, Y, G,
};
using input_type = vector <vector<Color>>;
using output_type = int32_t;

input_type readNumber() {
    unordered_map<uint8_t, Color> umap{{{'B', Color::B}, {'Y', Color::Y}, {'G', Color::G}, {'X', Color::X}}};
    size_t x{0}, y{0};
    uint8_t pixel;
    std::cin >> x >> y;
    vector <vector<Color>> board(x, vector<Color>(y));
    for (size_t i{0}; i < x; i++) {
        for (size_t j{0}; j < y; j++) {
            std::cin >> pixel;
            board[i][j] = umap.at(pixel);
        }
    }
    return board;
}

output_type count(input_type input) {
    const int32_t row = static_cast<int32_t>(input.size()), col = static_cast<int32_t>(input.front().size());
    const unordered_set<Color> uset_b{Color::B, Color::G};
    const unordered_map<Color, Color> umap_b{{{Color::B, Color::X}, {Color::G, Color::Y}}};
    const unordered_set<Color> uset_y{Color::Y, Color::G};
    const unordered_map<Color, Color> umap_y{{{Color::Y, Color::X}, {Color::G, Color::B}}};
    output_type sum{0};
    for (int32_t i{0}; i < row; i++) {
        for (int32_t j{0}; j < col; j++) {
            if (uset_y.count(input[i][j]) != 0) {
                int32_t i2{i}, j2{j};
                sum++;
                while (i2 < row && j2 < col && uset_y.count(input[i2][j2]) != 0) {
                    input[i2][j2] = umap_y.at(input[i2][j2]);
                    i2++;
                    j2++;
                }
            }
            if (uset_b.count(input[i][j]) != 0) {
                int32_t i2{i}, j2{j};
                sum++;
                while (i2 < row && 0 <= j2 && uset_b.count(input[i2][j2]) != 0) {
                    input[i2][j2] = umap_b.at(input[i2][j2]);
                    i2++;
                    j2--;
                }
            }
        }
    }
    return sum;
}

void output(int32_t num) {
    std::cout << num << std::endl;
}

int main() {
    input_type number{readNumber()};
    output_type will_return{count(number)};
    output(will_return);
    return 0;
}
}
#ifndef CS205_C_CPP_MIDTERM_2021SPRING

int main() {
    return question5::main();
}

#endif
