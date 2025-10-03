// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO

#include <tuple>
#include <vector>
#include <cstdint>
#include <iostream>
#include <catch_main.hpp>
#include "main.cpp"

std::string getFilePath() noexcept { return "./../../../../../algorithm/2021F/lab_02/lab_02_E/resource/"; }

const std::string CS203_redirect::file_paths = getFilePath();

namespace lab_02_E {

using std::tie;
using std::cin;
using std::cout;
using std::tuple;
using std::vector;

using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;

TEST_CASE("test case 1", "[test 02 E]") {
    const vector<int32_t> A{1, 3, 5, 7, 9};
    const vector<int32_t> B{2, 4, 6, 8, 10};
    const vector<std::pair<int32_t, int32_t>> pairs{{5, 5},
                                                    {1, 5}};
    const auto output_data = cal(std::make_tuple(A, B, pairs));
    CHECK_THAT(output_data, Equals<int>({6, 4}));
}

TEST_CASE("test case with sequence", "[test 02 E]") {
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
#endif //ALGORITHM_TEST_MACRO
