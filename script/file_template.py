#!/usr/bin/env python3
# coding=utf-8
"""

SPDX-License-Identifier: AGPL-3.0-or-later

SPDX-FileCopyrightText: 2020-2025 nanoseeds
"""

import os
import time
from typing import List

main_code_template: str
test_code_template: str
file_header_template: str
level1_cmake_template: str
level2_cmake_template: str
test_cmake_template: str
USER: str = 'nanoseeds'  # replace it with your user name # example: nanoseeds
year: str = time.strftime('%Y', time.localtime())
main_cmake_path: str = './../CMakeLists.txt'


def read_file(file_name: str) -> str:
    will_return: str
    with open(file_name, mode='r', encoding='UTF-8') as template:
        will_return = template.read()
    return will_return


def fill_file(lab_number: str, problem_order: str) -> None:
    with open(f'./../lab_{lab_number}/lab_{lab_number}_{problem_order}/main.cpp', mode='a+',
              encoding='UTF-8') as file:
        file.write(file_header_template.format(year, USER))
        file.write(main_code_template.format(lab_number, problem_order))
    print('main finish')
    with open(f'./../lab_{lab_number}/lab_{lab_number}_{problem_order}/test.cpp',
              mode='a+', encoding='UTF-8') as file:
        file.write(file_header_template.format(year, USER))
        file.write(test_code_template.format(lab_number, problem_order))
    print('test finish')


def try_mkdir(lab_number: str, problem_orders: List[str]) -> None:
    if not os.path.exists(f'./../lab_{lab_number}'):
        os.mkdir(f'./../lab_{lab_number}')
    for problem_order in problem_orders:
        if not os.path.exists(f'./../lab_{lab_number}/lab_{lab_number}_{problem_order}/'):
            os.mkdir(f'./../lab_{lab_number}/lab_{lab_number}_{problem_order}/')
            os.mkdir(f'./../lab_{lab_number}/lab_{lab_number}_{problem_order}/resource/')


def copy_cmakeLists(lab_number: str, problem_list: List[str]) -> None:
    problem_order_list_str: str = " ".join(problem_list)
    with open(f'./../lab_{lab_number}/CMakeLists.txt', mode='a+', encoding='UTF-8') as file:
        file.write(level1_cmake_template.format(lab_number, problem_order_list_str))
    for problem_order in problem_list:
        with open(f'./../lab_{lab_number}/lab_{lab_number}_{problem_order}/CMakeLists.txt',
                  mode='a+', encoding='UTF-8') as file:
            file.write(level2_cmake_template.format(problem_order))


def main() -> None:
    labs: List[str] = ['welcome', '02', '03', '04', '05', '06',
                       '07', '08', '09', '10', 'bonus']
    problem_order: List[str] = ['A', 'B', 'C', 'D', 'E', 'F']
    labs: List[str] = ['01']
    # problem_order: List[str] = ['A', 'B', 'C',
    #                                 'D', 'E', 'F', 'G', 'H', 'I', 'J']
    for i in labs:
        try_mkdir(i, problem_order)
        copy_cmakeLists(i, problem_order)  # prepare CMakeLists
        for j in problem_order:
            fill_file(i, j)  # 为 lab_${i}/lab_${i}_${j} 创建文件
        with open(f'./../lab_{i}/.gitattributes', mode='a+', encoding='UTF-8') as attr:
            attr.write("* linguist-vendored")
    print('produce files finish')
    print(f"{len(labs) * (len(problem_order) + 1) * 2} files is produced")


# range in [begin,end)
if __name__ == '__main__':
    file_header_template = read_file('file_header.txt')
    main_code_template = read_file('cpp_template.txt')
    test_code_template = read_file('cpp_test_template.txt')
    level1_cmake_template = read_file('cmake_level1_template.txt')
    level2_cmake_template = read_file('cmake_level2_template.txt')
    main()
