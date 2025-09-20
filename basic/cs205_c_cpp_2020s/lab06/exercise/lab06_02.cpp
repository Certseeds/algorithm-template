// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds

#include <iostream>
#include <cstring>

static constexpr const int32_t lab06_02_max_length = 1024;

int main() {
    std::cout << "Enter words (q to quit): ";
    std::cout.flush();
    int32_t nVowel = 0;
    int32_t nConsonant = 0;
    int32_t nOther = 0;
    char word[lab06_02_max_length + 1];
    while (std::cin >> word) {
        if (isalpha(word[0])) {
            if (strlen(word) == 1 && word[0] == 'q') {
                break;
            }
            char x = tolower(word[0]);
            switch (x) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u': {
                    nVowel++;
                    break;
                }
                default: {
                    nConsonant++;
                    break;
                }
            }
        } else {
            nOther++;
        };
    }
    std::cout << nVowel << " words begining with vowels" << std::endl
              << nConsonant << " words begining with consonants" << std::endl
              << nOther << " others" << std::endl;
    return 0;
}
