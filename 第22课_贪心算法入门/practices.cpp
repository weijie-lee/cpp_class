// ============================================
// Lesson 22: Introduction to Greedy Algorithms
// Practice solutions
// ============================================

// ---- Practice 1: Change Variant (3 denominations) ----
// Coin denominations: 50, 20, 1 (unlimited). Given amount n, find minimum coins.
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int coins[] = {50, 20, 1};  // Denominations from large to small
    int total = 0;
    int remain = n;

    for (int i = 0; i < 3; i++) {
        int cnt = remain / coins[i];  // Use as many of this coin as possible
        total += cnt;
        remain %= coins[i];
    }

    cout << total << endl;

    return 0;
}

/*
 * Sample Input:
 * 73
 *
 * Expected Output:
 * 5
 */

// ---- Practice 2: Filling Candies (Greedy - pick smallest) ----
// A pocket can hold at most W grams. Given n candies with different weights,
// find the maximum number of candies that fit (greedy: pick lightest first).
/*
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, W;
    cin >> n >> W;

    int w[1005];
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    sort(w, w + n);  // Sort by weight ascending

    int count = 0;
    int currentWeight = 0;
    for (int i = 0; i < n; i++) {
        if (currentWeight + w[i] <= W) {
            currentWeight += w[i];
            count++;
        } else {
            break;  // Can't fit any more
        }
    }

    cout << count << endl;

    return 0;
}
*/

/*
 * Sample Input:
 * 5 10
 * 3 1 5 2 4
 *
 * Expected Output:
 * 4
 */

// ---- Practice 3: Water Queue (Classic Greedy) ----
// n people queue to get water. Each person takes a different amount of time.
// Arrange the order to minimize total waiting time.
// Waiting time = time from start of queue until the person STARTS getting water.
/*
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int t[1005];
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    sort(t, t + n);  // Greedy: shortest time first

    long long totalWait = 0;
    long long elapsed = 0;  // Time elapsed so far
    for (int i = 0; i < n; i++) {
        totalWait += elapsed;  // Person i waits for all previous people
        elapsed += t[i];       // Update elapsed time
    }

    cout << totalWait << endl;

    return 0;
}
*/

/*
 * Sample Input:
 * 3
 * 3 1 2
 *
 * Expected Output:
 * 4
 */

// ---- Practice 4: Thinking Problem (Greedy doesn't always work) ----
// Coin denominations: 1, 3, 4. Make 6 yuan.
// Greedy: 4+1+1 = 3 coins. Optimal: 3+3 = 2 coins.
// This shows greedy does NOT always give the optimal answer.
/*
#include <iostream>
using namespace std;

int main() {
    // Greedy approach: always pick the largest coin first
    int amount = 6;
    int coins_greedy[] = {4, 3, 1};
    int greedy_count = 0;
    int remain = amount;

    for (int i = 0; i < 3; i++) {
        greedy_count += remain / coins_greedy[i];
        remain %= coins_greedy[i];
    }
    cout << "Greedy result: " << greedy_count << " coins" << endl;

    // Brute-force: try all combinations to find the true minimum
    int best = 9999;
    for (int a = 0; a <= 6; a++) {          // Number of 4-yuan coins
        for (int b = 0; b <= 6; b++) {      // Number of 3-yuan coins
            for (int c = 0; c <= 6; c++) {  // Number of 1-yuan coins
                if (4 * a + 3 * b + 1 * c == 6) {
                    int total = a + b + c;
                    if (total < best) best = total;
                }
            }
        }
    }
    cout << "Optimal result: " << best << " coins" << endl;
    cout << "Greedy fails on this problem!" << endl;

    return 0;
}
*/

/*
 * Expected Output:
 * Greedy result: 3 coins
 * Optimal result: 2 coins
 * Greedy fails on this problem!
 */
