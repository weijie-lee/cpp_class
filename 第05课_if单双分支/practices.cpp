// ============================================
// Lesson 05: if Single and Double Branch
// Practice exercises with reference answers
// ============================================

// ---- Practice 1: Roller Coaster Height Check (if single branch) ----
// Input height in cm. If height >= 140, output "YES" (allowed to ride)
#include <iostream>
using namespace std;

int main() {
    int h;
    cin >> h;
    if (h >= 140) {
        cout << "YES" << endl;
    }
    return 0;
}

/*
 * Sample Input:
 * 145
 *
 * Expected Output:
 * YES
 *
 * ---
 *
 * Sample Input:
 * 130
 *
 * Expected Output:
 * (no output)
 */

// ---- Practice 2: Pass or Retake (if-else double branch) ----
// Input a math score. If >= 60, output "及格"; otherwise output "补考"
#include <iostream>
using namespace std;

int main() {
    int score;
    cin >> score;
    if (score >= 60) {
        cout << "及格" << endl;
    } else {
        cout << "补考" << endl;
    }
    return 0;
}

/*
 * Sample Input:
 * 85
 *
 * Expected Output:
 * 及格
 *
 * ---
 *
 * Sample Input:
 * 45
 *
 * Expected Output:
 * 补考
 */

// ---- Practice 3: Divisibility Check (remainder + branching) ----
// Input two positive integers a and b. If a is divisible by b, output "YES"; otherwise "NO"
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a % b == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

/*
 * Sample Input:
 * 12 4
 *
 * Expected Output:
 * YES
 *
 * ---
 *
 * Sample Input:
 * 10 3
 *
 * Expected Output:
 * NO
 */

// ---- Practice 4: Who Wins the Race? (comparison + double branch) ----
// Two kids race. Input their times in seconds. The one with less time wins.
// Output the winner's time. If tied, output "tie".
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a < b) {
        cout << a << endl;
    } else {
        if (a > b) {
            cout << b << endl;
        } else {
            cout << "tie" << endl;
        }
    }
    return 0;
}

/*
 * Sample Input:
 * 15 20
 *
 * Expected Output:
 * 15
 *
 * ---
 *
 * Sample Input:
 * 10 10
 *
 * Expected Output:
 * tie
 */
