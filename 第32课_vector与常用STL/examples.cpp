// ============================================
// Lesson 32: Vector and Common STL
// Examples for classroom demonstration
// ============================================

// ---- Example 1: Dynamic Score Recording ----
// Read positive integers until 0 is entered (0 is not counted).
// Output all scores and the number of students.
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;
    int x;
    while (cin >> x) {
        if (x == 0) break;   // Stop when 0 is entered
        v.push_back(x);      // Add score to the vector
    }

    // Print all scores
    for (int i = 0; i < v.size(); i++) {
        if (i > 0) cout << " ";
        cout << v[i];
    }
    cout << endl;
    cout << v.size() << endl;  // Number of students

    return 0;
}

/*
 * Sample Input:
 * 88 95 72 100 65 0
 *
 * Expected Output:
 * 88 95 72 100 65
 * 5
 */

// ---- Example 2: Vector Sort and Find Min/Max ----
// Read n integers into a vector, sort ascending, then output max and min.

/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);  // Create a vector of size n
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Sort the vector (ascending)
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        if (i > 0) cout << " ";
        cout << v[i];
    }
    cout << endl;

    // After sorting: min is first, max is last
    cout << "max=" << v[v.size() - 1] << " min=" << v[0] << endl;

    return 0;
}
*/

/*
 * Sample Input:
 * 5
 * 3 1 4 1 5
 *
 * Expected Output:
 * 1 1 3 4 5
 * max=5 min=1
 */

// ---- Example 3: Count Distinct Numbers Using set ----
// Read n integers and count how many distinct values there are.

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
        s.insert(x);  // Duplicates are automatically ignored
    }
    cout << s.size() << endl;

    return 0;
}
*/

/*
 * Sample Input:
 * 7
 * 1 2 3 2 1 4 2
 *
 * Expected Output:
 * 4
 */

// ---- Example 4: Count Frequency of Each Number Using map ----
// Read n integers (range 1~100), output each number and its count
// in ascending order.

/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;  // Increment count for x
    }

    // map automatically sorts by key (ascending)
    for (auto it = cnt.begin(); it != cnt.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}
*/

/*
 * Sample Input:
 * 8
 * 3 1 2 3 1 3 2 1
 *
 * Expected Output:
 * 1 3
 * 2 2
 * 3 3
 */
