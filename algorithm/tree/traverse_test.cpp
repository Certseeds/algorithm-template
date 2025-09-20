/*
 * @Author: nanoseeds
 * @Date: 2020-07-30 10:30:53
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-07-30 18:18:53
 */
// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/

#include "traverse.cpp"
#include <numeric>

#include <tree/treenode_link.hpp>

namespace Tree_Traverse {

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;

TEST_CASE("traverse basic", "[tree traverse]") {
    static constexpr const std::array<const char *const, 4> name{"", "pre order", "in order", "post order"};
    static constexpr const int32_t tree_nodes{32};
    static int32_t count{0};
    vector<int32_t> vec(tree_nodes);
    std::iota(vec.begin(), vec.end(), 0);
    const vector<TreeNode *> numvec = TREE_NODE::numToTree<int32_t>(vec);
    const TreeNode *const head = numvec[0];
    const TreeNodeLink link{numvec[0]};
    static vector<int32_t> last(tree_nodes);
    vector<int32_t> res;
    const auto func2 = [&res](const TreeNode *tn) -> void { res.push_back(tn->val); };
    SECTION("pre_rec") {
        count++;
        rec::pre(head, func2);
    }SECTION("iter::pre1") {
        iter::pre1(head, func2);
        CHECK_THAT(res, Equals(last));
    }SECTION("pre_iter2") {
        iter::pre2(head, func2);
        CHECK_THAT(res, Equals(last));
    }SECTION("pre_iter3") {
        iter::pre3(head, func2);
        CHECK_THAT(res, Equals(last));
    }
    INFO("pre order finish");
    SECTION("in_rec") {
        count++;
        rec::in(head, func2);
    }SECTION("in_iter") {
        iter::in(head, func2);
        CHECK_THAT(res, Equals(last));
    }SECTION("in_iter2") {
        iter::in2(head, func2);
        CHECK_THAT(res, Equals(last));
    }
    INFO("in order finish");
    SECTION("post_iter") {
        count++;
        iter::post(head, func2);
    }SECTION("post_rec") {
        rec::post(head, func2);
        CHECK_THAT(res, Equals(last));
    }SECTION("iter_rec2") {
        iter::post2(head, func2);
        CHECK_THAT(res, Equals(last));
    }
    std::copy(std::begin(res), std::end(res), std::begin(last));
    std::copy(std::begin(res), std::end(res), std::ostream_iterator<int>{std::cout, " "});
    cout << name[count] << end;
    res.clear();
}
}
