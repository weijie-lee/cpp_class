// ============================================
// Lesson 31: Stack and Queue (STL)
// Practice solutions
// ============================================

// ---- Practice 1: Reverse Output Using Stack ----
// Read n integers, use a stack to output them in reverse order.
#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.push(x);
    }

    // Pop all elements — they come out in reverse order
    while (!s.empty()) {
        cout << s.top();
        s.pop();
        if (!s.empty()) cout << " ";
    }
    cout << endl;

    return 0;
}

/*
 * Sample Input:
 * 5
 * 10 20 30 40 50
 *
 * Expected Output:
 * 50 40 30 20 10
 */

// ---- Practice 2: Counting Off — Queue Elimination ----
// n people stand in a line (numbered 1~n), counting from person 1.
// Odd count → stay (go to back of queue); Even count → leave.
// Output the leaving order.

/*
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    int count = 0;
    while (!q.empty()) {
        int person = q.front();
        q.pop();
        count++;

        if (count % 2 == 0) {
            // Even count — person leaves
            cout << person << " ";
        } else {
            // Odd count — person goes back to the queue
            q.push(person);
        }
    }
    cout << endl;

    return 0;
}
*/

/*
 * Sample Input:
 * 5
 *
 * Expected Output:
 * 2 4 1 5 3
 */

// ---- Practice 3: Enhanced Parenthesis Matching ----
// Check if a string with '(', ')', '[', ']' (and other characters) has
// correctly matched brackets. Other characters are ignored.

/*
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string str;
    getline(cin, str);

    stack<char> s;
    bool ok = true;

    for (int i = 0; i < str.size(); i++) {
        char c = str[i];
        if (c == '(' || c == '[') {
            s.push(c);
        } else if (c == ')') {
            if (s.empty() || s.top() != '(') {
                ok = false;
                break;
            }
            s.pop();
        } else if (c == ']') {
            if (s.empty() || s.top() != '[') {
                ok = false;
                break;
            }
            s.pop();
        }
        // Other characters are ignored
    }

    if (!s.empty()) ok = false;

    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
*/

/*
 * Sample Input: (a+b)*[c-d]
 * Expected Output: Yes
 *
 * Sample Input: ([)]
 * Expected Output: No
 */

// ---- Practice 4: Printer Task Queue ----
// n print tasks, each taking t[i] minutes.
// Printer processes tasks in FIFO order.
// Output the completion time of each task.

/*
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    queue<int> q;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        q.push(t);
    }

    int currentTime = 0;
    bool first = true;
    while (!q.empty()) {
        currentTime += q.front();  // Add task duration
        q.pop();

        if (!first) cout << " ";
        cout << currentTime;
        first = false;
    }
    cout << endl;

    return 0;
}
*/

/*
 * Sample Input:
 * 3
 * 5 3 7
 *
 * Expected Output:
 * 5 8 15
 */
