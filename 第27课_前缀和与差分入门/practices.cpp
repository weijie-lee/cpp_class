// ============================================
// Lesson 27: Prefix Sum & Difference Arrays
// Practice solutions
// ============================================

// ---- Practice 1: Prefix Sum Basics (Paper Exercise) ----
// Pocket money for 7 days: 3 1 4 1 5 9 2
// 1) Write prefix sum array sum[0]..sum[7]
// 2) Compute sum of day 3 to day 6
// 3) Compute sum of day 1 to day 7
//
// Answers:
// 1) sum[]: 0, 3, 4, 8, 9, 14, 23, 25
// 2) sum[6] - sum[2] = 23 - 4 = 19
// 3) sum[7] - sum[0] = 25 - 0 = 25
//
// This is a paper exercise. The program below verifies the answers.
#include <iostream>
using namespace std;

int main() {
    int a[] = {0, 3, 1, 4, 1, 5, 9, 2};  // 1-indexed
    long long sum[8];
    sum[0] = 0;
    for (int i = 1; i <= 7; i++) {
        sum[i] = sum[i - 1] + a[i];
    }

    // print prefix sum array
    cout << "Prefix sum array: ";
    for (int i = 0; i <= 7; i++) {
        cout << sum[i];
        if (i < 7) cout << " ";
    }
    cout << endl;

    // day 3 to day 6
    cout << "Sum of day 3 to 6: " << sum[6] - sum[2] << endl;

    // day 1 to day 7
    cout << "Sum of day 1 to 7: " << sum[7] - sum[0] << endl;

    return 0;
}

/*
 * Expected Output:
 * Prefix sum array: 0 3 4 8 9 14 23 25
 * Sum of day 3 to 6: 19
 * Sum of day 1 to 7: 25
 */

// ---- Practice 2: Prefix Sum - Range Query (Coding) ----
// Read n integers and q queries. For each query (l, r),
// output the sum of range [l, r].
#if 0
#include <iostream>
using namespace std;

int a[100005];
long long sum[100005];

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // build prefix sum
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
#endif

/*
 * Sample Input:
 * 5 3
 * 2 6 1 8 3
 * 1 3
 * 2 5
 * 3 3
 *
 * Expected Output:
 * 9
 * 18
 * 1
 */

// ---- Practice 3: Difference Array Basics (Paper Exercise) ----
// 6 numbers initially all 0. Three operations:
// Op 1: add 3 to positions 2~5
// Op 2: add 2 to positions 1~3
// Op 3: add 1 to positions 4~6
// Write the difference array after all operations,
// then compute prefix sum to restore the final array.
//
// Answer:
// Difference array d[1..7]: +2 +3 0 -1 0 -3 -1
// Final array: 2 5 5 4 4 1
//
// This program verifies the answer.
#if 0
#include <iostream>
using namespace std;

int main() {
    int d[8] = {0};  // difference array, indices 1..7

    // Op 1: add 3 to [2, 5]
    d[2] += 3;
    d[6] -= 3;

    // Op 2: add 2 to [1, 3]
    d[1] += 2;
    d[4] -= 2;

    // Op 3: add 1 to [4, 6]
    d[4] += 1;
    d[7] -= 1;

    // prefix sum to restore
    cout << "Final array: ";
    for (int i = 1; i <= 6; i++) {
        d[i] = d[i] + d[i - 1];
        cout << d[i];
        if (i < 6) cout << " ";
    }
    cout << endl;

    return 0;
}
#endif

/*
 * Expected Output:
 * Final array: 2 5 5 4 4 1
 */

// ---- Practice 4: Difference Array - Range Addition (Coding) ----
// Read n and m. Then m operations, each giving l, r, v
// meaning add v to every element in [l, r].
// Output the final array.
#if 0
#include <iostream>
using namespace std;

int d[100005];

int main() {
    int n, m;
    cin >> n >> m;

    while (m--) {
        int l, r, v;
        cin >> l >> r >> v;
        d[l] += v;
        d[r + 1] -= v;
    }

    // prefix sum to restore
    for (int i = 1; i <= n; i++) {
        d[i] = d[i] + d[i - 1];
        cout << d[i];
        if (i < n) cout << " ";
    }
    cout << endl;

    return 0;
}
#endif

/*
 * Sample Input:
 * 6 3
 * 2 5 3
 * 1 3 2
 * 4 6 1
 *
 * Expected Output:
 * 2 5 5 4 4 1
 */
