// ============================================
// Lesson 38: Introduction to Dynamic Programming
// Practice solutions
// ============================================

// ---- Practice 1: Cow Counting (Fibonacci Variant) ----
// A farm starts with 1 cow. Each cow produces 1 calf starting
// from its 3rd year. Cows never die. How many cows are there
// in year n? (This follows the Fibonacci pattern.)
#include <iostream>
using namespace std;

long long dp[55];

int main() {
    int n;
    cin >> n;

    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n] << endl;

    return 0;
}

/*
 * Sample Input:
 * 6
 *
 * Expected Output:
 * 8
 */

// ---- Practice 2: Basic Climbing Stairs ----
// Climb n stairs, 1 or 2 steps at a time. Output the number
// of distinct ways to reach the n-th stair.
#include <iostream>
using namespace std;

long long dp[55];

int main() {
    int n;
    cin >> n;

    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n] << endl;

    return 0;
}

/*
 * Sample Input:
 * 7
 *
 * Expected Output:
 * 21
 */

// ---- Practice 3: Tile Paving ----
// A corridor is n cells long and 1 cell wide. You have 1x1 tiles
// and 2x1 tiles. How many ways to pave the entire corridor?
// (Same as climbing stairs: dp[i] = dp[i-1] + dp[i-2])
#include <iostream>
using namespace std;

long long dp[55];

int main() {
    int n;
    cin >> n;

    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n] << endl;

    return 0;
}

/*
 * Sample Input:
 * 5
 *
 * Expected Output:
 * 8
 */

// ---- Practice 4: Minimum Coins (Optional Challenge) ----
// You have coins of value 1, 5, and 11 (unlimited supply).
// To make n yuan, what is the minimum number of coins needed?
#include <iostream>
#include <algorithm>
using namespace std;

int dp[1005];

int main() {
    int n;
    cin >> n;

    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;  // At least use a 1-yuan coin
        if (i >= 5)  dp[i] = min(dp[i], dp[i - 5] + 1);
        if (i >= 11) dp[i] = min(dp[i], dp[i - 11] + 1);
    }
    cout << dp[n] << endl;

    return 0;
}

/*
 * Sample Input:
 * 15
 *
 * Expected Output:
 * 3
 *
 * Explanation: 5 + 5 + 5 = 15, using 3 coins.
 */
