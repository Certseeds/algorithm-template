// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO

#include <catch_main.hpp>
#include <tuple>
#include <vector>
#include <iostream>

#include "20200511_fst.cpp"

std::string getFilePath() noexcept {
    return "./../../../../algorithm/2020S/20200511/20200511_fst_data/";
}

const std::string CS203_redirect::file_paths = getFilePath();

namespace fst_20200511 {
using std::tie;
using std::cin;
using std::cout;
using std::tuple;
using std::vector;

TEST_CASE("test case with sequence", "[test 02 A]") {
    CS203_sequence sequence{1, 1, 0}; // // 基础设定,[1,1]
    sequence.set_postfix_of_datain("data.in"); // 输入数据后缀,默认为 data.in
    sequence.set_postfix_of_dataout("data.out"); // except输出数据后缀,默认为 data.out
    sequence.set_postfix_of_testout("test.out"); // 测试输出数据后缀,默认为 test.out
    const auto files_name = sequence.get_files(true);
    // 获取一个std::tuple<string,string,string> ,
    // 其中每个tuple内为 `输入数据`,`except输出数据`,`测试输出数据`名.
    for (const auto &file_name: files_name) {
        const auto &[datain, dataout, testout] = file_name;
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
