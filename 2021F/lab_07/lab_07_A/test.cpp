// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO

#include <catch_main.hpp>
#include <tuple>
#include <vector>
#include <cstdint>
#include <iostream>

#include "main.cpp"

std::string getFilePath() noexcept { return "./../../../../2021F/lab_07/lab_07_A/resource/"; }

const std::string CS203_redirect::file_paths = getFilePath();

// 测试链式前向星数据结构
namespace tree {
TEST_CASE("Graph chain forward star basic", "[graph]") {
    using tree::Graph;
    using std::vector;
    using std::pair;
    Graph g(3, 4); // 3个节点, 最多四条边
    g.add_undirected_edge(1, 2, 5); // 边 1-2/2-1，权重为 5
    g.add_edge(2, 3, 7); // 边 2-3，权重为 7
    vector<vector<pair<int32_t, int32_t> > > expected(4);
    // Directed edges stored outgoing: insertion order newest-first
    expected[1] = {{2, 5}};
    expected[2] = {{3, 7}, {1, 5}};
    expected[3] = {}; // no outgoing edges for node 3
    for (int u = 1; u <= 3; ++u) {
        vector<pair<int, int> > got;
        for (int eid = g.head[u]; eid != -1; eid = g.edges[eid].next) {
            got.emplace_back(g.edges[eid].to, g.edges[eid].weight);
        }
        CHECK_THAT(got, Catch::Matchers::UnorderedEquals(expected[u]));
    }
}
} // namespace tree

namespace lab_07_A {
using std::tie;
using std::cin;
using std::cout;
using std::tuple;
using std::vector;

using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;

// 因为[.],所以下面这个被隐藏了,确保需要重定向输入输出时,请删除`[.]`
TEST_CASE("test case with sequence [test 07_A]", "[test 07_A]") {
    CS203_sequence sequence{1, 1, 2}; // // 基础设定,[1,1]
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
