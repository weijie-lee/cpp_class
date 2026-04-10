// ============================================
// Lesson 35: Introduction to DFS
// Practice solutions
// ============================================

// ---- Practice 1: Permutations of 1~N with Count ----
// Read N (N <= 7), output all permutations of 1~N in lexicographic order,
// then output the total number of permutations.
#include <iostream>
using namespace std;

int n;
int arr[10];
bool used[10];
int cnt = 0;  // Count total permutations

void dfs(int step) {
    if (step > n) {
        for (int j = 1; j <= n; j++) {
            if (j > 1) cout << " ";
            cout << arr[j];
        }
        cout << endl;
        cnt++;
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
    cout << cnt << endl;
    return 0;
}

/*
 * Sample Input: 3
 *
 * Expected Output:
 * 1 2 3
 * 1 3 2
 * 2 1 3
 * 2 3 1
 * 3 1 2
 * 3 2 1
 * 6
 */

// ---- Practice 2: All Two-Digit Numbers from 1~N ----
// Read N (2 <= N <= 9). Choose 2 different digits from 1~N to form
// two-digit numbers. Output all such numbers in ascending order, one per line.

/*
#include <iostream>
using namespace std;

int n;
int arr[3];
bool used[10];

void dfs(int step) {
    if (step > 2) {
        // Form a two-digit number: arr[1] is tens digit, arr[2] is ones digit
        cout << arr[1] * 10 + arr[2] << endl;
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
 * Sample Input: 3
 *
 * Expected Output:
 * 12
 * 13
 * 21
 * 23
 * 31
 * 32
 */

// ---- Practice 3: Restricted Permutation (Challenge) ----
// Read N (N <= 6). Output all permutations of 1~N in lexicographic order,
// but number 1 must NOT be placed in the first position.

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
            // Skip if trying to place 1 in the first position
            if (step == 1 && i == 1) continue;

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
 * Sample Input: 3
 *
 * Expected Output:
 * 2 1 3
 * 2 3 1
 * 3 1 2
 * 3 2 1
 */
