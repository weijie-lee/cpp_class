// ============================================
// Lesson 19: Bubble Sort
// Practice solutions
// ============================================

// ---- Practice 1: Cyclic Right Shift of Three Variables ----
// Input three integers a, b, c. Cyclic right shift: a gets c's value,
// b gets a's value, c gets b's value. Output the result.

#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    // Cyclic right shift using a temp variable
    int temp = c;  // Save c first
    c = b;
    b = a;
    a = temp;

    cout << a << " " << b << " " << c << endl;

    return 0;
}

/*
 * Sample Input:
 * 1 2 3
 *
 * Expected Output:
 * 3 1 2
 */


// ---- Practice 2: Basic Bubble Sort (Consolidation) ----
// Input n integers, sort them ascending using bubble sort.

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

    // Bubble sort (ascending)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
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
 * 6
 * 64 34 25 12 22 11
 *
 * Expected Output:
 * 11 12 22 25 34 64
 */


// ---- Practice 3: Find the K-th Largest Number ----
// Input n integers and k, sort descending, output the k-th largest.

/*
#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int a[105];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Bubble sort (descending)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] < a[j + 1]) {  // Swap when left < right for descending
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    // After descending sort, a[k-1] is the k-th largest
    cout << a[k - 1] << endl;

    return 0;
}
*/

/*
 * Sample Input:
 * 5 2
 * 3 1 7 2 5
 *
 * Expected Output:
 * 5
 */


// ---- Practice 4: Count the Number of Swaps ----
// Sort n integers ascending with bubble sort.
// Output the sorted array and the total number of swaps.

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

    int cnt = 0;  // Swap counter
    // Bubble sort with swap counting
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                cnt++;  // Increment swap counter
            }
        }
    }

    // Output sorted array
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << a[i];
    }
    cout << endl;

    // Output total swap count
    cout << cnt << endl;

    return 0;
}
*/

/*
 * Sample Input:
 * 5
 * 5 2 8 1 4
 *
 * Expected Output:
 * 1 2 4 5 8
 * 6
 */
