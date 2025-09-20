// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Description 最长公共子序列
//@Plan 动态规划入门 Day19

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_1143_TEST_CPP
#define ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_1143_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_1143.cpp"

namespace leetcode_1143 {
using std::string;

using Catch::Matchers::Equals;

TEST_CASE("1 [test_1143]", "[test_1143]") {
    static constexpr const char *const input1{"abcde"}, *const input2{"ace"};
    static constexpr const auto result{3};
    Solution solution;
    CHECK(result == solution.longestCommonSubsequence(input1, input2));
    CHECK(result == solution.longestCommonSubsequence2(input1, input2));
}

TEST_CASE("2 [test_1143]", "[test_1143]") {
    static constexpr const char *const input1{"abc"}, *const input2{"abc"};
    static constexpr const auto result{3};
    Solution solution;
    CHECK(result == solution.longestCommonSubsequence(input1, input2));
    CHECK(result == solution.longestCommonSubsequence2(input1, input2));
}

TEST_CASE("3 [test_1143]", "[test_1143]") {
    static constexpr const char *const input1{"abc"}, *const input2{"degf"};
    static constexpr const auto result{0};
    Solution solution;
    CHECK(result == solution.longestCommonSubsequence(input1, input2));
    CHECK(result == solution.longestCommonSubsequence2(input1, input2));
}

TEST_CASE("4 [test_1143]", "[test_1143]") {
    static constexpr const char *const input1{"a"}, *const input2{"aba"};
    static constexpr const auto result{1};
    Solution solution;
    CHECK(result == solution.longestCommonSubsequence(input1, input2));
    CHECK(result == solution.longestCommonSubsequence2(input1, input2));
}

TEST_CASE("5 [test_1143]", "[test_1143]") {
    static constexpr const char *const input1{
            "fcvafurqjylclorwfoladwfqzkbebslwnmpmlkbezkxoncvwhstwzwpqxqtyxozkpgtgtsjobujezgrkvevklmludgtyrmjaxyputqbyxqvupojutsjwlwluzsbmvyxifqtglwvcnkfsfglwjwrmtyxmdgjifyjwrsnenuvsdedsbqdovwzsdghclcdexmtsbexwrszihcpibwpidixmpmxshwzmjgtadmtkxqfkrsdqjcrmxkbkfoncrcvoxuvcdytajgfwrcxivixanuzerebuzklyhezevonqdsrkzetsrgfgxibqpmfuxcrinetyzkvudghgrytsvwzkjulmhanankxqfihenuhmfsfkfepibkjmzybmlkzozmluvybyzsleludsxkpinizoraxonmhwtkfkhudizepyzijafqlepcbihofepmjqtgrsxorunshgpazovuhktatmlcfklafivivefyfubunszyvarcrkpsnglkduzaxqrerkvcnmrurkhkpargvcxefovwtapedaluhclmzynebczodwropwdenqxmrutuhehadyfspcpuxyzodifqdqzgbwhodcjonypyjwbwxepcpujerkrelunstebopkncdazexsbezmhynizsvarafwfmnclerafejgnizcbsrcvcnwrolofyzulcxaxqjqzunedidulspslebifinqrchyvapkzmzwbwjgbyrqhqpolwjijmzyduzerqnadapudmrazmzadstozytonuzarizszubkzkhenaxivytmjqjgvgzwpgxefatetoncjgjsdilmvgtgpgbibexwnexstipkjylalqnupexytkradwxmlmhsnmzuxcdkfkxyfgrmfqtajatgjctenqhkvyrgvapctqtyrufcdobibizihuhsrsterozotytubefutaxcjarknynetipehoduxyjstufwvkvwvwnuletybmrczgtmxctuny"};
    static constexpr const char *const input2{
            "nohgdazargvalupetizezqpklktojqtqdivcpsfgjopaxwbkvujilqbclehulatshehmjqhyfkpcfwxovajkvankjkvevgdovazmbgtqfwvejczsnmbchkdibstklkxarwjqbqxwvixavkhylqvghqpifijohudenozotejoxavkfkzcdqnoxydynavwdylwhatslyrwlejwdwrmpevmtwpahatwlaxmjmdgrebmfyngdcbmbgjcvqpcbadujkxaxujudmbejcrevuvcdobolcbstifedcvmngnqhudixgzktcdqngxmruhcxqxypwhahobudelivgvynefkjqdyvalmvudcdivmhghqrelurodwdsvuzmjixgdexonwjczghalsjopixsrwjixuzmjgxydqnipelgrivkzkxgjchibgnqbknstspujwdydszohqjsfuzstyjgnwhsrebmlwzkzijgnmnczmrehspihspyfedabotwvwxwpspypctizyhcxypqzctwlspszonsrmnyvmhsvqtkbyhmhwjmvazaviruzqxmbczaxmtqjexmdudypovkjklynktahupanujylylgrajozobsbwpwtohkfsxeverqxylwdwtojoxydepybavwhgdehafurqtcxqhuhkdwxkdojipolctcvcrsvczcxedglgrejerqdgrsvsxgjodajatsnixutihwpivihadqdotsvyrkxehodybapwlsjexixgponcxifijchejoxgxebmbclczqvkfuzgxsbshqvgfcraxytaxeviryhexmvqjybizivyjanwxmpojgxgbyhcruvqpafwjslkbohqlknkdqjixsfsdurgbsvclmrcrcnulinqvcdqhcvwdaxgvafwravunurqvizqtozuxinytafopmhchmxsxgfanetmdcjalmrolejidylkjktunqhkxchyjmpkvsfgnybsjedmzkrkhwryzan"};
    static constexpr const auto result{323};
    Solution solution;
    CHECK(result == solution.longestCommonSubsequence(input1, input2));
    CHECK(result == solution.longestCommonSubsequence2(input1, input2));
}

TEST_CASE("6 [test_1143]", "[test_1143]") {
    static constexpr const char *const input1{"bsbininm"}, *const input2{"jmjkbkjkv"};
    static constexpr const auto result{1};
    Solution solution;
    CHECK(result == solution.longestCommonSubsequence(input1, input2));
    CHECK(result == solution.longestCommonSubsequence2(input1, input2));
}

TEST_CASE("7 [test_1143]", "[test_1143]") {
    static constexpr const char *const input1{"horse"}, *const input2{"ros"};
    static constexpr const auto result{2};
    Solution solution;
    CHECK(result == solution.longestCommonSubsequence(input1, input2));
    CHECK(result == solution.longestCommonSubsequence2(input1, input2));
}

TEST_CASE("8 [test_1143]", "[test_1143]") {
    static constexpr const char *const input1{"intention"}, *const input2{"execution"};
    static constexpr const auto result{5}; // etion
    Solution solution;
    CHECK(result == solution.longestCommonSubsequence(input1, input2));
    CHECK(result == solution.longestCommonSubsequence2(input1, input2));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_1143_TEST_CPP
