// ============================================
// Lesson 27: Prefix Sum & Difference Arrays
// Examples for classroom demonstration
// ============================================

// ---- Example 1: Prefix Sum - Range Query ----
// Given n integers and q queries, for each query (l, r),
// output the sum of elements in range [l, r].
#include <iostream>
using namespace std;

int a[100005];
long long sum[100005];  // prefix sum may be large, use long long

int main() {
    int n, q;
    cin >> n >> q;

    // read array (1-indexed)
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // build prefix sum array
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }

    // answer queries
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << endl;
    }

    return 0;
}

/*
 * Sample Input:
 * 5 3
 * 400 350 380 420 390
 * 2 4
 * 1 5
 * 3 3
 *
 * Expected Output:
 * 1150
 * 1940
 * 380
 */

// ---- Example 2: Maximum Sum of Consecutive K Days ----
// Given n daily temperature changes (positive or negative),
// find the maximum sum of any consecutive k days.
#if 0
#include <iostream>
using namespace std;

int a[100005];
long long sum[100005];

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // build prefix sum
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }

    // enumerate all windows of length k, find the maximum sum
    long long maxSum = sum[k] - sum[0];  // first window [1, k]
    for (int i = 2; i + k - 1 <= n; i++) {
        long long cur = sum[i + k - 1] - sum[i - 1];
        if (cur > maxSum) {
            maxSum = cur;
        }
    }

    cout << maxSum << endl;

    return 0;
}
#endif

/*
 * Sample Input:
 * 6 3
 * -2 5 3 -1 4 2
 *
 * Expected Output:
 * 7
 */

// ---- Example 3: Difference Array - Range Addition ----
// n students (numbered 1 to n), initial scores are all 0.
// After m operations, each adding v to students in range [l, r],
// output the final score of each student.
#if 0
#include <iostream>
using namespace std;

int d[100005];  // difference array

int main() {
    int n, m;
    cin >> n >> m;

    // m operations
    while (m--) {
        int l, r, v;
        cin >> l >> r >> v;
        d[l] += v;        // open the faucet
        d[r + 1] -= v;    // close the faucet
    }

    // compute prefix sum of difference array to restore final scores
    for (int i = 1; i <= n; i++) {
        d[i] = d[i] + d[i - 1];  // prefix sum to restore
        cout << d[i];
        if (i < n) cout << " ";
    }
    cout << endl;

    return 0;
}
#endif

/*
 * Sample Input:
 * 5 2
 * 2 4 5
 * 1 3 3
 *
 * Expected Output:
 * 3 8 8 5 0
 */
