// ============================================
// Lesson 20: Selection Sort & Insertion Sort
// Examples for classroom demonstration
// ============================================

// ---- Example 1: Selection Sort (Ascending) ----
// Input n integers, sort them ascending using selection sort.
// Core idea: each pass selects the minimum from unsorted region
// and places it at the end of the sorted region.

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[1005];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Selection sort: each pass finds the minimum in unsorted region
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;  // Assume the first unsorted element is the minimum
        // Scan the unsorted region for the real minimum
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIdx]) {
                minIdx = j;  // Found a smaller one, update index
            }
        }
        // Swap the minimum to position i (end of sorted region)
        if (minIdx != i) {
            int temp = a[i];
            a[i] = a[minIdx];
            a[minIdx] = temp;
        }
    }

    // Output sorted array
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
 * 1 3 4 5 8
 */


// ---- Example 2: Insertion Sort (Ascending) ----
// Input n integers, sort them ascending using insertion sort.
// Core idea: like sorting playing cards - pick each card and
// insert it into the correct position among already sorted cards.

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

    // Insertion sort: start from the 2nd element (index 1)
    for (int i = 1; i < n; i++) {
        int temp = a[i];  // Take the new card out and save it
        int j = i - 1;     // Start comparing from the card to its left
        // Shift larger cards to the right to make room
        while (j >= 0 && a[j] > temp) {
            a[j + 1] = a[j];  // Push the larger card right
            j--;                // Continue looking left
        }
        a[j + 1] = temp;  // Insert the new card at the correct position
    }

    // Output sorted array
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
 * 1 3 4 5 8
 */


// ---- Example 3: Three Sorting Methods in One Program ----
// Input n integers and k (1, 2, or 3).
// k=1: bubble sort, k=2: selection sort, k=3: insertion sort.

/*
#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int a[1005];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (k == 1) {
        // Bubble sort (from Lesson 19)
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (a[j] > a[j + 1]) {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
    } else if (k == 2) {
        // Selection sort
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
    } else {
        // Insertion sort
        for (int i = 1; i < n; i++) {
            int temp = a[i];
            int j = i - 1;
            while (j >= 0 && a[j] > temp) {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = temp;
        }
    }

    // Output
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
 * 5 2
 * 4 2 7 1 3
 *
 * Expected Output:
 * 1 2 3 4 7
 */
