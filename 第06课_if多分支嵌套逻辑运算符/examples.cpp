// ============================================
// Lesson 06: if Multi-branch, Nesting & Logical Operators
// Examples for classroom demonstration
// ============================================

// ---- Example 1: Grade Classification (Multi-branch Basics) ----
// Input a score (0-100) and output the corresponding grade level.
#include <iostream>
using namespace std;

int main() {
    int score;
    cin >> score;

    if (score >= 90) {
        cout << "A" << endl;
    } else if (score >= 80) {
        cout << "B" << endl;
    } else if (score >= 60) {
        cout << "C" << endl;
    } else {
        cout << "D" << endl;
    }

    return 0;
}

/*
 * Sample Input: 75
 *
 * Expected Output:
 * C
 */

// ---- Example 2: Simple Calculator (Multi-branch Advanced) ----
// Input two integers and an operator (+, -, *), output the result.
// If the operator is invalid, output "Error".
#include <iostream>
using namespace std;

int main() {
    int a, b;
    char op;
    cin >> a >> op >> b;

    if (op == '+') {
        cout << a + b << endl;
    } else if (op == '-') {
        cout << a - b << endl;
    } else if (op == '*') {
        cout << a * b << endl;
    } else {
        cout << "Error" << endl;
    }

    return 0;
}

/*
 * Sample Input: 3 + 5
 *
 * Expected Output:
 * 8
 */

// ---- Example 3: Leap Year Check (Logical Operators) ----
// Input a year and determine whether it is a leap year.
// Rule: divisible by 4 AND not by 100, OR divisible by 400.
#include <iostream>
using namespace std;

int main() {
    int year;
    cin >> year;

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        cout << "Leap year" << endl;
    } else {
        cout << "Not a leap year" << endl;
    }

    return 0;
}

/*
 * Sample Input: 2024
 *
 * Expected Output:
 * Leap year
 *
 * Sample Input: 1900
 *
 * Expected Output:
 * Not a leap year
 *
 * Sample Input: 2000
 *
 * Expected Output:
 * Leap year
 */

// ---- Example 4: Amusement Park Ticket (if Nesting) ----
// Admission rules:
//   - Height < 120 cm: cannot enter.
//   - Height >= 120 cm: age < 12 -> ticket 50 yuan; age >= 12 -> ticket 100 yuan.
#include <iostream>
using namespace std;

int main() {
    int h, age;
    cin >> h >> age;

    if (h >= 120) {
        if (age < 12) {
            cout << "Welcome! Ticket price: 50 yuan" << endl;
        } else {
            cout << "Welcome! Ticket price: 100 yuan" << endl;
        }
    } else {
        cout << "Too short, cannot enter the park" << endl;
    }

    return 0;
}

/*
 * Sample Input: 130 10
 *
 * Expected Output:
 * Welcome! Ticket price: 50 yuan
 *
 * Sample Input: 130 15
 *
 * Expected Output:
 * Welcome! Ticket price: 100 yuan
 *
 * Sample Input: 110 8
 *
 * Expected Output:
 * Too short, cannot enter the park
 */
