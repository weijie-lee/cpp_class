// ============================================
// Lesson 28: Binary Search
// Practice solutions
// ============================================

// ---- Practice 1: Find a Marble ----
// n marbles with numbers sorted in ascending order.
// Find the 1-based position of marble x.
// If not found, output "No".
#include <iostream>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    int a[100005];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int left = 0, right = n - 1;
    int ans = -1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (a[mid] == x) {
            ans = mid + 1;  // convert to 1-based
            break;
        } else if (a[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (ans == -1) {
        cout << "No" << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}

/*
 * Sample Input:
 * 7 15
 * 3 7 11 15 20 25 30
 *
 * Expected Output:
 * 4
 *
 * Sample Input:
 * 7 12
 * 3 7 11 15 20 25 30
 *
 * Expected Output:
 * No
 */

// ---- Practice 2: Binary Search with Count ----
// Given a sorted array (no duplicates), determine if x exists.
// Output "Yes" or "No" on the first line.
// Output the number of comparisons on the second line.
#if 0
#include <iostream>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    int a[100005];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int left = 0, right = n - 1;
    bool found = false;
    int cnt = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        cnt++;

        if (a[mid] == x) {
            found = true;
            break;
        } else if (a[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (found) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    cout << cnt << endl;

    return 0;
}
#endif

/*
 * Sample Input:
 * 10 38
 * 2 5 8 12 16 23 38 42 56 72
 *
 * Expected Output:
 * Yes
 * 3
 */

// ---- Practice 3: Library Book Search ----
// n books sorted by ID. m students each want to borrow
// a book with ID x. Output "Yes" if the book exists,
// otherwise "No".
#if 0
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int a[100005];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    while (m--) {
        int x;
        cin >> x;

        // binary search for x
        int left = 0, right = n - 1;
        bool found = false;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (a[mid] == x) {
                found = true;
                break;
            } else if (a[mid] < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (found) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
#endif

/*
 * Sample Input:
 * 8 4
 * 101 203 305 408 512 619 723 856
 * 305
 * 100
 * 856
 * 500
 *
 * Expected Output:
 * Yes
 * No
 * Yes
 * No
 */
