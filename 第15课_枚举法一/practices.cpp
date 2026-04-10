// ============================================
// Lesson 15: Enumeration Method (Part 1)
// Practice solutions
// ============================================

// ---- Practice 1: Find All Divisors ----
// Input a positive integer N (<= 100000), output all divisors of N
// in ascending order, one per line.
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            cout << i << endl;
        }
    }
    return 0;
}

/*
 * Sample Input:
 * 12
 *
 * Expected Output:
 * 1
 * 2
 * 3
 * 4
 * 6
 * 12
 */

// ---- Practice 2: Two-Digit Numbers Whose Digits Sum to 10 ----
// Output all two-digit numbers where the tens digit plus the ones
// digit equals 10.
#include <iostream>
using namespace std;

int main() {
    for (int i = 10; i <= 99; i++) {
        int tens = i / 10;     // tens digit
        int ones = i % 10;    // ones digit
        if (tens + ones == 10) {
            cout << i << endl;
        }
    }
    return 0;
}

/*
 * Expected Output:
 * 19
 * 28
 * 37
 * 46
 * 55
 * 64
 * 73
 * 82
 * 91
 */

// ---- Practice 3 (Challenge): Form 3-Digit Numbers from {1,2,3,4} ----
// Using digits 1, 2, 3, 4, form all possible 3-digit numbers where
// no digit repeats. Output all such numbers.
#include <iostream>
using namespace std;

int main() {
    int count = 0;
    // Triple loop: enumerate hundreds, tens, and ones digits
    for (int a = 1; a <= 4; a++) {
        for (int b = 1; b <= 4; b++) {
            for (int c = 1; c <= 4; c++) {
                // All three digits must be different
                if (a != b && a != c && b != c) {
                    cout << a * 100 + b * 10 + c << endl;
                    count++;
                }
            }
        }
    }
    cout << "Total: " << count << endl;
    return 0;
}

/*
 * Expected Output:
 * 123
 * 124
 * 132
 * 134
 * 142
 * 143
 * 213
 * 214
 * 231
 * 234
 * 241
 * 243
 * 312
 * 314
 * 321
 * 324
 * 341
 * 342
 * 412
 * 413
 * 421
 * 423
 * 431
 * 432
 * Total: 24
 */
