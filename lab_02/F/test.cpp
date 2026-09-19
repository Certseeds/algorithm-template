// SPDX-License-Identifier: Apache-2.0
// SPDX-FileCopyrightText: 2020-2026 USER
#ifdef ALGORITHM_TEST_MACRO

#include <gtest_main.hpp>
#include <tuple>
#include <vector>
#include <cstdint>
#include <cstddef>
#include <iostream>

#include "main.cpp"

std::string getFilePath() noexcept { return "./../../../lab_02/F/resource/"; }
const std::string CS203_redirect::file_paths = getFilePath();

namespace lab_02_F {

using std::tie;
using std::cin;
using std::cout;
using std::tuple;
using std::vector;

TEST(lab_02_F, test_case_1) {
    const auto output_data = cal(std::make_tuple(114, 514));
    EXPECT_EQ(output_data, 628);
    EXPECT_EQ(1 + 2, 3);
    vector<int32_t> vec{2, 7, 11, 15};
    EXPECT_THAT(vec, ::testing::Contains(2));
    EXPECT_THAT(vec, ::testing::UnorderedElementsAre(15, 11, 7, 2));
}
TEST(lab_02_F, test_case_with_sequence) {
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
        EXPECT_TRUE(compareFiles(testout, dataout));
    }
}
}
#endif //ALGORITHM_TEST_MACRO
