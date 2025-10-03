// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO

#include <catch_main.hpp>
#include <vector>
#include <iostream>
#include "main.cpp"

std::string getFilePath() noexcept { return "./../../../lab_00/lab_00_C/resource/"; }

const std::string CS203_redirect::file_paths = getFilePath();

namespace lab_00_C {

using std::cin;
using std::cout;
using std::vector;

using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;
/*
 * Test case 1 -> Test case 5
 * 目的是为了展示只使用CS203_redirect的情况下
 * 应该如何只重定向输入,不重定向输出.
 * */
TEST_CASE("test case 1", "[test 00 C]") {
    const CS203_redirect cr{"01.data.in", ""};
    // 重定向开始,开始run
    const auto output_data = isBipartite(read());
    // 重定向结束
    CHECK_FALSE(output_data);
}

TEST_CASE("test case 2", "[test 00 C]") {
    const  CS203_redirect cr{"02.data.in"};
    const auto output_data = isBipartite(read());
    CHECK(output_data);
}

TEST_CASE("test case 3", "[test 00 C]") {
    const CS203_redirect cr{"03.data.in"};
    const auto output_data = isBipartite(read());
    CHECK(output_data);
}

TEST_CASE("test case 4", "[test 00 C]") {
    const  CS203_redirect cr{"04.data.in"};
    const auto output_data = isBipartite(read());
    CHECK_FALSE(output_data);
}

TEST_CASE("test case 5", "[test 00 C]") {
    const  CS203_redirect cr{"05.data.in"};
    const auto output_data = isBipartite(read());
    CHECK_FALSE(output_data);
}
/*目的在于展示,使用循环来精简Test case1~5中的工作量*/
TEST_CASE("test case in loop", "[test 00 C]") {
    const vector<string> strs{
            "01.data.in", "02.data.in",
            "03.data.in", "04.data.in",
            "05.data.in"
    };
    const vector<uint8_t> result{false, true, true, false, false};
    for (int i = 0; i < 5; ++i) {
        const  CS203_redirect cr{strs[i]};
        const auto output_data = isBipartite(read());
        CHECK(output_data == result[i]);
    }
}
/*目的在于展示,std::tuple的打包能力*/
TEST_CASE("test case with tuple", "[test 00 C]") {
    const vector<std::tuple<string, output_type>> input_result{
            {"01.data.in", false},
            {"02.data.in", true},
            {"03.data.in", true},
            {"04.data.in", false},
            {"05.data.in", false}
    };
    for (const auto &tup: input_result) {
        string path;
        output_type result;
        tie(path, result) = tup;
        const CS203_redirect cr{path};
        const auto output_data = isBipartite(read());
        CHECK(output_data == result);
    }
}
/* 目的在于展示 CS203_sequence 生成重定向相关文件名的能力
 * */
TEST_CASE("test case with sequence", "[test 00 C]") {

    CS203_sequence sequence{1, 5, 2};
    // 前缀被默认设定为 空串 ""
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
