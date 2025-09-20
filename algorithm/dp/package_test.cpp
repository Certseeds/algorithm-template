// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanos

*/

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_DP_PACKAGE_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_DP_PACKAGE_TEST_HPP

#include <catch_main.hpp>
#include "package.cpp"

namespace dp_package {

namespace zero_one {
TEST_CASE("1 [test_zero_one]", "[test_zero_one]") {
    const vector<something> things{
            something{2, 4}, something{1, 2}, something{3, 3},
    };
    static constexpr const size_t weight{4};
    Package package{things, weight};
    /**
     * cost 1 to things[1], get 2 <br>
     * cost 2 to things[0], get 4 <br>
     * Sums: cost 3, get 6
     * */
    static constexpr const size_t unFullResult{6};
    CHECK(unFullResult == package.solve<allow_unfull::ALLOW>());
    CHECK(unFullResult == package.solveSaveSpace<allow_unfull::ALLOW>());
    CHECK(unFullResult == package.solveOneLine<allow_unfull::ALLOW>());
    /**
     * cost 1 to things[1], get 2 <br>
     * cost 3 to things[2], get 3 <br>
     * Sums: cost 4, get 5
     * */
    static constexpr const size_t FullResult{5};
    CHECK(FullResult == package.solve<allow_unfull::UN_ALLOW>());
    CHECK(FullResult == package.solveSaveSpace<allow_unfull::UN_ALLOW>());
    CHECK(FullResult == package.solveOneLine<allow_unfull::UN_ALLOW>());
}
}
namespace complete {
TEST_CASE("1 [test_complate]", "[test_complate]") {
    const vector<something> things{
            something{1, 1}, something{2, 2}, something{5, 5},
    };
    static constexpr const size_t weight{5};
    Package package{things, weight};
    static constexpr const size_t unFullResult{5};
    CHECK(unFullResult == package.solve<allow_unfull::ALLOW>());
    CHECK(unFullResult == package.solve2<allow_unfull::ALLOW>());
    CHECK(unFullResult == package.solveBinary<allow_unfull::ALLOW>());
    CHECK(unFullResult == package.solveComplete<allow_unfull::ALLOW>());
    static constexpr const size_t FullResult{5};
    CHECK(FullResult == package.solve<allow_unfull::UN_ALLOW>());
    CHECK(FullResult == package.solve2<allow_unfull::UN_ALLOW>());
    CHECK(FullResult == package.solveBinary<allow_unfull::UN_ALLOW>());
    CHECK(FullResult == package.solveComplete<allow_unfull::UN_ALLOW>());
}

TEST_CASE("2 [test_complate]", "[test_complate]") {
    const vector<something> things{
            something{2, 2}
    };
    static constexpr const size_t weight{3};
    Package package{things, weight};
    static constexpr const size_t unFullResult{2};
    CHECK(unFullResult == package.solve<allow_unfull::ALLOW>());
    CHECK(unFullResult == package.solve2<allow_unfull::ALLOW>());
    CHECK(unFullResult == package.solveBinary<allow_unfull::ALLOW>());
    CHECK(unFullResult == package.solveComplete<allow_unfull::ALLOW>());
    static constexpr const size_t FullResult{0};
    CHECK(FullResult == package.solve<allow_unfull::UN_ALLOW>());
    CHECK(FullResult == package.solve2<allow_unfull::UN_ALLOW>());
    CHECK(FullResult == package.solveBinary<allow_unfull::UN_ALLOW>());
    CHECK(FullResult == package.solveComplete<allow_unfull::UN_ALLOW>());
}

TEST_CASE("3 [test_complate]", "[test_complate]") {
    const vector<something> things{
            something{3, 6},
            something{2, 5},
            something{5, 10},
            something{1, 2},
            something{6, 16},
            something{4, 8},
    };
    static constexpr const size_t weight{10};
    Package package{things, weight};
    static constexpr const size_t unFullResult{26};
    CHECK(unFullResult == package.solve<allow_unfull::ALLOW>());
    CHECK(unFullResult == package.solve2<allow_unfull::ALLOW>());
    CHECK(unFullResult == package.solveBinary<allow_unfull::ALLOW>());
    CHECK(unFullResult == package.solveComplete<allow_unfull::ALLOW>());
    static constexpr const size_t FullResult{26};
    CHECK(FullResult == package.solve<allow_unfull::UN_ALLOW>());
    CHECK(FullResult == package.solve2<allow_unfull::UN_ALLOW>());
    CHECK(FullResult == package.solveBinary<allow_unfull::UN_ALLOW>());
    CHECK(FullResult == package.solveComplete<allow_unfull::UN_ALLOW>());
}
}
}

#endif //ALGORITHM_TEMPLATE_ALGORITHM_DP_PACKAGE_TEST_HPP
