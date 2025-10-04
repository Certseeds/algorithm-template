// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO

#include <catch_main.hpp>
#include <tuple>
#include <vector>
#include <cstdint>
#include <iostream>
#include "main.cpp"

std::string getFilePath() noexcept { return "./../../../../../algorithm/2021F/lab_02/lab_02_C/resource/"; }

const std::string CS203_redirect::file_paths = getFilePath();

namespace lab_02_C {

using std::tie;
using std::cin;
using std::cout;
using std::tuple;
using std::vector
    ;
// 用wolframalpha 计算的 xe^(x/20)= b
TEST_CASE("test case 1", "[test 02 C]") {
    const Catch::Approx target = Catch::Approx(0.9534862518).epsilon(0.01);
    CHECK(cal_detail(1) == target);
    const Catch::Approx target2 = Catch::Approx(
            257.40091767269424137944971165126822636856843117329338741172807922).epsilon(0.01);
    CHECK(cal_detail(std::pow(10, 8)) == target2);
}
// 因为[.],所以下面这个被隐藏了,确保需要重定向输入输出时,请删除`[.]`
// 此处因为输出为 "一个范围",不适合进行直接比对输出
TEST_CASE("test case with sequence", "[test 02 C][.]") {
    CS203_sequence sequence{1, 0, 0}; // // 基础设定,[1,1]
    sequence.set_postfix_of_datain("data.in"); // 输入数据后缀,默认为 data.in
    sequence.set_postfix_of_dataout("data.out"); // except输出数据后缀,默认为 data.out
    sequence.set_postfix_of_testout("test.out"); // 测试输出数据后缀,默认为 test.out
    const auto files_name = sequence.get_files(true);
    // 获取一个std::tuple<string,string,string> ,
    // 其中每个tuple内为 `输入数据`,`except输出数据`,`测试输出数据`名.
    for (const auto &file_name: files_name) {
        string datain, dataout, testout; // 声明
        tie(datain, dataout, testout) = file_name; // 解包
        {
            const CS203_redirect cr{datain, testout}; // 重定向输入,输出
            main();
            // 用括号括住是为了让CS203_redirect在这里被析构,停止重定向
        }
        CHECK(compareFiles(testout, dataout));
    }
}
}
#endif //ALGORITHM_TEST_MACRO
