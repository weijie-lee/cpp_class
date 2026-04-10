// ============================================
// Lesson 04: Operators and Expressions
// Examples for classroom demonstration
// ============================================

// ---- Example 1: Basic Arithmetic Calculator ----
// Input two integers, output their sum, difference, product, quotient, and remainder
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    cout << a / b << endl;   // integer division (truncated)
    cout << a % b << endl;   // remainder
    return 0;
}

/*
 * Sample Input:
 * 7 2
 *
 * Expected Output:
 * 9
 * 5
 * 14
 * 3
 * 1
 */

// ---- Example 2: Precise Division (Getting Decimal Result) ----
// Input two integers, output the precise decimal result of a / b
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    // Trick: multiply by 1.0 to promote int to double before dividing
    cout << 1.0 * a / b << endl;
    return 0;
}

/*
 * Sample Input:
 * 7 2
 *
 * Expected Output:
 * 3.5
 */

// ---- Example 3: Split a Three-Digit Number ----
// Input a three-digit number, output its hundreds, tens, and ones digits
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int bai = n / 100;        // 527 / 100 = 5
    int shi = n / 10 % 10;    // 527 / 10 = 52, 52 % 10 = 2
    int ge  = n % 10;         // 527 % 10 = 7

    cout << bai << " " << shi << " " << ge << endl;
    return 0;
}

/*
 * Sample Input:
 * 527
 *
 * Expected Output:
 * 5 2 7
 */

// ---- Example 4: Convert Minutes to Hours and Minutes ----
// Input total minutes, output the equivalent hours and remaining minutes
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    int hours = t / 60;    // 135 / 60 = 2
    int mins  = t % 60;    // 135 % 60 = 15

    cout << hours << " " << mins << endl;
    return 0;
}

/*
 * Sample Input:
 * 135
 *
 * Expected Output:
 * 2 15
 */
