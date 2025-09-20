// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-04-02 19:52:38
 * @LastEditors  : nanoseeds
 */
#include <iostream>

struct box {
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void Cal_by_val(box box_in);

void Cal_by_val(box *box_in);

void Display(const box &box_in);

int main() {
    box box1{"ShanDong University", 11.4f, 51.4f, 19.19f, 0.0f};
    box box2{"JinNan College", 20.0f, 26.0f, 18.0f, 0.0f};
    std::cout << "Before setting valume by value" << std::endl;
    Display(box1);
    std::cout << "Before setting valume by address" << std::endl;
    Display(box2);
    Cal_by_val(box1);
    Cal_by_val(&box2);
    std::cout << "After setting valume by value" << std::endl;
    Display(box1);
    std::cout << "After setting valume by address" << std::endl;
    Display(box2);
    return 0;
}

void Cal_by_val(box box_in) {
    box_in.volume = box_in.height * box_in.width * box_in.length;
}

void Cal_by_val(box *box_in) {
    box_in->volume = (box_in->height) * (box_in->width) * (box_in->length);
}

void Display(const box &box_in) {
    std::cout << "Maker: " << box_in.maker << std::endl;
    std::cout << "Height: " << box_in.height << std::endl;
    std::cout << "Width: " << box_in.width << std::endl;
    std::cout << "Length: " << box_in.length << std::endl;
    std::cout << "Volume: " << box_in.volume << std::endl;
}
