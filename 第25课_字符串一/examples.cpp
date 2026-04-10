// ============================================
// Lesson 25: Strings (Part 1) - char Arrays and string
// Examples for classroom demonstration
// ============================================

// ---- Example 1: Say Hello (Basic string I/O) ----
// Read a name (single word), print "Hello, XXX!".
#include <bits/stdc++.h>
using namespace std;

int main() {
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;
    return 0;
}

/*
 * Sample Input:
 * Alice
 *
 * Expected Output:
 * Hello, Alice!
 */

// ---- Example 2: Self Introduction (getline) ----
// Read a full line (may contain spaces) and print it back.
/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    string intro;
    getline(cin, intro);
    cout << intro << endl;
    return 0;
}
*/

/*
 * Sample Input:
 * I am Alice
 *
 * Expected Output:
 * I am Alice
 */

// ---- Example 3: Measure String Length ----
// Read a word and print its length.
/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    cout << s.size() << endl;
    return 0;
}
*/

/*
 * Sample Input:
 * apple
 *
 * Expected Output:
 * 5
 */

// ---- Example 4: Reverse Output (Index Traversal) ----
// Read a word and print it in reverse order.
/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = s.size() - 1; i >= 0; i--) {
        cout << s[i];
    }
    cout << endl;
    return 0;
}
*/

/*
 * Sample Input:
 * Hello
 *
 * Expected Output:
 * olleH
 */
