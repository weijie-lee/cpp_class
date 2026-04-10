// ============================================
// Lesson 21: sort Function and Introduction to STL
// Practice solutions
// ============================================

// ---- Practice 1: Line Up (Ascending Sort) ----
// Kindergarten children line up. Read n heights, sort from shortest to tallest.
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[1005];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);  // Default ascending sort (shortest to tallest)
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << a[i];
    }
    cout << endl;
    return 0;
}

/*
 * Sample Input:
 * 4
 * 130 115 128 120
 *
 * Expected Output:
 * 115 120 128 130
 */

// ---- Practice 2: Reverse Order Output ----
// Read n integers, print them in descending order, one number per line.
/*
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[1005];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n, greater<int>());  // Sort descending
    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;  // One number per line
    }
    return 0;
}
*/

/*
 * Sample Input:
 * 3
 * 7 2 9
 *
 * Expected Output:
 * 9
 * 7
 * 2
 */

// ---- Practice 3: Remove Highest and Lowest Scores ----
// Singing competition: n judges give scores (n >= 3).
// Remove the highest and lowest scores, print the remaining scores in ascending order.
/*
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[1005];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);  // Sort ascending: a[0] is min, a[n-1] is max
    // Print from a[1] to a[n-2], skipping the lowest and highest
    for (int i = 1; i <= n - 2; i++) {
        if (i > 1) cout << " ";
        cout << a[i];
    }
    cout << endl;
    return 0;
}
*/

/*
 * Sample Input:
 * 5
 * 90 85 92 88 95
 *
 * Expected Output:
 * 88 90 92
 */
