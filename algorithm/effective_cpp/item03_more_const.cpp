// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <catch_main.hpp>
#include <string>
#include <utility>

using std::string;

struct TextBlock {
    const char &operator[](std::size_t position) const {
        std::cout << "invoke const []" << std::endl;
        return text[position];
    }

    char &operator[](size_t position) {
        std::cout << "invoke normal []" << std::endl;
        return text[position];
    }

    const char &operator()(std::size_t position) const {
        std::cout << "invoke const ()" << std::endl;
        return text[position];
    }

    char &operator()(size_t position) {
        std::cout << "invoke normal ()" << std::endl;
        return const_cast<char &>(
                static_cast<const TextBlock &>(*this)(position)
        );
    }

    explicit TextBlock(string text) : text(std::move(text)) {}

private:
    string text;
};

static void print(const TextBlock &ctb) {
    ctb[0];
}

int main() {
    TextBlock tb{"tb"};
    const TextBlock ctb{"tb2"};
    tb[0];
    ctb[0];
    print(ctb);
    tb[0] = '?'; // can
    // ctb[0] ='?'; // can not compile
    ctb(0);
    tb(0) = '?'; // can compile
}
