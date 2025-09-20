// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#ifndef _LAB04_PIZZA_
#define _LAB04_PIZZA_

#include <iostream>
#include <cstring>

static constexpr const int32_t lab04_01_max_length = 1024;

class pizza {
public:
    char *name{nullptr};
    double *diameter{nullptr};
    double *weight{nullptr};

    pizza();

    pizza(char *n, double d, double w);

    ~pizza();
};

#endif //  _LAB04_PIZZA_
