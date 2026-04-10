// ============================================
// Lesson 38: Introduction to Dynamic Programming
// Examples for classroom demonstration
// ============================================

// ---- Example 1a: Fibonacci — Recursive Version (Slow) ----
// Compute the n-th Fibonacci number using recursion.
// This version is very slow for large n due to repeated computation.
#include <iostream>
using namespace std;

int fib(int n) {
    if (n == 1 || n == 2) return 1;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}

/*
 * Sample Input:
 * 10
 *
 * Expected Output:
 * 55
 *
 * Note: Try n=40, it will be extremely slow!
 */

// ---- Example 1b: Fibonacci — DP Version (Fast!) ----
// Compute the n-th Fibonacci number using DP (bottom-up).
// Uses an array to store previously computed results.
#include <iostream>
using namespace std;

long long dp[105];  // Memo array to store each Fibonacci number

int main() {
    int n;
    cin >> n;

    // Step 1: Initialize base cases
    dp[1] = 1;
    dp[2] = 1;

    // Step 2: Build up from small to large
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];  // State transition equation
    }

    // Step 3: Output the answer
    cout << dp[n] << endl;

    return 0;
}

/*
 * Sample Input:
 * 10
 *
 * Expected Output:
 * 55
 *
 * Sample Input:
 * 50
 *
 * Expected Output:
 * 12586269025
 */

// ---- Example 2: Climbing Stairs ----
// There are n stairs. You can climb 1 or 2 steps at a time.
// How many distinct ways to reach the n-th stair?
#include <iostream>
using namespace std;

long long dp[55];

int main() {
    int n;
    cin >> n;

    dp[1] = 1;  // 1 stair: 1 way (take 1 step)
    dp[2] = 2;  // 2 stairs: 2 ways (1+1 or 2)

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];  // Come from (i-1) or (i-2)
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
 *
 * Sample Input:
 * 10
 *
 * Expected Output:
 * 89
 */

// ---- Example 3: Climbing Stairs — 1, 2, or 3 Steps ----
// There are n stairs. You can climb 1, 2, or 3 steps at a time.
// How many distinct ways to reach the n-th stair?
#include <iostream>
using namespace std;

long long dp[55];

int main() {
    int n;
    cin >> n;

    dp[1] = 1;  // 1 way:  (1)
    dp[2] = 2;  // 2 ways: (1,1) (2)
    dp[3] = 4;  // 4 ways: (1,1,1) (1,2) (2,1) (3)

    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    cout << dp[n] << endl;

    return 0;
}

/*
 * Sample Input:
 * 5
 *
 * Expected Output:
 * 13
 *
 * Sample Input:
 * 4
 *
 * Expected Output:
 * 7
 */
