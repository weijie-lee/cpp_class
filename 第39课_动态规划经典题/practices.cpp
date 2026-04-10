// ============================================
// Lesson 39: DP Classic Problems (Number Triangle)
// Practice solutions
// ============================================

// ---- Practice 1: Hand-fill DP Table ----
// This practice is a pen-and-paper exercise. Below is the
// programmatic verification of the answer.
// Triangle:
//     5
//    8 3
//   12 7 16
//  4 10 11 6
#include <iostream>
using namespace std;

int main() {
    int n = 4;
    int a[5][5] = {};
    int dp[5][5] = {};

    a[1][1] = 5;
    a[2][1] = 8;  a[2][2] = 3;
    a[3][1] = 12; a[3][2] = 7;  a[3][3] = 16;
    a[4][1] = 4;  a[4][2] = 10; a[4][3] = 11; a[4][4] = 6;

    for (int j = 1; j <= n; j++)
        dp[n][j] = a[n][j];

    for (int i = n - 1; i >= 1; i--)
        for (int j = 1; j <= i; j++)
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + a[i][j];

    cout << dp[1][1] << endl;

    return 0;
}

/*
 * DP table (bottom-up):
 *      35
 *    30  30
 *   16  21  27
 *  4  10  11  6    <- initial values
 *
 * Expected Output:
 * 35
 *
 * Path: 5 -> 3 -> 16 -> 11 = 35
 * (Greedy picking the larger neighbor at each step doesn't work here!)
 */

// ---- Practice 2: Fill-in-the-Blank Code ----
// The blanks are: a[n][j], max(dp[i+1][j], dp[i+1][j+1]), dp[1][1]
// Below is the complete, corrected version.
#include <iostream>
using namespace std;

int a[55][55], dp[55][55];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> a[i][j];

    // Blank 1: Initialize last row
    for (int j = 1; j <= n; j++)
        dp[n][j] = a[n][j];

    // Blank 2: State transition
    for (int i = n - 1; i >= 1; i--)
        for (int j = 1; j <= i; j++)
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + a[i][j];

    // Blank 3: Output the answer
    cout << dp[1][1] << endl;
    return 0;
}

/*
 * Sample Input:
 * 4
 * 2
 * 3 4
 * 6 5 7
 * 4 1 8 3
 *
 * Expected Output:
 * 20
 */

// ---- Practice 3: Minimum Path Sum in Number Triangle ----
// Same as the standard triangle problem, but find the MINIMUM
// path sum. Just change max() to min().
#include <iostream>
using namespace std;

int a[55][55], dp[55][55];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> a[i][j];

    for (int j = 1; j <= n; j++)
        dp[n][j] = a[n][j];

    for (int i = n - 1; i >= 1; i--)
        for (int j = 1; j <= i; j++)
            dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + a[i][j];

    cout << dp[1][1] << endl;
    return 0;
}

/*
 * Sample Input:
 * 3
 * 5
 * 9 2
 * 3 8 1
 *
 * Expected Output:
 * 8
 *
 * Path: 5 -> 2 -> 1 = 8
 */

// ---- Practice 4: Print Path (Optional Challenge) ----
// Output the maximum path sum AND the specific path taken
// (column indices from row 1 to row n).
#include <iostream>
using namespace std;

int a[105][105], dp[105][105];
int path[105][105];  // path[i][j]: which column to go next from (i,j)

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> a[i][j];

    for (int j = 1; j <= n; j++)
        dp[n][j] = a[n][j];

    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            if (dp[i + 1][j] >= dp[i + 1][j + 1]) {
                dp[i][j] = dp[i + 1][j] + a[i][j];
                path[i][j] = j;       // Go to lower-left
            } else {
                dp[i][j] = dp[i + 1][j + 1] + a[i][j];
                path[i][j] = j + 1;   // Go to lower-right
            }
        }
    }

    cout << dp[1][1] << endl;

    // Trace and print the path
    int col = 1;
    for (int i = 1; i <= n; i++) {
        if (i > 1) cout << " ";
        cout << col;
        col = path[i][col];  // Move to next row's chosen column
    }
    cout << endl;

    return 0;
}

/*
 * Sample Input:
 * 4
 * 2
 * 3 4
 * 6 5 7
 * 4 1 8 3
 *
 * Expected Output:
 * 20
 * 1 2 3 3
 *
 * Explanation: Start at col 1 (value 2), go to col 2 (value 4),
 * then col 3 (value 7), then col 3 (value 8). Total = 2+4+7+8 = 20.
 */
