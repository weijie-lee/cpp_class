// ============================================
// Lesson 19: Bubble Sort
// Examples for classroom demonstration
// ============================================

// ---- Example 1: Basic Bubble Sort (Ascending) ----
// Input n integers, sort them in ascending order using bubble sort.

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[105];  // Array with extra space to prevent overflow
    // Read input
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Bubble sort: n-1 passes, each pass bubbles the largest to the end
    for (int i = 0; i < n - 1; i++) {        // Outer: n-1 passes
        for (int j = 0; j < n - 1 - i; j++) { // Inner: comparisons per pass
            if (a[j] > a[j + 1]) {            // If left > right, swap
                int temp = a[j];              // Three-step swap (temp variable)
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    // Output the sorted array
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";  // Space between numbers
        cout << a[i];
    }
    cout << endl;

    return 0;
}

/*
 * Sample Input:
 * 5
 * 5 2 8 1 4
 *
 * Expected Output:
 * 1 2 4 5 8
 */


// ---- Example 2: Bubble Sort with Pass-by-Pass Output ----
// Same as Example 1, but print the array state after each pass.

/*
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[105];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
        // Print the array after each pass
        cout << "Pass " << i + 1 << ": ";
        for (int k = 0; k < n; k++) {
            if (k > 0) cout << " ";
            cout << a[k];
        }
        cout << endl;
    }

    return 0;
}
*/

/*
 * Sample Input:
 * 5
 * 5 2 8 1 4
 *
 * Expected Output:
 * Pass 1: 2 5 1 4 8
 * Pass 2: 2 1 4 5 8
 * Pass 3: 1 2 4 5 8
 * Pass 4: 1 2 4 5 8
 */


// ---- Example 3: Bubble Sort (Descending) ----
// Sort n integers in descending order.
// Only difference: change > to < in the comparison.

/*
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[105];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Bubble sort (descending): swap when left < right
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] < a[j + 1]) {   // Changed to < for descending
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << a[i];
    }
    cout << endl;

    return 0;
}
*/

/*
 * Sample Input:
 * 4
 * 3 1 7 2
 *
 * Expected Output:
 * 7 3 2 1
 */
