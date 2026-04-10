// ============================================
// Lesson 25: Strings (Part 1) - char Arrays and string
// Practice solutions
// ============================================

// ---- Practice 1: First and Last Letter ----
// Read a word, print its first letter and last letter on separate lines.
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    cout << s[0] << endl;              // First character
    cout << s[s.size() - 1] << endl;   // Last character
    return 0;
}

/*
 * Sample Input:
 * orange
 *
 * Expected Output:
 * o
 * e
 */

// ---- Practice 2: Count Vowels ----
// Read a lowercase word, count the number of vowels (a, e, i, o, u).
/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
            s[i] == 'o' || s[i] == 'u') {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
*/

/*
 * Sample Input:
 * beautiful
 *
 * Expected Output:
 * 5
 */

// ---- Practice 3: Character Replacement ----
// Read a lowercase word, replace every 'a' with '@', print the result.
/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a') {
            cout << '@';
        } else {
            cout << s[i];
        }
    }
    cout << endl;
    return 0;
}
*/

/*
 * Sample Input:
 * banana
 *
 * Expected Output:
 * b@n@n@
 */
