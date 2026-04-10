// ============================================
// Lesson 28: Binary Search
// Examples for classroom demonstration
// ============================================

// ---- Example 1: Basic Binary Search ----
// Given a sorted array (ascending) and a target x,
// output the index (0-based) of x, or -1 if not found.
#include <iostream>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    int a[100005];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // binary search
    int left = 0, right = n - 1;
    int ans = -1;  // default: not found

    while (left <= right) {
        int mid = (left + right) / 2;

        if (a[mid] == x) {
            ans = mid;        // found it
            break;
        } else if (a[mid] < x) {
            left = mid + 1;   // x is in the right half
        } else {
            right = mid - 1;  // x is in the left half
        }
    }

    cout << ans << endl;
    return 0;
}

/*
 * Sample Input:
 * 10 23
 * 2 5 8 12 16 23 38 42 56 72
 *
 * Expected Output:
 * 5
 */

// ---- Example 2: Binary Search with Comparison Count ----
// Given a sorted array and q queries, for each query x,
// output its 1-based index (or 0 if not found) and the
// number of comparisons made during the search.
#if 0
#include <iostream>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    int a[100005];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    while (q--) {
        int x;
        cin >> x;

        int left = 0, right = n - 1;
        int ans = 0;   // 0 means not found (1-based indexing)
        int cnt = 0;   // comparison counter

        while (left <= right) {
            int mid = (left + right) / 2;
            cnt++;  // count each comparison

            if (a[mid] == x) {
                ans = mid + 1;  // convert to 1-based index
                break;
            } else if (a[mid] < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        cout << ans << " " << cnt << endl;
    }

    return 0;
}
#endif

/*
 * Sample Input:
 * 8 3
 * 1 3 5 7 9 11 13 15
 * 5 10 13
 *
 * Expected Output:
 * 3 3
 * 0 4
 * 7 3
 */

// ---- Example 3: Find First Element >= x ----
// Given a sorted array (may have duplicates),
// find the 1-based index of the first element >= x.
// If all elements are less than x, output n+1.
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
    int ans = n + 1;  // default: all elements < x

    while (left <= right) {
        int mid = (left + right) / 2;

        if (a[mid] >= x) {
            ans = mid + 1;      // record this position (1-based)
            right = mid - 1;    // keep searching left for earlier one
        } else {
            left = mid + 1;     // too small, search right
        }
    }

    cout << ans << endl;
    return 0;
}
#endif

/*
 * Sample Input:
 * 8 5
 * 1 2 4 4 5 5 7 9
 *
 * Expected Output:
 * 5
 */
