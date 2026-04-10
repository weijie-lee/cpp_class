// ============================================
// Lesson 31: Stack and Queue (STL)
// Examples for classroom demonstration
// ============================================

// ---- Example 1: Basic Stack Operations ----
// Push 1~5 onto a stack, then pop them one by one to observe LIFO order.
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;

    // Push 1, 2, 3, 4, 5 onto the stack
    for (int i = 1; i <= 5; i++) {
        s.push(i);
        cout << "Pushed: " << i << endl;
    }

    cout << "Stack size: " << s.size() << endl;
    cout << "--- Start popping ---" << endl;

    // Pop elements one by one
    while (!s.empty()) {
        cout << "Popped: " << s.top() << endl;  // Peek at top
        s.pop();                                  // Remove top
    }

    cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << endl;

    return 0;
}

/*
 * Expected Output:
 * Pushed: 1
 * Pushed: 2
 * Pushed: 3
 * Pushed: 4
 * Pushed: 5
 * Stack size: 5
 * --- Start popping ---
 * Popped: 5
 * Popped: 4
 * Popped: 3
 * Popped: 2
 * Popped: 1
 * Is stack empty? Yes
 */

// ---- Example 2: Basic Queue Operations ----
// Simulate 5 people lining up (numbered 1~5), then leaving one by one.
// Demonstrates FIFO order.

/*
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    // 5 people join the queue
    for (int i = 1; i <= 5; i++) {
        q.push(i);
        cout << "Person " << i << " joined the queue" << endl;
    }

    cout << "Queue size: " << q.size() << endl;
    cout << "Front: Person " << q.front() << endl;
    cout << "Back: Person " << q.back() << endl;
    cout << "--- Start serving ---" << endl;

    // People leave one by one from the front
    while (!q.empty()) {
        cout << "Person " << q.front() << " left the queue" << endl;
        q.pop();
    }

    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}
*/

/*
 * Expected Output:
 * Person 1 joined the queue
 * Person 2 joined the queue
 * Person 3 joined the queue
 * Person 4 joined the queue
 * Person 5 joined the queue
 * Queue size: 5
 * Front: Person 1
 * Back: Person 5
 * --- Start serving ---
 * Person 1 left the queue
 * Person 2 left the queue
 * Person 3 left the queue
 * Person 4 left the queue
 * Person 5 left the queue
 * Is queue empty? Yes
 */

// ---- Example 3: Parenthesis Matching (Stack Application) ----
// Check if a string of '(' and ')' has valid matching.

/*
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Enter a parenthesis string: ";
    cin >> str;

    stack<char> s;
    bool ok = true;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            s.push('(');  // Push left parenthesis
        } else if (str[i] == ')') {
            if (s.empty()) {
                // Extra right parenthesis
                ok = false;
                break;
            }
            s.pop();  // Match found, pop the left parenthesis
        }
    }

    // If stack is not empty, there are extra left parentheses
    if (!s.empty()) {
        ok = false;
    }

    if (ok) {
        cout << "Parentheses match correctly!" << endl;
    } else {
        cout << "Parentheses do NOT match!" << endl;
    }

    return 0;
}
*/

/*
 * Sample Input: (())()
 * Expected Output:
 * Enter a parenthesis string: (())()
 * Parentheses match correctly!
 *
 * Sample Input: (()
 * Expected Output:
 * Enter a parenthesis string: (()
 * Parentheses do NOT match!
 *
 * Sample Input: ())
 * Expected Output:
 * Enter a parenthesis string: ())
 * Parentheses do NOT match!
 */

// ---- Example 4: Queue Simulation — Ice Cream Line ----
// n people line up (numbered 1~n). Each person takes 1 minute.
// If a person's number is a multiple of 3, they rejoin the queue once.
// Output the leaving order.

/*
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cout << "Enter number of people: ";
    cin >> n;

    queue<int> q;
    int bought[101] = {0};  // Track how many times each person has bought

    // Everyone joins the queue
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    cout << "Leaving order: ";
    while (!q.empty()) {
        int person = q.front();
        q.pop();

        bought[person]++;

        if (person % 3 == 0 && bought[person] == 1) {
            // Multiple of 3 and first purchase — rejoin the queue
            q.push(person);
        } else {
            // Actually leave
            cout << person << " ";
        }
    }
    cout << endl;

    return 0;
}
*/

/*
 * Sample Input: 6
 *
 * Expected Output:
 * Enter number of people: 6
 * Leaving order: 1 2 4 5 3 6
 */
