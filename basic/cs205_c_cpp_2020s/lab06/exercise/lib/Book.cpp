// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds

#include "Book.hpp"


double Book::Get_Area() const {
    return (this->height) * (this->length);
}

int Book::Get_Uuid() const {
    return this->uuid;
}
