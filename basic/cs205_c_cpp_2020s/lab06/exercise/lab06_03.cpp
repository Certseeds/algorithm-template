// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    double quiz = 0;
    double mid_term = 0;
    double scores = 0;
    double average = 0;
    cout << "Input scores between 0 to 100" << endl;
    cout << "Input quiz Score : ";
    cin >> quiz;
    while ((getchar()) != '\n');
    cout << "Input mid_term Score : ";
    cin >> mid_term;
    while ((getchar()) != '\n');
    cout << "Input final term Score : ";
    cin >> scores;
    while ((getchar()) != '\n');
    average = (quiz + mid_term + scores) / 3;
    char grade = '\0';
    if (average >= 90) {
        grade = 'A';
    } else if (average >= 70) {
        grade = 'B';
    } else if (average >= 50) {
        grade = 'C';
    } else {
        grade = 'F';
    }
    cout << "Average is : " << average << endl;
    cout << "Grade is : " << grade << endl;
    return 0;
}
