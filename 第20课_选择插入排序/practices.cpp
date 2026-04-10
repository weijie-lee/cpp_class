// ============================================
// Lesson 20: Selection Sort & Insertion Sort
// Practice solutions
// ============================================

// ---- Practice 1: Selection Sort (Descending) ----
// Input n integers, sort them descending using selection sort.
// Change: find the MAXIMUM each pass instead of minimum.

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[1005];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Selection sort (descending): find the maximum each pass
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;  // Assume first unsorted element is the largest
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[maxIdx]) {  // Find the larger one
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            int temp = a[i];
            a[i] = a[maxIdx];
            a[maxIdx] = temp;
        }
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << a[i];
    }
    cout << endl;

    return 0;
}

/*
 * Sample Input:
 * 5
 * 5 3 8 1 4
 *
 * Expected Output:
 * 8 5 4 3 1
 */


// ---- Practice 2: Insertion Sort (Descending) ----
// Input n integers, sort them descending using insertion sort.
// Change: shift when left card is SMALLER than the new card.

/*
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[1005];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Insertion sort (descending): smaller cards move right
    for (int i = 1; i < n; i++) {
        int temp = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] < temp) {  // Changed > to < for descending
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
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
 * 5
 * 5 3 8 1 4
 *
 * Expected Output:
 * 8 5 4 3 1
 */


// ---- Practice 3: Sort and Remove Duplicates ----
// Input n integers (may have duplicates), sort ascending using selection sort,
// then output without duplicates.

/*
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[1005];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Selection sort (ascending)
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            int temp = a[i];
            a[i] = a[minIdx];
            a[minIdx] = temp;
        }
    }

    // Output sorted array, skipping duplicates
    for (int i = 0; i < n; i++) {
        // Skip if current element equals the previous one
        if (i > 0 && a[i] == a[i - 1]) continue;
        if (i > 0 && a[i] != a[i - 1]) cout << " ";
        // Special case: always print the first element
        if (i == 0) cout << a[i];
        else cout << a[i];
    }
    cout << endl;

    return 0;
}
*/

/*
 * Sample Input:
 * 7
 * 3 1 4 1 5 3 2
 *
 * Expected Output:
 * 1 2 3 4 5
 */


// ---- Practice 4 (Challenge): Show Insertion Sort Process ----
// Input n integers, perform insertion sort.
// After each insertion, output the entire array state.

/*
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[1005];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Insertion sort with process output
    for (int i = 1; i < n; i++) {
        int temp = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > temp) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;

        // Print the entire array after each insertion
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
 * 5 3 8 1 4
 *
 * Expected Output:
 * 3 5 8 1 4
 * 3 5 8 1 4
 * 1 3 5 8 4
 * 1 3 4 5 8
 */
