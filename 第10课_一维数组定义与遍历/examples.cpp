// ============================================
// Lesson 10: 1D Array - Definition & Traversal
// Examples for classroom demonstration
// ============================================

// ---- Example 1: Store and Print 5 Scores (Array Basics) ----
// Input 5 math scores and print them in order.
#include <iostream>
using namespace std;

int main() {
    int a[5]; // Declare an array of 5 elements

    // Input: store scores into the array
    for (int i = 0; i < 5; i++) {
        cin >> a[i];
    }

    // Output: print each score
    for (int i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
 * Sample Input: 88 95 73 60 100
 *
 * Expected Output:
 * 88 95 73 60 100
 */

// ---- Example 2: Read N Numbers and Print (General Pattern) ----
// First line: integer n (how many numbers).
// Second line: n integers. Print them in order.
#include <iostream>
using namespace std;

int a[105]; // Declare globally, a bit larger for safety

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
 * Sample Input:
 * 4
 * 10 20 30 40
 *
 * Expected Output:
 * 10 20 30 40
 */

// ---- Example 3: Reverse Output (Traverse Backwards) ----
// Input n integers, print them in reverse order.
#include <iostream>
using namespace std;

int a[105];

int main() {
    int n;
    cin >> n;

    // Read in forward order
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Print in reverse order
    for (int i = n - 1; i >= 0; i--) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
 * Sample Input:
 * 5
 * 1 2 3 4 5
 *
 * Expected Output:
 * 5 4 3 2 1
 */
