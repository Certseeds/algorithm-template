// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds

#include "Book.hpp"
#include <iostream>

int32_t main() {
    static constexpr const Book book1{1, 4, 5};
    std::cout << book1.Get_Area() << std::endl;
}
