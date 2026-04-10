// ============================================
// Lesson 09: Nested Loops (Multiplication Table & Patterns)
// Practice solutions
// ============================================

// ---- Practice 1: Number Grid (Basic Nesting) ----
// Input a positive integer n, print an n x n grid where each row
// contains the numbers 1 to n separated by spaces.
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
 * Sample Input: 4
 *
 * Expected Output:
 * 1 2 3 4
 * 1 2 3 4
 * 1 2 3 4
 * 1 2 3 4
 */

// ---- Practice 2: Number Triangle (Inner Depends on Outer) ----
// Input a positive integer n, print a number triangle.
// Row i contains numbers 1 to i separated by spaces.
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
 * Sample Input: 5
 *
 * Expected Output:
 * 1
 * 1 2
 * 1 2 3
 * 1 2 3 4
 * 1 2 3 4 5
 */

// ---- Practice 3: Incrementing Number Triangle (Challenge) ----
// Input a positive integer n, print a triangle where numbers
// increment continuously across all rows.
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int num = 1;  // Counter, starts at 1 and keeps incrementing
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
    return 0;
}

/*
 * Sample Input: 4
 *
 * Expected Output:
 * 1
 * 2 3
 * 4 5 6
 * 7 8 9 10
 */
