// ============================================
// Lesson 14: Two-Dimensional Arrays
// Examples for classroom demonstration
// ============================================

// ---- Example 1: Input and Output a Matrix ----
// Input n rows and m columns of integers, then print the matrix as-is.
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int a[5][5];

    // Input: nested loop, outer for rows, inner for columns
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // Output: same nested loop structure
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j];
            if (j < m - 1) cout << " ";  // no trailing space
        }
        cout << endl;  // newline after each row
    }

    return 0;
}

/*
 * Sample Input:
 * 2 3
 * 1 2 3
 * 4 5 6
 *
 * Expected Output:
 * 1 2 3
 * 4 5 6
 */

// ---- Example 2: Multiplication Table Grid ----
// Input n, output an n*n multiplication table.
// Value at row i, col j is (i+1)*(j+1). Each number is right-aligned, width 4.
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(4) << (i + 1) * (j + 1);
        }
        cout << endl;
    }

    return 0;
}

/*
 * Sample Input:
 * 4
 *
 * Expected Output:
 *    1   2   3   4
 *    2   4   6   8
 *    3   6   9  12
 *    4   8  12  16
 */

// ---- Example 3: Grade Table - Row Sum and Column Average ----
// n students, m subjects each. Compute:
// 1) Each student's total score (row sum)
// 2) Each subject's average score (column average, 1 decimal place)
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int a[5][5];

    // Input scores
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // Row sums: total score per student
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            sum += a[i][j];
        }
        cout << "Student " << i + 1 << ": " << sum << endl;
    }

    // Column averages: average score per subject
    for (int j = 0; j < m; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i][j];
        }
        double avg = (double)sum / n;
        cout << "Subject " << j + 1 << ": "
             << fixed << setprecision(1) << avg << endl;
    }

    return 0;
}

/*
 * Sample Input:
 * 3 3
 * 90 85 78
 * 76 92 88
 * 85 79 95
 *
 * Expected Output:
 * Student 1: 253
 * Student 2: 256
 * Student 3: 259
 * Subject 1: 83.7
 * Subject 2: 85.3
 * Subject 3: 87.0
 */
