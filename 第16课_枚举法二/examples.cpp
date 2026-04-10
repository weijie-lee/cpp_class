// ============================================
// Lesson 16: Enumeration (Part II) - Nested Loops & Smart Enumeration
// Examples for classroom demonstration
// ============================================

// ---- Example 1a: Chicken and Rabbit Problem (Brute Force with Double Loop) ----
// Given n heads and m feet, find how many chickens and rabbits there are.
// Method: enumerate both chicken and rabbit counts with nested loops.

#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    bool found = false;

    // Enumerate chicken count
    for (int chicken = 0; chicken <= n; chicken++) {
        // Enumerate rabbit count
        for (int rabbit = 0; rabbit <= n; rabbit++) {
            // Check: total heads and total feet must match
            if (chicken + rabbit == n && chicken * 2 + rabbit * 4 == m) {
                cout << chicken << " " << rabbit << endl;
                found = true;
            }
        }
    }

    if (!found) {
        cout << "No answer" << endl;
    }

    return 0;
}

/*
 * Sample Input:
 * 35 94
 *
 * Expected Output:
 * 23 12
 */


// ---- Example 1b: Chicken and Rabbit Problem (Optimized with Single Loop) ----
// Optimization: if we know the chicken count, rabbit count = n - chicken.
// Only one loop is needed.

/*
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    bool found = false;

    for (int chicken = 0; chicken <= n; chicken++) {
        int rabbit = n - chicken;  // Derive rabbit count from chicken count
        if (chicken * 2 + rabbit * 4 == m) {
            cout << chicken << " " << rabbit << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No answer" << endl;
    }

    return 0;
}
*/

/*
 * Sample Input:
 * 35 94
 *
 * Expected Output:
 * 23 12
 */


// ---- Example 2: Fill in Operators ----
// Place + or - in: 1 O 2 O 3 O 4 = 4
// Enumerate all 3 operator positions (each can be + or -).
// Use 0 for +, 1 for -.

/*
#include <iostream>
using namespace std;

int main() {
    // op1, op2, op3 represent three operators
    // 0 means +, 1 means -
    for (int op1 = 0; op1 <= 1; op1++) {
        for (int op2 = 0; op2 <= 1; op2++) {
            for (int op3 = 0; op3 <= 1; op3++) {
                // Calculate the result starting from the first number
                int result = 1;

                if (op1 == 0) result = result + 2;
                else          result = result - 2;

                if (op2 == 0) result = result + 3;
                else          result = result - 3;

                if (op3 == 0) result = result + 4;
                else          result = result - 4;

                // Filter: check if result equals 4
                if (result == 4) {
                    cout << "1";
                    if (op1 == 0) cout << "+"; else cout << "-";
                    cout << "2";
                    if (op2 == 0) cout << "+"; else cout << "-";
                    cout << "3";
                    if (op3 == 0) cout << "+"; else cout << "-";
                    cout << "4";
                    cout << "=" << result << endl;
                }
            }
        }
    }

    return 0;
}
*/

/*
 * Expected Output:
 * 1-2+3+4=4 (virtual example, verify by running)
 * 1+2-3+4=4
 */


// ---- Example 3: Split a Number into Three Parts ----
// Input n, split it into a + b + c (a <= b <= c, all positive).
// Output all solutions and the total count.

/*
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int count = 0;

    for (int a = 1; a <= n / 3; a++) {               // a is the smallest
        for (int b = a; b <= (n - a) / 2; b++) {      // b starts from a, up to half of remainder
            int c = n - a - b;                         // c is computed directly
            cout << a << " " << b << " " << c << endl;
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
*/

/*
 * Sample Input:
 * 7
 *
 * Expected Output:
 * 1 1 5
 * 1 2 4
 * 1 3 3
 * 2 2 3
 * 4
 */
