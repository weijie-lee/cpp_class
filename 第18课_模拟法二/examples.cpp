// ============================================
// Lesson 18: Simulation (Part II) - Array-based Simulation
// Examples for classroom demonstration
// ============================================

// ---- Example 1: Josephus Problem (Count-out Game) ----
// n people (numbered 1 to n) stand in a circle. Starting from person 1,
// they count off. Whoever says m is eliminated. Output the last survivor.

#include <iostream>
using namespace std;

int alive[105];

int main() {
    int n, m;
    cin >> n >> m;

    // Initialize: everyone is alive (1 = alive, 0 = eliminated)
    for (int i = 0; i < n; i++) {
        alive[i] = 1;
    }

    int left = n;   // Remaining people
    int cnt = 0;    // Current count
    int pos = 0;    // Current position (starting from index 0)

    while (left > 1) {
        if (alive[pos] == 1) {  // This person is still alive
            cnt++;
            if (cnt == m) {     // Counted to m, eliminate!
                alive[pos] = 0;
                left--;
                cnt = 0;        // Reset counter
            }
        }
        pos = (pos + 1) % n;   // Move to next position (wrap around)
    }

    // Find the last person standing
    for (int i = 0; i < n; i++) {
        if (alive[i] == 1) {
            cout << i + 1 << endl;  // Output 1-based index
            break;
        }
    }

    return 0;
}

/*
 * Sample Input:
 * 8 3
 *
 * Expected Output:
 * 7
 */


// ---- Example 2: Caesar Cipher Encryption ----
// Input a lowercase string s and an integer k (1 <= k <= 25).
// Shift each letter forward by k positions (wrap around from z to a).

/*
#include <iostream>
#include <cstring>
using namespace std;

char s[105];

int main() {
    int k;
    cin >> s >> k;

    int len = strlen(s);  // Get string length

    for (int i = 0; i < len; i++) {
        // Step 1: Convert letter to number (a=0, b=1, ..., z=25)
        int num = s[i] - 'a';
        // Step 2: Add offset and wrap around using modulo
        int newNum = (num + k) % 26;
        // Step 3: Convert number back to letter
        char newChar = newNum + 'a';
        cout << newChar;
    }
    cout << endl;

    return 0;
}
*/

/*
 * Sample Input:
 * hello
 * 3
 *
 * Expected Output:
 * khoor
 */


// ---- Example 3: Debugging Demo - Buggy Josephus Code ----
// This example shows a buggy version where cnt is NOT reset after elimination.
// Students learn to add debug prints to find bugs.
// The bug: missing "cnt = 0;" after eliminating a person.

/*
#include <iostream>
using namespace std;

int alive[105];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        alive[i] = 1;
    }

    int left = n;
    int cnt = 0;
    int pos = 0;

    while (left > 1) {
        if (alive[pos] == 1) {
            cnt++;
            // DEBUG: print current state to find the bug
            cout << "DEBUG: pos=" << pos << " cnt=" << cnt << endl;
            if (cnt == m) {
                alive[pos] = 0;
                left--;
                cout << "DEBUG: eliminated pos=" << pos << " left=" << left << endl;
                // BUG: forgot to reset cnt to 0 here!
                // Fix: uncomment the line below
                // cnt = 0;
            }
        }
        pos = (pos + 1) % n;
    }

    for (int i = 0; i < n; i++) {
        if (alive[i] == 1) {
            cout << i + 1 << endl;
            break;
        }
    }

    return 0;
}
*/

/*
 * Sample Input:
 * 5 2
 *
 * Expected Output (with bug fix):
 * 3
 *
 * Note: This example is for debugging demonstration.
 * The DEBUG lines show how cnt keeps growing without being reset.
 * Adding "cnt = 0;" after the elimination fixes the bug.
 */
