// ============================================
// Lesson 34: Phase 3 Review and Test
// Reference answers for programming problems
// (Problems 8, 9, 10 from the test paper)
// ============================================

// ---- Problem 8: String Statistics (15 pts) ----
// Count uppercase and lowercase letters in a string (letters only, no spaces).
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int upper = 0, lower = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            upper++;
        } else if (s[i] >= 'a' && s[i] <= 'z') {
            lower++;
        }
    }

    cout << upper << " " << lower << endl;
    return 0;
}

/*
 * Sample Input:
 * HelloWorld
 *
 * Expected Output:
 * 2 8
 */

// ---- Problem 9: Parenthesis Matching (15 pts) ----
// Check if a string of '(' and ')' is correctly matched.
// Output "Yes" or "No".

/*
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string s;
    cin >> s;

    stack<char> st;
    bool ok = true;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push('(');
        } else {  // s[i] == ')'
            if (st.empty()) {
                ok = false;
                break;
            }
            st.pop();
        }
    }

    if (ok && st.empty()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
*/

/*
 * Sample Input 1: (()())
 * Expected Output: Yes
 *
 * Sample Input 2: (()
 * Expected Output: No
 */

// ---- Problem 10: Score Ranking (20 pts) ----
// Read n students (name and score). Sort by score descending.
// If scores are equal, preserve the original input order (stable sort).

/*
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Student {
    string name;
    int score;
    int id;  // Record input order for stable sorting
};

bool cmp(Student a, Student b) {
    if (a.score != b.score) return a.score > b.score;  // Higher score first
    return a.id < b.id;  // Same score: preserve input order
}

int main() {
    int n;
    cin >> n;

    Student stu[105];
    for (int i = 0; i < n; i++) {
        cin >> stu[i].name >> stu[i].score;
        stu[i].id = i;
    }

    sort(stu, stu + n, cmp);

    for (int i = 0; i < n; i++) {
        cout << stu[i].name << " " << stu[i].score << endl;
    }

    return 0;
}
*/

/*
 * Sample Input:
 * 4
 * Alice 88
 * Bob 95
 * Cindy 88
 * David 72
 *
 * Expected Output:
 * Bob 95
 * Alice 88
 * Cindy 88
 * David 72
 */
