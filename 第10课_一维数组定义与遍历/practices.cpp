// ============================================
// Lesson 10: 1D Array - Definition & Traversal
// Practice solutions
// ============================================

// ---- Practice 1: Read and Print N Numbers (Basic) ----
// Input n (n <= 100), then n integers. Print them separated by spaces.
#include <iostream>
using namespace std;

int a[105];

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
 * 3
 * 10 20 30
 *
 * Expected Output:
 * 10 20 30
 */

// ---- Practice 2: Reverse Output (Backward Traversal) ----
// Input n (n <= 100), then n integers. Print them in reverse order.
#include <iostream>
using namespace std;

int a[105];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
 * Sample Input:
 * 4
 * 5 8 2 9
 *
 * Expected Output:
 * 9 2 8 5
 */

// ---- Practice 3: Print Elements at Even Indices (Step Traversal) ----
// Input n (n <= 100), then n integers.
// Print elements at even indices (0, 2, 4, ...).
#include <iostream>
using namespace std;

int a[105];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Output elements at index 0, 2, 4, ...
    for (int i = 0; i < n; i += 2) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
 * Sample Input:
 * 6
 * 10 20 30 40 50 60
 *
 * Expected Output:
 * 10 30 50
 */
