// ============================================
// Lesson 14: Two-Dimensional Arrays
// Practice solutions
// ============================================

// ---- Practice 1: Matrix Transpose ----
// Input an n*m matrix, output its transpose (rows become columns).
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int a[5][5];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // Output transpose: outer loop goes to m, inner to n
    // Original a[i][j] becomes the element at row j, col i
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            cout << a[i][j];
            if (i < n - 1) cout << " ";
        }
        cout << endl;
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
 * 1 4
 * 2 5
 * 3 6
 */

// ---- Practice 2: Find Maximum Value and Its Position ----
// Input an n*m matrix, find the max value and output it along with
// its row and column (1-based). If there are ties, output the first one.
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int a[5][5];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int maxVal = a[0][0];
    int maxRow = 0, maxCol = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] > maxVal) {
                maxVal = a[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }

    // Output 1-based row and column
    cout << maxVal << " " << maxRow + 1 << " " << maxCol + 1 << endl;

    return 0;
}

/*
 * Sample Input:
 * 3 3
 * 1 5 3
 * 9 2 7
 * 4 8 6
 *
 * Expected Output:
 * 9 2 1
 */

// ---- Practice 3: Main Diagonal Sum ----
// Input an n*n square matrix, compute the sum of the main diagonal
// elements (a[0][0] + a[1][1] + a[2][2] + ...).
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[5][5];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    // Main diagonal: row index equals column index
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i][i];
    }

    cout << sum << endl;

    return 0;
}

/*
 * Sample Input:
 * 3
 * 1 2 3
 * 4 5 6
 * 7 8 9
 *
 * Expected Output:
 * 15
 */

// ---- Practice 4: Border Fill ----
// Input n and m, output an n*m matrix where all border elements are 1
// and all interior elements are 0.
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // A cell is on the border if it's in the first/last row
            // or first/last column
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                cout << 1;
            } else {
                cout << 0;
            }
            if (j < m - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
 * Sample Input:
 * 4 5
 *
 * Expected Output:
 * 1 1 1 1 1
 * 1 0 0 0 1
 * 1 0 0 0 1
 * 1 1 1 1 1
 */
