// ============================================
// Lesson 35: Introduction to DFS
// Examples for classroom demonstration
// ============================================

// ---- Example 1: Permutations of 1~3 (Core Intro) ----
// Output all permutations of 1, 2, 3 in lexicographic order.
// Demonstrates the DFS template: select, mark, recurse, backtrack.
#include <iostream>
using namespace std;

int arr[4];      // arr[1..3]: the number placed at each position
bool used[4];    // used[i] = true means number i is already chosen

// dfs(step): fill the step-th position
void dfs(int step) {
    // Base case: all 3 positions are filled
    if (step > 3) {
        cout << arr[1] << " " << arr[2] << " " << arr[3] << endl;
        return;
    }

    // Try each number from 1 to 3
    for (int i = 1; i <= 3; i++) {
        if (!used[i]) {          // If number i hasn't been used
            arr[step] = i;       // Place i at position step
            used[i] = true;      // Mark i as used

            dfs(step + 1);       // Recurse to fill the next position

            used[i] = false;     // Backtrack: unmark i
        }
    }
}

int main() {
    dfs(1);  // Start filling from position 1
    return 0;
}

/*
 * Expected Output:
 * 1 2 3
 * 1 3 2
 * 2 1 3
 * 2 3 1
 * 3 1 2
 * 3 2 1
 */

// ---- Example 2: Permutations of 1~N (Generalized) ----
// Read N (1 <= N <= 8), output all permutations of 1~N in lexicographic order.

/*
#include <iostream>
using namespace std;

int n;
int arr[10];
bool used[10];

void dfs(int step) {
    if (step > n) {
        for (int j = 1; j <= n; j++) {
            if (j > 1) cout << " ";
            cout << arr[j];
        }
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            arr[step] = i;
            used[i] = true;

            dfs(step + 1);

            used[i] = false;  // Backtrack
        }
    }
}

int main() {
    cin >> n;
    dfs(1);
    return 0;
}
*/

/*
 * Sample Input: 4
 *
 * Expected Output (first 6 of 24 lines):
 * 1 2 3 4
 * 1 2 4 3
 * 1 3 2 4
 * 1 3 4 2
 * 1 4 2 3
 * 1 4 3 2
 * ... (24 lines total)
 */

// ---- Example 3: Choose M from N (Partial Permutation) ----
// Read N and M (1 <= M <= N <= 8). Output all ways to arrange M numbers
// chosen from 1~N. Order matters. Output in lexicographic order.

/*
#include <iostream>
using namespace std;

int n, m;
int arr[10];
bool used[10];

void dfs(int step) {
    if (step > m) {        // Only need to fill m positions
        for (int j = 1; j <= m; j++) {
            if (j > 1) cout << " ";
            cout << arr[j];
        }
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            arr[step] = i;
            used[i] = true;

            dfs(step + 1);

            used[i] = false;  // Backtrack
        }
    }
}

int main() {
    cin >> n >> m;
    dfs(1);
    return 0;
}
*/

/*
 * Sample Input: 4 2
 *
 * Expected Output:
 * 1 2
 * 1 3
 * 1 4
 * 2 1
 * 2 3
 * 2 4
 * 3 1
 * 3 2
 * 3 4
 * 4 1
 * 4 2
 * 4 3
 */
