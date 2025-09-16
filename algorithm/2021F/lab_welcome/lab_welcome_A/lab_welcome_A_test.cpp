// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <catch_main.hpp>
#include <tuple>
#include <vector>
#include <cstdint>
#include <iostream>

#include "lab_welcome_A.cpp"

std::string getFilePath() noexcept { return "./../../../../../algorithm/2021F/lab_welcome/lab_welcome_A/resource/"; }

const std::string CS203_redirect::file_paths = getFilePath();

namespace lab_welcome_A {

using std::tie;
using std::cin;
using std::cout;
using std::tuple;
using std::vector;

using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;

TEST_CASE("test case 1", "[test welcome A]") {
    const auto output_data = cal(
            std::make_tuple(std::unordered_set<int32_t>{2, 3, 999999, 1}, std::vector<int32_t>{3, 99}));
    CHECK_THAT(output_data, Equals<TRUE_FALSE>({TRUE_FALSE::YES, TRUE_FALSE::NO}));
}

TEST_CASE("test case with sequence", "[test welcome A]") {
    CS203_sequence sequence{1, 1, 0}; // // 基础设定,[1,1]
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
#endif //CS203_DSAA_TEST_MACRO
