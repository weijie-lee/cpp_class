// ============================================
// Lesson 39: DP Classic Problems (Number Triangle)
// Examples for classroom demonstration
// ============================================

// ---- Example 1: 3-Row Small Triangle (Intro Version) ----
// Given a 3-row number triangle, find the maximum path sum
// from top to bottom using bottom-up DP.
#include <iostream>
using namespace std;

int main() {
    // 3-row number triangle, hardcoded for demonstration
    int n = 3;
    int a[4][4] = {};  // 1-indexed, extra space
    int dp[4][4] = {};

    // Store the triangle data
    a[1][1] = 1;
    a[2][1] = 3;  a[2][2] = 2;
    a[3][1] = 4;  a[3][2] = 10; a[3][3] = 1;

    // Step 1: Initialize — copy the last row
    for (int j = 1; j <= n; j++) {
        dp[n][j] = a[n][j];
    }

    // Step 2: Bottom-up DP
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + a[i][j];
        }
    }

    // Step 3: The answer is at the top
    cout << dp[1][1] << endl;

    return 0;
}

/*
 * Triangle:
 *   1
 *  3 2
 * 4 10 1
 *
 * Expected Output:
 * 14
 *
 * Path: 1 -> 3 -> 10 = 14
 */

// ---- Example 2: N-Row Number Triangle (Standard Version) ----
// Input an n-row number triangle (n <= 100), find the maximum
// path sum from top to bottom using bottom-up DP.
#include <iostream>
using namespace std;

int a[105][105];   // Triangle data
int dp[105][105];  // DP results

int main() {
    int n;
    cin >> n;

    // Read the triangle
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> a[i][j];
        }
    }

    // Initialize: last row
    for (int j = 1; j <= n; j++) {
        dp[n][j] = a[n][j];
    }

    // Bottom-up DP
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + a[i][j];
        }
    }

    // Output the answer
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
 *
 * Path: 2 -> 4 -> 7 -> 8 = 20 (going right-right-left from top)
 */
