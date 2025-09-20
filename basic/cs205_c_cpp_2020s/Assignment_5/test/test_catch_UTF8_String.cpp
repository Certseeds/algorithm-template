// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-04-27 11:13:41
 * @LastEditors  : nanoseeds
 */
#include <catch_main.hpp>
#include "UTF8string.hpp"

using std::cout;
using std::endl;
using Catch::Matchers::Equals;

TEST_CASE("test1") {
    UTF8string test1 = UTF8string("Mais où sont les neiges d'antan?");
    cout << test1 << endl;
    CHECK(33 == test1.bytes());
    CHECK(32 == test1.length());
    CHECK(8 == test1.find("sont"));
    test1 += UTF8string("!!!");
    CHECK_THAT(test1.get_str(),
               Equals("Mais où sont les neiges d'antan?!!!"));
}

TEST_CASE("test 2") {
    UTF8string test1 = UTF8string("Mais où sont les neiges d'antan?");
    UTF8string test2 = UTF8string("Всё хорошо́, что хорошо́ конча́ется");
    CHECK_THAT(test2.get_str(),
               Equals("Всё хорошо́, что хорошо́ конча́ется"));
    test2.replace("хорошо́", "просто");
    CHECK_THAT(test2.get_str(),
               Equals("Всё просто, что просто конча́ется"));
    CHECK_THAT((test1 + test2).get_str(),
               Equals("Mais où sont les neiges d'antan?Всё просто, что просто конча́ется"));
}

TEST_CASE("test 3") {
    UTF8string test3("hip ");
    CHECK_THAT((test3 * 3 + UTF8string("hurray")).get_str(),
               Equals("hip hip hip hurray"));
    CHECK_THAT(test3.get_str(), Equals("hip "));
    test3 * 3;
    CHECK_THAT(test3.get_str(), Equals("hip "));
    3 * test3;
    CHECK_THAT(test3.get_str(), Equals("hip "));
}

TEST_CASE("test 4") {
    UTF8string test4("Никола́й Васи́льевич Го́голь");
    CHECK_THAT((!test4).get_str(),
               Equals("ьлоѓоГ чивеьл́исаВ й́алокиН"));
}

TEST_CASE("test 5") {
    UTF8string test5 = UTF8string("静中有山口记者");
    CHECK(7 == test5.length());
}

TEST_CASE("test 6") {
    UTF8string test6 = UTF8string("星と僕らと -piano version-");
    CHECK(21 == test6.length());
}

TEST_CASE("test 7") {
    UTF8string test7 = UTF8string("Knight Artorias");
    CHECK(7 == test7.find("Artorias"));
}

TEST_CASE("test 8") {
    UTF8string test8 = UTF8string("薬師エマ - Emma The Physician");
    test8.replace("Emma The Physician", "Sekiro");
    CHECK_THAT(test8.get_str(), Equals("薬師エマ - Sekiro"));
}

TEST_CASE("test 9") {
    UTF8string test9 = UTF8string("Floating Dust");
    test9.replace("Floating", "Sherlock: Music");
    CHECK_THAT(test9.get_str(), Equals("Sherlock: Music Dust"));
}

TEST_CASE("test 10") {
    UTF8string test10 =
            UTF8string("PERSONA5 THE ROYAL STRAIGHT FLUSH EDITION Original Soundtrack ");
    test10.replace(" ROYAL ", "");
    CHECK_THAT(test10.get_str(),
               Equals("PERSONA5 THESTRAIGHT FLUSH EDITION Original Soundtrack "));
}

TEST_CASE("test 11") {
    UTF8string test11 =
            UTF8string("ジョジョの奇妙な冒険 スターダストクルセイダース");
    test11.replace("ジョ", "JO");
    CHECK_THAT(test11.get_str(),
               Equals("JOJOの奇妙な冒険 スターダストクルセイダース"));
}

TEST_CASE("test 12") {
    UTF8string test12("空は高く風は歌う");
    CHECK(0 == test12.find("空"));
    CHECK(3 == test12.find("く"));
    CHECK(7 == test12.find("う"));
}

TEST_CASE("test 13") {
    const auto lamb = [](UTF8string u) -> void {
        cout << "Testing operator !: " << u << " -> " << !u << endl;
    };
    const UTF8string test13("reinterpret_cast<const unsigned char *>");
    lamb(test13);
    CHECK_THAT(test13.get_str(),
               Equals("reinterpret_cast<const unsigned char *>"));
    lamb(" 鈥�UTF8string&&鈥�");
    const UTF8string test13_2 = UTF8string("鈥�UTF8string::UTF8string(UTF8string&&)鈥�");
    lamb(test13_2);
    CHECK_THAT(test13_2.get_str(),
               Equals("鈥�UTF8string::UTF8string(UTF8string&&)鈥�"));
}
