// ============================================
// Lesson 09: Nested Loops (Multiplication Table & Patterns)
// Examples for classroom demonstration
// ============================================

// ---- Example 1: Print a Rectangle of Stars (Basic Nesting) ----
// Input n (rows) and m (columns), print an n x m rectangle of stars.
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {       // Outer: controls rows
        for (int j = 1; j <= m; j++) {   // Inner: controls columns per row
            cout << "* ";
        }
        cout << endl;  // Newline after each row
    }
    return 0;
}

/*
 * Sample Input: 3 5
 *
 * Expected Output:
 * * * * * *
 * * * * * *
 * * * * * *
 */

// ---- Example 2: Right Triangle of Stars (Inner Depends on Outer) ----
// Input a positive integer n, print a right triangle with n rows.
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {       // Row i
        for (int j = 1; j <= i; j++) {   // Print i stars on row i
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}

/*
 * Sample Input: 5
 *
 * Expected Output:
 * *
 * * *
 * * * *
 * * * * *
 * * * * * *
 */

// ---- Example 3: Multiplication Table (Classic Nested Loop) ----
// Print the 9x9 multiplication table.
#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 9; i++) {           // i: row number (first factor)
        for (int j = 1; j <= i; j++) {       // j: column number (second factor)
            cout << j << "*" << i << "=" << i * j << "\t";
        }
        cout << endl;
    }
    return 0;
}

/*
 * Expected Output:
 * 1*1=1
 * 1*2=2	2*2=4
 * 1*3=3	2*3=6	3*3=9
 * 1*4=4	2*4=8	3*4=12	4*4=16
 * 1*5=5	2*5=10	3*5=15	4*5=20	5*5=25
 * 1*6=6	2*6=12	3*6=18	4*6=24	5*6=30	6*6=36
 * 1*7=7	2*7=14	3*7=21	4*7=28	5*7=35	6*7=42	7*7=49
 * 1*8=8	2*8=16	3*8=24	4*8=32	5*8=40	6*8=48	7*8=56	8*8=64
 * 1*9=9	2*9=18	3*9=27	4*9=36	5*9=45	6*9=54	7*9=63	8*9=72	9*9=81
 */

// ---- Example 4: Inverted Right Triangle (Reverse Thinking) ----
// Input a positive integer n, print an inverted right triangle.
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = n; i >= 1; i--) {       // Start from row n, go down to 1
        for (int j = 1; j <= i; j++) {   // Print i stars on current row
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}

/*
 * Sample Input: 5
 *
 * Expected Output:
 * * * * * *
 * * * * *
 * * * *
 * * *
 * *
 * *
 */
