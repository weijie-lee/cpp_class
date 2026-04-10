// ============================================
// Lesson 22: Introduction to Greedy Algorithms
// Examples for classroom demonstration
// ============================================

// ---- Example 1: Making Change (Minimum Coins) ----
// Given coin denominations 10, 5, 2, 1 (unlimited supply),
// find the minimum number of coins to make n yuan.
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int coins[] = {10, 5, 2, 1};  // Denominations from large to small
    int count[4] = {0};           // Number of each coin used
    int total = 0;                // Total coin count
    int remain = n;               // Remaining amount

    for (int i = 0; i < 4; i++) {
        count[i] = remain / coins[i];  // Use as many large coins as possible
        remain = remain % coins[i];    // Update remaining amount
        total = total + count[i];      // Accumulate total count
    }

    // Print result
    for (int i = 0; i < 4; i++) {
        cout << coins[i] << " yuan coins: " << count[i] << endl;
    }
    cout << "Minimum coins needed: " << total << endl;

    return 0;
}

/*
 * Sample Input:
 * 36
 *
 * Expected Output:
 * 10 yuan coins: 3
 * 5 yuan coins: 1
 * 2 yuan coins: 0
 * 1 yuan coins: 1
 * Minimum coins needed: 5
 */

// ---- Example 2: Activity Selection (Simplified) ----
// Given n activities with start and end times, find the maximum number
// of non-overlapping activities. An activity can start right when another ends.
/*
#include <iostream>
#include <algorithm>
using namespace std;

struct Activity {
    int start;  // Start time
    int end;    // End time
};

// Comparison function: sort by end time ascending
bool cmp(Activity a, Activity b) {
    return a.end < b.end;
}

int main() {
    int n;
    cin >> n;

    Activity a[105];
    for (int i = 0; i < n; i++) {
        cin >> a[i].start >> a[i].end;
    }

    // Step 1: Sort by end time (greedy preprocessing)
    sort(a, a + n, cmp);

    // Step 2: Greedy selection
    int count = 1;           // Always pick the first activity
    int lastEnd = a[0].end;  // Track end time of last selected activity

    for (int i = 1; i < n; i++) {
        if (a[i].start >= lastEnd) {  // No conflict, select it
            count++;
            lastEnd = a[i].end;       // Update end time
        }
    }

    cout << count << endl;

    return 0;
}
*/

/*
 * Sample Input:
 * 5
 * 8 10
 * 9 11
 * 10 12
 * 11 13
 * 8 9
 *
 * Expected Output:
 * 3
 */
