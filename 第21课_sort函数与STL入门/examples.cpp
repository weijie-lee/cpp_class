// ============================================
// Lesson 21: sort Function and Introduction to STL
// Examples for classroom demonstration
// ============================================

// ---- Example 1: Basic Sorting (Ascending) ----
// Read n integers, sort them in ascending order, and print them.
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
    sort(a, a + n);  // One line to sort!
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
 * 5 3 1 4 2
 *
 * Expected Output:
 * 1 2 3 4 5
 */

// ---- Example 2: Exam Scores (Descending) ----
// Read n math scores, sort them from highest to lowest, and print them.
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
    sort(a, a + n, greater<int>());  // Sort in descending order
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
 * 88 95 72 100 65 95
 *
 * Expected Output:
 * 100 95 95 88 72 65
 */

// ---- Example 3: Top Three Scores ----
// Long jump competition: n students compete, find and print the top 3 scores.
// If fewer than 3 students, print all scores.
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
    int top = 3;
    if (n < 3) top = n;  // Handle case with fewer than 3 people
    for (int i = 0; i < top; i++) {
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
 * 320 285 350 310 340
 *
 * Expected Output:
 * 350 340 320
 */
