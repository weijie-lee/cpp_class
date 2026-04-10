// ============================================
// Lesson 32: Vector and Common STL
// Practice solutions
// ============================================

// ---- Practice 1: Reverse Output ----
// Read positive integers until -1 (not counted). Output them in reverse order.
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;
    int x;
    while (cin >> x) {
        if (x == -1) break;
        v.push_back(x);
    }

    // Traverse from the last element to the first
    for (int i = v.size() - 1; i >= 0; i--) {
        if (i < (int)v.size() - 1) cout << " ";
        cout << v[i];
    }
    cout << endl;

    return 0;
}

/*
 * Sample Input:
 * 5 3 8 2 7 -1
 *
 * Expected Output:
 * 7 2 8 3 5
 */

// ---- Practice 2: Deduplicate and Sort ----
// Read n integers, remove duplicates, and output in ascending order.

/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);  // set automatically deduplicates and sorts
    }

    bool first = true;
    for (auto it = s.begin(); it != s.end(); it++) {
        if (!first) cout << " ";
        cout << *it;
        first = false;
    }
    cout << endl;

    return 0;
}
*/

/*
 * Sample Input:
 * 6
 * 5 3 5 1 3 2
 *
 * Expected Output:
 * 1 2 3 5
 */

// ---- Practice 3: Score Management Program ----
// Read exam scores (positive integers) until 0.
// Output: total count, highest score, lowest score,
// and all scores sorted from high to low.

/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;
    int x;
    while (cin >> x) {
        if (x == 0) break;
        v.push_back(x);
    }

    // Sort descending
    sort(v.begin(), v.end(), greater<int>());

    cout << v.size() << endl;           // Total exams
    cout << v[0] << endl;              // Highest (first after desc sort)
    cout << v[v.size() - 1] << endl;   // Lowest (last after desc sort)

    for (int i = 0; i < v.size(); i++) {
        if (i > 0) cout << " ";
        cout << v[i];
    }
    cout << endl;

    return 0;
}
*/

/*
 * Sample Input:
 * 85 92 78 95 88 0
 *
 * Expected Output:
 * 5
 * 95
 * 78
 * 95 92 88 85 78
 */
